#include <iostream>
#include <string>
#include <exception>
#include "HelpOverload.cpp"
#include "MyMatrix.h"

using namespace std;

template<class T>
MyMatrix<T>::MyMatrix(int x, int y)
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
template<class T>
MyMatrix<T>::MyMatrix(const MyMatrix & a)
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
template<class T>
int MyMatrix<T>::getSizeX()
{ 
	return sizeX;
}

template<class T>
int MyMatrix<T>::getSizeY()
{
	return sizeY;
}
template<class T>
 int MyMatrix<T>::getElement(int x, int y)
{
	return matrix[x][y];
}
 template<class T>
void MyMatrix<T>::showMatrix()
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
template<class T>
void MyMatrix<T>::setValue(int x, int y ,int toSet)
{
	if (x >= sizeX || y >= sizeY)throw out_of_range("out of range!!!");
	matrix[x][y] = toSet;
}
//********************************************************
template<class T>
MyMatrix<T> MyMatrix<T>::coppyMatrix(MyMatrix toCoppy)
{
	 MyMatrix newMatrix(toCoppy.sizeX, toCoppy.sizeY);
	 for (int i = 0; i < toCoppy.sizeX; i++)
	 {
		 for (int j = 0; j < toCoppy.sizeY; j++)
		 {
			newMatrix.setValue(i,j, toCoppy.getElement(i,j));
		 }
	 }
	 return newMatrix;
}
//********************************************************
template<class T>
MyMatrix<T> operator +(MyMatrix<T> oldMatrix, int a)
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
template<class T>
MyMatrix<T> MyMatrix<T>::operator+(MyMatrix & oldMatrix)
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
template<class T>
MyMatrix<T> operator -(MyMatrix<T> oldMatrix, int a)
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
template<class T>
MyMatrix<T> MyMatrix<T>::operator -(MyMatrix & oldMatrix)
{
	if (sizeX != oldMatrix.getSizeX() || sizeY != oldMatrix.getSizeY())throw std::invalid_argument("Matrix have difrennce size");
	MyMatrix newMatrix(sizeX, sizeY);
	for (int i = 0; i < oldMatrix.getSizeX(); i++)
	{
		for (int j = 0; j < oldMatrix.getSizeY(); j++)
		{
			newMatrix.matrix[i][j] =  getElement(i,j) - oldMatrix.getElement(i, j);
		}
	}
	return newMatrix;
}
//********************************************************
template<class T>
MyMatrix<T> operator *(MyMatrix<T> oldMatrix, int a)
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
template<class T>
MyMatrix<T> MyMatrix<T>::operator*(MyMatrix & oldMatrix)
{
	if (sizeY != oldMatrix.getSizeX())throw length_error("Wrong matrix dimension");
		MyMatrix newMatrix(sizeX, oldMatrix.getSizeY());
		for (int i = 0; i<sizeX; i++)
		{
			for (int j = 0; j<oldMatrix.getSizeY(); j++)
			{
				for (int k = 0; k<sizeY; k++)
				{
					newMatrix.matrix[i][j] = newMatrix.matrix[i][j] + (getElement(i,k) * oldMatrix.getElement(k, j));
				}
			}
		}
		return newMatrix;
}
//********************************************************
template<class T>
MyMatrix<T> operator /(MyMatrix<T> oldMatrix, int a)
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
template<class T>
MyMatrix<T> MyMatrix<T>::operator=(MyMatrix oldMatrix)
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
template<class T>
ostream &operator<<(ostream &stream, MyMatrix<T> oldMatrix)
{
	stream << oldMatrix.matrixToString();
	return stream;
}
//********************************************************
template<class T>
HelpOverload<T> MyMatrix<T>::operator[](int i)
{
	HelpOverload<T> newHelp(matrix[i], sizeY, i);
	return newHelp;
}
//********************************************************
template<class T>
std::string MyMatrix<T>::matrixToString()
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
template<class T>
MyMatrix<T>::~MyMatrix()
{
	for (int i = 0; i < sizeX; i++)
	{
		delete matrix[i];
	}
	delete matrix;
	matrix = nullptr;
}
//********************************************************