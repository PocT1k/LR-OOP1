#ifndef LR_OOP1_FIGURES
#define LR_OOP1_FIGURES

#include <windows.h>


class Location;
class Point;
class Face;


class Location
{
 protected:
	int x;
	int y;
 public:
	Location(int x, int y);
	virtual void move(int offsetX, int offsetY);
};

class Point : public Location
{
 public:
	Point(int x, int y);
	virtual void show(HDC hdc);
};

class Face : public Point
{
 protected:
	int weightLine = 4;
 public:
	Face(int x, int y);
	void onKeyDown(WPARAM wParam);
	void show(HDC hdc);
};

#endif
