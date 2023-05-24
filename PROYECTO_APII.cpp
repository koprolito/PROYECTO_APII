#include <iostream>  
#include <windows.h>  
#include <stdlib.h> 
#include <string>
#include <time.h>
#include <cstdlib>
#include <fstream>
#include "carros.h"
#include "menu.h"
#include <stdlib.h>
using namespace std;

string recibirDatosCarros(){
    string texto, linea;
    ifstream archivo("carritos.txt");   
    while(getline(archivo,linea)){
        texto += linea+"\n";
    }
    archivo.close();

    return texto;

}

TLista leerDatosDelArchivo(TLista p){
    string texto, linea, lineaAux, sVelocidad;
    int nCarros, nVelocidad, nPos;
    int cont;

    ifstream archivo("carritos.txt");

    while(getline(archivo, linea)){
        texto = linea;
        cont = 0;
        for(int i = 0; i < texto.length(); i++){
            if(i == 0){
                while(texto[i] != ' ')              //Verifica el numero del carro
                    i++;
                lineaAux = texto.substr(0, i);
                nCarros = stoi(lineaAux);
            }
            else if(texto[i] == 'v'){                //Determina la cantidad de espacios a recorrer por el carro y su velocidad
                while(texto[i] != ':')
                    i++;
                int j = i+1;
                while(texto[i] != '|'){
                    i++;
                    cont++;
                }
                lineaAux = texto.substr(j, cont-1);
                sVelocidad = lineaAux;
                cout << sVelocidad << endl;

                j = i+1;
                while(texto[i] != ' ')
                    i++;
                lineaAux = texto.substr(j, i);
                nVelocidad = stoi(lineaAux);
            }
            else{                                   //Determina la posicion inicial del carro
                int j = i;
                while(texto[i] != '\n')
                    i++;
                lineaAux = texto.substr(j, i);
                nPos = stoi(lineaAux);
            }
        }

        p = insertarFinal(p, nCarros, sVelocidad, nVelocidad, nPos);
    }

    archivo.close();
    return p;
}

void jugar(){

    string datosArchivo = recibirDatosCarros(), Bvel;
    srand(time(0));
    int Bcvel,Bpos,res2, cant, h, g, Bcar;
    int posUlt, nCarros;
    char resp;
    TLista p = NULL;

    do{
        ////system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\n";
        if(datosArchivo != ""){
            hacerLineasHorizontales(80,'-');
            cout << "\nExisten datos predefinidos en el archivo, estos datos son: " << endl;
            cout << datosArchivo;
            cout << "\nDesea usar estos datos (s) o definir\nmanualmente los carros? (n)";
            cin >> resp;
            
            if(resp == 'S' || resp == 's'){
                p = leerDatosDelArchivo(p);
                TLista aux = p;
                cant = 0;
                while(aux->prox != NULL){
                    aux = aux->prox;
                    cant++;
                }
                cant++;

                posUlt = aux->pos   ;
            }
            else{
                p = NULL;

                ////system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\n";
                hacerLineasHorizontales(100,'-');
                cout << "\n\nIndique la cantidad de carritos\nMinimo 2 y maximo 12 carritos: ";
                cin>>cant;
                h=2;
                for (int b=1; b<=cant; b++){
                    g=0;
                    //system("cls");
                    hacerLineasHorizontales(100,'-');
                    cout << endl;
                    if(b>1){
                        cout << "Velocidad del carro " + to_string(b) + " (1-10)";
                        cout << "Para regresar al carro anterior escriba 11: ";

                    }else{
                        cout << "Velocidad del carro " + to_string(b) + " (1-10): ";
                    } 

                    cin>>(Bcvel);
                    Bcar=b;

                    if((Bcvel==11)&&(b>1)){
                        //system("cls");
                        hacerLineasHorizontales(100,'-');
                        cout << endl;
                        if(b == 2){
                            TLista aux = p;
                            cout << "Cual sera la velocidad a modificar\n "; 
                            cout << "para el carro anterior?:";

                            cin >> Bcvel;
                            aux->cvel = Bcvel;
                            b--;

                        }else{
                            TLista aux = p;
                            cout << "A cual de los carros desea modificar la velocidad?\n"; 
                            cout <<  "Hasta ahora solo hay "+ to_string(b) +" carros\n\n";
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
            }
        }
        
        TLista n=p;
        //system("cls");


        cout << "\n\n\n\n\n\n\n\n\n\n\n";
        hacerLineasHorizontales(80,'-');
        cout << "\nEl proceso de lectura de los datos de los carros termino\n";
        cout << "Pulse cualquier tecla para iniciar la carrera\n\n";
        hacerLineasHorizontales(80,'-');
        cout << "\n\n";
        cin >> resp;
        cout << "\n\n\n\n\n\n\n\n\n\n\n";

        //system("pause");
        //system("cls");


        for (int f=1;f<=cant;f++){
            gotoxy(1,n->pos); 
            cout<<"*"; gotoxy(80,n->pos); 
            cout<<"|";
            n=n->prox;
        }
        n=p;

        cout << "\n" << endl;;

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
        case 2:
            
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