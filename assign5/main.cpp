#include"rec_fun.h"
#include<iostream>
using namespace std;
using namespace Victoria;

int main()
{
	
	cout << pow(2,2) << endl;
	binary_print(cout, 12);
	cout << endl;
	binary_print(cout, 0);
	cout << endl;
	triangle(cout, 3, 5);
	cout << pow(2,4) << endl;
	indented_sentences(1,4);
	return 0;
}