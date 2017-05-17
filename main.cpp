#include <QDebug>
#include <QGuiApplication>
#include <QApplication>
#include <QtQml/QQmlContext>
#include <QtQuick/QQuickView>

#include "core/sound_generator.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);

    SoundManager manager;

    if (!manager.initEnvironment()) {
        return 0;
    }

    QQuickView viewer;
//    generator.registerMetaQml();
    qmlRegisterType<SoundManager>("snd.manager", 1, 0, "Enums");
    viewer.rootContext()->setContextProperty("snd_manager", &manager);
    viewer.setSource(QUrl("qrc:/ui/main.qml"));
    viewer.show();

    return app.exec();
}
