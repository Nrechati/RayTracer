/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ray.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:13:58 by nrechati          #+#    #+#             */
/*   Updated: 2019/11/25 16:56:18 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H
# include <iostream>
#include "class/Vector.hpp"

class Ray
{
	public:
		Ray(void);
		Ray(const Vector& origin, const Vector& direction);
		virtual ~Ray(void) {} ;

		Vector	origin(void) const { return this->O; }
		Vector	direction(void) const { return this->dir; }
		Vector	pt_at_param(float t) const { return (this->O + (this->dir * t)); }

		Vector O;
		Vector dir;
};


#endif
