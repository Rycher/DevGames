#pragma once
#include "libUnicornio.h"
#include "Objeto.h"


enum Direcao { baixo, cima, esquerda, direita, parado };
enum Player{Player1,Player2};
class Personagem
{
	public:
		Personagem();
		~Personagem();

		void inicializar(int x,int y);
		void atualizar(Player Player);
		void desenhar();
		
		float getX() { return x; }
		float getY() { return y; }
		float getRot() { return Rot; };
		int getVida() { return vida; }



		Sprite getSprite() { return sprite; }
		int getPontuacao() { return pontuacao; }		
		void pegar(int valor,TipoObjeto item);
		int getimortal() { return imortal; }
		void levarDano(int valor);
		void setposicaox(int x);
		void setCorPlayer(bool twoplayer);
		void setPontuacao();
		void twoPlayers(bool twoPlayers);
		//void moverPlayer(Player Player);

	protected:
		Sprite sprite;
		float x, y, velocidade,Rot;
		bool noChao,pulando,imortal,twoPlayer;
		Direcao direcao;		
		float pontuacao,vida;
		int timer;
		Cor cor;
		
};

