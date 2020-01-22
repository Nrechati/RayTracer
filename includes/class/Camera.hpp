/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Camera.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:13:58 by nrechati          #+#    #+#             */
/*   Updated: 2020/01/22 12:00:42 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
# include <core/RayTracer.hpp>

class Camera {
	public:
		Camera(void);
		Camera(Vector lookfrom, Vector lookat, Vector vup, float vfov, float aspect, float aperture, float focus_dist);
		virtual ~Camera(void);

		Ray		getRay(float s, float t);
		Vector	random_in_unit_disk(void);

		Vector	origin;
		Vector	lower_left_corner;
		Vector	horizontal;
		Vector	vertical;
		Vector	u,v,w;
		float	lens_radius;
};

std::ostream	&operator<< (std::ostream &out, const Camera &rhs);

#endif
