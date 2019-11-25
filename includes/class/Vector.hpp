/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:00:02 by nrechati          #+#    #+#             */
/*   Updated: 2019/11/25 16:55:12 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <stdlib.h>
#include <math.h>

class Vector
{
	public:
		/* Construcotr/Destructor */
		Vector(void);
		Vector(float first, float second, float third);
		virtual ~Vector(void);

		/* Methods */
		float x(void) const;
		float y(void) const;
		float z(void) const;

		float	length() const;
		float	squared_lenght() const;
		void 	make_unit_vector();
		void			setValues(float x, float y, float z);

		/* Operator Overloads */
		Vector			operator-() const;
		const Vector&	operator+() const { return *this; }
		float			operator[](int i) const { return values[i]; }
		float&			operator[](int i) { return values[i]; }

		Vector&			operator+=(const Vector &v2);
		Vector&			operator-=(const Vector &v2);
		Vector&			operator*=(const Vector &v2);
		Vector&			operator/=(const Vector &v2);
		Vector&			operator*=(float t);
		Vector&			operator/=(float t);

		/* Public Attribute */
		float	values[3];

};

std::istream&	operator>>(std::istream &is, Vector &rhs);
std::ostream&	operator<<(std::ostream &os, const Vector &rhs);

Vector			operator+(const Vector &lhs, const Vector &rhs);
Vector			operator-(const Vector &lhs, const Vector &rhs);
Vector			operator*(const Vector &lhs, const Vector &rhs);
Vector			operator/(const Vector &lhs, const Vector &rhs);
Vector			operator*(const Vector &lhs, float t);
Vector			operator/(const Vector &lhs, float t);

float			dot(const Vector &lhs, const Vector &rhs);
Vector			cross(const Vector &lhs, const Vector &rhs);
Vector			unit_vector(Vector vec);

#endif
