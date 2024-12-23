//BIBLIOTECAS//
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{ // Crear una ventana SFML 
	sf::RenderWindow window(sf::VideoMode(800, 600), "Space");
	// Definir la posición y velocidad inicial del objeto 
	sf::Vector2f posicion(window.getSize().x/2, window.getSize().y/2);
	sf::Vector2f velocidad(0.0f, 0.0f);
	// Constante de aceleración 
	const float aceleracion = 10.0f;

	// Bucle principal del juego 
	while (window.isOpen())
	{
		Event evt;
		while (window.pollEvent(evt)) 
		{
			switch (evt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
			if (evt.type == sf::Event::KeyPressed) 
			{
				switch (evt.key.code)
				{
				case sf::Keyboard::Left:
					velocidad.x += (-1.0f);
					break;
				case sf::Keyboard::Right:
					velocidad.x += 1.0f;
					break;
				case sf::Keyboard::Up:
					velocidad.y += (-1.0f);
					break;
				case sf::Keyboard::Down:
					velocidad.y += 1.0f;
					break;
				}
			}
		}
		if (posicion.x > window.getSize().x){posicion.x = 0.0f;}
		if (posicion.x < 0){posicion.x = window.getSize().x;}
		if (posicion.y > window.getSize().y){posicion.y = 0;}
		if (posicion.y < 0){posicion.y = window.getSize().y;}
		// Actualizar la velocidad del objeto en función de la aceleración y el tiempo transcurrido 
		float deltaTime = 0.1f / 60.0f; // Suponemos que el juego se está ejecutando a 60 FPS 
		// Actualizar la posición del objeto en función de la velocidad y el tiempo transcurrido 
		posicion.x += velocidad.x * deltaTime;
		posicion.y += velocidad.y * deltaTime;
		// Limpiar la ventana 
		window.clear();
		// Dibujar el objeto en su posición actual 
		sf::CircleShape circulo(30.0f);
		circulo.setPosition(posicion);
		circulo.setFillColor(sf::Color::Yellow);
		window.draw(circulo);
		window.display();
	} return 0;
}