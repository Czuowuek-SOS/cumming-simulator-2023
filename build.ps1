g++ -c ".\\src\\main.cpp" -o ".\\bin\\game.out" #-I./include
g++ ".\\bin\\game.out" -o ".\\bin\\game.exe" -L./lib -lsfml-graphics -lsfml-window -lsfml-system