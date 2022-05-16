#include<iostream>
#include "List.h"
#include "Student.h"
using namespace std;

int main()
{
	List A(1);

	List B(1);

	cout << "List a = " << endl;
	cin >> A;
	cout << A;

	cout << "List b = " << endl;
	cin >> B;
	cout << B;

	if (A == B) {
		cout << "a == b" << endl;
	}
	if (A > B) {
		cout << "a > b" << endl;
	}
	if (A < B) {
		cout << "a < b" << endl;
	}
	if (A != B) {
		cout << "a != b" << endl;
	}
	if (A <= B) {
		cout << "a  <= b" << endl;
	}
	if (A >= B) {
		cout << "a >= b" << endl;
	} 

	Student a;
	cout << "enter information for new student : " << endl;
	cin >> a;
	List C;
	A += a;
	C = A; 
	cout << "this student was added to a-List : " << endl;
	cout << C;
	cout << "this student will deleted from a-List : " << endl;
	C - 0;
	cout << C;

	List D(5);
	int l, r;
	cout << "List d = " << endl;
	cin >> D;
	cout << "now i`ll show you all students of d-List" << endl;
	cout << D;
	cout << "enter from which to which position would you like to review d-List" << endl;
	cin >> l;
	cin >> r;
	D(l, r);



}