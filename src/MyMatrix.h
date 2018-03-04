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
	void setValue(int toSet);
	MyMatrix coppyMatrix(MyMatrix toCoppy);
	friend MyMatrix operator +(MyMatrix oldMatrix, int a);
	friend MyMatrix operator -(MyMatrix oldMatrix, int a);
	friend MyMatrix operator *(MyMatrix oldMatrix, int a);
	friend MyMatrix operator /(MyMatrix oldMatrix, int a);



	//~MyMatrix();
private:
	int sizeX, sizeY;
	int **matrix;
};