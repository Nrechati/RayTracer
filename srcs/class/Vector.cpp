/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:00:26 by nrechati          #+#    #+#             */
/*   Updated: 2019/11/25 16:11:54 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/Vector.hpp"

/*
** Constructor / Destructor
*/

Vector::Vector(void) {
	values[0] = 0;
	values[1] = 0;
	values[2] = 0;
	return;
}

Vector::Vector(float first, float second, float third) {
	values[0] = first;
	values[1] = second;
	values[2] = third;
	return;
}

Vector::~Vector(void) {
	std::cout << "Vector destructor called" << std::endl;
	return;
}

/*
** Get value
*/

inline float	Vector::x() const { return values[0]; }
inline float	Vector::y() const { return values[1]; }
inline float	Vector::z() const { return values[2]; }

/*
** Overload operators
*/

inline Vector	Vector::operator-() const {
	Vector	result(-values[0], -this->values[1], -values[2]);
	return  result;
}

inline Vector&	Vector::operator+=(const Vector &v) {
	values[0] += v.values[0];
	values[1] += v.values[1];
	values[2] += v.values[2];
	return *this;
}

inline Vector&	Vector::operator-=(const Vector &v) {
	values[0] -= v.values[0];
	values[1] -= v.values[1];
	values[2] -= v.values[2];
	return *this;
}

inline Vector&	Vector::operator*=(const Vector &v) {
	values[0] *= v.values[0];
	values[1] *= v.values[1];
	values[2] *= v.values[2];
	return *this;
}

inline Vector&	Vector::operator/=(const Vector &v) {
	values[0] /= v.values[0];
	values[1] /= v.values[1];
	values[2] /= v.values[2];
	return *this;
}

inline Vector&	Vector::operator*=(float t) {
	values[0] *= t;
	values[1] *= t;
	values[2] *= t;
	return *this;
}

inline Vector&	Vector::operator/=(float t) {
	float k = 1.0f / t;
	values[0] /= k;
	values[1] /= k;
	values[2] /= k;
	return *this;
}

/*
** Public Methods
*/

inline float	Vector::length() const {
	return (sqrt(values[0] * values[0]
				+ values[1] * values[1]
				+ values[2] * values[2]));
}

inline float	Vector::squared_lenght() const {
	return (values[0] * values[0]
				+ values[1] * values[1]
				+ values[2] * values[2]);
}

inline void		Vector::make_unit_vector() {
	float k = 1.0f / sqrt(values[0] * values[0]
						+ values[1] * values[1]
						+ values[2] * values[2]);
	values[0] *= k;
	values[1] *= k;
	values[2] *= k;
}


void			Vector::setValues(float x, float y, float z) {
	values[0] = x;
	values[1] = y;
	values[2] = z;
}

/*
** Static Vector functions
*/

inline std::istream &operator>>(std::istream &is, Vector &rhs) {
	is >> rhs.values[0] >> rhs.values[1] >> rhs.values[2];
	return is;
}

inline std::ostream &operator<<(std::ostream &os, Vector &rhs) {
	os << rhs.values[0] << rhs.values[1] << rhs.values[2];
	return os;
}


inline Vector		operator+(const Vector &lhs, const Vector &rhs) {
	Vector result(lhs.values[0] + rhs.values[0],
				  lhs.values[1] + rhs.values[1],
				  lhs.values[2] + rhs.values[2]);
	return (result);
}

inline Vector		operator-(const Vector &lhs, const Vector &rhs) {
	Vector result(lhs.values[0] - rhs.values[0],
				  lhs.values[1] - rhs.values[1],
				  lhs.values[2] - rhs.values[2]);
	return (result);
}

inline Vector		operator*(const Vector &lhs, const Vector &rhs) {
	Vector result(lhs.values[0] * rhs.values[0],
				  lhs.values[1] * rhs.values[1],
				  lhs.values[2] * rhs.values[2]);
	return (result);
}

inline Vector		operator/(const Vector &lhs, const Vector &rhs) {
	Vector result(lhs.values[0] / rhs.values[0],
				  lhs.values[1] / rhs.values[1],
				  lhs.values[2] / rhs.values[2]);
	return (result);
}

inline Vector		operator*(const Vector &lhs, float t) {
	Vector result(lhs.values[0] * t,
				  lhs.values[1] * t,
				  lhs.values[2] * t);
	return (result);
}

inline Vector		operator/(const Vector &lhs, float t) {
	Vector result(lhs.values[0] / t,
				  lhs.values[1] / t,
				  lhs.values[2] / t);
	return (result);
}

inline Vector		unit_vector(Vector v) {
	return (v / v.length());
}
