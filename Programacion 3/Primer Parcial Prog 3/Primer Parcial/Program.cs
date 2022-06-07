using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Primer_Parcial {
    internal class Program {
        static void Main(string[] args) {

            MenuOptions();

        }
    
        static void MenuOptions() {
            string opccion;

            Console.WriteLine("****************************************************");
            Console.WriteLine("*         Sistema de Gestion de Cuentas            *");
            Console.WriteLine("****************************************************");

            Console.WriteLine("[1] Agregar una cuenta.");
            Console.WriteLine("[2] Efectuar un deposito.");
            Console.WriteLine("[3] Efectuar una extraccion.");
            Console.WriteLine("[4] Agregar una cuenta");
            Console.WriteLine("[5] Agregar una cuenta");
            Console.WriteLine("[6] Agregar una cuenta");
            Console.WriteLine("[7] Agregar una cuenta");

            Console.WriteLine("****************************************************");

            Console.WriteLine("Ingrese una opccion entre 1 y 7");
            opccion = Console.ReadLine();

            switch (opccion) {
                case "1":
                    Console.WriteLine("1");
                break;
                
                case "2":
                    Console.WriteLine("2");
                break;

                case "3":
                    Console.WriteLine("3");
                break;

                case "4":
                    Console.WriteLine("4");
                break;

                case "5":
                    Console.WriteLine("5");
                break;

                case "6":
                    Console.WriteLine("6");
                break;

                case "7":
                    Console.WriteLine("7");
                break;
            }

            Console.ReadKey();

        }
    
    }
}
