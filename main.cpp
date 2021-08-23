#include "mainwindow.h"
#include "Common_tools.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    unsigned int seed = time(0);
    srand(seed);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
