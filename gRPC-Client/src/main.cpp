#define LOG_TO_FILE 0

#include <cloudseal/App.hpp>
#include <cloudseal/views/MainView.hpp>
#include <cloudseal/logger.hpp>
#include <nanochi/cc/colors.hpp>

inline const char* qtMsgTypeToString(QtMsgType type) {
    switch (type) {
    case QtDebugMsg:    return "Debug";
    case QtInfoMsg:     return "Info";
    case QtWarningMsg:  return "Warning";
    case QtCriticalMsg: return "Critical";
    case QtFatalMsg:    return "Fatal";
    default:            return "Unknown";
    }
}

void customMessageHandler(QtMsgType type, const QMessageLogContext& context, const QString& msg)
{
	auto& log = cloudseal::get_logger();

	namespace cc = nanochi::cc;

	log.debug() << msg.toStdString();
}

int main(int argc, char* argv[])
{
    qInstallMessageHandler(customMessageHandler);

	auto mainView = std::make_shared<cloudseal::views::MainView>();
	cloudseal::log.fatal() << "Starting application :(";

	return cloudseal::App(argc, argv, mainView).exec();
}