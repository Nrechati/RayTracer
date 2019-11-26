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
#include "class/Vector.hpp"
#include "class/Color.hpp"
#include "class/Ray.hpp"
#include "class/Stage.hpp"
#include "class/Camera.hpp"
#include "class/A_Object.hpp"
#include "class/Sphere.hpp"
#include "class/Light.hpp"
#include </Users/nrechati/.brew/Cellar/sdl2/2.0.10/include/SDL2/SDL.h>

bool			poll_event(Window &window, SDL_Event *event) {
	while (SDL_PollEvent(event))
	{
		if (event->type == SDL_QUIT || (event->type == SDL_KEYDOWN
					&& event->key.keysym.sym == SDLK_ESCAPE))
			window.updateRunning(false);
			return (false);
	}
	window.updateRunning(true);
	return (false);
}

void			render(Window &window) {
	Color		color;

	SDL_LockSurface(window.getSurface());
	for (size_t i = 0; i < window.width; i++)
		for (size_t j = 0; j < window.height; j++)
		{
			color.setRGB((float(i) / float(window.width)), (float(j) / float(window.height)), 0.2);
			window.put_pixel(i, j, color.getCValue());
		}
	SDL_UnlockSurface(window.getSurface());
}

void			run_engine(Window &window) {
	bool	render_needed = true;
	while (window.running() == true) {
		window.show_fps();
		if (render_needed == true)
			render(window);
		render_needed = poll_event(window, window.getEvent());
		SDL_UpdateWindowSurface(window.getWindow());
	}
}

int				main() {
	try {
		Window *window = new Window("RayTracer", 1280, 720);
		run_engine(*window);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		return (1);
	}
	return 0;
}
