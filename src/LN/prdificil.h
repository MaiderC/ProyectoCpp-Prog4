#ifndef DIFICIL_H
#define DIFICIL_H

#include "preguntas_respuestas.h"
#include <iostream>
#include <string.h>
#include "jugador.h"

using namespace std;

class prdificil :  public preguntas_respuestas
{
	private:
		
		string respuesta2;
		string respuesta3;
		string respuesta4;

	public:

		//constructores
		prdificil();
		prdificil(string pregunta, string respuesta1, string respuesta2, string respuesta3, string respuesta4, int ID, bool leerBD);
	
		//destructor
		virtual ~prdificil();

		//constructor copia
		prdificil(const prdificil &pd);

		//getter y setter
		void setRespuesta2(string RDos);
		string getRespuesta2() const;
		void setRespuesta3(string RTres);
		string getRespuesta3() const;
		void setRespuesta4(string RCuatro);
		string getRespuesta4() const;

		//metodos de clase
		virtual void sumarPunto(jugador& jugador);
		virtual void prepararRespuestas();

		//sobrecarga de operador =
		prdificil& operator=(const prdificil& pd);

		friend ostream& operator<<(ostream& out, const prdificil& preguntadificil);
		friend istream& operator>>(istream& in, prdificil& preguntadificil);

};

#endif