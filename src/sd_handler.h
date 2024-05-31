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

#include <sdbus-c++/IConnection.h>
#include <sdbus-c++/IProxy.h>

class sd_handler
{
public:
    //sd_handler(svcviewer*, int (*)());
    using DataCallback = int (*)();
    using StatusCallback = int (*)(std::string, std::string);
    sd_handler(DataCallback data_callback, StatusCallback status_callback);
    int fetch_latest();
    int watch();
private:
    sdbus::ServiceName sd_service_name;
    sdbus::ObjectPath sd_service_path;
    std::unique_ptr<sdbus::IConnection> conn;
    std::unique_ptr<sdbus::IProxy> proxy;
    DataCallback data_callback;
    StatusCallback status_callback;
};

#endif // SD_HANDLER_H
