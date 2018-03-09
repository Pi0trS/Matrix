#include<iostream>
#include<string>
using namespace std;
#include"MyMatrix.h"
#include"MyMatrix.cpp"
int main()
{
	try
	{
		MyMatrix <int> oko(2, 2);
		//cout << oko.getElement(0, 0);
		oko.setValue(0, 0, 3);
		oko[0][0] = 1;
		cout << oko.getElement(0, 0);
		//MyMatrix<int> oko1(2, 2);
		//oko1 = oko*oko;

		//cout << endl;
		//oko[0][0] = 1;
		//cout << oko[0][0];
		//cout << "helll0";
		return 0;
	}
	catch (const std::logic_error& e)
	{
		std::cout << e.what();
	}
	cout << "koniec";
}
