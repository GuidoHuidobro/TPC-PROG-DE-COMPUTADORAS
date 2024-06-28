#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "universidad.h"
#define LARGOMIEMBROS 300
#define LARGOMATERIAS 40
#define LARGOCARRERAS 10
#define LARGODEPARTAMENTOS 4
int main(){
    char opcion='*';
    int menu=0;
    int opcionmenu=0;
    int numdep=-1;
    int numcar=-1;
    int nummat=-1;
    int CantidadAIngresar=-1;
    int VectorNumeroMiembros[LARGOMIEMBROS];
    int *PunteroVecNumMiembros=VectorNumeroMiembros;
    int VectorNumeroMaterias[LARGOMATERIAS];
    int *PunteroVecNumMaterias=VectorNumeroMaterias;
    int VectorNumeroCarreras[LARGOCARRERAS];
    int *PunteroVecNumCarreras=VectorNumeroCarreras;
    int VectorNumeroDepartamentos[LARGODEPARTAMENTOS];
    int *PunteroVecNumDepartamentos=VectorNumeroDepartamentos;
    CargarArrayNumeroAlumnos(PunteroVecNumMiembros,LARGOMIEMBROS);
    CargarArrayNumeroMaterias(PunteroVecNumMaterias,LARGOMATERIAS);
    CargarArrayNumeroCarreras(PunteroVecNumCarreras,LARGOCARRERAS);
    CargarArrayNumeroDepartamentos(PunteroVecNumDepartamentos,LARGODEPARTAMENTOS);
    Universidad UNLa;
    UNLa=CargarDatos(LARGODEPARTAMENTOS,LARGOCARRERAS,LARGOMATERIAS);
    MostrarUniversidad(UNLa);
    Departamentoss();
    // Primero, le pregunto al usuario si desea saber acerca de los departamentos
    OpcionMostrarDepartamentos();
    fflush(stdin);
    scanf("%c",&opcion);
    printf("\n\n");
    switch(opcion)
    {
    case '1':
        MostrarDepartamentos(UNLa,LARGODEPARTAMENTOS,PunteroVecNumDepartamentos);
        break;
    }
    opcion='*';
    Carrerass(); // Imprimo titulo
    while(numdep!=0){ //
        OpcionMostrarCarreras(UNLa); // Ingrese 1 para acceder al DDPyT, 2 para acceder al Dep. Salud Comunitaria, etc...
        scanf("%d",&numdep); // El scanf va a pedir el numero de dep. (1,2,3 o 4). si ingresa un 0,
        printf("\n\n");      // No entra al if (No muestra ninguna carrera, y no vuelve a entrar al while
        if(numdep!=0){
            MostrarCarreras(UNLa,numdep,PunteroVecNumCarreras);
        }
    }
    Materiass(); // Este procedimiento solo muestra un título
    printf("1) Acceda al departamento en el cual se encuentra la carrera que busca.\n");
    printf("2) Elija la carrera para ver su plan de estudio.\n\n\n");
    while(numdep!=(-1)){ // En el procedimiento OpcionMostrarMaterias, si el usuario ingresa 0, a numdep se le guardará -1
        OpcionMostrarMaterias(UNLa,&numdep,&numcar);
        if(numdep!=(-1)){ // Si ingreso 0, numdep va a valer -1, entonces no muestra nada y sale del while
            MostrarMaterias(UNLa,numdep,numcar);
        }
    }
    numdep=0; // Cambio el valor de la variable para que entre al proximo while...
    TituloIngresoEstudiantes();
    printf("1) Acceda al departamento en el cual se encuentra la materia de la carrera que desea completar con los datos de sus integrantes (docentes y alumnos).\n");
    printf("2) Acceda a la carrera.\n");
    printf("3) Acceda a la materia y elija cuantos integrantes desea ingresar.\n\n\n");
    while((numdep>=0)&&(numdep<=3)){ // Mientras el usuario no ingrese 0,
        OpcionCargarMiembros(UNLa,&numdep,&numcar,&nummat);
        if((numdep>=0)&&(numdep<=3)){
            CargarMiembros(UNLa,numdep,numcar,nummat);
        }
    }
    numdep=0; // Cambio el valor de la variable para que entre al proximo while...
    TituloMostrarIntegrantes();
    printf("1) Acceda al departamento en el cual se encuentra la materia que contiene los datos que desea ver.\n");
    printf("2) Acceda a la carrera correspondiente.\n");
    printf("3) Acceda a la materia.\n\n\n");
    while((numdep>=0)&&(numdep<=3)){
        OpcionMostrarMiembros(UNLa,&numdep,&numcar,&nummat);
        if((numdep>=0)&&(numdep<=3)){
            MostrarMiembros(UNLa,numdep,numcar,nummat);
        }
    }
    Ordenamientoo();
    while(menu!=(-1)){
        MensajeMenu(&menu);
        if((menu>=0)&&(menu<=3)){ // Entra si el usuario ingresó un numero entre 1 y 4, ya que en el procedimiento
            switch(menu)          // se le resta 1 a menu
            {
            case 0: // El usuario quiere ordenar los departamentos
                MensajeMenuDepartamentos(&opcionmenu); //
                OrdenarDepartamentos(UNLa,PunteroVecNumDepartamentos,LARGODEPARTAMENTOS,&opcionmenu);
                break;
            case 1: // El usuario quiere ordenar las Carreras
                MensajeMenuCarreras(UNLa,&numdep,&opcionmenu);
                OrdenarCarreras(UNLa,PunteroVecNumCarreras,&opcionmenu,numdep);
                break;
            case 2: // El usuario quiere ordenar las materias
                MensajeMenuMaterias(UNLa,&numdep,&numcar,&opcionmenu);
                OrdenarMaterias(UNLa,PunteroVecNumMaterias,&opcionmenu,numdep,numcar);
                break;
            case 3: // El usuario quiere ordenar los departamentos
                MensajeMenuMiembros(UNLa,&numdep,&numcar,&nummat,&opcionmenu);
                OrdenarMiembros(UNLa,PunteroVecNumMiembros,&opcionmenu,numdep,numcar,nummat);
                break;
            }

        }
    }
    menu=1;
    Busquedaa();
    while((menu>=1)&&(menu<=4)){
        MensajeMenuBusqueda(&menu);
        if((menu>=1)&&(menu<=4)){
            switch(menu)
            {
            case 1:
                BuscarDepartamento(UNLa,PunteroVecNumDepartamentos,LARGODEPARTAMENTOS);
                break;
            case 2:
                BuscarCarreras(UNLa,LARGODEPARTAMENTOS);
                break;
            case 3:
                BuscarMaterias(UNLa,LARGODEPARTAMENTOS);
                break;
            case 4:
                BuscarMiembros(UNLa,LARGODEPARTAMENTOS);
                break;
            }
        }
    }
    MensajeCerrar();
    return 0;
}
