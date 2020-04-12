#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <mainmodel.h>
#include <QQuickStyle>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setOrganizationName("Example");
    QCoreApplication::setOrganizationDomain("Example");
    QCoreApplication::setApplicationName("Example");

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    QQuickStyle::setStyle("Material");
    LoginView::MainModel loginModel("exampleLogin");
    if (!loginModel.init(&engine)) {
        return -1;
    }

    QString pathXML = ":/example.xml";
    if (argc > 1) {
        pathXML = QString(argv[1]);
    }

    if (!loginModel.setCounrySource(pathXML)) {
        return -2;
    }

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {

        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);

    }, Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}
