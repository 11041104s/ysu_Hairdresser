#include "mainwindow.h"
#include "hairdressing.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Hairdressing projects;
    Mainwindow w;
    w.show();
    return a.exec();
}
