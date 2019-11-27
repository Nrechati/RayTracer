/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Object.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:14:08 by nrechati          #+#    #+#             */
/*   Updated: 2019/11/27 09:09:41 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_OBJECT_H
# define A_OBJECT_H
# include <iostream>

struct hit_result {
	float	t;
	Vector	p;
	Vector	normal;
};

class A_Object
{
	public:
		virtual void hit (const ray& r, float t_min, float t_max, hit_result& result) = 0;
};

std::ostream	&operator<< (std::ostream &out, const A_Object &rhs);

#endif
