#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <windows.h>


using namespace std;

void hacerLineasHorizontales(int n, char c){
    for(int i=0; i<n; i++){
        cout << c;
    }
    cout << endl;
}

void hacerLineasVerticales(int nEspacios, int nLineas, string opciones[],int longitudArray,char c){

    int cont = 0;
    int i = 0;

    //IMPORTANTE: longitudArray siempre debe modificarse segun la cantidad de opciones que se desean mostrar de forma manual
    //y por cada posicion en el array, nLineas = longitudArray + 4
    // Ejemplo: string opciones[] = {"1. JUGAR", "2. VER CARROS", "0. SALIR"};
    //          int longitudArray = 3;
    //          int nLineas = 7;
    

    while(cont < nLineas){
        cout << c;
        if((cont-2 == i)&&(i < longitudArray)){
            for(int j = 0; j < (nEspacios - longitudArray)/3; j++)
                cout << " ";
            cout << opciones[i];
            for(int j = opciones[i].length() + (nEspacios - longitudArray)/3; j < nEspacios-1; j++)
                cout << " ";
            i++;
        }
        else{
            for(int j = 0; j < nEspacios-1; j++)
                cout << " ";
        }
        cout << c << endl;
        cont++;
    }

    
}

void pantallaInicio(){

    system("cls");
    string bienvenido[] = {"BIENVENIDO", "A", "PEPE KART 23"};

    hacerLineasHorizontales(80,'-');
    hacerLineasVerticales(80, 7, bienvenido, 3, '|');
    hacerLineasHorizontales(80,'-');
    cout << "\n\n\n\n\n\n\n\n";
    system("pause");


};

void abusador(){
    cout << "\n\nError, opcion no valida\n";
    cout << "Volvera a la pantalla de inicio en 5 segundos\n\n";
    Sleep(5000);
    system("pause");
}

int principal(){

    int op = -1;

    while (op < 0 || op > 2){
        string menuP[] = {"1. JUGAR", "2. VER CARROS", "0. SALIR"};
        system("cls");
        hacerLineasHorizontales(80,'-');
        hacerLineasVerticales(80, 7, menuP, 3, '|');
        hacerLineasHorizontales(80,'-');
        cout << "\n\n\nSU RESPUESTA: ";
        cin >> op; 
        if(op < 0 || op > 2){
            abusador();
        }
    }
    

    return op;
}

void salir(){

    string chao[]{"GRACIAS", "POR", "JUGAR", "PEPE KART 23", " :D"};
    system("cls");
    hacerLineasHorizontales(80,'-');
    hacerLineasVerticales(80, 9, chao, 5, '|');
    hacerLineasHorizontales(80,'-');
}
