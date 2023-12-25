CXX = g++
CXXFLAGS = -std=c++14
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfeMovie -lsfml-audio

main: main.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(LIBS)
	$(CXX) $(CXXFLAGS) $< -g $(LIBS)
clean:
	rm -f main