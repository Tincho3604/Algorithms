using System;
namespace Taller
{
    class CEjecutora
    {
        static void Main(string[] args)
        {
            uint auxCod;
            bool ingreso=false;
            CAutoparte auxAutoparte, masCostosa=null;
            Console.Clear();
            Console.Write("Ingrese GANANCIA: %");
            CAutoparte.setGANANCIA(Convert.ToSingle(Console.ReadLine()));
            Console.Write("Ingrese Código de Pieza (0 para Finalizar):");
            auxCod = Convert.ToUInt32(Console.ReadLine());
            while (auxCod!=0) 
            {
                auxAutoparte = new CAutoparte(auxCod);
                Console.Write("Ingrese descripcion:");
                auxAutoparte.setDescripcion (Console.ReadLine());
                Console.Write("Ingrese valor de costo: $");
                auxAutoparte.setCosto(Convert.ToSingle(Console.ReadLine()));
                if (!ingreso)
                {
                    masCostosa = auxAutoparte;
                    ingreso = true;
                }
                else
                {
                    if (auxAutoparte.costoMayorQue(masCostosa))
                    {
                        masCostosa = auxAutoparte;
                    }

                }   
                Console.Clear();
                Console.Write("Ingrese Código de Pieza (0 para Finalizar):");
                auxCod = Convert.ToUInt32(Console.ReadLine());
            }
            if (ingreso)
            {
                Console.Clear();
                Console.WriteLine("La autoparte más costosa es: " + Environment.NewLine + masCostosa.darDatos());
                Console.WriteLine("Valor cuota en 12 pagos: $" + Convert.ToString(masCostosa.darPrecio(12)/12));
            }        
            else
            {
                Console.WriteLine("No se ingresaron autopartes");
            }
            Console.Write("Pulse ENTER");
            Console.ReadLine();
        }
    }
}
