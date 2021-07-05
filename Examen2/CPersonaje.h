#pragma once
#include"CMovil.h"
class CPersonaje : public CMovil
{
private:
	int puntos;
	int paciencia;
public:
	CPersonaje(Graphics^g) : CMovil()
	{
		puntos = 0;
		tipo = rand() % 2 + 1;
		//tipo 1->Camina
		//tipo 2->Corre
		x = rand() % ((int)g->VisibleClipBounds.Width - this->getWidth());
		y = rand() % ((int)g->VisibleClipBounds.Height - this->getHeight());
		if (tipo == 1)
		{
			dx = ((rand() % 2) * 10 - 5) * 2;
		}
		else
		{
			dx = ((rand() % 2) * 10 - 5) * 4;
		}
		maxfil = 2;
		maxcol = 7;
		paciencia = 96;
	}
	~CPersonaje()
	{

	}
	void mover(Graphics^ g)
	{
		if (x + dx<0 || x + dx + width>g->VisibleClipBounds.Width ||
			y + dy<0 || y + dy + height>g->VisibleClipBounds.Height || rand()%100>=paciencia)
		{
			movinvalido(0);
		}
		else
		{
			x += dx;
			y += dy;
		}
	}
	void mostrar(Graphics^ g, Bitmap^ bmp)
	{
		if (dx > 0)
		{
			fil = 1;
		}
		else if (dx < 0)
		{
			fil = 0;
		}
		else
		{
			fil = fil;
		}
		Rectangle sectionShow = Rectangle(col * bmp->Width / maxcol, fil * bmp->Height / maxfil, bmp->Width / maxcol, bmp->Height / maxfil);
		g->DrawImage(bmp, this->getRec(), sectionShow, GraphicsUnit::Pixel);
		col++;
		if (col >= maxcol)
		{
			col = 0;
		}
	}
	void increasePuntos()
	{
		puntos += 50;
	}
	int getPuntos()
	{
		return puntos;
	}
	void movinvalido(int n)
	{
		dx *= -1;
	}
};
