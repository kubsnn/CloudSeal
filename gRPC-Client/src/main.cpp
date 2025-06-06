#define LOG_TO_FILE 0
#include <fstream>
#include <ios>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <QtCore/QObject>
#include <cloudseal/utils/utils.hpp>


#include <cloudseal/App.hpp>
#include <cloudseal/qqt/jinja/QMLJinja.hpp>

#include <cloudseal/qqt/callbacks/CallbacksStorage.hpp>
#include <cloudseal/qqt/Layout.hpp>


using json = nlohmann::json;

int main(int argc, char **argv)
{
	// cloudseal::qqt::builders::ButtonBuilder buttonBuilder;

	// auto button = buttonBuilder
	// 	.text("Click Me")
	// 	.size({ 200, 50 })
	// 	.anchors({ .centerIn = "parent" })
	// 	.padding({ 10, 10, 10, 10 })
	// 	.build();

	cloudseal::App(argc, argv).exec();
}