//BIBLIOTECAS//
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;


int main()
{ // Crear una ventana SFML 
	sf::RenderWindow window(sf::VideoMode(800, 600), "Bounce");
	// Definir la posici�n y velocidad inicial del objeto 
	sf::Vector2f posicion(window.getSize().x / 2, window.getSize().y);
	sf::Vector2f velocidad(0.0f, -100.0f);
	// Constante de aceleraci�n 
	const float aceleracion = 9.8f;
	int rebotes = 0;
	// Bucle principal del juego 
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		// Actualizar la velocidad del objeto en funci�n de la aceleraci�n y el tiempo transcurrido 
		float deltaTime = 0.1f / 60.0f; // Suponemos que el juego se est� ejecutando a 60 FPS 
		// Actualizar la posici�n del objeto en funci�n de la velocidad y el tiempo transcurrido 
		posicion.y += velocidad.y * deltaTime;
		velocidad.y = velocidad.y + (aceleracion * deltaTime);
				
		if (posicion.y > window.getSize().y)
		{ // Rebote
			velocidad.y = velocidad.y * (-0.9);
			rebotes += 1;
		}
		if (rebotes == 9)
		{
			window.close();
		}
		// Limpiar la ventana 
		window.clear();
		// Dibujar el objeto en su posici�n actual 
		sf::CircleShape circulo(30.0f);
		circulo.setPosition(posicion);
		circulo.setFillColor(sf::Color::Yellow);
		window.draw(circulo);
		window.display();
	} return 0;
}