add_library(qqt STATIC
    Object.cpp
    GUI.cpp
    CallbacksStorage.cpp
    Loader.cpp
    LambdaSlot.hpp

    # jinja
    jinja/QMLJinja.cpp
    # builders
    builders/ButtonBuilder.cpp
    builders/InputBuilder.cpp
)

target_link_libraries(qqt PUBLIC
    Qt6::Widgets
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    pantor::inja
    nlohmann_json::nlohmann_json # Dodaj cel nlohmann_json
)

# Instalacja plików nagłówkowych
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/
    DESTINATION include/qqt
    FILES_MATCHING PATTERN "*.hpp"
)

# Instalacja plików źródłowych


install(TARGETS qqt RUNTIME DESTINATION bin)