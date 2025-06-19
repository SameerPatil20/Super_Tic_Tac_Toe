# Super Tic Tac Toe 🎮

A C++ implementation of **Super Tic Tac Toe** using **SFML (Simple and Fast Multimedia Library)**. The game features a clean UI, interactive gameplay, and accurate rule enforcement for the popular meta‑variant of Tic Tac Toe.

---

## 🧠 Game Rules

Super Tic Tac Toe is a 9‑board version of classic Tic Tac Toe. Here's how it works:

- The board consists of 9 small 3×3 Tic Tac Toe boards arranged in a 3×3 grid.  
- Your move in a small board determines which board your opponent will play in next.  
- If the target board is already won or drawn, the opponent can play in any board.  
- A small board is won just like normal Tic Tac Toe (3 in a row).  
- The first player to win 3 small boards in a row (horizontal, vertical, or diagonal) wins the game.  

---

## 🔧 Build Instructions

1. **Prerequisites**  
   - C++17 compiler (e.g., `g++`)  
   - SFML 2.5 or later (`libsfml-graphics`, `libsfml-window`, `libsfml-system`)  
   - Linux (tested) or Windows with SFML setup  

2. **Folder structure** (ensure this layout):
   ```
   .
   ├── Makefile
   ├── main.cpp
   ├── board.cpp
   ├── board.h
   ├── utils.cpp
   ├── utils.h
   └── image/
       └── wood_texture.png
   ```

3. **Install SFML** (Ubuntu example):
   ```bash
   sudo apt install libsfml-dev
   ```

4. **Compile & Link**:
   ```bash
   make
   ```

5. **Run the game**:
   ```bash
   ./super_ttt
   ```

6. **Clean build artifacts**:
   ```bash
   make clean
   ```

---

## 📁 File Structure

| File                     | Purpose                                   |
|--------------------------|-------------------------------------------|
| `main.cpp`               | Entry point, handles game loop & input    |
| `board.cpp` / `board.h`  | Renders the 9×9 board layout              |
| `utils.cpp` / `utils.h`  | Asset loading, global shapes/text, logic  |
| `Makefile`               | Build configuration                       |
| `image/wood_texture.png` | Wooden background texture                 |

---

## 🖼️ Assets

- **Texture**: `image/wood_texture.png` (required for the board’s wooden frame)  
- **Font**: Uses DejaVu Sans from system fonts:  
  ```
  /usr/share/fonts/truetype/dejavu/DejaVuSans.ttf
  ```
  Adjust the path in `utils.cpp` if needed.

---

## ✅ Features

- Full Super Tic Tac Toe rule enforcement  
- Interactive move highlighting  
- Sub‑board victory detection with line indicators  
- Overall game win/draw detection and display  
- Turn indicator (X / O) at bottom of window  

---

## 🙌 Credits

Created with ♥️ by **Sameer**  
Feel free to fork, modify, or expand this project!
