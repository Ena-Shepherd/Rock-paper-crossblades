/*

 Author: Yannis STEFANELLI

 Creation Date: 06-03-2023 12:05:28

 Description :

*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Thor/Shapes/ConcaveShape.hpp>
#include <Thor/Shapes/Shapes.hpp>
#include <vector>
#include "../include/controls.hpp"

using namespace sf;
using namespace thor::Shapes;

Button::Button(int z_layer) 
{
    this->z_layer = z_layer;
    texture = reference.hands;
    
    shape.setTexture(&texture);
}

void Button::hover(RenderWindow &window, Color color) {

    Mouse::getPosition(window);

    if (shape.getGlobalBounds().contains(mousepos.x, mousepos.y))
        shape.setFillColor(color);
    else 
        shape.setFillColor(this->color);
}

void Button::draw(RenderWindow &window) {

    mousepos = Mouse::getPosition(window);
    hover(window);
    window.draw(shape);
}

void Button::setImage(IntRect bounds) {
    shape.setTextureRect(bounds);
}

/////////////////////////////

ControlButtons::ControlButtons(int nb)
{
    int offset = 0;
    IntRect bounds(0, 0, 110, 110);
    GlobalReferencer reference;
    Clock clock;

    for (int i = 0; i != nb; i++) {
        controls.push_back(element);
        controls[i].shape.setPosition(20, 20 + offset);
        controls[i].setImage(bounds);
        
        offset += 220;
        bounds.left += 120;
    }
    offset = 0;

    this->nb = nb;
}

void ControlButtons::draw(RenderWindow &window) {
    for (int i = 0; i != nb; i++) {
        controls[i].draw(window);
    }
}