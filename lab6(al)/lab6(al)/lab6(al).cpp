// lab6(al).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "ctime"
using namespace std;

//class rational {
//private:
//	int m;
//	int n;
//public:
//	void print();
//	rational(int m, int n);
//	rational();
//	const rational operator+(const rational& r);
//	const rational operator*(const rational& r); //умножение на рац дробь
//	const rational operator*(int lambda); //умножение на число
//};

template <class T>
class matrix {
private:
	T **mat;
public:
	int m; //stroki
	int n; //stolbci
	const matrix<T> operator*(const matrix<T>& mat);  //умножение матриц
	//const matrix<T> operator+(const matrix<T>& mat); //plus
	//const T get(int m, int n);
	//const matrix<T> rotate();
	//void print(); //вывод матрицы

};

template <class T>
const matrix<T> matrix<T>::operator*(const matrix<T>& mat)
{
	matrix temp = matrix(m, mat.n); // создаем пустую матрицу
	T temprat; //temprat должен иметь возможность = 0 ))))
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < mat.n; j++)
		{
			temprat = 0; 
			for (int k = 0; k < n; k++)
			{
				temprat = temprat + (this->mat[i][k] * mat.mat[k][j]);
			}
			temp.mat[i][j] = temprat;
		}
	}
	return temp;
}
template <class T>
const matrix<T> matrix::operator+(const matrix<T>& mat)
{
	matrix<T> temp = matrix(m, n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp.mat[i][j] = this->mat[i][j] + mat.mat[i][j];
		}
	}
	return temp;
}
//template <class T>
//const rational matrix::get(int m, int n)
//{
//	T temp = mat[m - 1][n - 1];
//	return temp;
//}
//template <class T>
//const matrix matrix::rotate()
//{
//	matrix temp = matrix(m, n);
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			temp.mat[i][j] = mat[m - i - 1][n - j - 1];
//		}
//	}
//	return temp;
//}
//
//template <class T> //class T должен быть перегружен на <<
//void matrix::print() {
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			std::cout<< mat[i][j];
//			std::cout << " ";
//		}
//		std::cout << std::endl;
//	}
//}
//
//void rational::print()
//{
//	std::cout << m << "/" << n;
//}
//rational::rational() {
//
//}
//rational::rational(int m, int n) {
//	int a, b;
//	a = m;
//	b = n;
//	while (a != 0 && b != 0)
//	{
//		if (a > b)
//		{
//			a = a%b;
//		}
//		else
//		{
//			b = b%a;
//		}
//	}
//	a = a + b; // NOD
//	this->m = m / a;
//	this->n = n / a;
//}
//const rational rational::operator*(const rational& r) {
//	rational temp = rational(m*r.m, n*r.n);
//	return (temp);
//}
//const rational rational::operator*(int lambda) {
//	rational temp = rational(m*lambda, n);
//	return (temp);
//}
//const rational rational::operator+(const rational& r) {
//	int a = n; // 1 znamenatel
//	int b = r.n; // 2 znamenatel
//	int nod;
//	while (a != 0 && b != 0)
//	{
//		if (a > b)
//		{
//			a = a%b;
//		}
//		else
//		{
//			b = b%a;
//		}
//	}
//	nod = a + b; // NOD
//	a = n / nod;
//	b = r.n / nod;
//	rational temp = rational(m*b + r.m*a, nod*a*b);
//	return temp;
//}

int main()
{
	//srand(time(0));


	//	matrix<rational> mrrr; - конструктор по умолчанию тоже должен быть
	//= matrix(3, 3);
	//mrrr.print();
	//std::cout << std::endl << std::endl;

	//matrix mrrr2 = matrix(3, 3);
	//mrrr2.print();
	//std::cout << std::endl << std::endl;

	//try
	//{

	//	matrix mrrr3 = mrrr + mrrr2;
	//	if (mrrr.m != mrrr2.m || mrrr.n != mrrr2.n) throw mrrr3;
	//	cout << "addition:" << endl;
	//	mrrr3.print();

	//	std::cout << std::endl;
	//	std::cout << std::endl;

	//	mrrr3 = mrrr3.rotate();
	//	cout << "rotate:" << endl;
	//	mrrr3.print();

	//	std::cout << std::endl;
	//	std::cout << std::endl;

	//	rational r = mrrr3.get(2, 3);
	//	cout << "Element with index 2,3:" << endl;
	//	r.print();

	//	std::cout << std::endl;
	//	std::cout << std::endl;

	//	mrrr3 = mrrr * mrrr2;
	//	if (mrrr.m != mrrr2.m || mrrr.n != mrrr2.n) throw mrrr3;
	//	cout << "Multiply:" << endl;
	//	mrrr3.print();

	//	std::cout << std::endl;
	//	/*rational r = rational(13, 123);
	//	rational p = rational(16, 123);
	//	r = r * p;
	//	r.print();*/

	//}
	//catch (matrix mat)
	//{
	//	std::cout << "Error in matrix row or column!" << std::endl;
	//	return 0;
	//}

	//system("pause");
	return 0;
}