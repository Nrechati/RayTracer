/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stage.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 13:56:10 by nrechati          #+#    #+#             */
/*   Updated: 2020/01/22 14:12:21 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/RayTracer.hpp"

extern uint8_t render_mode;

Stage *init_stage()
{
	int n = 100; //To fix
	int i = 1;
	A_Object **list = new A_Object *[n + 1];

	// Support
	list[0] = new Sphere(Vector(0, -1000, 0), 1000, new default_mat(Vector(0.5f, 0.5f, 0.5f)));

	// Right part
	list[i++] = new Sphere(Vector(3, 0.2f, -3), 0.2f, new default_mat(Vector(drand48() * drand48(), drand48() * drand48(), drand48() * drand48())));
	list[i++] = new Sphere(Vector(2, 0.4f, -4), 0.4f, new metal(Vector(drand48() * drand48(), drand48() * drand48(), drand48() * drand48()), 0.1f));
	list[i++] = new Sphere(Vector(-1, 0.4f, -7.5f), 0.4f, new metal(Vector(drand48() * drand48(), drand48() * drand48(), drand48() * drand48()), 0.0f));
	list[i++] = new Sphere(Vector(-2.5, 0.3f, -8), 0.3f, new default_mat(Vector(drand48() * drand48(), drand48() * drand48(), drand48() * drand48())));
	list[i++] = new Sphere(Vector(2.5f, 0.1f, -3), 0.1f, new default_mat(Vector(drand48() * drand48(), drand48() * drand48(), drand48() * drand48())));
	list[i++] = new Sphere(Vector(3, 0.2f, -2), 0.2f, new metal(Vector(drand48() * drand48(), drand48() * drand48(), drand48() * drand48()), 0.0f));
	list[i++] = new Sphere(Vector(3.5f, 0.3f, -1), 0.3f, new default_mat(Vector(drand48() * drand48(), drand48() * drand48(), drand48() * drand48())));
	list[i++] = new Sphere(Vector(3, 0.15f, -0.5), 0.15f, new metal(Vector(drand48() * drand48(), drand48() * drand48(), drand48() * drand48()), 0.3f));

	// Left part
	list[i++] = new Sphere(Vector(1, 0.2f, 1), 0.2f, new default_mat(Vector(drand48() * drand48(), drand48() * drand48(), drand48() * drand48())));
	list[i++] = new Sphere(Vector(-1, 0.4f, 1), 0.4f, new metal(Vector(drand48() * drand48(), drand48() * drand48(), drand48() * drand48()), 0.2f));
	list[i++] = new Sphere(Vector(1, 0.3f, 2), 0.3f, new metal(Vector(drand48() * drand48(), drand48() * drand48(), drand48() * drand48()), 0.0f));
	list[i++] = new Sphere(Vector(-1, 0.2f, 2), 0.2f, new metal(Vector(drand48() * drand48(), drand48() * drand48(), drand48() * drand48()), 0.3f));
	list[i++] = new Sphere(Vector(-1.5, 0.1f, 2.5), 0.1f, new default_mat(Vector(drand48() * drand48(), drand48() * drand48(), drand48() * drand48())));
	list[i++] = new Sphere(Vector(-3, 0.5f, 3), 0.5f, new default_mat(Vector(drand48() * drand48(), drand48() * drand48(), drand48() * drand48())));
	list[i++] = new Sphere(Vector(-5, 0.5f, 2), 0.5f, new metal(Vector(drand48() * drand48(), drand48() * drand48(), drand48() * drand48()), 0.0f));
	list[i++] = new Sphere(Vector(0, 0.15f, 1.5f), 0.15f, new metal(Vector(0.7f, 0.6f, 0.5f), 0.0f));
	list[i++] = new Sphere(Vector(0, 0.35f, 0.5f), 0.35f, new metal(Vector(0.7f, 0.6f, 0.5f), 0.0f));
	list[i++] = new Sphere(Vector(1, 0.1f, 1.5f), 0.1f, new metal(Vector(drand48() * drand48(), drand48() * drand48(), drand48() * drand48()), 0.4f));
	list[i++] = new Sphere(Vector(2, 0.2f, 1.5f), 0.2f, new metal(Vector(drand48() * drand48(), drand48() * drand48(), drand48() * drand48()), 0.0f));
	list[i++] = new Sphere(Vector(2.5f, 0.4f, 0.5f), 0.4f, new metal(Vector(drand48() * drand48(), drand48() * drand48(), drand48() * drand48()), 0.0f));

	// Center Part
	list[i++] = new Sphere(Vector(-3, 1, -1), 1.0f, new default_mat(Vector(0.1f, 0.2f, 0.5f)));
	list[i++] = new Sphere(Vector(-0.5, 1, -1), 1.0f, new metal(Vector(0.8f, 0.6f, 0.2f), 0.05f));
	list[i++] = new Sphere(Vector(2, 1, -1), 1.0f, new metal(Vector(0.7f, 0.6f, 0.5f), 0.0f));
	return new Stage(list, i);
}
