add_executable(grpc_cpp_server
    main.cpp
    resources.qrc
)

target_link_libraries(grpc_cpp_server
    PRIVATE
        proto::proto
        gRPC::grpc++_reflection
        Qt6::Widgets
        Qt6::Core
        Qt6::Gui
        Qt6::Qml
        Qt6::Quick
        pantor::inja
        nlohmann_json::nlohmann_json # Dodaj cel nlohmann_json
)

target_include_directories(grpc_cpp_server PRIVATE
    ${CMAKE_SOURCE_DIR}/proto
)
