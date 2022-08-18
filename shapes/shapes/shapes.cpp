#include <iostream>
//#include <cmath>

const double pi = 3.141;
int select = 0;
enum { SQUARE = 1, RECTANGLE, TRIANGLE, CIRCLE, EXIT };
void mainMenu();

class Shapes {
private:
	double calc_result, height, width, radius;

public:

	Shapes() {
		calc_result = height = width = radius = 0;
	}
	virtual void drawShape() = 0;

	double calculatePerimeter(double height, double width) {
		double result = 0;
		result = height * 2 + width * 2;
		set_result(result);
		return result;
	}

	//overloaded function for rectangles and squares
	double calculateArea(double height, double width) { 
		double result = 0;
		result = height * width;
		set_result(result);
		return result;
	}

	//circle with overloading
	double calculateArea(double radius) { 
		double result = 0;
		result = pi * (radius * radius);
		set_result(result);
		return result;
	}

	void giveResult() {
		std::cout << calc_result;
	}

	double get_data() {
		double input = 0;
		std::cin >> input;
		return input;
	}

	void set_result(double input) {
		calc_result = input;
	}
};


//derived classes
class Square : public Shapes {
public:
	void drawShape();
};

class Rectangle : public Shapes {
public:
	void drawShape();
};

class Triangle : public Shapes {
public:
	void drawShape();
	double calculateArea(double height, double width);
	double calculatePerimeter(double height, double width);
};

class Circle : public Shapes {
public:
	void drawShape();
	double calculatePerimeter(double radius);
};



void Square::drawShape() {
	for (int i = 0; i < 5; i++) { //rows
		for (int j = 0; j < 5; j++) { //columns
			std::cout << " *";
		}

		std::cout << std::endl;
	}
}

void Rectangle::drawShape() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			std::cout << " *";
		}

		std::cout << std::endl;
	}
}

void Triangle::drawShape() {
	int shapeWidth = 1;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < shapeWidth; j++) {
			std::cout << " *";

		}

		//cuts square in half diagonally 
		shapeWidth++; 
		std::cout << std::endl;
	}
}

//right angle triangle
double Triangle::calculateArea(double height, double width) {
	double result = 0;
	result = (height * width) / 2; 
	set_result(result);
	return result;
}

//calculating the parameter
double Triangle::calculatePerimeter(double height, double width) {
	double result, hypot = 0;
	hypot = (height * height) + (width * width);
	hypot = sqrt(hypot);
	result = height + width + hypot;
	set_result(result);
	return result;
}

void Circle::drawShape() {
	std::cout <<
		"      * * *     \n" <<
		"    * * * * *   \n" <<
		"  * * * * * * * \n" <<
		"  * * * * * * * \n" <<
		"  * * * * * * * \n" <<
		"    * * * * *   \n" <<
		"      * * *       ";
}

double Circle::calculatePerimeter(double radius) {
	double result = 0;
	result = 2 * pi * radius;
	set_result(result);
	return result;
}




void area() {
	double height, width, radius = 0;
	Square square;
	Rectangle rectangle;
	Circle c;
	Triangle t;

	switch (select) {

	case SQUARE:
		std::cout << "Please enter the base length of the square in cm: ";
		width = square.get_data();
		square.calculateArea(width, width); //squares are equal, only one value needed
		std::cout << "\nThe result is: ";
		square.giveResult();
		std::cout << "cm\xFD\n"; /*^2 symbol*/
		break;

	case RECTANGLE:
		std::cout << "Please enter the height of the rectangle in cm: ";
		height = rectangle.get_data();
		std::cout << "Please enter the width of the rectangle in cm: ";
		width = rectangle.get_data();
		rectangle.calculateArea(height, width);
		std::cout << "\nThe result is: ";
		rectangle.giveResult();
		std::cout << "cm\xFD\n"; /*^2 symbol*/
		break;

	case TRIANGLE:
		std::cout << "Please enter the height of the triangle in cm: ";
		height = t.get_data();
		std::cout << "Please enter the width of the triangle in cm: ";
		width = t.get_data();
		t.calculateArea(height, width);
		std::cout << "\nThe result is: ";
		t.giveResult();
		std::cout << "cm\xFD\n"; /*^2 symbol*/
		break;
	case CIRCLE:
		std::cout << "Please enter the radius of the circle in cm: ";
		radius = c.get_data();
		c.calculateArea(radius);
		std::cout << "\nThe result is: ";
		c.giveResult();
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
	switch (select) {
	case SQUARE:
		std::cout << "Please enter the width of the square in cm: ";
		width = s.get_data();
		s.calculatePerimeter(width, width); //squares are equal, only one value needed
		std::cout << "\nThe result is: ";
		s.giveResult();
		std::cout << "cm\n";
		break;
	case RECTANGLE:
		std::cout << "Please enter the height of the rectangle in cm: ";
		height = r.get_data();
		std::cout << "Please enter the width of the rectangle in cm: ";
		width = r.get_data();
		r.calculatePerimeter(height, width);
		std::cout << "\nThe result is: ";
		r.giveResult();
		std::cout << "cm\n";
		break;
	case TRIANGLE:
		std::cout << "Please enter the height of the triangle in cm: ";
		height = t.get_data();
		std::cout << "Please enter the width of the triangle in cm: ";
		width = t.get_data();
		t.calculatePerimeter(height, width);
		std::cout << "\nThe result is: ";
		t.giveResult();
		std::cout << "cm\n";
		break;
	case CIRCLE:
		std::cout << "Please enter the radius of the circle in cm: ";
		radius = c.get_data();
		c.calculatePerimeter(radius);
		std::cout << "\nThe result is: ";
		c.giveResult();
		std::cout << "cm\n";
		break;
	}
	std::cout << std::endl;
}

void display() {
	Square square;
	Rectangle rectangle;
	Triangle triangle;
	Circle circle;

	switch (select) {
	case SQUARE:
		std::cout << "*******************\n" <<
			"Square Calculator\n\n" <<
			"*******************\n\n";
		square.drawShape();
		std::cout << std::endl;
		break;
	case RECTANGLE:
		std::cout << "*******************\n" <<
			"Rectangle Calculator\n\n" <<
			"*******************\n\n";
		rectangle.drawShape();
		std::cout << std::endl;
		break;
	case TRIANGLE:
		std::cout << "*******************\n" <<
			"Triangle Calculator\n\n" <<
			"*******************\n\n";
		triangle.drawShape();
		std::cout << std::endl;
		break;
	case CIRCLE:
		std::cout << "*******************\n" <<
			"Circle Calculator\n\n" <<
			"*******************\n\n";
		circle.drawShape();
		std::cout << std::endl;
		break;
	}
}

void menu_2() {
	int select;
	display();
	std::cout << "What would you like to calculate?\n";
	std::cout << "	1. Area\n	2. Perimeter\n	3. Return to main menu\n";
	std::cin >> select;

	switch (select) {

	case 1:
		area();
		menu_2();
		break;

	case 2:
		perimeter();
		menu_2();
		break;

	case 3:
		mainMenu();
		break;

	default:
		std::cout << "Invalid selection\n";
		menu_2();
		break;
	}
}

void mainMenu() {

	std::cout << "*******************\nShapes Calculator\n\n*******************\n";
	std::cout << "Which shape would you like to calculate?\n";
	std::cout << "	1. Square\n	2. Rectangle\n	3. Triangle\n	4. Circle\n	5. Exit\n";
	std::cin >> select;

	if (select > 0 && select < 5) {
		menu_2();
	}
	else if (select == 5) {
	}
	else {
		std::cout << "Invalid selection.\n";
		mainMenu();
	}
}


int main() {
	Square sqr;
	Rectangle rec;
	Circle cir;
	Triangle tri;

	while (select != 5) {
		mainMenu();
	}

	return 0;
}
