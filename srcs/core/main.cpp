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

// REMOVE GLOBAL
uint8_t	render_mode = 1;
uint8_t	pixel_size = 8;
Vector	lookfrom(6.5f, 1.8f, 1.0f);
Vector	lookat(0, 1, -1);
float	dist_to_focus = (lookfrom - lookat).length();
float	aperture = 0.0f;
bool	lock = false;

bool			poll_event(Window &window, Camera &cam, SDL_Event *event) {
	while (SDL_PollEvent(event))
	{
		if (event->type == SDL_QUIT || (event->type == SDL_KEYDOWN
					&& event->key.keysym.sym == SDLK_ESCAPE)) {
			window.updateRunning(false);
			return (false);
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_EQUALS)) {
			if (pixel_size <= 16)
				pixel_size *= 2;
			return true;
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_MINUS)) {
			if (pixel_size > 4)
				pixel_size /= 2;
			return true;
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_s)) {
			lookfrom -= 0.2f * unit_vector(lookat - lookfrom);
			if (lock == false)
				lookat -= 0.2f * unit_vector(lookat - lookfrom);
			return true;
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_w)) {
			lookfrom += 0.2f * unit_vector(lookat - lookfrom);
			if (lock == false)
				lookat += 0.2f * unit_vector(lookat - lookfrom);
			return true;
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_SPACE)) {
			lookfrom[1] += 0.2f;
			if (lock == false)
				lookat[1] += 0.2f;
			return true;
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_c)) {
			lookfrom[1] -= 0.2f;
			if (lock == false)
				lookat[1] -= 0.2f;
			return true;
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_d)) {
			lookfrom += 0.2f * cross(unit_vector(lookat - lookfrom), Vector(0,1,0));
			if (lock == false)
				lookat += 0.2f * cross(unit_vector(lookat - lookfrom), Vector(0,1,0));
			return true;
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_a)) {
			lookfrom -= 0.2f * cross(unit_vector(lookat - lookfrom), Vector(0,1,0));
			if (lock == false)
				lookat -= 0.2f * cross(unit_vector(lookat - lookfrom), Vector(0,1,0));
			return true;
		}
		if ((lock==false && event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_LEFT)) {
			lookat -= 0.3f * cross(unit_vector(lookat - lookfrom), Vector(0,1,0));
			return true;
		}
		if ((lock==false && event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_RIGHT)) {
			lookat += 0.3f * cross(unit_vector(lookat - lookfrom), Vector(0,1,0));
			return true;
		}
		if ((lock==false && event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_UP)) {
			lookat += 0.3f * Vector(0,1,0);
			return true;
		}
		if ((lock==false && event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_DOWN)) {
			lookat -= 0.3f * Vector(0,1,0);
			return true;
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_r)) {
			lookat = Vector(0, 1, -1);
			return true;
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_RETURN)) {
			if (lock == 0) {
				lock = 1;
			}
			else
				lock = 0;
			return true;
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_END)) {
			(void)cam;
			if (render_mode == 0) {
				render_mode = 1;
				aperture = 0.05f;
			}
			else {
				render_mode= 0;
				pixel_size = 8;
				aperture = 0.0f;
			}
			return (true);
		}
	}
	return (false);
}

Vector			random_in_unit_sphere() {
	if (render_mode == 0)
		return Vector(0,0,0);
	Vector	p;
	do {
		p = 2.0f * Vector(drand48(), drand48(), drand48()) - Vector(1,1,1);
	} while (p.squared_lenght() >= 1.0f);
	return p;

	//return Vector(0,0,0); // Low Render
}

Vector			reflect(const Vector &v, const Vector &n) {
	return v - 2*dot(v,n)*n;
}

bool			refract(const Vector& v, const Vector& n, float ni_over_nt, Vector refracted) {
	Vector	uv = unit_vector(v);
	float	dt = dot(uv,n);
	float discriminant = 1.0f - ni_over_nt * ni_over_nt * (1 - dt * dt);
	if (discriminant > 0) {
		refracted = ni_over_nt*(uv - n*dt) - n*sqrt(discriminant);
		return true;
	}
	else
		return false;
}

class default_mat : public A_Material {
	public:
		default_mat(const Vector& a) : albedo(a) {}
		virtual bool scatter(const Ray& r_in, const hit_result& result, Vector& attenuation, Ray& scattered) const {
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
		metal(const Vector& a, float f) : albedo(a) { if (f < 1) fuzz = f; else fuzz = 1; }
		virtual bool scatter(const Ray& r_in, const hit_result& result, Vector& attenuation, Ray& scattered) const {
			Vector reflected = reflect(unit_vector(r_in.direction()), result.normal);
			scattered = Ray(result.p, reflected + fuzz*random_in_unit_sphere());
			attenuation = albedo;
			if (render_mode == 0)
				return (true); //Low Render
			return (dot(scattered.direction(), result.normal) > 0);
		}
		Vector	albedo;
		float	fuzz;
};

class dielectric : public A_Material {
	public:
		dielectric(float ri) : ref_idx(ri) {}
		virtual bool scatter(const Ray& r_in, const hit_result& result, Vector& attenuation, Ray& scattered) const {
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
		float	ref_idx;
};

Vector			getColor(const Ray& r, A_Object *stage, int depth) {
	hit_result	result;
	result.mat_ptr = new default_mat(Vector(0.f,0.f,0.f)); // LEAKING
	if (stage->hit(r, 0.001f, MAXFLOAT, result)) {
		Ray		scattered;
		Vector	attenuation;
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

bool			poll_event(Window &window, Camera &cam, SDL_Event *event) {
	while (SDL_PollEvent(event))
	{
		if (event->type == SDL_QUIT || (event->type == SDL_KEYDOWN
					&& event->key.keysym.sym == SDLK_ESCAPE)) {
			window.updateRunning(false);
			return (false);
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_EQUALS)) {
			if (pixel_size <= 16)
				pixel_size *= 2;
			return true;
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_MINUS)) {
			if (pixel_size > 4)
				pixel_size /= 2;
			return true;
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_s)) {
			lookfrom -= 0.2f * unit_vector(lookat - lookfrom);
			if (lock == false)
				lookat -= 0.2f * unit_vector(lookat - lookfrom);
			return true;
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_w)) {
			lookfrom += 0.2f * unit_vector(lookat - lookfrom);
			if (lock == false)
				lookat += 0.2f * unit_vector(lookat - lookfrom);
			return true;
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_SPACE)) {
			lookfrom[1] += 0.2f;
			if (lock == false)
				lookat[1] += 0.2f;
			return true;
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_c)) {
			lookfrom[1] -= 0.2f;
			if (lock == false)
				lookat[1] -= 0.2f;
			return true;
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_d)) {
			lookfrom += 0.2f * cross(unit_vector(lookat - lookfrom), Vector(0,1,0));
			if (lock == false)
				lookat += 0.2f * cross(unit_vector(lookat - lookfrom), Vector(0,1,0));
			return true;
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_a)) {
			lookfrom -= 0.2f * cross(unit_vector(lookat - lookfrom), Vector(0,1,0));
			if (lock == false)
				lookat -= 0.2f * cross(unit_vector(lookat - lookfrom), Vector(0,1,0));
			return true;
		}
		if ((lock==false && event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_LEFT)) {
			lookat -= 0.3f * cross(unit_vector(lookat - lookfrom), Vector(0,1,0));
			return true;
		}
		if ((lock==false && event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_RIGHT)) {
			lookat += 0.3f * cross(unit_vector(lookat - lookfrom), Vector(0,1,0));
			return true;
		}
		if ((lock==false && event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_UP)) {
			lookat += 0.3f * Vector(0,1,0);
			return true;
		}
		if ((lock==false && event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_DOWN)) {
			lookat -= 0.3f * Vector(0,1,0);
			return true;
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_r)) {
			lookat = static_cast<Sphere*>(selected)->center;
			return true;
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_r)) {
			lookat = Vector(0, 1, -1);
			return true;
		}
		if ((selected != nullptr &&  event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_u)) {
			std::cout << "Ok" << std::endl;
			Sphere	*tmp = nullptr;
			if ((tmp = dynamic_cast<Sphere *>(selected)) != nullptr) {
				tmp->center[1] += 0.1f;
			}
			return true;
		}
		if ((selected != nullptr &&  event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_j)) {
			std::cout << "Ok" << std::endl;
			Sphere	*tmp = nullptr;
			if ((tmp = dynamic_cast<Sphere *>(selected)) != nullptr) {
				tmp->center[1] -= 0.1f;
			}
			return true;
		}
		if ((selected != nullptr &&  event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_h)) {
			std::cout << "Ok" << std::endl;
			Sphere	*tmp = nullptr;
			if ((tmp = dynamic_cast<Sphere *>(selected)) != nullptr) {
				tmp->center -= 0.1f * cross(unit_vector(lookat - lookfrom), Vector(0, 1, 0));
			}
			return true;
		}
		if ((selected != nullptr &&  event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_k)) {
			std::cout << "Ok" << std::endl;
			Sphere	*tmp = nullptr;
			if ((tmp = dynamic_cast<Sphere *>(selected)) != nullptr) {
				tmp->center += 0.1f * cross(unit_vector(lookat - lookfrom), Vector(0, 1, 0));
			}
			return true;
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_PAGEUP)) {
			selected = nullptr;
			return false;
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_HOME)) {
			if (selected_index == stage->size)
				selected_index = 0;
			selected = stage->list[selected_index++];
			return false;
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_t)) {
			int		x;
			int		y;
			SDL_GetMouseState(&x, &y);
			y = - y + 720 + 1;
			for (int j = 0; j < pixel_size; j++) {
				for (int i = 0; i < pixel_size; i++) {
					window.put_pixel(x + i, y + j, 10050000);
				}
			}
			return false;
		}

		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_RETURN)) {
			if (lock == 0) {
				lock = 1;
			}
			else
				lock = 0;
			return true;
		}
		if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_END)) {
			(void)cam;
			if (render_mode == 0) {
				render_mode = 1;
				aperture = 0.05f;
			}
			else {
				render_mode= 0;
				pixel_size = 8;
				aperture = 0.0f;
			}
			return (true);
		}
	}
	return (false);
}

void			low_render_loop(Window &window, Camera &cam, int ns) {
	for (int j = 0; j < window.height; j += pixel_size) {
		for (int i = 0; i < window.width; i += pixel_size) {
			Vector col_vector(0, 0, 0);
			for (int s = 0; s < ns; s++) {
				float u = float(i + drand48()) / float(window.width);
				float v = float(j + drand48()) / float(window.height);
				Ray r = cam.getRay(u, v);
				Vector p = r.pt_at_param(2.0f); // REALLY ?
				col_vector += getColor(r, stage, 0);
			}
			col_vector = col_vector / float(ns);
			col_vector = Vector(sqrt(col_vector[0]), sqrt(col_vector[1]), sqrt(col_vector[2]));
			Color color(col_vector[0], col_vector[1], col_vector[2]);
			for (int y = 0; y < pixel_size; y++) {
				for (int x = 0; x < pixel_size; x++) {
					window.put_pixel(i + x, j + y, color.getCValue());
				}
			}
		}
	}
}

void			high_render_loop(Window &window, Camera &cam, int ns) {
	ProgressBar bar(window.height - 1);
	for (int j = 0; j < window.height; j ++) {
		for (int i = 0; i < window.width; i++) {
			Vector col_vector(0, 0, 0);
			for (int s = 0; s < ns; s++) {
				float u = float(i + drand48()) / float(window.width);
				float v = float(j + drand48()) / float(window.height);
				Ray r = cam.getRay(u, v);
				Vector p = r.pt_at_param(2.0f); // REALLY ?
				col_vector += getColor(r, stage, 0);
			}
			col_vector = col_vector / float(ns);
			col_vector = Vector(sqrt(col_vector[0]), sqrt(col_vector[1]), sqrt(col_vector[2]));
			Color color(col_vector[0], col_vector[1], col_vector[2]);
			window.put_pixel(i, j, color.getCValue());
		}
		bar.update(j);
	}
	std::cout << std::endl;
}

Stage			*init_stage() {
	int			n = 100; //To fix
	int			i = 1;
	A_Object	**list = new A_Object*[n+1];

	// Support
	list[0] = new Sphere(Vector(0,-1000,0), 1000, new default_mat(Vector(0.5f,0.5f,0.5f)));

	// Right part
	list[i++] = new Sphere(Vector(3,0.2f,-3), 0.2f, new default_mat(Vector(drand48()*drand48(), drand48()*drand48(), drand48()*drand48())));
	list[i++] = new Sphere(Vector(2,0.4f,-4), 0.4f, new metal(Vector(drand48()*drand48(), drand48()*drand48(), drand48()*drand48()), 0.1f));
	list[i++] = new Sphere(Vector(-1,0.4f,-7.5f), 0.4f, new metal(Vector(drand48()*drand48(), drand48()*drand48(), drand48()*drand48()), 0.0f));
	list[i++] = new Sphere(Vector(-2.5,0.3f,-8), 0.3f, new default_mat(Vector(drand48()*drand48(), drand48()*drand48(), drand48()*drand48())));
	list[i++] = new Sphere(Vector(2.5f,0.1f,-3), 0.1f, new default_mat(Vector(drand48()*drand48(), drand48()*drand48(), drand48()*drand48())));
	list[i++] = new Sphere(Vector(3,0.2f,-2), 0.2f, new metal(Vector(drand48()*drand48(), drand48()*drand48(), drand48()*drand48()), 0.0f));
	list[i++] = new Sphere(Vector(3.5f,0.3f,-1), 0.3f, new default_mat(Vector(drand48()*drand48(), drand48()*drand48(), drand48()*drand48())));
	list[i++] = new Sphere(Vector(3,0.15f,-0.5), 0.15f, new metal(Vector(drand48()*drand48(), drand48()*drand48(), drand48()*drand48()), 0.3f));

	// Left part
	list[i++] = new Sphere(Vector(1,0.2f,1), 0.2f, new default_mat(Vector(drand48()*drand48(), drand48()*drand48(), drand48()*drand48())));
	list[i++] = new Sphere(Vector(-1,0.4f,1), 0.4f, new metal(Vector(drand48()*drand48(), drand48()*drand48(), drand48()*drand48()), 0.2f));
	list[i++] = new Sphere(Vector(1,0.3f,2), 0.3f, new metal(Vector(drand48()*drand48(), drand48()*drand48(), drand48()*drand48()), 0.0f));
	list[i++] = new Sphere(Vector(-1,0.2f,2), 0.2f, new metal(Vector(drand48()*drand48(), drand48()*drand48(), drand48()*drand48()), 0.3f));
	list[i++] = new Sphere(Vector(-1.5,0.1f,2.5), 0.1f, new default_mat(Vector(drand48()*drand48(), drand48()*drand48(), drand48()*drand48())));
	list[i++] = new Sphere(Vector(-3,0.5f,3), 0.5f, new default_mat(Vector(drand48()*drand48(), drand48()*drand48(), drand48()*drand48())));
	list[i++] = new Sphere(Vector(-5,0.5f,2), 0.5f, new metal(Vector(drand48()*drand48(), drand48()*drand48(), drand48()*drand48()), 0.0f));
	list[i++] = new Sphere(Vector(0,0.15f,1.5f), 0.15f, new metal(Vector(0.7f, 0.6f, 0.5f), 0.0f));
	list[i++] = new Sphere(Vector(0,0.35f,0.5f), 0.35f, new metal(Vector(0.7f, 0.6f, 0.5f), 0.0f));
	list[i++] = new Sphere(Vector(1,0.1f,1.5f), 0.1f, new metal(Vector(drand48()*drand48(), drand48()*drand48(), drand48()*drand48()), 0.4f));
	list[i++] = new Sphere(Vector(2,0.2f,1.5f), 0.2f, new metal(Vector(drand48()*drand48(), drand48()*drand48(), drand48()*drand48()), 0.0f));
	list[i++] = new Sphere(Vector(2.5f,0.4f,0.5f), 0.4f, new metal(Vector(drand48()*drand48(), drand48()*drand48(), drand48()*drand48()), 0.0f));

	// Center Part
	list[i++] = new Sphere(Vector(-3,1,-1), 1.0f, new default_mat(Vector(0.1f, 0.2f, 0.5f)));
	list[i++] = new Sphere(Vector(-0.5,1,-1), 1.0f, new metal(Vector(0.8f, 0.6f, 0.2f), 0.05f));
	list[i++] = new Sphere(Vector(2, 1, -1), 1.0f, new metal(Vector(0.7f, 0.6f, 0.5f), 0.0f));
	return new Stage(list,i);
}

void			render(Window &window, Camera &cam) {
	SDL_LockSurface(window.getSurface());
	if (render_mode == 0)
		low_render_loop(window, cam, 1);
	else
		high_render_loop(window, cam, NS);
	SDL_UnlockSurface(window.getSurface());
}

void			run_engine(Window &window) {
	bool		render_needed = true;
	Camera		*cam;
	stage = init_stage();
	while (window.running() == true) {
		//window.show_fps(); //Uncomment to show FPS
		if (render_needed == true) {
			cam = new Camera(lookfrom, lookat, Vector(0, 1, 0), 50, WIDTH / HEIGHT, aperture, dist_to_focus);
			render(window, *cam);
			delete cam;  // Check this
		}
		render_needed = poll_event(window, *cam, window.getEvent());
		SDL_UpdateWindowSurface(window.getWindow());
	}
}

int				main() {
	try {
		if (render_mode == 1) {
			std::cout << "\033[1;33m";
			std::cout << "Launching RayTracer in High Render setup" << std::endl;
			std::cout << "Setting up environnement ... \033[1;0m" << std::endl;
		}
		Window *window = new Window("RayTracer", WIDTH, HEIGHT);
		run_engine(*window);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		return (1);
	}
	return 0;
}
