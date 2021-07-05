#include <SFML/Graphics.hpp>
#include <iostream>
#include <unistd.h>
#include <math.h>
#include <experimental/random>
using namespace std;

int x;
int y;
int Xv = 0;
int Yv = 0;
int tubeX = 0;
int tubexx = 0;
unsigned int score = 0; 
bool start;


int main()
{
cout << "Game: \n";
cout << "\033[1;31mDeveloper: \033[0m" << "\033[36mSirMik3\033[0m" << "\n";
cout << "Sponsor, follow: \033[1;31mhttps://github.com/SirMik3.\033[0m\n";
cout << "Click to start game.\n";


    sf::Event event;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Game");
    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin( shape.getRadius(), shape.getRadius() );
    x = (window.getSize().x / 2);
    y = (window.getSize().y / 2);
    shape.setPosition(x, y);
    int uWidthe = rand() % 500 + 750;
    sf::RectangleShape tube(sf::Vector2f(100, 250));
    tube.setFillColor(sf::Color::Red);
    tube.setOrigin( 50, 250 );
    tubeX = (window.getSize().x);
    tube.setPosition( tubeX, (window.getSize().y) );

//window.setFramerateLimit(30);

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
//std::cout << "Pressed button: " << event.key.code << "\n";
if(event.type == sf::Event::MouseButtonPressed) { 
    start = true;
}
if (start){

    tubexx--;
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up){
     Yv--;
            if (Yv <= -500){
             window.close();
        }
    } else {
        if (Yv <= 669){
             Yv++;
        } else {
            window.close();
        }
       if (Yv <= -500){
             window.close();
        }
    }
    if (tubexx <= -2000){
        score++;
        tubexx = 0;
        tube.setScale(1, uWidthe);
    }
       sf::FloatRect player_boundingBox = shape.getGlobalBounds();
       sf::FloatRect tube_boundingBox = tube.getGlobalBounds();
   if (player_boundingBox.intersects(tube_boundingBox)){
        window.close();
    }
}

//std::cout << Yv << "\n";
    x = (window.getSize().x / 2) + Xv;
    y = (window.getSize().y / 2) + Yv;
    uWidthe = (std::experimental::randint(1, 4)) - 1;
    tubeX = (window.getSize().x) + tubexx;
        shape.setPosition(x, y);
        tube.setPosition(tubeX, (window.getSize().y));
        window.clear();
        window.draw(shape);
        window.draw(tube);
        window.display();
    }

    cout << "\033[1;31mYou Died, Your score is: \n" << score << "\033[0m\n"; 
}
