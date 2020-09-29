#include "libUnicornio.h"
#pragma once
class Candy
{
	public:
		Candy();
		~Candy();

		void inicializar(int valor, float x, float y);
		void atualizar();
		void desenhar();
		int pega();

		float getX() { return x; }
		float getY() { return y; }
		Sprite getSprite() { return sprite; }
		bool getVivo() { return vivo; }
		float getRot();

protected:
	Sprite sprite;
	float x, y;
	Som som;
	int valor;
	int i;
	bool vivo;
};

