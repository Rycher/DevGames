#include "Objeto.h"



Objeto::Objeto()
{
}


Objeto::~Objeto()
{
	exit(0);
}

void Objeto::inicializar(TipoObjeto t)
{
	timer2 = 0;
	velocidadePass = 0.0;
	tipo = t;
	if (!gRecursos.carregouSpriteSheet("predio"))
		gRecursos.carregarSpriteSheet("predio", "./assets/sprites/objetos/predio.png");
	
	if (!gRecursos.carregouSpriteSheet("passaro"))
		gRecursos.carregarSpriteSheet("passaro", "./assets/sprites/objetos/bird.png",1,4);
		sprite.setSpriteSheet("passaro");

	if (!gRecursos.carregouSpriteSheet("candy"))
			gRecursos.carregarSpriteSheet("candy", "./assets/sprites/objetos/candy.png");
			sprite.setSpriteSheet("candy");

	if (!gRecursos.carregouSpriteSheet("star"))
			gRecursos.carregarSpriteSheet("star", "./assets/sprites/objetos/star.png",1,7);
			sprite.setSpriteSheet("star");


	if (!gRecursos.carregouAudio("somCandy"))
			gRecursos.carregarAudio("somCandy", "assets/sons/candy.mp3");			

	if (!gRecursos.carregouAudio("somSnow"))
		gRecursos.carregarAudio("somSnow", "assets/sons/Snow.mp3");

	if (!gRecursos.carregouAudio("somPowerUp"))
		gRecursos.carregarAudio("somPowerUp", "assets/sons/powerup.mp3");
			

	int sorteio;

	switch (tipo)
	{
		case tBird: 	
					sprite.setSpriteSheet("passaro");
					sprite.setVelocidadeAnimacao(2);
					x = gJanela.getLargura() + sprite.getLargura() + rand() % 300;
					y = sprite.getAltura() + rand() % 600;
					velocidade = 2;
					break;
		case tPredio: 
					sprite.setSpriteSheet("predio");
					x = gJanela.getLargura() + 120;
					y = 880 - sprite.getAltura() / 2;
					velocidade = 2;
					break;
		case tCandy:					
					sprite.setSpriteSheet("candy");			
					x = gJanela.getLargura() + sprite.getLargura() + rand() % 300;
					y = sprite.getAltura() + rand() % 700 + 100;
					velocidade = 2;			
					break;
		case tStar:					
					sprite.setSpriteSheet("star");	
					sprite.setVelocidadeAnimacao(1);
					x = gJanela.getLargura() + sprite.getLargura() + rand() % 300;
					y = sprite.getAltura() + rand() % 600;
					velocidade = 2;			
					break;
	}
}

void Objeto::atualizar(float vCenario)
{	
	
	timer++;
	timer2++;
	x -= velocidade + vCenario;

	if (timer2 > 250)
	{
		velocidadePass += 0.15;
		timer2 = 0;
	}


	if (x < -sprite.getLargura())
	{
		int sorteio;

		switch (tipo)
		{
		case tBird:					
			sprite.setSpriteSheet("passaro");
			sorteio = rand() % 3;
			if (sorteio == 0) {
				y = rand() % 300 + 50;
			}
			else if (sorteio == 1) {
				y = rand() % 600;
			}
			else {
				y = rand() % 400 + 100;
			}
			sprite.setVelocidadeAnimacao(2);
			x = gJanela.getLargura() + sprite.getLargura() + rand() % 300;
			velocidade = vCenario + velocidadePass;
			break;

		case tPredio:			
			sprite.setSpriteSheet("predio");
			x = gJanela.getLargura() + rand() % 1000 + 500;
			y = 880 - sprite.getAltura() / 2;
			velocidade = vCenario + velocidadePass;
			timer = 0;
			break;			
		case tCandy:
			sprite.setSpriteSheet("candy");
			sorteio = rand() % 3;
			if (sorteio == 0) {
				y = rand() % 400 + 100;
			}
			else if (sorteio == 1) {
				y = rand() % 600 + 100;
			}
			else {
				y = rand() % 300 + 100;
			}			
			x = gJanela.getLargura() + sprite.getLargura() + rand() % 300;			
			velocidade = vCenario + velocidadePass;
			break;
		case tStar:
			sprite.setSpriteSheet("star");
			sprite.setVelocidadeAnimacao(3);			
			x = gJanela.getLargura() + sprite.getLargura() + 3000;
			y = sprite.getAltura() + rand() % 600;
			velocidade = vCenario + velocidadePass;
			break;	
		}	
	}
	sprite.setVelocidadeAnimacao(3);
	sprite.avancarAnimacao();	
}

void Objeto::desenhar()
{
	sprite.desenhar(x, y);	
}

void Objeto::setposicaox(int posicao)
{
	x = posicao;
}

void Objeto::tocarsom(TipoObjeto t)
{
	
	switch (t)
	{
	case tBird:
		som.setAudio("somSnow");
		som.tocar();		
		break;
	case tPredio:
		som.setAudio("somSnow");
		som.tocar();
		break;
	case tCandy:
		som.setAudio("somCandy");
		som.tocar();
		break;
	case tStar:
		som.setAudio("somPowerUp");
		som.tocar();		
		break;
	default:
		break;
	}	
}

void Objeto::zeraVelocidade()
{
	velocidadePass = 0.0;
}

