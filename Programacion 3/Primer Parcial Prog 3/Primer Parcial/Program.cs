using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Primer_Parcial {
    internal class Program
    {
        static void Main(string[] args)
        {


            // Punto 1)
            int cantidadDeViajes = 10;
            Viaje[] Viaje = new Viaje[cantidadDeViajes];
            Viaje ViajeMasCaro = new Viaje();
            string dominioIngreso = "";
            int distanciaRecorridaIngreso = 0;
            int costoKilometrosGeneral = 0;
            int kilometrajeMinimoIngreso = 0;



            Console.WriteLine("¡BIENVENIDO A Uwer! PORFAVOR A CONTINUACION CARGUE EL LISTADO DE VIAJES");
            Console.WriteLine("Ingrese el costo por kilometro unico para todos los viajes: ");

            while (!int.TryParse(Console.ReadLine(), out costoKilometrosGeneral))
            {
                Console.WriteLine("Formato Invalido ¡INTENTELO NUEVAMENTE!");
            }

            Console.WriteLine("¡COSTO ESTABLECIDO CON EXITO! para continuar pulse ENTER");
            Console.ReadKey();

            Console.WriteLine("El sistema solo le permitira cargar 10 viajes");

            Console.WriteLine("\n\n");


            for (int i = 0; i < cantidadDeViajes; i++) {
                Console.WriteLine("\n");
                Console.WriteLine("Viaje N° " + (i + 1));

                Console.WriteLine("Ingrese dominio del viaje: ");
                dominioIngreso = Console.ReadLine();

                Console.WriteLine("\n");

                Console.WriteLine("Ingrese la distancia recorrida del viaje: ");

                while (!int.TryParse(Console.ReadLine(), out distanciaRecorridaIngreso))
                {
                    Console.WriteLine("Formato Invalido ¡INTENTELO NUEVAMENTE!");
                }


                Console.WriteLine("Ingrese el kilometraje minimo: ");

                while (!int.TryParse(Console.ReadLine(), out kilometrajeMinimoIngreso))
                {
                    Console.WriteLine("Formato Invalido ¡INTENTELO NUEVAMENTE!");
                }


                Viaje[i] = new Viaje(dominioIngreso, distanciaRecorridaIngreso);
                Viaje[i].setKilometrajeMinimo(kilometrajeMinimoIngreso);
                Viaje[i].setCostoPorKilometro(costoKilometrosGeneral);
                Viaje[i].setPrecioFinal();

                if (Viaje[i].compararCon(ViajeMasCaro)) {
                  

                    ViajeMasCaro = new Viaje(Viaje[i].getDominio(), distanciaRecorridaIngreso);
                    ViajeMasCaro.setKilometrajeMinimo(Viaje[i].getKilometrajeMinimo());
                    ViajeMasCaro.setCostoPorKilometro(costoKilometrosGeneral);
                    ViajeMasCaro.setPrecioFinal();

                }
            }

            Console.WriteLine("¡CARGA FINALIZADA! :) POR FAVOR PRESIONE ENTER PARA VER EL VIAJE MAS CARO");
            Console.ReadKey();

            Console.WriteLine(ViajeMasCaro.darDatos());

            Console.WriteLine("A CONTINUACION POR FAVOR PRESIONE ENTER PARA VER EL LISTADO DE VIAJES");
            Console.ReadKey();

            mostrarViajes(Viaje, cantidadDeViajes);


            Console.WriteLine("¡Enter para FINALIZAR!");
            Console.ReadKey();
        }

        static void mostrarViajes(Viaje[] Viajes, int cantidadParam) {
            for (int i = 0; i < cantidadParam; i++) {
                
                Console.WriteLine("Viaje N° " + (i + 1));
                Console.Write(Viajes[i].darDatos());

                Console.WriteLine("\n");
            }
        }
    }
}
