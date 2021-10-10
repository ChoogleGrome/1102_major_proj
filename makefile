game_test:
	g++ ./game/Game.cpp -o a.out
	./a.out

entities_test:
	g++ ./entities/Entity.cpp ./entities/Player.cpp ./entities/Enemry.cpp ./entities/test_entities.cpp -o a.out
	./a.out

player_test:
	g++ ./entities/Entity.cpp ./entities/Player.cpp ./entities/test_entities.cpp -o a.out
	./a.out

enemy_test:
	g++ ./entities/Entity.cpp ./entities/Enemy.cpp ./entities/test_entities.cpp -o a.out
	./a.out

main:
	g++ main.cpp ./entities/Entity.cpp ./entities/Player.cpp ./entities/Enemy.cpp ./game/Game.cpp -o a.out
	./a.out

clean:
	rm a.out