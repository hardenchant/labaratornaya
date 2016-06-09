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
	matrix<T>(int m, int n);
	const matrix<T> operator*(const matrix<T>& mat);  //умножение матриц
	const matrix<T> operator+(const matrix<T>& mat); //plus
	const matrix<T> operator|(const matrix<T>& mat);
	int set(int m, int n, T set);
	//const T get(int m, int n);
	//const matrix<T> rotate();
	void print(); //вывод матрицы
	T begin();
	T end();
	class itr {
	private:
		int mpos;
		int npos;
	public:
		itr() {
			mpos = 0;
			npos = 0;
		}
		T operator*() {
			return mat[mpos][npos];
		}
		T operator++() {
			int old_mpos = mpos;
			int old_npos = npos;
			if (npos == (n - 1)) {
				mpos++;
			}
			else {
				npos++;
			}
			return mat[old_mpos][old_npos];
		}
	};
	friend itr;
};
template <class T>
matrix<T>::matrix(int m, int n) {
	this->m = m;
	this->n = n;
	mat = new T*[m];
	for (int i = 0; i < m; i++)
	{
			mat[i] = new T[n];
	}
}
template <class T>
int matrix<T>::set(int m, int n, T set) {
	mat[m-1][n-1] = set;
	return 1;
}
template <class T>
const matrix<T> matrix<T>::operator*(const matrix<T>& mat)
{
	matrix<T> temp = matrix<T>(m, mat.n); // создаем пустую матрицу
	T tempvalue; //tempvalue должен иметь возможность = 0 ))))
	{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < mat.n; j++)
		{
			tempvalue = 0; 
			for (int k = 0; k < n; k++)
			{
				tempvalue = tempvalue + (this->mat[i][k] * mat.mat[k][j]);
			}
			temp.mat[i][j] = tempvalue;
		}
	}
	return temp;
}
template <class T>
const matrix<T> matrix<T>::operator+(const matrix<T>& mat)
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
template <class T>
const matrix<T> matrix<T>::operator|(const matrix<T>& mat)
{
	matrix<T> temp(m, n + mat.n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			temp.mat[i][j] = this->mat[i][j];
		}
		for (int k = n; k < (n + mat.n); k++) {
			temp.mat[i][k] = mat.mat[i][k - n];
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
template <class T>
void matrix<T>::print()
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}
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
template <class T>
T matrix<T>::begin() {
	return mat[0][0];
}
template <class T>
T matrix<T>::end() {
	return mat[m - 1][n - 1];
}
//template <class T>
//class matrix<T>::itr{
//private:
//	int mpos;
//	int npos;
//public:
//	itr() {
//		mpos = 0;
//		npos = 0;
//	}
//	T operator*() {
//		return mat[mpos][npos];
//	}
//	T operator++() {
//		int old_mpos = mpos;
//		int old_npos = npos;
//		if (npos == (n - 1)) {
//			mpos++;
//		}
//		else {
//			npos++;
//		}
//		return mat[old_mpos][old_npos];
//	}
//}

int main()
{
	//srand(time(0));
	matrix<int> mmm(2, 2);
	matrix<int> nnn(2, 2);
	matrix<int>::itr sss;
	mmm.set(1, 1, 1);
	mmm.set(1, 2, 2);
	mmm.set(2, 1, 3);
	mmm.set(2, 2, 4);
	nnn.set(1, 1, 1);
	nnn.set(1, 2, 2);
	nnn.set(2, 1, 3);
	nnn.set(2, 2, 4);
	mmm = mmm * nnn;
	mmm.print();
	nnn.print();
	mmm = mmm | nnn;
	mmm.print();

	for (matrix<int>::itr iterator; *iterator != mmm.end(); ++iterator) {
		cout << *iterator << endl;
	}

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