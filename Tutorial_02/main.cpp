#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

int main()
{
    //Text&font
    Text text;
    Font font;

    font.loadFromFile("fonts/Roboto-Regular.ttf");

    text.setFont(font);
    text.setString("CENTER");
    text.setCharacterSize(32);
    text.setFillColor(Color::Black);
    text.setPosition(340.f, 280.f);

    //Window
    RenderWindow window(VideoMode(800, 600), "Tutorial 2", Style::Default);
    window.setFramerateLimit(60);

    //Shape
    RectangleShape rectangle(Vector2f(150.f, 150.f));
    rectangle.setFillColor(Color::Cyan);
    rectangle.setOutlineThickness(10.f);
    rectangle.setOutlineColor(Color::Yellow);
    rectangle.setPosition(325.f, 225.f);

    while(window.isOpen())
    {
        Event event;
        while(window.pollEvent(event))
        {
            if(event.type == Event::Closed)
            {
                window.close();
            }
        }

        //Mouse and keyboard
        if(Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up))
        {
            rectangle.move(0.f, -3.f);
            text.move(0.f, -3.f);
            text.setString("UP");
        }
        if(Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down))
        {
            rectangle.move(0.f, 3.f);
            text.move(0.f, 3.f);
            text.setString("DOWN");
        }
        if(Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))
        {
            rectangle.move(-3.f, 0.f);
            text.move(-3.f, 0.f);
            text.setString("LEFT");
        }
        if(Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))
        {
            rectangle.move(3.f, 0.f);
            text.move(3.f, 0.f);
            text.setString("RIGHT");
        }
        if(Mouse::isButtonPressed(Mouse::Right))
        {
            rectangle.move(3.f, 0.f);
            text.move(3.f, 0.f);
            text.setString("RIGHT");
        }
        if(Mouse::isButtonPressed(Mouse::Left))
        {
            rectangle.move(-3.f, 0.f);
            text.move(-3.f, 0.f);
            text.setString("LEFT");
        }

        window.clear();
        window.draw(rectangle);
        window.draw(text);
        window.display();
    }

    return 0;
}

