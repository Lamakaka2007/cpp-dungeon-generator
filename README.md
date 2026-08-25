# 🏰 2D Procedural Dungeon Generator (C++ GDExtension for Godot 4)

A high-performance **2D Procedural Dungeon Generator** written in **C++** as a native **GDExtension** module for **Godot Engine 4.3**.

It utilizes a optimized **Random Walk (Drunkard's Walk)** algorithm to generate fully connected rogue-like map layouts in real-time.

---

## 🚀 Key Features

* **Native C++ Performance:** Core generation logic is executed on the native layer for maximum efficiency.
* **Godot 4 Integration:** Seamlessly exposed to the Godot Editor with customizable properties (`width`, `height`, `max_steps`).
* **TileMap Support:** Generates arrays of tile coordinates ready to be rendered by Godot's `TileMapLayer`.
* **Guaranteed Connectivity:** Ensures all generated corridors and rooms are accessible.

---

## 🛠️ Tech Stack & Architecture

* **Language:** C++17
* **Engine:** Godot 4.3 (Standard Edition)
* **Binding:** `godot-cpp` (GDExtension API)
* **Build System:** SCons

---

## 💻 Build Instructions

1. **Clone the repository:**
   ```bash
   git clone --recursive [https://github.com/Lamakaka2007/cpp-dungeon-generator.git](https://github.com/Lamakaka2007/cpp-dungeon-generator.git)
   cd cpp-dungeon-generator
