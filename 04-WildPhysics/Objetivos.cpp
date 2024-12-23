#include "Objetivos.h"
#include "Librerias.h"

Objetivos::Objetivos()
{
	tex_objetivo.loadFromFile("Assets/objetivo.png");
	spr_objetivo.setTexture(tex_objetivo);
	spr_objetivo.setScale(0.2f, 0.2f);
	spr_objetivo.setPosition(1000, 1000);
	conVida = false;
	estaVisible = false;
	sf::Vector2f posicion(0.0f, 0.0f);
	sf::Vector2f velocidad(10.0f, 0.0f);
	float deltaTime = 0.1f / 60.0f;
	srand(time(NULL));
}

Vector2f Objetivos::movimiento()
{
	Vector2f bounds = spr_objetivo.getPosition();
	return bounds;
}

FloatRect Objetivos::lugar()
{
	FloatRect bounds = spr_objetivo.getGlobalBounds();
	return bounds;
}

void Objetivos::Dibujar(RenderWindow* ventana)
{
	if (estaActivo())
	{
		ventana->draw(spr_objetivo);
	}
}

void Objetivos::Actualizar(RenderWindow* ventana, Vector2f posicion, float dt)
{
	Vector2f movimiento(posicion.x, posicion.y);
	movimiento.x += velocidad.x * dt;
	movimiento.y += velocidad.y * dt;
	spr_objetivo.setPosition(movimiento.x, movimiento.y);
}

void Objetivos::Aparecer(RenderWindow* ventana)
{
	Objetivos::visibilidad(true);
	int pos = rand() % 2;
	if (pos == 0 )
	{
		spr_objetivo.setPosition(0, 300 + rand() % 300);
		velocidad.x = 150 + rand() % 100;
		velocidad.y = -(150+(rand() % 50));
	}
	if (pos == 1)
	{
		spr_objetivo.setPosition(ventana->getSize().x-20, 300 + rand() % 300);
		velocidad.x = -(150+(rand() % 100));
		velocidad.y = -(150+(rand() % 50));
	}
}



bool Objetivos::estaVivo()
{
	return conVida;
}

void Objetivos::Revive()
{
	conVida = true;
}

bool Objetivos::Visible() const
{
	return estaVisible;
}

bool Objetivos::estaActivo() const
{
	return conVida && estaVisible;
}

void Objetivos::visibilidad(bool estado)
{
	estaVisible = estado;
}

bool Objetivos::EnLaMira(float x, float y, FloatRect bounds)
{
	return bounds.contains(x, y);
}

void Objetivos::muerte()
{
	conVida = false;
}