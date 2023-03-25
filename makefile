SRCS = ".\\src\\main.cpp"
EXEC = ".\\bin\\game.exe"
SRCH = -LC:/msys64/mingw64/lib/SFML
CFLG = -std=c++17 -mwindows
LIBS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

all:
	g++ $(CFLG) $(SRCS) -o $(EXEC) $(SRCH) $(LIBS) 