#include "svcviewer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    svcviewer w;
    w.show();
    return a.exec();
}
