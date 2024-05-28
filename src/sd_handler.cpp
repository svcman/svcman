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

#include "sd_handler.h"
#include <sdbus-c++/IConnection.h>
#include <sdbus-c++/IProxy.h>
//#include <sdbus-c++/sdbus-c++.h>

using sdbus::ServiceName;
using sdbus::ObjectPath;

std::unique_ptr<sdbus::IConnection> conn;
std::unique_ptr<sdbus::IProxy> proxy;

sd_handler::sd_handler(handler_callback callback_) {
    ServiceName sd_service_name = ServiceName{"org.freedesktop.systemd1.Manager"};
    ObjectPath sd_service_path = ObjectPath{"/org/freedesktop/systemd1"};
    conn = sdbus::createSystemBusConnection();
    proxy = sdbus::createProxy(*conn, sd_service_name, sd_service_path);
}

int sd_handler::watch() {
    return 0;
}

int fetch_latest() {
    return 0;
}
