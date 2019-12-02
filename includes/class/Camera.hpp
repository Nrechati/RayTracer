/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Camera.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:13:58 by nrechati          #+#    #+#             */
/*   Updated: 2019/12/02 13:48:19 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
# include <core/RayTracer.hpp>

class Camera
{
	public:
	//	Camera(void); //Useless
	//	Camera(float vfov, float aspect); // Useless
		Camera(Vector lookfrom, Vector lookat, Vector vup, float vfov, float aspect);
		virtual ~Camera(void);

		Ray		getRay(float s, float t);

		Vector	origin;
		Vector	lower_left_corner;
		Vector	horizontal;
		Vector	vertical;
};

std::ostream	&operator<< (std::ostream &out, const Camera &rhs);

#endif
