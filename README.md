# Welcome to my Basic RayTracer in C++

This project is my attempt to implement a **RayTracer in C++**. The main goal here was to use my C++ knowledge on a medium scale project with a lot of room for **optimization architecture improvement and features ideas**. The only external lib used is **SDL2** that is required to run the project. As of January 2020 I **paused this project** to clean the Codebase in this *"V1.0"* state and focus on other things after 3 weeks on it. There is a lot of other features in the future. Those will be listed at the bottom of this documentation.

![V1.0](./v1_0.png)

## Disclaimer

As this project is still a **Work in Pogress** the codebase still have debugg function, commentary, and few architecture / coding issue. Regarding my mindset behind it, the target was not performance (real-time rendering and movement is not the goal), but the render quality. Rendering a full scene in 1080p takes around 15min and this will probably go higher when future features are implemented. Moreover this RayTracer has is default scene hard-written and in the current state is not a tool where you can create and test your own objects.

> **Note:** SDL2 is also required to run the RayTracer and the project was not tested on a Linux envrionnement.

## Abstract



## How to Run

To run this program :

- Clone this repository `git clone https://github.com/Nrechati/RayTracer.git`
- Just `make`
- `./RayTracer` to run

>**Note**: Program was built on macOS Mojave and I know there is some workaround to do to compile on Linux as well.

## Classes

- Window
	- Constructors :
		- `Window(std::string name)` take `WIDTH` and `HEIGHT` define in `RayTracer.hpp`
		- `Window(std::string name, size_t width, size_t height)`
	- Class to handle the render window. Initialize SDL objects and surface. Fill the render surface and implement addtional functions like `show_fps`

- Vector
	- Constructor :
		- `Vector(float first, float second, float third)`
	- A math class vector to handle every vector operation and management for calculation. Overload every operator for more convienience in vector usage in the project

- Stage :
	- Constructor :
		- `Stage(A_Object **lst, int n)`
	- Simple class for a **list of *A_Object***. The *hit* method call the *hit* of every *A_Object* in the lst in succession.

- Camera
	- Constructor :
		- `Camera(Vector lookfrom, Vector lookat, Vector vup, float vfov, float aspect, float aperture, float focus_dist)`
	- Camera class for the view. Handle position and direction of the camera and getting Ray for render.

- A_Object
	- *Abstract class*, implement a **hit** function that every child must have
		- `virtual bool hit (const Ray& r, float t_min, float t_max, hit_result& result) const = 0`
	- Abstract class that every object inherit from *(Sphere for example, is a child of A_Object)*. Also declare the **hit_result** struct to store data from the `hit` function of the object.

- Ray
	- Constructor :
		- `Ray(const Vector& origin, const Vector& direction)`
	- Ray class to Ray tracing. Defined by origin, direction, and a float to represent `t` in `A + t*B` segment equation.

- Sphere
	- Constructor :
		- `Sphere(Vector center, float radius, A_Material *mat_ptr)`
	- Class for spheres, inherited from *A_object*. Defined by center, radius and material. Implement his own `hit` method regarding 2-Order equation.

- A_Material
	- Constructor
	- Description

- Color
	- Constructor
	- Description

- ProgressBar
	- Constructor
	- Description

> **Note :** Naming convention is `A_` prefix is for abstract class and `I_` is for interfaces

## Features

## Features to ne implemented

- Soon to be implemented
	- Targeting Object on mouse pointer to move/change them
	- Adding Dielectrics materials for glass and water.

- Later implemented features
	- Motion Blur
	- Volume Hierarchy
	- Texture & texture Mapping
	- Perlin Noise texture
	- Rectangle and Lights
	- Volumes

## Current TODO list *(last Update : 01/15/2020)*:

-	V1.0 codebase cleaning :
	- Split files
	- Cleaner calculus for reading
	- Leak on materials
	- Leak on Camera
	- Remove Global in main nicely
	- Remove C type cast


