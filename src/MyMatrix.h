#pragma once

class MyMatrix
{
public:
	MyMatrix();
	MyMatrix(int x, int y);
	~MyMatrix();

	MyMatrix(const MyMatrix & a);
	MyMatrix coppyMatrix(MyMatrix toCoppy);
private:
	 int sizeX, sizeY;
	 int **matrix;
};