#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <controllers/mastercontroller.h>
#include <controllers/commandcontroller.h>
#include <framework/command.h>

#include <data/datetime-decorator.h>
#include <data/enumerator-decorator.h>
#include <data/int-decorator.h>
#include <data/string-decorator.h>

#include <models/address.h>
#include <models/appointment.h>
#include <models/client.h>
#include <models/contact.h>


#include <QQmlContext>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<cm::controllers::MasterController>("CM",1, 0, "MasterController");
    qmlRegisterType<cm::controllers::NavigationController>("CM",1, 0, "NavigationController");
    qmlRegisterType<cm::controllers::CommandController>("CM", 1, 0, "CommandController");
    qmlRegisterType<cm::framework::Command>("CM", 1, 0, "Command");

    qmlRegisterType<cm::data::DateTimeDecorator>("CM",1, 0, "DateTimeDecorator");
    qmlRegisterType<cm::data::EnumeratorDecorator>("CM",1, 0, "EnumeratorDecorator");
    qmlRegisterType<cm::data::IntDecorator>("CM",1, 0, "IntDecorator");

    qmlRegisterType<cm::data::StringDecorator>("CM",1, 0, "StringDecorator");

    qmlRegisterType<cm::models::Address>("CM",1, 0, "Address");
    qmlRegisterType<cm::models::Appointment>("CM",1, 0, "Appointment");
    qmlRegisterType<cm::models::Contact>("CM",1, 0, "Contact");
    qmlRegisterType<cm::models::Client>("CM",1, 0, "Client");

    cm::controllers::MasterController masterController;

    QQmlApplicationEngine engine;

    // for importing custom Resources like modules
    engine.addImportPath("qrc:/");

    engine.rootContext()->setContextProperty("masterController", &masterController);

    engine.load(QUrl(QStringLiteral("qrc:views/MasterView.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
