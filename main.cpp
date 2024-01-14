#include "MyRenderer.h"

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
    
    MyRenderer renderer(size.x, size.y,&window);
    Sprite sprite;


    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed){
                switch (event.key.code){
                case Keyboard::Space:
                    renderer.pause();
                    if(renderer.getMovieState())
                        movie.play();
                    else
                        movie.pause();
                    break;
                case Keyboard::Left:
                    renderer.decreaseRenderPhase();
                    break;
                case Keyboard::Right:
                    renderer.increaseRenderPhase();
                    break;
                case Keyboard::Up:
                    if(renderer.getRenderPhase() == 4)
                        renderer.increaseThreshold(0.01);
                    break;
                case Keyboard::Down:
                    if(renderer.getRenderPhase() == 4)
                        renderer.increaseThreshold(-0.01);
                    break;
                case Keyboard::R:
                    movie.setPlayingOffset(seconds(0));
                    printf("Restarted\n");
                case Keyboard::Escape:
                    window.close();
                    break;
                default:
                    break;
                }
            }
        }

        window.clear();
        movie.update();
        renderer.setTexture(movie.getCurrentImage());
        renderer.render();
    }
}