#include <iostream>
#include "MyMatrix.h"


MyMatrix::MyMatrix()
{
}

MyMatrix::MyMatrix(int x, int y)
{
	sizeX = x;
	sizeY = y;
	matrix = new int *[x];
	for (int i = 0; i < x; i++)
	{
		matrix[i] = new int[y];
		for (int j = 0; j < y; j++)
		{
			matrix[i][j] = 0;
		}
	}
}



MyMatrix::MyMatrix(const MyMatrix & a)
{
	sizeX = a.sizeX;
	sizeY = a.sizeY;
	matrix = new int*[sizeX];
	for (int i = 0; i < sizeX; i++)
	{
		matrix[i] = new int[sizeY];
		for (int j = 0; j < sizeY; j++)
		{
			matrix[i][j] = 
		}
	}


}

MyMatrix MyMatrix::coppyMatrix(MyMatrix toCoppy)
{
	 MyMatrix newMatrix(toCoppy.sizeX, toCoppy.sizeY);
	 for (int i = 0; i < toCoppy.sizeX; i++)
	 {
		 for (int j = 0; j < toCoppy.sizeY; j++)
		 {
			 toCoppy.matrix[i][j];
		 }
	 }
	 return newMatrix;
}
