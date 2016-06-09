// lab6(al).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "ctime"
#include <memory>
#include <algorithm>

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

template <class T, int m, int n>
class matrix {
private:
	T **mat;
public:
	matrix<T, m, n>();
	matrix(matrix &matr) {
		mat = new T*[m];
		for (int i = 0; i < m; i++)
		{
			mat[i] = new T[n];
			for (int j = 0; j < n; j++) {
				set(i, j, matr.get(i, j));
			}
		}

	}
	~matrix();


	const void operator=(const matrix<T, m, n>& mat);

	template <class U = T, int m2 = n, int n2>
	matrix<T, m, n2> operator*(matrix<U, m2, n2>& mat);  //умножение матриц

	T get(int m, int n);

	template <class U = T, int m2 = m, int n2, int n3=n+n2>
	
	matrix<U, m2, n3> operator|(matrix<U, m2, n2>& mat);
	
	void set(int m_in, int n_in, T set);
	void print(); //вывод матрицы
	
	
	class iter {
		matrix* p_mat;
		int pos_m, pos_n;
	public:
		iter& operator++() {
			if (pos_n == n - 1) {
				pos_m++;
				pos_n = 0;
			}
			else
			{
				pos_n++;
			}
			return *this;
		}
		bool operator!=(const iter& prev_it){
			return !(pos_m == prev_it.pos_m && pos_n == prev_it.pos_n);
		}
		iter(matrix* p_mat, int pos_m, int pos_n) {
			this->p_mat = p_mat;
			this->pos_m = pos_m;
			this->pos_n = pos_n;
		}
		T operator*() {
			return p_mat->get(pos_m, pos_n);
		}
		T* operator->() {
			return *p_mat->get(pos_m, pos_n);
		}

	};
	iter begin() {
		iter temp(this, 0, 0);
		return temp;
	}
	iter end() {
		iter temp(this, m, 0);
		return temp;
	}
};
template <class T, int m, int n>
matrix<T, m, n>::matrix() {
	mat = new T*[m];
	for (int i = 0; i < m; i++)
	{
			mat[i] = new T[n];
	}
}

template <class T, int m, int n>
T matrix<T, m, n>::get(int m, int n) {
	return mat[m][n];
}

template <class T, int m, int n>
const void matrix<T, m, n>::operator=(const matrix<T, m, n>& mat) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			set(i, j, mat.get(i, j));
		}
	}
}

template <class T, int m, int n>
void matrix<T, m, n>::set(int m_in, int n_in, T set) {
	mat[m_in][n_in] = set;
}

template <class T, int m, int n>
template <class U = T, int m2 = n, int n2>
matrix<T, m, n2> matrix<T, m, n>::operator*(matrix<U, m2, n2>& mat)
{
	matrix<T, m, n2> temp; // создаем пустую матрицу m1xn2
	T tempvalue; //tempvalue должен иметь возможность = 0 ))))
	{
	for (int i = 0; i < m; i++) //m1
		for (int j = 0; j < n2; j++) //n2
		{
			tempvalue = 0; 
			for (int k = 0; k < n; k++) //n1
			{
				tempvalue = tempvalue + (get(i, k) * mat.get(k, j));
			}
			temp.set(i, j, tempvalue);
		}
	}
	return temp;
}

template <class T, int m, int n> //class T должен быть перегружен на <<
void matrix<T, m, n>::print() {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << get(i, j);
			std::cout << " ";
		}
		std::cout << std::endl;
	}
}

template <class T, int m, int n>
template <class U = T, int m2 = m, int n2, int n3 = n + n2>
matrix<U, m2, n3> matrix<T, m, n>::operator|(matrix<U, m2, n2>& mat) {
	matrix<U, m2, n3> temp;
	for (int i = 0; i < m2; i++) {
		for (int j = 0; j < n; j++) {
			temp.set(i, j, get(i, j));
		}
		for (int k = n; k < n + n2; k++) {
			temp.set(i, k, mat.get(i, k - n));
		}
	}
	return temp;
}

template <class T, int m, int n>
matrix<T, m, n>::~matrix() {
	for (int i = 0; i < m; i++)
	{
		delete mat[i];
	}
	delete mat;
}

int main()
{
	matrix<int, 2, 1> mmm;
	mmm.set(0, 0, 1);
	mmm.set(1, 0, 3);
	matrix<int, 1, 2> nnn;
	nnn.set(0, 0, 4);
	nnn.set(0, 1, 3);
	matrix<int, 2, 2> sss = mmm*nnn;
	sss.print();
	matrix<int, 2, 1> mmm1;
	mmm1.set(0, 0, 11);
	mmm1.set(1, 0, 31);
	matrix<int, 2, 2> konk = mmm | mmm1;
	konk.print();

	auto it = konk.begin();
	for (; it != konk.end(); ++it) {
		cout << *it << endl;
	}

	return 0;
}