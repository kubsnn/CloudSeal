add_executable(grpc_cpp_server
    main.cpp
)

target_link_libraries(grpc_cpp_server
    PRIVATE
        proto::proto
        gRPC::grpc++_reflection
)

target_include_directories(grpc_cpp_server PRIVATE
    ${CMAKE_SOURCE_DIR}/proto
)
