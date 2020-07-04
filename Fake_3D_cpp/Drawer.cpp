
#include "Drawer.h"

float Drawer::w, Drawer::h;

Drawer::Drawer()
{
    window.create(sf::VideoMode(1024, 576), "Friction");
    w = window.getSize().x, h = window.getSize().y;

    //Distance focale
    fl = 10;
}

void Drawer::update()
{
    while(window.pollEvent(sfEvent))
    {
        if(sfEvent.type == sf::Event::Closed)
            window.close();
    }

    dt = dtClock.restart().asSeconds();

    //Tous les 500 i, on fait apparaître un
    // nouveau portail
    if(++i % 500 == 0)
        randomPostcard();

    updatePostcards();
}

void Drawer::render()
{
    window.clear(sf::Color::Black);

    for (auto& p: postcards)
    {
        window.draw(p.shape);
    }

    window.display();
}

void Drawer::run()
{
    while(window.isOpen())
    {
        update();
        render();
    }
}

void Drawer::updatePostcards()
{
    for (auto& p: postcards)
    {
        if(p.perspective > 0.05)
        {
            //On déplace l'objet de la manière habituelle
            p.pos += p.vel * dt;
            //On calcule la perspective
            p.perspective = fl / p.pos.z;
            //On replace la figure en fonction de la perspective
            p.shape.setPosition(p.pos.x * p.perspective + w / 2, p.pos.y * p.perspective + h / 2);
            //Et on change sa taille en fonction de celle-ci
            p.shape.setScale(p.perspective, p.perspective);
        }
        else
        {
            //Si la perspective est inférieure à 0.05,
            // on considère que l'objet est trop loin
            // pour être vu et on le dessine de la même
            // couleur que le fond.
            p.shape.setFillColor(sf::Color::Black);
        }
    }
}

void Drawer::randomPostcard()
{
    //Pour générer des nombres aléatoires en C++, il
    // faut d'abord un "engine" (moteur; celui utilisé en
    // general, que j'utilise ici, est le mt19937, ou "Mersenne
    // Twister"), auquel on donne une graine; c'est le moteur qui
    // se charge de produire une série de nombres pseudo-aléatoires
    // en fonction de la graine donnée.
    //Afin d'éviter de tomber sur la même serie, la graine donnée
    // est le temps qui s'est écoulé depuis l'epoch (le point à partir
    // duquel les ordinateurs commencent à compter le temps; en général,
    // c'est le 1er janvier 1970).
    engine.seed(std::chrono::system_clock::now().time_since_epoch().count());

    //La deuxième chose nécessaire à l'heure de produire un nombre
    // aléatoire en C++ est la distribution de nombres choisie.
    // La distribution uniforme donne à chaque nombre la même
    // probabilité d'apparaître; la distribution gaussienne donne
    // plus de probabilités aux nombres éloignés des extrêmes de la
    // distribution, etc.
    std::uniform_real_distribution<float> posDistr(-500, 500);
    std::uniform_int_distribution<> velDistr(1, 5);
    std::uniform_int_distribution<> sizeDistr(50, 200);

    sf::Vector3f pos = {posDistr(engine), posDistr(engine), 1};
    sf::Vector3f vel = {0, 0, static_cast<float>(velDistr(engine))};

    postcards.emplace_back(pos, vel, static_cast<float>(sizeDistr(engine)));
}
