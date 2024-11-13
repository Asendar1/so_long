
# So Long - 2D Game in C using MiniLibX

**So Long** is a simple 2D top-down game developed using the **MiniLibX** graphics library. The game challenges the player to collect all collectibles on a map and reach an exit, all while avoiding obstacles and navigating through a maze-like environment. The project is designed as a mini-game with basic game mechanics and graphical management, utilizing custom libraries and efficient programming practices.

This project serves as an introduction to graphical programming in C and leverages the **42 School's** required toolset for graphical applications.

---

## 📜 Game Description

### **Gameplay**

The player controls a character that must:
1. Navigate a map consisting of walls, empty spaces, collectibles, and an exit.
2. Collect all items marked as **C** (collectibles) on the map.
3. Reach the **E** (exit) after collecting all the collectibles.
4. The character is controlled using the **WASD** keys or arrow keys.
5. Each movement is displayed in the terminal as a step counter.
6. The player cannot pass through walls (represented by **1**).
7. Pressing **ESC** will quit the game cleanly.
8. Pressing **R** will reset the game to the starting state.

### **Graphics**

- The game is displayed in a window, where the map and the player are drawn using images in **.xpm** format.
- The game window is handled smoothly with basic event management (resize, minimize, focus, etc.).
- You can quit the game by either pressing **ESC** or closing the window via the cross button.
  
### **Map Structure**

- The map is a rectangular grid composed of the following characters:
  - **'1'**: Wall
  - **'0'**: Empty space
  - **'C'**: Collectible item
  - **'E'**: Exit
  - **'P'**: Player's starting position

- The map must be enclosed by walls and contain:
  - Exactly one **P** (Player)
  - Exactly one **E** (Exit)
  - At least one **C** (Collectible)

### **Features**
- Collect all collectibles before escaping.
- Detect and handle invalid map configurations (e.g., non-rectangular maps, missing walls, or duplicate entries for the player or exit).
- Use the **MiniLibX** library for window management, graphical rendering, and event handling.
- A clean and smooth user experience with basic keyboard input for player movement.

---

## 🚀 Features

### **Mandatory Features**
- **Movement**: The player can move up, down, left, or right using either WASD or arrow keys.
- **Game Mechanics**: The game ends when all collectibles are collected and the player reaches the exit.
- **Graphical Management**: The game uses images and textures (e.g., **.xpm** files) to represent the player, walls, collectibles, and the exit.
- **Error Handling**: Invalid maps (non-rectangular, incorrect characters, or missing elements) are properly detected, and the game exits with an error message.
- **Terminal Output**: Every movement made by the player is displayed in the terminal.


---

## 🛠️ Installation

To run this game locally, follow these steps:

### Prerequisites

- **Linux** or **MacOS** is required to run the project.
- Install **MiniLibX** and dependencies:
  ```bash
  sudo apt-get install libx11-dev
  ```

### Steps to Run

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/so_long.git
   cd so_long
   ```

2. Build the project:
   - Install **MiniLibX** using the `make call_mlx` command.
   - Compile the project:
     ```bash
     make
     ```

3. Run the game:
   ```bash
   ./bin/so_long rscs/maps/valid_map.ber
   ```

4. Play the game and control the player using the **WASD** or arrow keys.

---

## 📖 How to Create Your Own Map

Maps are stored in **.ber** format and can be created by following these steps:

1. Create a new text file with the `.ber` extension.
2. Define the map using the following characters:
   - **'1'**: Wall
   - **'0'**: Empty space
   - **'C'**: Collectible
   - **'E'**: Exit
   - **'P'**: Player start position
3. Ensure the map is rectangular, surrounded by walls, and contains one **P**, one **E**, and at least one **C**.
4. Save the file and run the game with your custom map:
   ```bash
   ./bin/so_long path/to/your_map.ber
   ```

---

## 📈 Technologies

- **C Programming Language**: Core language for game logic and implementation.
- **MiniLibX**: A simple graphical library for creating windows, handling events, and rendering images in X-Window.
- **libft**: A custom implementation of C standard library functions.
- **ft_printf**: A custom printf implementation to handle formatted output.
- **Makefile**: Automates the build process for compiling and linking the project.

---
