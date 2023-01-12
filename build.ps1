g++ -c ".\\src\\main.cpp" -o ".\\bin\\game.out" #-I./include
g++ ".\\bin\\game.out" -o ".\\bin\\game.exe" -LC:/msys64/mingw64/lib\SFML -lsfml-graphics -lsfml-window -lsfml-system