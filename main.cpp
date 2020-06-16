#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QQuickView>
#include <QMidiOut.h>
#include <QMidiFile.h>
#include <midihandler.h>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    MidiHandler* midiHandler = new MidiHandler();
    midiHandler->setFilePath("foo"); //have it run this to set it to the "please select a .mid prompt

    //qmlRegisterType<MidiHandler>("com.internal.MidiHandler", 1, 0, "MidiHandler"); // MyQMLType will be usable with: import com.internal.MidiHandler 1.0

    //I commented this out because when i did nothing broke and i want to keep things simple
//    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
//                     &app, [url](QObject *obj, const QUrl &objUrl) {
//        if (!obj && url == objUrl)
//            QCoreApplication::exit(-1);
//    }, Qt::QueuedConnection);
    engine.load(QStringLiteral("qrc:/main.qml"));
    engine.rootContext()->setContextProperty("midiHandler", midiHandler);

    return app.exec();
}
