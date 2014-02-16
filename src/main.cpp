#include "menu.h"
#include "background.h"
#include "character.h"
#include <SFML/Graphics.hpp>
#include <iostream>

/*
resize(sf::Sprite s, int width, int height) {
  sf::FloatRect f s.getLocalBounds();
  std::cout << << std::endl;
}
*/

// Program entry point
int main(int argc, char ** argv) {
  // Create the SFML window
  sf::RenderWindow window(sf::VideoMode(1280, 720), "Rouge Hero");
  window.setFramerateLimit(30); // call it once, after creating the window
/*
  sf::Texture bg;
  if (!bg.loadFromFile("assets/ColorCrunched.jpg"))
    return EXIT_FAILURE;
  sf::Sprite background(bg);
*/
  //resize(background, 800.0, 600.0);
  
  Menu menu;
  Background bg;
  std::string char_name("test");
  Character character(char_name);

  sf::Event event;    // For polling events that SFML sends us

  bool a_dirty = false, d_dirty = false, j_dirty = false, k_dirty = false, l_dirty = false;

  while (window.isOpen()) {
    // Process any events sent by SFML since the last frame
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            // SFML sent us a close event, so clean up
            window.close();
        }

        if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::A)) {
          if(!a_dirty) {
            std::cout << "A down" << std::endl;
            a_dirty = true;
            character.moveLeft();
          }
        }

        if((event.type == sf::Event::KeyReleased) && (event.key.code == sf::Keyboard::A)) {
          std::cout << "A up" << std::endl;
          a_dirty = false;
        }

        if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::D)) {
          if(!d_dirty) {
            std::cout << "D down" << std::endl;
            d_dirty = true;
            character.moveRight();
          }
        }

        if((event.type == sf::Event::KeyReleased) && (event.key.code == sf::Keyboard::D)) {
          std::cout << "D up" << std::endl;
          d_dirty = false;
        }

        if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::J)) {
          if(!j_dirty) {
            std::cout << "J down" << std::endl;
            j_dirty = true;
            character.meleeAttack();
          }
        }

        if((event.type == sf::Event::KeyReleased) && (event.key.code == sf::Keyboard::J)) {
          std::cout << "J up" << std::endl;
          j_dirty = false;
        }

        if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::K)) {
          if(!k_dirty) {
            std::cout << "K down" << std::endl;
            k_dirty = true;
          }
        }

        if((event.type == sf::Event::KeyReleased) && (event.key.code == sf::Keyboard::K)) {
          std::cout << "K up" << std::endl;
          k_dirty = false;
        }

        if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::L)) {
          if(!l_dirty) {
            std::cout << "L down" << std::endl;
            l_dirty = true;
          }
        }

        if((event.type == sf::Event::KeyReleased) && (event.key.code == sf::Keyboard::L)) {
          std::cout << "L up" << std::endl;
          l_dirty = false;
        }
    }

    // Clear the window before we start drawing to it
    window.clear();

    //window.draw(background);

    bg.draw(&window);
    menu.draw(&window);
    character.draw(&window);

    // Notify the window that we're ready to render
    window.display();
  }

  return 0;
}
