// ConsoleApplication4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "ctime"

class rational {
private:
	int m;
	int n;
public:
	void get();
	rational(int m, int n);
	rational();
	const rational operator+(rational& r);
	const rational operator*(const rational& r); //умножение на рац дробь
	const rational operator*(int lambda); //умножение на число
};

class matrix {
private:
	rational **mat;
	int m; //stroki
	int n; //stolbci
public:
	matrix(int m, int n);
	matrix();
	const matrix operator*(const matrix& mat);
	
};
matrix::matrix()
{

}
matrix::matrix(int m, int n) //m-stroki n-stolbiki 
{
	this->m = m;
	this->n = n;
	srand(time(0));
	mat = new rational*[m];
	for (int i = 0; i < m; i++) {

		mat[i] = new rational[n];
		for (int j = 0; j < n; j++)
		{
			mat[i][j] = rational(rand() % 10000, rand() % 10000);
		}
	}
}
const matrix matrix::operator*(const matrix& mat) {
	matrix temp;
	temp.mat = new rational*[m];
	rational temprat = rational(0, 0);
	for (int i = 0; i < m; i++) {
		   
		temp.mat[i] = new rational[mat.n];
		for (int j = 0; j < mat.n; j++)
		{
			for (int e = 0; e < mat.n;e++)
				temprat = temprat+
				temp.mat[i][j] = temp
		}
	}
	
}


void rational::get()
{
	std::cout << m << "/" << n << std::endl;
}
rational::rational() {

}
rational::rational(int m, int n) {
	int a, b;
	a = m;
	b = n;
	while (a != 0 && b != 0)
	{
		if (a > b) 
		{
			a = a%b;
		}
		else
		{
			b = b%a;
		}
	}
	a = a + b; // NOD
	this->m = m / a;
	this->n = n / a;
}
const rational rational::operator*(const rational& r) {
	rational temp = rational(m*r.m, n*r.n);
	return (temp);
}

const rational rational::operator*(int lambda) {
	rational temp = rational(m*lambda, n);
	return (temp);
}

const rational rational::operator+(rational& r) {
	int a = n; // 1 znamenatel
	int b = r.n; // 2 znamenatel
	int nod;
	while (a != 0 && b != 0)
	{
		if (a > b)
		{
			a = a%b;
		}
		else
		{
			b = b%a;
		}
	}
	nod = a + b; // NOD
	a = n / nod;
	b = r.n / nod;
	rational temp = rational(m*b + r.m*a, nod*a*b);
	return temp;
}

int main()
{
	/*catch (int a) {
		if (a == 1) {
			std::cout << "Stroki 1 ne ravni stolbcam 2" << std::endl;
		}
	}
	try
	{

	}
	*/
	
	rational r = rational(13, 123);
	rational p = rational(16, 123);
	r = r * p;
	r.get();
    return 0;
}

