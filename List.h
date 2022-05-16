#pragma once
#include "Student.h"
using namespace std;
class List
{
private:
	
public:
Student* p;
	int count;
	Student* getP()const { return p; }
	int getCount() const;
	bool Init(string n, double m, double p, double o, int i);


	List();
	List(int count);
	List(List& l);
	~List();

	List& operator =(List& l);
	List& operator +(Student&);
	List& operator +=(Student&);
	List& operator -(int);

	bool operator ==(List& l);
	bool operator !=(List& l);
	bool operator >(List& l);
	bool operator <(List& l);
	bool operator >=(List& l);
	bool operator <=(List& l);

	Student& operator [](int ind);

	void operator++();
	void operator--();
	void operator()(int l, int r);

	friend ostream& operator << (ostream& out, const List& s);
	friend istream& operator >> (istream&, List&);
	operator string() const;

};

