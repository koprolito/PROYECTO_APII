#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include "carros.h"

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
    int nOpciones = sizeof(opciones)/sizeof(opciones[0]);



    while(cont < nLineas){
        cout << c;
        if((cont-2 == i)&&(i < longitudArray)){
            for(int j = 0; j < (nEspacios - nOpciones)/3; j++)
                cout << " ";
            cout << opciones[i];
            for(int j = opciones[i].length() + (nEspacios - nOpciones)/3; j < nEspacios-1; j++)
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

void jugar(){
    srand(time(0));
    int Bcvel,Bpos,res2;
    string Bvel, res;
    int cant, h, g, Bcar;
    int posUlt;
    do{
        system("cls");
        cout<<"Indique la cantidad de carritos. Minimo 2 y maximo 12:\n\n";
        cin>>cant;
        h=2;
        TLista p=NULL;
        for (int b=1; b<=cant; b++){
            g=0;
            cout<<"\n\nIndique velocidad del carrito "<<b<<": ";
            cin>>(Bcvel);
            Bcar=b;
            do{
                g++;
                Bvel=Bvel+" ";              
            }while (g!=Bcvel);
            Bpos=h;
            h=h+2;
            if (b==cant){
                posUlt=Bpos;
            }

            p = insertarFinal(p,Bcar, Bvel,Bcvel, Bpos);
                
        }
        TLista n=p;
        for (int f=1;f<=cant;f++){
            gotoxy(1,n->pos);cout<<"*"; gotoxy(80,n->pos);cout<<"|";
            n=n->prox;
        }
        n=p;
        system("cls");
        cout << "\n\nEl proceso de lectura de los datos de los carros ha finalizado exitosamente" << endl;
        cout << "\nPulse cualquier tecla para iniciar la carrera"<<endl;
        system("pause");
        system("cls");
            
        Carre(n,cant,posUlt);
            
        cout<<endl;
        cout<<endl;
        cout<<"iniciar de nuevo? 1 Si y 2 No"<<endl;
        cin>>res2;
    }while(res2==1);
}

void salir(){

    string chao[]{"GRACIAS", "POR", "JUGAR", "PEPE KART 23", " :D"};
    
    hacerLineasHorizontales(80,'-');
    hacerLineasVerticales(80, 9, chao, 5, '|');
}

void opcionSeleccionada(int op){
    
    switch (op){
        case 1:
            jugar();
            break;
        case 0:
            salir();
            break;
        
        default: 
            abusador();
            break;
    }
}
