#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QMediaPlayer>

#include <src/pickfiledialog.h>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/src/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    // Connect changeVideoSignal to changeVideoSlot
    PickFileDialog* fileDialog;
    QObject* root = engine.rootObjects()[0];
    QObject* player = root->findChild<QObject*>("player");
    if (player)
    {
        fileDialog = new PickFileDialog(player);
        qDebug() << "Connect changeVideoSignal: " << QObject::connect(root, SIGNAL(changeVideoSignal()),
                             fileDialog, SLOT(changeVideoSlot()));
    }

    return app.exec();
}
