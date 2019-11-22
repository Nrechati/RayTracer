/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:17:01 by nrechati          #+#    #+#             */
/*   Updated: 2019/11/21 18:24:52 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/Window.hpp"

/*
** Constructor / Destructor
*/
Window::Window(void) : width(1280), height(720), name("Unamed") {
		this->initialize();
}

Window::Window(std::string name) : width(1280), height(720), name(name) {
        this->initialize();
}

Window::~Window(void)
{
	SDL_FreeSurface(this->surface);
	SDL_DestroyWindow(this->window);
	SDL_Quit();
}

/*
** Overload operator
*/

std::ostream		&operator<<(std::ostream &out, Window const &rhs) {
	out << " Print Message " << std::endl;
	(void)rhs;
	return (out);
	}

/*
** Method and Member fucntion
*/

void	Window::initialize(void) {
	SDL_Init(SDL_INIT_VIDEO);
	char	name[] = "Unamed";
	this->window = SDL_CreateWindow(name,
										  SDL_WINDOWPOS_UNDEFINED,
										  SDL_WINDOWPOS_UNDEFINED,
										  this->width,
										  this->height,
										  SDL_WINDOW_SHOWN);
	this->nb_frames = 0;
	this->timestamp = SDL_GetTicks();
	this->surface = SDL_GetWindowSurface(this->window);
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

