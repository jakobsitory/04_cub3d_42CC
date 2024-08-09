# **cub3D**
The cub3D project is a challenge within the 42 School curriculum aimed at deepening students' understanding of computer graphics, raycasting, and game development in C. The goal is to create a 3D game engine similar to the classic Wolfenstein 3D, using a 2D map to render a 3D world.

## **Task**
The task was to implement a program that renders a 3D scene from a 2D map using raycasting. The program needs to handle various tasks such as:

- Parsing a map file to create a 2D representation of the game world.
- Implementing a raycasting algorithm to project the 2D map into a 3D perspective.
- Handling player movement and interactions within the game world.
- Managing textures and rendering them correctly on the walls.

## **Key objectives included:**

- Implementing a program that reads a map file and renders a 3D scene based on the player's perspective.
- Ensuring the program correctly handles edge cases, such as invalid map files and boundary conditions.
- Demonstrating a deep understanding of raycasting, texture mapping, and game loop mechanics.
- (Bonus) Adding additional features: Wall collision, Minimap System and Shading.

**Key Achievements**

- Successful Raycasting Implementation: Developed a robust raycasting algorithm that accurately projects a 2D map into a 3D scene.
- Efficient Texture Mapping: Integrated texture mapping to enhance the visual quality of the rendered scene.
- Comprehensive Error Handling: Integrated extensive error checking and handling to manage edge cases and unexpected scenarios, ensuring the program operates reliably in various conditions.

## **Installation**
To install the project, follow these steps:

1. Clone the repository: **`git clone git@github.com:jakobsitory/04_cub3d_42CC.git`**
2. Navigate to the project directory: **`cd 04_cub3d_42CC`**
3. Build the project: **`make shader`**

## **Usage**

The cub3D program should be executed as follows:
```bash
./cub3D resources/valid_map_1.cub
```
This command starts the game using the specified map file `resources/valid_map_1.cub`. The player can navigate through the 3D world using the keyboard controls:

| **Key**           | **Function**                                      |
|-------------------|---------------------------------------------------|
| **←** / **→**     | Rotate the voint of view left and right           |
| **W** / **A** / **S** / **D**              | Move through the map     |
| **Esc**           | Close the window                                  |
