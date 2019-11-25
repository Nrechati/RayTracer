/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Color.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:03:35 by nrechati          #+#    #+#             */
/*   Updated: 2019/11/25 13:49:36 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/Color.hpp"

/*
** Constructor / Destructor
*/
Color::Color(void) {
	this->red = 0;
	this->green = 0;
	this->blue = 0;
	this->setValue();
	return;
}

Color::Color(uint8_t r, uint8_t g, uint8_t b) {
	this->red = r;
	this->green = g;
	this->blue = b;
	this->setValue();
}

Color::~Color(void) {
	std::cout << "Color destruction" << std::endl;
}

/*
** Getters / Setters
*/

uint8_t		Color::getRed(void) const { return this->red; }
uint8_t		Color::getGreen(void) const { return this->green; }
uint8_t		Color::getBlue(void) const { return this->blue; }
uint32_t	Color::getValue(void) const { return this->color_value; }

void		Color::setRed(uint8_t red){
	this->red = red;
	this->setValue();
}

void		Color::setGreen(uint8_t green){
	this->green = green;
	this->setValue();
}
void		Color::setBlue(uint8_t blue){
	this->blue = blue;
	this->setValue();
}

void		Color::setValue(void) {
	this->color_value =  this->getRed() << 16 | this->getGreen() << 8 | this->getBlue();
}

/*
** Method and Member fucntion
*/

void		Color::print(void) const{
	printf("Color is : {r = %d | g = %d | b = %d}", this->red, this->green, this->blue);
}

void		Color::setRGB(uint8_t r, uint8_t g, uint8_t b) {
	this->red = r;
	this->green = g;
	this->blue = b;
	this->setValue();
}

