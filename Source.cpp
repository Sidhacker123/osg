#include <iostream>
#include<vector>
#include <cmath>
#include <osg/Geometry>
#include <osg/Geode>
#include <osg/Point>
#include <osgViewer/Viewer>
using namespace std;

struct Point
{
	double x;
	double y;
	double z;
};

void displayPoints(vector<Point>& pointG, vector<Point>& pointR, vector<Point>& pointAns)
{
	cout << "sis";
	osg::ref_ptr<osg::Vec3Array> polygonVertices = new osg::Vec3Array;
	osg::ref_ptr<osg::Vec3Array> insideVertices = new osg::Vec3Array;
	//osg::ref_ptr<osg::Vec3Array> onsideVertices = new osg::Vec3Array;
	osg::ref_ptr<osg::Vec3Array> outsideVertices = new osg::Vec3Array;
	osg::ref_ptr<osg::Vec3Array> normals = new osg::Vec3Array;
	osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;
	osg::ref_ptr<osg::Vec4Array> colors1 = new osg::Vec4Array;
	//osg::ref_ptr<osg::Vec4Array> colors3 = new osg::Vec4Array;
	osg::ref_ptr<osg::Vec4Array> colors2 = new osg::Vec4Array;
	for (int i = 0; i < pointG.size(); i++)
	{
		polygonVertices->push_back(osg::Vec3(pointG[i].x, pointG[i].y, pointG[i].z));
		colors->push_back(osg::Vec4(0.0f, 0.0f, 1.0f, 1.0f));
	}
	for (int i = 0; i < pointR.size(); i++)
	{
		insideVertices->push_back(osg::Vec3(pointR[i].x, pointR[i].y, pointR[i].z));
		colors1->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f));
	}

	for (int i = 0; i < pointAns.size(); i++)
	{
		outsideVertices->push_back(osg::Vec3(pointAns[i].x, pointAns[i].y, pointAns[i].z));
		colors2->push_back(osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f));
	}

	normals->push_back(osg::Vec3(0.0f, -1.0f, 0.0f));


	/* colors->push_back(osg::Vec4(0.0f, 1.0f, 1.0f, 1.0f));
	 colors->push_back(osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f));*/


	osg::ref_ptr<osg::Geometry> quad = new osg::Geometry;
	quad->setVertexArray(polygonVertices.get());
	quad->setNormalArray(normals.get());
	quad->setNormalBinding(osg::Geometry::BIND_OVERALL);
	quad->setColorArray(colors.get());
	quad->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
	osg::ref_ptr<osg::Point> pointSize = new osg::Point;
	pointSize->setSize(10.f);
	quad->getOrCreateStateSet()->setAttribute(pointSize,
		osg::StateAttribute::ON);
	quad->addPrimitiveSet(new osg::DrawArrays(GL_LINE_LOOP, 0, pointG.size()));

	osg::ref_ptr<osg::Geometry> quad1 = new osg::Geometry;
	quad1->setVertexArray(insideVertices.get());
	quad1->setNormalArray(normals.get());
	quad1->setNormalBinding(osg::Geometry::BIND_OVERALL);
	quad1->setColorArray(colors.get());
	quad1->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
	osg::ref_ptr<osg::Point> pointSize1 = new osg::Point;
	pointSize1->setSize(20.f);
	quad1->getOrCreateStateSet()->setAttribute(pointSize,
		osg::StateAttribute::ON);
	quad1->addPrimitiveSet(new osg::DrawArrays(GL_LINE_LOOP, 0, pointR.size()));

	osg::ref_ptr<osg::Geometry> quad2 = new osg::Geometry;
	quad2->setVertexArray(outsideVertices.get());
	quad2->setNormalArray(normals.get());
	quad2->setNormalBinding(osg::Geometry::BIND_OVERALL);
	quad2->setColorArray(colors.get());
	quad2->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
	osg::ref_ptr<osg::Point> pointSize2 = new osg::Point;
	pointSize2->setSize(20.f);
	quad2->getOrCreateStateSet()->setAttribute(pointSize,
		osg::StateAttribute::ON);
	quad2->addPrimitiveSet(new osg::DrawArrays(GL_LINE_LOOP, 0, pointAns.size()));



	osg::ref_ptr<osg::Geode> root = new osg::Geode;
	root->addDrawable(quad.get());
	//osg::ref_ptr<osg::Geode> root1 = new osg::Geode;
	root->addDrawable(quad1.get());
	//root->addDrawable(insidePoints.get());
	root->addDrawable(quad2.get());
	osgViewer::Viewer viewer;
	viewer.setSceneData(root.get());
	viewer.run();

}
double anglex(Point Y) {
	double val = (Y.x * Y.x) + (Y.y * Y.y) + (Y.z * Y.z);
	double val1 = sqrt(val);
	double val2 = Y.x / val1;
	double angleX = acos(val2);
	angleX = angleX * (180 / 3.1415);
	return angleX;
}

double angley(Point Y) {
	double val = (Y.x * Y.x) + (Y.y * Y.y) + (Y.z * Y.z);
	double val1 = sqrt(val);
	double val2 = Y.y / val1;
	double angleY = acos(val2);
	angleY = angleY * (180 / 3.1415);
	return angleY;
}
double anglez(Point Y) {
	double val = (Y.x * Y.x) + (Y.y * Y.y) + (Y.z * Y.z);
	double val1 = sqrt(val);
	double val2 = Y.z / val1;
	double angleZ = acos(val2);
	angleZ = angleZ * (180 / 3.1415);
	return angleZ;
}
double anglexg(Point X) {
	double val = (X.x * X.x) + (X.y * X.y) + (X.z * X.z);
	double val1 = sqrt(val);
	double val2 = X.x / val1;
	double angleX = acos(val2);
	angleX = angleX * (180 / 3.1415);
	return angleX;
}

double angleyg(Point X) {
	double val = (X.x * X.x) + (X.y * X.y) + (X.z * X.z);
	double val1 = sqrt(val);
	double val2 = X.y / val1;
	double angleY = acos(val2);
	angleY = angleY * (180 / 3.1415);
	return angleY;
}
double anglezg(Point X) {
	double val = (X.x * X.x) + (X.y * X.y) + (X.z * X.z);
	double val1 = sqrt(val);
	double val2 = X.z / val1;
	double angleZ = acos(val2);
	angleZ = angleZ * (180 / 3.1415);
	return angleZ;
}

void rotatex(Point& X, Point Y, double angleDX) {
	angleDX = angleDX * 3.14159 / 180;
	double sinV = sin(angleDX);
	double cosV = cos(angleDX);
	//cout << X.z * cosV << " angle " << sinV << " " << cosV <<" "<< X.y * sinV << endl;
	double temp = X.y;
	X.y = (X.y * cosV) - (X.z * sinV);
	X.z = (temp * sinV) + (X.z * cosV);
	//cout << X.y << " rotx " << X.z << endl;
	//X.y = round(X.y);
	//X.z = round(X.z);
	//cout << X.y << " rotx " << X.z << endl;
}
void rotatey(Point& X, Point Y, double angleDY) {
	angleDY = angleDY * 3.14159 / 180;
	double sinV = sin(angleDY);
	double cosV = cos(angleDY);
	//cout << " roty" << sinV << "sin  cos" << cosV<<endl;
	double temp = X.x;
	X.x = (X.x * cosV) + (X.z * sinV);
	X.z = (X.z * cosV) - (temp * sinV);
	//X.x = round(X.x);
	//X.z = round(X.z);
	//cout << X.x << " "<<X.z;
}
void rotatez(Point& X, Point Y, double angleDZ) {
	angleDZ = angleDZ * 3.14159 / 180;
	double sinV = sin(angleDZ);
	double cosV = cos(angleDZ);
	double temp = X.x;
	X.x = (X.x * cosV) - (X.y * sinV);
	X.y = (temp * sinV) + (X.y * cosV);
	//X.y = round(X.y);
	//X.x = round(X.x);
}

int main()
{
	double a, b, c, d, e, f, g, h, i, j, k, l;
	vector<Point> pointG;
	vector<Point> pointR;
	vector<Point> pointAns;
	cout << "Enter the initial co-ordinates of the given line";
	cin >> a >> b >> c;
	Point R = { a,b,c };
	pointG.push_back(R);
	pointAns.push_back(R);
	cout << "Enter the final co-ordinates of the given line";
	cin >> d >> e >> f;
	R = { d,e,f };
	pointG.push_back(R);
	a = d - a;
	b = e - b;
	c = f - c;
	Point X = { a,b,c }; //to rotate

	cout << "Enter the initial co-ordinates of the ref line";
	cin >> g >> h >> i;
	R = { g,h,i };
	pointR.push_back(R);
	//pointAns.push_back(R);
	cout << "Enter the final co-ordinates of the ref line";
	cin >> j >> k >> l;
	R = { j,k,l };
	pointR.push_back(R);
	j = j - g;
	k = k - h;
	l = l - i;

	Point Y = { j,k,l }; //ref

	double anY = anglex(Y);
	double anX = anglexg(X);
	//cout << anY << " angle " << anX;
	anY = round(anY);
	anX = round(anX);
	if (anY != anX) {
		double del = anX - anY;
		del = abs(del);
		rotatey(X, Y, del);
		double aa = anglex(Y);
		double bb = anglexg(X);
		aa = round(aa);
		bb = round(bb);
		if (aa != bb) {
			del = 360 - (2 * del);
			rotatey(X, Y, del);
			aa = anglex(Y);
			bb = anglexg(X);
			aa = round(aa);
			bb = round(bb);
			if (aa != bb) {
				del = anX - anY;
				del = abs(del);
				rotatey(X, Y, del);
			}
		}
	}
	if (anY != anX) {
		double del = anX - anY;
		del = abs(del);
		rotatez(X, Y, del);
		double aa = anglex(Y);
		double bb = anglexg(X);
		aa = round(aa);
		bb = round(bb);
		if (aa != bb) {
			del = 360 - (2 * del);
			rotatez(X, Y, del);
			aa = anglex(Y);
			bb = anglexg(X);
			aa = round(aa);
			bb = round(bb);
			if (aa != bb) {
				del = anX - anY;
				del = abs(del);
				rotatez(X, Y, del);
			}
		}
	}

	cout << X.y << " y Angle with XX  z " << X.z << endl;


	anY = angley(Y);
	anX = angleyg(X);
	anY = round(anY);
	anX = round(anX);
	//cout << anY << "  angle " << anX;
	if (anY != anX) {
		double del = anX - anY;
		del = abs(del);
		cout << "angle is" << del << endl;
		rotatex(X, Y, del);
		cout << X.y << " y 2y  z " << X.z << endl;
		double aa = angley(Y);
		double bb = angleyg(X);
		aa = round(aa);
		bb = round(bb);
		cout << aa << " vv " << bb << endl;
		if (aa != bb) {
			del = 360 - (2 * del);
			cout << "angle is" << del << endl;
			rotatex(X, Y, del);
			aa = angley(Y);
			bb = angleyg(X);
			aa = round(aa);
			bb = round(bb);
			if (aa != bb) {
				del = aa - bb;
				del = abs(del);
				cout << "angle is" << del << endl;
				rotatex(X, Y, del);
			}
		}
	}
	if (anY != anX) {
		double del = anX - anY;
		del = abs(del);
		cout << "angle is" << del << endl;
		rotatez(X, Y, del);
		cout << X.y << " y 2y  z " << X.z << endl;
		double aa = angley(Y);
		double bb = angleyg(X);
		aa = round(aa);
		bb = round(bb);
		if (aa != bb) {
			del = 360 - (2 * del);
			cout << "angle is" << del << endl;
			rotatez(X, Y, del);
			if (angley(Y) != angleyg(X)) {
				del = anX - anY;
				del = abs(del);
				cout << "angle is" << del << endl;
				rotatez(X, Y, del);
			}
		}
	}
	cout << "angle with y over" << endl;

	anY = anglez(Y);
	anX = anglezg(X);
	anY = round(anY);
	anX = round(anX);
	//cout << anY << "  angle " << anX;
	if (anY != anX) {
		double del = anX - anY;
		del = abs(del);
		cout << "angle is" << del << endl;
		rotatex(X, Y, del);
		cout << X.y << "y 3z  z" << X.z << endl;
		double aa = anglez(Y);
		double bb = anglezg(X);
		aa = round(aa);
		bb = round(bb);
		if (aa != bb) {
			del = 360 - (2 * del);
			rotatex(X, Y, del);
			aa = anglez(Y);
			bb = anglezg(X);
			aa = round(aa);
			bb = round(bb);
			if (aa != bb) {
				del = anX - anY;
				del = abs(del);
				rotatex(X, Y, del);
			}
		}
	}
	if (anY != anX) {
		double del = anX - anY;
		del = abs(del);
		cout << "angle is" << del << endl;
		rotatey(X, Y, del);
		cout << X.y << "y 3z  z" << X.z << endl;
		double aa = anglez(Y);
		double bb = anglezg(X);
		aa = round(aa);
		bb = round(bb);
		if (aa != bb) {
			del = 360 - (2 * del);
			rotatey(X, Y, del);
			aa = anglez(Y);
			bb = anglezg(X);
			aa = round(aa);
			bb = round(bb);
			if (aa != bb) {
				del = anX - anY;
				del = abs(del);
				rotatey(X, Y, del);
			}
		}
	}

	//cout << X.x<<"x   "<<X.y << " y final  z " << X.z;
	R = { X.x,X.y,X.z };
	pointAns.push_back(R);
	cout << X.x << " " << X.y << " " << X.z;
	displayPoints(pointG, pointR, pointAns);

}