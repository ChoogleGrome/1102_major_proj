game_test:
	clang++ -std=c++11 ./entities/Entity.cpp ./entities/Player.cpp ./entities/Enemy.cpp ./artifacts/Artifacts.cpp ./game/Game.cpp ./game/test_game.cpp -o a.out
	./a.out

artifacts_test:
	clang++ -std=c++11 ./entities/Entity.cpp ./entities/Player.cpp ./artifacts/Artifacts.cpp ./artifacts/test_artifacts.cpp -o a.out
	./a.out

entities_test:
	clang++ -std=c++11 ./entities/Entity.cpp ./entities/Player.cpp ./entities/Enemy.cpp ./entities/test_entities.cpp ./artifacts/Artifacts.cpp -o a.out
	./a.out

player_test:
	clang++ -std=c++11 ./entities/Entity.cpp ./entities/Player.cpp ./artifacts/Artifacts.cpp ./entities/test_player.cpp -o a.out
	./a.out

enemies_test:
	clang++ -std=c++11 ./entities/Entity.cpp ./entities/Enemy.cpp ./entities/test_enemies.cpp -o a.out
	./a.out

main:
	clang++ -std=c++11 ./artifacts/Artifacts.cpp ./entities/Entity.cpp ./entities/Player.cpp ./entities/Enemy.cpp ./game/Game.cpp main.cpp -o a.out -lncurses
	./a.out

clean:
	rm a.out