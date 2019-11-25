/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ray.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:14:17 by nrechati          #+#    #+#             */
/*   Updated: 2019/11/25 16:52:46 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/Ray.hpp"

/*
** Constructor / Destructor
*/
Ray::Ray(void) {
	std::cout << "Default constructor called" << std::endl;
	return;
}

Ray::Ray(const Vector& origin, const Vector& direction) {
	this->O = origin;
	this->dir = direction;
	return;
}

/*
** Overload operator
*/

/*
** Method and Member fucntion
*/
