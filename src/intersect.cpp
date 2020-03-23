#include "intersect.h"

int Intersect::read_line(std::string& s)
{
	std::istringstream iss(s);
	char type;
	double input[10];
	int i = 0;
	iss >> type;
	if (type == 'C') {
		while (iss >> input[i]) {
			i++;
		}
		if (i != 3)throw format_error();
		add_object(type, input[0], input[1], input[2]);
	}
	else if (type == 'L' || type == 'R' || type == 'S') {
		while (iss >> input[i]) {
			i++;
		}
		if (i != 4)throw format_error();
		add_object(type, input[0], input[1], input[2], input[3]);
	}
	else throw format_error();
	return 0;
}

void Intersect::read_from_file(const char* file_in, const char* file_out)
{

	std::ifstream fin;
	std::ofstream fout;
	fin.open(file_in);
	fout.open(file_out);
	int n;
	std::string s;
	try
	{
		if (!(fin >> n)) throw format_error();
		getline(fin, s);
		for (int i = 0; i < n; i++) {
			getline(fin, s);
			read_line(s);
		}
	}
	catch (const same_point_error s_error)
	{
		fout << s_error.error_mesg();
		exit(0);
	}
	catch (const Inf_intersection_error i_error)
	{
		fout << i_error.error_mesg();
		exit(0);
	}
	catch (const out_index_error o_error)
	{
		fout << o_error.error_mesg();
		exit(0);
	}
	catch (const format_error f_error) {
		fout << f_error.error_mesg();
		exit(0);
	}
	fout << point_set.size();
	fin.close();
	fout.close();
}

void Intersect::read_from_console()
{
	int n;
	std::string s;
	std::cin >> n;
	getline(std::cin,s);
	for (int i = 0; i < n; i++) {
		try
		{
			getline(std::cin, s);
			read_line(s);
		}
		catch (const same_point_error s_error)
		{
			std::cout << s_error.error_mesg() << std::endl;
			i--;
			continue;
		}
		catch (const Inf_intersection_error i_error)
		{
			std::cout << i_error.error_mesg() << std::endl;
			i--;
			continue;
		}
		catch (const out_index_error o_error)
		{
			std::cout << o_error.error_mesg() << std::endl;
			i--;
			continue;
		}
	}
	std::cout << point_set.size();
}

void Intersect::add_object(char type, double x1, double y1, double x2, double y2)
{
	Point p1(x1, y1);
	Point p2(x2, y2);
	if (p1 == p2)throw(same_point_error());
	Line* l;

	if (type == 'L') {
		l = new Line(p1, p2);
	}
	else if (type == 'R') {
		l = new Ray(p1, p2);
	}
	else {
		l = new Seg(p1, p2);
	}
	find_add(l, line_list, point_set);
	find_add(l, circle_list, point_set);
	line_list.push_back(l);
}

void Intersect::add_object(char type, double x1, double y1, double r)
{
	Point p1(x1, y1);
	Circle* circle = new Circle(p1, r);
	find_add(circle, line_list, point_set);
	find_add(circle, circle_list, point_set);
	circle_list.push_back(circle);
}


void Intersect::delete_object(char type, double x1, double y1, double x2, double y2)
{
	std::vector<Line*>::iterator line_it;
	for (line_it = line_list.begin(); line_it != line_list.end(); line_it++) {
		Line* l = *line_it;
		Point start_p(x1, y1);
		Point end_p(x2, y2);
		if (start_p == end_p)throw(same_point_error());
		if (l->get_type() == type && l->get_start_point() == start_p && l->get_end_point() == end_p) {
			line_list.erase(line_it);
			find_delete(l, line_list, point_set);
			find_delete(l, circle_list, point_set);
			return;
		}
	}
	throw(no_delete_object_error());
}


void Intersect::delete_object(char type, double x1, double y1, double r)
{
	std::vector<Circle*>::iterator circle_it;

	for (circle_it = circle_list.begin(); circle_it != circle_list.end(); circle_it++) {
		Circle* c = *circle_it;
		Point o(x1, y1);
		if (c->get_o() == o && c->get_r() == r) {
			circle_list.erase(circle_it);
			find_delete(c, line_list, point_set);
			find_delete(c, circle_list, point_set);
			return;
		}
	}
	throw(no_delete_object_error());
}

std::vector<std::pair<double, double>> Intersect::get_point_gui() const
{
	std::vector<std::pair<double, double>> point_gui_list;
	std::set<Point>::iterator it;
	for (it = point_set.begin(); it != point_set.end(); it++){
		Point p = *it;
		point_gui_list.push_back(std::make_pair(p.get_x(), p.get_y()));
	}
	return point_gui_list;
}

void Intersect::print_intersect()
{
	std::cout << "#########################" << std::endl;
	print_point();
	print_line();
	print_circle();
}


void Intersect::print_line()
{
	for (unsigned int i = 0; i < line_list.size(); i++) {
		std::cout << line_list[i]->info()<< std::endl;
	}
}

void Intersect::print_circle()
{
	for (unsigned int i = 0; i < circle_list.size(); i++) {
		std::cout << circle_list[i]->info() << std::endl;
	}
}

void Intersect::print_point()
{
	std::set<Point>::iterator it;
	for (it = point_set.begin(); it != point_set.end(); it++) {
		Point p = *it;
		std::cout << p;
	}
}
