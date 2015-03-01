#pragma once
#include <iostream>

unsigned GCD(unsigned x, unsigned y);

class CRational
{
public:

	CRational(int numerator = 0, int denominator = 1);

	// ¬озвращаем числитель
	int GetNumerator()const;

	// ¬озвращаем знаменатель
	int GetDenominator()const;
	
	bool operator==(CRational const & rhs)const;
	bool operator!=(CRational const & rhs)const;

	bool operator<(CRational const & rhs)const;
	bool operator<=(CRational const & rhs)const;
	
	bool operator>(CRational const & rhs)const;
	bool operator>=(CRational const & rhs)const;

	//унарный +
	const CRational operator+ () const;
	//унарный -
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


// бинарный + *
CRational const operator+(CRational lhs, CRational const & rhs);
CRational const operator-(CRational lhs, CRational const & rhs);
// бинарный - /
CRational const operator*(CRational lhs, CRational const & rhs);
CRational const operator/(CRational lhs, CRational const & rhs);

std::ostream& operator<<(std::ostream & ost, CRational const & rhs);
std::istream& operator>>(std::istream & ist, CRational & rhs);