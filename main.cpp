#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int size = 0;


//Funcion para registrar los altletas
void Registrar(std::string nombres[], std::string pais[],std::string diciplina[],std::string genero[], int Num_medallas[]){
    
    int indice = size + 1; //esto va aguardar el nombre del atleta un indice mas arriba del tamaño ya establiecido por el csv
   
    std::cout<< "Nombre completo del atleta:"<<std::endl;
    std::cin>> nombres[indice];
    std::cout<< "Pais de origen:"<<std::endl;
    std::cin>> pais[indice];
    std::cout << "Diciplina: "<<std::endl;
    std::cin>> diciplina[indice];
    std::cout<<"Genero del atleta M/F:"<<std::endl;//agg validacion
    std::cin>>genero[indice];
    std::cout<<"ingresa el numero de medallas de oro que tiene el atleta"<<std::endl;
    std::cin>> Num_medallas[indice];

    return 0;
}



void Mostrar



int main() {

int menu = 1;
std::string nombres[size];
std::string pais[size];
std::string diciplina[size];
std::string genero[size];
int Num_medallas[size];
std::string linea;


//abrir archivo con su validacion  y determinar el tamaño de los arrays...

std::ifstream archivo("data1.csv");

 if (!archivo.is_open()){
 std::cerr << "No se pudo abrir el archivo" << std::endl;
 return 1; 
 }


 //obtener lineas del archivo e ir linea por linea hasta que no queden y si es true aumentar el tamaño del array
 while(std::getline(archivo, linea)){
    size++;
 }


//menu
std::cout<< "-Programa Oficial de Registro de Atletas de la FMA-"<<std::endl;
std::cout<< "Selecciona que deseas realizar"<<std::endl;
std::cout<< "1.- Registrar Atleta" <<std::endl;


switch (menu)
{
case 1: 
    Registrar;
    break;
case 2:
  

default:
    break;
}



    return 0;
}