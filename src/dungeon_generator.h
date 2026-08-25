#ifndef DUNGEON_GENERATOR_H
#define DUNGEON_GENERATOR_H

#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/vector2i.hpp>

namespace godot {

class DungeonGenerator : public Node2D {
    GDCLASS(DungeonGenerator, Node2D)

private:
    int width = 40;
    int height = 40;
    int max_steps = 300;

protected:
    static void _bind_methods();

public:
    DungeonGenerator();
    ~DungeonGenerator();

    void set_width(int p_width);
    int get_width() const;

    void set_height(int p_height);
    int get_height() const;

    void set_max_steps(int p_steps);
    int get_max_steps() const;

    // Функция генерации: возвращает массив координат тайлов пола Vector2i
    Array generate_dungeon();
};

} // namespace godot

#endif