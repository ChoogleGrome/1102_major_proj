game_test:
	clang++ ./game/Game.cpp -o a.out
	./a.out

entities_test:
	clang++ -std=c++11 ./entities/Entity.cpp ./entities/Player.cpp ./entities/Enemy.cpp ./entities/test_entities.cpp -o a.out
	./a.out

player_test:
	clang++ ./entities/Entity.cpp ./entities/Player.cpp ./entities/test_entities.cpp -o a.out
	./a.out

enemy_test:
	clang++ ./entities/Entity.cpp ./entities/Enemy.cpp ./entities/test_entities.cpp -o a.out
	./a.out

main:
	clang++ ./entities/Entity.cpp ./entities/Player.cpp ./entities/Enemy.cpp ./game/Game.cpp main.cpp -o a.out -lncurses
	./a.out

clean:
	rm a.out