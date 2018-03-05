#include<iostream>
#include<string>
using namespace std;
#include"MyMatrix.h"


int main()
{
	try
	{
		MyMatrix oko(2, 2);
		oko.setValue(0, 0, 3);
		MyMatrix oko1(2, 2);
		oko1 = oko*oko;

		cout << endl;
		cout  << oko1;
		cout << "helll0";
		return 0;
	}
	catch (const std::logic_error& e)
	{
		std::cout << e.what();
	}
	cout << "koniec";
}