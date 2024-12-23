#pragma once
#include "Librerias.h"
#include "MiraJugador.h"
#include "Objetivos.h"

class game
{
	RenderWindow* _ventana;
	MiraJugador* _jugador;
	Objetivos* _objetivo;
	Text puntaje;
	Texture tex_fondo;
	Sprite spr_fondo;
	Font fuente;
	int puntos;
	sf::Clock Reloj;

	void actualizarPuntaje(int puntos)
	{
		puntaje.setString("Puntaje: " + to_string(puntos));
	}
public:

	game();
	void run();
	void eventos();
	void actualizar(float dt);
	void disparar();
	void renderJuego();
	~game()
	{
		delete _objetivo;
		delete _jugador;
		delete _ventana;
	}
};
