#pragma once
#include "libUnicornio.h"
#include "Objeto.h"



class Personagem2
{
public:
	Personagem2();
	~Personagem2();

	void inicializar(int x, int y);
	void atualizar();
	void desenhar();

	float getX() { return x; }
	float getY() { return y; }
	float getRot() { return Rot; };
	int getVida() { return vida; }



	Sprite getSprite() { return sprite; }
	int getPontuacao() { return pontuacao; }
	void pegar(int valor, TipoObjeto item);
	int getimortal() { return imortal; }
	void twoPlayers(bool twoPlayers);
	void levarDano(int valor);
	void setposicaox(int x);
	void setPontuacao();
protected:
	Sprite sprite;
	float x, y, velocidade, Rot,pontuacao;
	bool noChao, pulando, imortal, twoPlayer;
	//TipoItem item;
	int  vida;
	int timer;
};

