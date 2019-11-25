/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Color.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:51:21 by nrechati          #+#    #+#             */
/*   Updated: 2019/11/25 16:12:24 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
#define COLOR_H
#include <iostream>
#include <array>
#include "class/Vector.hpp"
#include </Users/nrechati/.brew/Cellar/sdl2/2.0.10/include/SDL2/SDL.h>

class Color : public Vector
{
	public:
		/* Construcotr/Destructor */
		Color();
		Color(float r, float g, float b);
		virtual ~Color(void);

		/* Methods */
		inline float r() const { return this->values[0]; }
		inline float g() const { return this->values[1]; }
		inline float b() const { return this->values[2]; }

		inline void		setCValue(void);
		inline uint32_t	getCValue(void) { return this->color_value; }

		void			setRGB(float r, float g, float b);
		void			print(void) const;

	private:
		uint32_t	color_value;

};

#endif
