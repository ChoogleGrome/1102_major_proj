game_test:
	clang++ ./game/Game.cpp -o a
	./a

entities_test:
	clang++ ./entities/Entity.cpp ./entities/Player.cpp ./entities/Enemy.cpp -o a
	./a

main:
	clang++ main.cpp ./entities/Entity.cpp ./entities/Player.cpp ./entities/Enemy.cpp ./game/Game.cpp -o a
	./a
