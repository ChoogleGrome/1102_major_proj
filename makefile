game_test:
	clang++ -std=c++11 ./entities/Entity.cpp ./entities/Player.cpp ./entities/Enemy.cpp ./game/test_game.cpp -o a.out
	./a.out < inputGame01.txt > outputGame01.txt
	diff outputGame01.txt gameChecker01.txt
	./a.out < inputGame02.txt > outputGame02.txt
	diff outputGame02.txt gameChecker02.txt

artifacts_test:
	clang++ -std=c++11 ./entities/Entity.cpp ./entities/Player.cpp ./artifacts/Artifacts.cpp ./artifacts/test_artifacts.cpp -o a.out
	./a.out

entities_test:
	clang++ -std=c++11 ./entities/Entity.cpp ./entities/Player.cpp ./entities/Enemy.cpp ./entities/test_entities.cpp ./artifacts/Artifacts.cpp -o a.out
	./a.out

player_test:
	clang++ ./entities/Entity.cpp ./entities/Player.cpp ./entities/test_entities.cpp -o a.out
	./a.out

enemy_test:
	clang++ ./entities/Entity.cpp ./entities/Enemy.cpp ./entities/test_entities.cpp -o a.out
	./a.out

main:
	clang++ -std=c++11 ./artifacts/Artifacts.cpp ./entities/Entity.cpp ./entities/Player.cpp ./entities/Enemy.cpp ./game/Game.cpp main.cpp -o a.out -lncurses
	./a.out

clean:
	rm a.out