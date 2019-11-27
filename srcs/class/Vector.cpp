/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:00:26 by nrechati          #+#    #+#             */
/*   Updated: 2019/11/27 09:55:36 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "core/RayTracer.hpp"

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

Vector::~Vector(void) {}

/*
** Get value
*/

float	Vector::x() const { return values[0]; }
float	Vector::y() const { return values[1]; }
float	Vector::z() const { return values[2]; }

/*
** Overload operators
*/

Vector	Vector::operator-() const {
	Vector	result(-values[0], -this->values[1], -values[2]);
	return  result;
}

Vector&	Vector::operator+=(const Vector &v) {
	values[0] += v.values[0];
	values[1] += v.values[1];
	values[2] += v.values[2];
	return *this;
}

Vector&	Vector::operator-=(const Vector &v) {
	values[0] -= v.values[0];
	values[1] -= v.values[1];
	values[2] -= v.values[2];
	return *this;
}

Vector&	Vector::operator*=(const Vector &v) {
	values[0] *= v.values[0];
	values[1] *= v.values[1];
	values[2] *= v.values[2];
	return *this;
}

Vector&	Vector::operator/=(const Vector &v) {
	values[0] /= v.values[0];
	values[1] /= v.values[1];
	values[2] /= v.values[2];
	return *this;
}

Vector&	Vector::operator*=(float t) {
	values[0] *= t;
	values[1] *= t;
	values[2] *= t;
	return *this;
}

Vector&	Vector::operator/=(float t) {
	float k = 1.0f / t;
	values[0] /= k;
	values[1] /= k;
	values[2] /= k;
	return *this;
}

/*
** Public Methods
*/

float	Vector::length() const {
	return (sqrt(values[0] * values[0]
				+ values[1] * values[1]
				+ values[2] * values[2]));
}

float	Vector::squared_lenght() const {
	return (values[0] * values[0]
				+ values[1] * values[1]
				+ values[2] * values[2]);
}

void		Vector::make_unit_vector() {
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

std::istream &operator>>(std::istream &is, Vector &rhs) {
	is >> rhs.values[0] >> rhs.values[1] >> rhs.values[2];
	return is;
}

std::ostream &operator<<(std::ostream &os, Vector &rhs) {
	os << rhs.values[0] << rhs.values[1] << rhs.values[2];
	return os;
}


Vector		operator+(const Vector &lhs, const Vector &rhs) {
	Vector result(lhs.values[0] + rhs.values[0],
				  lhs.values[1] + rhs.values[1],
				  lhs.values[2] + rhs.values[2]);
	return (result);
}

Vector		operator-(const Vector &lhs, const Vector &rhs) {
	Vector result(lhs.values[0] - rhs.values[0],
				  lhs.values[1] - rhs.values[1],
				  lhs.values[2] - rhs.values[2]);
	return (result);
}

Vector		operator*(const Vector &lhs, const Vector &rhs) {
	Vector result(lhs.values[0] * rhs.values[0],
				  lhs.values[1] * rhs.values[1],
				  lhs.values[2] * rhs.values[2]);
	return (result);
}

Vector		operator/(const Vector &lhs, const Vector &rhs) {
	Vector result(lhs.values[0] / rhs.values[0],
				  lhs.values[1] / rhs.values[1],
				  lhs.values[2] / rhs.values[2]);
	return (result);
}

Vector		operator*(const Vector &lhs, float t) {
	Vector result(lhs.values[0] * t,
				  lhs.values[1] * t,
				  lhs.values[2] * t);
	return (result);
}

Vector		operator*(float t, const Vector &lhs) {
	Vector result(lhs.values[0] * t,
				  lhs.values[1] * t,
				  lhs.values[2] * t);
	return (result);
}

Vector		operator/(const Vector &lhs, float t) {
	Vector result(lhs.values[0] / t,
				  lhs.values[1] / t,
				  lhs.values[2] / t);
	return (result);
}

float		dot(const Vector &v1, const Vector &v2){
	return v1.values[0]*v2.values[0]
			+ v1.values[1]*v2.values[1]
			+ v1.values[2]*v2.values[2];
}

Vector		cross(const Vector &v1, const Vector &v2){
	return Vector(v1.values[1]*v2.values[2] - v1.values[2]*v2.values[1]
			, (-(v1.values[0]*v2.values[2] - v1.values[2]*v2.values[0]))
			, v1.values[0]*v2.values[1] - v1.values[1]*v2.values[0]);
}

Vector		unit_vector(Vector v) {
	return (v / v.length());
}
