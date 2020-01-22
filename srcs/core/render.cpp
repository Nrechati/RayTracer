/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:49:32 by nrechati          #+#    #+#             */
/*   Updated: 2020/01/22 14:59:28 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/RayTracer.hpp"

extern Stage *stage;
extern uint8_t pixel_size;

Vector getColor(const Ray &r, A_Object *stage, int depth) {
	hit_result result;
	result.mat_ptr = new default_mat(Vector(0.f, 0.f, 0.f));
	if (stage->hit(r, 0.001f, MAXFLOAT, result)) {
		Ray scattered;
		Vector attenuation;
		if (depth < 50 && result.mat_ptr->scatter(r, result, attenuation, scattered))
			return attenuation * getColor(scattered, stage, depth + 1);
		else
			return (Vector(0, 0, 0));
	}
	else {
		Vector unit_direction = unit_vector(r.direction());
		float t = 0.5f * (unit_direction.y() + 1.0f);
		return ((1.0f - t) * Vector(1.0f, 1.0f, 1.0f) + t * Vector(0.5f, 0.7f, 1.0f));
	}
}

void low_render_loop(Window &window, Camera &cam, int ns) {
	for (int j = 0; j < window.height; j += pixel_size) {
		for (int i = 0; i < window.width; i += pixel_size) {
			Vector col_vector(0, 0, 0);
			for (int s = 0; s < ns; s++) {
				float u = float(i + drand48()) / float(window.width);
				float v = float(j + drand48()) / float(window.height);
				Ray r = cam.getRay(u, v);
				col_vector += getColor(r, stage, 0);
			}
			col_vector = col_vector / float(ns);
			col_vector = Vector(sqrt(col_vector[0]), sqrt(col_vector[1]), sqrt(col_vector[2]));
			Color color(col_vector[0], col_vector[1], col_vector[2]);
			for (int y = 0; y < pixel_size; y++) {
				for (int x = 0; x < pixel_size; x++) {
					window.put_pixel(i + x, j + y, color.getCValue());
				}
			}
		}
	}
}

void high_render_loop(Window &window, Camera &cam, int ns) {
	ProgressBar bar(window.height - 1);
	for (int j = 0; j < window.height; j++) {
		for (int i = 0; i < window.width; i++) {
			Vector col_vector(0, 0, 0);
			for (int s = 0; s < ns; s++) {
				float u = float(i + drand48()) / float(window.width);
				float v = float(j + drand48()) / float(window.height);
				Ray r = cam.getRay(u, v);
				col_vector += getColor(r, stage, 0);
			}
			col_vector = col_vector / float(ns);
			col_vector = Vector(sqrt(col_vector[0]), sqrt(col_vector[1]), sqrt(col_vector[2]));
			Color color(col_vector[0], col_vector[1], col_vector[2]);
			window.put_pixel(i, j, color.getCValue());
		}
		bar.update(j);
	}
	std::cout << std::endl;
}

void render(Window &window, Camera &cam) {
	SDL_LockSurface(window.getSurface());
	if (render_mode == 0)
		low_render_loop(window, cam, 1);
	else
		high_render_loop(window, cam, NS);
	SDL_UnlockSurface(window.getSurface());
}
