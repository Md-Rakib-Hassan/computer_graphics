# Computer Graphics Final Project (GLUT)

This is a **Computer Graphics final project** using **OpenGL (GLUT)** in C++. The project presents an animated scene representing cultural and natural elements, including boats, a flying plane, Shaheed Minar, and weather effects like rain, snow, and fire.

---

## 🗂️ Project Structure

```
computer_graphics/
├── Computer_Graphics_Final_Project.cbp   # Code::Blocks project file
├── main.cpp                              # Main application
├── include/
│   └── draw.h                            # Header file for drawing functions
├── functions/                            # Modular OpenGL drawing and logic functions
│   ├── controlKeyboard.cpp               # Keyboard control logic
│   ├── drawBackground.cpp
│   ├── drawBoat.cpp
│   ├── drawMemorial.cpp
│   ├── drawMiniPlan.cpp
│   ├── ...
│   └── drawTree.cpp
```

---

## 🛠️ Requirements

- **C++ Compiler** (e.g., `g++`)
- **OpenGL Utility Toolkit (GLUT)**
- **FreeGLUT or GLUT library**
- Optional: **Code::Blocks IDE**

---

## 🚀 How to Run

### ✅ With Code::Blocks

1. Open the `Computer_Graphics_Final_Project.cbp` file using Code::Blocks.
2. If source files are not added yet:
   - Right-click on Project File **"Computer_Graphics_Final_Project"** → `Add files recursively...`
   - Select the `functions/` folder and add them.
   - Select the `include/` folder and add them.

3. Make sure to link OpenGL libraries:
   ```
   -lglu32
   -lopengl32
   -lfreeglut
   ```
4. Press `F9` to **Build & Run** the project.

### ✅ From Terminal

Linux/macOS:
```
g++ main.cpp functions/*.cpp -Iinclude -o graphics_app -lGL -lGLU -lglut
./graphics_app
```

Windows (MinGW + FreeGLUT):
```
g++ main.cpp functions/*.cpp -Iinclude -o graphics_app -lfreeglut -lopengl32 -lglu32
graphics_app.exe
```

---

## ⌨️ Keyboard Controls

| Key       | Action                         |
|-----------|--------------------------------|
| `r`       | Toggle Rain                    |
| `s`       | Toggle Snow                    |
| `f`       | Toggle Fire Particles          |
| `m`       | Toggle Memorial Mode           |
| `n`       | Toggle Night/Day Mode          |
| Arrow ⬅️➡️⬆️⬇️ | Move the Plane (Left/Right/Up/Down) |

---

## 📸 Features

- 🇧🇩 **Sriti Shoudho (Shaheed Minar)**
- 🚆 **Metro Train Animation**
- ✈️ **Controllable Airplane**
- 🌦️ **Rain, Snow, and Fire Effects**
- 🌳 **Palm Trees, Flowers, Landscape**
- 🧑‍💻 **Keyboard-Controlled Interactivity**
- 🌗 **Day/Night Mode Switching**
- 🚗 **Moving Cars and Boats**

---