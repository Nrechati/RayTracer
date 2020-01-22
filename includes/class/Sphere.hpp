/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sphere.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:13:58 by nrechati          #+#    #+#             */
/*   Updated: 2020/01/22 12:01:38 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H
# include "core/RayTracer.hpp"

class A_Material;

class Sphere : public A_Object {
	public:
		Sphere(void);
		Sphere(Vector center, float radius, A_Material *mat_ptr);
		virtual ~Sphere(void);

		virtual bool hit(const Ray& r, float t_min, float t_max, hit_result& result) const;

		Vector		center;
		float		radius;
		A_Material	*mat_ptr;
};

std::ostream	&operator<< (std::ostream &out, const Sphere &rhs);

#endif
