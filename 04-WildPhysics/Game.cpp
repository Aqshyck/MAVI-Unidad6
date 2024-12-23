#pragma once
#include "Game.h"

game::game()
{
	_ventana = new RenderWindow(VideoMode(800, 800), "Wild West?");
	_jugador = new MiraJugador();
	_objetivo = new Objetivos();
	puntos = 0;
	fuente.loadFromFile("Assets/CHILLER.TTF");
	Reloj.restart();
	
	tex_fondo.loadFromFile("Assets/Background.jpg");
	spr_fondo.setTexture(tex_fondo);
	spr_fondo.setPosition(0, 0);
	float height_fondo = (float)tex_fondo.getSize().y;
	float width_fondo = (float)tex_fondo.getSize().x;
	float escalax = 800 / width_fondo;
	float escalay = 600 / height_fondo;
	spr_fondo.setScale(escalax, escalay);
	tex_fondo.setSmooth(true);
	puntaje.setFont(fuente);
	puntaje.setPosition(50.f, 650.f);
	puntaje.setCharacterSize(30);
	puntaje.setFillColor(Color::Cyan);
	puntaje.setString("Puntaje: " + to_string(puntos));


	actualizarPuntaje(puntos);
	srand(time(NULL));
}
void game::run()
{
	Clock clock;
	clock.restart();
	float deltaTime;
	srand(time(NULL));
	while (_ventana->isOpen())
	{
		float deltaTime = clock.restart().asSeconds();
		eventos();
		actualizar(deltaTime);
		renderJuego();		
	}
}
void game::eventos()
{
	Event play;
	_ventana->setMouseCursorVisible(false);
	while (_ventana->pollEvent(play))
	{
		
		switch (play.type)
		{
		case sf::Event::Closed:
			_ventana->close();
			break;
		case sf::Event::MouseMoved:
			_jugador->Posicion(play.mouseMove.x, play.mouseMove.y);
			break;
		case sf::Event::MouseButtonPressed:
			if (play.mouseButton.button == Mouse::Button::Left)
			{
				disparar();
			}
			break;
		}
	}
}
void game::actualizar(float deltaTime)
{
	if (Reloj.getElapsedTime().asSeconds() > 3.0f)
	{
		_objetivo->Revive();
		_objetivo->Aparecer(_ventana);
		Reloj.restart();
	}
	if (_objetivo->estaVivo() && Reloj.getElapsedTime().asSeconds() < 4.0f)
	{
		_objetivo->Actualizar(_ventana, _objetivo->movimiento(), deltaTime);
	}
	else
	{
		_objetivo->visibilidad(false);
	}
}

void game::disparar()
{
	Vector2f puntoMira = _jugador->posicionMira();

	if (_objetivo->estaActivo())
	{
		if (_objetivo->EnLaMira(puntoMira.x, puntoMira.y, _objetivo->lugar()))
		{
			_objetivo->muerte();
			_objetivo->visibilidad(false);
			puntos++;
		}
	}
	actualizarPuntaje(puntos);

}

void game::renderJuego()
{
	_ventana->clear();
	_ventana->draw(spr_fondo);
	if (_objetivo->estaActivo())
	{
		_objetivo->Dibujar(_ventana);
	}
	_ventana->draw(puntaje);
	_jugador->Dibujar(_ventana);
	_ventana->display();	
}