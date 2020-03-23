#ifndef MATH_H
#define MATH_H
#include <ostream>
#include <iostream>
#include<fstream>
#include <algorithm>
#include <functional>	
#include<string>
#include <set>
#include <vector>
#include<sstream>

class Point;
class Line;
class Circle;
class Ray;
class Seg;
class Inf_intersection_error;

class Point {
	double x_;
	double y_;
public:
	Point(double x, double y);
	Point();
	double get_x()const;
	double get_y()const;
	double distance(const Point& point)const;
	bool operator==(const Point& point) const;
	bool operator<(const Point& point) const;  //	以x大小排序
	Point operator+(const Point& point) const;
	Point operator-(const Point& point) const;
	Point operator*(const double& d) const;
	Point operator/(const double& d) const;
	friend void operator<<(std::ostream &os,  Point &point);
};

typedef Point Vector;



class Line {
protected:
	double a;
	double b;
	double c;
	char type;
	Point start_point;
	Point end_point;
	Vector direction;
public:
	Line(const Point& p1, const  Point& p2);
	Line(const double& a_, const double& b_, const Point &point);
	double get_a()const;
	double get_b()const;
	double get_c()const;
	char get_type()const;
	Point get_start_point();
	Point get_end_point();
	//	点在线上
	virtual bool contain(const Point& p)const;
	//	线的信息
	virtual const std::string info()const;
	//	方向向量
	Vector get_directionVector()const;
	//	线线重合
	bool coincide(const Line& line)const;
	//	线线交点
	int find_intersection(const Line &line, Point *p) const; 
	//	圆线交点
	int find_intersection(const Circle& circle, Point* p) const;	
	//	判断交点是否在line的边界里	
};

class Circle {
	Point o;
	double r;
public:
	Circle(const Point& point, const double r_);
	Circle();
	int find_intersection(const Line& line , Point *p)const;
	int find_intersection(const Circle& circle, Point* p)const;
	double get_r()const;
	Point get_o()const;
	const std::string info()const;
};


class Ray:public Line {
public:
	Ray(const Point& p1, const  Point& p2) :Line(p1, p2) { type = 'R'; };
	virtual bool contain(const Point& p)const;
	virtual const std::string info()const;
};

class Seg :public Line {
public:
	Seg(const Point& p1, const  Point& p2) :Line(p1, p2) { type = 'S'; };
	virtual bool contain(const Point& p)const;
	virtual const std::string info()const;
};


class Inf_intersection_error{
private:
	enum errorType
	{
		ll = 1,	//	线线无限交点
		cc = 2	//	圆圆无限交点
	};
	std::string object1;
	std::string object2;
	int type;
public:
	Inf_intersection_error(const Line& l_1, const Line& l_2) { object1 = l_1.info(); object2 = l_2.info(); type = ll; };
	Inf_intersection_error(const Circle& c_1,const Circle& c_2){ object1 = c_1.info(); object2 = c_2.info(); type = cc; };
	const std::string error_mesg()const;
};

class same_point_error {
public:
	const std::string error_mesg()const;
};

class no_delete_object_error {
public:
	const std::string error_mesg()const;
};

class out_index_error {
public:
	const std::string error_mesg()const;
};

class format_error {
public:
	const std::string error_mesg()const;
};

bool equal(const double& a, const double& b);



#endif