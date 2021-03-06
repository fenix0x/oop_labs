// Task2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Rectangle.h"
#include "Canvas.h"
#include <string>
#include <fstream>
#include <exception>
#include <iostream>
#include <iomanip>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

using namespace std; 
using namespace boost;

void ProcessCommand(ifstream & ifs, CRectangle & rect, string const & command)
{
	if (command == "rectangle")
	{
		int left, top, width, height;
		ifs >> left >> top >> width >> height;
		rect.SetLeft(left);
		rect.SetTop(top);
		rect.SetWidth(width);
		rect.SetHeight(height);
	}
	else if (command == "move")
	{
		int dx, dy;
		ifs >> dx >> dy;
		rect.Move(dx, dy);
	}
	else if (command == "scale")
	{
		int sx, sy;
		ifs >> sx >> sy;
		rect.Scale(sx, sy);
	}
	else
	{
		throw logic_error("Unknown command " + command);
	}
}

CRectangle CreateRectangleFromFile(string filename)
{
	CRectangle rect(0, 0, 0, 0);
	ifstream ifs(filename);
	if (!ifs)
	{
		throw runtime_error("Can't open file " + filename);
	}
	string command;
	while (ifs >> command)
	{
		trim(command);
		to_lower(command);
		ProcessCommand(ifs, rect, command);
	}
	return rect;
}

void ShowRectangleInfo(CRectangle rect, string title)
{
	cout << title << ":\n";
	cout << "\tLeft top:\t(" << rect.GetLeft() << "; " << rect.GetTop() << ")\n";
	cout << "\tSize:\t\t" << rect.GetWidth() << " x " << rect.GetHeight() << "\n";
	cout << "\tRight bottom:\t(" << rect.GetRight() << "; " << rect.GetBottom() << ")\n";
	cout << "\tArea:\t\t" << rect.GetArea() << "\n";
	cout << "\tPerimeter:\t" << rect.GetPerimeter() << "\n";
}

unsigned CanvasCoord(int value)
{
	return (value < 0) ? 0 : (unsigned)value;
}

void PutRectangle2Canvas(CRectangle const& rect, char code, CCanvas & canvas)
{
	for (unsigned y = CanvasCoord(rect.GetTop()); y < CanvasCoord(rect.GetBottom()); ++y)
	{
		for (unsigned x = CanvasCoord(rect.GetLeft()); x < CanvasCoord(rect.GetRight()); ++x)
		{
			canvas.SetPixel(x, y, code);
		}
	}
}

void ShowRectangleCanvas(string const& filename, CCanvas const& canvas)
{
	if (filename.empty())
	{
		canvas.Write(cout);
	}
	else
	{
		ofstream output(filename);
		canvas.Write(output);
		output.close();
	}
}

int main(int argc, char * argv[])
{
	if (argc < 3)
	{
		cout << "Usage: rectangle <file1> <file2>\n";
		return 1;
	}

	try
	{
		CRectangle rect1 = CreateRectangleFromFile(argv[1]);
		CRectangle rect2 = CreateRectangleFromFile(argv[2]);
		CCanvas canvas(60, 20);

		ShowRectangleInfo(rect1, "First file rectangle");
		PutRectangle2Canvas(rect1, '+', canvas);
		ShowRectangleInfo(rect2, "Second file rectangle");
		PutRectangle2Canvas(rect2, '-', canvas);

		rect1.Intersect(rect2);
		ShowRectangleInfo(rect1, "Intersection rectangle");
		PutRectangle2Canvas(rect1, '#', canvas);

		ShowRectangleCanvas((argc > 3) ? argv[3] : "", canvas);
	}
	catch (logic_error const & e)
	{
		cout << e.what() << endl;
		return 1;
	}
	catch (runtime_error const & e)
	{
		cout << e.what() << endl;
		return 1;
	}
	return 0;
}