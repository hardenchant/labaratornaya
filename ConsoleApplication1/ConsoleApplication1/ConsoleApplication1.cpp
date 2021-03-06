// ConsoleApplication17.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <math.h>
#include <string>
#include <iostream>

class vector {
protected:
	int *coord;
public:
	vector(int x, int y)
	{
		coord = new int[3];
		coord[0] = x;
		coord[1] = y;
	}
	double lenght()
	{
		return(sqrt(coord[0] * coord[0] + coord[1] * coord[1]));
	}
	void printvect()
	{
		std::cout << "Vector = " << coord[0] << " , " << coord[1];
	}
	virtual void printdlina()
	{
		std::cout << "Dlina: " << lenght() << std::endl;
	}
	virtual ~vector()
	{
		std::cout << "Srabotal destructor" << std::endl;
		delete coord;
	}
};
class vector3d : protected vector {
protected:

public:
	vector3d(int x, int y, int z) :vector(x, y)
	{
		coord[2] = z;
	}
	double lenght()
	{
		return(sqrt(coord[0] * coord[0] + coord[1] * coord[1] + coord[2] * coord[2]));
	}
	void printdlina()
	{
		std::cout << "Srabotala dlina iz nasled classa" << std::endl;
		vector::printvect();
		std::cout << " , " << coord[2] << std::endl;
		std::cout << lenght() << std::endl;
	}
};

class functor;
class contain;
void foreach(functor& fun, contain& con);


class contain {
private:
	vector3d **vec;
	int kolvo;
public:
	vector3d** getcon()
	{
		return(vec);
	}
	int getkolvo()
	{
		return(kolvo);
	}
	contain(int k)
	{
		kolvo = k;
		vec = new vector3d*[k];
		for (int i = 0; i < k; i++)
		{
			vec[i] = new vector3d(1, 11, 111);
		}
	}
};


class funktor {
public:
	const void operator()(vector3d& vec)
		const {
		vec.printdlina();
	}
};

void foreach(funktor& fun, contain& con)
{
	for (int i = 0; i < con.getkolvo(); i++)
	{
		fun(*con.getcon()[i]);
	}

}

int main()
{

	funktor i;   // создаем функтор
	contain cont = contain(3); // создаем контейнер и инициализируем его тремя векторами
	foreach(i, cont); // функция foreach, используя метод печати заданного функтора, перебирает все вектора в контейнере.




	return 0;
}

