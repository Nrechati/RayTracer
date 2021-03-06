/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RayTracer.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 09:51:48 by nrechati          #+#    #+#             */
/*   Updated: 2020/01/22 14:52:54 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

#include </Users/nrechati/.brew/Cellar/sdl2/2.0.10/include/SDL2/SDL.h>

# include <iostream>
# include <iomanip>
# include <cctype>
# include <string>
# include <cmath>
# include <array>
# include <stdlib.h>

# include "class/Window.hpp"
# include "class/Vector.hpp"
# include "class/Color.hpp"
# include "class/Ray.hpp"
# include "class/A_Object.hpp"
# include "class/Stage.hpp"
# include "class/Sphere.hpp"
# include "class/Camera.hpp"
# include "class/A_Material.hpp"
# include "class/Materials.hpp"
# include "class/ProgressBar.hpp"

/* Classes */
class Camera;
class Stage;

/* General functions */
void	render(Window &window, Camera &cam);
bool	poll_event(Window &window, Camera &cam, SDL_Event *event);
Stage	*init_stage();

# define WIDTH 1280.0f
# define HEIGHT 720.0f
# define NS 100
#endif
