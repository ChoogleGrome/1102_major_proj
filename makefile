game_test:
	g++ ./game/Game.cpp -o a
	./a

entities_test:
	g++ ./entities/Entitiy.cpp ./entities/Player.cpp ./entities/Enemry.cpp ./entities/test_entities.cpp -o a
	./a

main:
	g++ main.cpp ./entities/Entitiy.cpp ./entities/Player.cpp ./entities/Enemry.cpp ./game/Game.cpp -o a
	./a
