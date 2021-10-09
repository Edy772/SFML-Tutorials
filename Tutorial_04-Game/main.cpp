#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <cstdlib>
#include <ctime>

using namespace sf;
using namespace std;

int w = 640;
int h = 480;

int score = 0;

int main()
{
    srand(time(0));

    //Settings
    ContextSettings settings;
    settings.antialiasingLevel = 8;

    RenderWindow window(VideoMode(w, h), "Simple game!", Style::Close, settings);
    window.setFramerateLimit(60);

    Sprite background;
    Texture tex1;
    tex1.loadFromFile("images/background.png");
    background.setTexture(tex1);

    Text text1;
    Text text2;

    Font font;

    font.loadFromFile("fonts/Roboto-Regular.ttf");

    text1.setFont(font);
    text1.setString("Score= " + to_string(score));
    text1.setCharacterSize(25);
    text1.setFillColor(Color::White);
    text1.setPosition(15.f, 450.f);

    text2.setFont(font);
    text2.setString("Press ESC to exit the game");
    text2.setCharacterSize(25);
    text2.setFillColor(Color::White);
    text2.setPosition(330.f, 450.f);

    //Bullet
    CircleShape bullet(30.f, 3);
    bool isShot = false;
    bullet.setFillColor(Color(235, 163, 82));
    bullet.setOutlineThickness(3);
    bullet.setOutlineColor(Color(140, 189, 85));
    bullet.setPosition(0.f, window.getSize().y - bullet.getRadius()*3);

    //Ball
    CircleShape ball(60.f, 100);
    int dir = 0;
    ball.setFillColor(Color(rand() % 255, rand() % 255, rand() % 255));
    ball.setPosition(0.f, 10.f);

    while (window.isOpen())
    {
        Event e;
        while(window.pollEvent(e))
        {
            if(e.type == Event::Closed)
            {
                window.close();
            }

                if (e.type == Event::KeyPressed && e.key.code == Keyboard::Escape)
                {
                    window.close();
                }
        }

        //Update ball
        if(ball.getPosition().x <= 0)
            dir = 1;
        else if (ball.getPosition().x + ball.getRadius()*2 >= window.getSize().x)
            dir = 0;

        if(dir == 0)
        {
            ball.move(-5.f, 0.f);
        }
        else
        {
            ball.move(5.f, 0.f);
        }

        //Update bullet
        if(Mouse::isButtonPressed(Mouse::Left))
            isShot = true;

        if(!isShot)
            bullet.setPosition(Mouse::getPosition(window).x, bullet.getPosition().y);
        else
            bullet.move(0.f, -5.f);

        //Bullet collision
        if(bullet.getPosition().y <= 0)
        {
            isShot = false;
            bullet.setPosition(bullet.getPosition().x, window.getSize().y - bullet.getRadius()*3);
        }

        if(bullet.getGlobalBounds().intersects(ball.getGlobalBounds()))
        {
            isShot = false;
            bullet.setPosition(bullet.getPosition().x, window.getSize().y - bullet.getRadius()*3);
            ball.setFillColor(Color(rand() % 255, rand() % 255, rand() % 255));
            score ++;
            text1.setString("Score= " + to_string(score));
        }

        window.clear();

        //Draw
        window.draw(background);
        window.draw(ball);
        window.draw(bullet);
        window.draw(text1);
        window.draw(text2);
        window.display();
    }
}
