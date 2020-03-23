#include "pch.h"
#include "CppUnitTest.h"
#include "..\c_practice\intersect.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace mymathtest
{
	TEST_CLASS(mymathtest)
	{
	public:
		TEST_METHOD(TestMethod2)	//	两线相交一点
		{
			Point p;
			int n;

			Point a1(5, 2);
			Point b1(0, -3);
			Point a2(-5, 3);
			Point b2(4, -1);

			Line l1(a1,b1);
			Line l2(a2,b2);
			n = l1.find_intersection(l2,&p);

			Point i(2.6153846153846, -0.3846153846154);
			Assert::AreEqual(1, n);
			Assert::AreEqual(true, p == i);
		}
		TEST_METHOD(TestMethod3)	//	两线相交一点
		{
			Point p;
			int n;

			Point a1(2, 2);
			Point b1(4, 4);
			Point a2(4, 2);
			Point b2(2, 6);

			Line l1(a1, b1);
			Line l2(a2, b2);
			n = l1.find_intersection(l2, &p);

			Point i(3.3333333333333, 3.3333333333333);
			Assert::AreEqual(1, n);
			Assert::AreEqual(true, p == i);
		}

		TEST_METHOD(TestMethod4)	//	两线平行
		{
			Point p;
			int n;

			Point a1(2, 2);
			Point b1(4, 8);
			Point a2(4, 2);
			Point b2(6, 8);

			Line l1(a1, b1);
			Line l2(a2, b2);
			n = l1.find_intersection(l2, &p);

			Assert::AreEqual(0, n);
		}
		TEST_METHOD(TestMethod5)	//	两线平行
		{
			Point p;
			int n;

			Point a1(-2, 0);
			Point b1(2, 6);
			Point a2(6, 2);
			Point b2(10, 8);

			Line l1(a1, b1);
			Line l2(a2, b2);
			n = l1.find_intersection(l2, &p);

			Assert::AreEqual(0, n);
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////	圆线交点
		TEST_METHOD(TestMethod7)
		{
			Point p(0,0);
			double r = 1;
			Line l1(0, 1, Point(0,1));
			Circle o1(p, r);
			int n;
			Point p_list[2];
			n = o1.find_intersection(l1,p_list);
			Assert::AreEqual(1, n);
		}

		TEST_METHOD(TestMethod8)
		{
			Point p(0, 0);
			double r = 1;
			Line l1(-1, 1, Point(0,sqrt(2)));
			Circle o1(p, r);
			int n;
			Point p_list[2];
			n = o1.find_intersection(l1, p_list);
			Assert::AreEqual(1, n);
		}
		TEST_METHOD(TestMethod9)
		{
			Line l1(-1, 1, Point(0,1));

			Point p(0, 0);
			double r = 1;
			Circle o1(p, r);

			int n;
			Point p_list[2];
			n = o1.find_intersection(l1, p_list);

			Point a(0,1);
			Point b(-1,0);
			Assert::AreEqual(2, n);
			Assert::AreEqual(true, p_list[0] == a || p_list[0] == b);
			Assert::AreEqual(true, p_list[1] == a || p_list[1] == b);
		}

		TEST_METHOD(TestMethod9_)
		{
			Line l1(2, 5, Point(0,1.2));

			Point p1(-1, 3);
			double r1 = sqrt(7);
			Circle o1(p1, r1);

			int n;
			Point p_list[2];
			n = o1.find_intersection(l1, p_list);

			Point a(-3.6223575251708, 2.6489430100683);
			Point b(0.6568402837915, 0.9372638864834);
			Assert::AreEqual(2, n);
			Assert::AreEqual(true, p_list[0] == a || p_list[0] == b);
			Assert::AreEqual(true, p_list[1] == a || p_list[1] == b);
		}

		TEST_METHOD(TestMethod9__)
		{
			Point p_1(-1, 4);
			Point p_2(4, -1);
			Line l1(p_1, p_2);

			Point p1(2, 2);
			double r1 = 1;
			Circle o1(p1, r1);

			int n;
			Point p_list[2];
			n = o1.find_intersection(l1, p_list);

			Point a(1.0, 2.0);
			Point b(2.0, 1.0);
			Assert::AreEqual(true, p_list[0] == a || p_list[0] == b);
			Assert::AreEqual(true, p_list[1] == a || p_list[1] == b);
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////	圆圆交点
		TEST_METHOD(TestMethod10)
		{
			Point p1(0, 0);
			double r1 = 1;
			Circle o1(p1, r1);

			Point p2(1, 0);
			double r2 = 1;
			Circle o2(p2, r2);

			int n;
			Point p_list[2];
			n = o1.find_intersection(o2, p_list);

			Point a(1.0/2.0, sqrt(3)/2.0);
			Point b(1.0/2.0, -sqrt(3)/2.0);
			Assert::AreEqual(2, n);
			Assert::AreEqual(true, p_list[0] == a || p_list[0] == b);
			Assert::AreEqual(true, p_list[1] == a || p_list[1] == b);
		}

		TEST_METHOD(TestMethod12)	
		{
			Point p1(-1, 3);
			double r1 = sqrt(7);
			Circle o1(p1, r1);

			Point p2(1, 2);
			double r2 = sqrt(7);
			Circle o2(p2, r2);

			int n;
			Point p_list[2];
			n = o1.find_intersection(o2, p_list);

			Point a(1.0723805294764, 4.6447610589527);
			Point b(-1.0723805294764, 0.3552389410473);
			Assert::AreEqual(2, n);
			Assert::AreEqual(true, p_list[0] == a || p_list[0] == b);
			Assert::AreEqual(true, p_list[1] == a || p_list[1] == b);
		}
		TEST_METHOD(TestMethod13)
		{
			Point p1(-1, 3);
			double r1 = sqrt(7);
			Circle o1(p1, r1);

			Point p2(2, 2);
			double r2 = sqrt(7);
			Circle o2(p2, r2);

			int n;
			Point p_list[2];
			n = o1.find_intersection(o2, p_list);

			Point a(1.1708203932499, 4.5124611797498);
			Point b(-0.1708203932499, 0.4875388202502);
			Assert::AreEqual(2, n);
			Assert::AreEqual(true, p_list[0] == a || p_list[0] == b);
			Assert::AreEqual(true, p_list[1] == a || p_list[1] == b);
		}
		TEST_METHOD(TestMethod14)
		{
			Point p1(-1, 3);
			double r1 = sqrt(7);
			Circle o1(p1, r1);

			Point p2(2*sqrt(7)-1, 3);
			double r2 = sqrt(7);
			Circle o2(p2, r2);

			int n;
			Point p_list[2];
			n = o1.find_intersection(o2, p_list);

			Point a(sqrt(7)-1, 3);
			Assert::AreEqual(1, n);
			Assert::AreEqual(true, p_list[0] == a);
		}
		TEST_METHOD(TestMethod15)
		{
			Point p1(-1, 3);
			double r1 = sqrt(7);
			Circle o1(p1, r1);

			Point p2(-1.0/2.0, 3);
			double r2 = sqrt(7)-1.0/2.0;
			Circle o2(p2, r2);

			int n;
			Point p_list[2];
			n = o1.find_intersection(o2, p_list);

			Point a(sqrt(7) - 1, 3);
			Assert::AreEqual(1, n);
			Assert::AreEqual(true, p_list[0] == a);
		}

		TEST_METHOD(TestMethod16)
		{
			Point p1(-1, 3);
			double r1 = sqrt(7);
			Circle o1(p1, r1);

			Point p2(-1.0 / 2.0, 3);
			double r2 = 10;
			Circle o2(p2, r2);

			int n;
			Point p_list[2];
			n = o1.find_intersection(o2, p_list);

			Assert::AreEqual(0, n);
		}
		// 射线 射线
		TEST_METHOD(TestMethod17)
		{
			Point p;
			int n;
			Line* l1;
			Line* l2;
			Point a1(-1, -2);
			Point b1(2, 2);
			Point a2(0, 0);
			Point b2(-3, 2);

			l1 = new Ray(a1, b1);
			l2 = new Ray(a2, b2);
			n = l1->find_intersection(*l2, &p);
		
			Assert::AreEqual(0, n);
		}
		TEST_METHOD(TestMethod18)
		{
			Point p;
			int n;
			Line* l1;
			Line* l2;
			Point a1(-2, 0);
			Point b1(4, 2);
			Point a2(4, -4);
			Point b2(2, 0);

			l1 = new Ray(a1, b1);
			l2 = new Ray(a2, b2);
			n = l1->find_intersection(*l2, &p);

			Point i(1.4285714285714, 1.1428571428571);
			Assert::AreEqual(1, n);
			Assert::AreEqual(true, p == i);
			
		}
		// 线段 线段
		TEST_METHOD(TestMethod19)
		{
			Point p;
			int n;
			Line* l1;
			Line* l2;
			Point a1(-2, 0);
			Point b1(2, 4);
			Point a2(-2, 4);
			Point b2(4, -2);

			l1 = new Seg(a1, b1);
			l2 = new Seg(a2, b2);
			n = l1->find_intersection(*l2, &p);
			Assert::AreEqual(1, n);
			Point i(0.0, 2.0);
			Assert::AreEqual(true, p == i);
			

		}

		TEST_METHOD(TestMethod20)
		{
			Point p;
			int n;
			Line* l1;
			Line* l2;
			Point a1(-2, 0);
			Point b1(2, 4);
			Point a2(2, 0);
			Point b2(4, -2);

			l1 = new Seg(a1, b1);
			l2 = new Seg(a2, b2);
			n = l1->find_intersection(*l2, &p);
			Assert::AreEqual(0, n);

		}

		//	射线 圆
		TEST_METHOD(TestMethod21)
		{

			Point p1(1, -2);
			double r1 = 3;
			Circle o1(p1, r1);

			Point p[2];
			int n;
			Line* l1;
			Point a1(2, -2);
			Point b1(4, 0);
			l1 = new Ray(a1, b1);


			n = l1->find_intersection(o1, p);

			Assert::AreEqual(1, n);
			Point i(3.5615528128088, -0.4384471871912);
			Assert::AreEqual(true, p[0] == i);
		}

		TEST_METHOD(TestMethod22)
		{

			Point p1(1, -2);
			double r1 = 3;
			Circle o1(p1, r1);

			Point p_list[2];
			int n;
			Line* l1;
			Point a1(-2, -4);
			Point b1(4, 0);
			l1 = new Ray(a1, b1);


			n = l1->find_intersection(o1, p_list);

			Assert::AreEqual(2, n);
			Point a(-1.4961508830135, -3.6641005886757);
			Point b(3.4961508830135, -0.3358994113243);
			Assert::AreEqual(true, p_list[0] == a || p_list[0] == b);
			Assert::AreEqual(true, p_list[1] == a || p_list[1] == b);
		}


		//	线段 圆
		TEST_METHOD(TestMethod23)
		{

			Point p1(1, -2);
			double r1 = 3;
			Circle o1(p1, r1);

			Point p[2];
			int n;
			Line* l1;
			Point a1(0, -2);
			Point b1(2, 0);
			l1 = new Seg(a1, b1);


			n = l1->find_intersection(o1, p);

			Assert::AreEqual(0, n);

		}

		TEST_METHOD(TestMethod24)
		{

			Point p1(1, -2);
			double r1 = 3;
			Circle o1(p1, r1);

			Point p[2];
			int n;
			Line* l1;
			Point a1(0, -2);
			Point b1(4, -2);
			l1 = new Seg(a1, b1);


			n = l1->find_intersection(o1, p);

			Assert::AreEqual(1, n);

		}

		//	test line::contain()
		TEST_METHOD(TestMethod25)
		{
			Point a1(-2, 0);
			Point b1(4, 2);
			Line l(a1, b1);

			Point i(-4, -2);
			Assert::AreEqual(false, l.contain(i));
		}
		TEST_METHOD(TestMethod26)
		{
			Point a1(-2, 0);
			Point b1(4, 2);
			Line l(a1, b1);

			Point i(-5.9848381802165, -1.3282793934055);
			Assert::AreEqual(true, l.contain(i));
		}

		//	test Ray::contain()

		TEST_METHOD(TestMethod27)
		{
			Point a1(-2, 0);
			Point b1(4, 2);
			Ray l(a1, b1);

			Point i(-5.9848381802165, -1.3282793934055);
			Assert::AreEqual(false, l.contain(i));
		}

		TEST_METHOD(TestMethod28)
		{
			Point a1(-2, 0);
			Point b1(4, 2);
			Ray l(a1, b1);

			Point i(-4, -2);
			Assert::AreEqual(false, l.contain(i));
		}

		TEST_METHOD(TestMethod29)
		{
			Point a1(-2, 0);
			Point b1(4, 2);
			Ray l(a1, b1);

			Point i(10, 4);
			Assert::AreEqual(true, l.contain(i));
		}

		TEST_METHOD(TestMethod29_1)
		{
			Point a1(-2, 0);
			Point b1(4, 2);
			Ray l(a1, b1);

			Point i(-2, 0);
			Assert::AreEqual(true, l.contain(i));
		}

		// test Seg
		TEST_METHOD(TestMethod30)
		{
			Point a1(-2, 0);
			Point b1(4, 2);
			Seg l(a1, b1);

			Point i(-5.9848381802165, -1.3282793934055);
			Assert::AreEqual(false, l.contain(i));
		}

		TEST_METHOD(TestMethod31)
		{
			Point a1(-2, 0);
			Point b1(4, 2);
			Seg l(a1, b1);

			Point i(-4, -2);
			Assert::AreEqual(false, l.contain(i));
		}

		TEST_METHOD(TestMethod32)
		{
			Point a1(-2, 0);
			Point b1(4, 2);
			Seg l(a1, b1);

			Point i(10, 4);
			Assert::AreEqual(false, l.contain(i));
		}
		TEST_METHOD(TestMethod33)
		{
			Point a1(-2, 0);
			Point b1(4, 2);
			Seg l(a1, b1);

			Point i(1, 2);
			Assert::AreEqual(false, l.contain(i));
		}

		TEST_METHOD(TestMethod34)
		{
			Point a1(-2, 0);
			Point b1(4, 2);
			Seg l(a1, b1);

			Point i(-2, 0);
			Assert::AreEqual(true, l.contain(i));
		}

		TEST_METHOD(TestMethod35)
		{
			Point a1(-2, 0);
			Point b1(4, 2);
			Seg l(a1, b1);

			Point i(4, 2);
			Assert::AreEqual(true, l.contain(i));
		}
		//	test Line::coincide
		TEST_METHOD(TestMethod36)
		{
			Point a1(-2, 0);
			Point b1(4, 2);
			Line l1(a1, b1);

			Point a2(-2, 0);
			Point b2(10, 4);
			Line l2(a2, b2);

			Assert::AreEqual(true, l1.coincide(l2));
		}

		//	test Ray::coincide
		TEST_METHOD(TestMethod37)
		{
			Point a1(-2, 0);
			Point b1(4, 2);
			Ray l1(a1, b1);

			Point a2(-2, 0);
			Point b2(10, 4);
			Ray l2(a2, b2);

			Assert::AreEqual(true, l1.coincide(l2));
		}

		TEST_METHOD(TestMethod38)
		{
			Point a1(-4, 0);
			Point b1(0, 2);
			Ray l1(a1, b1);

			Point a2(-4, 0);
			Point b2(-12, -4);
			Ray l2(a2, b2);

			Assert::AreEqual(false, l1.coincide(l2));
		}

		TEST_METHOD(TestMethod39)
		{
			Point a1(-4, 0);
			Point b1(0, 2);
			Ray l1(a1, b1);

			Point a2(4, 4);
			Point b2(-12, -4);
			Ray l2(a2, b2);

			Assert::AreEqual(true, l1.coincide(l2));
		}

		//	test seg::coincide
		TEST_METHOD(TestMethod40)
		{
			Point a1(-8, 0);
			Point b1(-4, -4);
			Seg l1(a1, b1);

			Point a2(-4, -4);
			Point b2(-2, -6);
			Seg l2(a2, b2);

			Assert::AreEqual(false, l1.coincide(l2));
		}

		TEST_METHOD(TestMethod41)
		{
			Point a1(-8, 0);
			Point b1(-4, -4);
			Seg l1(a1, b1);

			Point a2(-2, -6);
			Point b2(0, -8);
			Seg l2(a2, b2);

			Assert::AreEqual(false, l1.coincide(l2));
		}

		TEST_METHOD(TestMethod42)
		{
			Point a1(-8, 0);
			Point b1(2, -10);
			Seg l1(a1, b1);

			Point a2(0, -8);
			Point b2(-4, -4);
			Seg l2(a2, b2);

			Assert::AreEqual(true, l1.coincide(l2));
		}

		//	test out_index_error
		TEST_METHOD(TestMethod43)
		{
			int a = 0;
			try
			{
				Point a1(-100001, 0);
			}
			catch (const out_index_error o)
			{
				a = 1;
			}
			Assert::AreEqual(1, a);

			a = 0;
			try
			{
				Line l1(Point(-1, 200000), Point(-2, -3));
			}
			catch (const out_index_error o)
			{
				a = 1;
			}
			Assert::AreEqual(1, a);


			a = 0;
			try
			{
				Circle r1(Point(-1, 200), 100002);
			}
			catch (const out_index_error o)
			{
				a = 1;
			}
			Assert::AreEqual(1, a);


			a = 0;
			try
			{
				Circle r1(Point(-1, 200), -1);
			}
			catch (const out_index_error o)
			{
				a = 1;
			}
			Assert::AreEqual(1, a);
		}

		//	test same_point_error
		TEST_METHOD(TestMethod44)
		{
			int a = 0;
			try
			{
				Point a1(-1000, 0);
				Point b1(-1000, 0);
				Seg l1(a1, b1);
			}
			catch (const same_point_error s)
			{
				a = 1;
			}
			Assert::AreEqual(1, a);
		}

		//	test Inf_intersection_error
		TEST_METHOD(TestMethod45)
		{
			Point p[2];
			int a = 0;
			try
			{
				Point a1(0, 0);
				Point b1(2, 2);
				Seg l1(a1, b1);

				Point a2(1, 1);
				Point b2(3, 3);
				Ray l2(a2, b2);
				l1.find_intersection(l2,p);
			}
			catch (const Inf_intersection_error i)
			{
				a = 1;
			}
			Assert::AreEqual(1, a);

			a = 1;
			try
			{
				Point a1(0, 0);
				Point b1(1, 1);
				Seg l1(a1, b1);

				Point a2(1, 1);
				Point b2(3, 3);
				Ray l2(a2, b2);
				l1.find_intersection(l2, p);
			}
			catch (const Inf_intersection_error i)
			{
				a = 0;
			}
			Assert::AreEqual(1, a);

			a = 0;
			try
			{
				Point a1(0, 0);
				Point b1(1, 1);
				Seg l1(a1, b1);

				Point a2(0, 0);
				Point b2(3, 3);
				Seg l2(a2, b2);
				l1.find_intersection(l2, p);
			}
			catch (const Inf_intersection_error i)
			{
				a = 1;
			}
			Assert::AreEqual(1, a);

		}

		//	test no_delete_object_error
		TEST_METHOD(TestMethod46)
		{
			Intersect intersect;
			int a = 0;
			try
			{
				Line l(Point(1, 1), Point(2, 2));
				intersect.add_object('L',1,1,2,2);
				intersect.delete_object('L', 1, 1, 2, 3);
			}
			catch (const no_delete_object_error n)
			{
				a = 1;
			}
			Assert::AreEqual(1, a);
		}

		TEST_METHOD(TestMethod47)
		{
			Intersect intersect;
			int a = 1;
			try
			{
				Line l(Point(1, 1), Point(2, 2));
				intersect.add_object('C', 1, 1, 2);
				intersect.delete_object('C', 1, 1, 2);
			}
			catch (const no_delete_object_error n)
			{
				a = 0;
			}
			Assert::AreEqual(1, a);
		}

		TEST_METHOD(TestMethod48) {
			Intersect intersect;
			int a = 0;
			try
			{
				Line l(Point(1, 1), Point(2, 2));
				intersect.add_object('C', 1, 1, 2);
				intersect.delete_object('C', 1, 1, 3);
			}
			catch (const no_delete_object_error n)
			{
				a = 1;
			}
			Assert::AreEqual(1, a);
		}

		TEST_METHOD(TestMethod49) {
			Intersect intersect;
			int a = 1;
			try
			{
				Line l(Point(1, 1), Point(2, 2));
				intersect.add_object('L', 1, 1, 2, 2);
				intersect.delete_object('L', 1, 1, 2, 2);
			}
			catch (const no_delete_object_error n)
			{
				a = 0;
			}
			Assert::AreEqual(1, a);
		}

		TEST_METHOD(TestMethod50) {
			Intersect intersect;
			int a = 0;
			try
			{
				Line l(Point(1, 1), Point(2, 2));
				intersect.add_object('L', 1, 1, 2, 2);
				intersect.delete_object('R', 1, 1, 2, 2);
			}
			catch (const no_delete_object_error n)
			{
				a = 1;
			}
			Assert::AreEqual(1, a);
		}
	};
}
