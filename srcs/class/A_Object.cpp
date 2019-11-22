/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:14:17 by nrechati          #+#    #+#             */
/*   Updated: 2019/10/22 14:13:57 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/A_Object.hpp"

/*
** Constructor / Destructor
*/
A_Object::A_Object(void) {
	std::cout << "Default constructor called" << std::endl;
	return;
}

A_Object::A_Object(A_Object const& src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

A_Object::~A_Object(void) {
	std::cout << "Default destructor called" << std::endl;
	return;
}

/*
** Overload operator
*/
A_Object&		A_Object::operator=(A_Object const& rhs) {
	std::cout << "Assignation operator called" << std::endl;
	(void)rhs;/*Assignation code*/
	return *this;
}

std::ostream		&operator<<(std::ostream &out, A_Object const &rhs) {
	out << " Print Message " << std::endl;
	(void)rhs;
	return (out);
	}

	/*
** Method and Member fucntion
*/
