#pragma once
#include <iostream>

unsigned GCD(unsigned x, unsigned y);

class CRational
{
public:

	CRational(int numerator = 0, int denominator = 1);

	// ���������� ���������
	int GetNumerator()const;

	// ���������� �����������
	int GetDenominator()const;

	// ���������� ��������� ��������� � ����������� � ���� ����� double
	double ToDouble()const;
	
	bool operator==(CRational const & rhs)const;
	bool operator!=(CRational const & rhs)const;

	bool operator<(CRational const & rhs)const;
	bool operator<=(CRational const & rhs)const;
	
	bool operator>(CRational const & rhs)const;
	bool operator>=(CRational const & rhs)const;

	//������� +
	const CRational operator+ () const;
	//������� -
	const CRational operator-() const;

	CRational& operator+=(CRational const & rhs);
	CRational& operator-=(CRational const & rhs);

	CRational& operator*=(CRational const & rhs);
	CRational& operator/=(CRational const & rhs);

private:
	void Assign(int numerator, int denominator);

	int m_numerator;
	int m_denominator;

};


// �������� + *
CRational const operator+(CRational lhs, CRational const & rhs);
CRational const operator-(CRational lhs, CRational const & rhs);
// �������� - /
CRational const operator*(CRational lhs, CRational const & rhs);
CRational const operator/(CRational lhs, CRational const & rhs);

std::ostream& operator<<(std::ostream & ost, CRational const & rhs);
std::istream& operator>>(std::istream & ist, CRational & rhs);