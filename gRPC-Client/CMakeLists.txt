cmake_minimum_required(VERSION 3.20)
project(CloudSealApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Znalezienie nlohmann_json
find_package(nlohmann_json CONFIG REQUIRED)

include(FetchContent)

set(INJA_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(INJA_BUILD_BENCHMARKS OFF CACHE BOOL "" FORCE)

# Pobranie i konfiguracja inja
FetchContent_Declare(
    inja
    GIT_REPOSITORY https://github.com/pantor/inja.git
    GIT_TAG v3.4.0 # Możesz zmienić na inną wersję lub commit
)

FetchContent_MakeAvailable(inja)

# Pobranie i konfiguracja consolecolors
FetchContent_Declare(
    consolecolors
    GIT_REPOSITORY https://github.com/kubsnn/ConsoleColors.git
)
FetchContent_GetProperties(consolecolors)
if(NOT consolecolors_POPULATED)
    FetchContent_Populate(consolecolors)
endif()
include_directories(${consolecolors_SOURCE_DIR}/include)

# Automatyczne generowanie plików Qt

# Znalezienie bibliotek Qt6
#ustaw Qt6_DIR do katalogu, w którym zainstalowano Qt6
# Możesz to zrobić poprzez ustawienie zmiennej środowiskowej lub bezpośrednio w CMake
if(APPLE)
set(Qt6_DIR "/Users/kosmagasiorowski/Qt/6.9.0/macos/lib/cmake/Qt6")
endif()
find_package(Qt6 REQUIRED COMPONENTS Widgets Core Network Gui Qml Quick Grpc Protobuf)

qt_standard_project_setup()

# Podprojekt z serwerem
include_directories(${CMAKE_SOURCE_DIR}/resources)
include_directories(${CMAKE_SOURCE_DIR}/include)

install(DIRECTORY "resources" DESTINATION bin)

add_subdirectory(src/grpc)

add_subdirectory(src)