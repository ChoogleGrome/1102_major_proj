game_test:
	g++ ./game/Game.cpp -o a.out
	./a.out

entities_test:
	g++ -std=c++11 ./entities/Entity.cpp ./entities/Player.cpp ./entities/Enemy.cpp ./entities/test_entities.cpp -o a.out
	./a.out

player_test:
	g++ ./entities/Entity.cpp ./entities/Player.cpp ./entities/test_entities.cpp -o a.out
	./a.out

enemy_test:
	g++ ./entities/Entity.cpp ./entities/Enemy.cpp ./entities/test_entities.cpp -o a.out
	./a.out

main:
	clang++ ./entities/Entity.cpp ./entities/Player.cpp ./entities/Enemy.cpp ./game/Game.cpp main.cpp -o a.out -lncurses
	./a.out

clean:
	rm a.out