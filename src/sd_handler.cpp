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

// devel/diag
#include <iostream>

#include "sd_handler.h"
#include "stdStyles.h"
#include <sdbus-c++/IConnection.h>
#include <sdbus-c++/IProxy.h>
//#include <sdbus-c++/sdbus-c++.h>

sd_handler::sd_handler(DataCallback data_callback, StatusCallback status_callback)
    : data_callback(data_callback)
    , status_callback(status_callback)
    , sd_service_name(sdbus::ServiceName{"org.freedesktop.systemd1"})
    , sd_service_path(sdbus::ObjectPath{"/org/freedesktop/systemd1"})
    , conn(sdbus::createSystemBusConnection())
    , proxy(sdbus::createProxy(*conn, sd_service_name, sd_service_path))
    {}

int sd_handler::watch() {
    return 0;
}

int sd_handler::fetch_latest() {
    try{
        std::vector<std::tuple<
            std::string, // Id
            std::string, // Description
            std::string, // LoadState
            std::string, // ActiveState
            std::string, // SubState
            std::string, // Following
            std::string, // UnitPath
            std::string, // JobId
            std::string, // JobType
            std::string, // JobPath
            std::string  // UnitFileState
        >> loadedUnits;

        proxy->callMethod("ListUnit")
            .onInterface(sd_service_name)
            .withTimeout(60000)
            .storeResultsTo(loadedUnits);

        for (const auto& unit : loadedUnits) {
                const auto& [id, description, loadState, activeState, subState, following, unitPath, jobId, jobType, jobPath, unitFileState] = unit;
                std::cout << "ID: " << id << ", Description: " << description << ", Active State: " << activeState << std::endl;
            }
    } catch (const sdbus::Error& e) {
        std::string errMsg = "D-Bus error: " + e.getName() + " - " + e.getMessage();
        std::cerr << errMsg << std::endl;
        status_callback(errMsg, VIEWER_STATUS_MESSAGE_STYLE_FATAL);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
