#include <SFML/Graphics.hpp>
#include <optional> // обязательно для std::optional

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");

    sf::CircleShape circle(20.f); // радиус 20
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(sf::Vector2f(100.f, 100.f));

    while (window.isOpen())
    {
        while (std::optional<sf::Event> event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        //window.clear(sf::Color::Black);
        window.draw(circle);
        window.display();
    }

    return 0;
}
