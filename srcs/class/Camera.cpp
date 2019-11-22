/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Camera.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:14:17 by nrechati          #+#    #+#             */
/*   Updated: 2019/11/21 17:19:35 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/Camera.hpp"

/*
** Constructor / Destructor
*/
Camera::Camera(void) {
	std::cout << "Default constructor called" << std::endl;
	return;
}

Camera::Camera(Camera const& src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Camera::~Camera(void) {
	std::cout << "Default destructor called" << std::endl;
	return;
}

/*
** Overload operator
*/
Camera&		Camera::operator=(Camera const& rhs) {
	std::cout << "Assignation operator called" << std::endl;
	(void)rhs;/*Assignation code*/
	return *this;
}

std::ostream		&operator<<(std::ostream &out, Camera const &rhs) {
	out << " Print Message " << std::endl;
	(void)rhs;
	return (out);
	}

/*
** Method and Member fucntion
*/
