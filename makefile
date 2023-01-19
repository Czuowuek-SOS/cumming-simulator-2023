all:
	g++ ".\\src\\main.cpp" -o ".\\bin\\game.exe" -LC:/msys64/mingw64/lib\SFML -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system