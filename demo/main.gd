extends Node2D

@onready var generator: DungeonGenerator = $DungeonGenerator
@onready var tilemap: TileMapLayer = $TileMapLayer

func _ready() -> void:
	generate_dungeon()

func _input(event: InputEvent) -> void:
	# Нажимай Пробел или Enter для перегенерации
	if event.is_action_pressed("ui_accept"): 
		generate_dungeon()

func generate_dungeon() -> void:
	tilemap.clear()
	
	# Вызываем C++ функцию generate_dungeon()!
	var floor_coords: Array = generator.generate_dungeon()
	
	# Отрисовываем тайлы на карте
	for coords in floor_coords:
		# Рендерим точку на сетке (источник тайла 0, координаты 0,0)
		tilemap.set_cell(coords, 0, Vector2i(0, 0))
