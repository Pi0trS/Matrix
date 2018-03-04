#include <iostream>
#include "MyMatrix.h"
#include <exception>
using namespace std;


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
			matrix[i][j] = a.matrix[i][j];
		}
	}
}

int MyMatrix::getSizeX()
{
	return sizeX;
}

int MyMatrix::getSizeY()
{
	return sizeY;
}
int MyMatrix::getElement(int x, int y)
{
	return matrix[x][y];
}
void MyMatrix::showMatrix()
{
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			cout << matrix[i][j];
		}
		cout << endl;
	}
}

void MyMatrix::setValue(int toSet)
{

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

MyMatrix operator +(MyMatrix oldMatrix, int a)
{
	MyMatrix newMatrix(oldMatrix.getSizeX(), oldMatrix.getSizeY());
	for (int i = 0; i < oldMatrix.getSizeX(); i++)
	{
		for (int j = 0; j < oldMatrix.getSizeY(); j++)
		{
			newMatrix.matrix[i][j] = oldMatrix.getElement(i,j) + a;
		}
	}
	return newMatrix;
}

MyMatrix operator -(MyMatrix oldMatrix, int a)
{
	MyMatrix newMatrix(oldMatrix.getSizeX(), oldMatrix.getSizeY());
	for (int i = 0; i < oldMatrix.getSizeX(); i++)
	{
		for (int j = 0; j < oldMatrix.getSizeY(); j++)
		{
			newMatrix.matrix[i][j] = oldMatrix.getElement(i, j) - a;
		}
	}
	return newMatrix;
}

MyMatrix operator *(MyMatrix oldMatrix, int a)
{
	MyMatrix newMatrix(oldMatrix.getSizeX(), oldMatrix.getSizeY());
	for (int i = 0; i < oldMatrix.getSizeX(); i++)
	{
		for (int j = 0; j < oldMatrix.getSizeY(); j++)
		{
			newMatrix.matrix[i][j] = oldMatrix.getElement(i, j) * a;
		}
	}
	return newMatrix;
}

MyMatrix operator /(MyMatrix oldMatrix, int a)
{
		if (a == 0)throw std::logic_error("Divide by zero exception");
		MyMatrix newMatrix(oldMatrix.getSizeX(), oldMatrix.getSizeY());
		for (int i = 0; i < oldMatrix.getSizeX(); i++)
		{
			for (int j = 0; j < oldMatrix.getSizeY(); j++)
			{
				newMatrix.matrix[i][j] = oldMatrix.getElement(i, j) / a;
			}
		}
		return newMatrix;
}