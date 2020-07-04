
#pragma once

#include <iostream>
#include <random>
#include <chrono>

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class Drawer
{
    private:

        sf::RenderWindow window;
        static float w, h;
        sf::Event sfEvent;
        sf::Clock dtClock;
        float dt;

        std::mt19937 engine;
        int i = -1;

        sf::RectangleShape postcard;
        sf::Vector3f postcardPos;
        sf::Vector3f postcardVel;

        //Classe auxiliaire pour créer des objets
        // de type 'Postcard' avec une figure, une
        // position, une vitesse et une perspective
        // associées.
        class Postcard
        {
            public:

                sf::RectangleShape shape;
                sf::Vector3f pos;
                sf::Vector3f vel;
                float perspective;

                Postcard(sf::Vector3f pos, sf::Vector3f vel, float size): pos(pos), vel(vel)
                {
                    perspective = 1;
                    shape.setSize({size, size});
                    shape.setOrigin(shape.getSize() / 2.f);
                    shape.setPosition(this->pos.x, this->pos.y);
                    shape.setFillColor(sf::Color::White);
                }
        };

        float fl;
        std::vector<Postcard> postcards;

        void randomPostcard();
        void updatePostcards();

    public:

        Drawer();

        void update();
        void render();
        void run();
};
