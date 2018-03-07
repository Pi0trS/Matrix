#pragma once
#include "HelpOverload.h"
using namespace std;
class MyMatrix
{
public:
	MyMatrix();
	MyMatrix(int x, int y);
	MyMatrix(const MyMatrix & a);
	~MyMatrix();

	int getSizeX();
	int getSizeY();
	int getElement(int x, int y);
	void showMatrix();
	void setValue(int x, int y, int toSet);
	MyMatrix coppyMatrix(MyMatrix toCoppy);
	friend MyMatrix operator +(MyMatrix oldMatrix, int a);
	MyMatrix operator +(MyMatrix & oldMatrix);
	friend MyMatrix operator -(MyMatrix oldMatrix, int a);
	MyMatrix operator -(MyMatrix & oldMatrix);
	friend MyMatrix operator *(MyMatrix oldMatrix, int a);
	MyMatrix operator *(MyMatrix & oldMatrix);
	friend MyMatrix operator /(MyMatrix oldMatrix, int a);
	MyMatrix operator=(MyMatrix oldMatrix);
	friend ostream &operator<<(ostream &stream, MyMatrix oldMatrix);
	HelpOverload operator[](int i);
	string matrixToString();

private:
	int sizeX, sizeY;
	int **matrix;
};