#include <iostream>
#include <cmath>


#pragma once

const double pi = 3.14159265;

class Shapes {
private:
	double calc_result, height, width, radius;

public:
	Shapes();
	virtual void draw_shape() = 0;
	double calculate_perimeter(double height, double width);
	double calculate_perimeter(double radius);
	double calculate_area(double height, double width);
	double calculate_area(double radius);
	void give_result();
	double get_data();
	void set_result(double input);
};


//derived classes
class Square : public Shapes {
public:
	void draw_shape();
};
class Rectangle : public Shapes {
public:
	void draw_shape();
};
class Triangle : public Shapes {
public:
	void draw_shape();
	double calculate_area(double height, double width);
	double calculate_perimeter(double height, double width);
};
class Circle : public Shapes {
public:
	void draw_shape();
	double calculate_perimeter(double radius);
};

Shapes::Shapes() {
	calc_result = height = width = radius = 0;
}


double Shapes::calculate_area(double radius) { //single argument for circle, this would be in the circle sub-class but i must show off overloading.
	double result = 0;
	result = pi * (radius * radius);
	set_result(result);
	return result;
}

double Shapes::calculate_area(double height, double width) { //overloaded function for rectangles and squares
	double result = 0;
	result = height * width;
	set_result(result);
	return result;
}

double Shapes::calculate_perimeter(double height, double width) {
	double result = 0;
	result = height * 2 + width * 2;
	set_result(result);
	return result;
}

void Shapes::set_result(double input) {
	calc_result = input;
}

double Shapes::get_data() {
	double input = 0;
	std::cin >> input;
	return input;
}

void Shapes::give_result() {
	std::cout << calc_result;
}

//derived class function overriding
void Square::draw_shape() {
	for (int i = 0; i < 5; i++) { //rows

		for (int j = 0; j < 5; j++) { //columns
			std::cout << " *";
		}
		std::cout << std::endl;
	}
}

void Rectangle::draw_shape() {
	for (int i = 0; i < 5; i++) { //rows

		for (int j = 0; j < 10; j++) { //columns
			std::cout << " *";
		}
		std::cout << std::endl;
	}
}

void Triangle::draw_shape() {
	int shape_w = 1;
	for (int i = 0; i < 5; i++) { //rows

		for (int j = 0; j < shape_w; j++) { //columns
			std::cout << " *";

		}
		shape_w++; //pretty much just draws a square cut in half diagonally
		std::cout << std::endl;
	}
}

double Triangle::calculate_area(double height, double width) {
	double result = 0;
	result = (height * width) / 2; //right angle triangle
	set_result(result);
	return result;
}

double Triangle::calculate_perimeter(double height, double width) {
	double result, hypot = 0;
	hypot = (height * height) + (width * width);
	hypot = sqrt(hypot);
	result = height + width + hypot;
	set_result(result);
	return result;
}

void Circle::draw_shape() {
	std::cout <<
		"     * * *\n" <<
		"   * * * * *\n" <<
		" * * * * * * *\n" <<
		" * * * * * * * \n" <<
		"   * * * * *\n" <<
		"     * * *\n";
}

double Circle::calculate_perimeter(double radius) {
	double result = 0;
	result = 2 * pi * radius;
	set_result(result);
	return result;
}


int shape_sel = 0; //global selection variable
enum { SQUARE = 1, RECTANGLE, TRIANGLE, CIRCLE, EXIT };
void main_menu();

void area() {
	double height, width, radius = 0;
	Square s;
	Rectangle r;
	Circle c;
	Triangle t;
	switch (shape_sel) {
	case SQUARE:
		std::cout << "Please enter the base length of the square in cm: ";
		width = s.get_data();
		s.calculate_area(width, width); //squares are equal, only one value needed
		std::cout << "\nThe result is: ";
		s.give_result();
		std::cout << "cm\xFD\n"; /*^2 symbol*/
		break;
	case RECTANGLE:
		std::cout << "Please enter the height of the rectangle in cm: ";
		height = r.get_data();
		std::cout << "Please enter the width of the rectangle in cm: ";
		width = r.get_data();
		r.calculate_area(height, width);
		std::cout << "\nThe result is: ";
		r.give_result();
		std::cout << "cm\xFD\n"; /*^2 symbol*/
		break;
	case TRIANGLE:
		std::cout << "Please enter the height of the triangle in cm: ";
		height = t.get_data();
		std::cout << "Please enter the width of the triangle in cm: ";
		width = t.get_data();
		t.calculate_area(height, width);
		std::cout << "\nThe result is: ";
		t.give_result();
		std::cout << "cm\xFD\n"; /*^2 symbol*/
		break;
	case CIRCLE:
		std::cout << "Please enter the radius of the circle in cm: ";
		radius = c.get_data();
		c.calculate_area(radius);
		std::cout << "\nThe result is: ";
		c.give_result();
		std::cout << "cm\xFD\n"; /*^2 symbol*/
		break;
	}
	std::cout << std::endl;
}

void perimeter() {
	double height, width, radius = 0;
	Square s;
	Rectangle r;
	Circle c;
	Triangle t;
	switch (shape_sel) {
	case SQUARE:
		std::cout << "Please enter the width of the square in cm: ";
		width = s.get_data();
		s.calculate_perimeter(width, width); //squares are equal, only one value needed
		std::cout << "\nThe result is: ";
		s.give_result();
		std::cout << "cm\n";
		break;
	case RECTANGLE:
		std::cout << "Please enter the height of the rectangle in cm: ";
		height = r.get_data();
		std::cout << "Please enter the width of the rectangle in cm: ";
		width = r.get_data();
		r.calculate_perimeter(height, width);
		std::cout << "\nThe result is: ";
		r.give_result();
		std::cout << "cm\n";
		break;
	case TRIANGLE:
		std::cout << "Please enter the height of the triangle in cm: ";
		height = t.get_data();
		std::cout << "Please enter the width of the triangle in cm: ";
		width = t.get_data();
		t.calculate_perimeter(height, width);
		std::cout << "\nThe result is: ";
		t.give_result();
		std::cout << "cm\n";
		break;
	case CIRCLE:
		std::cout << "Please enter the radius of the circle in cm: ";
		radius = c.get_data();
		c.calculate_perimeter(radius);
		std::cout << "\nThe result is: ";
		c.give_result();
		std::cout << "cm\n";
		break;
	}
	std::cout << std::endl;
}

void title_display() {
	Square s;
	Rectangle r;
	Circle c;
	Triangle t;
	switch (shape_sel) {
	case SQUARE:
		std::cout << "*******************\n" <<
			"Square Calculator\n\n" <<
			"*******************\n\n";
		s.draw_shape();
		std::cout << std::endl;
		break;
	case RECTANGLE:
		std::cout << "*******************\n" <<
			"Rectangle Calculator\n\n" <<
			"*******************\n\n";
		r.draw_shape();
		std::cout << std::endl;
		break;
	case TRIANGLE:
		std::cout << "*******************\n" <<
			"Triangle Calculator\n\n" <<
			"*******************\n\n";
		t.draw_shape();
		std::cout << std::endl;
		break;
	case CIRCLE:
		std::cout << "*******************\n" <<
			"Circle Calculator\n\n" <<
			"*******************\n\n";
		c.draw_shape();
		std::cout << std::endl;
		break;
	}
}

void menu_2() {
	int sel;
	title_display();
	std::cout << "What would you like to calculate?\n";
	std::cout << "	1. Area\n";
	std::cout << "	2. Perimeter\n";
	std::cout << "	3. Return to main menu\n";
	std::cin >> sel;

	switch (sel) {
	case 1:
		area();
		menu_2();
		break;
	case 2:
		perimeter();
		menu_2();
		break;
	case 3:
		main_menu();
		break;
	default:
		std::cout << "Invalid selection\n";
		menu_2();
		break;
	}
}

void main_menu() {

	std::cout << "*******************\n" <<
		"Shapes Calculator\n\n" <<
		"*******************\n";
	std::cout << "Which shape would you like to calculate?\n";
	std::cout << "	1. Square\n";
	std::cout << "	2. Rectangle\n";
	std::cout << "	3. Triangle\n";
	std::cout << "	4. Circle\n";
	std::cout << "	5. Exit\n";
	std::cin >> shape_sel;

	if (shape_sel > 0 && shape_sel < 5) {
		menu_2();
	}
	else if (shape_sel == 5) {
	}
	else {
		std::cout << "Invalid selection.\n";
		main_menu();
	}
}


int main() {
	Square sqr;
	Rectangle rec;
	Circle cir;
	Triangle tri;

	while (shape_sel != 5) {
		main_menu();
	}

	return 0;
}