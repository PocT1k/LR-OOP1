#include "Figures.hpp"


Location::Location(int x, int y)
{
	this->x = x;
	this->y = y;
}

Point::Point(int x, int y) : Location(x, y) {};

void Point::show(HDC hdc)
{
	SetPixel(hdc, x, y, RGB(0, 0, 0));
}

void Point::move(int offsetX, int offsetY)
{
	this->x += offsetX;
	this->y += offsetY;
}

Face::Face(int x, int y) : Point(x, y) {};

void Face::onKeyDown(WPARAM wParam) {
	int step = 5;
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

	Ellipse(hdc, 0 + x + weightLine, 0 + y + weightLine, 200 + x + weightLine, 200 + y + weightLine);
	Ellipse(hdc, 50 + x + weightLine, 50 + y + weightLine, 80 + x + weightLine, 80 + y + weightLine);
	Ellipse(hdc, 62 + x + weightLine, 62 + y + weightLine, 68 + x + weightLine, 68 + y + weightLine);
	Ellipse(hdc, 120 + x + weightLine, 50 + y + weightLine, 150 + x + weightLine, 80 + y + weightLine);
	Ellipse(hdc, 132 + x + weightLine, 62 + y + weightLine, 138 + x + weightLine, 68 + y + weightLine);
	MoveToEx(hdc, 65 + x + weightLine, 150 + y + weightLine, NULL);
	LineTo(hdc, 135 + x + weightLine, 150 + y + weightLine);

	SelectObject(hdc, GetStockObject(BLACK_PEN));
	DeleteObject(pen);
}
