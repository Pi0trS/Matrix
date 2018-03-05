#include<iostream>
using namespace std;
#include"MyMatrix.h"


int main()
{
	try
	{
		MyMatrix oko(2, 2);
		oko.showMatrix();
		oko.setValue(0, 0, 3);
		MyMatrix oko1(2, 4);
		oko1.setValue(0, 0, 3);
		MyMatrix oko2((oko * oko1));
		oko2.showMatrix();
		cout << "helll0";
		return 0;
	}
	catch (const std::logic_error& e)
	{
		std::cout << e.what();
	}
	cout << "koniec";
}