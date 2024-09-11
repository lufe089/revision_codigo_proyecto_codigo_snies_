#ifndef PROGRAMA_ACADEMICO_H
#define PROGRAMA_ACADEMICO_H
/*Todo el codigo va entre estas guardas*/
#include <cstdio>
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "Consolidado.h"

using namespace std;

class ProgramaAcademico
{
protected:
    int codigoDeLaInstitucion;
    int iesPadre;
    string institucionDeEducacionSuperiorIes;
    string principalOSeccional;
    int idSectorIes;
    string sectorIes;
    int idCaracter;
    string caracterIes;
    int codigoDelDepartamentoIes;
    string departamentoDeDomicilioDeLaIes;
    int codigoDelMunicipioIes;
    string municipioDeDomicilioDeLaIes;
    int codigoSniesDelPrograma;
    string programaAcademico;
    int idNivelAcademico;
    string nivelAcademico;
    int idNivelDeFormacion;
    string nivelDeFormacion;
    int idMetodologia;
    string metodologia;
    int idArea;
    string areaDeConocimiento;
    int idNucleo;
    string nucleoBasicoDelConocimientoNbc;
    int idCineCampoAmplio;
    string descCineCampoAmplio;
    int idCineCampoEspecifico;
    string descCineCampoEspecifico;
    int idCineCodigoDetallado;
    string descCineCodigoDetallado;
    int codigoDelDepartamentoPrograma;
    string departamentoDeOfertaDelPrograma;
    int codigoDelMunicipioPrograma;
    string municipioDeOfertaDelPrograma;
    vector<Consolidado *> consolidados;

public:
    ProgramaAcademico();

    void setCodigoDeLaInstitucion(int);
    int getCodigoDeLaInstitucion();

    void setIesPadre(int);
    int getIesPadre();

    void setInstitucionDeEducacionSuperiorIes(string &);
    string getInstitucionDeEducacionSuperiorIes();

    void setPrincipalOSeccional(string &);
    string getPrincipalOSeccional();

    void setIdSectorIes(int);
    int getIdSectorIes();

    void setSectorIes(string &);
    string getSectorIes();

    void setIdCaracter(int);
    int getIdCaracter();

    void setCaracterIes(string &);
    string getCaracterIes();

    void setCodigoDelDepartamentoIes(int);
    int getCodigoDelDepartamentoIes();

    void setDepartamentoDeDomicilioDeLaIes(string &);
    string getDepartamentoDeDomicilioDeLaIes();

    void setCodigoDelMunicipioIes(int);
    int getCodigoDelMunicipioIes();

    void setMunicipioDeDomicilioDeLaIes(string &);
    string getMunicipioDeDomicilioDeLaIes();

    void setCodigoSniesDelPrograma(int);
    int getCodigoSniesDelPrograma();

    void setProgramaAcademico(string &);
    string getProgramaAcademico();

    void setIdNivelAcademico(int);
    int getIdNivelAcademico();

    void setNivelAcademico(string &);
    string getNivelAcademico();

    void setIdNivelDeFormacion(int);
    int getIdNivelDeFormacion();

    void setNivelDeFormacion(string &);
    string getNivelDeFormacion();

    void setIdMetodologia(int);
    int getIdMetodologia();
    void setMetodologia(string &);
    string getMetodologia();

    void setIdArea(int);
    int getIdArea();
    void setAreaDeConocimiento(string &);
    string getAreaDeConocimiento();
    void setIdNucleo(int);
    int getIdNucleo();
    void setNucleoBasicoDelConocimientoNbc(string &);
    string getNucleoBasicoDelConocimientoNbc();
    void setIdCineCampoAmplio(int);
    int getIdCineCampoAmplio();
    void setDescCineCampoAmplio(string &);
    string getDescCineCampoAmplio();
    void setIdCineCampoEspecifico(int);
    int getIdCineCampoEspecifico();
    void setDescCineCampoEspecifico(string &);
    string getDescCineCampoEspecifico();
    void setIdCineCodigoDetallado(int);
    int getIdCineCodigoDetallado();
    void setDescCineCodigoDetallado(string &);
    string getDescCineCodigoDetallado();
    void setCodigoDelDepartamentoPrograma(int);
    int getCodigoDelDepartamentoPrograma();
    void setDepartamentoDeOfertaDelPrograma(string &);
    string getDepartamentoDeOfertaDelPrograma();
    void setCodigoDelMunicipioPrograma(int);
    int getCodigoDelMunicipioPrograma();
    void setMunicipioDeOfertaDelPrograma(string &);
    string getMunicipioDeOfertaDelPrograma();
    void setConsolidado(Consolidado *, int);
    Consolidado *getConsolidado(int);
    ~ProgramaAcademico();
};

#endif