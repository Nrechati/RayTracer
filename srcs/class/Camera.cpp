/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Camera.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:14:17 by nrechati          #+#    #+#             */
/*   Updated: 2019/12/04 16:02:11 by nrechati         ###   ########.fr       */
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
Camera::Camera(Vector lookfrom, Vector lookat, Vector vup, float vfov, float aspect, float aperture, float focus_dist) {
	this->lens_radius = aperture / 2;
	float theta = vfov*M_PI/180;
	float half_height = tan(theta/2);
	float half_width = aspect * half_height;
	origin = lookfrom;
	this->w = unit_vector(lookfrom - lookat);
	this->u = unit_vector(cross(vup, w));
	this->v = cross(w,u);
	//this->lower_left_corner = Vector(-half_width, -half_height, -1.0f); //REALLY ?
	//this->lower_left_corner = origin - half_width * u - half_height * v - w;
	this->lower_left_corner = origin - half_width*focus_dist*u - half_height*focus_dist*v - focus_dist*w;
	this->horizontal = 2*half_width*focus_dist*u;
	this->vertical = 2*half_height*focus_dist*v;
}

Camera::~Camera(void) {
	//std::cout << "Camera destructor called" << std::endl;
	return;
}

/*
** Method and Member fucntion
*/

Vector	Camera::random_in_unit_disk(void) {
	Vector p;
	do {
		p = 2.0f*Vector(drand48(), drand48(),0) - Vector(1,1,0);
	} while (dot(p,p) >= 1.0f);
	return p;
}

Ray		Camera::getRay(float s, float t) {
	Vector	rd = this->lens_radius*random_in_unit_disk();
	Vector	offset = u * rd.x() + v*rd.y();
	return Ray(origin + offset, lower_left_corner + s * horizontal + t * vertical - origin - offset);
}

/*
** Static function
*/

std::ostream		&operator<<(std::ostream &out, Camera const &rhs) {
	out << " Camera is on " << std::endl;
	(void)rhs;
	return (out);
	}
