#include <iostream>

using namespace std;


class Postulante
{
public :
    Postulante(char *_email, char *_fechaPres, bool _sabeIngles, int _lugarTrab);
    ~Postulante() ;

    char *email;
    char *fechaPres;
    bool sabeIngles;
    int  lugarTrab;  //  1.- Remoto 2.- Presencial 3.- Indistinto

    Postulante *sig;
};


class OfertaLaboral
{

public:
    OfertaLaboral(char *_tituloPuesto, char *_fechaCierre, bool _reqIngles, int lugarTrab);
    ~OfertaLaboral();

    char *tituloPuesto; // titulo del puesto buscado
    char *fechaCierre; // fecha de cierre
    bool reqIngles; // requiere ingles o no,
    int lugarTrab; // 1.- Remoto, 2.- Presencial.

    // Lista de postulantes
    Postulante *inicioP;

    OfertaLaboral *sig;
};


class Empresa
{
private:
    OfertaLaboral *inicioOL;

public:
    Empresa();
    ~Empresa();

    void MostrarCandidatosCorrectos();
    void PorcentajeIngles(); // porcentaje de las ofertas requieren ingles
};



int main(){
    
    return 0;
}


Postulante::Postulante(char *_email, char *_fechaPres, bool _sabeIngles, int _lugarTrab)
{
    email= _email;
    fechaPres= _fechaPres;
    sabeIngles= _sabeIngles;
    lugarTrab= _lugarTrab;

    sig= 0;
}

Postulante::~Postulante()
{

}

OfertaLaboral::OfertaLaboral(char *_tituloPuesto, char *_fechaCierre, bool _reqIngles, int _lugarTrab)
{
    tituloPuesto= _tituloPuesto;
    fechaCierre= _fechaCierre;
    reqIngles= _reqIngles;
    lugarTrab= _lugarTrab;

    inicioP= 0;
    sig= 0;
}

OfertaLaboral::~OfertaLaboral()
{

}

Empresa::Empresa()
{
    inicioOL= 0;

}

Empresa::~Empresa()
{



}


void Empresa::MostrarCandidatosCorrectos()
{
    Postulante *p;

    // Buscar todas las ofertas laborales
    OfertaLaboral *ol= inicioOL;
    while(ol)
    {
        p= ol->inicioP;
        while(p)
        {
            if((ol->reqIngles && p->sabeIngles) || !ol->reqIngles)
            {
                if(p->lugarTrab == 3 || ol->lugarTrab == p->lugarTrab)
                {
                    cout << "\nEmail: " << p->email << ", Fecha Presentacion: " << p->fechaPres;
                }
            }

            p= p->sig;
        }

        ol= ol->sig;
    }

}

void Empresa::PorcentajeIngles()   // porcentaje de las ofertas requieren ingles
{
    int contTotal= 0;
    int cont= 0;

    // Buscar todas las ofertas laborales
    OfertaLaboral *ol= inicioOL;
    while(ol)
    {
        if(ol->reqIngles)
        {
            cont++;
        }

        contTotal++;
        ol= ol->sig;
    }

    if(contTotal > 0)
    {
        float porc= ((float) cont) / contTotal;
        cout << "\nPorcentaje: " << porc;
    }
    else
    {
        cout << "\nNo hay ofertas registrada";
    }

}

