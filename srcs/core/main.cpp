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

#include "core/RayTracer.hpp"

bool			poll_event(Window &window, SDL_Event *event) {
	while (SDL_PollEvent(event))
	{
		if (event->type == SDL_QUIT || (event->type == SDL_KEYDOWN
					&& event->key.keysym.sym == SDLK_ESCAPE))
		{
			window.updateRunning(false);
			return (false);
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_SPACE))
		{
			std::cout << "Render" << std::endl;
			return (true);
		}
	}
	return (false);
}

Vector			colored(const Ray& r, A_Object *stage) {
	hit_result	result;
	if (stage->hit(r, 0.0f, MAXFLOAT, result)) {
		return 0.5f * Vector(result.normal.x() + 1, result.normal.y() + 1, result.normal.z() + 1);
	}
	else {
		Vector	unit_direction = unit_vector(r.direction());
		float 	t = 0.5f*(unit_direction.y() + 1.0f);
		return (1.0f-t)*Vector(1.0f,1.0f,1.0f) + t*Vector(0.5f, 0.7f, 1.0f);
	}
}

void			render(Window &window) {
	Color		color;

	Camera		cam;
	A_Object	*list[2];
	A_Object	*stage;
	list[0] = new Sphere(Vector(0.0f,0.0f,-1.0f), 0.5f);
	list[1] = new Sphere(Vector(0.0f, -100.5f, -1.0f), 100.0f);
	stage = new Stage(list, 2);

	SDL_LockSurface(window.getSurface());
	for (int j = window.height - 1; j >= 0; j--)
		for (int i = 0; i < window.width; i++)
		{
			float u = float(i + drand48()) / float(window.width);
			float v = float(j + drand48()) / float(window.height);

			Ray r = cam.getRay(u, v);
			Vector p = r.pt_at_param(2.0f);
			Vector tmp = colored(r, stage);
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
		Window *window = new Window("RayTracer", WIDTH, HEIGHT);
		run_engine(*window);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		return (1);
	}
	return 0;
}
