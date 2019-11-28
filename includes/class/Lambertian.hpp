/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lambertian.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:01:10 by nrechati          #+#    #+#             */
/*   Updated: 2019/11/28 11:02:25 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAMBERTIAN_H
# define LAMBERTIAN_H
# include "core/RayTracer.hpp"

Vector			reflect(const Vector &v, const Vector &n) {
	return v - 2 * dot(v, n) * n;
}

class lambertian : public A_Material {
	public:
		lambertian(const Vector& a) : albedo(a) {}
		virtual bool scatter(const Ray& r_in, const hit_result& result, Vector& attenuation, Ray& scattered) const {
			(void)r_in; //REALLY ?
			Vector target = result.p + result.normal + random_in_unit_sphere();
			scattered = Ray(result.p, target - result.p);
			attenuation = albedo;
			return true;
		}
		Vector albedo;
};

class metal : public A_Material {
	public:
		metal(const Vector& a) : albedo(a) {}
		virtual bool scatter(const Ray& r_in, const hit_result& result, Vector& attenuation, Ray& scattered) const {
			Vector reflected = reflect(unit_vector(r_in.direction()), result.normal);
			scattered = Ray(result.p, reflected);
			attenuation = albedo;
			return (dot(scattered.direction(), result.normal) > 0);
		}
		Vector albedo;
};

#endif
