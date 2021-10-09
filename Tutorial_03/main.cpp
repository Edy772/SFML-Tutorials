#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

int main()
{
    //Texture
    Texture tex;
    tex.loadFromFile("images/texture.jpg");
    tex.setSmooth(true);
    tex.setRepeated(true);

    //Shape
    CircleShape circle(300.f);
    circle.setTexture(&tex);
    circle.setTextureRect(IntRect(10, 10, 100, 100));

    //Window
    RenderWindow window(VideoMode(600, 600), "SFML tutorial 3", Style::Default);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(circle);
        window.display();
    }

    return 0;
}
