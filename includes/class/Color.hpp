/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Color.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:51:21 by nrechati          #+#    #+#             */
/*   Updated: 2019/11/25 12:45:52 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
#define COLOR_H
#include <iostream>
#include <array>
#include </Users/nrechati/.brew/Cellar/sdl2/2.0.10/include/SDL2/SDL.h>

class Color
{
	public:
		/* Construcotr/Destructor */
		Color(void);
		Color(uint8_t r, uint8_t g, uint8_t b);
		virtual ~Color(void);

		/* Methods */
		void		setRed(uint8_t);
		uint8_t		getRed(void) const;
		void		setGreen(uint8_t);
		uint8_t		getGreen(void) const;
		void		setBlue(uint8_t);
		uint8_t		getBlue(void) const;

		void		setValue(void);
		uint32_t	getValue(void) const;

		void		print(void) const;
		void		setRGB(uint8_t r, uint8_t g, uint8_t b);

	private:
		uint8_t	red;
		uint8_t 	green;
		uint8_t 	blue;
		uint32_t	color_value;

};

#endif
