CXX = g++
CXXFLAGS = -std=c++14
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfeMovie -lsfml-audio
OBJS = main.o MyRenderer.o

all: main

main: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@ $(LIBS)

main.o: main.cpp MyRenderer.h
	$(CXX) $(CXXFLAGS) -c main.cpp

MyRenderer.o: MyRenderer.cpp MyRenderer.h
	$(CXX) $(CXXFLAGS) -c MyRenderer.cpp

clean:
	rm -f main $(OBJS)