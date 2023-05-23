#include <iostream>  
#include <windows.h>  
#include <stdlib.h> 
#include <string>
#include <time.h>
#include <cstdlib>
#include "carros.h"
#include "menu.h"
using namespace std;


void pantallaDefault(int nEspacios,string cositas[], int nLineas, int longitudArray){
    hacerLineasHorizontales(nEspacios,'-');
    hacerLineasVerticales(nEspacios, nLineas, cositas, longitudArray, '|');
    hacerLineasHorizontales(nEspacios,'-');
    cout << "\n\n\nSU RESPUESTA: ";
}

void jugar(){
    srand(time(0));
    int Bcvel,Bpos,res2;
    string Bvel, res;
    int cant, h, g, Bcar;
    int posUlt;
    int nCarros;
    TLista p = NULL;

    do{
        p = NULL;
        string vPalabra[] = {"Indique la cantidad de carritos", "Minimo 2 y maximo 12 carritos: "};
        system("cls");
        pantallaDefault(80,vPalabra, 6, 2);
        cin>>cant;
        h=2;
        for (int b=1; b<=cant; b++){
            g=0;
            system("cls");
            if(b>1){
                vPalabra[0] = "Velocidad del carro " + to_string(b) + " (1-10)";
                vPalabra[1] = "Para regresar al carro anterior escriba 11";
                pantallaDefault(80,vPalabra, 6, 2);
            }else{
                vPalabra[0] = "Velocidad del carro " + to_string(b) + " (1-10): ";
                pantallaDefault(80,vPalabra, 4, 1);
            } 

            cin>>(Bcvel);
            Bcar=b;

            if((Bcvel==11)&&(b>1)){
                system("cls");
                if(b == 2){
                    TLista aux = p;
                    vPalabra[0] = "Cual sera la velocidad a modificar";
                    vPalabra[1] = "para el carro anterior?:";
                    pantallaDefault(80,vPalabra, 6, 2);
                    cin >> Bcvel;
                    aux->cvel = Bcvel;
                    b--;
                }else{
                    TLista aux = p;
                    vPalabra[0] = {"A cual de los carros desea modificar la velocidad?"};
                    vPalabra[1] = {"Hasta ahora solo hay "+ to_string(b) +" carros"};
                    pantallaDefault(80,vPalabra, 6, 2);
                    cin >> nCarros;
                    while(aux->car != nCarros){
                        aux = aux->prox;
                    }
                    cin >> Bcvel;
                    aux->cvel = Bcvel;
                    b--;
                }
            }else{
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
        }
        TLista n=p;
        for (int f=1;f<=cant;f++){
            gotoxy(1,n->pos); cout<<"*"; gotoxy(80,n->pos);cout<<"|";
            n=n->prox;
        }
        n=p;
        system("cls");
        vPalabra[0] = "El proceso de lectura de los datos de los carros termino";
        vPalabra[1] = "Pulse cualquier tecla para iniciar la carrera";
        pantallaDefault(100,vPalabra, 6, 2);
        system("pause");
        system("cls");

        Carre(n,cant,posUlt);

        cout<<endl;
        cout<<endl;
        cout<<"iniciar de nuevo? 1 Si y 2 No"<<endl;
        cin>>res2;
    }while(res2==1);
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

int main(){  

    int op = -1;
    pantallaInicio();
    while(op!=0){
        op = principal();
        opcionSeleccionada(op);
    }

    return 0;  
}