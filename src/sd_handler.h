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

#ifndef SD_HANDLER_H
#define SD_HANDLER_H

#include <functional>

class sd_handler
{
public:
    //sd_handler(svcviewer*, int (*)());
    sd_handler(
        const std::function<int()>&data_callback,
        const std::function<int(const std::string, const std::string)>&status_callback
    );
    int fetch_latest();
    int watch();
private:
    std::function<int()> data_callback;
    std::function<int(const std::string, const std::string)> status_callback;
};

#endif // SD_HANDLER_H
