/***License********************************************************************

    svcman - Graphical Service Manager for systemd on Linux
    Copyright (C) 2024  Paul Pfeister <code@pfeister.dev>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

*****************************************************************************/

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

int svcviewer::updateSvcMonitorPane() {
    return 0;
}

int svcviewer::updateStatus(const std::string mesg, const std::string style) {
    ui->statusbar->setStyleSheet(QString::fromStdString(style));
    ui->statusbar->showMessage(QString::fromStdString(mesg));
    return 0;
}

void svcviewer::on_filter_clearAllButton_released()
{
    ui->filter_customPattern->clear();
    ui->filter_unitTypeSelect->clear();
    ui->filter_stateSelect->clear();
    ui->filter_substateSelect->clear();
    ui->filter_startupStateSelect->clear();
}

