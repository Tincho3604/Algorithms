


/*


Se desea armar una guirnalda para mantener la información de stock de algunos productos.
Estos productos corresponden a diversas marcas.
La lista principal está compuesta de nodos Marca, de los cuales surge una lista secundaria de nodos Producto.

Le llamamos "punto de reposición" a la cantidad de productos que, cuando es alcanzada 
(a medida que los productos se venden), indica que debemos comprar más para reponer.




class Comercio {         class Marca {                    class Producto {
	private:               	private:                         char nombre[50];
	Marca * marcas;         char nombre[50];                 int stock;
}                           Marca * sig;                     int ptoreposicion;
                            Producto * productos;            Producto * sig;
                         }                                }


*/

int main(void) {
	Comercio c;
	c.ingresar("Samsung", "S10", 10, 2); //marca, producto, stock, punto de reposicion
	c.ingresar("Samsung", "A12", 20, 0);
	c.ingresar("iPhone", "12", 5, 4);
	c.ingresar("iPhone", "12Pro", 0, 2);
	c.ingresar("LG", "Moto Z", 20, 5);

	c.venderUno("iPhone", "12");   //resta 1

	printf("Se debe llamar a estos fabricantes: ");
	c.imprimirMarcasConProductosAReponer();   //mostrar las marcas con faltantes, sin repetir!
											//para el ejemplo debe verse iphone (una sola vez)
}