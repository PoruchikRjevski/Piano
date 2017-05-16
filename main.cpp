#include <QDebug>
#include <QGuiApplication>
#include <QtQml/QQmlContext>
#include <QtQuick/QQuickView>

#include "core/sound_generator.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    SoundGenerator generator;

    QQuickView viewer;
//    generator.registerMetaQml();
    qmlRegisterType<SoundGenerator>("sound.gen", 1, 0, "Enums");
    viewer.rootContext()->setContextProperty("generator", &generator);
    viewer.setSource(QUrl("qrc:/ui/main.qml"));
    viewer.show();

    return app.exec();
}
