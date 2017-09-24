#include <SFML/Graphics.hpp>
#include <iostream>

#include "Framework.h"

int main(){
    sf::RenderWindow rw(sf::VideoMode(1000, 800), "Graphing Calculator");
    Framework f(&rw);

    while (rw.isOpen()){
        sf::Event event;

        while (rw.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                rw.close();
            }
        }
    }

    return 0;
}
