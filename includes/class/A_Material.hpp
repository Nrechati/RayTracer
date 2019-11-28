/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Material.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:13:58 by nrechati          #+#    #+#             */
/*   Updated: 2019/11/27 10:30:56 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_MATERIAL_H
# define A_MATERIAL_H
# include "core/RayTracer.hpp"

class A_Material
{
	public:
		virtual bool scatter(const Ray& r_in, const hit_result& result, Vector& attenuation, Ray& scattered) const = 0;
};

#endif
