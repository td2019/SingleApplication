#include <QApplication>
#include <QTextCodec>
#include <QSharedMemory>
#include <QDialog>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextCodec *codec = QTextCodec::codecForName("System");
    QTextCodec::setCodecForLocale(codec);

    //使用QSharedMemory防止多开
    QSharedMemory shared_memory;
    shared_memory.setKey(QString("main_window"));
    if(shared_memory.attach())
    {
        return 0;
    }

    if(shared_memory.create(1))
    {
        QDialog w;
        w.show();
        return app.exec();
    }
}
