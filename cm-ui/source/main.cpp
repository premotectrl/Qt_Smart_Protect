#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <controllers/mastercontroller.h>
#include <controllers/commandcontroller.h>
#include <framework/command.h>

#include <QQmlContext>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<cm::controllers::MasterController>("CM",1, 0, "MasterController");
    qmlRegisterType<cm::controllers::NavigationController>("CM",1, 0, "NavigationController");
    qmlRegisterType<cm::controllers::CommandController>("CM", 1, 0, "CommandController");
    qmlRegisterType<cm::framework::Command>("CM", 1, 0, "Command");

    cm::controllers::MasterController masterController;

    QQmlApplicationEngine engine;

    // for importing custom Resources like modules
    engine.addImportPath("qrc:/");

    engine.rootContext() ->setContextProperty("masterController", &masterController);

    engine.load(QUrl(QStringLiteral("qrc:views/MasterView.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
