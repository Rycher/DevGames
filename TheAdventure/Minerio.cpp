#include "Minerio.h"

Minerio::Minerio()
{	
}

Minerio::~Minerio()
{
}

void Minerio::inicializar(int x, int y)
{
	this->x = 0;
	this->y= 0;
	if (!gRecursos.carregouSpriteSheet("minerio"))
		gRecursos.carregarSpriteSheet("minerio", "./assets/imagens/minerio.png");

	sprite.setSpriteSheet("minerio");
	sprite.setEscala(2, 2);
	vida = 100;	
	this->x = x;
	this->y = y;
}

void Minerio::atualizar()
{

	sprite.setSpriteSheet("minerio");
	/*sprite.setVelocidadeAnimacao(10);
	sprite.avancarAnimacao();*/
}

void Minerio::desenhar()
{
	sprite.desenhar(x, y);
}

void Minerio::retirarVida(int forca)
{
	vida -= forca;
}

void Minerio::setVida(int vida)
{
	this->vida = vida;
}

int Minerio::getVida()
{
	return this->vida;
}

int Minerio::getY()
{
	return this->y;
}

int Minerio::getX()
{
	return this->x;
}
