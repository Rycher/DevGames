#include "Personagem2.h"



Personagem2::Personagem2()
{

}


Personagem2::~Personagem2()
{
}

void Personagem2::inicializar(int x, int y)
{
	if (!gRecursos.carregouSpriteSheet("personagem2"))
		gRecursos.carregarSpriteSheet("personagem2", "./assets/sprites/player/SantaWalk_2.png", 1, 24);
	sprite.setSpriteSheet("personagem2");
	sprite.setEscala(1.5, 1.5);
	this->x = x;
	this->y = y;	
	velocidade = 3;
	pontuacao = 0;
	vida = 100;
	imortal = false;
	sprite.setCorAlpha(250);
}

void Personagem2::atualizar()
{
	

	if (gTeclado.segurando[TECLA_DIR]  || gJoysticks.player2.segurando[TECLA_DIR])
	{
		if (x < 1250)
		{
			if (twoPlayer) {
				x += velocidade;
			}			
		}		
	}
	if (gTeclado.segurando[TECLA_ESQ] || gJoysticks.player2.segurando[TECLA_ESQ])
	{
		if (x >= 30)
		{
			if (twoPlayer) {
				x -= velocidade;
			}
		}		
	}

	if (gTeclado.segurando[TECLA_CIMA] || gJoysticks.player2.segurando[TECLA_CIMA])
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

void Personagem2::desenhar()
{
	sprite.desenhar(x, y);
}

void Personagem2::pegar(int valor, TipoObjeto item)
{
	if (item == 2)
	{
		pontuacao += valor;
	}
	else if (item == 3)
	{
		sprite.setCorAlpha(100);
		imortal = true;
	}

}

void Personagem2::twoPlayers(bool twoPlayers)
{
	twoPlayer = twoPlayers;
}

void Personagem2::levarDano(int valor)
{
	if (imortal == false)
	{
		vida -= valor;
	}

}

void Personagem2::setposicaox(int x)
{
	this->x += x;
}

void Personagem2::setPontuacao()
{
	pontuacao += 0.16;
}




