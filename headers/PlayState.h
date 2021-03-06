#pragma once

#include "Game.h"
#include "State.h"
#include "Organism.h"
#include "Book.h"
#include "SFML/Audio.hpp"
#include <vector>

class PlayState : public State
{
public:
  PlayState(Game* game);
  ~PlayState();

  void Update(float dt);
  void Render(sf::RenderWindow& window);
  void Clean();
  int GetPersonIndex() const;
  void AddPerson();
  void Keyboard(char key);
  void Controller(sf::Keyboard::Key& key); // za kretanje kroz meni
  void ResetGame();
  sf::Music loadMusic(std::string music_filename, float music_frequency, float music_volume, bool music_loop);

private:
  std::vector<sf::Text> m_options;

  sf::Sprite m_background;
  sf::Sprite m_badge;
  sf::Sprite m_logo;
  sf::Clock m_clock;

  float m_optionsX;
  float m_spawnTime;
  int m_selectedOption;

  // objects
  std::vector<Organism*> m_organisms;
  std::vector<char> m_inputText;
  std::vector<Animation*> m_animations;
  Book m_book;

  // bools - logic
  bool m_optionsAnimation;
  bool m_bookAnimation;
  bool m_peopleMoving;
  bool m_drawMenu;
  bool m_drawBook;
  bool m_menuActive;


private:
  const int OPTIONS_MOVE_STEP = 550;
  const int OPTIONS_LINE_HEIGHT = 120;
  const int OPTIONS_FONT_SIZE = 90;

private:
  void DeleteOrganism(size_t indeks);
  void SortOrganisms();
  void RenderAnimations(sf::RenderWindow& window);
  void UpdateAnimations();
  void RemoveAnimation(size_t index);
  void AddExplosion(const std::string resourceName, float x, float y);
};
