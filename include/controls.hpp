/*

 Author: Yannis STEFANELLI

 Creation Date: 13-03-2023 20:47:28

 Description :

*/

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Thor/Shapes/ConcaveShape.hpp>
#include <Thor/Shapes/Shapes.hpp>
#include <vector>
#include "../include/reference.hpp"

using namespace sf;
using namespace thor::Shapes;

class Button {

    public:

        Button(int z_layer = 0);

        int z_layer;
        
        GlobalReferencer reference;
        Texture texture;
        Vector2i mousepos;
        Color color = Color::Cyan;
        ConvexShape shape = roundedRect(Vector2f(200, 200), 15, this->color);

        void hover(RenderWindow &window, Color color = Color::Magenta);
        void draw(RenderWindow &window);
        void setImage(IntRect bounds);
};

class ControlButtons {

    int nb = 1;

    public:

        ControlButtons(int nb = 1);

        Button element;
        std::vector<Button> controls;

        void draw(RenderWindow &window);
};