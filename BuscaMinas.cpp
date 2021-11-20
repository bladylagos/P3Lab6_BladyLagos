#include "BuscaMinas.h"

BuscaMinas::BuscaMinas(){
	x = y = 0;
}
BuscaMinas::BuscaMinas(int i, int j) 
{
	x = i; 
	y = j;
}
int BuscaMinas::getX() const
{
	return x;
}

int BuscaMinas::getY() const
{
	return y;
}

void BuscaMinas::setX(int number)
{
	x = number;
}

void BuscaMinas::setY(int number)
{
	y = number;
}

bool operator==(const BuscaMinas& uno, const BuscaMinas& otro){
	bool igual = uno.getX() == otro.getX() && uno.getY() == otro.getY();
	return igual;
}