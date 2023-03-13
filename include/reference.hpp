/*

 Author: Yannis STEFANELLI

 Creation Date: 13-03-2023 22:22:08

 Description :

*/

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

class GlobalReferencer {

    public :
        Texture hands;

        GlobalReferencer() {
            if (!hands.loadFromFile("../sprites/hands.png"))
                std::cout << "hands n'a pas chargé\n";
            hands.setSmooth(true);
        }
};