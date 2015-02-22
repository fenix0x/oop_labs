#include "stdafx.h"
#include <sstream>
#include <string>
#include "../Task2/Rectangle.h"
#include "../Task2/Canvas.h"

using namespace std;

bool CheckRectProps(const CRectangle & rect, int left, int top, int right, int bottom, int width, int height, int perimeter, int area)
{
	return ((rect.GetLeft() == left)
	&& (rect.GetTop() == top)
	&& (rect.GetRight() == right)
	&& (rect.GetBottom() == bottom)
	&& (rect.GetWidth() == width)
	&& (rect.GetHeight() == height)
	&& (rect.GetPerimeter() == perimeter)
	&& (rect.GetArea() == area));
}

BOOST_AUTO_TEST_SUITE(TestCreateRectangle)

BOOST_AUTO_TEST_CASE(TestCreationOfRectangle)
{
	CRectangle rect(10, 10, 10, 10);
	BOOST_CHECK(CheckRectProps(rect, 10, 10, 20, 20, 10, 10, 40, 100));
}

BOOST_AUTO_TEST_CASE(TestCreateRectangleWithNegativeWidth)
{
	CRectangle rect1(10, 10, -10, 10);
	BOOST_CHECK(CheckRectProps(rect1, 10, 10, 10, 20, 0, 10, 20, 0));
	CRectangle rect2(10, 10, 10, -10);
	BOOST_CHECK(CheckRectProps(rect2, 10, 10, 20, 10, 10, 0, 20, 0));
}

BOOST_AUTO_TEST_SUITE_END()

struct TestRectangleFixture
{
	CRectangle rect = CRectangle(10, 20, 15, 25);
};

BOOST_FIXTURE_TEST_SUITE(TestRectangle, TestRectangleFixture)

BOOST_AUTO_TEST_CASE(TestSetWidth)
{
	BOOST_CHECK(CheckRectProps(rect, 10, 20, 25, 45, 15, 25, 80, 375));
	rect.SetWidth(20);
	BOOST_CHECK(CheckRectProps(rect, 10, 20, 30, 45, 20, 25, 90, 500));
	rect.SetWidth(-10);
	BOOST_CHECK(CheckRectProps(rect, 10, 20, 30, 45, 20, 25, 90, 500));
}

BOOST_AUTO_TEST_CASE(TestSetHeight)
{
	BOOST_CHECK(CheckRectProps(rect, 10, 20, 25, 45, 15, 25, 80, 375));
	rect.SetHeight(30);
	BOOST_CHECK(CheckRectProps(rect, 10, 20, 25, 50, 15, 30, 90, 450));
	rect.SetHeight(-10);
	BOOST_CHECK(CheckRectProps(rect, 10, 20, 25, 50, 15, 30, 90, 450));
}

BOOST_AUTO_TEST_CASE(TestSetTop)
{
	//BOOST_CHECK(CheckRectProps(rect, 10, 20, 25, 45, 15, 25, 80, 375));
	rect.SetTop(50);
	BOOST_CHECK(CheckRectProps(rect, 10, 50, 25, 75, 15, 25, 80, 375));
}

BOOST_AUTO_TEST_CASE(TestSetLeft)
{
	//BOOST_CHECK(CheckRectProps(rect, 10, 20, 25, 45, 15, 25, 80, 375));
	rect.SetLeft(0);
	BOOST_CHECK(CheckRectProps(rect, 0, 20, 15, 45, 15, 25, 80, 375));
}

BOOST_AUTO_TEST_CASE(TestSetRight)
{
	//BOOST_CHECK(CheckRectProps(rect, 10, 20, 25, 45, 15, 25, 80, 375));
	rect.SetRight(40);
	BOOST_CHECK(CheckRectProps(rect, 10, 20, 40, 45, 30, 25, 110, 750));
}

BOOST_AUTO_TEST_CASE(TestSetBottom)
{
	//BOOST_CHECK(CheckRectProps(rect, 10, 20, 25, 45, 15, 25, 80, 375));
	rect.SetBottom(40);
	BOOST_CHECK(CheckRectProps(rect, 10, 20, 25, 40, 15, 20, 70, 300));
}

BOOST_AUTO_TEST_CASE(TestMoveRectangle)
{
	//BOOST_CHECK(CheckRectProps(rect, 10, 20, 25, 45, 15, 25, 80, 375));
	rect.Move(10, 10);
	BOOST_CHECK(CheckRectProps(rect, 20, 30, 35, 55, 15, 25, 80, 375));
}

BOOST_AUTO_TEST_CASE(TestMoveNegative)
{
	//BOOST_CHECK(CheckRectProps(rect, 10, 20, 25, 45, 15, 25, 80, 375));
	rect.Move(-10, -10);
	BOOST_CHECK(CheckRectProps(rect, 0, 10, 15, 35, 15, 25, 80, 375));
}

BOOST_AUTO_TEST_CASE(TestScaleRectangle)
{
	//BOOST_CHECK(CheckRectProps(rect, 10, 20, 25, 45, 15, 25, 80, 375));
	rect.Scale(2, 2);
	BOOST_CHECK(CheckRectProps(rect, 10, 20, 40, 70, 30, 50, 160, 1500));
}


BOOST_AUTO_TEST_CASE(TestNegativeScaleRectangle)
{
	//BOOST_CHECK(CheckRectProps(rect, 10, 20, 25, 45, 15, 25, 80, 375));
	rect.Scale(-2, -2);
	BOOST_CHECK(CheckRectProps(rect, 10, 20, 25, 45, 15, 25, 80, 375));
}

BOOST_AUTO_TEST_SUITE_END()

struct TestIntersectRectangleFixture
{
	CRectangle rect1 = CRectangle(0, 0, 10, 10);
};

BOOST_FIXTURE_TEST_SUITE(TestIntersectRectangle, TestIntersectRectangleFixture)

BOOST_AUTO_TEST_CASE(TestNonIntersectRectangle)
{
	//BOOST_CHECK(CheckRectProps(rect1, 0, 0, 10, 10, 10, 10, 40, 100));
	CRectangle rect2 = CRectangle(11, 11, 10, 10);
	BOOST_CHECK(!rect1.Intersect(rect2));
	BOOST_CHECK(CheckRectProps(rect1, 0, 0, 0, 0, 0, 0, 0, 0));
}

BOOST_AUTO_TEST_CASE(TestIntersectionRectangleBottomRight)
{
	//BOOST_CHECK(CheckRectProps(rect1, 0, 0, 10, 10, 10, 10, 40, 100));
	CRectangle rect2(8, 8, 10, 10);
	rect1.Intersect(rect2);
	BOOST_CHECK(CheckRectProps(rect1, 8, 8, 10, 10, 2, 2, 8, 4));
}

BOOST_AUTO_TEST_CASE(TestIntersectionRectangleTopLeft)
{
	//BOOST_CHECK(CheckRectProps(rect1, 0, 0, 10, 10, 10, 10, 40, 100));
	CRectangle rect2(-8, -8, 10, 10);
	rect1.Intersect(rect2);
	BOOST_CHECK(CheckRectProps(rect1, 0, 0, 2, 2, 2, 2, 8, 4));
}

BOOST_AUTO_TEST_CASE(TestIntersectionRectangleBottomLeft)
{
	//BOOST_CHECK(CheckRectProps(rect1, 0, 0, 10, 10, 10, 10, 40, 100));
	CRectangle rect2(-8, 8, 10, 10);
	rect1.Intersect(rect2);
	BOOST_CHECK(CheckRectProps(rect1, 0, 8, 2, 10, 2, 2, 8, 4));
}

BOOST_AUTO_TEST_SUITE_END();

struct CanvasTestFixture
{
	CCanvas canvas = CCanvas(10, 20);
};

BOOST_FIXTURE_TEST_SUITE(CanvasTest, CanvasTestFixture)

BOOST_AUTO_TEST_CASE(TestCanvasSize)
{
	BOOST_CHECK_EQUAL(canvas.GetWidth(), 10);
	BOOST_CHECK_EQUAL(canvas.GetHeight(), 20);
}

BOOST_AUTO_TEST_CASE(TestSetCanvasPixel)
{
	canvas.SetPixel(0, 0, 'x');
	BOOST_CHECK_EQUAL(canvas.GetPixel(0, 0), 'x');
	canvas.SetPixel(1, 1, 0x10);
	BOOST_CHECK_EQUAL(canvas.GetPixel(1, 1), ' ');
}

BOOST_AUTO_TEST_CASE(TestOutOfRangePixel)
{
	BOOST_CHECK_EQUAL(canvas.GetPixel(30, 30), ' ');
}

BOOST_AUTO_TEST_CASE(TestFillCanvas)
{
	canvas.Clear('x');
	BOOST_CHECK_EQUAL(canvas.GetPixel(0, 0), 'x');
	BOOST_CHECK_EQUAL(canvas.GetPixel(5, 5), 'x');
	BOOST_CHECK_EQUAL(canvas.GetPixel(9, 19), 'x');
	canvas.Clear();
	BOOST_CHECK_EQUAL(canvas.GetPixel(0, 0), ' ');
	BOOST_CHECK_EQUAL(canvas.GetPixel(5, 5), ' ');
	BOOST_CHECK_EQUAL(canvas.GetPixel(9, 19), ' ');
	canvas.Clear(0x10);
	BOOST_CHECK_EQUAL(canvas.GetPixel(0, 0), ' ');
	BOOST_CHECK_EQUAL(canvas.GetPixel(5, 5), ' ');
	BOOST_CHECK_EQUAL(canvas.GetPixel(9, 19), ' ');
}

BOOST_AUTO_TEST_CASE(TestWirteCanvas)
{
	stringstream ss;
	canvas.Clear('x');
	canvas.SetPixel(0, 0, '!');
	canvas.SetPixel(3, 0, '!');
	canvas.Write(ss);
	string first;
	ss >> first;
	BOOST_CHECK_EQUAL(first, "!xx!xxxxxx");
}

BOOST_AUTO_TEST_SUITE_END();