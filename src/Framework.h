#ifndef FRAMEWORK_H
#define FRAMEWORK_H

#include <SFML/Graphics.hpp>

class Framework
{
    public:
        Framework(sf::RenderWindow *);

        void input();
        void process();
        void output();

    protected:

    private:
        sf::RenderWindow *rw;
};

#endif // FRAMEWORK_H
