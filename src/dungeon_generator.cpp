#include "dungeon_generator.h"
#include <godot_cpp/core/class_db.hpp>
#include <random>
#include <vector>

using namespace godot;

void DungeonGenerator::_bind_methods() {
    // Регистрируем методы для редактора Godot
    ClassDB::bind_method(D_METHOD("get_width"), &DungeonGenerator::get_width);
    ClassDB::bind_method(D_METHOD("set_width", "p_width"), &DungeonGenerator::set_width);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "width"), "set_width", "get_width");

    ClassDB::bind_method(D_METHOD("get_height"), &DungeonGenerator::get_height);
    ClassDB::bind_method(D_METHOD("set_height", "p_height"), &DungeonGenerator::set_height);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "height"), "set_height", "get_height");

    ClassDB::bind_method(D_METHOD("get_max_steps"), &DungeonGenerator::get_max_steps);
    ClassDB::bind_method(D_METHOD("set_max_steps", "p_steps"), &DungeonGenerator::set_max_steps);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "max_steps"), "set_max_steps", "get_max_steps");

    ClassDB::bind_method(D_METHOD("generate_dungeon"), &DungeonGenerator::generate_dungeon);
}

DungeonGenerator::DungeonGenerator() {}
DungeonGenerator::~DungeonGenerator() {}

void DungeonGenerator::set_width(int p_width) { width = p_width; }
int DungeonGenerator::get_width() const { return width; }

void DungeonGenerator::set_height(int p_height) { height = p_height; }
int DungeonGenerator::get_height() const { return height; }

void DungeonGenerator::set_max_steps(int p_steps) { max_steps = p_steps; }
int DungeonGenerator::get_max_steps() const { return max_steps; }

Array DungeonGenerator::generate_dungeon() {
    Array floor_tiles;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dir_dist(0, 3);

    int current_x = width / 2;
    int current_y = height / 2;

    const int dx[] = {0, 1, 0, -1};
    const int dy[] = {-1, 0, 1, 0};

    std::vector<std::vector<bool>> visited(width, std::vector<bool>(height, false));

    for (int i = 0; i < max_steps; ++i) {
        if (!visited[current_x][current_y]) {
            visited[current_x][current_y] = true;
            floor_tiles.append(Vector2i(current_x, current_y));
        }

        int dir = dir_dist(gen);
        int next_x = current_x + dx[dir];
        int next_y = current_y + dy[dir];

        if (next_x > 1 && next_x < width - 1 && next_y > 1 && next_y < height - 1) {
            current_x = next_x;
            current_y = next_y;
        }
    }

    return floor_tiles;
}