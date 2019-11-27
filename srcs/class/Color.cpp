/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Color.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:03:35 by nrechati          #+#    #+#             */
/*   Updated: 2019/11/27 09:55:23 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/RayTracer.hpp"

/*
** Constructor / Destructor
*/

Color::Color() : Vector() {
	this->setCValue();
	return;
}

Color::Color(float r, float g, float b) : Vector(r,g,b){
	this->setCValue();
}

Color::~Color(void) {}

/*
** Getters / Setters
*/
void	Color::setCValue(void) {
	color_value = ((uint8_t)(values[0]*255)) << 16 | ((uint8_t)(values[1]*255)) << 8 | ((uint8_t)(values[2]*255));
}

/*
** Method and Member fucntion
*/

void	Color::print(void) const{
	printf("Color is : {r = %f | g = %f | b = %f}", values[0], values[1], values[2]);
}

void		Color::setRGB(float r, float g, float b) {
	this->setValues(r,g,b);
	this->setCValue();
}

