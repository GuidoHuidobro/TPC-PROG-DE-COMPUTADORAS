#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "universidad.h"
#define LARGOMIEMBROS 300
#define LARGOMATERIAS 40
#define LARGOCARRERAS 10
#define LARGODEPARTAMENTOS 4
struct Estructura_Miembros{
    char nombre_completo[40];
    char dni[10];
    char doc_o_alum[10];
};
struct Estructura_Materia{
    char nombre_materia[85];
    char codigo[7];
    int contarintegrantes; // Los contar son por si no se cargan todos los datos
    int secargo;
    Miembros mie[LARGOMIEMBROS]; // La añido con la estructura de 300 integrantes
};
struct Estructura_Carrera{
    char nombre_carrera[75];
    char titulo[250];
    int contarmaterias;
    Materias mat[LARGOMATERIAS]; // La añido con la estructura de 40 materias
};
struct Estructura_Departamento{
    char nombre[60];
    char descripcion[45];
    int contarcarreras;
    Carreras car[LARGOCARRERAS]; // La añido con la estructura de máximo 10 carreras
};
struct Estructura_Universidad{
    char nombre[35];
    char direccion[70];
    char contacto[15];
    Departamentos dep[LARGODEPARTAMENTOS]; // La añido con la estructura de 4 departamentos
};
void Departamentoss(){ // Este procedimiento solo imprime un titulo
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                                                            Departamentos                                                                          |\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
}
void Carrerass(){
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                                                               Carreras                                                                            |\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
}
void Materiass(){
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                                                               Materias                                                                            |\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
}
void TituloIngresoEstudiantes(){
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                                                     Ingreso estudiantes y docentes                                                                |\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
}
void TituloMostrarIntegrantes(){
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                                                     Mostrar estudiantes y docentes                                                                |\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
}
void Busquedaa(){
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                                                               Busqueda                                                                            |\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
}
void Ordenamientoo(){
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                                                             Ordenamiento                                                                          |\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
}
void MensajeCerrar(){
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                                                          Cierre el programa                                                                       |\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
}
void MensajeMenu(int *Menu){
    int i=0;
    for(i=0;i<4;i=i+1){
        switch(i)
        {
        case 0:
            printf("Ingrese '%d' para ordenar los departamentos.\n",(i+1));
            break;
        case 1:
            printf("Ingrese '%d' para ordenar las carreras.\n",(i+1));
            break;
        case 2:
            printf("Ingrese '%d' para ordenar las materias.\n",(i+1));
            break;
        case 3:
            printf("Ingrese '%d' para ordenar los integrantes.\n",(i+1));
            break;
        }
    }
    printf("Ingrese '0' para salir del proceso de ordenamiento.\n");
    scanf("%d",Menu);
    *Menu=(*Menu)-1; // Si el usuario quiere salir del programa, le mando -1 al menú
    printf("\n\n");
}
void MensajeMenuBusqueda(int *Menu){
    printf("Ingrese '1' para buscar un departamento.\n");
    printf("Ingrese '2' para buscar una carrera.\n");
    printf("Ingrese '3' para buscar una materia.\n");
    printf("Ingrese '4' para buscar un integrante.\n");
    printf("Ingrese '0' para salir del menu de busqueda y finalizar la ejecucion del programa.\n");
    scanf("%d",Menu);
    printf("\n\n");
}
void MensajeMenuDepartamentos(int *OpcionMenu){ // Se pueden ordenar alfabéticamente, y por cant. de carreras (may a men y men a may)
    int i=0;
    for(i=0;i<3;i=i+1){
        switch(i)
        {
        case 0:
            printf("Ingrese '%d' para ordenar los departamentos alfabeticamente por nombre.\n",(i+1));
            break;
        case 1:
            printf("Ingrese '%d' para ordenar los departamentos por cantidad de carreras (de menor a mayor).\n",(i+1));
            break;
        case 2:
            printf("Ingrese '%d' para ordenar los departamentos por cantidad de carreras (de mayor a menor).\n",(i+1));
            break;
        }
    }
    scanf("%d",OpcionMenu);
    printf("\n\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
}
void MensajeMenuCarreras(Universidad U, int *NumDep, int *OpcionMenu){
    // Se pueden ordenar por cantidad de materias(De menor a mayor y de mayor a menor), alfabeticamente
    int i=0;
    int aux=0;
    for(i=0;i<LARGODEPARTAMENTOS;i=i+1){
        printf("Ingrese '%d' para ordenar las carreras del '%s'.\n",(i+1),U->dep[i].nombre);
    }
    scanf("%d",&aux);
    aux--;
    *NumDep=aux; // Le paso el valor real del departamento al que quiere acceder
    printf("\n\n");
    for(i=0;i<3;i=i+1){
        switch(i)
        {
        case 0:
            printf("Ingrese '%d' para ordenar las carreras del %s alfabeticamente por nombre.\n",(i+1),U->dep[aux].nombre);
            break;
        case 1:
            printf("Ingrese '%d' para ordenar las carreras del %s por cantidad de materias (de menor a mayor).\n",(i+1),U->dep[aux].nombre);
            break;
        case 2:
            printf("Ingrese '%d' para ordenar las carreras del %s por cantidad de materias (de mayor a menor).\n",(i+1),U->dep[aux].nombre);
            break;
        }
    }
    scanf("%d",OpcionMenu);
    printf("\n\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
}
void MensajeMenuMaterias(Universidad U, int *NumDep, int *NumCar, int *OpcionMenu){
    int i=0;
    int aux=0;
    int aux2=0;
    for(i=0;i<LARGODEPARTAMENTOS;i=i+1){
        printf("Ingrese '%d' para acceder al '%s'.\n",(i+1),U->dep[i].nombre);
    }
    scanf("%d",&aux);
    aux--;
    *NumDep=aux;
    printf("\n\n");
    for(i=0;i<(U->dep[aux].contarcarreras);i=i+1){
        printf("Ingrese '%d' para acceder a la carrera %s.\n",(i+1),U->dep[aux].car[i].nombre_carrera);
    }
    scanf("%d",&aux2);
    aux2--;
    *NumCar=aux2;
    printf("\n\n");
    for(i=1;i<=4;i=i+1){
        switch(i)
        {
        case 1:
            printf("Ingrese '%d' para ordenar las materias de la carrera '%s' alfabeticamente por nombre.\n",i,U->dep[aux].car[aux2].nombre_carrera);
            break;
        case 2:
            printf("Ingrese '%d' para ordenar las materias de la carrera '%s' por codigo.\n",i,U->dep[aux].car[aux2].nombre_carrera);
            break;
        case 3:
            printf("Ingrese '%d' para ordenar las materias de la carrera '%s' por cantidad de integrantes (de menor a mayor).\n",i,U->dep[aux].car[aux2].nombre_carrera);
            break;
        case 4:
            printf("Ingrese '%d' para ordenar las materias de la carrera '%s' por cantidad de integrantes (de mayor a menor).\n",i,U->dep[aux].car[aux2].nombre_carrera);
            break;
        }
    }
    scanf("%d",OpcionMenu);
    printf("\n\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
}
void MensajeMenuMiembros(Universidad U, int *NumDep, int *NumCar, int *NumMat, int *OpcionMenu){
    int i=0;
    int aux=0;
    int aux2=0;
    int aux3=0;
    for(i=0;i<LARGODEPARTAMENTOS;i=i+1){
        printf("Ingrese '%d' para acceder al '%s'.\n",(i+1),U->dep[i].nombre);
    }
    scanf("%d",&aux);
    aux--;
    *NumDep=aux;
    printf("\n\n");
    for(i=0;i<(U->dep[aux].contarcarreras);i=i+1){
        printf("Ingrese '%d' para acceder a %s.\n",(i+1),U->dep[aux].car[i].nombre_carrera);
    }
    scanf("%d",&aux2);
    aux2--;
    *NumCar=aux2;
    printf("\n\n");
    for(i=0;i<(U->dep[aux].car[aux2].contarmaterias);i=i+1){
        printf("Ingrese '%d' para acceder a los miembros de %s.\n",(i+1),U->dep[aux].car[aux2].mat[i].nombre_materia);
    }
    scanf("%d",&aux3);
    aux3--;
    *NumMat=aux3;
    printf("\n\n");
    for(i=1;i<=3;i=i+1){
        switch(i)
        {
        case 1:
            printf("Ingrese %d para ordenar los miembros de %s alfabeticamente por nombre.\n",(i),U->dep[aux].car[aux2].mat[aux3].nombre_materia);
            break;
        case 2:
            printf("Ingrese %d para ordenar los miembros de %s por D.N.I.\n",(i),U->dep[aux].car[aux2].mat[aux3].nombre_materia);
            break;
        }
    }
    scanf("%d",OpcionMenu);
    printf("\n\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
}
void OpcionMostrarDepartamentos(){ // Este procedimiento solo es de impresion de un mensaje
    printf("Ingrese '1' si desea conocer los departamentos de la UNLa.\n");
    printf("Ingrese '0' si no quiere ver nada.\n");
}
void OpcionMostrarCarreras(Universidad U){
    int i=0;
    for(i=0;i<LARGODEPARTAMENTOS;i=i+1){ // si ingresas 1, accedes al DDPyT, si ingresas 2 -> Salud comunitaria
        printf("Ingrese '%d' para ver las carreras del '%s'.\n",(i+1),U->dep[i].nombre);
    }
    printf("Ingrese '0' si no quiere ver nada.\n");
}
void OpcionMostrarMaterias(Universidad U, int *PuntNumDep, int *PuntNumCarrera){
    int i=0;
    int aux; // aux para el numero de departamento
    int aux2; // aux para el numero de carrera
    for(i=0;i<LARGODEPARTAMENTOS;i=i+1){
        printf("Ingrese '%d' para acceder al %s.\n",(i+1),U->dep[i].nombre); // 1->DDPyT, 2->Salud Com, 3-> Planif. y pol
    }
    printf("Ingrese '0' si no quiere ver nada.\n");
    scanf("%d",&aux);
    aux--; // Le paso la posicion real del departamento...
    *(PuntNumDep)=aux; // Desde el main, le paso a la dir. de 'numdep' la posicion del departamento que ingreso el usuario
    if(aux!=(-1)){ // Si ingreso 0, el usuario quiere salir. Como en la instruccion anterior decrementa, se evalua en -1.
        printf("\n\n");
        for(i=0;i<(U->dep[aux].contarcarreras);i=i+1){ // Recorro las carreras del departamento correspondiente...
            printf("Ingrese '%d' para ver el plan de estudios de %s\n",(i+1),U->dep[aux].car[i].nombre_carrera);
        }
        scanf("%d",&aux2); // si ingreso 1, le tengo que mostrar el plan de estudios de la carrera en la pos 0
        aux2--; // Para eso, lo decremento en 1
        *(PuntNumCarrera)=aux2;
    }
    printf("\n\n");
}
void OpcionCargarMiembros(Universidad U, int *NumDep, int *NumCar, int *NumMat){
    int i=0;
    int aux=0;
    int aux2=0;
    int aux3=0;
    for(i=0;i<LARGODEPARTAMENTOS;i++){
        printf("Ingrese '%d' para acceder al %s.\n",(i+1),U->dep[i].nombre);
    }
    printf("Ingrese '0' para finalizar el ingreso de datos.\n");
    scanf("%d",&aux);
    aux--;
    *NumDep=aux; // Le paso la posicion real al departamento
    if(aux>(-1)){ // Si el usuario no ingresó 0, le sigo preguntando...
        printf("\n\n");
        for(i=0;i<(U->dep[aux].contarcarreras);i++){ // Recorro las carreras de ese departamento
            printf("Ingrese '%d' para acceder a la carrera '%s'.\n",(i+1),U->dep[aux].car[i].nombre_carrera);
        }
        scanf("%d",&aux2);
        aux2--;
        *NumCar=aux2;
        printf("\n\n");
        for(i=0;i<(U->dep[aux].car[aux2].contarmaterias);i++){
            printf("Ingrese '%d' para acceder a %s.\n",(i+1),U->dep[aux].car[aux2].mat[i].nombre_materia);
        }
        scanf("%d",&aux3);
        aux3--;
        *NumMat=aux3;
        printf("\n\nCuantos miembros va a ingresar?\n");
        scanf("%d",&(U->dep[aux].car[aux2].mat[aux3].contarintegrantes));
    }
    printf("\n\n");
}
void OpcionMostrarMiembros(Universidad U, int *NumDep, int *NumCar, int *NumMat){
    int i=0;
    int aux=0;
    int aux2=0;
    int aux3=0;
    for(i=0;i<LARGODEPARTAMENTOS;i++){
        printf("Ingrese '%d' para acceder al %s.\n",(i+1),U->dep[i].nombre);
    }
    printf("Ingrese '%d' para salir.\n",0);
    scanf("%d",&aux);
    aux--;
    *NumDep=aux;
    if((aux>=0)&&(aux<=3)){
        printf("\n\n");
        for(i=0;i<(U->dep[aux].contarcarreras);i++){
            printf("Ingrese '%d' para acceder a la carrera %s.\n",(i+1),U->dep[aux].car[i].nombre_carrera);
        }
        scanf("%d",&aux2);
        aux2--;
        *NumCar=aux2;
        printf("\n\n");
        for(i=0;i<(U->dep[aux].car[aux2].contarmaterias);i++){
            printf("Ingrese '%d' para acceder a %s.\n",(i+1),U->dep[aux].car[aux2].mat[i].nombre_materia);
        }
        scanf("%d",&aux3);
        aux3--;
        *NumMat=aux3;
    }
    printf("\n\n");
}
void CargarArrayNumeroAlumnos(int *punt, int l){ // El puntero debe apuntar a la posicion 0
    int i=0;
    for(i=0;i<l;i=i+1){
        punt[i]=(i+1);
    }
}
void CargarArrayNumeroMaterias(int *punt, int l){
    int i=0;
    for(i=0;i<l;i=i+1){
        punt[i]=(i+1);
    }
}
void CargarArrayNumeroCarreras(int *punt, int l){
    int i=0;
    for(i=0;i<l;i=i+1){
        punt[i]=(i+1);
    }
}
void CargarArrayNumeroDepartamentos(int *punt, int l){
    int i=0;
    for(i=0;i<l;i=i+1){
        punt[i]=(i+1);
    }
}
Universidad CargarDatos(int departamentos, int carreras, int materias){
    int i=0;            // Los parámetros son para pasarle el largo de cada vector de estructuras
    int j=0;
    int k=0;
    // Variables para los bucles for...
    Universidad U=malloc(sizeof(struct Estructura_Universidad)); // Reservo memoria para la estructura universidad
    strcpy(U->nombre,"Universidad Nacional de Lanus"); // Nombre de la universidad
    strcpy(U->direccion,"29 de Septiembre 3901, Remedios de Escalada, Buenos Aires, Argentina"); // Direccion
    strcpy(U->contacto,"011-5533-5600"); // Contacto de la universidad
    for(i=0;i<departamentos;i=i+1){
        (U->dep[i].contarcarreras)=0; // Cada vez que entra a un departamento nuevo, la cantidad de carreras
        switch(i)                     // que tiene ese departamento es 0, a medida que se van cargando las carreras, el entero aumenta
        {                             // en 1
        case 0: // Departamento en la posición 0 (Desarrollo productivo y tecnológico).
            strcpy(U->dep[i].nombre,"Departamento de Desarrollo Productivo y Tecnologico");
            strcpy(U->dep[i].descripcion,"Director: Dr. Pablo Narvaja");
            for(j=0;j<carreras;j=j+1){ // Dentro del dep. DPyT cargo las carreras...
                (U->dep[i].car[j].contarmaterias)=0; // Cada vez que entra a una carrera distinta, la cantidad de
                switch(j)   // materias es 0. A medida que se van cargando, este valor va incrementando
                {
                case 0: // Carrera en la posicion 0, carrera en la posicion 1....
                    strcpy(U->dep[i].car[j].nombre_carrera,"Licenciatura en Gestion Ambiental Urbana");
                    strcpy(U->dep[i].car[j].titulo,"Esta carrera te capacita para intervenir en la gestion de los procesos ambientales urbanos con fines sustentables");
                    for(k=0;k<materias;k=k+1){ // Dentro de la carrera correspondiente
                        switch(k) // Ingreso cada una de las materias de la carrera correspondiente
                        {
                        case 0:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Introduccion a la problematica urbana");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"01");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera correspondiente ya hay una materia más
                            break;
                        case 1:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Ambiente 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"02");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera correspondiente ya hay una materia más
                            break;
                        case 2:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Geografia urbana");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"03");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera correspondiente ya hay una materia más
                            break;
                        case 3:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Introduccion al esarrollo sustentable");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"04");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera correspondiente ya hay una materia más
                            break;
                        case 4:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller de ciencias aplicadas al ambiente");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"05");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera correspondiente ya hay una materia más
                            break;
                        case 5:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Tecnicas en cartografia y fotointerpretacion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"06");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera correspondiente ya hay una materia más
                            break;
                        case 6:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Principios de administracion y gestion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"07");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera correspondiente ya hay una materia más
                            break;
                        case 7:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Matematica y estadistica aplicada a estudios ambientales");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"08");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera correspondiente ya hay una materia más
                            break;
                        case 8:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Sociologia ambiental");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"09");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera correspondiente ya hay una materia más
                            break;
                        case 9:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Ciudad y territorio");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"10");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera correspondiente ya hay una materia más
                            break;
                        case 10:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Ambiente 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"11");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera correspondiente ya hay una materia más
                            break;
                        case 11:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller de investigacion urbana");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"12");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera correspondiente ya hay una materia más
                            break;
                        case 12:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Economia y desarrollo sustentable 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"13");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera correspondiente ya hay una materia más
                            break;
                        case 13:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Teledeteccion y sistemas de informacion geografica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"14");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera correspondiente ya hay una materia más
                            break;
                        case 14:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Educacion ambiental");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"15");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera correspondiente ya hay una materia más
                            break;
                        case 15:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Procesos urbanos 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"16");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera correspondiente ya hay una materia más
                            break;
                        case 16:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Fundamentos de ecologia");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"17");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera correspondiente ya hay una materia más
                            break;
                        case 17:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Procesos de evaluacion de impactos ambientales");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"18");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera correspondiente ya hay una materia más
                            break;
                        case 18:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Legislacion ambiental");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"19");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera correspondiente ya hay una materia más
                            break;
                        case 19:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Ambiente 3");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"20");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera correspondiente ya hay una materia más
                            break;
                        case 20:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Economia y desarrollo sustentable");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"21");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera correspondiente ya hay una materia más
                            break;
                        case 21:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Practica pre-profesional");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"22");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera correspondiente ya hay una materia más
                            break;
                        case 22:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Gestion administrativa municipal ambiental");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"23");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera correspondiente ya hay una materia más
                            break;
                        case 23:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Procesos urbanos 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"24");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera correspondiente ya hay una materia más
                            break;
                        case 24:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Redes 1: movilidad urbana");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"25");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera correspondiente ya hay una materia más
                            break;
                        case 25:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Politica ambiental en argentina y mercosur");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"33");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera correspondiente ya hay una materia más
                            break;
                        case 26:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Procesos de produccion del habitat");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"34");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera correspondiente ya hay una materia más
                            break;
                        case 27:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Ambiente 4");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"35");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera correspondiente ya hay una materia más
                            break;
                        case 28:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Formulacion y gestion de proyectos urbano-ambientales");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"36");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera correspondiente ya hay una materia más
                            break;
                        case 29:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Gestion ambiental y empresa");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"37");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera correspondiente ya hay una materia más
                            break;
                        case 30:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Procesos urbanos 3");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"38");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera correspondiente ya hay una materia más
                            break;
                        case 31:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Redes 2: servicios y saneamiento urbano");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"39");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera correspondiente ya hay una materia más
                            break;
                        case 32:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Auditoria ambiental");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"41");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera correspondiente ya hay una materia más
                            break;
                        case 33:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Financiamiento y evaluacion de proyectos urbano-ambientales");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"42");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera correspondiente ya hay una materia más
                            break;
                        case 34:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Negociacion y mediacion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"43");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera correspondiente ya hay una materia más
                            break;
                        } // Cierro switch para cargar cada una de las materias de Lic. en gestion ambiental urbana
                    } // Cierro FOR recorrer el vector de materias. Gestion ambiental tiene 35 materias curriculares
                    (U->dep[i].contarcarreras)++;
                    break;
                case 1:
                    strcpy(U->dep[i].car[j].nombre_carrera,"Licenciatura en Economia Empresarial");
                    strcpy(U->dep[i].car[j].titulo,"Esta carrera te capacita para responder ante la necesidad de alcanzar niveles de conpetitividad en la produccion de bienes y servicios, compatibles con las exigencias de costos, calidad y oportunidad que plantean los mercados internacionales");
                    for(k=0;k<materias;k=k+1){
                        switch(k)
                        {
                        case 0:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Historia economica contemporanea");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"01");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 1:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Contabilidad");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"02");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 2:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Introduccion a la matematica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"03");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 3:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller de produccion de textos de economia y administracion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"04");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 4:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Economia y sociedad");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"05");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 5:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Organizacion y gestion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"06");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 6:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Elementos de matematica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"07");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 7:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Microeconomia");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"08");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 8:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Derecho comercial");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"09");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 9:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Calculo financiero y desarrollo estadistico aplicado");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"10");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 10:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Macroeconomia");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"11");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 11:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Costos empresariales");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"12");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 12:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Derecho tributario");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"13");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 13:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Organizacion de la produccion y la tecnologia");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"14");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 14:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Control de gestion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"15");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 15:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Macroeconomia y politica economica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"16");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 16:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Comercializacion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"17");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 17:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Derecho del trabajo y de la seguridad social");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"18");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 18:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Comercio exterior y economia internacional");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"19");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 19:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Fininciamiento");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"20");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 20:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Plan de negocios");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"21");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 21:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller de integracion 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"22");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 22:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Formulacion y evaluacion de proyectos");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"23");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 23:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Gestion ambiental y empresa");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"24");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 24:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Sistemas de organizacion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"25");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 25:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Economia bancaria y financiera");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"26");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 26:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Administracion de los recursos humanos");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"27");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 27:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Economia industrial");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"28");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 28:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Problemas actuales de la economia argentina");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"35");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 29:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Etica y empresa");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"36");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 30:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Mediacion y negociacion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"37");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 31:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Politicas y estrategias para el desarrollo regional y local");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"38");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 32:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Planeamiento estrategico y toma de decisiones");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"41");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        } // Economia empresarial tiene 33 materias
                    }
                    (U->dep[i].contarcarreras)++;
                    break;
                case 2:
                    strcpy(U->dep[i].car[j].nombre_carrera,"Licenciatura en Economia Politica");
                    strcpy(U->dep[i].car[j].titulo,"Esta carrera te capacita para desempeñarte con buenos conocimientos en el sector privado y en el campo de las politicas economicas publicas");
                    (U->dep[i].contarcarreras)++;
                    for(k=0;k<materias;k=k+1){
                        switch(k)
                        {
                        case 0:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller de produccion de textos de economia y administracion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"01");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 1:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Introduccion a la matematica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"02");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 2:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Introduccion a la economia politica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"03");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 3:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Sociologia");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"04");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 4:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Economia clasica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"05");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 5:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Matematica para economistas 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"06");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 6:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Economia neoclasica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"08");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 7:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Estadistica 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"09");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 8:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Historia economica y social general");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"11");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 9:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Derecho publico y administrativo");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"12");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 10:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Economia keynesiana");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"13");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 11:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Historia economica y social argentina");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"16");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 12:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Matematica para economistas 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"17");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 13:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Topicos avanzados de economia clasica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"18");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 14:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Teorias recientes de economia politica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"19");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 15:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Planificacion estrategica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"20");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 16:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Cuentas nacionales y estructura economica argentina");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"21");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 17:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Macroeconomia argentina y latinoamericana");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"22");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 18:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller de analisis economico");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"23");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 19:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Estadistica 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"24");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 20:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Teorias de los precios y la competencia");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"25");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 21:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Finanzas publicas");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"26");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 22:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Matematica para economistas 3");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"27");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 23:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Organizacion de la produccion industrial y agropecuaria");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"28");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 24:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Teoria y politica monetaria");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"29");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 25:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Econometria");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"30");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 26:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Topicos avanzados de macroeconomia");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"31");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 27:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Desarrollo y subdesarrollo economico");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"32");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 28:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Sociologia y politicas publicas");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"33");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 29:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Desarrollo regional y sectorial");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"34");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 30:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Formulacion y evaluacion de proyectos");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"35");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 31:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Problemas actuales de la economia politica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"37");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 32:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Economia internacional");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"38");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 33:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Mencion economia del sector real");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"40a");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 34:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Mencion economia financiera");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"40b");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 35:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Crecimiento economico");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"42");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 36:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Mencion economia del sector real");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"43a");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 37:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Mencion economia financiera");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"43b");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 38:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller de elaboracion de trabajo final integrador");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"44");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        }
                    }
                    (U->dep[i].contarcarreras)++;
                    break;
                case 3:
                    strcpy(U->dep[i].car[j].nombre_carrera,"Licenciatura en Ciencia y Tecnologia de los Alimentos");
                    strcpy(U->dep[i].car[j].titulo,"Esta carrera te capacita en Fisico-Quimica, Microbiologia y Desarrollo y Fermentaciones Industriales");
                    for(k=0;k<materias;k=k+1){
                        switch(k)
                        {
                        case 0:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Matematica 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"3260");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 1:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Quimica general");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"3200");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 2:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Fisica 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"3201");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 3:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Biologia");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"3203");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 4:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Matematica 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"3261");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 5:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Quimica inorganica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"3204");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 6:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Fisica 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"3243");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 7:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Anatomia y fisiologia");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"3207");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 8:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Microbiologia general");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"3208");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 9:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Quimica organica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"3209");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 10:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Matematica 3");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"3247");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 11:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Fisicoquimica y biofisica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"3211");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 12:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Quimica analitica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"3212");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 13:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Quimica biologica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"3244");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 14:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Bromatologia 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"3245");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 15:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Industria y tecnologia de los alimentos 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"3216");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 16:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Microbiologia de los alimentos 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"3246");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 17:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Estadistica y bioestadistica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"3210");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 18:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Nutricion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"3219");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 19:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Bromatologia 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"3220");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 20:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"3222");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"Industria y tecnologia de los alimentos 2");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 21:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Equipos e instalaciones 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"3262");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 22:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Microbiologia de los alimentos 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"3248");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 23:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Toxicologia");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"3265");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 24:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Bromatologia 3");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"3249");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 25:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Industria y tecnologia de los alimentos 3");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"3225");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 26:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Historia, legislacion y etica profesional");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"3263");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 27:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Practica preprofesional en bromatologia");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"3242");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 28:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Equipos e instalaciones 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"3264");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 29:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Calidad");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"3266");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 30:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Conservacion y empaque");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"3232");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 31:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Instrumentacion y automatizacion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"3230");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 32:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Industria y tecnologia de los alimentos 4");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"3231");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 33:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Economia y gestion empresaria");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"3267");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 34:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Formulacion de proyectos industriales");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"3268");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 35:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Integracion de la industria alimentaria");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"3269");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 36:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Industria alimentaria y medioambiente");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"3270");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 37:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Industria y tecnologia de los alimentos 5");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"3236");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 38:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Educacion y fiscalizacion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"3271");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 39:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Trabajo final");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"3255");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        }
                    }
                    (U->dep[i].contarcarreras)++;
                    break;
                case 4:
                    strcpy(U->dep[i].car[j].nombre_carrera,"Licenciatura en Turismo");
                    strcpy(U->dep[i].car[j].titulo,"Esta carrera te capacita para organizar, gestionar, ejecutar y supervisar actividades en el ambito turistico");
                    for(k=0;k<materias;k=k+1){
                        switch(k)
                        {
                        case 0:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Introduccion al turismo");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"01");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 1:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Introduccion a la geografia");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"02");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 2:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Estado, derecho y legislacion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"03");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 3:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Principios de la economia");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"04");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 4:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Organizacion y gestion de la empresa turistica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"05");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 5:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Introduccion a la matematica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"06");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 6:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Espacios turisticos de Africa, Asia y Oceania");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"07");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 7:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Procesos historicos mundiales");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"08");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 8:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Servicios turisticos 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"09");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 9:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Espacios turisticos de Europa");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"10");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 10:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Metodologia de la investigacion social");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"11");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 11:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Historia latinoamericana y argentina");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"12");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 12:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Organizacion y gestion hotelera");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"13");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 13:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Servicios turisticos 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"14");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 14:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Espacios turisticos de America");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"15");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 15:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Marketing");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"16");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 16:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Indicadores turisticos");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"17");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 17:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Historia del turismo");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"18");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 18:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller de investigacion turistica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"19");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 19:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Espacios turisticos de Argentina");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"20");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 20:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Analisis economico y financiero de la actividad turistica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"21");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 21:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Etica profesional y responsabilidad social");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"22");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 22:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller de formulacion y evaluacion de proyectos");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"23");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 23:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Patrimonio historico-cultural argentino");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"24");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 24:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Marco normativo de la actividad turistica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"25");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 25:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Practica preprofesional");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"26");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 26:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Politica turistica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"27");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 27:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Procesos geopoliticos de integracion del turismo");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"28");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 28:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Diseño de productos turisticos");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"29");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 29:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Comportamiento organizacional y recursos humanos");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"30");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 30:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Turismo social y derecho al turismo");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"31");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 31:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Emprendedorismo");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"32");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 32:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Planeamiento del desarrollo turistico");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"33");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 33:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Cooperacion internacional");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"34");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 34:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller de trabajo final integrador");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"35");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 35:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Planeamiento y gestion del destino turistico");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"36");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 36:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Gobernabilidad del turismo");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"38");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 37:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Practica preprofesional orientada al ambito publico");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"40");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        }
                    }
                    (U->dep[i].contarcarreras)++;
                    break;
                case 5: // Carrera en la posicion 0, carrera en la posicion 1....
                    strcpy(U->dep[i].car[j].nombre_carrera,"Licenciatura en Sistemas");
                    strcpy(U->dep[i].car[j].titulo,"Esta carrera te capacita para adaptarte al cambio permanente tan caracteristico de los sistemas informaticos");
                    for(k=0;k<materias;k=k+1){
                        switch(k)
                        {
                        case 0:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Programacion de computadoras");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"8600");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 1:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Organizacion de computadoras");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"8601");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 2:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Arquitectura de computadoras");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"8602");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 3:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Matematica 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"8603");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 4:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Matematica 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"8604");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 5:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Expresion de problemas y algoritmos");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"8605");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 6:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Introduccion al pensamiento cientifico");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"8606");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 7:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Ingenieria en software 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"8607");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 8:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Introduccion a bases de datos");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"8608");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 9:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Algoritmos y estructuras de datos");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"8609");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 10:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Orientacion a objetos 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"8610");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 11:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Seminario de lenguajes");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"8611");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 12:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Introduccion a los sistemas operativos");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"8612");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 13:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Matematica 3");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"8613");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 14:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Probabilidad y estadistica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"8614");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 15:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Programacion concurrente");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"8615");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 16:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Ingenieria en software 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"8616");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 17:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Orientacion a objetos 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"8617");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 18:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Sistemas y organizaciones");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"8618");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 19:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Bases de datos 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"8619");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 20:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Proyecto de software");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"8620");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 21:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Conceptos y paradigmas de lenguajes de programacion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"8621");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 22:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Redes y comunicaciones");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"8622");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 23:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Ingenieria en software 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"8623");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 24:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Bases de datos 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"8624");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 25:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Fundamentos de teoria de la computacion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"8625");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 26:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Sistemas operativos");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"8626");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 27:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Desarrollo de software en sistemas distribuidos");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"8627");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 28:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Matematica discreta");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"8628");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 29:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Optativa area arquitectura, sistemas operativos y redes");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"8629");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 30:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Optativa area algoritmos y lenguajes");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"8630");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 31:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Politica y gestion tecnologicas");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"8631");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 32:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Aspectos legales y profesionales de la informatica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"8632");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 33:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Nuevos escenarios");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"8633");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 34:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Optativa area ingenieria de software y bases de datos");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"8634");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 35:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Seminario de trabajo final");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"8635");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        }
                    }
                    (U->dep[i].contarcarreras)++;
                    break;
                case 6:
                    strcpy(U->dep[i].car[j].nombre_carrera,"Licenciatura en Tecnologias Ferroviarias");
                    strcpy(U->dep[i].car[j].titulo,"Esta carrera te provee saberes cientificos y tecnologicos para abordar problematicas en el transporte ferroviario e intervenir con el objetivo de mejorar la calidad de los servicios");
                    for(k=0;k<materias;k=k+1){
                        switch(k)
                        {
                        case 0:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Matematica 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"5372");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 1:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Representecion grafica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"5332");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 2:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Historia del ferrocarril");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"5348");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 3:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Aspectos tecnicos y socioeconomicos del ferrocarril");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"5373");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 4:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Matematica 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"5310");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 5:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Fisica 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"5309");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 6:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Introduccion a la quimica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"5302");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 7:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"El transporte ferroviario");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"5380");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 8:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Tecnologia ferroviaria 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"5342");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 9:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Matematica 3");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"5321");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 10:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Fisica 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"5332");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 11:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Tecnologias de la informacion y de las comunicaciones");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"5378");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 12:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Nuevos escenarios");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"5389");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 13:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Tecnologia ferroviaria 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"5306");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 14:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Seguridad laboral y ambiental");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"5311");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 15:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Legislacion ferroviaria");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"5341");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 16:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Mecanica y tecnologia de los materiales");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"5301");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 17:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Electronica y electromecanica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"5353");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 18:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Tecnologia ferroviaria 3");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"5337");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 19:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Termodinamica y maquinas termicas");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"5381");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 20:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Instalaciones electricas y electromecanicas");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"5375");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 21:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Tecnologia ferroviaria 4");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"5399");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 22:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Tecnologia ferroviaria 5");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"5330");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 23:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Metodologia de la investigacion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"5352");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 24:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Mecanica de los fluidos");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"5339");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 25:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Tecnologia ferroviaria 6");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"5347");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 26:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Gestion de calidad, ensayos y mediciones");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"5327");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        }
                    }
                    (U->dep[i].contarcarreras)++;
                    break;
                case 7:
                    strcpy(U->dep[i].car[j].nombre_carrera,"Ciclo de licenciatura Planificacion Logistica");
                    strcpy(U->dep[i].car[j].titulo,"Esta carrera de provee de conocimientos estrategicos para participar en el proceso de planeamiento, operativo y control de sistemas economicos, juridicos, socioculturales y tecnologicos y prevencion de accidentes y enfermedades del trabajo");
                    for(k=0;k<materias;k=k+1){
                        switch(k)
                        {
                        case 0:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Matematica 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"01");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 1:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Fundamentos de economia");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"02");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 2:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Logistica 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"03");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 3:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Transporte 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"04");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 4:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Regimen juridico 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"05");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 5:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Geografia economica argentina y regional");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"06");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 6:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Matematica 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"07");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 7:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Matematica aplicada a la logistica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"10");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 8:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Almacenamiento 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"11");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 9:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Seguridad e higiene");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"12");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 10:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Logistica 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"13");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 11:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Transporte 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"14");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 12:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Estadistica aplicada a la logistica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"15");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 13:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Distribucion 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"16");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 14:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Legislacion y practica aduanera 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"17");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 15:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Modulo de informatica 4");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"18");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 16:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Regimen juridico 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"19");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 17:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Costos y evaluacion de proyectos");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"20");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 18:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Tecnologias aplicadas a la logistica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"21");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 19:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Metodologia de la investigacion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"22");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 20:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Relaciones laborales");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"23");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 21:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Logistica 3");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"24");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 22:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Transporte 3");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"25");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 23:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Negociacion y toma de decisiones");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"26");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 24:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Problemas economicos y politicos del siglo XXI");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"29");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 25:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Logistica de la seguridad");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"30");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 26:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Infraestructura y servicios");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"31");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 27:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Planeamiento estrategico 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"32");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 28:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Logistica inversa");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"33");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 29:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Comercio exterior");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"34");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 30:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Logistica y articulacion territorial");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"35");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 31:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller de practica preprofesional");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"40");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 32:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Distribucion 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"41a");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 33:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Almacenamiento 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"42a");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 34:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Legislacion y practica aduanera");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"43a");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 35:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Planeamiento estrategico 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"41b");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 36:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Compras y contrataciones en el sector publico");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"42b");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 37:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Logistica de la defensa");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"43b");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 38:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller de trabajo final integrador");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"44");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        } // Cierro switch k
                    } // Cierro for k
                    (U->dep[i].contarcarreras)++;
                    break;
                } // Cierro switch carreras
            } // Cierro for carreras
            break; // Termina el case del departamento de desarrollo productivo y tecnologico
        case 1: // Departamento en la posición 1 (Departamento de salud comunitaria).
            strcpy(U->dep[i].nombre,"Departamento de Salud Comunitaria");
            strcpy(U->dep[i].descripcion,"Director: Lic. Ramon Alvarez");
            for(j=0;j<carreras;j=j+1){
                (U->dep[i].car[j].contarmaterias)=0;
                switch(j)
                {
                case 0: // Carrera en la posicion 0, carrera en la posicion 1....
                    strcpy(U->dep[i].car[j].nombre_carrera,"Licenciatura en Enfermeria");
                    strcpy(U->dep[i].car[j].titulo,"Esta carrera te ofrece conocimientos que te permitiran dar respuesta a las problematicas sociosanitarias dentro del campo de la Salud Colectiva");
                    for(k=0;k<materias;k=k+1){
                        switch(k)
                        {
                        case 0:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Cultura y salud");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"01");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 1:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Quimica y fisica biologica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"02");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 2:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Anatomo-fisiologia");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"03");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 3:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Fundamentos de enfermeria");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"04");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 4:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Salud mental");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"06");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 5:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Salud colectiva");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"07");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 6:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Microbiologia y parasitologia");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"08");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 7:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Nutricion y dietoterapia");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"09");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 8:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Enfermeria materno-infantil 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"10");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 9:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Farmacologia y toxicologia");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"12");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 10:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Epidemiologia");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"13");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 11:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Enfermeria del adulto y del anciano 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"14");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 12:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Enfermeria en salud mental");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"15");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 13:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Educacion y salud");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"17");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 14:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Enfermeria en salud comunitaria");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"18");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 15:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Enfermeria del adulto y del anciano 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"19");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 16:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Enfermeria materno-infantil 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"20");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 17:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Etica y problemas legales de la practica profesional");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"22");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 18:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Filosofia del cuidado");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"23");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 19:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Psicologia social e institucional");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"24");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 20:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Gestion de las organizaciones de salud");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"25");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 21:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Enfermeria del niño y del adolescente");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"26");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 22:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Investigacion en enfermeria");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"28");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 23:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Practicas integradas de enfermeria");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"29");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 24:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Epistemologia del cuidado de enfermeria");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"33");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 25:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Educacion en enfermeria");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"34");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 26:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Metodologia de la investigacion aplicada a la enfermeria");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"35");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 27:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Enfermeria en el cuidado critico");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"36");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 28:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Gestion y organizacion de los servicios de enfermeria");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"37");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 29:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Etica y deontologia profesional");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"39");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 30:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Enfermeria en salud colectiva");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"40");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 31:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller integrador de practicas e investigacion en enfermeria colectiva");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"42");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 32:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Practicas pre-profesionales");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"45");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        } // Cierro switch materias Enfermeria
                    } // Cierro for vector de estructura de materias de Licenciatura en enfermeria
                    (U->dep[i].contarcarreras)++;
                    break;
                case 1: // Paso a la siguiente carrera dentro del departamento de salud colectiva
                    strcpy(U->dep[i].car[j].nombre_carrera,"Licenciatura en Trabajo Social");
                    strcpy(U->dep[i].car[j].titulo,"Esta carrera te brinda una formacion en sociologia, antropologia y psicologia en la problematica social argentina y latinoamericana; en metodologia de la investigacion; en concepciones y modelos de desarrollo social");
                    for(k=0;k<materias;k=k+1){
                        switch(k)
                        {
                        case 0:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Historia del trabajo social");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"02");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 1:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Introduccion a las ciencias sociales");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"03");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 2:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Trabajo social 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"04");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 3:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Historia social latinoamericana");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"05");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 4:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Estado y politicas publicas");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"06");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 5:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Analisis de la realidad argentina");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"08");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 6:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Introduccion a la psicologia y salud mental comunitaria");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"09");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 7:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Politicas sociales");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"10");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 8:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Trabajo social 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"11");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 9:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Metodologia de la investigacion 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"12");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 10:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Antropologia");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"13");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 11:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Teoria de los grupos y dinamicas grupales");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"15");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 12:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Metodologia de la investigacion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"16");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 13:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Teoria de las organizaciones y analisis institucional");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"17");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 14:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Promocion comunitaria");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"18");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 15:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Estadistica y demografia");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"19");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 16:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Teoria social 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"20");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 17:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Planificacion social");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"27");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 18:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Teoria social 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"28");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 19:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Legislacion y trabajo social 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"29");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 20:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Abordajes socio-familiares");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"30");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 21:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Evaluacion de programa y proyectos sociales");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"31");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 22:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Sistematizacion de la practica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"32");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 23:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Comunicacion social");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"33");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 24:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Legislacion y trabajo social 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"34");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 25:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Gestion social y gobierno");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"35");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 26:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Teoria economica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"37");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 27:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Salud y ciclos vitales");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"38");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 28:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Epidemiologia");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"42");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        } // Cierro switch para cargar c/u de las materias de trabajo social
                    } // Cierro for materias trabajo social
                    (U->dep[i].contarcarreras)++;
                    break;
                case 2:
                    strcpy(U->dep[i].car[j].nombre_carrera,"Licenciatura en Nutricion");
                    strcpy(U->dep[i].car[j].titulo,"Esta carrera te ofrece conocimientos sobre practicas alimentarias propias de diferentes grupos sociales y culturales, sobre la seguridad alimentaria, de trabajo orientado a la promocion de la salud");
                    for(k=0;k<materias;k=k+1){
                        switch(k)
                        {
                        case 0:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Salud colectiva");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"01");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 1:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Anatomia y fisiologia");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"02");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 2:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Seminario de situaciones problematicas y territorio");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"03");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 3:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Seminario de introduccion a las problematicas alimentarias");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"04");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 4:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Nutricion 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"05");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 5:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Biofisica y bioquimica 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"06");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 6:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Salud mental");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"07");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 7:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Nutricion 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"08");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 8:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Fisica y quimica culinaria");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"09");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 9:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Antropologia");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"10");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 10:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Evaluacion nutricional");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"12");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 11:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Biofisica y bioquimica 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"13");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 12:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Nutricion 3");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"14");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 13:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Educacion alimentaria nutricional");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"15");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 14:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Bromatologia y tecnologia de los alimentos 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"16");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 15:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Microbiologia y parasitologia");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"17");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 16:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Etica profesional");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"18");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 17:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Nutricion 4");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"19");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 18:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Promocion comunitaria");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"20");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 19:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Economia regional y alimentaria");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"21");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 20:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Bromatologia y tecnologia de los alimentos 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"22");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 21:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Nutricion comunitaria");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"23");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 22:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Desarrollo comunitario y organizacion social");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"24");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 23:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Epidemologia 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"26");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 24:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Practicas de nutricion comunitaria");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"27");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 25:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Fisiopatologia, dietoterapia del adulto y tecnica dietoterapica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"28");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 26:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Metodologia de la investigacion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"29");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 27:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Epidemiologia 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"30");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 28:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Gestion y administracion de servicios de alimentacion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"31");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 29:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Gestion de las organizaciones de salud");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"32");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 30:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Fisiopatologia y dietoterapia del ninio");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"33");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 31:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Practicas en salud colectiva");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"34");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 32:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller de trabajo final integrador");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"35");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 33:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Practicas en dietoterapia y gestion y administracion de servicios de alimentacion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"36");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        } // Cierro switch k
                    } // Cierro for materias
                    (U->dep[i].contarcarreras)++;
                    break;
                } // Cierro switch departamento
            } // Cierro For departamentos...
            break;
        case 2: // Departamento en la posición 2 (Departamento de planificacion y politicas publicas).
            strcpy(U->dep[i].nombre,"Departamento de Planificacion y Politicas Publicas");
            strcpy(U->dep[i].descripcion,"Director: Dr. Francisco Pestanha");
            for(j=0;j<carreras;j=j+1){
            (U->dep[i].car[j].contarmaterias)=0;
                switch(j)
                {
                case 0: // Carrera en la posicion 0, carrera en la posicion 1....
                    strcpy(U->dep[i].car[j].nombre_carrera,"Licenciatura en Seguridad Ciudadana");
                    strcpy(U->dep[i].car[j].titulo,"Esta carrera te provee de conocimientos en ciencias juridicas, sociales y humanas, orientados a la investigacion y cooperacion de temas que vinculan violencia, seguridad y ciudadania");
                    for(k=0;k<materias;k=k+1){
                        switch(k)
                        {
                        case 0:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Aspectos constitucionales de la seguridad ciudadana");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"01");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 1:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Estado, gobierno y sociedad");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"02");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 2:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Seguridad y comunicacion social");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"04");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 3:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Metodologia de analisis mediatico");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"05");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 4:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Antropologia social y juridica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"07");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 5:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Paradigmas y sistemas de seguridad");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"08");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 6:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Metodologia de analisis de las instituciones y las organizaciones");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"10");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 7:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Historia moderna y contemporanea");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"11");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 8:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Perspectivas sociologicas de fundamento de la seguridad");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"12");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 9:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Politicas publicas y planificacion en seguridad");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"13");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 10:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Tecnologias y seguridad");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"14");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 11:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller de derechos humanos y seguridad ciudadana");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"15");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 12:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Analisis socioeconomico de la sociedad argentina");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"16");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 13:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Criminologia");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"17");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 14:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Problemas sociales urbanos y gestion de los territorios");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"18");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 15:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Metodos y tecnicas de trabajo con grupos e instituciones");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"19");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 16:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Participacion comunitaria y seguridad ciudadana");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"21");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 17:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Diseño, gestion y evaluacion de proyectos locales en seguridad ciudadana");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"23");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 18:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller de intervencion de operadores locales en prevencion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"24");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 19:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Legislacion y normatividad en seguridad ciudadana");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"27");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 20:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Invstigacion del delito y gestion de informacion criminal");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"28");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 21:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Ciudadania, inseguridad y miedo al delito");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"29");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 22:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Elementos de estadistica aplicada y demografia");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"30");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 23:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Metodologia de la investigacion social aplicada a la seguridad");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"31");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 24:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Geopolitica, globalizacion y seguridad");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"32");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 25:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Sociologia de las violencias");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"33");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 26:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Politicas comparadas en seguridad");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"34");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 27:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Politicas multiagenciales de prevencion de la violencia y el delito");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"35");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 28:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller de elaboracion de trabajo final integrador");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"36");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 29:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Seguridad, imaginario colectivo y subjetividad social");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"37");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 30:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Politicas de formacion, capacitacion y promocion de la seguridad ciudadana");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"39");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 31:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Metodos de gestion de la conflictividad");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"40");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 32:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Practica pre-profesional integrada");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"41");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 33:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller de trabajo final integrador");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"42");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        }
                    }
                    (U->dep[i].contarcarreras)++;
                    break;
                case 1:
                    strcpy(U->dep[i].car[j].nombre_carrera,"Licenciatura en Ciencia Politica y Gobierno");
                    strcpy(U->dep[i].car[j].titulo,"Esta carrera te brinda conocimientos utiles para comprender la actividad de gobierno y para gestionar asuntos publicos");
                    for(k=0;k<materias;k=k+1){
                        switch(k)
                        {
                        case 0:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Sociologia politica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"01");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 1:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Fundamentos de ciencia politica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"02");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 2:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Economia politica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"03");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 3:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Historia moderna y contemporanea");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"04");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 4:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Instituciones del derecho");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"05");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 5:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Estadistica social");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"07");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 6:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Teoria politica 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"08");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 7:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Metodologia de la investigacion social 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"09");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 8:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Teoria politica 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"10");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 9:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Derecho constitucional");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"11");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 10:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Fundamentos de macroeconomia");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"12");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 11:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Historia politica y social latinoamericana");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"13");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 12:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Metodologia de la investigacion social 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"14");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 13:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Teoria del estado");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"15");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 14:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Economia internacional");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"16");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 15:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Historia politica y social argentina");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"17");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 16:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Politica internacional");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"19");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 17:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Analisis de la sociedad argentina");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"20");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 18:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Derecho administrativo");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"21");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 19:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Teoria politica contemporanea");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"22");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 20:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Administracion publica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"23");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 21:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Economia de gobierno y finanzas publicas");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"24");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 22:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Gobierno local");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"25");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 23:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Politicas publicas");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"26");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 24:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Analisis politico y opinion publica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"27");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 25:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Planificacion estrategica y analisis de politicas publicas");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"29");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 26:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Formulacion y evaluacion de proyectos");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"30");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 27:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Ideas politicas en america latina");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"31");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 28:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Politica comparada");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"32");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 29:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Politica latinoamericana");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"33");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 30:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Comunicacion politica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"34");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        }
                    }
                    (U->dep[i].contarcarreras)++;
                    break;
                case 2:
                    strcpy(U->dep[i].car[j].nombre_carrera,"Licenciatura en Educacion");
                    strcpy(U->dep[i].car[j].titulo,"Esta carrera te forma en el diseño de modelos y estrategias de intervencion en diferentes situaciones educativas, como en los problemas, y en la busqueda de explicaciones y soluciones");
                    for(k=0;k<materias;k=k+1){
                        switch(k)
                        {
                        case 0:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Psicologia de la educacion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"01");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 1:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller 'Las instituciones educativas'");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"02");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 2:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Filosofia de la educacion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"03");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 3:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Politica, estado y educacion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"04");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 4:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Teorias del aprendizaje");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"05");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 5:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Historia de la educacion argentina y latinoamericana");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"06");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 6:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Economia de la educacion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"07");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 7:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Sociologia de la educacion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"08");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 8:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Administracion y gestion 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"09");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 9:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Teoria curricular");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"10");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 10:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Teorias pedagogicas");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"11");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 11:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Infancia y juventud");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"12");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 12:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Administracion y gestion 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"13");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 13:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Didactica 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"14");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 14:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Talleres 'Las TIC en educacion'");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"15");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 15:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Adultos mayores");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"16");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 16:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Niveles y modalidades del sistema educativo argentino");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"17");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 17:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Investigacion educativa 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"18");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 18:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Didactica 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"19");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 19:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Nuevos modelos universitarios");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"21");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 20:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Investigacion educativa 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"23");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 21:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Sistemas educativos comparados");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"24");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 22:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Politicas publicas en educacion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"25");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 23:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Formulacion de proyectos de formacion profesional y capacitacion laboral");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"26");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 24:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Ateneo 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"27");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 25:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Practicas profesionales");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"28");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 26:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Ateneo 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"29");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        }
                    }
                    (U->dep[i].contarcarreras)++;
                    break;
                case 3:
                    strcpy(U->dep[i].car[j].nombre_carrera,"Licenciatura en Justicia y Derechos Humanos");
                    strcpy(U->dep[i].car[j].titulo,"Esta carrera te brinda conocimientos para entender y explicar la relacion entre justicia, democracia y derechos humanos, sistemas de organizacion social, practicas politico-institucionales, fundamentos juridicos y principios eticos");
                    for(k=0;k<materias;k=k+1){
                        switch(k)
                        {
                        case 0:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Introduccion a la teoria del estado");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"01");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 1:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Instituciones del derecho");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"02");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 2:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Historia argentina y derechos humanos");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"03");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 3:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Derecho constitucional y constitucionalismo social");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"04");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 4:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Configuracion historica de los derechos humanos en America Latina 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"05");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 5:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Derechos humanos y comunicacion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"06");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 6:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Educacion y TIC en derechos humanos");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"07");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 7:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Derechos humanos y soberania");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"08");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 8:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Metodologia de la investigacion social 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"09");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 9:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Teoria politica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"10");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 10:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Configuracion historica de los derechos humanos en America Latina 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"11");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 11:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Derecho penal");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"12");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 12:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Historia politica, social y cultural latinoamericana");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"13");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 13:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Problemas actuales de acceso a la justicia");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"14");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 14:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Derechos sociales, economicos y culturales");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"15");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 15:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Politicas publicas y politicas en organizaciones sociales");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"16");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 16:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Psicologia social");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"17");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 17:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Estrategias de formacion, capacitacion y promocion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"18");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 18:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Practica pre-profesional");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"27");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 19:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller de integracion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"28");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 20:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Sociologia del derecho");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"29");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 21:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Los derechos sociales en las politicas publicas");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"30");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 22:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Analisis de las politicas publicas");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"31");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 23:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Derechos humanos y derechos sociales en Latinoamerica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"32");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 24:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Proteccion internacional de derechos humanos");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"33");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 25:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Politica contemporanea Latinoamericana");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"34");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 26:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Metodologia de la investigacion social 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"35");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 27:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Elementos basicos de los procesos judiciales");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"36");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 28:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Introduccion al sistema judicial argentino");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"37");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 29:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Formulacion y evaluacion de proyectos");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"38");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 30:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Filosofia del derecho y teoria de la justicia");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"39");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 31:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Democracia y derechos humanos");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"40");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 32:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller de trabajo final integrador");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"46");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        }
                    }
                    (U->dep[i].contarcarreras)++;
                    break;
                case 4:
                    strcpy(U->dep[i].car[j].nombre_carrera,"Licenciatura en Relaciones Internacionales");
                    strcpy(U->dep[i].car[j].titulo,"Esta carrera te permite reconocer la cantidad de fenomenos globales que nos atraviesan, abordando temas como la autodeterminacion y soberania de la politica economica exterior");
                    for(k=0;k<materias;k=k+1){
                        switch(k)
                        {
                        case 0:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Historia moderna y contemporanea 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"01");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 1:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Historia argentina 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"02");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 2:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Logica y epistemologia de las ciencias sociales");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"03");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 3:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Introduccion a las relaciones internacionales");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"04");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 4:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Pensamiento filosofico");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"05");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 5:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Historia moderna y contemporanea 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"07");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 6:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Historia argentina 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"08");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 7:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Metodologia de la investigacion en ciencias sociales");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"09");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 8:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Filosofia moderna y contemporanea");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"10");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 9:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Economia politica 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"11");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 10:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Historia de las relaciones internacionales");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"13");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 11:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Economia politica 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"14");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 12:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Sistematica de la ciencia politica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"15");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 13:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Metodos y tecnicas de investigacion aplicados");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"16");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 14:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Pensamientos clasicos de las relaciones internacionales");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"17");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 15:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Teoria de las relaciones internacionales 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"19");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 16:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Teoria politica 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"20");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 17:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Economia politica internacional 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"21");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 18:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Politica internacional contemporanea");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"22");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 19:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Disenio y formulacion de modelos prospectivos y de investigacion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"23");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 20:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Portugues 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"24");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 21:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Economia politica internacional 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"25");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 22:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Teoria de las relaciones internacionales 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"26");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 23:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Sistemas politicos comparados");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"27");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 24:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Politica exterior argentina 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"28");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 25:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Historia de las relaciones internacionales latinoamericanas");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"29");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 26:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Portugues 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"30");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 27:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Derecho e instituciones internacionales");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"31");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 28:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Agenda internacional");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"32");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 29:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Teoria politica 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"33");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 30:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Politica exterior argentina 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"35");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 31:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Procesos de integracion americanos");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"39");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 32:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Sistemas politicos latinoamericanos comparados");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"41");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 33:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Prospectiva estrategica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"42");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 34:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Politica domestica y externa brasilera");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"43");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 35:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Politicas exteriores latinoamericanas comparadas");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"45");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 36:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Procesos de integracion americanos");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"46");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 37:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Teoria de la integracion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"47");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 38:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Prospectiva estrategica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"48");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 39:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Derecho a la integracion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"49");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        } // Cierro switch cargar materias 1 por 1
                    } // Cierro for recorrer materias de Lic. en comercio exterior..
                    (U->dep[i].contarcarreras)++; // Se cargo la carrera, hay una carrera mas en el departamento
                    break; // Cierro el case de la carrera x del departamento de planificacion y politicas publicas
                } // Cierro switch carreras de departamento de planificacion y politicas publicas
            } // Cierro for numero de carreras
            break;
        case 3: // Departamento en la posición 3 (Humanidades).
            strcpy(U->dep[i].nombre,"Departamento de Humanidades y Artes");
            strcpy(U->dep[i].descripcion,"Director: Mtro. Daniel Bozzani");
            for(j=0;j<carreras;j=j+1){
            (U->dep[i].car[j].contarmaterias)=0;
                switch(j)
                {
                case 0: // Carrera en la posicion 0, carrera en la posicion 1....
                    strcpy(U->dep[i].car[j].nombre_carrera,"Licenciatura en Audiovision");
                    strcpy(U->dep[i].car[j].titulo,"Esta carrera te prepara para manipular la tecnologia actual concebida para el registro, la realizacion y la edicion de imagenes y sonidos");
                    for(k=0;k<materias;k=k+1){
                        switch(k)
                        {
                        case 0:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Tecnologia de la imagen");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"01");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 1:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Elementos de audio");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"02");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 2:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller de lectura y escritura profesional");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"03");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 3:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Educacion auditiva");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"04");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 4:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Electronica de las comunicaciones");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"05");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 5:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Lenguaje audiovisual 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"06");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 6:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Registro de sonido en audiovisuales");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"07");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 7:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Montaje 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"08");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 8:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Fotografia e iluminacion en audiovisuales");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"09");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 9:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Lenguaje audiovisual 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"11");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 10:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Audicion y analisis musical");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"12");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 11:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller de edicion de sonido");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"13");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 12:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller de montaje");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"15");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 13:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Realizacion integral audiovisual 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"16");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 14:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Arte y sociedad");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"17");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 15:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Guion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"18");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 16:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller de composicion sonora");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"19");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 17:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Banda sonora");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"21");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 18:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Generos estilos audiovisuales");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"22");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 19:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller de experimentacion audiovisual");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"23");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 20:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Realizacion integral audiovisual 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"24");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 21:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Etica profesional");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"25");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 22:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Gestion de proyectos audiovisuales");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"26");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 23:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Estetica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"27");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 24:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Comunicacion audiovisual");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"30");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 25:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Tecnologia de postproduccion 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"28");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 26:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Imagen, tipografia e identidad cultural");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"29");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 27:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Acustica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"47");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 28:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Organologia");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"48");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 29:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Semiotica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"49");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 30:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Metodologia de investigacion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"50");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 31:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Edicion y correccion digital de imagen");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"51");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 32:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Tecnologia de postproduccion 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"52");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 33:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Montaje 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"53");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 34:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Animacion 3D 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"54");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 35:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Composicion digital");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"55");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 36:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Tecnologia de postproduccion 3");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"56");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 37:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Masterizacion y postproduccion 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"57");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 38:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Sistemas de electroacustica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"58");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 39:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Masterizacion y postproduccion 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"59");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        }
                    }
                    (U->dep[i].contarcarreras)++;
                    break;
                case 1:
                    strcpy(U->dep[i].car[j].nombre_carrera,"Licenciatura en Disenio Industrial");
                    strcpy(U->dep[i].car[j].titulo,"Esta carrera te permite acceder a conocimientos que te permitiran contribuir al trabajo y a la economia nacional, con una impronta cultural local y la incorporacion de valores propios de nuestra identidad");
                    for(k=0;k<materias;k=k+1){
                        switch(k)
                        {
                        case 0:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller de disenio industrial 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"01");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 1:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Tecnologia, materiales y procesos 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"02");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 2:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Desarrollos visuales");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"03");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 3:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Dibujo tecnico");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"04");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 4:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller de disenio industrial 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"05");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 5:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Tecnologia, materiales y procesos 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"06");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 6:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Morfologia");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"07");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 7:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Representacion digital");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"08");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 8:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller de lectura y escritura profesional");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"09");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 9:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Metodos del diseño");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"10");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 10:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller de disenio industrial 3");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"11");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 11:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Tecnologia, materiales y procesos 3");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"12");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 12:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Modelado digital");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"13");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 13:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Ciencia aplicada al disenio industrial");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"14");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 14:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Historia social del disenio 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"15");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 15:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller de practica pre-profesional");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"16");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 16:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller de disenio industrial 4");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"20");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 17:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Tecnologia, materiales y procesos 4");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"21");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 18:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Semiotica aplicada al disenio industrial");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"22");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 19:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Manufactura digital");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"23");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 20:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Historia social del disenio");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"24");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 21:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller de disenio industrial 5");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"25");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 22:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Desarrollos cientifico, tecnologico e innovacion productiva");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"26");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 23:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Metodologia de la investigacion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"27");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 24:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Disenio sustentable");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"28");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 25:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Etica y legislacion profesional");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"29");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 26:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller de trabajo integrador final");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"30");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        }
                    }
                    (U->dep[i].contarcarreras)++;
                    break;
                case 2:
                    strcpy(U->dep[i].car[j].nombre_carrera,"Licenciatura en Disenio y Comunicacion Visual");
                    strcpy(U->dep[i].car[j].titulo,"Esta carrera te capacita para elaborar un producto que sera reproducido por medios industriales, cuyo caudal comunicativo esta dirigido a un sector determinado de la comunidad");
                    for(k=0;k<materias;k=k+1){
                        switch(k)
                        {
                        case 0:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller de disenio 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"01");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 1:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Geometria descriptiva aplicada");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"02");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 2:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Medios expresivos 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"03");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 3:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Espacio tipografico 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"04");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 4:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Teoria del disenio 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"05");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 5:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Lectura y escritura profesional");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"06");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 6:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Tecnologia 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"07");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 7:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Computacion 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"08");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 8:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Medios expresivos 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"09");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 9:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller de disenio 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"10");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 10:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Espacio tipografico 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"11");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 11:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Historia de la comunicacion visual");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"12");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 12:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Metodologia de la investigacion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"13");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 13:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller de disenio 3");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"14");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 14:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Tecnologia 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"15");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 15:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Computacion 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"16");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 16:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Fotografia");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"17");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 17:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Medios expresivos 3");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"18");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 18:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Espacio tipografico 3");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"19");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 19:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Historia social del disenio");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"20");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 20:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller de disenio 4");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"21");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 21:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Computacion 3");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"22");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 22:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Comunicacion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"24");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 23:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Teoria del disenio 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"25");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 24:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Semiotica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"26");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 25:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Video");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"27");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 26:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller de trabajo final integrador");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"28");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 27:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Practica pre-profesional");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"29");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 28:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Estetica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"30");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 29:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Etica profesional");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"31");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 30:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller de trabajo final integrador");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"32");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        }
                    }
                    (U->dep[i].contarcarreras)++;
                    break;
                case 3:
                    strcpy(U->dep[i].car[j].nombre_carrera,"Traductorado Publico en idioma Ingles");
                    strcpy(U->dep[i].car[j].titulo,"En esta carrera aprenderas sobre como debes proceder a la hora de traducir escritos y documentos tecnicos y/o publicos, en pos de satisfacer necesidades sociales actuales y del contexto");
                    for(k=0;k<materias;k=k+1){
                        switch(k)
                        {
                        case 0:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Lengua inglesa 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"01");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 1:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Gramatica inglesa 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"02");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 2:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Lengua espaniola 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"03");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 3:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Principios basicos de la traduccion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"04");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 4:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Semiotica");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"05");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 5:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Traduccion tecnica 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"06");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 6:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Introduccion al derecho y constitucionalismo");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"07");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 7:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Lengua inglesa 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"08");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 8:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Traduccion tecnica 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"09");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 9:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Lengua espaniola 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"10");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 10:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Fonetica inglesa");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"11");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 11:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Gramatica inglesa 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"12");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 12:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Traduccion tecnica 3");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"13");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 13:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Historia social general contemporanea");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"14");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 14:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Tecnologia aplicada a la traduccion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"15");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 15:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Elementos de derecho civil y comercial");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"16");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 16:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Lengua especializada 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"17");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 17:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Traduccion legal 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"18");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 18:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Contratos civiles y comerciales");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"19");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 19:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Estructuras comparadas");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"20");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 20:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Etica profesional");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"21");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 21:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Traduccion legal 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"24");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 22:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Elementos del derecho procesal");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"25");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 23:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Historia y cultura inglesa");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"26");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 24:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Principios generales de economia y finanzas");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"27");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 25:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Metodologia de la investigacion");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"28");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 26:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Practicas pre-profesionales 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"29");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 27:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Lengua especializada 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"32");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 28:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Traduccion legal 3");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"33");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 29:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Literatura de los paisas de habla inglesa 1");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"34");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 30:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Traduccion especializada");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"35");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 31:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Literatura de los paises de habla inglesa 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"36");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 32:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Traduccion legal 4");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"37");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 33:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Regimen legal de la traduccion y del traductor");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"38");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 34:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Derecho comparado");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"39");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 35:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Practicas pre-profesionales 2");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"40");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        case 36:
                            strcpy(U->dep[i].car[j].mat[k].nombre_materia,"Taller de trabajo final integrador");
                            strcpy(U->dep[i].car[j].mat[k].codigo,"41");
                            (U->dep[i].car[j].contarmaterias)++; // Se cargo la materia. en la carrera de sistemas ya hay una materia más
                            break;
                        }
                    }
                    (U->dep[i].contarcarreras)++;
                    break;
                } // Cierro switch carreras de departamento de Humanidades y Artes
            }
            break;
        } // Cierro switch para cargar los datos de cada departamento
    }
    (U->dep[0].contarcarreras)--; // Por error que no se pudo encontrar (En el DDPyT muestra 9 carreras cuando son 8)
    return U; // La función me devuelve un puntero a la estructura universidad...
}
void CargarMiembros(Universidad U, int NumDep, int NumCar, int NumMat){
    int i=0;
    int j=0;
    char auxnombre[40]=" ";
    char auxdnidoc[10]=" ";
    Miembros aux; // Auxiliar estructura miembros para hacer burbuja y que ya queden ordenados alfabéticamente
    printf("Ingrese los datos de los integrantes de %s.\n\n\n",U->dep[NumDep].car[NumCar].mat[NumMat].nombre_materia);
    for(i=0;i<(U->dep[NumDep].car[NumCar].mat[NumMat].contarintegrantes);i++){
        printf("Integrante %d:\n",(i+1));
        printf("Ingrese el nombre completo:\n");
        fflush(stdin);
        gets(auxnombre);
        strcpy(U->dep[NumDep].car[NumCar].mat[NumMat].mie[i].nombre_completo,auxnombre);
        printf("Ingrese su D.N.I:\n");
        fflush(stdin);
        gets(auxdnidoc);
        strcpy((U->dep[NumDep].car[NumCar].mat[NumMat].mie[i].dni),auxdnidoc);
        printf("Ingrese si es un docente o un alumno (POR ESCRITO):\n");
        fflush(stdin);
        gets(auxdnidoc);
        strcpy((U->dep[NumDep].car[NumCar].mat[NumMat].mie[i].doc_o_alum),auxdnidoc);
        printf("\n\n");
    }
    (U->dep[NumDep].car[NumCar].mat[NumMat].secargo)=1;
    printf("\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
    // Hago burbuja para que queden ordenados alfabeticamente...
    for(i=0;i<(U->dep[NumDep].car[NumCar].mat[NumMat].contarintegrantes);i=i+1){
        for(j=0;j<(U->dep[NumDep].car[NumCar].mat[NumMat].contarintegrantes);j=j+1){ // Recorro el vector de integrantes
            // la cantidad que se ingresó
            if(strcmp(U->dep[NumDep].car[NumCar].mat[NumMat].mie[j].nombre_completo,U->dep[NumDep].car[NumCar].mat[NumMat].mie[j+1].nombre_completo)==1){
                if((j+1)<(U->dep[NumDep].car[NumCar].mat[NumMat].contarintegrantes)){
                    aux=(U->dep[NumDep].car[NumCar].mat[NumMat].mie[j]);
                    (U->dep[NumDep].car[NumCar].mat[NumMat].mie[j])=(U->dep[NumDep].car[NumCar].mat[NumMat].mie[j+1]);
                    (U->dep[NumDep].car[NumCar].mat[NumMat].mie[j+1])=aux;
                }
            }
        }
    }
}
void MostrarUniversidad(Universidad U){
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                                                                                                                                                   |\n");
    printf("|                                                                   %s                                                                   |\n",U->nombre);
    printf("|                                                                                                                                                                   |\n");
    printf("|                                               %s                                                |\n",U->direccion);
    printf("|                                                                                                                                                                   |\n");
    printf("|                                                                      Telefono: %s                                                                      |\n",U->contacto);
    printf("|                                                                                                                                                                   |\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
}
void MostrarDepartamentos(Universidad U, int departamentos, int *PuntVec){
    int i=0;
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
    printf("La Universidad Nacional de Lanus cuenta con 4 departamentos:\n\n\n");
    for(i=0;i<departamentos;i=i+1){
        printf("%d) '%s': %s\n",PuntVec[i],U->dep[i].nombre,U->dep[i].descripcion); // Imprimo los 4 departamentos y su descripcion
        if(i==(departamentos-1)){
            printf("\n\n"); // Cuando termina de mostrar todo, dejo un renglon más para separar, antes de ir mostrando departamento por departamento
        }
    }
}
void MostrarCarreras(Universidad U, int numdepartamento, int *PuntVecNumCarrera){
    int i=0; // Variable para recorrer las carreras
    int carreras=U->dep[numdepartamento-1].contarcarreras; // Recorre la cantidad de carreras que hay en ese departamento
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
    printf("El '%s' contiene las siguientes %d carreras de grado:\n\n",U->dep[numdepartamento-1].nombre,U->dep[numdepartamento-1].contarcarreras);
    for(i=0;i<carreras;i=i+1){ // For para recorrer las carreras de dicho departamento
        printf("%d) %s\n%s\n",PuntVecNumCarrera[i],U->dep[numdepartamento-1].car[i].nombre_carrera,U->dep[numdepartamento-1].car[i].titulo);
    }
    printf("\n\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
}
void MostrarMaterias(Universidad U, int numdepartamento, int numcarrera){
    int i=0;
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
    printf("Plan de estudios - '%s':\n\n",U->dep[numdepartamento].car[numcarrera].nombre_carrera);
    for(i=0;i<(U->dep[numdepartamento].car[numcarrera].contarmaterias);i=i+1){
        printf("%d) %s - [%s]\n",(i+1),U->dep[numdepartamento].car[numcarrera].mat[i].nombre_materia,U->dep[numdepartamento].car[numcarrera].mat[i].codigo);
        // Muestro el numero de materia, el nombre, y su codigo.
    }
    printf("\n\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
}
void MostrarMiembros(Universidad U, int NumDep, int NumCar, int NumMat){
    int i=0;
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
    if((U->dep[NumDep].car[NumCar].mat[NumMat].secargo)!=1){
        printf("Lo sentimos. La materia '%s' de la carrera de %s no tiene datos de integrantes ingresados.\n",U->dep[NumDep].car[NumCar].mat[NumMat].nombre_materia,U->dep[NumDep].car[NumCar].nombre_carrera);
    }
    else{
        for(i=0;i<(U->dep[NumDep].car[NumCar].mat[NumMat].contarintegrantes);i++){
            printf("Integrante %d:\n",(i+1));
            printf("Nombre completo: %s\n",U->dep[NumDep].car[NumCar].mat[NumMat].mie[i].nombre_completo);
            printf("D.N.I: %s\n",U->dep[NumDep].car[NumCar].mat[NumMat].mie[i].dni);
            printf("Es un %s\n\n",U->dep[NumDep].car[NumCar].mat[NumMat].mie[i].doc_o_alum);
        }
    }
    printf("\n\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
}
void OrdenarDepartamentos(Universidad U, int *PuntVec, int departamentos, int *Opcion){
    // Si opcion es 1, los ordena alfabeticamente, si es 2, cantcar (men-may), si es 3, cantcar (maymen).
    int i=0;
    int j=0;
    int auxvec;
    Departamentos *aux=malloc(sizeof(struct Estructura_Departamento));
    switch(*Opcion)
    {
    case 1:
        for(i=0;i<departamentos;i=i+1){
            for(j=0;j<departamentos;j=j+1){
                if((strcmp(U->dep[j].nombre,U->dep[j+1].nombre)==1)&&((j+1)<departamentos)){
                    *aux=U->dep[j];
                    U->dep[j]=U->dep[j+1];
                    U->dep[j+1]=*aux;
                    auxvec=PuntVec[j];
                    PuntVec[j]=PuntVec[j+1];
                    PuntVec[j+1]=auxvec;
                }
            }
        } // Se ordenó
        printf("Departamentos de la %s ordenados alfabeticamente por nombre:\n\n\n",U->nombre);
        for(i=0;i<departamentos;i=i+1){
            printf("'%s': %s\n",U->dep[i].nombre,U->dep[i].descripcion);
        }
        printf("\n\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
        break;
    case 2: // Ordeno por cantidad de carreras de menor a mayor
        for(i=0;i<departamentos;i=i+1){
            for(j=0;j<departamentos;j=j+1){
                if(((U->dep[j].contarcarreras)>(U->dep[j+1].contarcarreras))&&((j+1)<departamentos)){
                    *aux=U->dep[j];
                    U->dep[j]=U->dep[j+1];
                    U->dep[j+1]=*aux;
                    auxvec=PuntVec[j];
                    PuntVec[j]=PuntVec[j+1];
                    PuntVec[j+1]=auxvec;
                }
            }
        } // Se ordenó
        printf("Departamentos de la %s ordenados por cantidad de carreras de menor a mayor:\n\n\n",U->nombre);
        for(i=0;i<departamentos;i=i+1){
            printf("'%s': %s. %d carreras de grado\n",U->dep[i].nombre,U->dep[i].descripcion,U->dep[i].contarcarreras);
        }
        printf("\n\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
        break;
    case 3: // Ordeno por cantidad de carreras de mayor a menor
        for(i=0;i<departamentos;i=i+1){
            for(j=0;j<departamentos;j=j+1){
                if(((U->dep[j].contarcarreras)<(U->dep[j+1].contarcarreras))&&((j+1)<departamentos)){
                    *aux=U->dep[j];
                    U->dep[j]=U->dep[j+1];
                    U->dep[j+1]=*aux;
                    auxvec=PuntVec[j];
                    PuntVec[j]=PuntVec[j+1];
                    PuntVec[j+1]=auxvec;
                }
            }
        } // Se ordenó
        printf("Departamentos de la %s ordenados por cantidad de carreras de menor a mayor:\n\n\n",U->nombre);
        for(i=0;i<departamentos;i=i+1){
            printf("'%s': %s. %d carreras de grado\n",U->dep[i].nombre,U->dep[i].descripcion,U->dep[i].contarcarreras);
        }
        printf("\n\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
        break;
    }
}
void OrdenarCarreras(Universidad U, int *PuntVec, int *Opcion, int NumDep){
    int i=0;
    int j=0;
    int auxvec=0;
    Carreras *aux=malloc(sizeof(struct Estructura_Carrera));
    switch(*Opcion)
    {
    case 1: // Ordenar carreras del departamento correspondiente alfabéticamente...
        for(i=0;i<(U->dep[NumDep].contarcarreras);i=i+1){
            for(j=0;j<(U->dep[NumDep].contarcarreras);j=j+1){
                if(strcmp(U->dep[NumDep].car[j].nombre_carrera,U->dep[NumDep].car[j+1].nombre_carrera)==1){
                    if((j+1)<(U->dep[NumDep].contarcarreras)){
                        *aux=(U->dep[NumDep].car[j]);
                        (U->dep[NumDep].car[j])=(U->dep[NumDep].car[j+1]);
                        (U->dep[NumDep].car[j+1])=*aux;
                        auxvec=PuntVec[j];
                        PuntVec[j]=PuntVec[j+1];
                        PuntVec[j+1]=auxvec;
                    }
                }
            }
        } // Se ordenó
        printf("Carreras del %s ordenadas alfabeticamente por nombre:\n\n\n",U->dep[NumDep].nombre);
        for(i=0;i<(U->dep[NumDep].contarcarreras);i=i+1){
            printf("%d) %s\n",PuntVec[i],U->dep[NumDep].car[i].nombre_carrera);
        }
        printf("\n\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
        break;
    case 2: // Ordenar por cantidad de materias de menor a mayor
        for(i=0;i<(U->dep[NumDep].contarcarreras);i=i+1){
            for(j=0;j<(U->dep[NumDep].contarcarreras);j=j+1){
                if((U->dep[NumDep].car[j].contarmaterias)>(U->dep[NumDep].car[j+1].contarmaterias)){
                    if((j+1)<(U->dep[NumDep].contarcarreras)){
                        *aux=(U->dep[NumDep].car[j]);
                        (U->dep[NumDep].car[j])=(U->dep[NumDep].car[j+1]);
                        (U->dep[NumDep].car[j+1])=*aux;
                        auxvec=PuntVec[j];
                        PuntVec[j]=PuntVec[j+1];
                        PuntVec[j+1]=auxvec;
                    }
                }
            }
        } // Se ordenó
        printf("Carreras del %s ordenadas por cantidad de materias de menor a mayor:\n\n\n",U->dep[NumDep].nombre);
        for(i=0;i<(U->dep[NumDep].contarcarreras);i=i+1){
            printf("%d) %s. %d materias\n",PuntVec[i],U->dep[NumDep].car[i].nombre_carrera,U->dep[NumDep].car[i].contarmaterias);
        }
        printf("\n\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
        break;
    case 3:
        for(i=0;i<(U->dep[NumDep].contarcarreras);i=i+1){
            for(j=0;j<(U->dep[NumDep].contarcarreras);j=j+1){
                if((U->dep[NumDep].car[j].contarmaterias)<(U->dep[NumDep].car[j+1].contarmaterias)){
                    if((j+1)<(U->dep[NumDep].contarcarreras)){
                        *aux=(U->dep[NumDep].car[j]);
                        (U->dep[NumDep].car[j])=(U->dep[NumDep].car[j+1]);
                        (U->dep[NumDep].car[j+1])=*aux;
                        auxvec=PuntVec[j];
                        PuntVec[j]=PuntVec[j+1];
                        PuntVec[j+1]=auxvec;
                    }
                }
            }
        } // Se ordenó
        printf("Carreras del %s ordenadas por cantidad de materias de mayor a menor:\n\n\n",U->dep[NumDep].nombre);
        for(i=0;i<(U->dep[NumDep].contarcarreras);i=i+1){
            printf("%d) %s. %d materias\n",PuntVec[i],U->dep[NumDep].car[i].nombre_carrera,U->dep[NumDep].car[i].contarmaterias);
        }
        printf("\n\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
        break;
    }
}
void OrdenarMaterias(Universidad U, int *PuntVec, int *Opcion, int NumDep, int NumCar){
    int i=0;
    int j=0;
    int auxvec=0;
    Materias *aux=malloc(sizeof(struct Estructura_Materia));
    switch(*Opcion)
    {
    case 1: // Orden alfabetico
        for(i=0;i<(U->dep[NumDep].car[NumCar].contarmaterias);i=i+1){
            for(j=0;j<(U->dep[NumDep].car[NumCar].contarmaterias);j=j+1){
                if((strcmp(U->dep[NumDep].car[NumCar].mat[j].nombre_materia,U->dep[NumDep].car[NumCar].mat[j+1].nombre_materia)==1)&&((j+1)<(U->dep[NumDep].car[NumCar].contarmaterias))){
                    *aux=(U->dep[NumDep].car[NumCar].mat[j]);
                    (U->dep[NumDep].car[NumCar].mat[j])=(U->dep[NumDep].car[NumCar].mat[j+1]);
                    (U->dep[NumDep].car[NumCar].mat[j+1])=*aux;
                    auxvec=PuntVec[j];
                    PuntVec[j]=PuntVec[j+1];
                    PuntVec[j+1]=aux;
                }
            }
        } // Se ordenó
        printf("Materias de la carrera '%s' ordenadas alfabeticamente por nombre:\n\n\n",U->dep[NumDep].car[NumCar].nombre_carrera);
        for(i=0;i<(U->dep[NumDep].car[NumCar].contarmaterias);i=i+1){
            printf("%s - [%s]\n",U->dep[NumDep].car[NumCar].mat[i].nombre_materia,U->dep[NumDep].car[NumCar].mat[i].codigo);
        }
        printf("\n\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
        break;
    case 2: // Ordenar por codigo
        for(i=0;i<(U->dep[NumDep].car[NumCar].contarmaterias);i=i+1){
            for(j=0;j<(U->dep[NumDep].car[NumCar].contarmaterias);j=j+1){
                if((strcmp(U->dep[NumDep].car[NumCar].mat[j].codigo,U->dep[NumDep].car[NumCar].mat[j+1].codigo)==1)&&((j+1)<(U->dep[NumDep].car[NumCar].contarmaterias))){
                    *aux=(U->dep[NumDep].car[NumCar].mat[j]);
                    (U->dep[NumDep].car[NumCar].mat[j])=(U->dep[NumDep].car[NumCar].mat[j+1]);
                    (U->dep[NumDep].car[NumCar].mat[j+1])=*aux;
                    auxvec=PuntVec[j];
                    PuntVec[j]=PuntVec[j+1];
                    PuntVec[j+1]=aux;
                }
            }
        } // Se ordenó
        printf("Materias de la carrera '%s' ordenadas por codigo:\n\n\n",U->dep[NumDep].car[NumCar].nombre_carrera);
        for(i=0;i<(U->dep[NumDep].car[NumCar].contarmaterias);i=i+1){
            printf("%s - [%s]\n",U->dep[NumDep].car[NumCar].mat[i].nombre_materia,U->dep[NumDep].car[NumCar].mat[i].codigo);
        }
        printf("\n\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
        break;
    case 3: // Por cantidad de integrantes (de menor a mayor).
        for(i=0;i<(U->dep[NumDep].car[NumCar].contarmaterias);i=i+1){
            for(j=0;j<(U->dep[NumDep].car[NumCar].contarmaterias);j=j+1){
                if(((U->dep[NumDep].car[NumCar].mat[j].contarintegrantes)>(U->dep[NumDep].car[NumCar].mat[j+1].contarintegrantes))&&((j+1)<(U->dep[NumDep].car[NumCar].contarmaterias))){
                    *aux=(U->dep[NumDep].car[NumCar].mat[j]);
                    (U->dep[NumDep].car[NumCar].mat[j])=(U->dep[NumDep].car[NumCar].mat[j+1]);
                    (U->dep[NumDep].car[NumCar].mat[j+1])=*aux;
                    auxvec=PuntVec[j];
                    PuntVec[j]=PuntVec[j+1];
                    PuntVec[j+1]=aux;
                }
            }
        } // Se ordenó
        printf("Materias de la carrera '%s' ordenadas por cantidad de integrantes de menor a mayor:\n\n\n",U->dep[NumDep].car[NumCar].nombre_carrera);
        for(i=0;i<(U->dep[NumDep].car[NumCar].contarmaterias);i=i+1){
            printf("%s - [%s].\n",U->dep[NumDep].car[NumCar].mat[i].nombre_materia,U->dep[NumDep].car[NumCar].mat[i].codigo);
        }
        printf("\n\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
        break;
    case 4: // Por cantidad de integrantes de mayor a menor
        for(i=0;i<(U->dep[NumDep].car[NumCar].contarmaterias);i=i+1){
            for(j=0;j<(U->dep[NumDep].car[NumCar].contarmaterias);j=j+1){
                if(((U->dep[NumDep].car[NumCar].mat[j].contarintegrantes)<(U->dep[NumDep].car[NumCar].mat[j+1].contarintegrantes))&&((j+1)<(U->dep[NumDep].car[NumCar].contarmaterias))){
                    *aux=(U->dep[NumDep].car[NumCar].mat[j]);
                    (U->dep[NumDep].car[NumCar].mat[j])=(U->dep[NumDep].car[NumCar].mat[j+1]);
                    (U->dep[NumDep].car[NumCar].mat[j+1])=*aux;
                    auxvec=PuntVec[j];
                    PuntVec[j]=PuntVec[j+1];
                    PuntVec[j+1]=aux;
                }
            }
        } // Se ordenó
        printf("Materias de la carrera '%s' ordenadas por cantidad de integrantes de menor a mayor:\n\n\n",U->dep[NumDep].car[NumCar].nombre_carrera);
        for(i=0;i<(U->dep[NumDep].car[NumCar].contarmaterias);i=i+1){
            printf("%s - [%s]\n",U->dep[NumDep].car[NumCar].mat[i].nombre_materia,U->dep[NumDep].car[NumCar].mat[i].codigo);
        }
        printf("\n\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
        break;
    }
}
void OrdenarMiembros(Universidad U, int *PuntVec, int *Opcion, int NumDep, int NumCar, int NumMat){
    int i=0;
    int j=0;
    int auxvec=0;
    Miembros *aux=malloc(sizeof(struct Estructura_Miembros));
    switch(*Opcion)
    {
    case 1:
        for(i=0;i<(U->dep[NumDep].car[NumCar].mat[NumMat].contarintegrantes);i=i+1){
            for(j=0;j<(U->dep[NumDep].car[NumCar].mat[NumMat].contarintegrantes);j=j+1){
                if(strcmp(U->dep[NumDep].car[NumCar].mat[NumMat].mie[j].nombre_completo,U->dep[NumDep].car[NumCar].mat[NumMat].mie[j+1].nombre_completo)==1){
                    if((j+1)<(U->dep[NumDep].car[NumCar].mat[NumMat].contarintegrantes)){
                        *aux=(U->dep[NumDep].car[NumCar].mat[NumMat].mie[j]);
                        (U->dep[NumDep].car[NumCar].mat[NumMat].mie[j])=(U->dep[NumDep].car[NumCar].mat[NumMat].mie[j+1]);
                        (U->dep[NumDep].car[NumCar].mat[NumMat].mie[j+1])=*aux;
                        auxvec=PuntVec[j];
                        PuntVec[j]=PuntVec[j+1];
                        PuntVec[j+1]=auxvec;
                    }
                }
            }
        } // Se ordenó
        if(U->dep[NumDep].car[NumCar].mat[NumMat].secargo==1){
            printf("Miembros de '%s' ordenados alfabeticamente por nombre:\n\n\n",U->dep[NumDep].car[NumCar].mat[NumMat].nombre_materia);
            for(i=0;i<(U->dep[NumDep].car[NumCar].mat[NumMat].contarintegrantes);i=i+1){
                printf("Integrante %d:\n",(i+1));
                printf("Nombre completo: %s\n",U->dep[NumDep].car[NumCar].mat[NumMat].mie[i].nombre_completo);
                printf("D.N.I: %s\n",U->dep[NumDep].car[NumCar].mat[NumMat].mie[i].dni);
                printf("Es un %s\n",U->dep[NumDep].car[NumCar].mat[NumMat].mie[i].doc_o_alum);
                printf("\n\n");
            }
        }
        else{
            printf("Lo sentimos. Los miembros de '%s' no han sido ingresados.\n",U->dep[NumDep].car[NumCar].mat[NumMat].nombre_materia);
        }
        printf("\n\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
        break;
    case 2: // ordenar por dni
        for(i=0;i<(U->dep[NumDep].car[NumCar].mat[NumMat].contarintegrantes);i=i+1){
            for(j=0;j<(U->dep[NumDep].car[NumCar].mat[NumMat].contarintegrantes);j=j+1){
                if(strcmp(U->dep[NumDep].car[NumCar].mat[NumMat].mie[j].dni,U->dep[NumDep].car[NumCar].mat[NumMat].mie[j+1].dni)==1){
                    if((j+1)<(U->dep[NumDep].car[NumCar].mat[NumMat].contarintegrantes)){
                        *aux=(U->dep[NumDep].car[NumCar].mat[NumMat].mie[j]);
                        (U->dep[NumDep].car[NumCar].mat[NumMat].mie[j])=(U->dep[NumDep].car[NumCar].mat[NumMat].mie[j+1]);
                        (U->dep[NumDep].car[NumCar].mat[NumMat].mie[j+1])=*aux;
                        auxvec=PuntVec[j];
                        PuntVec[j]=PuntVec[j+1];
                        PuntVec[j+1]=auxvec;
                    }
                }
            }
        } // Se ordenó
        if(U->dep[NumDep].car[NumCar].mat[NumMat].secargo==1){
        printf("Miembros de '%s' ordenados por D.N.I:\n\n\n",U->dep[NumDep].car[NumCar].mat[NumMat].nombre_materia);
            for(i=0;i<(U->dep[NumDep].car[NumCar].mat[NumMat].contarintegrantes);i=i+1){
                printf("Integrante %d:\n",PuntVec[i]);
                printf("Nombre completo: %s\n",U->dep[NumDep].car[NumCar].mat[NumMat].mie[i].nombre_completo);
                printf("D.N.I: %s\n",U->dep[NumDep].car[NumCar].mat[NumMat].mie[i].dni);
                printf("Es un %s\n",U->dep[NumDep].car[NumCar].mat[NumMat].mie[i].doc_o_alum);
                printf("\n\n");
            }
        }
        else{
            printf("Lo sentimos. Los miembros de '%s' no han sido ingresados.\n",U->dep[NumDep].car[NumCar].mat[NumMat].nombre_materia);
        }
        printf("\n\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
        break;
    }
}
void BuscarDepartamento(Universidad U, int *PuntVecDep, int departamentos){
    // Solo se puede buscar por cantidad de carreras...
    int i=0;
    int j=0;
    int opcion=0;
    int bandera=-1;
    int auxvec=0;
    Departamentos *aux=malloc(sizeof(struct Estructura_Departamento));
    printf("Ingrese la cantidad de carreras que tiene el departamento que desea buscar.\n");
    scanf("%d",&opcion);
    printf("\n\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
    // Primero, ordeno los departamentos por cantidad de carreras de menor a mayor
    for(i=0;i<departamentos;i=i+1){
        for(j=0;j<departamentos;j=j+1){
            if(((U->dep[j].contarcarreras)>(U->dep[j+1].contarcarreras))&&((j+1)<departamentos)){
                *aux=(U->dep[j]);
                (U->dep[j])=(U->dep[j+1]);
                (U->dep[j+1])=*aux;
                auxvec=PuntVecDep[j];
                PuntVecDep[j]=PuntVecDep[j+1];
                PuntVecDep[j+1]=auxvec;
            }
        }
    } // Se ordenó
    int inicio=0;
    int fin=(departamentos-1);
    int centro=0;
    while(inicio<=fin){ // Buscar el departamento por cantidad de carreras
        centro=(fin+inicio)/2;
        if((U->dep[centro].contarcarreras)==opcion){ // Si el departamento en la posicion centro tiene las carreras
            bandera=1;                               // que dijo el usuario, bandera se pone en 1 y entra el if de abajo
            break;                             // que dijo el usuario, bandera se pone en 1 y entra el if de abajo
        }
        if((U->dep[centro].contarcarreras)<opcion){ // si la cant. carreras es < a lo que eligio, el inicio incrementa
            inicio=centro+1;                        // en 1 con respecto a centro
        }
        if((U->dep[centro].contarcarreras)>opcion){ // Si lo que busca está antes del centro, el fin, es centro-1
            fin=centro-1;
        }
    }
    if(bandera==(-1)){ // Si nunca la encontro, bandera se mantiene en -1 como quedó en la declaración
        printf("Lo sentimos. Ninguno de nuestros departamentos tiene %d carreras.\n",opcion);
    }
    if(bandera==1){ // Si la bandera se puso en 1, encontró el departamento con dichas carreras
        printf("El '%s', cuyo numero de identificacion es %d tiene %d carreras.\n",U->dep[centro].nombre,PuntVecDep[centro],U->dep[centro].contarcarreras);
    }
    printf("\n\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
}
void BuscarCarreras(Universidad U, int departamentos){
    // Buscar carreras por cantidad de materias...
    int i=0;
    int j=0;
    int opcion=0;
    int bandera=-1;
    printf("Ingrese la cantidad de materias que tiene la carrera que desea buscar.\n");
    scanf("%d",&opcion);
    printf("\n\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
    for(i=0;i<departamentos;i=i+1){
        for(j=0;j<(U->dep[i].contarcarreras);j=j+1){
            if((U->dep[i].car[j].contarmaterias)==opcion){
                bandera=1;
                printf("Dentro del %s, la carrera '%s' tiene %d materias.\n",U->dep[i].nombre,U->dep[i].car[j].nombre_carrera,opcion);
            }
        }
    }
    if(bandera==(-1)){
        printf("Lo sentimos. Ninguna carrera de la %s tiene %d materias.\n",U->nombre,opcion);
    }
    printf("\n\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
}
void BuscarMaterias(Universidad U, int departamentos){
    // Buscar materias por cantidad de integrantes y por codigo...
    int i=0;
    int j=0;
    int k=0;
    int bandera=(-1);
    int integrantes=0;
    char Codigo[7]=" ";
    int opcion=0;
    int numdep=0;
    int numcar=0;
    printf("Ingrese '1' para buscar las materias por codigo.\nIngrese '2' para buscar las materias por cantidad de integrantes.\n");
    scanf("%d",&opcion);
    printf("\n\n");
    switch(opcion)
    {
    case 1:
        for(i=0;i<departamentos;i=i+1){
        printf("Ingrese '%d' para acceder al %s.\n",(i+1),U->dep[i].nombre);
        }
        scanf("%d",&numdep);
        numdep--;
        printf("\n\n");
        for(i=0;i<(U->dep[numdep].contarcarreras);i=i+1){
            printf("Ingrese '%d' para acceder a la carrera de %s.\n",(i+1),U->dep[numdep].car[i].nombre_carrera);
        }
        scanf("%d",&numcar);
        numcar--;
        printf("\n\nIngrese el codigo de la materia que desea buscar.\n");
        fflush(stdin);
        gets(Codigo);
        printf("\n\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
        for(i=0;i<(U->dep[numdep].car[numcar].contarmaterias);i=i+1){
            if(strcmp(U->dep[numdep].car[numcar].mat[i].codigo,Codigo)==0){
                bandera=1;
                printf("La materia '%s' tiene como codigo [%s].\n",U->dep[numdep].car[numcar].mat[i].nombre_materia,U->dep[numdep].car[numcar].mat[i].codigo);
            }
        }
        if(bandera==(-1)){
            printf("Lo sentimos. Ninguna materia de %s tiene %s como codigo.\n",U->dep[numdep].car[numcar].nombre_carrera,Codigo);
        }
        printf("\n\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
        break;
    case 2: // Buscar por cantidad de integrantes:
        for(i=0;i<departamentos;i=i+1){
            printf("Ingrese '%d' para acceder al %s.\n",(i+1),U->dep[i].nombre);
        }
        scanf("%d",&numdep);
        numdep--;
        printf("\n\n");
        for(i=0;i<(U->dep[numdep].contarcarreras);i=i+1){
            printf("Ingrese '%d' para acceder a %s.\n",(i+1),U->dep[numdep].car[i].nombre_carrera);
        }
        scanf("%d",&numcar);
        numcar--;
        printf("\n\nIngrese la cantidad de integrantes de la materia que esta buscando.\n");
        scanf("%d",&integrantes);
        printf("\n\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
        for(i=0;i<(U->dep[numdep].car[numcar].contarmaterias);i=i+1){
            if((U->dep[numdep].car[numcar].mat[i].contarintegrantes)==integrantes){
                bandera=1;
                printf("La materia '%s' tiene %d integrantes.\n",U->dep[numdep].car[numcar].mat[i].nombre_materia,integrantes);
            }
        }
        if(bandera==(-1)){
            printf("Lo sentimos. Ninguna materia tiene %d integrantes.\n",integrantes);
        }
        printf("\n\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
        break;
    }
    bandera=-1;
}
void BuscarMiembros(Universidad U, int departamentos){
   int i=0;
    int numdep=0;
    int numcar=0;
    int nummat=0;
    int bandera=-1;
    char dnibuscar[10]=" ";
    for(i=0;i<departamentos;i++){
        printf("Ingrese '%d' para acceder al '%s'.\n",(i+1),U->dep[i].nombre);
    }
    scanf("%d",&numdep);
    numdep--;
    printf("\n\n");
    for(i=0;i<(U->dep[numdep].contarcarreras);i++){
        printf("Ingrese '%d' para acceder a la carrera '%s'.\n",(i+1),U->dep[numdep].car[i].nombre_carrera);
    }
    scanf("%d",&numcar);
    numcar--;
    printf("\n\n");
    for(i=0;i<(U->dep[numdep].car[numcar].contarmaterias);i++){
        printf("Ingrese '%d' para acceder a '%s'.\n",(i+1),U->dep[numdep].car[numcar].mat[i].nombre_materia);
    }
    scanf("%d",&nummat);
    nummat--;
    printf("\n\nIngrese el D.N.I de la persona que esta buscando para obtener sus datos.\n");
    fflush(stdin);
    gets(dnibuscar);
    printf("\n\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
    for(i=0;i<(U->dep[numdep].car[numcar].mat[nummat].contarintegrantes);i++){
        if(strcmp(U->dep[numdep].car[numcar].mat[nummat].mie[i].dni,dnibuscar)==0){
            bandera=1;
            printf("El D.N.I '%s' le corresponde al %s %s, de la materia '%s' de %s.\n",dnibuscar,U->dep[numdep].car[numcar].mat[nummat].mie[i].doc_o_alum,U->dep[numdep].car[numcar].mat[nummat].mie[i].nombre_completo,U->dep[numdep].car[numcar].mat[nummat].nombre_materia,U->dep[numdep].car[numcar].nombre_carrera);
        }
    }
    if(bandera==(-1)){
        printf("Lo sentimos. el D.N.I '%s' no corresponde a ningun estudiante ni docente de la %s.\n",dnibuscar,U->nombre);
    }
    printf("\n\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
}



