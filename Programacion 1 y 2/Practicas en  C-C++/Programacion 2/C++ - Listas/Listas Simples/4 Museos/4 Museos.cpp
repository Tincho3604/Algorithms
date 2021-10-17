

class Visitante {
  
};

class Museo {
   
};

class RegistroVisitas {

};



int main() {
	RegistroVisitas * lista = new RegistroVisitas;

	lista->nuevoMuseo("MALBA");
    lista->nuevoMuseo("Museo Historico Nacional");
    lista->nuevoMuseo("Museo de Ciencias Naturales");

	lista->registrarVisita("MALBA", "Pepe Gomez");
	lista->registrarVisita("Museo Historico Nacional", "Pepe Gomez");
	lista->registrarVisita("MALBA", "Maria Alvarez");
	lista->registrarVisita("Museo de Ciencias Naturales", "Pepe Gomez");
    lista->registrarVisita("Museo de Ciencias Naturales", "Roberto Sanchez");

    printf("Antes de borrar: \n");
    lista->mirar();

	lista->borrarMuseosPocoVisitados();  //borra de la lista a los museos con menos de 2 visitas, para este ejemplo es unicamente el M. Hist. Nac.

    printf("\n\nDespues de borrar: \n");
	lista->mirar();
}
