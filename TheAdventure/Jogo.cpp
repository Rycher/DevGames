#include "Jogo.h"


Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{	
	uniInicializar(900  , 720  , true);
	//telaAtual = tMenu;	
	Mapx = 16;	
	minerios = 0;
	golds = 0;
	mapaAtual = 1;
	pPlayerPos.x = 0;
	pPlayerPos.y = 0;

	savesVars[0] = 100;
	savesVars[1] = 100;
	savesVars[2] = 100;
	savesVars[3] = 100;
	savesVars[4] = 100;
	savesVars[5] = 100;	
	savesVars[6] = 1;
	savesVars[7] = 1;
	savesVars[8] = 0;
	savesVars[9] = 0;
	

	vMinerio = new Minerio[6];

	vMinerio[0].inicializar(526, 430);
	vMinerio[1].inicializar(526, 400);
	vMinerio[2].inicializar(526, 370);
	vMinerio[3].inicializar(526, 340);
	vMinerio[4].inicializar(526, 310);
	vMinerio[5].inicializar(526, 280);

	Player.inicializar(400, 600);
	
	//Carregar Save
	arqSaveIf.open("save.txt");
	if (arqSaveIf.is_open())
	{		
		for (int i = 0; i < 11; i++) {
			arqSaveIf >> savesVars[i];		
		}
		
		for (int i = 0; i < 6; i++) {
			vMinerio[i].setVida(savesVars[i]);
		}
		
		for (int i = 6; i < 8; i++) {
			Player.setUp(savesVars[i],i - 5);
		}

		minerios = savesVars[8];
		golds = savesVars[9];
		
		pBackPack = Player.getUp(1);
		pCollectOre = Player.getUp(2);		
	}
	arqSaveIf.close();
		//Interface
		//-------------------------------------------
		
		if (!gRecursos.carregouSpriteSheet("telaFim"))
			gRecursos.carregarSpriteSheet("telaFim", "assets/imagens/menus/telaFim.jpg");
		fundoFim.setSpriteSheet("telaFim");
		fundoFim.setEscala(1, 1);

		
		if (!gRecursos.carregouSpriteSheet("iconGold"))
			gRecursos.carregarSpriteSheet("iconGold", "assets/imagens/iconGold.png");
		iconGold.setSpriteSheet("iconGold");
		iconGold.setEscala(0.03, 0.03);

		if (!gRecursos.carregouSpriteSheet("iconOre"))
			gRecursos.carregarSpriteSheet("iconOre", "assets/imagens/iconOre.png");
		iconOre.setSpriteSheet("iconOre");
		iconOre.setEscala(1.2, 1.2);

		if (!gRecursos.carregouSpriteSheet("fundoMenu"))
			gRecursos.carregarSpriteSheet("fundoMenu", "assets/imagens/menus/Tela_Menu2.jpg");
		fundoMenu.setSpriteSheet("fundoMenu");
		fundoMenu.setEscala(1, 1);

		if (!gRecursos.carregouSpriteSheet("fundoMenuBtn1"))
			gRecursos.carregarSpriteSheet("fundoMenuBtn1", "assets/imagens/menus/MouseBtn1.jpg");
		btGame1.setSpriteSheet("fundoMenuBtn1");
		btGame1.setEscala(1, 1);

		if (!gRecursos.carregouSpriteSheet("fundoMenuBtn2"))
			gRecursos.carregarSpriteSheet("fundoMenuBtn2", "assets/imagens/menus/MouseBtn2.jpg");
		btTutorial1.setSpriteSheet("fundoMenuBtn2");
		btTutorial1.setEscala(1, 1);

		if (!gRecursos.carregouSpriteSheet("fundoMenuBtn3"))
			gRecursos.carregarSpriteSheet("fundoMenuBtn3", "assets/imagens/menus/MouseBtn3.jpg");
		btCred1.setSpriteSheet("fundoMenuBtn3");
		btCred1.setEscala(1, 1);		

		if (!gRecursos.carregouSpriteSheet("fundoMenuBtn4"))
			gRecursos.carregarSpriteSheet("fundoMenuBtn4", "assets/imagens/menus/MouseBtn4.jpg");
		btExit1.setSpriteSheet("fundoMenuBtn4");
		btExit1.setEscala(1, 1);

		if (!gRecursos.carregouSpriteSheet("Credits"))
			gRecursos.carregarSpriteSheet("Credits", "assets/imagens/menus/Credits.jpg");
		fundoCredits.setSpriteSheet("Credits");
		fundoCredits.setEscala(1, 1);

		if (!gRecursos.carregouSpriteSheet("CreditsHover"))
			gRecursos.carregarSpriteSheet("CreditsHover", "assets/imagens/menus/CreditsHover.jpg");
		btCred2.setSpriteSheet("CreditsHover");
		btCred2.setEscala(1, 1);

		if (!gRecursos.carregouSpriteSheet("controls_back"))
			gRecursos.carregarSpriteSheet("controls_back", "assets/imagens/menus/controls_back.jpg");
		fundoTutorial.setSpriteSheet("controls_back");
		fundoTutorial.setEscala(1, 1);

		if (!gRecursos.carregouSpriteSheet("controls_back2"))
			gRecursos.carregarSpriteSheet("controls_back2", "assets/imagens/menus/controls_back2.jpg");
		btTutorial2.setSpriteSheet("controls_back2");
		btTutorial2.setEscala(1, 1);

		telaAtual = tMenu;

		if (!gRecursos.carregouMusica("musicaMenu"))
			gRecursos.carregarMusica("musicaMenu", "assets/Musicas/Menu.mp3");

		if (!gRecursos.carregouMusica("musicaJogo"))
			gRecursos.carregarMusica("musicaJogo", "assets/Musicas/Game.mp3");

		if (!gRecursos.carregouMusica("mining"))
			gRecursos.carregarMusica("mining", "assets/Musicas/mining.wav");		
		
	

	if (!gRecursos.carregouSpriteSheet("Upgrade"))
		gRecursos.carregarSpriteSheet("Upgrade", "./assets/imagens/scroll.png");
	spriteMenu.setSpriteSheet("Upgrade");

	mudarMapa = false;
	arqConfig.open("mapa1.txt");
	if (arqConfig.is_open())
	{
		arqConfig >> numTiles;
		for (int t = 0; t < numTiles; t++)
		{
			arqConfig >> nomesTile[t] >> caminho >> numFrames;
			if (!gRecursos.carregouSpriteSheet(nomesTile[t]))
				if (nomesTile[t] == "chao") {
					gRecursos.carregarSpriteSheet(nomesTile[t], caminho, 1, numFrames);
				}
				else {
					gRecursos.carregarSpriteSheet(nomesTile[t], caminho, Mapx, numFrames);
				}					

				spritesTile[t].setSpriteSheet(nomesTile[t]);	
				if (nomesTile[t] == "chao") {
					spritesTile[t].setEscala(4, 4);
				}
				else {
					spritesTile[t].setEscala(2, 2);
				}				
		}
		arqConfig >> numCamadas >> numColunas >> numLinhas;	

		Tile = new Tiled**[numCamadas];
		for (int c = 0; c < numCamadas; c++) {
			Tile[c] = new Tiled *[numColunas];
			for (int x = 0; x < numColunas; x++) {
				Tile[c][x] = new Tiled[numLinhas];
			}
		}
			
		deslocamento.x = 0;
		deslocamento.y = 0;
		for (int c = 0; c < numCamadas; c++)
			for (int y = 0; y < numLinhas; y++)
				for (int x = 0; x < numColunas; x++)
				{
					if (c != 3) {						
						arqConfig >> Tile[c][x][y].ID;
						if (c == 0) {
							Tile[c][x][y].x = Tile[c][x][y].ID - (round(Tile[c][x][y].ID / Mapx) * Mapx);
						}
						else if(c != 0) {
							Tile[c][x][y].x = Tile[c][x][y].ID - (round(Tile[c][x][y].ID / Mapx) * Mapx) - 1;
						}					
						Tile[c][x][y].y = round(Tile[c][x][y].ID / Mapx); 				
						mapas[c][x][y] = 1; 
					}											
					else
						arqConfig >> mapas[c][x][y];
				}
		arqConfig.close();
	}
	else
	{
		//uniFinalizar();
		//exit(0);
	}	
	
}

void Jogo::finalizar()
{
	//	O resto da finalização vem aqui (provavelmente  em ordem inversa a inicialização)!
	//	...

	arqSaveOf.open("save.txt");
	if (arqSaveOf.is_open()) {
				
		for (int i = 0; i < 6; i++) {
			arqSaveOf << vMinerio[i].getVida() << " ";
		}

		for (int i = 1; i < 3; i++) {
			arqSaveOf << Player.getUp(i) << " ";
		}		

		arqSaveOf << minerios << " ";
		arqSaveOf << golds << " ";
		arqSaveOf.close();
}
	
	for (int x = 0; x < numColunas; x++)
	{
		for (int y = 0; y < numLinhas; y++)
			delete[] Tile[x][y]; //camadas
			delete[] Tile[x]; //linhas
	}
	delete[] Tile; //colunas


	uniFinalizar();
}

void Jogo::executar()
{
	while (!gTeclado.soltou[TECLA_ESC] && !gEventos.sair
		&& telaAtual != tSair)
	{
		uniIniciarFrame();

		switch (telaAtual)
		{
		case tMenu: telaMenu();
			break;
		case tJogo: telaJogo();
			break;		
		case tCreditos: telaCreditos();
			break;
		case tInstrucoes: telaInstrucoes();
			break;	
		case tFim: telaFim();
			break;
		}

		uniTerminarFrame();
	}

}

void Jogo::telaMenu()
{
	gMouse.mostrarCursor();

	if (gMusica.getNomeMusica() == "musicaJogo") {
		gMusica.parar();
	}	

	if (!gMusica.estaTocando()) {
		gMusica.tocar("musicaMenu", true);
	}

	/*gDebug.depurar("Mouse x:", gMouse.x);
	gDebug.depurar("Mouse y:", gMouse.y);*/

	if (gMouse.x >= 540 && gMouse.x <= 659 && gMouse.y <= 572 && gMouse.y >= 520) {
		if (gMouse.pressionou[BOTAO_MOUSE_ESQ])
		{			
			telaAtual = tCreditos;
		}
		else
		{
			btCred1.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
		}
	}
	else if (gMouse.x >= 585 && gMouse.x <= 744 && gMouse.y <= 395 && gMouse.y >= 337) {
		if (gMouse.pressionou[BOTAO_MOUSE_ESQ])
		{
			telaAtual = tJogo;
		}
		else
		{
			btGame1.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
		}
	}
	else if (gMouse.x >= 564 && gMouse.x <= 700 && gMouse.y <= 475 && gMouse.y >= 420) {
		if (gMouse.pressionou[BOTAO_MOUSE_ESQ])
		{
			telaAtual = tInstrucoes;
		}
		else
		{
			btTutorial1.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
		}
	}
	else if (gMouse.x >= 514 && gMouse.x <= 670 && gMouse.y <= 652 && gMouse.y >= 610) {
		if (gMouse.pressionou[BOTAO_MOUSE_ESQ])
		{
			telaAtual = tSair;
		}
		else
		{
			btExit1.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
		}
	}
	else {
		fundoMenu.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	}
	
}

void Jogo::telaJogo()
{	
	pSpeed = 2;
	pBackPack = Player.getUp(1);
	pCollectOre = Player.getUp(2);
	Player.setVelocidade(2);

	if (gMusica.getNomeMusica() == "musicaMenu") {
		gMusica.parar();
	}

	if (!gMusica.estaTocando()) {
		gMusica.tocar("musicaJogo", true);
	}

	velocidade = 4;
	gMouse.esconderCursor();
	while (!gTeclado.soltou[TECLA_ESC] && !gEventos.sair && telaAtual == tJogo)
	{
		uniIniciarFrame();

		for (int c = 0; c < numCamadas; c++)
			for (int y = 0; y < numLinhas; y++)
				for (int x = 0; x < numColunas; x++)
					if (mapas[c][x][y] >= 0)
					{
						if (c != 3)
						{
							if (spritesTile[mapas[c][x][y]].getFrame() != Tile[c][x][y].x)
								spritesTile[mapas[c][x][y]].setFrame(Tile[c][x][y].x);
							if (spritesTile[mapas[c][x][y]].getAnimacao() != Tile[c][x][y].y)
								spritesTile[mapas[c][x][y]].setAnimacao(Tile[c][x][y].y);
						}
						spritesTile[mapas[c][x][y]].desenhar(deslocamento.x + 16 + 32 * x, deslocamento.y + 16 + 32 * y);
					}

		pTile.x = Player.getX() / 32;
		pTile.y = Player.getY() / 32;

		pTileMapa.x = pTile.x - deslocamento.x / 32;
		pTileMapa.y = pTile.y - deslocamento.y / 32;
			

		if (Tile[2][pTileMapa.x - 1][pTileMapa.y].ID == 234) {
			spriteMenu.desenhar(350, 350, 0);
			if (gTeclado.pressionou[TECLA_1])
			{
				if (golds >= 500) {
					Player.setUp(pBackPack + 1, 1);
					pBackPack = Player.getUp(1);
					golds -= 500;
				}
			}

			if (gTeclado.pressionou[TECLA_2])
			{
				if (golds >= 600){
					Player.setUp(pCollectOre + 1, 2);
					pCollectOre = Player.getUp(2);
					golds -= 600;
				}
			}
		}

		if (Tile[2][pTileMapa.x][pTileMapa.y].ID == 162) {
			telaAtual = tFim;
		}


			   
		Player.desenhar();
		pPlayerPos.x = Player.getX();
		pPlayerPos.y = Player.getY();


		if (Tile[2][pTileMapa.x][pTileMapa.y - 1].ID == 150) {
			gGraficos.desenharTexto("Press (E) to go to the next map", Player.getX(), Player.getY() - 100);
			if (gTeclado.pressionou[TECLA_E]) {
				setMapa(mapaAtual + 1);
			}
		}

		if (Tile[2][pTileMapa.x + 1][pTileMapa.y].ID == 161) {
			gGraficos.desenharTexto("Please help my friend he's trapped in the mines", Player.getX() + 20, Player.getY() - 20);			
		}

		if (Tile[2][pTileMapa.x][pTileMapa.y + 1].ID == 182) {
			gGraficos.desenharTexto("Press (E) to go back", Player.getX(), Player.getY() + 10);
			if (gTeclado.pressionou[TECLA_E]) {
				setMapa(mapaAtual - 1);
			}
		}

		if (Tile[2][pTileMapa.x][pTileMapa.y - 1].ID == 232) {
			gGraficos.desenharTexto("Press (E) to sell your ores", Player.getX(), Player.getY() - 20);
			if (gTeclado.pressionou[TECLA_E]) {
				golds += minerios * 5;
				minerios = 0;
			}
		}

		if (gTeclado.segurando[TECLA_D] && Tile[0][pTileMapa.x + 1][pTileMapa.y].ID == 63) {
			Player.atualizar();
		}
		else if (gTeclado.segurando[TECLA_A] && Tile[0][pTileMapa.x - 1][pTileMapa.y].ID == 63) {
			Player.atualizar();
		}
		else if (gTeclado.segurando[TECLA_S] && Tile[0][pTileMapa.x][pTileMapa.y + 1].ID == 63) {
			Player.atualizar();
		}
		else if (gTeclado.segurando[TECLA_W] && Tile[0][pTileMapa.x][pTileMapa.y - 1].ID == 63) {
			Player.atualizar();
		}		

		


		if (mapaAtual == 2) {
			if (vMinerio[0].getVida() > 0){
				vMinerio[0].desenhar();
				vMinerio[0].atualizar();
			}
			if (vMinerio[1].getVida() > 0) {
				vMinerio[1].desenhar();
				vMinerio[1].atualizar();
			}
			if (vMinerio[2].getVida() > 0) {
				vMinerio[2].desenhar();
				vMinerio[2].atualizar();
			}
			if (vMinerio[3].getVida() > 0) {
				vMinerio[3].desenhar();
				vMinerio[3].atualizar();
			}
			if (vMinerio[4].getVida() > 0) {
				vMinerio[4].desenhar();
				vMinerio[4].atualizar();
			}
			if (vMinerio[5].getVida() > 0) {
				vMinerio[5].desenhar();
				vMinerio[5].atualizar();
			}
				

			//Minerio 1
			if (Player.getY() - 40 == vMinerio[0].getY() && vMinerio[0].getVida() > 0) {
				gGraficos.desenharTexto("Press (X) to mine", Player.getX(), Player.getY() - 35);

				if (minerios == 25 * Player.getUp(1)) {
					gGraficos.desenharTexto("Full bag! you can't mine anymore", Player.getX(), Player.getY());
				}

				Player.setVelocidade(0);
				if (gTeclado.pressionou[TECLA_X]) {

					if (minerios < 25 * Player.getUp(1)) {
						vMinerio[0].retirarVida(3);						
						minerios += 5 * Player.getUp(2);
					}
				}

				if (gTeclado.pressionou[TECLA_S]) {
					Player.atualizar();
					Player.setVelocidade(pSpeed);
				}

				gGraficos.desenharTexto("Remaining ores: " + to_string(vMinerio[0].getVida()), Player.getX(), Player.getY() - 20);
			}
			//Minerio 2
			else if (Player.getY() - 40 == vMinerio[1].getY() && vMinerio[1].getVida() > 0) {
				gGraficos.desenharTexto("Press (X) to mine", Player.getX(), Player.getY() - 30);

				if (minerios == 25 * Player.getUp(1)) {
					gGraficos.desenharTexto("Full bag! you can't mine anymore", Player.getX(), Player.getY());
				}

				Player.setVelocidade(0);
				if (gTeclado.pressionou[TECLA_X]) {

					if (minerios < 25 * Player.getUp(1)) {
						vMinerio[1].retirarVida(3);
						minerios += 5 * Player.getUp(2);
					}
				}

				if (gTeclado.pressionou[TECLA_S]) {
					Player.atualizar();
					Player.setVelocidade(pSpeed);
				}

				gGraficos.desenharTexto("Remaining ores: " + to_string(vMinerio[1].getVida()), Player.getX(), Player.getY() - 20);
			}

			//Minerio 3
			else if (Player.getY() - 40 == vMinerio[2].getY() && vMinerio[2].getVida() > 0) {
				gGraficos.desenharTexto("Press (X) to mine", Player.getX(), Player.getY() - 30);

				if (minerios == 25 * Player.getUp(1)) {
					gGraficos.desenharTexto("Full bag! you can't mine anymore", Player.getX(), Player.getY());
				}

				Player.setVelocidade(0);
				if (gTeclado.pressionou[TECLA_X]) {

					if (minerios < 25 * Player.getUp(1)) {
						vMinerio[2].retirarVida(3);
						minerios += 5 * Player.getUp(2);
					}
				}

				if (gTeclado.pressionou[TECLA_S]) {
					Player.atualizar();
					Player.setVelocidade(pSpeed);
				}

				gGraficos.desenharTexto("Remaining ores: " + to_string(vMinerio[2].getVida()), Player.getX(), Player.getY() - 20);
			}
			//Minerio 4
			else if (Player.getY() - 40 == vMinerio[3].getY() && vMinerio[3].getVida() > 0) {
				gGraficos.desenharTexto("Press (X) to mine", Player.getX(), Player.getY() - 30);

				if (minerios == 25 * Player.getUp(1)) {
					gGraficos.desenharTexto("Full bag! you can't mine anymore", Player.getX(), Player.getY());
				}

				Player.setVelocidade(0);
				if (gTeclado.pressionou[TECLA_X]) {

					if (minerios < 25 * Player.getUp(1)) {
						vMinerio[3].retirarVida(3);						
						minerios += 5 * Player.getUp(2);
					}
				}

				if (gTeclado.pressionou[TECLA_S]) {
					Player.atualizar();
					Player.setVelocidade(pSpeed);
				}

				gGraficos.desenharTexto("Remaining ores: " + to_string(vMinerio[3].getVida()), Player.getX(), Player.getY() - 20);
			}
			//Minerio 5
			else if (Player.getY() - 40 == vMinerio[4].getY() && vMinerio[4].getVida() > 0) {
				gGraficos.desenharTexto("Press (X) to mine", Player.getX(), Player.getY() - 30);

				if (minerios == 25 * Player.getUp(1)) {
					gGraficos.desenharTexto("Full bag! you can't mine anymore", Player.getX(), Player.getY());
				}

				Player.setVelocidade(0);
				if (gTeclado.pressionou[TECLA_X]) {

					if (minerios < 25 * Player.getUp(1)) {
						vMinerio[4].retirarVida(3);
						minerios += 5 * Player.getUp(2);
					}
				}

				if (gTeclado.pressionou[TECLA_S]) {
					Player.atualizar();
					Player.setVelocidade(pSpeed);
				}

				gGraficos.desenharTexto("Remaining ores: " + to_string(vMinerio[4].getVida()), Player.getX(), Player.getY() - 20);
			}

			//Minerio 6
			else if (Player.getY() - 40 == vMinerio[5].getY() && vMinerio[5].getVida() > 0) {
				gGraficos.desenharTexto("Press (X) to mine", Player.getX(), Player.getY() - 30);

				if (minerios == 25 * Player.getUp(1)) {
					gGraficos.desenharTexto("Full bag! you can't mine anymore", Player.getX(), Player.getY());
				}

				Player.setVelocidade(0);
				if (gTeclado.pressionou[TECLA_X]) {

					if (minerios < 25 * Player.getUp(1)) {
						vMinerio[5].retirarVida(3);
						minerios += 5 * Player.getUp(2);
					}
				}

				if (gTeclado.pressionou[TECLA_S]) {
					Player.atualizar();
					Player.setVelocidade(pSpeed);
				}

				gGraficos.desenharTexto("Remaining ores: " + to_string(vMinerio[5].getVida()), Player.getX(), Player.getY() - 20);
			}
			else
			{
				if (Player.getVelocidade() == 0)
					Player.setVelocidade(pSpeed);
			}

		}

		

		


		iconGold.desenhar(100, 700, 0);
		iconOre.desenhar(30, 700, 0);				
		gGraficos.desenharTexto(to_string(golds), 135, 700);
		gGraficos.desenharTexto(to_string(minerios), 50, 700);

		uniTerminarFrame();
	}

}

void Jogo::telaCreditos()
{	
	if (gMouse.x >= 412 && gMouse.x <= 470 && gMouse.y <= 688 && gMouse.y >= 653) {
		if (gMouse.pressionou[BOTAO_MOUSE_ESQ])
		{
			telaAtual = tMenu;
		}
		else
		{
			btCred2.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
		}
	}
	else {
		fundoCredits.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	}
	
}

void Jogo::telaInstrucoes()
{	
	if (gMouse.x >= 412 && gMouse.x <= 470 && gMouse.y <= 688 && gMouse.y >= 653) {
		if (gMouse.pressionou[BOTAO_MOUSE_ESQ])
		{
			telaAtual = tMenu;
		}
		else
		{
			btTutorial2.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
		}
	}
	else {
		fundoTutorial.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	}
}

void Jogo::tPause()
{
}

void Jogo::telaFim()
{
	fundoFim.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	if (gTeclado.pressionou[TECLA_ESC])
	{
		uniFinalizar();
	}
}

void Jogo::setTileID(int PosC, int PosX, int PosY, int ID)
{
	Tile[PosC][PosX][PosY].ID = ID;
	Tile[PosC][PosX][PosY].x = Tile[PosC][PosX][PosY].ID - (round(Tile[PosC][PosX][PosY].ID / Mapx) * Mapx);
	Tile[PosC][PosX][PosY].y = round(Tile[PosC][PosX][PosY].ID / Mapx);
}

void Jogo::setMapa(int indiceMapa)
{
	mapaAtual = indiceMapa;
	mudarMapa = false;
	arqConfig.open("mapa" + to_string(indiceMapa) + ".txt");

	if (mapaAtual == 2) {
		
	}

	if (arqConfig.is_open())
	{
		arqConfig >> numTiles;
		for (int t = 0; t < numTiles; t++)
		{
			arqConfig >> nomesTile[t] >> caminho >> numFrames;
			if (!gRecursos.carregouSpriteSheet(nomesTile[t]))
				if (nomesTile[t] == "chao") {
					gRecursos.carregarSpriteSheet(nomesTile[t], caminho, 1, numFrames);
				}
				else {
					gRecursos.carregarSpriteSheet(nomesTile[t], caminho, Mapx, numFrames);
				}
			spritesTile[t].setSpriteSheet(nomesTile[t]);
			if (nomesTile[t] == "chao") {
				spritesTile[t].setEscala(4, 4);
			}
			else {
				spritesTile[t].setEscala(2, 2);
			}			
		}
		arqConfig >> numCamadas >> numColunas >> numLinhas;		
		deslocamento.x = 0;
		deslocamento.y = 0;
		for (int c = 0; c < numCamadas; c++)
			for (int y = 0; y < numLinhas; y++)
				for (int x = 0; x < numColunas; x++)
				{
					if (c != 3) {						
						arqConfig >> Tile[c][x][y].ID;
						if (c == 0)
						{
							Tile[c][x][y].x = Tile[c][x][y].ID - (round(Tile[c][x][y].ID / Mapx) * Mapx);												
						}
						else if (c != 0) {
							Tile[c][x][y].x = Tile[c][x][y].ID - (round(Tile[c][x][y].ID / Mapx) * Mapx) - 1;
						}						
						Tile[c][x][y].y = round(Tile[c][x][y].ID / Mapx); 				
						mapas[c][x][y] = 1;
					}
					else
						arqConfig >> mapas[c][x][y];				
				}
		if (mapaAtual == 2) {
			Player.setposicaox(200);
			Player.setposicaoy(500);			
		}
		else if (mapaAtual == 1) {
			Player.setposicaox(-200);
			Player.setposicaoy(-500);
		}
		arqConfig.close();
	}
	else
	{
		//uniFinalizar();
		//exit(0);
	}
}

