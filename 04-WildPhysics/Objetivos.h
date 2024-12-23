#pragma once
#include "Librerias.h"
#include "MiraJugador.h"
using namespace sf;

class Objetivos 
{
private:
	bool conVida;
	bool estaVisible;
	Texture tex_objetivo;
	Sprite spr_objetivo;
	
public:
	Vector2f posicion;
	Vector2f velocidad;
	int pos;
	float deltaTime;

	Objetivos();
	Vector2f movimiento();
	FloatRect lugar();
	void Dibujar(RenderWindow* ventana);
	void Actualizar(RenderWindow* ventana, Vector2f posicion, float dt);
	void Aparecer(RenderWindow* ventana);
	bool estaVivo();
	void Revive();
	bool Visible() const;
	bool estaActivo() const;
	void visibilidad(bool estado);
	bool EnLaMira(float x, float y, FloatRect bounds);
	void muerte();
};