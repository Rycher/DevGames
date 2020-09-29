#pragma once
#include "libUnicornio.h"
class Minerio
{
public:
	Minerio();
	~Minerio();

	void inicializar(int x, int y);
	void atualizar();
	void desenhar();
	void retirarVida(int forca);
	void setVida(int vida);
	int getVida();
	int getY();
	int getX();

protected:
	Sprite sprite;
	float x, y;
	int vida;
};

