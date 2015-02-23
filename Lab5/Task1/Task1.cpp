#include "stdafx.h"
#include "Body.h"
#include "Cone.h"
#include "Cylinder.h"
#include "Parallelepiped.h"
#include "Sphere.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

const double G = 9.18;
const double P = 1000;

typedef shared_ptr<CBody> CBodyPointer;

CBodyPointer CreateSphere(istream & ist)
{
	double radius, density;
	ist >> radius >> density;
	return make_shared<CSphere>(radius, density);
}

CBodyPointer CreateParallelepiped(istream & ist)
{
	double width, height, depth, density;
	ist >> width >> height >> depth >> density;
	return make_shared<CParallelepiped>(width, height, depth, density);
}

CBodyPointer CreateCone(istream & ist)
{
	double radius, height, density;
	ist >> radius >> height >> density;
	return make_shared<CCone>(radius, height, density);
}

CBodyPointer CreateCylinder(istream & ist)
{
	double radius, height, density;
	ist >> radius >> height >> density;
	return make_shared<CCylinder>(radius, height, density);
}

CBodyPointer CreateComplex(istream & ist)
{
	return nullptr;
}

CBodyPointer LoadShape(istream & ist)
{
	string name;
	ist >> name;
	if (name == "sphere")
	{
		return CreateSphere(ist);
	}
	else if (name == "parallelepiped")
	{
		return CreateParallelepiped(ist);
	}
	else if (name == "cone")
	{
		return CreateCone(ist);
	}
	else if (name == "cylinder")
	{
		return CreateCylinder(ist);
	}
	else if (name == "compound")
	{
		return CreateComplex(ist);
	}
	else
	{
		return nullptr;
	}
}

void LoadShapes(vector<CBodyPointer> & shapes, istream & ist){
	CBodyPointer shape = LoadShape(ist);
	while (shape != nullptr)
	{
		shapes.push_back(shape);
		shape = LoadShape(ist);
	}
}

void PrintShapes(vector<CBodyPointer> & shapes, ostream & ost){
	for (auto & shape : shapes) {
		ost << shape->ToString() << endl;
	}
}

bool CompareWeight(CBodyPointer shape1, CBodyPointer shape2)
{
	return shape1->GetMass() < shape2->GetMass();
}

bool CompareWeightInWater(CBodyPointer shape1, CBodyPointer shape2)
{
	double p1, p2;
	p1 = (shape1->GetDensity() - P) * G * shape1->GetVolume();
	p2 = (shape2->GetDensity() - P) * G * shape2->GetVolume();
	return p1 < p2;
}


int main(int argc, char * argv[])
{
	vector<CBodyPointer> shapes;
	LoadShapes(shapes, cin);

	PrintShapes(shapes, cout);

	cout << endl;

	if (shapes.empty())
	{
		cout << "Shapes list is empty" << endl;
	}
	else
	{
		auto maxMassBody = max_element(shapes.begin(), shapes.end(), CompareWeight);
		auto minWeightInWater = min_element(shapes.begin(), shapes.end(), CompareWeightInWater);
		cout << "Body with max mass: " << (*maxMassBody)->ToString() << endl;
		cout << "Body with min weight in water: " << (*minWeightInWater)->ToString() << endl;
	}

	return 0;
}