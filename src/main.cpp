#include<iostream>
#include<string>
using namespace std;
#include"MyMatrix.h"
//#include"MyMatrix.cpp"
int main()
{
	int i = 1;
	try
	{
		
		MyMatrix <double> oko(2, 2);
		MyMatrix<double> oko1(2, 3);
		MyMatrix<double> oko2(2, 3);
		//cout << oko.getElement(0, 0);
		//oko.setValue(0, 0, 3);
		oko = oko + 3;
		oko1 = oko1 + 23;
		//oko = oko / 2;
		oko2 = (oko * oko1);
		//cout << oko.getElement(0, 0);
		//oko.showMatrix();
		cout << oko2;
		//string s = oko.matrixToString();
		//cout << s;
		//oko1 = oko*oko;
		//cout << endl;
		//oko[0][0] = 1;
		//cout << oko[0][0];
		//cout << "helll0";
	}
	catch (const std::logic_error& e)
	{
		std::cout << e.what();
	}
	cout << "koniec";
	cin >> i;
	return 0;
}
