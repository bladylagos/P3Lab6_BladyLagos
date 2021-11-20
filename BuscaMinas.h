#ifndef BUSCAMINAS_H
#define BUSCAMINAS_H

class BuscaMinas
{
	private:
	int x;
	int y;
public:
	BuscaMinas();
	BuscaMinas(int i, int j);

	int getX() const ;
	int getY() const ;

	void setX(int number);
	void setY(int number);

};

#endif