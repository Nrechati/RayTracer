/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 13:39:10 by nrechati          #+#    #+#             */
/*   Updated: 2020/01/22 13:51:19 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/RayTracer.hpp"

extern Stage *stage;
extern uint8_t render_mode;
extern uint8_t pixel_size;
extern Vector lookfrom;
extern Vector lookat;
extern float aperture;

A_Object *selected = nullptr;
int selected_index = 0;
bool lock = false;

bool poll_event(Window &window, Camera &cam, SDL_Event *event) {
	while (SDL_PollEvent(event)) {
		if (event->type == SDL_QUIT || (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_ESCAPE)) {
			window.updateRunning(false);
			return (false);
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_EQUALS)) {
			if (pixel_size <= 16)
				pixel_size *= 2;
			return true;
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_MINUS)) {
			if (pixel_size > 4)
				pixel_size /= 2;
			return true;
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_s)) {
			lookfrom -= 0.2f * unit_vector(lookat - lookfrom);
			if (lock == false)
				lookat -= 0.2f * unit_vector(lookat - lookfrom);
			return true;
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_w)) {
			lookfrom += 0.2f * unit_vector(lookat - lookfrom);
			if (lock == false)
				lookat += 0.2f * unit_vector(lookat - lookfrom);
			return true;
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_SPACE)) {
			lookfrom[1] += 0.2f;
			if (lock == false)
				lookat[1] += 0.2f;
			return true;
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_c)) {
			lookfrom[1] -= 0.2f;
			if (lock == false)
				lookat[1] -= 0.2f;
			return true;
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_d)) {
			lookfrom += 0.2f * cross(unit_vector(lookat - lookfrom), Vector(0, 1, 0));
			if (lock == false)
				lookat += 0.2f * cross(unit_vector(lookat - lookfrom), Vector(0, 1, 0));
			return true;
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_a)) {
			lookfrom -= 0.2f * cross(unit_vector(lookat - lookfrom), Vector(0, 1, 0));
			if (lock == false)
				lookat -= 0.2f * cross(unit_vector(lookat - lookfrom), Vector(0, 1, 0));
			return true;
		}
		if ((lock == false && event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_LEFT)) {
			lookat -= 0.3f * cross(unit_vector(lookat - lookfrom), Vector(0, 1, 0));
			return true;
		}
		if ((lock == false && event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_RIGHT)) {
			lookat += 0.3f * cross(unit_vector(lookat - lookfrom), Vector(0, 1, 0));
			return true;
		}
		if ((lock == false && event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_UP)) {
			lookat += 0.3f * Vector(0, 1, 0);
			return true;
		}
		if ((lock == false && event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_DOWN)) {
			lookat -= 0.3f * Vector(0, 1, 0);
			return true;
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_r)) {
			lookat = static_cast<Sphere *>(selected)->center;
			return true;
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_r)) {
			lookat = Vector(0, 1, -1);
			return true;
		}
		if ((selected != nullptr && event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_u)) {
			Sphere *tmp = nullptr;
			if ((tmp = dynamic_cast<Sphere *>(selected)) != nullptr)
				tmp->center[1] += 0.1f;
			return true;
		}
		if ((selected != nullptr && event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_j)) {
			Sphere *tmp = nullptr;
			if ((tmp = dynamic_cast<Sphere *>(selected)) != nullptr)
				tmp->center[1] -= 0.1f;
			return true;
		}
		if ((selected != nullptr && event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_h)) {
			Sphere *tmp = nullptr;
			if ((tmp = dynamic_cast<Sphere *>(selected)) != nullptr)
				tmp->center -= 0.1f * cross(unit_vector(lookat - lookfrom), Vector(0, 1, 0));
			return true;
		}
		if ((selected != nullptr && event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_k)) {
			Sphere *tmp = nullptr;
			if ((tmp = dynamic_cast<Sphere *>(selected)) != nullptr)
				tmp->center += 0.1f * cross(unit_vector(lookat - lookfrom), Vector(0, 1, 0));
			return true;
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_PAGEUP)) {
			selected = nullptr;
			return false;
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_HOME)) {
			if (selected_index == stage->size)
				selected_index = 0;
			selected = stage->list[selected_index++];
			return false;
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_RETURN)) {
			if (lock == 0)
				lock = 1;
			else
				lock = 0;
			return true;
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_END)) {
			(void)cam;
			if (render_mode == 0) {
				render_mode = 1;
				aperture = 0.05f;
			}
			else {
				render_mode = 0;
				pixel_size = 8;
				aperture = 0.0f;
			}
			return (true);
		}
	}
	return (false);
}
