#pragma once
#include<vector>
#include<ctime>
#include"CJugador.h"
#include"CPersonaje.h"
using namespace std;
class CControladora
{
private:
	CJugador* jug;
	vector<CPersonaje*>vec;//vector de Personajes
	int segundos, tiempo;
	time_t inicio, actual, reloj;
	bool gano, termino;
public:
	CControladora(int segundos, int tiempo)
	{
		jug = new CJugador();
		time(&inicio);
		this->segundos = segundos;
		this->tiempo = tiempo;
		time(&reloj);
		gano = false;
		termino = false;
	}
	~CControladora()
	{
		delete jug;
	}
	void crearPersonajes(Graphics^ g, Bitmap^ imgPersonaje1, Bitmap^ imgPersonaje2)
	{
		//tipo 1->Camina
		//tipo 2->Corre
		CPersonaje*nuevo = new CPersonaje(g);
		vec.push_back(nuevo);
	}
	void mostrarTodo(Graphics^ g, Bitmap^ imgJugador, Bitmap^ imgPersonaje1, Bitmap^ imgPersonaje2)
	{
		jug->mostrar(g, imgJugador);
		for (int i = 0; i < vec.size(); i++)
		{
			if (vec.at(i)->getTipo() == 1)
			{
				vec.at(i)->mostrar(g, imgPersonaje1);
			}
			else
			{
				vec.at(i)->mostrar(g, imgPersonaje2);
			}
		}
	}
	void moverTodos(Graphics^ g)
	{
		jug->mover(g);
		for each (CPersonaje * p in vec)
		{
			p->mover(g);
		}
	}
	void run(Graphics^ g, Bitmap^ imgJugador, Bitmap^ imgPersonaje1, Bitmap^ imgPersonaje2)
	{
		time(&actual);
		moverTodos(g);
		mostrarTodo(g, imgJugador, imgPersonaje1, imgPersonaje2);
		if (difftime(actual, inicio) >= segundos)
		{
			time(&inicio);
			crearPersonajes(g, imgPersonaje1, imgPersonaje2);
		}
		verificarColisiones();
		if (difftime(actual, reloj) >= 1)
		{
			time(&reloj);
			tiempo--;
		}
		if (jug->getPuntos() >= 500)
		{
			gano = true;
		}
		if (tiempo <= 0)
			termino = true;
	}
	void verificarColisiones()
	{
		for (int i = 0; i < vec.size(); i++)
		{
			if (jug->colision(vec.at(i)->getRec()))
			{
				jug->increasePuntos();
				vec.erase(vec.begin() + i);
				break;
			}
		}
	}
	void tecla(char t)
	{
		switch(t)
		{
			case 'A': 
				jug->setDx(-15);
				jug->setDy(0);
				break;
			case 'D': 
				jug->setDx(15);
				jug->setDy(0);
				break;
			case 'W': 
				jug->setDx(0);
				jug->setDy(-15);
				break;
			case 'S': 
				jug->setDx(0);
				jug->setDy(15);
				break;
			case 'N': 
				jug->setDx(0);
				jug->setDy(0);
				break;
		}
	}
	bool getGano()
	{
		return gano;
	}
	bool getTermino()
	{
		return termino;
	}
	int getTime()
	{
		return tiempo;
	}
	int getPuntos()
	{
		return jug->getPuntos();
	}
};
