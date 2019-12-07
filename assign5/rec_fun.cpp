//PROVIDED BY: _________Xing Yang_______
//              __________xyang004@citymail.cuny.edu____________


#include<assert.h>
#include"rec_fun.h"
#include<iostream>
using namespace std;

namespace Victoria{
	void binary_print(ostream& outs, unsigned int n){
		if(n <= 1){
			outs << n;
			return;
		}
		binary_print(outs, n/2);
		outs << n%2;
	}
	void triangle(ostream& outs, unsigned int m, unsigned int n){
		assert(m <= n);
		for(int x = 0; x < m; x++){
			outs << "*";
		}
		outs << endl;
		if (m == n){
			for(int x = 0; x < m; x++){
				outs << "*";
			}
			outs << endl;
		}
		else{
			triangle(outs, m+1, n);
			for(int x = 0; x < m; x++){
				outs << "*";
			}
			outs << endl;	
		}
	}

	double pow(double x, int n){
		assert( x != 0 || (n > 0 && x == 0));
		if(x == 0){
			return 0;
		}
		else if(n == 0){
			return 1;
		}
		else if(n == 1){
			return x;
		}
		else if(n < 0) return 1/pow(x,-n);
		if(n%2 == 0){
			double tmp = pow(x,n/2);
			return tmp * tmp;
		}
		else{
			double tmp = pow(x,(n+1)/2);
			return tmp * tmp / x;
		}
	}

	void indented_sentences(size_t m, size_t n){
		assert(m <= n);
		for(int x = 0; x < m-1; x++){
			cout << " ";
		}
		cout << "This was written by calling number " << m << endl;		
		if (m == n){
			for(int x = 0; x < m-1; x++){
				cout << " ";
			}
			cout << "This was ALSO written by calling number " << m << endl;
			return;
		}
		indented_sentences(m+1, n);
		for(int x = 0; x < m-1; x++){
			cout << " ";
		}
		cout << "This was ALSO written by calling number " << m << endl;

	}
}