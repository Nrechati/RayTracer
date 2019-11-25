/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sphere.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:14:17 by nrechati          #+#    #+#             */
/*   Updated: 2019/11/25 13:58:51 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/Sphere.hpp"

/*
** Constructor / Destructor
*/
Sphere::Sphere(void) {
	std::cout << "Default constructor called" << std::endl;
	return;
}

Sphere::Sphere(Sphere const& src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Sphere::~Sphere(void) {
	std::cout << "Default destructor called" << std::endl;
	return;
}

/*
** Overload operator
*/
Sphere&		Sphere::operator=(Sphere const& rhs) {
	std::cout << "Assignation operator called" << std::endl;
	(void)rhs;/*Assignation code*/
	return *this;
}

std::ostream		&operator<<(std::ostream &out, Sphere const &rhs) {
	out << " Print Message " << std::endl;
	(void)rhs;
	return (out);
	}

	/*
** Method and Member fucntion
*/
