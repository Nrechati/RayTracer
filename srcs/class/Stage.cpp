/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stage.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:14:17 by nrechati          #+#    #+#             */
/*   Updated: 2019/11/28 12:07:17 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/Stage.hpp"

/*
** Constructor / Destructor
*/
Stage::Stage(void) {
	return;
}

Stage::Stage(A_Object **lst, int n) {
	this->list = lst;
	this->size = n;
	return;
}

Stage::~Stage(void) {
	std::cout << "Stage destructor called" << std::endl;
	return;
}

/*
** Methods
*/

bool	Stage::hit(const Ray &r, float t_min, float t_max, hit_result &result) const {
	hit_result	tmp_res;
	bool		hitted_smth = false;
	double		closest_hit = t_max;
	for (int i = 0; i < this->size; i++) {
		if (list[i]->hit(r, t_min, closest_hit, tmp_res)) {
			hitted_smth = true;
			closest_hit = tmp_res.t;
			result = tmp_res;
		}
	}
	return hitted_smth;
}


/*
** Static Function
*/

std::ostream		&operator<<(std::ostream &out, Stage const &rhs)
{
	out << " Stage has " << rhs.size << " Objects in it" << std::endl;
	return (out);
	}
