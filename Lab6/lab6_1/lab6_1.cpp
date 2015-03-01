// lab6_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Rational.h"


BOOST_AUTO_TEST_SUITE(Rational)

// Рациональное число по умолчанию равно 0/1
BOOST_AUTO_TEST_CASE(RationalIs0_1ByDefault)
{
	CRational const r;
	BOOST_CHECK_EQUAL(r.GetNumerator(), 0);
	BOOST_CHECK_EQUAL(r.GetDenominator(), 1);
}

// Целое число N является рациональным вида N/1
BOOST_AUTO_TEST_CASE(IntegerIsRational_N_1)
{
	{
		CRational const r(42);
		BOOST_CHECK_EQUAL(r.GetNumerator(), 42);
		BOOST_CHECK_EQUAL(r.GetDenominator(), 1);
	}

	{
		CRational const r(0);
		BOOST_CHECK_EQUAL(r.GetNumerator(), 0);
		BOOST_CHECK_EQUAL(r.GetDenominator(), 1);
	}

	{
		CRational const r(-42);
		BOOST_CHECK_EQUAL(r.GetNumerator(), -42);
		BOOST_CHECK_EQUAL(r.GetDenominator(), 1);
	}
}

// Дробное число N / M является рациональным вида N/M
BOOST_AUTO_TEST_CASE(FractionIsRational_N_M)
{
	{
		CRational const r(-42, 5);
		BOOST_CHECK_EQUAL(r.GetNumerator(), -42);
		BOOST_CHECK_EQUAL(r.GetDenominator(), 5);
	}
}

// Рациональные числа равны если равны их числители и знаменатели
BOOST_AUTO_TEST_CASE(RationalsEquality)
{
	BOOST_CHECK(CRational(2, 3) == CRational(2, 3));
	BOOST_CHECK(!(CRational(2, 3) == CRational(5, 8)));
	BOOST_CHECK(!(CRational(2, 5) == CRational(2, 3)));
	BOOST_CHECK(!(CRational(2, 3) == CRational(1, 3)));
}

// Рациональные числа не равны если не равны их числители
// либо не равны их знаменатели
BOOST_AUTO_TEST_CASE(RationalsInequality)
{
	BOOST_CHECK(!(CRational(2, 3) != CRational(2, 3)));
	BOOST_CHECK(CRational(2, 3) != CRational(5, 8));
	BOOST_CHECK(CRational(2, 5) != CRational(2, 3));
	BOOST_CHECK(CRational(2, 3) != CRational(1, 3));
}

// Сложение дробей с несократимыми знаменателями
BOOST_AUTO_TEST_CASE(Sum1)
{
	BOOST_CHECK(CRational(1, 2) + CRational(1, 3) == CRational(5, 6));
	CRational r(1, 2);
	// Оператор += возвращает ссылку на левый операнд
	BOOST_CHECK_EQUAL(&(r += CRational(1, 3)), &r);
	// Результат должен быть сохранен в левом операнде
	BOOST_CHECK(r == CRational(5, 6));
}

BOOST_AUTO_TEST_CASE(SelfAddition)
{
	CRational r(2);
	r += r;
	BOOST_CHECK(r == CRational(4));
}

BOOST_AUTO_TEST_CASE(ComputeGcd)
{
	BOOST_CHECK_EQUAL(GCD(6, 8), 2);
	BOOST_CHECK_EQUAL(GCD(0, 8), 8);
	BOOST_CHECK_EQUAL(GCD(0, 0), 0);
	BOOST_CHECK_EQUAL(GCD(3, 5), 1);
	BOOST_CHECK_EQUAL(GCD(1, 1), 1);
	BOOST_CHECK_EQUAL(GCD(3, 3), 3);
	BOOST_CHECK_EQUAL(GCD(1, 5), 1);
	BOOST_CHECK_EQUAL(GCD(3, 1), 1);
}

//рациональные числа хранятся в виде несократимых дробей с натуральным знаменателем
BOOST_AUTO_TEST_CASE(RationalsAreNormalizedAfterCreation)
{
	{
		CRational r(6, 8);
		BOOST_CHECK_EQUAL(r.GetNumerator(), 3);
		BOOST_CHECK_EQUAL(r.GetDenominator(), 4);
	}

	{
		CRational r(6, -8);
		BOOST_CHECK_EQUAL(r.GetNumerator(), -3);
		BOOST_CHECK_EQUAL(r.GetDenominator(), 4);
	}

	{
		CRational r(-6, 8);
		BOOST_CHECK_EQUAL(r.GetNumerator(), -3);
		BOOST_CHECK_EQUAL(r.GetDenominator(), 4);
	}

	{
		CRational r(-6, -8);
		BOOST_CHECK_EQUAL(r.GetNumerator(), 3);
		BOOST_CHECK_EQUAL(r.GetDenominator(), 4);
	}

	{
		CRational r(-10, 20);
		BOOST_CHECK_EQUAL(r.GetNumerator(), -1);
		BOOST_CHECK_EQUAL(r.GetDenominator(), 2);
	}
}

BOOST_AUTO_TEST_CASE(DenominatorMustNotBeZero)
{
	BOOST_CHECK_THROW((CRational(0, 0)), std::invalid_argument);
	BOOST_CHECK_THROW((CRational(1, 0)), std::invalid_argument);
}

// После сложения результат нормализован
BOOST_AUTO_TEST_CASE(AdditionResultIsNormalized)
{
	BOOST_CHECK((CRational(1, 2) += CRational(1, 6)) == CRational(2, 3));
	BOOST_CHECK((CRational(1, 2) + CRational(1, 6)) == CRational(2, 3));
}

BOOST_AUTO_TEST_CASE(Multiplication)
{
	CRational r(2, 5);
	// Оператор *= возвращает ссылку на левый операнд
	BOOST_CHECK_EQUAL(&(r *= CRational(5, 4)), &r);
	// Результат должен быть сохранен в левом операнде
	BOOST_CHECK(r == CRational(1, 2));
	BOOST_CHECK((CRational(-2, 5) * CRational(5, 4)) == CRational(-1, 2));
}

BOOST_AUTO_TEST_CASE(AdditionWithInteger)
{
	BOOST_CHECK(CRational(1, 2) + 1 == CRational(3, 2));
	BOOST_CHECK(1 + CRational(1, 2) == CRational(3, 2));
}

BOOST_AUTO_TEST_CASE(MultiplicationWithInteger)
{
	BOOST_CHECK(CRational(1, 2) * 3 == CRational(3, 2));
	BOOST_CHECK(3 * CRational(1, 2) == CRational(3, 2));
}

BOOST_AUTO_TEST_CASE(UnarPlusMinus)
{
	BOOST_CHECK(CRational(-1, 2) == -CRational(1, 2));
	BOOST_CHECK(CRational( 1, 2) == +CRational(1, 2));
	BOOST_CHECK(CRational(0) == -CRational(0));
}

BOOST_AUTO_TEST_CASE(BinarMinus)
{
	BOOST_CHECK((CRational(2, 3) - CRational(1, 3)) == CRational(1, 3));
	BOOST_CHECK((CRational(5, 3) - CRational(1)) == CRational(2, 3));
	BOOST_CHECK((CRational(0) - CRational(1, 3)) == CRational(-1, 3));
	BOOST_CHECK((CRational(1) - CRational(1, 3)) == CRational(2, 3));
	BOOST_CHECK((CRational(1, 2) - CRational(1, 2)) == CRational(0));
	CRational r(41, 42);
	BOOST_CHECK(std::addressof(r -= CRational(1, 2)) == std::addressof(r));
	BOOST_CHECK(r == CRational(10, 21));
}

BOOST_AUTO_TEST_CASE(Division)
{
	BOOST_CHECK((CRational(1, 2) / CRational(1, 2)) == CRational(1));
	CRational r(2, 5);
	BOOST_CHECK_EQUAL(&(r /= CRational(5, 4)), &r);
	BOOST_CHECK(r == CRational(8, 25));
	BOOST_CHECK((CRational(-2, 5) / CRational(5, 4)) == CRational(-8, 25));
}

BOOST_AUTO_TEST_CASE(Less)
{
	BOOST_CHECK(CRational(1, 3) < CRational(2, 3));
	BOOST_CHECK(!(CRational(2, 3) < CRational(1, 3)));
	BOOST_CHECK(!(CRational(1, 3) < CRational(1, 3)));
	BOOST_CHECK(CRational(1, 3) < CRational(2, 5));
}

BOOST_AUTO_TEST_CASE(More)
{
	BOOST_CHECK(CRational(2, 3) > CRational(1, 3));
	BOOST_CHECK(!(CRational(1, 3) > CRational(2, 3)));
	BOOST_CHECK(!(CRational(1, 3) > CRational(1, 3)));
	BOOST_CHECK(CRational(2, 5) > CRational(1, 3));
}

BOOST_AUTO_TEST_CASE(LessOrEqual)
{
	BOOST_CHECK(CRational(1, 3) <= CRational(2, 3));
	BOOST_CHECK(!(CRational(2, 3) <= CRational(1, 3)));
	BOOST_CHECK((CRational(1, 3) <= CRational(1, 3)));
	BOOST_CHECK(CRational(1, 3) <= CRational(2, 5));
}

BOOST_AUTO_TEST_CASE(MoreOrEqual)
{
	BOOST_CHECK(CRational(2, 3) >= CRational(1, 3));
	BOOST_CHECK(!(CRational(1, 3) >= CRational(2, 3)));
	BOOST_CHECK((CRational(1, 3) >= CRational(1, 3)));
	BOOST_CHECK(CRational(2, 5) >= CRational(1, 3));
}

BOOST_AUTO_TEST_CASE(OutputStream)
{
	std::stringstream ss;
	CRational r(1, 3);
	ss << r;
	BOOST_CHECK_EQUAL(ss.str(), "1/3");
}

BOOST_AUTO_TEST_CASE(OutputStreamDenominatorIs1)
{
	std::stringstream ss;
	CRational r(3);
	ss << r;
	BOOST_CHECK_EQUAL(ss.str(), "3");
}

BOOST_AUTO_TEST_CASE(InputStream)
{
	CRational r;
	std::stringstream ss;
	ss << "1/3";
	ss >> r;
	BOOST_CHECK(r == CRational(1, 3));
}

BOOST_AUTO_TEST_CASE(InputStreamDenominatorIs1)
{
	CRational r;
	std::stringstream ss;
	ss << "3";
	ss >> r;
	BOOST_CHECK(r == CRational(3));
}

BOOST_AUTO_TEST_SUITE_END()
