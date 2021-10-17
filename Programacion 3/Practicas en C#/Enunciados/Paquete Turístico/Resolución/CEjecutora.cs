using System;
namespace Agencia
{
    class CEjecutora
    {
        static void Main()
        {
            ushort auxNumero;
            string auxDetalle;
            CPaquete auxPaquete;
            Console.Write("Ingrese el porcentaje de impuesto:");
            CPaquete.setIMPUESTO(Convert.ToSingle(Console.ReadLine()));

            Console.Write("Ingrese el número de paquete:");
            auxNumero=Convert.ToUInt16(Console.ReadLine());
            Console.Write("Ingrese el detalle:");
            auxDetalle=Console.ReadLine();
            auxPaquete=new CPaquete(auxNumero,auxDetalle);
            Console.Write("Ingrese el precio:");
            auxPaquete.setPrecio(Convert.ToSingle(Console.ReadLine()));
            Console.WriteLine(auxPaquete.ToString());
            Console.Write("Pulse ENTER");
            Console.ReadLine();

            
	    CPaquete paq1, paq2;

            paq1 = new CPaquete(100, "Viaje de Disney");
            paq1.setPrecio(50000);

            paq2 = new CPaquete(101, "Viaje a Europa");
            paq2.setPrecio(60000);


            if (paq2.esMasBaratoQue(paq1)==true)
            {
                Console.WriteLine("Conviene ir a a Europa");
            }
            else
            {
                Console.WriteLine("Conviene ir a a Disney");
            }

        }
    }
}
