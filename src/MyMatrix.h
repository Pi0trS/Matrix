#pragma once
#include "HelpOverload.h"


using namespace std;

template<class T>
class MyMatrix
{
public:
	//MyMatrix();
	MyMatrix(int x, int y);
	MyMatrix(const MyMatrix<T> & a);
	~MyMatrix();
	
	int getSizeX();
	int getSizeY();
	int getElement(int x, int y);
	void showMatrix();
	void setValue(int x, int y, T toSet);
	MyMatrix coppyMatrix(MyMatrix toCoppy);
	template<class T> friend MyMatrix operator +(MyMatrix<T> oldMatrix, T a);
	 MyMatrix operator +(MyMatrix & oldMatrix);
	friend MyMatrix operator -(MyMatrix oldMatrix, int a);
	MyMatrix operator -(MyMatrix & oldMatrix);
	friend MyMatrix operator *(MyMatrix oldMatrix, int a);
	MyMatrix operator *(MyMatrix & oldMatrix);
	friend MyMatrix operator /(MyMatrix oldMatrix, int a);
	MyMatrix operator=(MyMatrix oldMatrix);
	friend ostream &operator<<(ostream &stream, MyMatrix oldMatrix);
	HelpOverload<T> operator[](int i);
	string matrixToString();

private:
	int sizeX, sizeY;
	int **matrix;
	T **testMatrix;
};



