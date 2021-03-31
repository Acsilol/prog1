/*
    g++ drill.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill `fltk-config --ldflags --use-images`
*/
#include "std_lib_facilities.h"

// declaring all the structs
struct A{
	virtual void pvf() = 0;
};

struct B1 : A{
	virtual void vf() {cout << "B1::vf()\n";}
	void f() {cout << "B1::f()\n";}
	void pvf() {cout << "B1::pfv()\n";}
};

struct D1 : B1{
	void vf() override {cout << "D1::vf()\n";}
	void f() {cout << "D1::f()\n";}
};

struct D2 : D1{
	void pvf() override {cout << "D2::pvf()\n";}
};

struct B2{
	virtual void pvf() = 0;
};

struct D21 : B2{
	string s = "valami";
	void pvf() override {cout << s << endl;}
};


struct D22 : B2{
	int i = 40;
	void pvf() override {cout << i << endl;}
};

void f(B2& b1){
	b1.pvf();
};

int main()
{
	B1 b1;
	b1.vf();
	b1.f();
	b1.pvf();
	cout << endl;

	D1 d1;
	d1.vf();
	d1.f();
	d1.pvf();
	cout << endl;

	B1& b1_ref {d1};
	b1_ref.vf();
	b1_ref.f();
	b1_ref.pvf();
	cout << endl;

	D2 d2;
	d2.vf();
	d2.f();
	d2.pvf();
	cout << endl;

	D21 d21;
	D22 d22;
	f(d21);
	f(d22);

	return 0;
}