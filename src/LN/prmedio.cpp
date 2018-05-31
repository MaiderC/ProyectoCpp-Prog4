#include "prmedio.h"
#include "preguntas_respuestas.h"
#include <iostream>
#include <string.h>
#include "jugador.h"

using namespace std;


#define DEFAULT_RESPUESTA2 "defaultAnswer2"
#define DEFAULT_RESPUESTA3 "defaultAnswer3"
#define DEFAULT_DIFICULTAD "##"


//constructores
prmedio::prmedio()
{
  this -> respuesta2 = DEFAULT_RESPUESTA2;
  this -> respuesta3 = DEFAULT_RESPUESTA3;
}
		
prmedio::prmedio(string pregunta, string respuesta1, string respuesta2, string respuesta3, string dificultad, bool leerBD): preguntas_respuestas(pregunta, respuesta1, dificultad, leerBD)
{
  this -> respuesta2 = respuesta2;
  this -> respuesta3 = respuesta3;
}

//destructor
 prmedio::~prmedio()
{
}

//constructor copia
prmedio::prmedio(const prmedio &pm): preguntas_respuestas(pm)
{
	this -> respuesta2 = pm.respuesta2;
	this -> respuesta3 = pm.respuesta3;
	//para los atributos que están en la madre
	// preguntas_respuestas :: prmedio();
}

//getter y setter

void prmedio::setRespuesta2(string RDos)
{
	this -> respuesta2 = RDos;
}

string prmedio::getRespuesta2() const
{
	return respuesta2;
}

void prmedio::setRespuesta3(string RTres)
{
	this -> respuesta3 = RTres;
}

string prmedio::getRespuesta3() const
{
	return respuesta3;
}

//metodos

 void prmedio::sumarPunto(jugador jugador)
{
	jugador.setPuntuacion(jugador.getPuntuacion() + 2);
}

 void prmedio::prepararRespuestas(preguntas_respuestas pregunta, string medio)
{
	int i = 2;
	int igual = 0;
	int r;
	int random[3];
	//array de respuestas auxiliares 
	string respuestas[3];

	random[0] = -1;
	random[1] = -1;
	random[2] = -1;
 	
	// Este while llena el array random con números aleatorios de 0 a 2, pero que no se repitan.
	while(i>=0)
	{
		igual = 0;
		r = rand() % 3;

		for(int j = 0; j<3; j++)
		{
			if(r == random[j])
				igual = 1;
		}

		if(igual == 0)
		{
			random[i] = r;
			i--;
		}
	}

	respuestas[random[0]] = this -> respuesta1;
	respuestas[random[1]] = this -> respuesta2;
	respuestas[random[2]] = this -> respuesta3;
	
	this -> respuesta1 = respuestas[0];
	this -> respuesta2 = respuestas[1];
	this -> respuesta3 = respuestas[2];	
}

bool prmedio::operator=(const prmedio& pm)
{
	this -> respuesta2 = pm.respuesta2;
	this -> respuesta3 = pm.respuesta3;
}

ostream& operator<<(ostream& out, const preguntas_respuestas& Pregunta)
{
	prfacil* preguntamedio = dynamic_cast<*prfacil>(Pregunta);

	out << (*preguntamedio).getPregunta() << endl;

	out << "a) ";
	if((*preguntamedio).getRespuesta1()[0] == '#')
	{
		string aux = (*preguntamedio).getRespuesta1();

		aux.erase(0, 1);

		out << aux << endl;
	} else
	{
		out << (*preguntamedio).getRespuesta1() << endl;
	}

	out << "b) ";
	if((*preguntamedio).respuesta2[0] == '#')
	{
		string aux = (*preguntamedio).respuesta2;

		aux.erase(0, 1);

		out << aux << endl;
	} else
	{
		out << (*preguntamedio).respuesta2 << endl;
	}

	out << "c) ";
	if((*preguntamedio).respuesta3[0] == '#')
	{
		string aux = (*preguntamedio).respuesta3;

		aux.erase(0, 1);

		out << aux << endl;
	} else
	{
		out << (*preguntamedio).respuesta3 << endl;
	}

	return out;
}

istream& operator>>(istream& in, preguntas_respuestas& Pregunta)
{
	prfacil* preguntamedio = dynamic_cast<*prfacil>(Pregunta);

	string temporal;
	mostrarMensaje("Introduce la pregunta a insertar: ");
	in >> temporal;
	(*preguntamedio).getPregunta(temporal);

	mostrarMensaje("*La respuesta no debe contener la letra de la opcion (a o b) ni signos de puntuacion al inicio (salvo que se trate de un guion, por ser la respuesta un numero negativo)");
	mostrarMensaje("Introduce la respuesta correcta: ");
	in >> temporal;
	(*preguntamedio).getRespuesta1(temporal);

	(*preguntamedio).getRespuesta1() = '#' + (*preguntamedio).getRespuesta1();

	mostrarMensaje("Introduce otra respuesta (una incorrecta): ");
	in >> (*preguntamedio).respuesta2;

	mostrarMensaje("Introduce otra respuesta (una incorrecta): ");
	in >> (*preguntamedio).respuesta3;

	return in;
}
