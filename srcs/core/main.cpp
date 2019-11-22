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
#include "class/Ray.hpp"
#include "class/Stage.hpp"
#include "class/Camera.hpp"
#include "class/A_Object.hpp"
#include "class/Sphere.hpp"
#include "class/Light.hpp"
#include </Users/nrechati/.brew/Cellar/sdl2/2.0.10/include/SDL2/SDL.h>

int				poll_event(SDL_Event *event)
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
	std::cout << "Courtesy of jle-quel" << std::endl;

	Window	window;

	while (true) {
		window.show_fps();
		SDL_UpdateWindowSurface(window.window);
	//	running = poll_event(&event);
	}
	return 0;
}
