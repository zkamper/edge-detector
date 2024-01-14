#include <SFML/Graphics.hpp>
#include <sfeMovie/Movie.hpp>
#include <iostream>
#include <cstring>

using namespace sf;

class MyRenderer{
private:
    int x,y;
    Shader black_and_white,gaussian_blur,sobel,sobel2,threshold;
    RenderTexture texBuffer;
    bool movieState;
    RenderWindow* window;
    Texture texture;
    int renderPhase;
    float thresholdValue;
public:
    MyRenderer(int x, int y, RenderWindow* window);
    void pause();
    bool getMovieState();
    void gaussBlur();
    void sobelOperator();
    void sobelOperator2();
    void blackAndWhite();
    void thresholding();
    void setTexture(Texture texture);
    Texture& getTexture();
    void printRenderPhase();
    void increaseRenderPhase();
    void decreaseRenderPhase();
    void render();
    int getRenderPhase();
    void increaseThreshold(float value);
};