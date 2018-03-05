#pragma once

class MyMatrix
{
public:
	MyMatrix();
	MyMatrix(int x, int y);
	MyMatrix(const MyMatrix & a);

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
	MyMatrix operator=(MyMatrix &oldMatrix);
	//~MyMatrix();
private:
	int sizeX, sizeY;
	int **matrix;
};