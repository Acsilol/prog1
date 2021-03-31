/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;

	Simple_window win {Point{100, 100}, 600, 400, "My window"};

	Axis xa {Axis::x, Point{20,300}, 560, 10, "x axis"};			//changed the length of the x axis - first minor change
	win.attach(xa);
	win.set_label("My window #2");
	win.wait_for_button();

	Axis ya {Axis::y, Point{20,300}, 280, 10, "y axis"};
	ya.set_color(Color::cyan);
	ya.label.set_color(Color::dark_red);
	win.attach(ya);
	win.set_label("My window #3");
	win.wait_for_button();

	Function sine {sin, 0, 100, Point{20,150}, 1000, 20, 20};		//changed x and y values * 50 to --> * 20
	win.attach(sine);
	win.set_label("My window #4");
	win.wait_for_button();

	sine.set_color(Color::blue);

	Polygon poly;
	poly.add(Point{300,200});
	poly.add(Point{350,100});
	poly.add(Point{400,200});

	poly.set_color(Color::dark_blue); //changed color from red to brown
	poly.set_style(Line_style::dash);
	win.attach(poly);
	win.set_label("My window #5");
	win.wait_for_button();

	Rectangle r {Point{200,200}, 70, 50}; // it's x coordinate changed from 100 to 70
	win.attach(r);
	win.set_label("My window #6");
	win.wait_for_button();

	Closed_polyline poly_rect;
	poly_rect.add(Point{100,50});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,100});
	poly_rect.add(Point{100,100});
	win.attach(poly_rect);

	poly_rect.add(Point{125, 75}); //changed x coordinate from 50 to 125, making a concave poly


	//filling colors
	r.set_fill_color(Color::white); //changed color from yellow to white
	poly.set_style(Line_style(Line_style::dash, 4));
	poly_rect.set_style(Line_style(Line_style::dash, 2));
	poly_rect.set_fill_color(Color::green);
	win.set_label("My window #7");
	win.wait_for_button();

	//attaching the text on points

	Text t {Point(250,80), "Hello, graphical world!"}; //changed both x and y coordinates of the text
	win.attach(t);
	win.set_label("My window #8");
	win.wait_for_button();

	t.set_font(Font::times_bold);
	t.set_font_size(20);
	win.set_label("My window #9");
	win.wait_for_button();

	//adding the image
	Image ii {Point{30,50}, "badge.jpg"}; //changed x coordinates of the picture
	win.attach(ii);
	win.set_label("My window #10");
	win.wait_for_button();

	ii.move(100,200);
	win.set_label("My window #11");
	win.wait_for_button();

	//other stuff from the book (?)

	Circle c {Point{150,180}, 50};    //changed coordinates
	Mark m {Point{150,180}, 'x'};	  //changed coordinates according to the circle

	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max()
		<< "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes {Point{100,20}, oss.str()};
	Image cal{Point{250, 190}, "rick.gif"};
	
	win.attach(c);
	win.attach(m);
	win.attach(sizes);
	win.attach(cal);
	win.set_label("My window #12");
	win.wait_for_button();
}