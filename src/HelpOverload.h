#pragma once
#include<iostream>
#include"MyMatrix.h"

using namespace std;
template<class H>
class  HelpOverload
{
public:
	HelpOverload(H* oldMatrix, int size_, int placeRow_);
	int& operator[](int col);	
	int *onRow;
	H *testOnRow;
	int size, placeRow;
};
//#include"MyMatrix.cpp"//dziwne
