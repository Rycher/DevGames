#pragma once
#include "libUnicornio.h"

enum Direcao { baixo, cima, esquerda, direita, parado };
class Player
{		
	public:
		Player();
		~Player();

		void inicializar(int x, int y);
		void atualizar();
		void desenhar();

		int getX();
		int getY();
		int getVelocidade();
		int getUp(int up);
		void setUp(int val, int up);
		void setposicaox(int x);
		void setposicaoy(int y);
		void setposicaoxA(int x);
		void setposicaoyA(int y);
		void setVelocidade(int velocidade);
		

	protected:
		Sprite sprite;
		int x, y;		
		int Up1, Up2, velocidade;
		Direcao direcao;
};

