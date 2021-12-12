using System;

namespace Jueguito
{
    class Program
    {
        static void Main(string[] args)
        {
            Coche e = new Coche(50, "Ford","2009",100, 12000);
            Console.Write(e.Precio);

            e.Precio = 2;

            Console.WriteLine(e.ToString());

        }
    }
}
