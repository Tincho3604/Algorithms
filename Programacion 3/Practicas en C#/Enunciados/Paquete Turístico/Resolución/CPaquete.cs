using System;
namespace Agencia
{
    class CPaquete
    {
        private static float IMPUESTO;
        private ushort numPaquete;
        private string detalle;
        private float precio;
        
        public static void setIMPUESTO(float porcentaje)
        {
            CPaquete.IMPUESTO=porcentaje;
        }
   
        public CPaquete (ushort codigo, string descripcion)
        {
            this.numPaquete=codigo;
            this.detalle = descripcion;
        }
        public void setPrecio(float monto)
        {
           this.precio=monto;
        }
        public float getPrecio()
        {
            return this.precio;
        }
        public float darMontoTotal()
        {
           return this.precio * (1F + CPaquete.IMPUESTO / 100);
        }
        public float darMontoTotal(ushort cuotas)
        {
            //if (cuotas > 1) return (this.darMontoTotal(System.Convert.ToUInt16(cuotas - 1)) * 1.1F);
            // return this.darMontoTotal();
            //Otra forma:
            return this.darMontoTotal() *(1+ ((cuotas - 1) * 0.1F));
        } 
       public override string ToString() 
       {
           string datos= "Número de Paquete: " + Convert.ToString(this.numPaquete);
           datos+="\nDetalle: " + this.detalle;
           datos += "\nPrecio: $" + Convert.ToString(this.precio);
           datos += "\nImpuesto: " + Convert.ToString(CPaquete.IMPUESTO) + "%";
           datos += "\nMonto Total: $ " + Convert.ToString(this.darMontoTotal());
           return datos;
       }
       public float Costo
       {
           get { return this.precio; }
           set { this.precio = value; }
       }
       public bool esMasBaratoQue(CPaquete otroPaquete)
       {
           if (this.precio<otroPaquete.getPrecio()) return true;
           return false;
       }
    }
}
