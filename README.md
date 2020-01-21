# Welcome to my Basic RayTracer in C++

This project is my attempt to implement a **RayTracer in C++**. The main goal here was to use my C++ knowledge on a medium scale project with a lot of room for **optimization architecture improvement and features ideas**. The only external lib used is **SDL2** which is required to run the project. As of January 2020 I **paused this project** to clean the Codebase in this *"V1.0"* state and focus on other things after 3 weeks on it. There is a lot of other features in the future. Those will be listed at the bottom of this documentation.

![V1.0](./v1_0.png)

## Disclaimer

As this project is still a **Work in Progress** the codebase still has debug function, commentary, and few architecture/coding issues. Regarding my mindset behind it, the target was not performance (real-time rendering and movement is not the goal), but the render quality. Rendering a full scene in 1080p takes around 15min and this will probably go higher when future features are implemented. Moreover, this RayTracer has is default scene hard-written and in the current state is not a tool where you can create and test your scene.

> **Note:** SDL2 is also required to run the RayTracer and the project was not tested on a Linux environment.

## Abstract



## How to Run

To run this program :

- Clone this repository `git clone https://github.com/Nrechati/RayTracer.git`
- Just `make`
- `./RayTracer` to run

>**Note**: The program was built on macOS Mojave and I know there is some workaround to do to compile on Linux as well.

## Classes

- Window
    - Constructors :
        - `Window(std::string name)` take `WIDTH` and `HEIGHT` define in `RayTracer.hpp`
        - `Window(std::string name, size_t width, size_t height)`
    - Class to handle the render window. Initialize SDL objects and surface. Fill the render surface and implement addtional functions like `show_fps`

- Vector
    - Constructor :
        - `Vector(float first, float second, float third)`
    - A math class vector to handle every vector operation and management for calculation. Overload every operator for more convenience in vector usage in the project

- Stage :
    - Constructor :
        - `Stage(A_Object **lst, int n)`
    - Simple class for a **list of *A_Object***. The *hit* method call the *hit* of every *A_Object* in the lst in succession.

- Camera
    - Constructor :
        - `Camera(Vector lookfrom, Vector lookat, Vector vup, float vfov, float aspect, float aperture, float focus_dist)`
    - Camera class for the view. Handle the position and direction of the camera and getting Ray for render.

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
    - *Abstract class*, implement a **scatter** function that every child must have
        - `virtual bool scatter(const Ray& r_in, const hit_result& result, Vector& attenuation, Ray& scattered) const = 0`
    - Abstract call that every material inherit from. It implement the `scatter` function that *describe* how each material reflect and refract light.

- Color
    - Constructor :
        - `Color(float r, float g, float b)`
    - Color class to interface color `{r,g,b}` vector to values for **SDL2** surface. The class can set and get value from a vector then pass them to the **SDL2**.

- ProgressBar
    - Constructor :
        - `ProgressBar(size_t iterations);`
    - A very simple, not very accurate ProgressBar Class. The goal was to reuse my Python ProgressBar in a C++ environment. Accuracy was not the goal, getting a rough render time on the RayTracer was. This class might be optimized then reused in the future. This progress bar size doesn't scale with the terminal and output is not protected. This is still more of a *debug* feature than a strong, fail-free one.

> **Note:** Naming convention is `A_` prefix is for abstract class and `I_` is for interfaces

## Core Features

### Outputting the image

This project uses **SDL2** as a graphics library. I chose it because I used the SDL2 in other projects and was already able to implement what I needed from it, **not for optimization or architecture**. I wanted to focus more on the RayTracer computing that the graphic library. I might change to **OpenGL / OpenCL** in the future, for better performance and/or **GPU-side rendering**.

### The vector class

Calculation using vector is key for ray tracing. So a strong vector class to ease those calculations was key. The class overloads `+,-,*,/` and `%` signs both between two vectors and vector/float and/or vector/int. It also overload assignations operators and implement **dot** and **cross** products, **unit_vector** and **length** calculation.

### Rays and Camera

Rays and Camera are the earth a RayTracer. **Camera defines the rendering point and direction of view**, as well as a defining few constants such as **FoV**. **Rays describe light going from camera to every point in the stage** and reflect/refract upon encountering objects. During computation, rays are viewed as lines with the `A + t*B` equation. The program will send a ray from the camera to every pixel in the window *(representing the plane in space defined by the camera FoV and the distance to it)*. Then each ray will go through each of the stage's *A_Object* **hit** method to see if it touches something and need reflection/refraction.

### Spheres

A the moment, **sphere is the only object handled by this raytracer**. The **hit** method resolves the standard **line - sphere intersection** equation. Meaning if the line cross a point at a distance from the center of the sphere is equal to the sphere's radius, it touches it. **Closest hit form camera position is always kept**.

## Additional Features

### Antialiasing

**Antialising** main goal is to **blur the edges of objects** by adding some of the **background color**. Precision is also enhanced by **shooting multiple rays for each pixel** and taking a **mean of all color result** for each pixel. This results in a more **smooth visual on colors**.

### Diffuse Materials

**Default material used is based upon Lambertian reflectance**. Lambertian reflectance defines an ideal *matte* surface with diffuse reflectance. It is named after the *Lambert's cosine law*. This gives a smooth, *matte* look to objects.

### Metal

The other implemented material is **metal**. This is a higher reflecting material but could be altered to add some fuzziness to it depending on the render wanted. It could be close to a mirror or a very fuzzy reflecting metal.

### Positionable camera

Handling a proper camera position was the first step to handle camera movement. It is done by defining a camera with a *look from* and a *look at* vector for position and direction. From that, by properly handling rays starting point in equations, you can change the position and the direction of the view rendered by the ray tracer.

### Defocus Blur

Defocus blur aims to add blur on the object the further the object is from the camera focal point. Like in photography. This is handled by defining the camera aperture and focal point. Thus you can increase the effect as needed.

### Aliasing

Aliasing main goal is to get a rough render allowing real-time rendering to move camera, direction, and object while still having a rough idea of the stage before starting a full render.

### Camera movement

Aliasing allows the user for a full camera position and direction movement on a 3D space. The camera can move on the X/Y/Z-axis alongside its *look at* vector direction. Direction movement also allows modifying the *look at* vector direction around the *look from* position of the camera. You can also **lock** the *look at* point to allow circular movement around a point with an **RPG-like** feeling.

> **Note:** Collision are not a thing in this ray tracer. Thus you can pass through any objects.

### Object movement

This is still a *Work in progress* feature. I still wanted to implement a mouse pointer selection for objects but in the current state you can *blindly* go through each stage object and modify their positions in the space.

## Keymapping

- **Escape :** Quit all
- **W A S D :** Move camera origin
- **Spacebar :** Move up
- **C :** Move down
- **Arrows :** Move camera direction
- **R :** Reset camera
- **Left Return :** Lock On/Off
- **End :** Change render mode *High/Low*
- **= :** Pixel size + *(For aliasing)*
- **- :** Pixel size - *(For aliasing)*
- **Home :** select next object in stage
- **PageUp :** clear selected object
- **U H J K :** move selected object

> **Note:** *Keymaps done on a QWERTY Keyboard*. Those keymaps are in no way optimized or not subject to change. They were just chosen as found natural to me and for a final build, surely needs more tuning and reflections to feel natural.

## Features to be implemented

- Soon to be implemented
    - Targeting Object on mouse pointer to move/change them
    - Adding Dielectrics materials for glass and water.

- Later implemented features
    - Motion Blur
    - Bounding Volume Hierarchy
    - Texture & texture Mapping
    - Perlin Noise texture
    - Rectangle and Lights
    - Volumes

## Current TODO list *(last Update : 01/15/2020)*:

-   V1.0 codebase cleaning :
    - Split files
    - Cleaner calculus for reading
    - Leak on materials
    - Leak on Camera
    - Remove Global in main nicely
    - Remove C type cast
