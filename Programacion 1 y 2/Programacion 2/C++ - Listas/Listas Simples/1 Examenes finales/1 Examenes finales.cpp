
/*

La siguiente lista enlazada se utiliza para almacenar los exámenes finales rendidos en una carrera.

Se pide hacer las clases y métodos necesarios para que funcione el main provisto.

Debe haber una lista enlazada de Materias, que cada una posee una lista enlazada de Finales.
Además debe existir una clase TUP, que representa a la lista múltiple y es con la cual se comunica el main.

Cada final tiene un nombre de estudiante y nota obtenida.

El método imprimePromedios muestra los nombres de las materias, y el promedio de las notas existentes.


*/


int main() {
	
	TUP * tup = new TUP;

	tup->crearMateria("Matematica");
	tup->crearMateria("Programacion 1");
	tup->crearMateria("Materia fantasma");

	tup->inscribirFinal("Pepe Gomez", "Matematica", 2);
	tup->inscribirFinal("Maria Lopez", "Matematica", 8);
	tup->inscribirFinal("Bart Simpson", "Programacion 1", 8);

	tup->imprimePromedios();
	// debe imprimir:
	//
	// Matematica: 5
	// Programacion 1: 8
}