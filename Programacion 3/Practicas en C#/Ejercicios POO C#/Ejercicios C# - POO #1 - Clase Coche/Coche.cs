using System;
using System.Collections.Generic;
using System.Text;

namespace Jueguito
{
    class Coche
    {
        private int _id;
        private string _marca;
        private string _modelo;
        private int _KM;
        private double _precio;

        public Coche(int id, string marca, string modelo, int km, float precio)
        {
            _id = id;
            _marca = marca;
            _modelo = modelo;
            _KM = km;
            _precio = precio;
        }

        public int Id { get => _id; set => _id = value; }
        public string Marca { get => _marca; set => _marca = value; }
        public string Modelo { get => _modelo; set => _modelo = value; }
        public int KM { get => _KM; set => _KM = value; }
        public double Precio { get => _precio; set => _precio = value; }

        public override string ToString()
        {
            return "Marca: "+_marca+"Modelo: "+_modelo+"Precio: "+_precio;
        }
    }
}
