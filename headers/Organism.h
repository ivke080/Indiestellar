#pragma once

#ifdef __linux__
	#include <SFML/Graphics.hpp>
	#include <fstream>
	#include "Animation.h"
	#include "Consts.h"
#elif defined _WIN32
	#include <SFML\Graphics.hpp>
#endif
/*
*	Bazna klasa za sve objekte u igri
*/
class Organism
{
public:
  Organism();
  Organism(const sf::Texture &a, const sf::Font& font, const std::vector<Organism*>& listOfNames);
	~Organism();

	void Resize();
  void Update(float dt);
	void Render(sf::RenderWindow &window);
	const Animation& GetAnimation() const;
	std::string& GetName();

	void SetRenderText(const std::string& s);

	void SetColor(sf::Color);
private:
	std::string m_name;
  int m_situation;
  int m_VEL_MIN = 200;
  int m_VEL_MAX = 400;
  int m_velocity;

	Animation *m_anim;
	sf::Sprite m_image;
	sf::Text m_renderText;
	sf::Font m_font;
	sf::Color m_textColor = sf::Color::White;
};
