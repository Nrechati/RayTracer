/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Color.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:51:21 by nrechati          #+#    #+#             */
/*   Updated: 2020/01/22 12:00:47 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "core/RayTracer.hpp"

class Color : public Vector {
	public:
		Color();
		Color(float r, float g, float b);
		virtual ~Color(void);

		float r() const { return this->values[0]; }
		float g() const { return this->values[1]; }
		float b() const { return this->values[2]; }

		void		setCValue(void);
		uint32_t	getCValue(void) { return this->color_value; }
		void		setRGB(float r, float g, float b);
		void		print(void) const;

	private:
		uint32_t	color_value;
};

#endif
