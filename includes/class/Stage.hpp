/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stage.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:13:58 by nrechati          #+#    #+#             */
/*   Updated: 2019/11/27 10:48:19 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STAGE_H
# define STAGE_H

#include "core/RayTracer.hpp"

class Stage : public A_Object
{
public:
	Stage(void);
	Stage(A_Object **lst, int n);
	virtual ~Stage(void);

	virtual bool hit(const Ray &r, float t_min, float t_max, hit_result &result) const;

	A_Object **list;
	int size;
};

std::ostream &operator<<(std::ostream &out, const Stage &rhs);

#endif
