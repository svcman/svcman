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

#include "svcmanRunner.h"
#include "svcviewer.h"
#include "sd_handler.h"
#include <QApplication>

int svcman::run(int argc, char *argv[]) {
    // Non-QApplication-related args should be removed by this point
    QApplication a(argc, argv);

    svcviewobj = new svcviewer();
    svcviewobj->show();
    sd_handler sd_obj(&svcman::handler_callback, &svcman::status_callback);
    sd_obj.fetch_latest();


    return a.exec();
}

int svcman::handler_callback() {
    return 0;
}

int svcman::status_callback(const std::string mesg, const std::string style) {
    svcviewobj->updateStatus(mesg, style);
    return 0;
}

int main(int argc, char *argv[]) {
    svcman *svcrunner = new svcman();
    return svcrunner->run(argc, argv);
}
