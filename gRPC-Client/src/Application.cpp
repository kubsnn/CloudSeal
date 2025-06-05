#include <cloudseal/Application.hpp>
#include <QApplication>
#include <QtCore/QMetaMethod>
#include <cloudseal/logger.hpp>

namespace cloudseal
{
	void Application::exit(int code)
	{
		log.debug() << "Exiting application...";
		loader.reset();

		QMetaObject::invokeMethod(QApplication::instance(), "quit", Qt::QueuedConnection);
		QCoreApplication::exit(code);
	}
}