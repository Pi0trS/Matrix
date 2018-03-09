#include<iostream>
#include <exception>
#include"MyMatrix.h"
#include"HelpOverload.h"

using namespace std;
template<class H>
//HelpOverload<H>::HelpOverload(int* oldMatrix, int size_, int placeRow_)
HelpOverload<H>::HelpOverload(H* oldMatrix, int size_, int placeRow_)
{
	//onRow = oldMatrix;
	testOnRow = oldMatrix;
	size = size_;
	placeRow = placeRow_;
}
template<class H>
int &HelpOverload<H>::operator[](int col_)
{
	if (size <= col_)throw out_of_range("out of range!!!");
	//return onRow[col_];
	return testOnRow[col_];
//logic_error out_of_range
}