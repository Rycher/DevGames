#include "Personagem.h"


Personagem::Personagem()
{
	
}


Personagem::~Personagem()
{
}

void Personagem::inicializar(int x, int y)
{
	if (!gRecursos.carregouSpriteSheet("personagem")) 
	{
		gRecursos.carregarSpriteSheet("personagem", "./assets/sprites/player/SantaWalk.png", 1, 24);
		sprite.setSpriteSheet("personagem");
		cor = sprite.getCor();
	}

	this->x = x;
	this->y = y;
	direcao = baixo;
	velocidade = 3;
	pontuacao = 0;
	vida = 100;
	imortal = false;
	sprite.setCorAlpha(250);
	sprite.setEscala(1.5, 1.5);
}

void Personagem::atualizar(Player Player)
{
	
	direcao = parado;

	
	if (gTeclado.segurando[TECLA_D] || gJoysticks.player1.segurando[TECLA_DIR])
	{
		if (x < 1250)
		{
			if (twoPlayer) {
				x += velocidade;
			}
			//
		}
	}
	if (gTeclado.segurando[TECLA_A] || gJoysticks.player1.segurando[TECLA_ESQ])
	{
		if (x >= 30)
		{
			if (twoPlayer) {
				x -= velocidade;
			}
			// 
		}
	}

	if (gTeclado.segurando[TECLA_W] || gJoysticks.player1.segurando[TECLA_CIMA])
	{
		if (y > 60)
		{
			y -= 5;
		}		
	}	
	
	
	if (y < 650) {
		y += 3;
	}		
	sprite.setVelocidadeAnimacao(10);		
	sprite.avancarAnimacao();		

	if (imortal) 
	{
		timer++;
	}
	else
	{
		timer = 0;
	}
				
	if (timer > 600)
	{
		sprite.setCorAlpha(250);
		imortal = false;
	}

		
}

void Personagem::desenhar()
{	
		sprite.desenhar(x, y);	
}

void Personagem::pegar(int valor,TipoObjeto item)
{
	if  (item == tCandy)
	{
		pontuacao += valor;
	}
	else if (item == tStar)
	{
		sprite.setCorAlpha(100);
		imortal = true;
	}
	
}

void Personagem::levarDano(int valor)
{
	if (imortal == false) 
	{
		vida -= valor;
	}
	
}

void Personagem::setposicaox(int x)
{
	this->x += x;
	
}

void Personagem::setCorPlayer(bool twoplayer)
{
	if (twoplayer) {
		sprite.setCor(250, 1, 1);
	}	
	else
	{
		sprite.setCor(cor);
	}
}

void Personagem::setPontuacao()
{
	pontuacao+= 0.16;
}

void Personagem::twoPlayers(bool twoPlayers)
{
	twoPlayer = twoPlayers;
} 




