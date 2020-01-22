/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:17:58 by nrechati          #+#    #+#             */
/*   Updated: 2020/01/22 12:03:02 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H
# include <core/RayTracer.hpp>

class Window
{
	public:
		Window(void);
		Window(std::string name);
		Window(std::string name, size_t width, size_t height);
		virtual ~Window(void);

		void			updateRunning(const bool);
		bool			running(void) const;
		SDL_Window*		getWindow(void) const;
		SDL_Surface*	getSurface(void) const;
		SDL_Event*		getEvent(void);

		void show_fps(void);
		void put_pixel(size_t x, size_t y, uint32_t color);

		const int			width;
		const int			height;
		const std::string	name;

		class SDL_Init_Exception : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("SDL Initialization went wrong");
				}
		};
		class SDL_Window_Exception : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("SDL Window and/or surface creation went wrong");
				}
		};

	private:
		size_t				nb_frames;
		double				timestamp;
		SDL_Window			*window;
		SDL_Surface			*surface;
		SDL_Event			event;
		bool				status;
		void				initialize(void);

};

std::ostream	&operator<< (std::ostream &out, const Window &rhs);

#endif
