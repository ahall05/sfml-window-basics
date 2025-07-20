#include <SFML/Graphics.hpp>

int main()
{
    // Get the current desktop resolution
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    

    // Calculate window size as a fraction of the desktop size
    unsigned int windowWidth = static_cast<unsigned int>(desktop.size.x * 0.75f);
    unsigned int windowHeight = static_cast<unsigned int>(desktop.size.y * 0.75f);

    sf::RenderWindow window(sf::VideoMode({ windowWidth, windowHeight}), "Main Window");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    // (Optional) centre the window
    sf::Vector2i pos{
        static_cast<int>((desktop.size.x - windowWidth) / 2),
        static_cast<int>((desktop.size.y - windowHeight) / 2)
    };

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event ->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}