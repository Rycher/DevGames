#include "Candy.h"



Candy::Candy()
{
}


Candy::~Candy()
{
	exit(0);
}

void Candy::inicializar(int valor, float x, float y)
{
	if (!gRecursos.carregouAudio("somCandy"))
		gRecursos.carregarAudio("somCandy", "assets/sons/coin.wav");
	
	som.setAudio("somCandy");

	if (!gRecursos.carregouSpriteSheet("Candy"))
		gRecursos.carregarSpriteSheet("Candy", "./assets/sprites/candy.png");

	sprite.setSpriteSheet("Candy");
	this->x = x;
	this->y = y;
	this->valor = valor;
	vivo = true;
}

void Candy::atualizar()
{
	if (vivo) {
		sprite.avancarAnimacao();
		x--;



	}
}

void Candy::desenhar()
{
	if(vivo)
		sprite.desenhar(x, y);
}

int Candy::pega()
{
	vivo = false;
	som.tocar();
	return valor;
}

float Candy::getRot()
{
	return 0.0f;
}
