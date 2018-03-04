#include<iostream>
using namespace std;
#include"MyMatrix.h"


int main()
{
	try
	{
		MyMatrix oko(2, 2);
		MyMatrix oko1((oko + 2));
		MyMatrix oko2(oko1);

		oko / 0;
		oko1.showMatrix();
		oko.showMatrix();
		oko2.showMatrix();
		cout << "helll0";
		return 0;
	}
	catch (logic_error e)
	{
		std::cout << e.what() << " -> ";
	}
}