# Milan The Carrot Hunter 🥕🐕 (so_long)

A 2D top-down puzzle-adventure game built with the MiniLibX graphical library. Navigate Milan, the hungry carrot hunter, 
through a challenging labyrinth to collect all the carrots and find the exit, all while validating maps for a fair and winnable experience.

---

## 🎮 Gameplay Screenshots
It was amazing to begin from drawing pixels...

![Screenshot from 2025-04-23 11-19-53](https://github.com/user-attachments/assets/acd6e8a8-bcba-4c11-93c1-cffe3eef2bae)

Until we get to the final version! Here's a glimpse of Milan's adventure, from the initial map to a completed level!

![Milan The Carrot Hunter](https://github.com/user-attachments/assets/3d50486f-f303-4b48-8ac5-33024e6b028d)


**Starting the Hunt:**
![Initial Game State Screenshot](assets/screenshot_start.png)
*(Replace `assets/screenshot_start.png` with the actual path to your initial game state image)*

**Mission Accomplished!**
![Game Completion Screenshot](assets/screenshot_end.png)
*(Replace `assets/screenshot_end.png` with the actual path to your game completion image)*

---

## 🚀 Features

* **Custom Map Loading:** Loads game maps from `.ber` files, allowing for varied level designs.
* **Comprehensive Map Validation:**
    * Ensures maps are rectangular and enclosed by walls.
    * Verifies the presence of exactly one player ('P'), one exit ('E'), and at least one collectible ('C').
    * **Crucially, validates a reachable path** from the player to all collectibles and then to the exit, guaranteeing solvable maps.
* **Player Movement:** Control Milan using `W`, `A`, `S`, `D` keys or arrow keys.
* **Collectible Interaction:** Collect carrots ('C') scattered across the map.
* **Dynamic Exit:** The exit ('E') only becomes accessible once all collectibles are gathered.
* **Move Counter:** Tracks and displays the number of moves taken to complete the level.
* **Graphical Interface:** Renders the game using custom `.xpm` sprites for walls, floor, player, collectibles, and exit.
* **Clean Exit Handling:** Robust memory management and graceful window closing on game completion or manual exit.

---

## 🛠️ Technologies & Tools
* **C Language:** Core development language, adhering to C99 standards.
* **MiniLibX (MLX42):** A lightweight graphical library for rendering graphics and handling events.
* **Custom `libft` Library:** Utilizes a custom-built C library for essential utility functions (e.g., string manipulation, memory allocation, `ft_printf`, `get_next_line`).
* **XPM Image Format:** Used for game sprites.
* **Makefile:** Manages compilation, linking, and cleaning of the project and its dependencies (MiniLibX, libft).
* **Valgrind-friendly Code:** Developed with memory safety in mind, as indicated by explicit memory allocation/deallocation and error handling.

---
## ⚙️ Installation & Setup

To compile and run "Milan The Carrot Hunter" on a Linux system (typically used with MiniLibX):

1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/yourusername/so_long_final_may2025.git](https://github.com/yourusername/so_long_final_may2025.git)
    cd so_long_final_may2025
    ```

2.  **Compile the project:**
    This command will also compile the `libft` and `minilibx-linux` dependencies automatically.
    ```bash
    make
    ```

---
## 💡 Usage
Run the game by providing a valid `.ber` map file as an argument:

```bash
./so_long maps/good/map_3_5.ber
```

### Controls:

- **Move Up**: W or Up Arrow
- **Move Left**: A or Left Arrow
- **Move Down**: S or Down Arrow
- **Move Right**: D or Right Arrow
- **Exit Game**: ESC key or click the window's close button (X).

**Map Files**:
- Valid maps are located in maps/good/.
- Invalid maps (for testing error handling) are in maps/bad/. Try running the game with one of these to see the error messages:

```
./so_long maps/bad/no_path.ber
```

---
## 🧠 Development & Challenges 

This project was a deep dive into graphical programming, event handling, and robust map parsing. Key challenges and learnings included:

- **Robust Map Validation**: Ensuring all map rules are met, including edge cases and unplayable scenarios (e.g., unreachable collectibles/exit), was a significant algorithmic challenge.
The flood fill algorithm was crucial for verifying a valid path.

- **Memory Management**: Implementing efficient memory allocation and meticulous freeing of resources to prevent leaks, especially in a C environment without automatic garbage collection.

- **MiniLibX Integration**: Understanding the intricacies of mlx_init, mlx_new_window, mlx_put_image_to_window, and mlx_loop for fluid rendering and user interaction.

- **Modular Design**: Breaking down the game logic into separate files (map.c, move.c, render.c, findpath.c, graphic.c, window.c) for better organization and maintainability.

- **Cross-Platform Considerations**: While primarily targeting Linux/X11, understanding the underlying principles of graphic libraries.

---

## 📂 File structure
```
.
├── assets/                  # Contains all game sprites (.xpm images)
├── libft/                   # My custom utility functions and libraries (ft_printf, get_next_line)
├── maps/                    # Collection of example maps, both valid and invalid
│   ├── bad/                 # Maps designed to fail validation (e.g., no path, invalid characters)
│   └── good/                # Playable maps conforming to rules
├── obj/                     # Compiled object files (automatically generated)
├── minilibx-linux/          # MiniLibX graphical library source
├── main.c                   # Entry point for the game
├── map.c                    # Handles map parsing and initialization
├── map_check.c              # Functions for validating map structure and elements
├── map_utils.c              # Utility functions for map handling
├── graphic.c                # Functions for loading and managing graphical assets
├── render.c                 # Manages rendering game elements to the window
├── move.c                   # Handles player movement logic and collision detection
├── findpath.c               # Implements the pathfinding algorithm (e.g., flood fill)
├── window.c                 # Manages window creation, destruction, and event hooks
├── so_long.h                # Header file with structs and function prototypes
└── Makefile                 # Project build system
```
---

## 👤 Autor
Alicia Betancourt ([mainibet](https://github.com/mainibet))

