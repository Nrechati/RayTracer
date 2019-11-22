/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:17:58 by nrechati          #+#    #+#             */
/*   Updated: 2019/11/21 18:21:56 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H
# include <iostream>
# include </Users/nrechati/.brew/Cellar/sdl2/2.0.10/include/SDL2/SDL.h>
class Window
{
	public:
		Window(void);
		Window(std::string name);
		virtual ~Window(void);

		void	show_fps(void);
		SDL_Window			*window;

	private:
		int					nb_frames;
		double				timestamp;
		const int			width;
		const int			height;
		const std::string	name;
		SDL_Surface			*surface;
		//SDL_Event			*event;

		void				initialize(void);

};

std::ostream	&operator<< (std::ostream &out, const Window &rhs);

#endif
