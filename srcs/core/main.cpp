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

/* Environment */
Stage *stage = nullptr;
uint8_t render_mode = 1;
uint8_t pixel_size = 8;
Vector lookfrom(6.5f, 1.8f, 1.0f);
Vector lookat(0, 1, -1);
float dist_to_focus = (lookfrom - lookat).length();
float aperture = 0.0f;

void run_engine(Window &window)
{
	bool render_needed = true;
	Camera *cam;
	stage = init_stage();
	while (window.running() == true) {
		if (render_needed == true) {
			cam = new Camera(lookfrom, lookat, Vector(0, 1, 0), 50, WIDTH / HEIGHT, aperture, dist_to_focus);
			render(window, *cam);
			delete cam;
		}
		render_needed = poll_event(window, *cam, window.getEvent());
		SDL_UpdateWindowSurface(window.getWindow());
	}
}

int main()
{
	try {
		if (render_mode == 1) {
			std::cout << "\033[1;33m";
			std::cout << "Launching RayTracer in High Render setup" << std::endl;
			std::cout << "Setting up environnement ... \033[1;0m" << std::endl;
		}
		Window *window = new Window("RayTracer", WIDTH, HEIGHT);
		run_engine(*window);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
		return (1);
	}
	return 0;
}
