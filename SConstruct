import os
import sys

# Настраиваем godot-cpp с версией 4.3
env = SConscript("godot-cpp/SConstruct", exports={"api_version": "4.3"})

# Путь к нашему C++ коду
env.Append(CPPPATH=["src/"])
sources = Glob("src/*.cpp")

# Чёткое имя выходной библиотеки под Windows
target_lib = "demo/bin/libdungeon.windows.template_debug.x86_64.dll"

library = env.SharedLibrary(
    target=target_lib,
    source=sources,
)

Default(library)