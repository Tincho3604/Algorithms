using System;
using CAutoparte;

namespace CAutoparte

{
    class CEjecutora
    {
        static void Main(string[] args)
        {
            float precioMasCaro = 0;

            Console.WriteLine("\n\n INGRESE GANANCIA GENERAL DE LAS AUTPOARTES: ");
            CAutoparte.setGanancia(float.Parse(Console.ReadLine()));

            CAutoparte parte = new CAutoparte(2015);
            CAutoparte mayor = new CAutoparte(2016);

            Console.WriteLine("\n\n\t BIENVENIDO INGRESE LOS DATOS DE AUTPOARTES \t\n\n");

                while (parte.CODIGO_DE_PIEZA != 0) {
                
                if (precioMasCaro < parte.darPrecio(12))
                {
                    Console.WriteLine("Precio mas caro anterior: " + precioMasCaro);
                    precioMasCaro = parte.darPrecio(12);
                    Console.WriteLine("Precio mas caro: " + precioMasCaro);
                }
                Console.WriteLine("\nIngrese Codigo de pieza: \n");
                    parte.CODIGO_DE_PIEZA = Int32.Parse(Console.ReadLine());

                    Console.WriteLine("\nIngrese Descripccion de la autoparte: \n");
                    parte.DESCRIPCIÓN = Console.ReadLine();

                    Console.WriteLine("\nIngrese Costo de la autoparte: \n");
                    parte.COSTO = float.Parse(Console.ReadLine());


               }
                Console.WriteLine("El costo total es: " + precioMasCaro);
           }
        }
    }


