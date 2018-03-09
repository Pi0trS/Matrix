#pragma once
#include<iostream>
#include"MyMatrix.h"

using namespace std;
template<class R>
class  HelpOverload
{
public:
	HelpOverload(R* oldMatrix, int size_, int placeRow_);
	int& operator[](int col);	
	R *onRow;
	int size, placeRow;
};
#include"MyMatrix.cpp"//dziwne
