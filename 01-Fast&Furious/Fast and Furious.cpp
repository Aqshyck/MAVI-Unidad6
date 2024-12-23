#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp> 

int main() 
{ // Crear una ventana SFML 
	sf::RenderWindow window(sf::VideoMode(800, 600), "Fast and Furious");
	// Definir la posición y velocidad inicial del objeto 
	sf::Vector2f posicion(0.0f, 300.0f); 
	sf::Vector2f velocidad(10.0f, 0.0f); 
	// Constante de aceleración 
	const float aceleracion = 10.0f;
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
		// Actualizar la velocidad del objeto en función de la aceleración y el tiempo transcurrido 
		float deltaTime = 0.1f / 60.0f; // Suponemos que el juego se está ejecutando a 60 FPS 
		// Actualizar la posición del objeto en función de la velocidad y el tiempo transcurrido 
		posicion.x += velocidad.x * deltaTime; 
		// Comprobar si el objeto ha alcanzado el limite lateral
		if (posicion.x > 800.0f) 
		{ // Reiniciar la vuelta y aumentar la velocidad 
			posicion.x = 0.0f;
			velocidad.x += 10.0f; 
		} 
		//Cerrar despues de alcanzaar cierta velocidad
		if (velocidad.x > 100)
		{
			window.close();
		}
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