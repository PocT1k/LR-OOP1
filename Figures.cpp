#include "Figures.hpp"


Location::Location(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Location::move(int offsetX, int offsetY)
{
	this->x += offsetX;
	this->y += offsetY;
}

Point::Point(int x, int y) : Location(x, y) {};

void Point::show(HDC hdc)
{
	SetPixel(hdc, x, y, RGB(0, 0, 0));
}

Face::Face(int x, int y) : Point(x, y) {};

void Face::onKeyDown(WPARAM wParam) {
	int step = 1;
	switch (wParam) {
	case 'W':
		move(0, -step);
		break;
	case 'S':
		move(0, step);
		break;
	case 'A':
		move(-step, 0);
		break;
	case 'D':
		move(step, 0);
		break;
	}
}

void Face::show(HDC hdc)
{
	HPEN pen = CreatePen(PS_SOLID, weightLine * 2, RGB(0, 0, 0));
	SelectObject(hdc, pen);
	this->x += weightLine;
	this->y += weightLine;

	Ellipse(hdc, 0 + x, 0 + y, 200 + x, 200 + y);
	Ellipse(hdc, 50 + x, 50 + y, 80 + x, 80 + y);
	Ellipse(hdc, 62 + x, 62 + y, 68 + x, 68 + y);
	Ellipse(hdc, 120 + x, 50 + y, 150 + x, 80 + y);
	Ellipse(hdc, 132 + x, 62 + y, 138 + x, 68 + y);
	MoveToEx(hdc, 65 + x, 150 + y, NULL);
	LineTo(hdc, 135 + x, 150 + y);

	SelectObject(hdc, GetStockObject(BLACK_PEN));
	DeleteObject(pen);
	this->x -= weightLine;
	this->y -= weightLine;
}
