#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //Only enabling the Min Max Options in the MainWindow
    w.setWindowFlags(Qt::Window | Qt::WindowMinMaxButtonsHint);
    w.show();
    return a.exec();
}
