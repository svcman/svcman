#ifndef SVCVIEWER_H
#define SVCVIEWER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class svcviewer;
}
QT_END_NAMESPACE

class svcviewer : public QMainWindow
{
    Q_OBJECT

public:
    svcviewer(QWidget *parent = nullptr);
    ~svcviewer();

private:
    Ui::svcviewer *ui;
};
#endif // SVCVIEWER_H
