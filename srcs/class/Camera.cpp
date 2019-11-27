/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Camera.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:14:17 by nrechati          #+#    #+#             */
/*   Updated: 2019/11/27 11:45:35 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/Camera.hpp"

/*
** Constructor / Destructor
*/
Camera::Camera(void) {
	this->lower_left_corner = Vector(-2.0f, -1.0f, -1.0f);
	this->horizontal = Vector(4.0f,0.0f,0.0f);
	this->vertical = Vector(0.0f,2.0f,0.0f);
	this->origin = Vector(0.0f,0.0f,0.0f);
	return;
}

Camera::~Camera(void) {
	std::cout << "Camera destructor called" << std::endl;
	return;
}

/*
** Method and Member fucntion
*/

Ray		Camera::getRay(float u, float v) {
	return Ray(origin, lower_left_corner + u*horizontal + v*vertical - origin);
}

/*
** Static function
*/

std::ostream		&operator<<(std::ostream &out, Camera const &rhs) {
	out << " Camera is on " << std::endl;
	(void)rhs;
	return (out);
	}


