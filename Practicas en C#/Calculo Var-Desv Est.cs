using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            /* Calculo de Deviacion Estandar y Varianza*/

            double[] numeros = new double[] { 1, 2, 3, 4, 5 };
            double sumatoria = 0;
            double sumatoriaVar = 0;
            double promedio;
            double varianza;
            
            Console.WriteLine("Muestra:");
            
            for (int i=0; i<numeros.Length; i++){
                sumatoria += numeros[i];
                Console.WriteLine(numeros[i]);    
            
            }
            promedio = sumatoria / numeros.Length;

            Console.WriteLine("Mi promedio = {0}", promedio);
            
            Console.WriteLine("Diferencias: ");
            for (int j=0; j<numeros.Length; j++){
                numeros[j] -= promedio;
                Console.WriteLine(numeros[j]);
            }

            for (int x=0; x<numeros.Length; x++){
                numeros[x] = Math.Pow(numeros[x],2);
                Console.WriteLine("Diferencia elv a 2 = {0} ", numeros[x]);
                sumatoriaVar += numeros[x];
            }
            Console.WriteLine("Sumatoria {0}", sumatoriaVar);
            varianza = sumatoriaVar / numeros.Length;
            Console.WriteLine("Varianza {0}",varianza);
            Console.WriteLine("Desviacion Estandar -->  {0} ",Math.Sqrt(varianza));
        }  
    }
}