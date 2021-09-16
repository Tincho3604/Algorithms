namespace Taller
{
    class CAutoparte
    {
        private static float GANANCIA;
        private uint codPieza;
        private string descripcion;
        private float costo;
        
        public static void setGANANCIA(float porcentaje)
        {
            CAutoparte.GANANCIA=porcentaje;
        }
        
        public CAutoparte (uint codigo)
        {
            this.codPieza=codigo;
        }
        public void setDescripcion(string detalle)
        {
            this.descripcion = detalle;
        }
       public void setCosto(float monto)
       {
           this.costo=monto;
       }
       public float darPrecio()
       {
           return this.costo * (1F + CAutoparte.GANANCIA / 100);
       }
       public string darDatos() 
       {
           string datos= "Cod: " + System.Convert.ToString(this.codPieza);
           datos+=" - " + this.descripcion;
           datos+=" - Costo: $" + System.Convert.ToString(this.costo) ;
           datos+=" - Precio: $ " + System.Convert.ToString(this.darPrecio());
           return datos;
       }
       public bool costoMayorQue(CAutoparte otraAutoparte)
       {
           if (this.darPrecio()>otraAutoparte.darPrecio()) return true;
           return false;
       }
        public float darPrecio(ushort cuotas)
        {
            if(cuotas > 1) return (this.darPrecio(System.Convert.ToUInt16(cuotas - 1)) * 1.1F);
            return this.darPrecio();
            //return this.darPrecio() *(1+ ((cuotas - 1) * 0.1F));
        }        
    }
}
