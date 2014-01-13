/*
    MINX - A C++ Graphics and Input Wrapper Library
    Copyright (C) 2013-2014  MINX Team

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

	*/

#ifndef GAMETIME_H_
#define GAMETIME_H_
#include <thread>
#include <chrono>
#include <GL/glew.h>
#include <GL/glfw3.h>
namespace MINX
{
	/** Contains a bunch of time related functions for use in the Game
	 */
	class GameTime
	{
		public:
			/** Constructs a GameTime
			 */
			GameTime();
			/** @return the number of milliseconds since the start of the Game
			 */
			long getElapsedMillis();
			/** @return the number of milliseconds since the last update()
			 */
			long getDeltaTimeMillis();
			/** @return the number of seconds since the last update()
			 */
			double getDeltaTimeSeconds();
			/** updates the gametime
			 */
			void update();
			/** limits the updates per second of the current thread by delaying
			 */
			inline void limitFPS(int desiredFPS){std::this_thread::sleep_for(std::chrono::milliseconds(1000/desiredFPS-(long(glfwGetTime())-long(lastUpdate))));}
		private:
			double totalTimeMillis;
			double deltaTime;
			double lastUpdate;
	};
}
#endif
