#include "MyRenderer.h"

MyRenderer::MyRenderer(int x, int y, RenderWindow* window){
    renderPhase = 4;
    thresholdValue = 0.5;
    this->x = x;
    this->y = y;
    black_and_white.loadFromFile("shaders/black.frag", Shader::Fragment);
    gaussian_blur.loadFromFile("shaders/gauss.frag", Shader::Fragment);
    sobel.loadFromFile("shaders/sobel.frag", Shader::Fragment);
    sobel2.loadFromFile("shaders/sobel2.frag", Shader::Fragment);
    threshold.loadFromFile("shaders/threshold.frag", Shader::Fragment);
    threshold.setUniform("threshold", thresholdValue);
    gaussian_blur.setUniform("screenSize", Vector2f(x, y));
    sobel.setUniform("screenSize", Vector2f(x, y));
    sobel2.setUniform("screenSize", Vector2f(x, y));
    texBuffer.create(x, y);
    movieState = true;
    this->window = window;
}
void MyRenderer::pause(){
    movieState = !movieState;
}
bool MyRenderer::getMovieState(){
    return movieState;
}
void MyRenderer::gaussBlur(){
    texBuffer.clear();
    gaussian_blur.setUniform("texture", texture);
    texBuffer.draw(Sprite(texture),&gaussian_blur);
    texBuffer.display();
    texture = texBuffer.getTexture();
}
void MyRenderer::sobelOperator(){
    texBuffer.clear();
    sobel.setUniform("texture", texture);
    texBuffer.draw(Sprite(texture),&sobel);
    texBuffer.display();
    texture = texBuffer.getTexture();
}
void MyRenderer::sobelOperator2(){
    texBuffer.clear();
    sobel2.setUniform("texture", texture);
    texBuffer.draw(Sprite(texture),&sobel2);
    texBuffer.display();
    texture = texBuffer.getTexture();
}
void MyRenderer::blackAndWhite(){
    texBuffer.clear();
    texBuffer.draw(Sprite(texture),&black_and_white);
    texBuffer.display();
    texture = texBuffer.getTexture();
}
void MyRenderer::thresholding(){
    texBuffer.clear();
    texBuffer.draw(Sprite(texture),&threshold);
    texBuffer.display();
    texture = texBuffer.getTexture();
}
void MyRenderer::setTexture(Texture texture){
    this->texture = texture;
}
Texture& MyRenderer::getTexture(){
    return texture;
}
void MyRenderer::printRenderPhase(){
    switch (renderPhase)
    {
    case 0:
        printf("Black and white\n");
        break;
    case 1:
        printf("Gaussian blur\n");
        break;
    case 2:
        printf("Sobel operator with edge orientation\n");
        break;
    case 3:
        printf("Sobel operator\n");
        break;
    case 4:
        printf("Thresholding\n");
        break;
    default:
        printf("Unknown render phase\n");
        break;
    }
}
void MyRenderer::increaseRenderPhase(){
    renderPhase++;
    renderPhase %= 5;
    printRenderPhase();
}
void MyRenderer::decreaseRenderPhase(){
    renderPhase--;
    if (renderPhase < 0)
        renderPhase = 4;
    printRenderPhase();
}
void MyRenderer::render(){
    if (renderPhase >= 0)
        blackAndWhite();
    if (renderPhase >= 1)
        gaussBlur();
    if (renderPhase >= 3)
        sobelOperator2();
    else if (renderPhase >= 2)
        sobelOperator();
    if (renderPhase >= 4)
        thresholding();
    window->draw(Sprite(getTexture()));
    window->display();
}
int MyRenderer::getRenderPhase(){
    return renderPhase;
}
void MyRenderer::increaseThreshold(float value){
    thresholdValue += value;
    if (thresholdValue > 1)
        thresholdValue = 1;
    else if (thresholdValue < 0)
        thresholdValue = 0;
    threshold.setUniform("threshold", thresholdValue);
    printf("Threshold: %f\n", thresholdValue);
}
