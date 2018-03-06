#pragma once
#include<iostream>
#include"MyMatrix.h"

using namespace std;

class  HelpOverload
{
public:
	HelpOverload(int** oldMatrix, int size_, int placeRow_);
	int operator[](int col);	
	int **onRow;
	int size, placeRow;
};