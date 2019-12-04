/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:17:01 by nrechati          #+#    #+#             */
/*   Updated: 2019/12/03 12:17:14 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/RayTracer.hpp"

/*
** Constructor / Destructor
*/
Window::Window(void) : width(WIDTH), height(HEIGHT), name("Unamed") {
		this->initialize();
}

Window::Window(std::string name) : width(WIDTH), height(HEIGHT), name(name) {
        this->initialize();
}

Window::Window(std::string name, size_t width, size_t height) : width(width),
																height(height),
																name(name) {
	this->initialize();
}

Window::~Window(void)
{
	std::cout << "Destructing window" << std::endl;
	SDL_FreeSurface(this->surface);
	SDL_DestroyWindow(this->window);
	SDL_Quit();
}

/*
** Overload operator
*/
std::ostream		&operator<<(std::ostream &out, Window const &rhs) {
	out	<< " Window specification:" << std::endl;
	out	<< "\tName is " << rhs.name << std::endl;
	out	<< "\tWindow size is " << rhs.width << "x" << rhs.height << std::endl;
	return (out);
	}

/*
** Set/Getters
*/
void			Window::updateRunning(const bool running) { this->status = running; }
bool			Window::running(void) const { return this->status; }
SDL_Window*		Window::getWindow(void) const { return this->window; }
SDL_Surface*	Window::getSurface(void) const { return this->surface; }
SDL_Event*		Window::getEvent(void) { return &this->event; }


/*
** Method and Member fucntion
*/
void	Window::initialize(void) {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		throw Window::SDL_Init_Exception();
	}
	this->window = SDL_CreateWindow(this->name.data(),
									SDL_WINDOWPOS_UNDEFINED,
									SDL_WINDOWPOS_UNDEFINED,
									this->width,
									this->height,
									SDL_WINDOW_SHOWN);
	this->nb_frames = 0;
	this->status = true;
	this->timestamp = SDL_GetTicks();
	this->surface = SDL_GetWindowSurface(this->window);
	if (this->window == nullptr || this->window == nullptr) {
		throw Window::SDL_Window_Exception();
	}
}

void	Window::show_fps(void) {
	double currenttime = SDL_GetTicks();

	if (currenttime - this->timestamp >= 1000)
	{
		std::cout << this->nb_frames << " fps\n";
		this->nb_frames = 0;
		this->timestamp += 1000;
	}
	this->nb_frames++;
}

void	Window::put_pixel(size_t x, size_t y, uint32_t color)
{
	uint32_t *pixels;

	pixels = (uint32_t*)this->surface->pixels;
	pixels[x + ((this->height - 1 - y) * this->width)] = color;
}
