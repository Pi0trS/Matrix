#include <iostream>
#include <string>
#include <exception>
#include "MyMatrix.h"

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
//********************************************************
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
//********************************************************
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

void MyMatrix::setValue(int x, int y ,int toSet)
{
	if (x >= sizeX || y >= sizeY)throw out_of_range("out of range!!!");
	matrix[x][y] = toSet;
}
//********************************************************
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
//********************************************************
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
//********************************************************
MyMatrix MyMatrix::operator+(MyMatrix & oldMatrix)
{
	if (sizeX != oldMatrix.getSizeX() || sizeY != oldMatrix.getSizeY())throw std::invalid_argument("Matrix have difrennce size");
	MyMatrix newMatrix(sizeX, sizeY);
	for (int i = 0; i < oldMatrix.getSizeX(); i++)
	{
		for (int j = 0; j < oldMatrix.getSizeY(); j++)
		{
			newMatrix.matrix[i][j] = matrix[i][j] + oldMatrix.getElement(i, j) ;
		}
	}
	return newMatrix;
}
//********************************************************
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
//********************************************************
MyMatrix MyMatrix::operator -(MyMatrix & oldMatrix)
{
	if (sizeX != oldMatrix.getSizeX() || sizeY != oldMatrix.getSizeY())throw std::invalid_argument("Matrix have difrennce size");
	MyMatrix newMatrix(sizeX, sizeY);
	for (int i = 0; i < oldMatrix.getSizeX(); i++)
	{
		for (int j = 0; j < oldMatrix.getSizeY(); j++)
		{
			newMatrix.matrix[i][j] = matrix[i][j] - oldMatrix.getElement(i, j);
		}
	}
	return newMatrix;
}
//********************************************************
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
//********************************************************
MyMatrix MyMatrix::operator*(MyMatrix & oldMatrix)
{
	if (sizeY != oldMatrix.getSizeX())throw length_error("Wrong matrix dimension");
		MyMatrix newMatrix(sizeX, oldMatrix.getSizeY());
		for (int i = 0; i<sizeX; i++)
		{
			for (int j = 0; j<oldMatrix.getSizeY(); j++)
			{
				for (int k = 0; k<sizeY; k++)
				{
					newMatrix.matrix[i][j] = newMatrix.matrix[i][j] + (matrix[i][k] * oldMatrix.matrix[k][j]);
				}
			}
		}
		return newMatrix;
}
//********************************************************
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
//********************************************************
MyMatrix MyMatrix::operator=(MyMatrix oldMatrix)
{
	if (sizeX != oldMatrix.getSizeX() || sizeY != oldMatrix.getSizeY()) throw length_error("Wrong matrix dimension");
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			matrix[i][j] = oldMatrix.getElement(i, j);
		}
	}
	return *this;
}
//********************************************************
ostream &operator<<(ostream &stream, MyMatrix oldMatrix)
{
	stream << oldMatrix.matrixToString();
	return stream;
}
//********************************************************
HelpOverload MyMatrix::operator[](int i)
{
	HelpOverload newHelp(matrix, sizeY, i);
	return newHelp;
}
//********************************************************
std::string MyMatrix::matrixToString()
{
	string s;
	for (int i = 0; i < getSizeX(); i++)
	{
		for (int j = 0; j < getSizeY(); j++) 
		{
			s.append(std::to_string(getElement(i, j)));
		}
		s.append("\n");
	}
	return s;
}
//********************************************************