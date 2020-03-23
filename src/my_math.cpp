#include "my_math.h"
#define max(a,b) a>=b?a:b
#define min(a,b) a<=b?a:b
double eps = 0.00000001;

Point::Point(double x, double y) {
	x_ = x;
	y_ = y;
}
Point::Point()
{
	x_ = INFINITY;
	y_ = INFINITY;
}
bool Point::operator==(const Point& point) const 
{
	if (x_ == point.x_ && y_ == point.y_)
		return true;
	if (equal(x_, point.x_) && equal(y_, point.y_))
	{
		return true;
	}
	return false;
}

bool Point::operator<(const Point& point) const
{
	if (equal(x_, point.x_) && equal(y_, point.y_)) {
		return false;
	}
	if (!equal(x_, point.x_)) {
		return x_ < point.x_;
	}
	else {
		return y_ < point.y_;
	}
}

Point Point::operator+(const Point& point) const
{	
	return Point(x_ + point.x_, y_ + point.y_);
}

Point Point::operator-(const Point& point) const
{
	return Point(x_ - point.x_, y_ - point.y_);
}

Point Point::operator*(const double& d) const
{
	return Point(x_ * d, y_ * d);
}

Point Point::operator/(const double& d) const
{
	return Point(x_ / d, y_ / d);
}

double Point::get_x()const {
	return x_;
}
 
double Point::get_y()const {
	return y_;
}

double Point::distance(const Point& point) const
{
	return sqrt(pow((x_ - point.x_),2)+pow((y_ - point.y_),2));
}


void operator<<(std::ostream& os, Point& point)
{
	os << "x is " << point.x_ << " and " << " y is " << point.y_ << "\n";
}

Line::Line(const Point& p1, const Point& p2)
{
	type = 'L';
	start_point = p1;
	end_point = p2;
	double x_1 = p1.get_x();
	double y_1 = p1.get_y();
	double x_2 = p2.get_x();
	double y_2 = p2.get_y();
	a = y_2 - y_1;
	b = x_1 - x_2;
	c = x_2 * y_1 - x_1 * y_2;
	direction = (p2 - p1) / p1.distance(p2);
}

Line::Line(const double& a_, const double& b_, const Point& point)
{
	type = 'L';
	a = a_;
	b = b_;
	c = -a * point.get_x() - b * point.get_y();
	direction = Vector(b / sqrt(pow(b, 2) + pow(a, 2)), -a / sqrt(pow(b, 2) + pow(a, 2)));
	start_point = point;
	end_point = start_point + direction;
}

int Line::find_intersection(const Line& line, Point* p)const
{
	if (coincide(line)) {
		return 0;
	}
	else {
		if (b * line.a - a * line.b == 0) {
			return 0;
		}
		else {
			double x;
			double y;
			y = (a * line.c - c * line.a) / (b * line.a - a * line.b);
			if (a != 0) {
				x = (- c - b * y) / a;
			}
			else {
				x = (-line.c - line.b * y) / line.a;
			}
			p[0] = Point(x,y);
			if ((line.get_type() == 'L' || contain(p[0])) && (line.get_type() == 'L' || line.contain(p[0]))) {
				return 1;
			}
			return 0;
		}
	}
}

int Line::find_intersection(const Circle& circle, Point* p)const
{
	int n;
	n = circle.find_intersection(*this, p);
	return n;
}

bool Line::contain(const Point& p) const
{
	if (p == start_point)return 1;
	Vector v1 = (p - start_point) / p.distance(start_point);
	Vector v2 = (start_point - p) / p.distance(start_point);
	return (v1 == direction) || (v2 == direction);
}


const std::string Line::info()const
{
	std::string a;
	a += "L ";
	a += std::to_string(int(start_point.get_x())) + " " + std::to_string(int(start_point.get_y())) + " "  + std::to_string(int(end_point.get_x())) + " "+ std::to_string(int(end_point.get_y()));
	return a;
}


double Line::get_a()const
{
	return a;
}

double Line::get_b()const
{
	return b;
}
double Line::get_c()const
{
	return c;
}

char Line::get_type() const
{
	return type;
}

Point Line::get_start_point()
{
	return start_point;
}

Point Line::get_end_point()
{
	return end_point;
}

Vector Line::get_directionVector() const
{
	return Vector(b/sqrt(pow(b,2)+ pow(a, 2)), -a / sqrt(pow(b, 2) + pow(a, 2)));
}
//	两个线类重合，只要相互间有两个以上的点在另一条线上，若只有两个点则需要是不同的点
bool Line::coincide(const Line& line) const
{
	int co_amount = 0;
	Point p_list[4];
	if (contain(line.start_point))p_list[co_amount++] = line.start_point;
	if (contain(line.end_point))p_list[co_amount++] = line.end_point;
	if(line.contain(start_point))p_list[co_amount++] = start_point;
	if (line.contain(end_point))p_list[co_amount++] = end_point;
	if (co_amount > 2)return true;
	else if (co_amount == 2) {
		if (p_list[0] == p_list[1])return false;
		else return true;
	}else return false;
	
}


bool equal(const double &a, const double &b) {
	if (abs(a - b) < eps) {
		return true;
	}
	else {
		return false;
	}
}

Circle::Circle(const Point& point, const double r_)
{
	o = point;
	r = r_;
}

Circle::Circle()
{
	Point o();
	r = 0;
}

int Circle::find_intersection(const Line& line, Point* p)const
{
	int n;	//	交点个数
	Point i1;
	Vector line_vector = line.get_directionVector();	//	line 的单位向量
	Line line_h(-line.get_b(), line.get_a(), o); // 和 line 垂直且过圆心的垂线 line_h
	line_h.find_intersection(line, &i1);	// l_h 和 line 的交点 i1
	double d = i1.distance(o);	//	i1 到 圆心 o 的 距离
	double l = sqrt(pow(r, 2) - pow(d, 2));	//  sqrt(r^2 - d^2)
	Vector v = line_vector* l;
	*p = i1 + line_vector * l;
	*(p+1) = i1 - line_vector * l;

	if (d > r) {
		n = 0;
		return n;
	}
	else if (abs(d - r) <= eps) {
		if (line.get_type() == 'L' || line.contain(*p)) {
			return 1;
		}
		return 0;
	}
	else {
		Point t0 = p[0];
		Point t1 = p[1];
		n = 0;
		if (line.get_type() == 'L' || line.contain(t0)) {
			p[n++] = t0;
		}
		if (line.get_type() == 'L' || line.contain(t1)) {
			p[n++] = t1;
		}
		return n;
	}
}

int Circle::find_intersection(const Circle& circle, Point* p)const
{
	if (o == circle.o && abs(r - circle.r) < eps) {
		return 0;
	}

	//	交点个数
	int n;

	//	分大小圆
	Circle big;
	Circle small;
	if (r >= circle.r) {
		big = *this;
		small = circle;
	}
	else {
		big = circle;
		small = *this;
	}

	//	判断交点个数
	double d = big.o.distance(small.o);
	if (d > (big.r + small.r) || d < big.r - small.r) {
		n = 0;
		return n;
	}
	else if (abs(d - (big.r + small.r)) <= eps) {	//	小圆外切
		n = 1;
		Vector v1 = small.o - big.o;	//	大圆圆心射向小圆圆心的向量
		v1 = v1 * (big.r / (big.r + small.r));
		*p = big.o + v1;
		return n;
	}
	else if (abs(d - (big.r - small.r)) <= eps) {	//	小圆内切
		n = 1;
		Vector v1 = small.o - big.o;	//	大圆圆心射向小圆圆心的向量
		v1 = v1 / big.o.distance(small.o) * big.r;
		*p = big.o + v1;
		return n;
	}
	else  {	// 2个交点  d ，r1，r2形成三角形 
		n = 2;
		Vector v1 = small.o - big.o;
		v1 = v1 / big.o.distance(small.o);	//	单位向量
		double x = (pow(big.r, 2) - pow(small.r, 2) + pow(d, 2)) / (2 * d);
		v1 = v1 *  x;
		Point cross = big.o + v1;
		Line l(v1.get_x(), v1.get_y(), cross);
		big.find_intersection(l, p);
		return n;
	}
	return 0;
}

double Circle::get_r() const
{
	return r;
}

Point Circle::get_o() const
{
	return o;
}

const std::string Circle::info() const
{
	std::string a;
	a += "C ";
	a += std::to_string(int(o.get_x())) + " " + std::to_string(int(o.get_y())) + " " + std::to_string(int(r));
	return a;
}

//////////	Ray

bool Ray::contain(const Point& p) const
{
	if (p == start_point)return true;
	Vector v = (p - start_point) / p.distance(start_point);
	return (v == direction); 
}

const std::string Ray::info() const
{
	std::string a;
	a += "R ";
	a += std::to_string(int(start_point.get_x())) + " " + std::to_string(int(start_point.get_y())) + " " + std::to_string(int(end_point.get_x())) + " " + std::to_string(int(end_point.get_y()));
	return a;
}

//////////	Seg

bool Seg::contain(const Point& p) const
{
	if (p == start_point || p == end_point)return true;	//	在端点上
	Vector v = (p - start_point) / p.distance(start_point);
	double max_x = max(start_point.get_x(), end_point.get_x());
	double min_x = min(start_point.get_x(), end_point.get_x());
	return (v == direction) && (p.get_x() <= max_x) & (p.get_x() >= min_x);	//	在线上
		
}

const std::string Seg::info() const
{
	std::string a;
	a += "S ";
	a += std::to_string(int(start_point.get_x())) + " " + std::to_string(int(start_point.get_y())) + " " + std::to_string(int(end_point.get_x())) + " " + std::to_string(int(end_point.get_y()));
	return a;
}


