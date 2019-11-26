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

float			hit_sphere(const Vector& center, float radius, const Ray& r) {
	Vector	oc = r.origin() - center;
	float	a = dot(r.direction(), r.direction());
	float	b = 2.0f * dot (oc, r.direction());
	float	c = dot(oc, oc) - radius*radius;
	float	discriminant = b*b - 4.0f*a*c;
	if (discriminant < 0)
		return -1.0f;
	else
		return (-b - sqrt(discriminant)) / (2.0f*a);
}

Vector			colored(const Ray& r){
	float t = hit_sphere(Vector(0.0f,0.0f,-1.0f), 0.5f, r);
	if (t > 0.0f) {
		Vector N = unit_vector(r.pt_at_param(t) - Vector(0.0f,0.0f,-1.0f));
		return 0.5f*Vector(N.x()+1.0f, N.y()+1.0f, N.z()+1.0f);
	}
	Vector		unit_direction = unit_vector(r.direction());
	t = 0.5f*(unit_direction.y() + 1.0f);
	return (1.0f-t)*Vector(1.0f,1.0f,1.0f) + t*Vector(1.0f, 0.7f, 0.26f);
}

void			render(Window &window) {
	Color		color;
	Vector		lower_left_corner(-2.0f, -1.0f, -1.0f);
	Vector		horizontal(4.0f,0.0f,0.0f);
	Vector		vertical(0.0f,2.0f,0.0f);
	Vector		origin(0.0f,0.0f,0.0f);

	SDL_LockSurface(window.getSurface());
	for (int i = 0; i < window.width; i++)
		for (int j = 0; j < window.height; j++)
		{
			float u = float(i) / float(window.width);
			float v = float(j) / float(window.height);

			Ray r(origin, lower_left_corner + u*horizontal + v*vertical);
			Vector tmp = colored(r);
			color.setRGB(tmp.values[0], tmp.values[1], tmp.values[2]);
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
		Window *window = new Window("RayTracer", 1280, 640);
		run_engine(*window);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		return (1);
	}
	return 0;
}
