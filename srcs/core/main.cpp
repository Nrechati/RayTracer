/* **************************************************************************** */
/*                                                                              */
/*                                                         :::      ::::::::    */
/*    main                                               :+:      :+:    :+:    */
/*                                                     +:+ +:+         +:+      */
/*    By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+         */
/*                                                 +#+#+#+#+#+   +#+            */
/*    Created: 2019/10/18 09:45:47 by nrechati          #+#    #+#              */
/*    Updated: 2019/10/18 09:47:02 by nrechati         ###   ########.fr        */
/*                                                                              */
/* **************************************************************************** */

#include "core/RayTracer.hpp"

bool			poll_event(Window &window, SDL_Event *event) {
	while (SDL_PollEvent(event))
	{
		if (event->type == SDL_QUIT || (event->type == SDL_KEYDOWN
					&& event->key.keysym.sym == SDLK_ESCAPE))
		{
			window.updateRunning(false);
			return (false);
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_SPACE))
		{
			std::cout << "Render" << std::endl;
			return (true);
		}
	}
	return (false);
}

Vector			random_in_unit_sphere() {
	Vector	p;
	do {
		p = 2.0f * Vector(drand48(), drand48(), drand48()) - Vector(1,1,1);
	} while (p.squared_lenght() >= 1.0f);
	return p;
}

Vector			reflect(const Vector &v, const Vector &n) {
	return v - 2*dot(v,n)*n;
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

Vector			getColor(const Ray& r, A_Object *stage, int depth) {
	hit_result	result;
	if (stage->hit(r, 0.001f, MAXFLOAT, result)) {
		Ray		scattered;
		Vector	attenuation;
		if (result.mat_ptr == nullptr)
			exit(0);
		if (depth < 50 && result.mat_ptr->scatter(r, result, attenuation, scattered)) {
			return attenuation * getColor(scattered, stage, depth + 1);
		}
		else {
			return (Vector(0,0,0));
		}
	}
	else {
		Vector	unit_direction = unit_vector(r.direction());
		float	t = 0.5f * (unit_direction.y() + 1.0f);
		return ((1.0f - t) * Vector(1.0f, 1.0f, 1.0f) + t * Vector(0.5f, 0.7f, 1.0f));
	}
}

void			render(Window &window) {

	int			ns = 100;
	Color		color;
	Camera		cam;

	A_Object	*list[4];
	A_Object	*stage;

	list[0] = new Sphere(Vector(0.0f,0.0f,-1.0f), 0.5f, new lambertian(Vector(0.8f, 0.3f, 0.3f)));
	list[1] = new Sphere(Vector(0.0f, -100.5f, -1.0f), 100.0f, new lambertian(Vector(0.8f, 0.8f, 0.0f)));
	list[2] = new Sphere(Vector(1.0f, 0.0f, -1.0f), 0.5f, new metal(Vector(0.8f, 0.6f, 0.2f)));
	list[3] = new Sphere(Vector(-1.0f, 0.0f, -1.0f), 0.5f, new metal(Vector(0.8f, 0.8f, 0.8f)));

	stage = new Stage(list, 4);

	SDL_LockSurface(window.getSurface());
	for (int j = window.height - 1; j >= 0; j--) {
		for (int i = 0; i < window.width; i++) {
			Vector col_vector(0,0,0);
			for (int s=0; s < ns; s++) {
				float u = float(i + drand48()) / float(window.width);
				float v = float(j + drand48()) / float(window.height);

				Ray r = cam.getRay(u, v);
				Vector p = r.pt_at_param(2.0f); // REALLY ?
				col_vector += getColor(r, stage, 0);
			}
			col_vector = col_vector / float(ns);
			col_vector = Vector(sqrt(col_vector[0]), sqrt(col_vector[1]), sqrt(col_vector[2]));
			Color	color(col_vector[0], col_vector[1], col_vector[2]);
			window.put_pixel(i, j, color.getCValue());
		}
	}
	SDL_UnlockSurface(window.getSurface());
}

void			run_engine(Window &window) {
	bool	render_needed = true;
	while (window.running() == true) {
		window.show_fps();
		if (render_needed == true)
			render(window);
		render_needed = poll_event(window, window.getEvent());
		SDL_UpdateWindowSurface(window.getWindow());
	}
}

int				main() {
	try {
		Window *window = new Window("RayTracer", WIDTH, HEIGHT);
		run_engine(*window);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		return (1);
	}
	return 0;
}
