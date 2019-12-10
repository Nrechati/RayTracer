/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Object.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:14:08 by nrechati          #+#    #+#             */
/*   Updated: 2019/12/09 16:47:41 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_OBJECT_H
# define A_OBJECT_H
# include "core/RayTracer.hpp"

class A_Material;

struct hit_result {
	float		t;
	Vector		p;
	Vector		normal;
	A_Material	*mat_ptr;
};

class A_Object
{
	public:
		virtual bool hit (const Ray& r, float t_min, float t_max, hit_result& result) const = 0;
};

#endif
