//#
//# Copyright (C) 2018-2020 Yankovich Andrei (EndrII).
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <lvmainmodel.h>
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
    LoginView::LVMainModel loginModel("exampleLogin");
    if (!loginModel.init(&engine)) {
        return -1;
    }

    QString pathXML = ":/example.xml";
    if (argc > 1) {
        pathXML = QString(argv[1]);
    }

    if (!loginModel.setCountriesSource(pathXML)) {
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
