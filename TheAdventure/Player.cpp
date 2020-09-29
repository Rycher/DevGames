#include "Player.h"


Player::Player()
{

}


Player::~Player()
{
}

void Player::inicializar(int x, int y)
{
	if (!gRecursos.carregouSpriteSheet("player"))
	{
		gRecursos.carregarSpriteSheet("player", "./assets/imagens/player.png");
		sprite.setSpriteSheet("player");		
		sprite.setEscala(2, 2);
	}

	this->x = x;
	this->y = y;
	direcao = baixo;
	Up1 = 1;
	velocidade = 2;	
	sprite.setCorAlpha(250);
	sprite.setEscala(2, 2);	
	Up2 = 1;	
}

void Player::atualizar()
{

	direcao = parado;	

	if (gTeclado.segurando[TECLA_D] || gJoysticks.player1.segurando[TECLA_DIR])
	{
		x += velocidade;		
	}
	if (gTeclado.segurando[TECLA_A] || gJoysticks.player1.segurando[TECLA_ESQ])
	{
		x -= velocidade;
	}

	if (gTeclado.segurando[TECLA_W] || gJoysticks.player1.segurando[TECLA_CIMA])
	{		
		y -= velocidade;
	}

	if (gTeclado.segurando[TECLA_S] || gJoysticks.player1.segurando[TECLA_BAIXO])
	{
		y += velocidade;
	}
	
	/*sprite.setVelocidadeAnimacao(10);
	sprite.avancarAnimacao();*/
}

void Player::desenhar()
{
	sprite.desenhar(x, y);
}

int Player::getX()
{
	return this->x;
}

int Player::getY()
{
	return this->y;
}



int Player::getVelocidade()
{
	return this->velocidade;
}

int Player::getUp(int up)
{
	switch (up)
	{
	case 1:
		return Up1;
		break;
	case 2:
		return Up2;
		break;	
	default:
		break;
	}
}

void Player::setUp(int val, int up)
{
	switch (up)
	{
	case 1:
		Up1 = val;
		break;
	case 2:
		Up2 = val;
		break;	
	default:
		break;
	}
}

void Player::setposicaox(int x)
{
	this->x += x;

}

void Player::setposicaoy(int y)
{
	this->y += y;
}

void Player::setposicaoxA(int x)
{
	this->x = x;
}

void Player::setposicaoyA(int y)
{
	this->y = y;
}

void Player::setVelocidade(int velocidade)
{
	this->velocidade = velocidade;
}





