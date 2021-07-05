#pragma once
#include"CMovil.h"
class CJugador: public CMovil
{
private:
	int puntos;
public:
	CJugador(): CMovil()
	{
		puntos = 0;
		x = 100;
		y = 100;
		//dx = ((rand() % 2) * 10 - 5)*3;
		//dy = ((rand() % 2) * 10 - 5) * 3;
		maxfil = 2;
		maxcol = 3;
		fil = 1;
		col = 1;
	}
	~CJugador()
	{

	}
void mover(Graphics^ g)
	{
		if (x + dx<0 || x + dx + width>g->VisibleClipBounds.Width ||
			y + dy<0 || y + dy + height>g->VisibleClipBounds.Height)
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
			maxfil = 2;
			maxcol = 3;
			fil = 1;
			col = 1;
		}
		else if (dx < 0)
		{
			maxfil = 2;
			maxcol = 3;
			fil = 0;
			col = 1;
		}
		else if (dy < 0)
		{
			maxfil = 1;
			maxcol = 3;
			fil = 0;
			col = 0;
		}
		else if (dy > 0)
		{
			maxfil = 1;
			maxcol = 3;
			fil = 0;
			col = 2;
		}
		else
		{
			fil = fil;
			col = col;
			maxcol = maxcol;
			maxfil = maxfil;
		}
		Rectangle sectionShow = Rectangle(col * bmp->Width / maxcol, fil * bmp->Height / maxfil, bmp->Width / maxcol, bmp->Height / maxfil);
		g->DrawImage(bmp, this->getRec(), sectionShow, GraphicsUnit::Pixel);
	}
	void increasePuntos()
	{
		puntos += 50;
	}
	int getPuntos()
	{
		return puntos;
	}

};
