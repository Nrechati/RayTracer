/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:17:58 by nrechati          #+#    #+#             */
/*   Updated: 2019/11/22 15:22:45 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H
# include <iostream>
# include </Users/nrechati/.brew/Cellar/sdl2/2.0.10/include/SDL2/SDL.h>
class Window
{
	public:
		/* Construcotr/Destructor */
		Window(void);
		Window(std::string name);
		virtual ~Window(void);

		/* Setters */
		void			setStatus(const bool);

		/* Getters */
		bool			getStatus(void) const;
		SDL_Window*		getWindow(void) const;
		SDL_Surface*	getSurface(void) const;
		SDL_Event*		getEvent(void);

		/* Methods */
		void show_fps(void);

	private:
		int					nb_frames;
		double				timestamp;
		const int			width;
		const int			height;
		const std::string	name;
		SDL_Window			*window;
		SDL_Surface			*surface;
		SDL_Event			event;
		bool				running;
		void				initialize(void);

};

std::ostream	&operator<< (std::ostream &out, const Window &rhs);

#endif
