#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
using namespace std;

class jugador
{
	private:

		string nick;
		int puntuacion;

	public:

	//constructores
	juagdor();
	jugador(string nick, int puntuacion);

	//destructor
	~juagdor();

	//constructor copia
	jugador(const jugador &j);

	//getters y setters
	void setNick (string nick);
	void setPuntuacion(int punt);

	string getNick() const;
	int getPuntuacion() const;

	//metodos
	// void sumar_puntos(jugador j, string dificultad);
	int existeJugador(jugador* listaJugadores, char* Nick); 
	jugador* actualizarPuntuacion(jugador* listaTodosJugadores, int* numTodos, jugador* listaJugadoresSesion, int numElem);

	friend bool operator<(const t_jugador& jugador);
	friend bool operator>(const t_jugador& jugador);
};

#endif