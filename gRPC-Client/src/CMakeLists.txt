add_subdirectory(qqt)

add_executable(app
    main.cpp
    grpc/client.cpp
    grpc/client.hpp
    resources.qrc
    utils/generate_uuid.cpp
)

target_link_libraries(app PRIVATE
    qqt
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

# Instalacja main.qml razem z binarką
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/main.qml" "${CMAKE_CURRENT_SOURCE_DIR}/resources.qrc" DESTINATION bin)


# ----  AUTODEPLOY DLL-ek Qt  ----
if(WIN32)
    qt_generate_deploy_app_script(       # tworzy skrypt z wywołaniem windeployqt
        TARGET app
        OUTPUT_SCRIPT deploy_script
    )
    install(SCRIPT ${deploy_script})     # uruchom skrypt podczas 'cmake --install'
endif()
if(APPLE)
    file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/main.qml" DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/../src)
    file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/resources.qrc" DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/../src)
    file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/../resources" DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/../src)
endif()