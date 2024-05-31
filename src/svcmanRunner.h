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

#ifndef svcmanRunner_H
#define svcmanRunner_H

#include "svcviewer.h"

class svcman
{
public:
    int run(int, char *[]);
    int handler_callback();
    int status_callback(const std::string, const std::string);
private:
    svcviewer* svcviewobj;
};

#endif // svcmanRunner
