/*

 Author: Yannis STEFANELLI

 Creation Date: 06-03-2023 11:42:41

 Description :

*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Thor/Shapes/ConcaveShape.hpp>
#include <Thor/Shapes/Shapes.hpp>

#include "../include/square.hpp"
#include "../include/controls.hpp"

using namespace sf;

int main(void)
{
    ContextSettings settings;
    settings.antialiasingLevel = 8;

    RenderWindow window(VideoMode(1080, 731), "RockPaperScissors", Style::Titlebar | Style::Close, settings);
    // auto image = sf::Image{};
    // if (!image.loadFromFile("../sprites/logo.png"))
    //     std::cout << "Icone n'a pas chargé\n";
    // window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());

    bool testclick = false;
    bool debug = true;

    Clock clock;
    Texture texture;

    ControlButtons actions(3);

    //Frame loop
    while (window.isOpen())
    {   
        //Event loop
        Event event;
        while (window.pollEvent(event))
        {   
            //Conditions to close the window
            if (event.type == Event::Closed)
                window.close();
            if (Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();
            if (event.type == Event::MouseButtonReleased)
                testclick = true;
        }    
        //Clearing the window after each draw
        window.clear(Color::Black);

        actions.draw(window); 
        
        testclick = false;
        window.display();
    }
    return 0;
}