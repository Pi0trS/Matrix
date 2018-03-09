#include<iostream>
#include <exception>
#include"MyMatrix.h"
#include"HelpOverload.h"

using namespace std;
template<class R>
HelpOverload<R>::HelpOverload(R* oldMatrix, int size_, int placeRow_)
{
	onRow = oldMatrix;
	size = size_;
	placeRow = placeRow_;
}
template<class R>
int &HelpOverload<R>::operator[](int col_)
{
	if (size <= col_)throw out_of_range("out of range!!!");
	return onRow[col_];
//logic_error out_of_range
}