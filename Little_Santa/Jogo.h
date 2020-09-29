#pragma once
#include "Personagem.h"
#include "Personagem2.h"
#include "Objeto.h"

enum Telas {tMenu, tJogo, tConfig, tCreditos, tInstrucoes, 
	        tGameOver, tSair};

enum Botoes {bJogar, bInstrucoes, bCreditos, bSair, 
	         bOk, bContinuar, b1Jogador, b2Jogadores};

class Jogo
{
public:
	Jogo();
	~Jogo();
	void inicializar();
	void finalizar();
	void executar();

	

protected:
	Telas telaAtual;
	BotaoSprite botoes[8];

	Sprite fundo,fundo2, chao, fundoPausa,fundoMenu, fundoCreditos, fundoInstrucoes, fundoCreditos2, fundoInstrucoes2, fundoGameOver;
	Vetor2D pfundo1, pfundo2;
	Personagem personagem;
	Personagem2 personagem2;
	float velocidadeCenario;
	Objeto birds[4], candys[8], predios[2],star;
	Texto tPontuacao,tVida;
	bool twoPlayers;
	int timer,timer2;
	bool pausa;
	void telaMenu();
	void telaJogo();
	void telaCreditos();
	void telaInstrucoes();
	void telaConfig();
	void telaGameOver();
	void reiniciarGame();	
};

