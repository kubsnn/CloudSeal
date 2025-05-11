cmake_minimum_required(VERSION 3.20)
project(gRPCServer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include(FetchContent)

FetchContent_Declare(
    inja
    GIT_REPOSITORY https://github.com/pantor/inja.git
    GIT_TAG v3.4.0 # Możesz zmienić na inną wersję lub commit
)
FetchContent_MakeAvailable(inja)

FetchContent_Declare(
  consolecolors
  GIT_REPOSITORY https://github.com/kubsnn/ConsoleColors.git
)
FetchContent_MakeAvailable(consolecolors)
FetchContent_GetProperties(consolecolors)
if(NOT consolecolors_POPULATED)
  FetchContent_Populate(consolecolors)
endif()
include_directories(${consolecolors_SOURCE_DIR}/include)

# Znalezienie bibliotek
find_package(Protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(inja CONFIG REQUIRED)

set(PROTO_GENERATED_DIR ${CMAKE_SOURCE_DIR}/proto-generated)

if(NOT DEFINED gRPC_CPP_PLUGIN_EXECUTABLE)
  set(gRPC_CPP_PLUGIN_EXECUTABLE
      "C:/vcpkg/installed/x64-windows/tools/grpc/grpc_cpp_plugin.exe")
endif()

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Core Network Gui Qml Quick Grpc Protobuf)
# Pokaż ścieżkę (debug)
message(STATUS "gRPC_CPP_PLUGIN_EXECUTABLE = ${gRPC_CPP_PLUGIN_EXECUTABLE}")

# Własna funkcja grpc_generate_cpp()
function(grpc_generate_cpp GRPC_SRCS GRPC_HDRS)
    if(NOT ARGN)
        message(SEND_ERROR "grpc_generate_cpp() called without proto files")
        return()
    endif()

    foreach(FIL ${ARGN})
        get_filename_component(ABS_FIL ${FIL} ABSOLUTE)
        get_filename_component(FIL_WE ${FIL} NAME_WE)

        set(GRPC_SRCS_FILE "${PROTO_GENERATED_DIR}/${FIL_WE}.grpc.pb.cc")
        set(GRPC_HDRS_FILE "${PROTO_GENERATED_DIR}/${FIL_WE}.grpc.pb.h")
        message (STATUS "${gRPC_CPP_PLUGIN_EXECUTABLE}")
        add_custom_command(
            OUTPUT "${GRPC_SRCS_FILE}" "${GRPC_HDRS_FILE}"
            COMMAND ${Protobuf_PROTOC_EXECUTABLE}
            ARGS --grpc_out=${PROTO_GENERATED_DIR}
                 --plugin=protoc-gen-grpc=${gRPC_CPP_PLUGIN_EXECUTABLE}
                 --proto_path=${CMAKE_SOURCE_DIR}/proto
                 -I=${CMAKE_CURRENT_SOURCE_DIR}/proto
                 "${ABS_FIL}"
            DEPENDS "${ABS_FIL}"
            COMMENT "Generating gRPC for ${FIL}"
            VERBATIM)

        list(APPEND ${GRPC_SRCS} "${GRPC_SRCS_FILE}")
        list(APPEND ${GRPC_HDRS} "${GRPC_HDRS_FILE}")
    endforeach()

    set(${GRPC_SRCS} ${${GRPC_SRCS}} PARENT_SCOPE)
    set(${GRPC_HDRS} ${${GRPC_HDRS}} PARENT_SCOPE)
endfunction()

# Proto pliki
file(GLOB PROTO_FILES ${CMAKE_SOURCE_DIR}/proto/*.proto)

# Generowanie protobuf
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_FILES})
grpc_generate_cpp(GRPC_SRCS GRPC_HDRS ${PROTO_FILES})

# Biblioteka z kodem .pb i .grpc.pb
add_library(proto_objects
    ${PROTO_SRCS}
    ${GRPC_SRCS}
)

target_include_directories(proto_objects PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}
    ${PROTO_GENERATED_DIR}
    ${CMAKE_SOURCE_DIR}/proto
    ${Protobuf_INCLUDE_DIRS}
    ${gRPC_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/proto-generated
)

target_link_libraries(proto_objects PUBLIC
    protobuf::libprotobuf
    gRPC::grpc++
)

add_library(proto::proto ALIAS proto_objects)

# Podprojekt z serwerem
include_directories(${CMAKE_SOURCE_DIR}/resources)
include_directories(${CMAKE_SOURCE_DIR}/include)
add_subdirectory(src)
