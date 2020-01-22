/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_functions.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 13:14:04 by nrechati          #+#    #+#             */
/*   Updated: 2020/01/22 13:53:05 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/RayTracer.hpp"

extern uint8_t render_mode;

Vector random_in_unit_sphere() {
	if (render_mode == 0)
		return Vector(0, 0, 0);
	Vector p;
	do {
		p = 2.0f * Vector(drand48(), drand48(), drand48()) - Vector(1, 1, 1);
	} while (p.squared_lenght() >= 1.0f);
	return p;
}

Vector reflect(const Vector &v, const Vector &n) {
	return v - 2 * dot(v, n) * n;
}

bool refract(const Vector &v, const Vector &n, float ni_over_nt, Vector refracted)
{
	Vector uv = unit_vector(v);
	float dt = dot(uv, n);
	float discriminant = 1.0f - ni_over_nt * ni_over_nt * (1 - dt * dt);
	if (discriminant > 0) {
		refracted = ni_over_nt * (uv - n * dt) - n * sqrt(discriminant);
		return true;
	}
	else
		return false;
}
