#include "libUnicornio.h"
#include "Player.h"
#include "Minerio.h"
#pragma once
enum Telas {
	tMenu, tJogo, tCreditos, tInstrucoes, tFim,
	tSair
};
#define NUMTILES 5
struct Tiled{
	int ID,  x,  y;
};

struct P2D {
	int x,  y; 
};

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();
	void setTileID(int PosC, int PosX, int PosY, int ID);
	void setMapa(int indiceMapa);	
	void executar();

protected:
	Sprite spritesTile[NUMTILES], spriteMenu, fundoMenu, fundoCredits, fundoTutorial, fundoFim;
	Sprite btCred1, btCred2, btGame1, btGame2, btTutorial1, btTutorial2, btExit1, btExit2, iconGold, iconOre;
	string nomesTile[NUMTILES],  caminho;
	int numTiles,  numColunas,  numLinhas,  numCamadas , savesVars[11],
		mapas[3][32][24],  numFrames,  velocidade,  Mapx, pSpeed, pBackPack, pCollectOre;
	Tiled*** Tile;//Tile[3][32][24];
	ifstream arqConfig, arqSaveIf;
	ofstream arqSaveOf;
	P2D deslocamento,  pTile, pTileMapa, pPlayerPos;
	bool mudarMapa;
	Player Player;
	Minerio *vMinerio;
	int minerios, golds, mapaAtual;
	Telas telaAtual;
	void telaMenu();
	void telaJogo();
	void telaCreditos();
	void telaInstrucoes();	
	void tPause();
	void telaFim();
};

