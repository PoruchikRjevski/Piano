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

//    SoundManager manager(&viewer);
    SoundManager manager;

    if (!manager.initEnvironment()) {
        return 0;
    }

    QQuickView viewer;

    manager.setQmlViewerPtr(&viewer);

    qmlRegisterType<SoundManager>("sound.environment", 1, 0, "Enums");
    viewer.rootContext()->setContextProperty("sound_manager", &manager);
    viewer.setSource(QUrl("qrc:/ui/main.qml"));
    viewer.setFlags(Qt::MSWindowsFixedSizeDialogHint);
    viewer.show();

    return app.exec();
}
