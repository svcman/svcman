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
#include "sd_handler.h"
#include <QApplication>

const QString StatusStyle_Fatal = "background-color: darkred; color: lightgrey; font-weight: bold;";

void sd_handler_callback() {

}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    svcviewer svcviewobj;
    svcviewobj.show();

    sd_handler sd_obj(sd_handler_callback);


    return a.exec();
}
