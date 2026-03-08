#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);


    // 关键：在 QGuiApplication 之前加入这一行，屏蔽图片库的警告
    qputenv("QT_LOGGING_RULES", "qt.gui.imageio=false");

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("QmlCppIntegration", "Main");

    return app.exec();
}
