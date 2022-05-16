#pragma once
#include <string>
using namespace std;

class Student
{
private:
	string name;
	double MathGrade;
	double PhysicsGrade;
	double OOPGrade;
public:
	string getName()const { return name; }
	double getMath_G()const { return MathGrade; }
	double getPhysics_G()const { return PhysicsGrade; }
	double getOOP_G()const { return OOPGrade; }

	void setName(string value) { name = value; }
	void setMath_G(double value) { MathGrade = value; }
	void setPhysics_G(double value) { PhysicsGrade = value; }
	void setOOP_G(double value) { OOPGrade = value; }

	Student(string n, double m, double p, double o);
	Student();
	Student(const Student& s);

	operator string() const;

	Student& operator =(Student& s);
	friend ostream& operator << (ostream&, const Student&);
	friend istream& operator >> (istream&, Student&);

};

