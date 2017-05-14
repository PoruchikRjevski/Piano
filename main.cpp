#include <QDebug>
#include <QGuiApplication>
#include <QtQml/QQmlContext>
//#include <QtQml/QQmlEngine>
#include <QtQuick/QQuickView>
//#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQuickView viewer;

    viewer.setSource(QUrl("qrc:/ui/main.qml"));

    viewer.show();

//    QQmlApplicationEngine engine;
//    engine.load(QUrl(QLatin1String("qrc:/ui/main.qml")));

    return app.exec();
}
