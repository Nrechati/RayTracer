/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Camera.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:14:17 by nrechati          #+#    #+#             */
/*   Updated: 2020/01/22 12:14:22 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/Camera.hpp"

/*
** Constructor / Destructor
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

Camera::~Camera(void) { return; }

/*
** Method and Member fucntion
*/

Vector	Camera::random_in_unit_disk(void) {
	Vector p;
	do {
		p = 2.0f * Vector(drand48(), drand48(),0) - Vector(1,1,0);
	} while (dot(p,p) >= 1.0f);
	return p;
}

Ray		Camera::getRay(float s, float t) {
	Vector	rd = this->lens_radius * random_in_unit_disk();
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
