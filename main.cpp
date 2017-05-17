#include <QDebug>
#include <QGuiApplication>
#include <QApplication>
#include <QtQml/QQmlContext>
#include <QtQuick/QQuickView>

#include "sound_core/sound_manager.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);

    SoundManager manager;

    if (!manager.initEnvironment()) {
        return 0;
    }

    QQuickView viewer;
    qmlRegisterType<SoundManager>("sound.environment", 1, 0, "Enums");
    viewer.rootContext()->setContextProperty("sound_manager", &manager);
    viewer.setSource(QUrl("qrc:/ui/main.qml"));
    viewer.show();

    return app.exec();
}
