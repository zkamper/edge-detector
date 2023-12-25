#include <SFML/Graphics.hpp>
#include <sfeMovie/Movie.hpp>
#include <iostream>
#include <cstring>

using namespace sf;

int main(int argn, char **argc)
{
    char name[100];
    if (argn < 2){
        std::cout << "Please enter the name of the video:" << std::endl;
        std::cin >> name;
    }
    else{
        strcpy(name, argc[1]);
    }

    sfe::Movie movie;
    if(movie.openFromFile(name) != true){
        std::cout << "Error opening movie" << std::endl;
        return 0;
    }
    movie.play();
    Vector2f size = movie.getSize();
    RenderWindow window(VideoMode(size.x, size.y), "Image");

    // Variable declarations
    Texture texture;
    RenderTexture textureBuffer, textureBuffer2;
    Sprite sprite;
    Shader black_and_white,gaussian_blur,sobel;
    
    // Create textures with the size of the video
    texture.create(size.x,size.y);
    textureBuffer.create(size.x,size.y);
    textureBuffer2.create(size.x,size.y);

    // Load shaders from memory
    black_and_white.loadFromFile("shaders/black.frag", Shader::Fragment);
    gaussian_blur.loadFromFile("shaders/gauss.frag", Shader::Fragment);
    sobel.loadFromFile("shaders/sobel.frag", Shader::Fragment);
    
    // Declare shader variables
    black_and_white.setUniform("texture", texture);
    gaussian_blur.setUniform("texture", textureBuffer.getTexture());
    gaussian_blur.setUniform("screenSize", Vector2f(size.x,size.y));
    sobel.setUniform("screenSize", Vector2f(size.x,size.y));


    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        
        movie.update();
        texture = movie.getCurrentImage();
        
        // Apply black-and white filter
        textureBuffer.clear();
        textureBuffer.draw(Sprite(texture), &black_and_white);
        textureBuffer.display();

        // Apply gaussian blur filter
        textureBuffer2.clear();
        textureBuffer2.draw(Sprite(textureBuffer.getTexture()), &gaussian_blur);
        textureBuffer2.display();

        // Apply sobel operator
        sobel.setUniform("texture", textureBuffer2.getTexture());
        sprite.setTexture(textureBuffer2.getTexture());
        window.draw(sprite, &sobel);

        window.display();
    }
}