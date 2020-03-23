#pragma once
#include"my_math.h"

class Intersect {
	std::set<Point>point_set;
	std::vector<Line*> line_list;
	std::vector<Circle*>circle_list;
	template<typename T1, typename T2>
	void find_add(T1& c, std::vector<T2>& c_list, std::set<Point>& p_set);
	template<typename T1, typename T2>
	void find_delete(T1& c, std::vector<T2>& c_list, std::set<Point>& p_set);
	int read_line(std::string &s);
public:
	//	文件读入
	void read_from_file(const char* file_in, const char* file_out);
	//	控制台读入
	void read_from_console();
	//	添加几何体
	void add_object(char type, double x1, double y1, double x2, double y2);
	void add_object(char type, double x1, double y1, double r);
	//	删除几何体
	void delete_object(char type, double x1, double y1, double x2, double y2);
	void delete_object(char type, double x1, double y1, double r);
	//	返回交点列表
	std::vector<std::pair<double, double>> get_point_gui()const;
	//	打印intersect内部信息
	void print_intersect();
	void print_line();
	void print_circle();
	void print_point();
};

template<typename T1, typename T2>
inline void Intersect::find_add(T1& c, std::vector<T2>& c_list, std::set<Point>& p_set)
{
	for (unsigned int i = 0; i < c_list.size(); i++) {
		Point p[2];
		int n;
		n = (*c_list[i]).find_intersection(*c, p);
		if (n == 0)continue;
		else if (n == 1) {
			p_set.insert(p[0]);
		}
		else {
			p_set.insert(p[0]);
			p_set.insert(p[1]);
		}
	}
}

template<typename T1, typename T2>
inline void Intersect::find_delete(T1& c, std::vector<T2>& c_list, std::set<Point>& p_set)
{
	for (unsigned int i = 0; i < c_list.size(); i++) {
		Point p[2];
		int n;
		n = (*c_list[i]).find_intersection(*c, p);
		if (n == 0)continue;
		else if (n == 1) {
			p_set.erase(p[0]);
		}
		else {
			p_set.erase(p[0]);
			p_set.erase(p[1]);
		}
	}
}
