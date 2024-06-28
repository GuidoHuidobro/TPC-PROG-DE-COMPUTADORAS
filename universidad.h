#ifndef UNIVERSIDAD_H_INCLUDED
#define UNIVERSIDAD_H_INCLUDED
// DECLARO LAS ESTRUCTURAS A USAR
struct Estructura_Miembros;
struct Estructura_Materia;
struct Estructura_Carrera;
struct Estructura_Departamento;
struct Estructura_Universidad;
// DECLARO UN IDENTIFICADOR DEL TIPO PUNTERO A LA ESTRUCTURA PRINCIPAL E IDENTIFICADORES PARA LAS SUBESTRUCTURAS
typedef struct Estructura_Miembros Miembros;
typedef struct Estructura_Materia Materias;
typedef struct Estructura_Carrera Carreras;
typedef struct Estructura_Departamento Departamentos;
typedef struct Estructura_Universidad *Universidad;
// CARGA AUTOMÁTICA DE VECTORES QUE CONTIENEN EL NÚMERO DE CADA DEP, CAR, MAT... 1, 2, 3, 4, ETC...
void CargarArrayNumeroAlumnos(int *punt, int l);
void CargarArrayNumeroMaterias(int *punt, int l);
void CargarArrayNumeroCarreras(int *punt, int l);
void CargarArrayNumeroDepartamentos(int *punt, int l);
// PROCEDIMIENTOS PARA MOSTRAR TÍTULOS
void Departamentoss();
void Carrerass();
void Materiass();
void TituloMostrarIntegrantes();
void TituloIngresoEstudiantes();
void Busquedaa();
void Ordenamientoo();
void MensajeMenu(int *Menu);
void MensajeMenuBusqueda(int *Menu);
void MensajeMenuDepartamentos(int *OpcionMenu);
void MensajeMenuCarreras(Universidad U, int *NumDep, int *OpcionMenu);
void MensajeMenuMaterias(Universidad U, int *NumDep, int *NumCar, int *OpcionMenu);
void MensajeMenuMiembros(Universidad U, int *NumDep, int *NumCar, int *NumMat, int *OpcionMenu);
// PROCEDIMIENTOS PARA LA PRIMERA PARTE DEL MENÚ (OBTENCIÓN DE DATOS FIJOS).
void OpcionMostrarDepartamentos();
void OpcionMostrarCarreras(Universidad U);
void OpcionMostrarMaterias(Universidad U, int *PuntNumDep, int *PuntNumCarrera);
Universidad CargarDatos(int departamentos, int carreras, int materias);
void MostrarUniversidad(Universidad U);
// PROCEDIMIENTOS PARA INCORPORAR AL MENÚ (Cargar miembros y mostrar datos).
void MostrarDepartamentos(Universidad U, int departamentos, int *PuntVec);
void MostrarCarreras(Universidad U, int numdepartamento, int *PuntVecNumCarrera);
void MostrarMaterias(Universidad U, int numdepartamento, int numcarrera);
void OpcionCargarMiembros(Universidad U, int *NumDep, int *NumCar, int *NumMat);
void CargarMiembros(Universidad U, int NumDep, int NumCar, int NumMat);
void OpcionMostrarMiembros(Universidad U, int *NumDep, int *NumCar, int *NumMat);
void MostrarMiembros(Universidad U, int NumDep, int NumCar, int NumMat);
// PROCEDIMIENTOS DE BUSQUEDA...
// BuscarDepartamento está hecho con búsqueda binaria. El resto de los procedimientos están hechos con búsqueda secuencial
void BuscarDepartamento(Universidad U, int *PuntVecDep, int departamentos);
void BuscarCarreras(Universidad U, int departamentos);
void BuscarMaterias(Universidad U, int departamentos);
void BuscarMiembros(Universidad U, int departamentos);
// PROCEDIMIENTOS DE ORDENAMIENTO...
void OrdenarDepartamentos(Universidad U, int *PuntVec, int departamentos, int *Opcion); // Ordena Correctamente
void OrdenarCarreras(Universidad U, int *PuntVec, int *Opcion, int NumDep);
void OrdenarMaterias(Universidad U, int *PuntVec, int *Opcion, int NumDep, int NumCar);
void OrdenarMiembros(Universidad U, int *PuntVec, int *Opcion, int NumDep, int NumCar, int NumMat);

void MensajeCerrar();
#endif // UNIVERSIDAD_H_INCLUDED
