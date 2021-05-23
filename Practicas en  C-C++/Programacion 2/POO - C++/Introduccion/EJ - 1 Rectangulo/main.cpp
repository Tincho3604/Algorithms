#include<iostream>
#include<stdlib.h>
/*
Construya una clase llamada Rectángulo que tenga los siguientes atributos:
largo y ancho, y los siguientes métodos: perímetro() y área()
*/


using namespace std;

class Rectangulo {
  private:  
	float largo;
	float ancho;
  public:
	Rectangulo(float, float);
	void perimetro();
	void area();
};

Rectangulo::Rectangulo(float _largo, float _ancho) {
	largo = _largo;
	ancho = _ancho;
}

void Rectangulo::perimetro() {
	float perimetro;
	perimetro = 2 * (ancho + largo);
	cout << "El perimetro es: " << perimetro << endl;
}

void Rectangulo::area() {
	float area;
	area = ancho * largo;
	cout << "El area es: " << area << endl;
}

int main() {

	Rectangulo P1(18, 12);
	Rectangulo P2(18, 12);

	P1.perimetro();
	P2.area();



	system("pause");
	return 0;
}
