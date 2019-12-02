/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Camera.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:14:17 by nrechati          #+#    #+#             */
/*   Updated: 2019/12/02 13:48:43 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/Camera.hpp"

/*
** Constructor / Destructor
*/
/*
Camera::Camera(void) {
	this->lower_left_corner = Vector(-2.0f, -1.0f, -1.0f);
	this->horizontal = Vector(4.0f,0.0f,0.0f);
	this->vertical = Vector(0.0f,2.0f,0.0f);
	this->origin = Vector(0.0f,0.0f,0.0f);
	return;
}

Camera::Camera(float vfov, float aspect) {
	float	theta = vfov * M_PI/180;
	float	half_height = tan(theta/2);
	float	half_width = aspect * half_height;
	this->lower_left_corner = Vector(-half_width, -half_height, -1.0f);
	this->horizontal = Vector(2*half_width, 0.0f, 0.0f);
	this->vertical = Vector(0.0f, 2*half_height, 0.0f);
	this->origin = Vector(0.0f, 0.0f, 0.0f);
	return;
}
*/
Camera::Camera(Vector lookfrom, Vector lookat, Vector vup, float vfov, float aspect) {
	Vector	u,v,w;
	float theta = vfov*M_PI/180;
	float half_height = tan(theta/2);
	float half_width = aspect * half_height;
	origin = lookfrom;
	w = unit_vector(lookfrom - lookat);
	u = unit_vector(cross(vup, w));
	v = cross(w,u);
	this->lower_left_corner = Vector(-half_width, -half_height, -1.0f); //REALLY ?
	this->lower_left_corner = origin - half_width*u - half_height*v - w;
	this->horizontal = 2*half_width*u;
	this->vertical = 2*half_height*v;
}

Camera::~Camera(void) {
	//std::cout << "Camera destructor called" << std::endl;
	return;
}

/*
** Method and Member fucntion
*/

Ray		Camera::getRay(float s, float t) {
	return Ray(origin, lower_left_corner + s*horizontal + t*vertical - origin);
}

/*
** Static function
*/

std::ostream		&operator<<(std::ostream &out, Camera const &rhs) {
	out << " Camera is on " << std::endl;
	(void)rhs;
	return (out);
	}


