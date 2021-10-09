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
    text.setString("Circle");
    text.setCharacterSize(48);
    text.setFillColor(Color::Red);
    text.setPosition(265.f, 265.f);
    text.setStyle(Text::Bold | Text::Underlined);

    //Antialiasing
    ContextSettings settings;
    settings.antialiasingLevel = 8;

    RenderWindow window(VideoMode(650, 650), "SFML Window", Style::Default, settings);

    //Circle
    CircleShape shape(225.f);
    shape.setFillColor(Color::Green);

    shape.setOutlineThickness(20.f);
    shape.setOutlineColor(Color(3, 94, 252));

    shape.setPointCount(100);
    shape.setPosition(105.f, 100.f);


    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if(event.type == Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        window.draw(shape);
        window.draw(text);
        window.display();
    }

    return 0;
}
