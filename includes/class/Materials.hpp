/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materials.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:09:43 by nrechati          #+#    #+#             */
/*   Updated: 2020/01/22 14:49:13 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIALS_H
# define MATERIALS_H
# include <core/RayTracer.hpp>

Vector	random_in_unit_sphere();
Vector	reflect(const Vector &v, const Vector &n);
bool	refract(const Vector &v, const Vector &n, float ni_over_nt, Vector refracted);

extern uint8_t render_mode;

class default_mat : public A_Material {
	public:
		default_mat(const Vector &a) : albedo(a) {}
		virtual bool scatter(const Ray &r_in, const hit_result &result, Vector &attenuation, Ray &scattered) const
		{
			(void)r_in;
			Vector target = result.p + result.normal + random_in_unit_sphere();
			scattered = Ray(result.p, target - result.p);
			attenuation = albedo;
			return true;
		}
		Vector albedo;
};

class metal : public A_Material {
	public:
		metal(const Vector &a, float f) : albedo(a)
		{
			if (f < 1)
				fuzz = f;
			else
				fuzz = 1;
		}
		virtual bool scatter(const Ray &r_in, const hit_result &result, Vector &attenuation, Ray &scattered) const
		{
			Vector reflected = reflect(unit_vector(r_in.direction()), result.normal);
			scattered = Ray(result.p, reflected + fuzz * random_in_unit_sphere());
			attenuation = albedo;
			if (render_mode == 0)
				return (true); //Low Render
			return (dot(scattered.direction(), result.normal) > 0);
		}
		Vector albedo;
		float fuzz;
};

/* Broken */
class dielectric : public A_Material {
	public:
		dielectric(float ri) : ref_idx(ri) {}
		virtual bool scatter(const Ray &r_in, const hit_result &result, Vector &attenuation, Ray &scattered) const
		{
			Vector outward_normal;
			Vector reflected = reflect(r_in.direction(), result.normal);
			float ni_over_nt;
			attenuation = Vector(1.0f, 1.0f, 0.0f);
			Vector refracted;
			if (dot(r_in.direction(), result.normal) > 0) {
				outward_normal = -result.normal;
				ni_over_nt = ref_idx;
			}
			else {
				outward_normal = result.normal;
				ni_over_nt = 1.0f / ref_idx;
			}
			if (refract(r_in.direction(), outward_normal, ni_over_nt, refracted)) {
				scattered = Ray(result.p, refracted);
			}
			else {
				scattered = Ray(result.p, reflected);
				return false;
			}
			return true;
		}
		float ref_idx;
};

#endif
