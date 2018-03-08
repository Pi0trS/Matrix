#include<iostream>
#include <exception>
#include"MyMatrix.h"
#include"HelpOverload.h"

using namespace std;

HelpOverload::HelpOverload(int* oldMatrix, int size_, int placeRow_)
{
	onRow = oldMatrix;
	size = size_;
	placeRow = placeRow_;
}

int &HelpOverload::operator[](int col_)
{
	if (size <= col_)throw out_of_range("out of range!!!");
	return onRow[col_];
//logic_error out_of_range
}