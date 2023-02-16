SRCS = ".\\src\\main.cpp"
EXEC = ".\\bin\\game.exe"
SRCH = -LC:/msys64/mingw64/lib/SFML
LIBS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
RSCS = ".\\src\\resources\\icon.png"
OBJC = ".\\build\\icon.o"

all:
	objcopy --input binary --output elf64-x86-64 ".\\src\\resources\\icon.png" icon.o
	g++ $(SRCS) -o $(EXEC) $(SRCH) $(LIBS)
	# rm .\\build\\icon.o