#pragma once
#include "Librerias.h"
using namespace sf;

class MiraJugador
{
	Texture tex_mira;
	Sprite spr_mira;

public:
	MiraJugador();
	void Dibujar(RenderWindow* ventana);
	void Posicion(float x, float y);
	Vector2f posicionMira();
};
