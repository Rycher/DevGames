#include "libUnicornio.h"

#pragma once

enum TipoObjeto {tBird, tPredio, tCandy, tStar};

class Objeto
{
public:
	Objeto();
	~Objeto();
	void inicializar(TipoObjeto t);
	void atualizar(float vCenario);
	void desenhar();

	float getX() { return x; }
	float getY() { return y; }
	void setposicaox(int posicao);	
	void tocarsom(TipoObjeto t);	
	Sprite getSprite() { return sprite;}
	void zeraVelocidade();

protected:
	Sprite sprite;
	Som som;
	float x, y, velocidade, velocidadeCenario,velocidadePass;
	TipoObjeto tipo;	
	int timer, timer2;
	char Op;
	
};

