using System;
namespace Librería
{
    class CEjecutora
    {
        static void Main(string[] args)
        {
            ulong auxISBN;
            bool huboIngresoValido=false;
            CLibro auxLibro, masCostoso=null;
            Console.Write("Ingrese ISBN (0 para Salir):");
            auxISBN=Convert.ToUInt64(Console.ReadLine());
            while (auxISBN!=0)
            {
                auxLibro = new CLibro(auxISBN);
                Console.Write("Ingrese Signatura Topográfica:");
                auxLibro.setSignaTopog(Console.ReadLine());
                Console.Write("Ingrese Costo: $");
                auxLibro.setCosto(Convert.ToSingle(Console.ReadLine()));
                if (!huboIngresoValido)
                {
                    masCostoso = auxLibro;
                    huboIngresoValido = true;
                }
                else
                {
                    if (!auxLibro.esMasBaratoQue(masCostoso))
                    {
                        masCostoso = auxLibro;
                    }
                }
                Console.Write("Ingrese ISBN (0 para Salir):");
                auxISBN = Convert.ToUInt64(Console.ReadLine());
            }
            if (huboIngresoValido)
            {
                Console.WriteLine("Libro más costoso:");
                Console.Write(masCostoso.darDatos());
                Console.WriteLine("\nPrecio con Descuento 40%: $" + Convert.ToString(masCostoso.darPrecio(40.0f)));
            }
            else Console.WriteLine("No se ingresaron libros.");
            Console.WriteLine("Pulse Enter");
            Console.ReadLine();
        }
    }
}
