/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:00:02 by nrechati          #+#    #+#             */
/*   Updated: 2019/11/25 16:11:59 by nrechati         ###   ########.fr       */
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
		inline float x(void) const;
		inline float y(void) const;
		inline float z(void) const;

		inline float	length() const;
		inline float	squared_lenght() const;
		inline void 	make_unit_vector();
		void			setValues(float x, float y, float z);

		/* Operator Overloads */
		inline Vector			operator-() const;
		inline const Vector&	operator+() const { return *this; }
		inline float			operator[](int i) const { return values[i]; }
		inline float&			operator[](int i) { return values[i]; }

		inline Vector&			operator+=(const Vector &v2);
		inline Vector&			operator-=(const Vector &v2);
		inline Vector&			operator*=(const Vector &v2);
		inline Vector&			operator/=(const Vector &v2);
		inline Vector&			operator*=(float t);
		inline Vector&			operator/=(float t);

		/* Public Attribute */
		float	values[3];

};

inline std::istream&	operator>>(std::istream &is, Vector &rhs);
inline std::ostream&	operator<<(std::ostream &os, const Vector &rhs);

inline Vector			operator+(const Vector &lhs, const Vector &rhs);
inline Vector			operator-(const Vector &lhs, const Vector &rhs);
inline Vector			operator*(const Vector &lhs, const Vector &rhs);
inline Vector			operator/(const Vector &lhs, const Vector &rhs);
inline Vector			operator*(const Vector &lhs, float t);
inline Vector			operator/(const Vector &lhs, float t);

inline float			dot(const Vector &lhs, const Vector &rhs);
inline Vector			cross(const Vector &lhs, const Vector &rhs);
inline Vector			unit_vector(Vector vec);

#endif
