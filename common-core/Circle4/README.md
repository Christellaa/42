# CPP00 - CPP04
These projects serve to introduce the core of object-oriented programming using c++ (98 version).
We explore syntax, memory management, and OOP principles like inheritance, polymorphism and encapsulation.

## Technologies used
- Language
	- C++
- Tools
	- Makefile, C++98

## What I learned
- Class design and access control
- Object lifecycle and RAII
- Operator overloading and memory management
- Polymorphism, inheritance, virtual functions, abstract classes, interfaces

## How to run
```make```

### Example usage
```
make
./programName
```

# CUB3D
This is a 3D graphics project inspired by Wolfenstein 3D. It involves rendering a 3D world using raycasting.

## Technologies used
- Language
	- C
- Tools
	- Makefile, [Minilibx](https://github.com/42paris/minilibx-linux)
- Norm
	- [42 norminette](https://github.com/42school/norminette)

## What I learned
- Raycasting algorithm
- Rendering a 3D perspective from a 2D map
- Handle player movement and collision detection
- Map texture and color floor/ceiling
- Handle events and updates in real-time

## How to run
```make```
OR to have a 2D map and be able to rotate the point of view with the mouse
```make bonus```

### Example usage
```
make
./cub3D map/valid_map.cub

make bonus
./cub3D map/valid_map.cub
```
