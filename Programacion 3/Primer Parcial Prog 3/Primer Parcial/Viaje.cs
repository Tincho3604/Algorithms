using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Primer_Parcial {
     class Viaje {
        static private float _costoPorKilometro;
        static private int _kilometrajeMinimo;
        private string _dominio;
        private int _distanciaRecorrida;
        public float _precioFinal;
        private int _kilometraje;

        // Punto 1
        public Viaje() {
            _costoPorKilometro = 0F;
            _kilometrajeMinimo = 0;
            _dominio = "Sin Datos";
            _distanciaRecorrida = 0;
            _precioFinal = 0F;
        }

        // Punto 2
        public void setCostoPorKilometro(float costoParam) {
            _costoPorKilometro = costoParam;
        }
        public float getCostoPorKilometro() {
            return _costoPorKilometro;
        }

        public void setKilometrajeMinimo(int kilometrajeParam) {
            _kilometrajeMinimo = kilometrajeParam;
        }
        public int getKilometrajeMinimo() {
            return _kilometrajeMinimo;
        }

        // Punto 3

        public Viaje(string dominioParam, int distanciaParam) {
            _dominio = dominioParam;
            _distanciaRecorrida = distanciaParam;
        }

        // Punto 4
        public string getDominio() {
            return _dominio;
        }

        public void setDominio(string dominioParam) {
            _dominio = dominioParam;
        }

        // Punto 6

        public void setPrecioFinal() {
            float precioFinalVariable = 0F;

            if(_distanciaRecorrida < _kilometrajeMinimo) {

                precioFinalVariable = _costoPorKilometro * _kilometrajeMinimo;

            } else {
               
                precioFinalVariable = _costoPorKilometro * _distanciaRecorrida;
            }
            _precioFinal = precioFinalVariable;
        }
    
        // Punto 7
        public bool compararCon(Viaje VViaje) {

            return VViaje._precioFinal < _precioFinal;
           
        }

        // Punto 8
        public string darDatos() {
          
           string warningCobro = _distanciaRecorrida < _kilometrajeMinimo ? "¡ATENCION! Se cobro el precio por kilometraje mínimo." : "";
            Console.WriteLine("VALOR " + warningCobro);
            return "Costo por kilometro: " + _costoPorKilometro + " Kilometraje Minimo: " + _kilometrajeMinimo + " Dominio: " + _dominio + " Distancia Recorrida: " + _distanciaRecorrida + " Precio Final: " + _precioFinal + warningCobro;

        }

    }
}
