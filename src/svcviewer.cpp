#include "svcviewer.h"
#include "./ui_svcviewer.h"

svcviewer::svcviewer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::svcviewer)
{
    ui->setupUi(this);
}

svcviewer::~svcviewer()
{
    delete ui;
}

void svcviewer::on_filter_clearAllButton_released()
{
    ui->filter_customPattern->clear();
}

