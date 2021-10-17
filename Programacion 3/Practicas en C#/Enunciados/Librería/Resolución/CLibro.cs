using System;

namespace Librería
{
    class CLibro
    {
        private ulong iSBN;
        private string signaTopog;
        private float costo;

        public CLibro(ulong numISBN)
        {
            this.iSBN = numISBN;
        }
        public void setSignaTopog(string codigo)
        {
            this.signaTopog = codigo;
        }
        public void setCosto(float monto)
        {
            this.costo=monto;
        }
        public float darPrecio()
        {
            return this.costo * 1.15f;
        }
        public string darDatos()
        {
            string datos = "ISBN: " + Convert.ToString(this.iSBN);
            datos += " - Signatura Topográfica: " + this.signaTopog;
            datos += " - Costo: $" + Convert.ToString(this.costo);
            datos += " - Precio: $" + Convert.ToString(this.darPrecio());
            return datos;
        }
        public bool esMasBaratoQue(CLibro otroLibro)
        {
            if (this.darPrecio() < otroLibro.darPrecio()) return true;
            return false;
        }
        public float darPrecio(float descuento)
        {
            if (descuento > 0)
            {
                return this.darPrecio() * (1 - (descuento / 100.0f));
            }
            return darPrecio();
        }
    }
}
