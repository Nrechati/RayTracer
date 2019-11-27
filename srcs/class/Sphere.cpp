/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sphere.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:14:17 by nrechati          #+#    #+#             */
/*   Updated: 2019/11/27 10:45:59 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/RayTracer.hpp"

/*
** Constructor / Destructor
*/

Sphere::Sphere(void) {
	std::cout << "Default constructor called" << std::endl;
	return;
}

Sphere::Sphere(Vector center, float radius) : center(center), radius(radius) {
	return;
}

Sphere::~Sphere(void) {
	std::cout << "Sphere destructor called" << std::endl;
	return;
}

/*
** Method and Member fucntion
*/

bool			Sphere::hit(const Ray& r, float t_min, float t_max, hit_result& result) const{
	Vector	oc = r.origin() - center;
	float	a = dot(r.direction(), r.direction());
	float	b = dot(oc, r.direction());
	float	c = dot(oc,oc) - radius * radius;
	float	discriminant = b*b - a*c;
	if (discriminant > 0) {
		float tmp = (-b - sqrt(discriminant)) / a; //REALLY ?
		if (tmp < t_max && tmp > t_min) {
			result.t = tmp;
			result.p = r.pt_at_param(result.t);
			result.normal = (result.p - center) / radius;
			return true;
		}
		tmp = (-b + sqrt(discriminant)) / a;
		if (tmp < t_max && tmp > t_min) {
			result.t = tmp;
			result.p = r.pt_at_param(result.t);
			result.normal = (result.p - center) / radius;
			return true;
		}
	}
	return false;
}

/*
** Static function
*/

std::ostream	&operator<<(std::ostream &out, Sphere const &rhs) {
	out << " Sphere specification is :" << std::endl;
	out << " Center {" << rhs.center.values[0] << ","
		<< rhs.center.values[0] << "," << rhs.center.values[0] << "}"
		<< " and Radius =" << rhs.radius << std::endl;
	return (out);
	}
