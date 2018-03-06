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
		oko1[0][12] = 2;
		cout  << oko1[0][1212122];
		cout << "helll0";
		return 0;
	}
	catch (const std::logic_error& e)
	{
		std::cout << e.what();
	}
	cout << "koniec";
}