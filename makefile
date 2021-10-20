game_test:
	clang++ -std=c++11 ./entities/Entity.cpp ./entities/Player.cpp ./entities/Enemy.cpp ./artifacts/Artifacts.cpp ./game/Game.cpp ./game/test_game.cpp -o a.out
	
	./a.out < ./testFiles/inputGame01.txt > ./testFiles/outputGame01.txt
	diff ./testFiles/outputGame01.txt ./testFiles/gameChecker01.txt

	./a.out < ./testFiles/inputGame02.txt > ./testFiles/outputGame02.txt
	diff ./testFiles/outputGame02.txt ./testFiles/gameChecker02.txt

artifacts_test:
	clang++ -std=c++11 ./entities/Entity.cpp ./entities/Player.cpp ./artifacts/Artifacts.cpp ./artifacts/test_artifacts.cpp -o a.out
	./a.out

player_test:
	clang++ -std=c++11 ./entities/Entity.cpp ./entities/Player.cpp ./artifacts/Artifacts.cpp ./entities/test_player.cpp -o a.out
	
	./a.out > ./testFiles/playerOutput01.txt
	diff ./testFiles/playerOutput01.txt ./testFiles/playerChecker01.txt

enemies_test:
	clang++ -std=c++11 ./entities/Entity.cpp ./entities/Enemy.cpp ./entities/test_enemies.cpp -o a.out
	
	./a.out > ./testFiles/enemyOutput01.txt
	diff ./testFiles/enemyOutput01.txt ./testFiles/enemyChecker01.txt

main:
	clang++ -std=c++11 ./artifacts/Artifacts.cpp ./entities/Entity.cpp ./entities/Player.cpp ./entities/Enemy.cpp ./game/Game.cpp main.cpp -o a.out -lncurses
	./a.out

clean:
	rm a.out