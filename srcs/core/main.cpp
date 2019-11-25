/* **************************************************************************** */
/*                                                                              */
/*                                                         :::      ::::::::    */
/*    main                                               :+:      :+:    :+:    */
/*                                                     +:+ +:+         +:+      */
/*    By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+         */
/*                                                 +#+#+#+#+#+   +#+            */
/*    Created: 2019/10/18 09:45:47 by nrechati          #+#    #+#              */
/*    Updated: 2019/10/18 09:47:02 by nrechati         ###   ########.fr        */
/*                                                                              */
/* **************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <cmath>
#include "class/Window.hpp"
#include "class/Color.hpp"
#include "class/Ray.hpp"
#include "class/Stage.hpp"
#include "class/Camera.hpp"
#include "class/A_Object.hpp"
#include "class/Sphere.hpp"
#include "class/Light.hpp"
#include </Users/nrechati/.brew/Cellar/sdl2/2.0.10/include/SDL2/SDL.h>

bool			poll_event(SDL_Event *event)
{
	while (SDL_PollEvent(event))
	{
		if (event->type == SDL_QUIT || (event->type == SDL_KEYDOWN
					&& event->key.keysym.sym == SDLK_ESCAPE))
			return (false);
	}
	return (true);
}

int				main() {
	Window		window("Color", 1280, 720);
	Color		color(0,0,0);
	std::cout << window << std::endl;
	while (window.running() == true) {
		window.show_fps();
		for (size_t i=0 ; i < window.width ; i++)
			for (size_t j = 0; j < window.height; j++)
			{
				color.setRGB((float(i)/float(window.width))*255, (float(j)/float(window.height))*255, 51);
				window.put_pixel(i, j, color.getValue());
			}
		SDL_UpdateWindowSurface(window.getWindow());
		window.updateRunning(poll_event(window.getEvent()));
	}

	return 0;
}
