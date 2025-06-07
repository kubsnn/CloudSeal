add_library(qqt STATIC
    Object.cpp
    GUI.cpp
    Loader.cpp
    Application.cpp

    # callbacks
    callbacks/CallbacksStorage.cpp
    callbacks/LambdaSlot.hpp
    callbacks/LambdaSlot.cpp

    # jinja
    jinja/QMLJinja.cpp
    # builders
    builders/ButtonBuilder.cpp
    builders/InputBuilder.cpp
)

target_link_libraries(qqt PUBLIC
    utils
    Qt6::Widgets
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    pantor::inja
    nlohmann_json::nlohmann_json # Dodaj cel nlohmann_json
)
# Wyłącz Code Analysis dla Qt i inja (MSVC only)
if(MSVC)
    set_source_files_properties(
        ${CMAKE_BINARY_DIR}/_deps/inja-src/include/inja/inja.hpp
        PROPERTIES COMPILE_FLAGS "/analyze-"
    )

    # Jeśli warningi pochodzą z Qt (w MSVC PATH), też można próbować:
    target_compile_options(qqt PRIVATE "/analyze-")
endif()

# Instalacja plików nagłówkowych
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/
    DESTINATION include/qqt
    FILES_MATCHING PATTERN "*.hpp"
)

# Instalacja plików źródłowych


install(TARGETS qqt RUNTIME DESTINATION bin)