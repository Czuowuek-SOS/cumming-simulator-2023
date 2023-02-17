SRCS = ".\\src\\main.cpp"
EXEC = ".\\bin\\game.exe"
SRCH = -LC:/msys64/mingw64/lib/SFML
LIBS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system


all:
	g++ $(SRCS) -o $(EXEC) $(SRCH) $(LIBS) 