#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int size = 0; // cantidad de atletas leídos del archivo
std::string Nombre;

// funcion para registrar los atletas  
void Registrar(std::string nombres[], std::string pais[], std::string disciplina[],
               std::string genero[], int Num_medallas[]) {

    int indice = size; //indice se va a iniciar con el tamaño de size

    std::cout << "Nombre completo del atleta: ";
    std::cin >> nombres[indice];
    std::cout << "Pais de origen: ";
    std::cin >> pais[indice];
    std::cout << "Disciplina: ";
    std::cin >> disciplina[indice];
    std::cout << "Genero del atleta M/F: ";
    std::cin >> genero[indice];
    std::cout << "Numero de medallas de oro: ";
    std::cin >> Num_medallas[indice];

    size++; // actualiza la variable size al agregar a un nuevo atleta
}

// mostrar los datos del atleta con su nombre
void Mostrar(std::string nombres[], std::string pais[], std::string disciplina[],
             std::string genero[], int Num_medallas[]) {
    std::cout << "Ingresa el nombre del atleta: ";
    std::cin >> Nombre;

bool encontrado = false;
    
    for (int i = 0; i < size; i++) {
        if (Nombre == nombres[i]) {
            std::cout << "Nombre: " << nombres[i] << std::endl;
            std::cout << "Pais: " << pais[i] << std::endl;
            std::cout << "Genero: " << genero[i] << std::endl;
            std::cout << "Disciplina: " << disciplina[i] << std::endl;
            std::cout << "Medallas: " << Num_medallas[i] << std::endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        std::cout << Nombre << "no es un atleta" << std::endl;
    }
}

// Calcular total de medallas de un país
void MedallasPais(std::string pais[], int Num_medallas[]) {
   
   
    std::string paisBuscar; 
    std::cout << "Ingresa el nombre del pais: ";
    std::cin >> paisBuscar;

    int total = 0;
    for (int i = 0; i < size; i++) {
        if (pais[i] == paisBuscar) {
            total += Num_medallas[i];
        }
    }
    std::cout << "Total de medallas de oro de " << paisBuscar << ": " << total << std::endl;
}



// Encontrar al atleta con más medallas
void AtletaMax(std::string nombres[], int Num_medallas[]) {
    if (size == 0) {
        std::cout << "No hay atletas registrados.\n";
        return;
    }

    int max = Num_medallas[0];
    int indi = 0;
    for (int i = 1; i < size; i++) {
        if (Num_medallas[i] > max) {
            max = Num_medallas[i];
            indi = i;
        }
    }
    std::cout << "El atleta con mas medallas es " << nombres[indi]
              << " con " << max << " medallas de oro.\n";
}


int main() {
    std::string rutaArchivo;

    // pedir ruta del archivo al usuario
    std::cout << "Ingresa la ruta del archivo CSV: ";
    std::cin >> rutaArchivo;

    // abrir archivo
    std::ifstream archivo(rutaArchivo);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo.\n";
        return 1;
    }



    // cuenta las lineas para darle el tamaño a size
    std::string linea;
    while (std::getline(archivo, linea)) {
        size++;
    }
    archivo.close();

    // al inicio queria iniciar los arreglos con size pero me di cuetna que no se puede definir los arreglos con una variable que se define en tienpo de ejecucion por lo tanto ya los inicie con un limite
    std::string nombres[200];
    std::string pais[200];
    std::string disciplina[200];
    std::string genero[200];
    int Num_medallas[200];

    size = 0; // reinicia para rellenar datos

    // cierro el anterior para volvcer a hacer otra lectura pero esta vez para leer lo que hay dentro de cada linea
    std::ifstream archivo2(rutaArchivo);
    while (std::getline(archivo2, linea)) {
        std::stringstream ss(linea);
        std::string temp;
        std::getline(ss, nombres[size], ',');
        std::getline(ss, pais[size], ',');
        std::getline(ss, disciplina[size], ',');
        std::getline(ss, genero[size], ',');
        std::getline(ss, temp, ',');
        Num_medallas[size] = std::stoi(temp); //stoi convierte el string del numero de medallas a un int para poder gaurdarlo
        size++;
    }
    archivo2.close();

    //menu
    int menu;
    do {
        std::cout << "\n-Programa Oficial de Registro de Atletas de la FMA-\n";
        std::cout << "1. Registrar atleta\n";
        std::cout << "2. Mostrar atleta por nombre\n";
        std::cout << "3. Medallas totales de un pais\n";
        std::cout << "4. Atleta con mas medallas\n";
        std::cout << "5. Salir\n";
        std::cout << "Elige una opcion: ";
        std::cin >> menu;

        switch (menu) {
        case 1:
            Registrar(nombres, pais, disciplina, genero, Num_medallas);
            break;
        case 2:
            Mostrar(nombres, pais, disciplina, genero, Num_medallas);
            break;
        case 3:
            MedallasPais(pais, Num_medallas);
            break;
        case 4:
            AtletaMax(nombres, Num_medallas);
            break;
        case 5:
            std::cout << "Saliendo...\n";
            break;
        default:
            std::cout << "Opcion no valida.\n";
        }

    } while (menu != 5);

    return 0;
}
