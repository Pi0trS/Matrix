#pragma once
#include<iostream>
#include <exception>
#include"MyMatrix.h"

using namespace std;
template<class H>
class  HelpOverload
{
public:
	HelpOverload(H* oldMatrix, int size_, int placeRow_);
	H& operator[](int col);	
	int *onRow;
	H *testOnRow;
	int size, placeRow;
};


template<class H>
HelpOverload<H>::HelpOverload(H* oldMatrix, int size_, int placeRow_)
{
	testOnRow = oldMatrix;
	size = size_;
	placeRow = placeRow_;
}
template<class H>
H &HelpOverload<H>::operator[](int col_)
{
	if (size <= col_)throw out_of_range("out of range!!!");
	return testOnRow[col_];
}