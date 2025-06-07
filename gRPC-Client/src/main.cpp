#define LOG_TO_FILE 0

#include <cloudseal/App.hpp>
#include <cloudseal/views/MainView.hpp>

int main(int argc, char* argv[])
{
	auto mainView = std::make_shared<cloudseal::views::MainView>();
	cloudseal::log.fatal() << "Starting application :(";

	return cloudseal::App(argc, argv, mainView).exec();
}