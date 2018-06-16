#include "terreno.hpp"
#include <SFML\Graphics.hpp>
#include <SFML/Graphics.hpp>

Terreno::Terreno(void)
{
	load();
}
Terreno& Terreno::getInstance()
{
	static Terreno instance;
	return instance;
}
void Terreno::load()
{
	mRenderTexture.create(1280,720);
	sf::Texture* temp=new sf::Texture;
	temp->loadFromFile("terreno.png");
	mTerrenoSpr.setTexture(*temp);
	mTerrenoSpr.setPosition(0,0);
	mChanged=true;
}
void Terreno::draw(sf::RenderWindow& window)
{
	if(mChanged == true)
	{
		mRenderTexture.clear(sf::Color::White);
		mRenderTexture.draw(mTerrenoSpr);
		
		for(auto i=mHuecos.begin();i!= mHuecos.end();i++)
		{
			mRenderTexture.draw(*(*i));
		}
		mRenderTexture.display();
		
		mTerrenoImg= mRenderTexture.getTexture().copyToImage();
		mTerrenoImg.createMaskFromColor(sf::Color::Blue);
		mTerrain.loadFromImage(mTerrenoImg);
		
		std::cout<<"ACTUALIZAR"<<std::endl;
		mChanged=false;
	}
	window.draw(sf::Sprite(mTerrain));
}
void Terreno::crearHueco(sf::Vector2f pos,float radio)
{
	sf::CircleShape* temp=new sf::CircleShape;
	temp->setRadius(radio);
	temp->setOrigin(radio,radio);
	temp->setPosition(pos);
	temp->setFillColor(sf::Color::Blue);
	mHuecos.push_back(temp);
	mChanged=true;
}
sf::Image& Terreno::getTerrenoImage()
{
	return mTerrenoImg;
}
void Terreno::reset()
{
	while(!mHuecos.empty())
	{
		delete mHuecos[mHuecos.size()-1];
		mHuecos.pop_back();
	}
	mChanged = true;
}
