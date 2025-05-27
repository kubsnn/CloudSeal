add_executable(app
    main.cpp
    grpc/client.cpp
    grpc/client.hpp
    resources.qrc
    utils/generate_uuid.cpp
)

target_link_libraries(app PRIVATE
    Qt6::Widgets
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    pantor::inja
    nlohmann_json::nlohmann_json # Dodaj cel nlohmann_json
    CloudSealProtos           # biblioteka z kodem wygenerowanym z .proto
    Qt6::Protobuf        # Qt Protobuf (serializacja obiektów protobuf)
    Qt6::Grpc            # Qt GRPC (obsługa komunikacji gRPC)
)

install(TARGETS app RUNTIME DESTINATION bin)

# ----  AUTODEPLOY DLL-ek Qt  ----
if(WIN32)
    qt_generate_deploy_app_script(       # tworzy skrypt z wywołaniem windeployqt
        TARGET app
        OUTPUT_SCRIPT deploy_script
    )
    install(SCRIPT ${deploy_script})     # uruchom skrypt podczas 'cmake --install'
endif()