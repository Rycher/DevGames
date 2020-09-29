#include "Jogo.h"

Jogo::Jogo()
{

}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(1280, 720, true);	

	//Interface
	//-------------------------------------------

	twoPlayers = false;
	personagem.twoPlayers(false);

	if (!gRecursos.carregouSpriteSheet("fundoMenu"))
		gRecursos.carregarSpriteSheet("fundoMenu", "assets/sprites/telas/tela_menu.jpg");
	fundoMenu.setSpriteSheet("fundoMenu");

	if (!gRecursos.carregouSpriteSheet("bJogar"))
		gRecursos.carregarSpriteSheet("bJogar",	"assets/sprites/botoes/bJogar.png", 3);

	botoes[bJogar].setSpriteSheet("bJogar");
	botoes[bJogar].setPos(gJanela.getLargura() / 2, 340);

	if (!gRecursos.carregouSpriteSheet("bInstrucoes"))
		gRecursos.carregarSpriteSheet("bInstrucoes", "assets/sprites/botoes/bInstrucoes.png", 3);

	botoes[bInstrucoes].setSpriteSheet("bInstrucoes");
	botoes[bInstrucoes].setPos(gJanela.getLargura() / 2, 400);

	if (!gRecursos.carregouSpriteSheet("bCreditos"))
		gRecursos.carregarSpriteSheet("bCreditos", "assets/sprites/botoes/bCreditos.png", 3);

	botoes[bCreditos].setSpriteSheet("bCreditos");
	botoes[bCreditos].setPos(gJanela.getLargura() / 2, 460);

	if (!gRecursos.carregouSpriteSheet("bSair"))
		gRecursos.carregarSpriteSheet("bSair", "assets/sprites/botoes/bSair.png", 3);

	botoes[bSair].setSpriteSheet("bSair");
	botoes[bSair].setPos(gJanela.getLargura() / 2, 540);

	if (!gRecursos.carregouSpriteSheet("bOk"))
		gRecursos.carregarSpriteSheet("bOk", "assets/sprites/botoes/bOk.png", 3);

	botoes[bOk].setSpriteSheet("bOk");
	botoes[bOk].setPos(gJanela.getLargura() / 2, 680);

	if (!gRecursos.carregouSpriteSheet("bContinuar"))
		gRecursos.carregarSpriteSheet("bContinuar", "assets/sprites/botoes/bContinuar.png", 3);

	botoes[bContinuar].setSpriteSheet("bContinuar");
	botoes[bContinuar].setPos(gJanela.getLargura() / 2 - 200, 300);

	if (!gRecursos.carregouSpriteSheet("b1Jogador"))
		gRecursos.carregarSpriteSheet("b1Jogador", "assets/sprites/botoes/b1Jogador.png", 3);

	botoes[b1Jogador].setSpriteSheet("b1Jogador");
	botoes[b1Jogador].setPos(gJanela.getLargura() / 2 - 150, 300);

	if (!gRecursos.carregouSpriteSheet("b2Jogadores"))
		gRecursos.carregarSpriteSheet("b2Jogadores", "assets/sprites/botoes/b2Jogadores.png", 3);

	botoes[b2Jogadores].setSpriteSheet("b2Jogadores");
	botoes[b2Jogadores].setPos(gJanela.getLargura() / 2 + 150, 300);

	telaAtual = tMenu;
	
	if (!gRecursos.carregouMusica("musicaMenu"))
		gRecursos.carregarMusica("musicaMenu", "assets/sons/Music_Menu.mp3");	

	//Game
	//-------------------------------------------		

	if (!gRecursos.carregouMusica("musicaJogo"))
		gRecursos.carregarMusica("musicaJogo", "assets/sons/Christimas_Music.mp3");

	if (!gRecursos.carregouSpriteSheet("fundo"))
		gRecursos.carregarSpriteSheet("fundo", "assets/sprites/telas/jogo.png");
	fundo.setSpriteSheet("fundo");

	if (!gRecursos.carregouSpriteSheet("fundo2"))
		gRecursos.carregarSpriteSheet("fundo2", "assets/sprites/telas/jogo.png");
	fundo2.setSpriteSheet("fundo2");


	if (!gRecursos.carregouSpriteSheet("fundoCreditos"))
		gRecursos.carregarSpriteSheet("fundoCreditos", "assets/sprites/telas/fundo_credito.jpg");
		fundoCreditos.setSpriteSheet("fundoCreditos");


	if (!gRecursos.carregouSpriteSheet("fundoinstrucoes"))
		gRecursos.carregarSpriteSheet("fundoinstrucoes", "assets/sprites/telas/fundo_instrucoes.jpg");
		fundoInstrucoes.setSpriteSheet("fundoinstrucoes");

	if (!gRecursos.carregouSpriteSheet("fundoPausa"))
		gRecursos.carregarSpriteSheet("fundoPausa", "assets/sprites/telas/pausa.png");
	fundoPausa.setSpriteSheet("fundoPausa");

	if (!gRecursos.carregouSpriteSheet("fundoGameOver"))
		gRecursos.carregarSpriteSheet("fundoGameOver", "assets/sprites/telas/gameOver.png");
	fundoGameOver.setSpriteSheet("fundoGameOver");

	//

	pfundo1.x = 0;
	pfundo1.y = gJanela.getAltura() / 2;

	pfundo2.x = gJanela.getLargura();
	pfundo2.y = gJanela.getAltura() / 2;	
	
	
	star.inicializar(tStar);
	for (int n = 0; n < 4; n++)
	{
		birds[n].inicializar(tBird);
	}

	for (int c = 0; c < 8; c++)
	{
		candys[c].inicializar(tCandy);
	}

	for (int c = 0; c < 2; c++)
	{
		predios[c].inicializar(tPredio);
	}

	if (!gRecursos.carregouFonte("minhaFonte"))
		gRecursos.carregarFonte("minhaFonte", "assets/fontes/Hey August.ttf", 22);

	tPontuacao.setFonte("minhaFonte");
	tPontuacao.setCor(0, 0, 0);
	tPontuacao.setAncora(0, 0.5);
	tPontuacao.setEscala(2.0, 2.0);

	tVida.setFonte("minhaFonte");
	tVida.setCor(0, 0, 0);
	tVida.setAncora(0, 0.5);

	personagem.inicializar(200, 600);
	personagem2.inicializar(200,700);


	velocidadeCenario = 2;
	timer = 0;
	timer2 = 0;
	pausa = false;
	   
}

void Jogo::finalizar()
{
	
	uniFinalizar();
}

void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair
		  && telaAtual != tSair)
	{
		uniIniciarFrame();

		switch (telaAtual)
		{
			case tMenu: telaMenu();
				break;
			case tJogo: telaJogo();				
				break;
			case tConfig: telaConfig();
				break;
			case tCreditos: telaCreditos();
				break;
			case tInstrucoes: telaInstrucoes();
				break;
			case tGameOver: telaGameOver();
				break;
		}				

		uniTerminarFrame();
	}
}

void Jogo::telaMenu()
{
	
	
	if (gMusica.getNomeMusica() == "musicaJogo") {
		gMusica.parar();
	}

	if (!gMusica.estaTocando()) {
		gMusica.tocar("musicaMenu", true);		
	}

	fundoMenu.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2); 

	botoes[bJogar].atualizar();
	botoes[bJogar].desenhar();


	if (botoes[bJogar].estaClicado())
		telaAtual = tConfig;

	botoes[bInstrucoes].atualizar();
	botoes[bInstrucoes].desenhar();

	if (botoes[bInstrucoes].estaClicado())
		telaAtual = tInstrucoes;

	botoes[bCreditos].atualizar();
	botoes[bCreditos].desenhar();

	if (botoes[bCreditos].estaClicado())
		telaAtual = tCreditos;

	botoes[bSair].atualizar();
	botoes[bSair].desenhar();

	if (botoes[bSair].estaClicado())
		telaAtual = tSair;
	
}

void Jogo::telaJogo()
{	
	timer++;
	timer2++;

	fundo.desenhar(pfundo1.x, pfundo1.y); //fundo 1
	fundo2.desenhar(pfundo2.x, pfundo2.y); //fundo 2	
	
	/*if (timer2 > 60 && personagem.getVida() > 0)
	{*/
		for (int b = 0; b < 4; b++) {
			birds[b].desenhar();
		}

		for (int c = 0; c < 8; c++)
			candys[c].desenhar();

		for (int p = 0; p < 2; p++)
			predios[p].desenhar();	

		star.desenhar();
	//}


	personagem.desenhar();
	

	if (twoPlayers)
	{
		personagem2.desenhar();
	}



	if (pausa)
		fundoPausa.desenhar(640, 360);

	if (gTeclado.pressionou[TECLA_P])
	{
		pausa = !pausa;
		if (gMusica.estaTocando())
			gMusica.pausar();
		else
			gMusica.continuar();
	}


	if (!pausa)
	{

		personagem.setPontuacao();
		personagem2.setPontuacao();

		if (timer > 1000 && velocidadeCenario < 2)
		{
			velocidadeCenario+=0.5;			
			timer = 0;
		}	

		
		tPontuacao.setString("Pontuação: " +
			to_string(personagem.getPontuacao()));
		tPontuacao.desenhar(20, 30);

		if (twoPlayers)
		{	
			tPontuacao.setString("Pontuação 2: " +
			to_string(personagem2.getPontuacao()));
			tPontuacao.desenhar(300, 30);			
		}


		if (gMusica.getNomeMusica() == "musicaMenu") {
			gMusica.parar();
		}

		if (!gMusica.estaTocando()) {
			gMusica.tocar("musicaJogo", true);
		}		

		pfundo1.x -= velocidadeCenario;
		if (pfundo1.x <= -gJanela.getLargura() / 2)
			pfundo1.x = gJanela.getLargura() * 1.5;

		pfundo2.x -= velocidadeCenario;
		if (pfundo2.x <= -gJanela.getLargura() / 2)
			pfundo2.x = gJanela.getLargura() * 1.5;


		if (timer2 > 60 && personagem.getVida() > 0) 
		{

			for (int n = 0; n < 4; n++)
			{
				birds[n].atualizar(velocidadeCenario);
				if (uniTestarColisaoCirculoComSprite(personagem.getX(), personagem.getY(), 23,
					birds[n].getSprite(), birds[n].getX(), birds[n].getY(), 0))
				{
					personagem.levarDano(100);
				}
			}


			for (int c = 0; c < 8; c++) {
				candys[c].atualizar(velocidadeCenario);

				if (uniTestarColisao(personagem.getSprite(),
					personagem.getX(),
					personagem.getY(),
					0,
					candys[c].getSprite(),
					candys[c].getX(),
					candys[c].getY(),
					0))
				{
					personagem.pegar(10, tCandy);
					candys[c].setposicaox(-100);
					candys[c].tocarsom(tCandy);
				}
			}

			for (int p = 0; p < 2; p++) {

				predios[p].atualizar(velocidadeCenario);

				if (uniTestarColisaoCirculoComSprite(personagem.getX(), personagem.getY(), 23,
					predios[p].getSprite(), predios[p].getX(), predios[p].getY(), 0))
				{
					personagem.levarDano(100);
				}
			}

			star.atualizar(velocidadeCenario);
			if (uniTestarColisaoCirculoComSprite(personagem.getX(), personagem.getY(), 23,
				star.getSprite(),
				star.getX(),
				star.getY(),
				0))
			{
				personagem.pegar(10, tStar);
				star.setposicaox(-100);
				star.tocarsom(tStar);
			}
		}

		if (twoPlayers)
		{
			for (int n = 0; n < 4; n++)
			{
				if (uniTestarColisaoCirculoComSprite(personagem2.getX(), personagem2.getY(), 23,
					birds[n].getSprite(), birds[n].getX(), birds[n].getY(), 0))
				{
					personagem2.levarDano(100);
				}
			}

			for (int c = 0; c < 8; c++) {			

				if (uniTestarColisaoCirculoComSprite(personagem2.getX(), personagem2.getY(), 23,
					candys[c].getSprite(),
					candys[c].getX(),
					candys[c].getY(),
					0))
				{
					personagem2.pegar(10, tCandy);
					candys[c].setposicaox(-100);
					candys[c].tocarsom(tCandy);
				}
			}

			for (int p = 0; p < 2; p++) {		

				if (uniTestarColisaoCirculoComSprite(personagem2.getX(), personagem2.getY(), 23,
					predios[p].getSprite(),predios[p].getX(), predios[p].getY(),1))
				{
					personagem2.levarDano(100);
				}

			}
			
			if (uniTestarColisaoCirculoComSprite(personagem2.getX(), personagem2.getY(), 23,
				star.getSprite(),
				star.getX(),
				star.getY(),
				0))
			{
				personagem2.pegar(10, tStar);
				star.setposicaox(-100);
				star.tocarsom(tStar);
			}

			if (personagem2.getVida() <= 0) {
				telaAtual = tGameOver;				
			}

			if (!pausa)
				personagem2.atualizar();
		}

		if (!pausa)
			personagem.atualizar(Player1);

		if (personagem.getVida() <= 0 ) {
			telaAtual = tGameOver;					
		}
	}
}

void Jogo::telaCreditos()
{
	fundoCreditos.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2); 

	botoes[bOk].atualizar();
	botoes[bOk].desenhar();

	if (botoes[bOk].estaClicado())
		telaAtual = tMenu;
}

void Jogo::telaInstrucoes()
{
	fundoInstrucoes.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);	
	botoes[bOk].atualizar();
	botoes[bOk].desenhar();

	if (botoes[bOk].estaClicado())
		telaAtual = tMenu;
}

void Jogo::telaConfig()
{
	telaAtual = tConfig;
	fundoMenu.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	botoes[b1Jogador].atualizar();
	botoes[b1Jogador].desenhar();

	botoes[b2Jogadores].atualizar();
	botoes[b2Jogadores].desenhar();

	if (botoes[b1Jogador].estaClicado())
		telaAtual = tJogo;
	else if(botoes[b2Jogadores].estaClicado())
	{
		twoPlayers = true;
		personagem.twoPlayers(true);
		personagem2.twoPlayers(true);
		telaAtual = tJogo;
	}
	
	if (gTeclado.pressionou[TECLA_T])
	{
		if (twoPlayers == false) {
			twoPlayers = true;
			personagem.twoPlayers(true);
			personagem2.twoPlayers(true);
		}
		else
		{
			twoPlayers = false;
			personagem2.twoPlayers(false);
			personagem.twoPlayers(false);
		}
	}
}

void Jogo::telaGameOver()
{
	
	fundo.desenhar(pfundo1.x, pfundo1.y); //fundo 1
	fundo2.desenhar(pfundo2.x, pfundo2.y); //fundo 2	

	
	//fundoGameOver.setCorAlpha(300);
	for (int b = 0; b < 4; b++) {
		birds[b].desenhar();
	}

	for (int c = 0; c < 8; c++)
		candys[c].desenhar();

	for (int p = 0; p < 2; p++)
		predios[p].desenhar();

	personagem.desenhar();

	if (twoPlayers)
	{
		personagem2.desenhar();
	}

	star.desenhar();

	fundoGameOver.desenhar(649, 360);
	
	tPontuacao.setString("Player 1: Pontuação: " +
		to_string(personagem.getPontuacao()));
	tPontuacao.desenhar(350, 50);
	
	if (twoPlayers)
	{
		tPontuacao.setString("Player 2: Pontuação: " +
			to_string(personagem2.getPontuacao()));
		tPontuacao.desenhar(750, 50);
	}

	
	gMusica.pausar();	

	if (gTeclado.pressionou[TECLA_ESPACO])
	{
		reiniciarGame();
		telaAtual = tJogo;
	}
	else if (gTeclado.pressionou[TECLA_M]) 
	{
		reiniciarGame();
		telaAtual = tMenu;
		twoPlayers = false;
		personagem2.twoPlayers(false);
		personagem.twoPlayers(false);
	}
}

void Jogo::reiniciarGame()
{

	pfundo1.x = 0;
	pfundo1.y = gJanela.getAltura() / 2;

	pfundo2.x = gJanela.getLargura();
	pfundo2.y = gJanela.getAltura() / 2;

	personagem.inicializar(200,600);
	personagem2.inicializar(200, 700);
	
	//star.inicializar(tStar);

	star.setposicaox(-100);
	star.zeraVelocidade();
	for (int b = 0; b < 4; b++)
	{
		birds[b].setposicaox(-120);
		birds[b].zeraVelocidade();
	}

	for (int c = 0; c < 8; c++)
	{
		candys[c].setposicaox(-120);
		candys[c].zeraVelocidade();
	}

	for (int p = 0; p < 2; p++)
	{
		predios[p].setposicaox(-150);
		predios[p].zeraVelocidade();
	}	

	timer2 = 0;
	velocidadeCenario = 2;
	pausa = false;	
}

