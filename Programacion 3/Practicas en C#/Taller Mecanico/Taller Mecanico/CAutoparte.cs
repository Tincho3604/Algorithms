using System;

namespace CAutoparte

/* 
 - GANANCIA: Número real (punto flotante de precisión simple) –Valor único compartidoparatodas las instanciasdel objeto.
   Representa el porcentaje de incremento sobre el costo que se desea establecer como margen de ganancia.Ejemplo:25,75%.
 - Código de Pieza: Número entero del intervalo [0 a 999.999.999]. Ejemplo:733.615.993.
 - Descripción:Cadenade caracteresdescriptiva de laAutoparte.Ejemplo:“Correa de Distribución”.
 - Costo: Número real (punto flotante de precisión simple) que representa el valor de reposición del artículo. Ejemplo:$189,50. 
 */

{
    class CAutoparte
    {
        public static float GANANCIA;
        public int CODIGO_DE_PIEZA;
        public string DESCRIPCIÓN;
        public float COSTO;


        // 4 - Constructor parametrizado seteando Codigo por defecto. 
        public CAutoparte(int Codigo)
        {
            this.CODIGO_DE_PIEZA = Codigo;
        }
        // 2 - Crear setDescripcion()
        public void setDescripción(string descripcion)
        {
            this.DESCRIPCIÓN = descripcion;
        }
        // 3 - Crear setGanancia()
        public static void setGanancia(float ganancia)
        {
            GANANCIA = ganancia;
        }

        // 5 - Crear setCosto()
        public void setCosto(float costo)
        {
            this.COSTO = costo;
        }

        // 6 - Crear darPrecio()
        public float darPrecio(){
            float precio;

            precio = (0.01F * GANANCIA) + 1;
            precio = precio * this.COSTO;
            return precio;
        }
        // 7 - Crear darDatos()
        public string darDatos()
        {
            return this.CODIGO_DE_PIEZA.ToString() +'\t'+ this.DESCRIPCIÓN +'\t'+ this.COSTO.ToString() +'\t'+ this.darPrecio().ToString();
        }
        // 8 - Crear costoMayorQue(cuotas)
        public bool costoMayorQue(CAutoparte nuevaAutoparte)
        {
            if (nuevaAutoparte.COSTO > this.COSTO) return true;
            else return false;
        }
        // 9 - Sobrecargado darPrecio(cuotas);
        public float darPrecio(int cuotas)
        {
            float penalizacion = 1.10F;
            float valorTotal = 0F;

            for (int i = 0; i < cuotas; i++) {
                valorTotal = cuotas == 1 ? darPrecio() + cuotas : darPrecio() + ((cuotas * penalizacion) + 1);
            }
            return valorTotal;
        }
    }
}