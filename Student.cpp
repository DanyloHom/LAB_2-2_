#include "Student.h"
#include <iostream>
#include <sstream>
using namespace std;

Student::Student(string n, double m, double p, double o)
{
	if (name != "" && (m > 0 && m <= 5) && (p > 0 && p <= 5) && (o > 0 && o <= 5)) {
		name = n;
		MathGrade = m;
		PhysicsGrade = p;
		OOPGrade = o;
	}
	else Student();
}

Student::Student()
{
	setName("Vasyl Pupkin");
	setMath_G(0);
	setPhysics_G(0);
	setOOP_G(0);
}

Student::Student(const Student& s)
{
	setName(s.getName());

	setMath_G(s.getMath_G());
	setPhysics_G(s.getPhysics_G());
	setOOP_G(s.getOOP_G());
}

Student::operator string() const
{
	stringstream ss;
	ss << "Student`s name is " << name << endl
		<< "Math Grade = " << MathGrade << endl
		<< "Physics Grade = " << PhysicsGrade << endl
		<< "OOP Grade = " << OOPGrade << endl;

	return ss.str();
}

Student& Student::operator=(Student& s)
{
	setName(s.getName());
	setMath_G(s.getMath_G());
	setPhysics_G(s.getPhysics_G());
	setOOP_G(s.getOOP_G());

	return *this;
}

ostream& operator<<(ostream& out, const Student& s)
{
	out << "Student`s name is " << s.name << endl
		<< "Math Grade = " << s.MathGrade << endl
		<< "Physics Grade = " << s.PhysicsGrade << endl
		<< "OOP Grade = " << s.OOPGrade << endl;

	return out;
}

istream& operator>>(istream& in, Student& s)
{
	cout << "Student`s name is " << endl; in >> s.name;
	cout << "Math Grade = " << endl;	  in >> s.MathGrade;
	cout << "Physics Grade = " << endl;   in >> s.PhysicsGrade;
	cout << "OOP Grade = " << endl;       in >> s.OOPGrade;

	return in;
}
