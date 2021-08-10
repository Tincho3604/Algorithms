using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            /* El usuario ingresara frases hasta que introduzca la palabra = "FIN" */
            /*Mostrar en pantalla la frase que tiene mas vocales.
             Considerar mayúsculas y minúsculas */
            
            char[] vocals = new char[5] { 'a', 'e', 'i', 'o', 'u' };
            String frase;
            char[] delimitador = {',' , ' '};
            int cont = 0;
            int cantidad = 0;
            String fraseVocal = "nada";

            do{
            
                Console.WriteLine("Ingrese frase: ");
                frase = Console.ReadLine();
                
                char[] frases = frase.ToCharArray();

                foreach (char c in frases)
                {
                    foreach (char v in vocals)
                    {
                        if (c == Char.ToLower(v) || c == Char.ToUpper(v))
                        {
                            Console.WriteLine("Vocales en la frase -->  {0}", c.ToString());
                            cont++;
                        }
                    }
                }
                if (cont > cantidad){
                    cantidad = cont;
                    fraseVocal = frase;
                }
                
                cont = 0;

            }while(frase != "FIN");
            Console.WriteLine("La frase con mas vocales es : " + fraseVocal);
        }  
    }
}