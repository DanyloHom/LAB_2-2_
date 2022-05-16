#include "List.h"
#include <iostream>
#include <sstream>
using namespace std;

int List::getCount() const
{
	return count;
}

bool List::Init(string n, double m, double p, double o, int i)
{
	if ((m >= 0 && m <= 5) && (p >= 0 && p <= 5) && (o >= 0 && o <= 5)) {
		this->p[i].setName(n);
		this->p[i].setMath_G(m);
		this->p[i].setPhysics_G(p);
		this->p[i].setOOP_G(o);

		return true;
	}
	else
		return false;
}


List::List()
{
	count = 0;
	p = new Student[count];
}

List::List(int count)
{
	this->count = count;
	p = new Student[count];
}

List::List(List& l)
{
	count = l.count;
	delete[]p;
	p = new Student[count];
	for (int i = 0; i < count; i++) {
		p[i] = l.p[i];
	}
	delete[]l.p;
}

List::~List()
{
	delete[]p;
}

List& List::operator=(List& l)
{
	count = l.count;
	delete[]p;
	p = new Student[count];
	for (int i = 0; i < count; i++) {
		p[i] = l.p[i];
	}

	return *this;
}

List& List::operator+(Student& s)
{
	int alt = count + 1;
	Student* tmp = new Student[alt];

	for (int i = 0; i < count; i++) {
		tmp[i] = p[i];
	}

	tmp[count + 1] = s;

	delete[]p;
	p = new Student[alt];

	for (int i = 0; i < alt; i++) {
		p[i] = tmp[i];
	}

	count = alt;

	delete[]tmp;

	return *this;
}

List& List::operator+=(Student& s)
{
	Student* tmp;
	int alt = count + 1;
	tmp = new Student[alt];

	for (int i = 0; i < count; i++) {
		tmp[i+1] = p[i];
	}

	tmp[0] = s;

	delete[]p;
	p = new Student[alt];

	for (int i = 0; i < alt; i++) {
		p[i] = tmp[i];
	}

	delete[]tmp;

	count++;

	return *this;
}

List& List::operator-(int value)
{
	if (value >= 0 && value <= count) {
		int alt = count - 1;
		Student* tmp = new Student[alt];

		for (int i = 0; i < value; i++) {
			tmp[i] = p[i];
		}

		for (int i = value; i < alt; i++) {
			tmp[i] = p[i + 1];
		}

		delete[]p;
		p = new Student[alt];

		for (int i = 0; i < alt; i++) {
			p[i] = tmp[i];
		}

		count = alt;

		delete[]tmp;
	}

	return *this;
}

bool List::operator==(List& l)
{
	return count == l.count;
}

bool List::operator!=(List& l)
{
	return count != l.count;
}

bool List::operator>(List& l)
{
	return count > l.count;
}

bool List::operator<(List& l)
{
	return count < l.count;
}

bool List::operator>=(List& l)
{
	return count >= l.count;
}

bool List::operator<=(List& l)
{
	return count <= l.count;
}

Student& List::operator[](int ind)
{
	return p[ind];
}

void List::operator++()
{
	p++;
}

void List::operator--()
{
	p--;
}

void List::operator()(int l, int r)
{
	if (l >= 0 && r >= 0 && l <= count && r <= count && r > l) {
		for (int i = l; i < r; i++)
			cout << p[i];
	}
}




List::operator string() const
{
	stringstream ss;
	int max = getCount();
	for (int i = 0; i > max; i++) {
		ss << p[i];
	}

	return ss.str();
}

ostream& operator<<(ostream& out, const List& s)
{
	int max = s.getCount();
	for (int i = 0; i < max; i++) {
		out << s.p[i];
	}

	return out;
}

istream& operator>>(istream& in, List& s)
{
	int max = s.getCount();
	double m, p, o;
	string n;

	for (int i = 0; i < max; i++) {
		do {
			Student student = s.p[i];

			n = student.getName();
			cout << "Student`s name is " << endl; in >> n;

			m = student.getMath_G();
			cout << "Math Grade = " << endl;	  in >> m;

			p = student.getPhysics_G();
			cout << "Physics Grade = " << endl;   in >> p;

			o = student.getOOP_G();
			cout << "OOP Grade = " << endl;       in >> o;
		} while (!s.Init(n, m, p, o, i));
	}

	return in;
}
