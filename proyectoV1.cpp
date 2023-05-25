#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <string.h>
#include <conio.h>
#include "menus.h"

using namespace std;

struct vehiculos
{
    string nomEsp;
    string nomEng;
    string nomConductores;
    int tipoCaucho;
    int velocidad;
    int resistencia;
    struct vehiculos *anterior;
    struct vehiculos *prox;
};

struct infoVehiculos
{
    struct vehiculos *primerCarro;
    struct vehiculos *ultimoCarro;
};

typedef struct vehiculos *Tlista;
typedef struct infoVehiculos *NodoCabeza;


NodoCabeza crearNodoCabeza()
{
    NodoCabeza nodoCab = new infoVehiculos();
    nodoCab->primerCarro = NULL;
    nodoCab->ultimoCarro = NULL;
    int contCarros=0;
    return nodoCab;
}

Tlista crearVehiculo(string nomEsp, string nomEng, string nomConductores, int tipoCaucho, int velocidad, int resistencia)
{
    Tlista nuevoVehiculo = new vehiculos();
    nuevoVehiculo->nomEsp = nomEsp;
    nuevoVehiculo->nomEng = nomEng;
    nuevoVehiculo->nomConductores = nomConductores;
    nuevoVehiculo->tipoCaucho = tipoCaucho;
    nuevoVehiculo->velocidad = velocidad;
    nuevoVehiculo->resistencia = resistencia;
    nuevoVehiculo->anterior = NULL;
    nuevoVehiculo->prox = NULL;
    return nuevoVehiculo;
}

void agregarVehiculo(Tlista &lCarros, NodoCabeza &infoCarros, string nomEsp, string nomEng, string nomConductores, int tipoCaucho, int velocidad, int resistencia,int &cantCarros)
{
    Tlista carroNuevo = new vehiculos();
    carroNuevo = crearVehiculo(nomEsp, nomEng, nomConductores, tipoCaucho, velocidad, resistencia);
    if (lCarros == NULL)
    {
        lCarros = carroNuevo;
        infoCarros->primerCarro = lCarros;
        infoCarros->ultimoCarro = lCarros;
    }
    else
    {
        carroNuevo->anterior = infoCarros->ultimoCarro;
        infoCarros->ultimoCarro->prox = carroNuevo;
        infoCarros->ultimoCarro = carroNuevo;
    }
    cantCarros++;
}

void mostrarInfoVehiculos(Tlista &lCarros)
{
    system("cls");
    if (lCarros)
    {
        Tlista auxMostrar = lCarros;
        int contCarros = 1;
        while (auxMostrar != NULL)
        {
            cout << "\nCarro [" << contCarros << "]:\n";
            cout << "  Nombre en espa" << (char)164 << "ol: " << auxMostrar->nomEsp << endl;
            cout << "  Nombre en ingles: " << auxMostrar->nomEng << endl;
            cout << "  Nombres de los conductores: " << auxMostrar->nomConductores << endl;
            cout << "  Tipo de caucho: " << auxMostrar->tipoCaucho << endl;
            cout << "  Velocidad del carro: " << auxMostrar->velocidad << endl;
            cout << "  Resistencia del carro: " << auxMostrar->resistencia << endl
                 << endl;
            auxMostrar = auxMostrar->prox;
            contCarros++;
        }
    }
    else
    {
        cout << "No se ha registrado ningun carro por los momentos." << endl;
    }
}

void modificarInfo(int opcion, string &nomEsp, string &nomEng, string &nomConductores, int &tipoCaucho, int &velocidad, int &resistencia)
{
    switch (opcion)
    {
    case 1:
        cout << "Ingrese el nuevo nombre en espanol: ";
        getline(cin, nomEsp);
        break;
    case 2:
        cout << "Ingrese el nuevo nombre en ingles: ";
        getline(cin, nomEng);
        break;
    case 3:
        cout << "Ingrese el nuevo nombre de los conductores: ";
        getline(cin, nomConductores);
        break;
    case 4:
        cout << "Ingrese el nuevo valor del tipo de Cauchos:";
        cin >> tipoCaucho;
        break;
    case 5:
        cout << "Ingrese el nuevo valor de la velocidad: ";
        cin >> velocidad;
        break;
    case 6:
        cout << "Ingrese el nuevo valor de la resistencia: ";
        cin >> resistencia;
        break;
    case 0:
        break;
    default:
        cout << "Opcion invalida, introduzca un numero del 0-6." << endl;
        break;
    }
}

void modificarCarro (Tlista  &carroSelec,int opcion,string nomEsp,string nomEng,string nomConductores,int tipoCaucho,int velocidad,int resistencia){
    switch (opcion){
        case 1:
           carroSelec->nomEsp=nomEsp;
        break;
        case 2:
            carroSelec->nomEng=nomEng;
        break;
        case 3:
            carroSelec->nomConductores=nomConductores;
        break;
        case 4:
            carroSelec->tipoCaucho=tipoCaucho;
        break;
        case 5:
            carroSelec->velocidad=velocidad;
        break;
        case 6:
            carroSelec->resistencia=resistencia;
        break;
        case 0:
        break;
        default:
            cout<<"Opcion invalida, introduzca un numero del 0-6."<<endl;
        break;

    }
}

void nomCarrosDisp(Tlista lCarros){
    if (lCarros){
        Tlista recorrerL = lCarros;
        int contCarros = 0;
        while (recorrerL != NULL)
        {
            contCarros++;
            cout << contCarros << ") " << recorrerL->nomEsp << "." << endl;
            recorrerL = recorrerL->prox;
        }
    }
}

Tlista seleccionarCarro(Tlista carroSelec,int carro){
    if (carroSelec){
        int i=1;
        while (i!=carro){
            carroSelec=carroSelec->prox; i++;
        }
    cout<<"Quiero el carro: "<<carro;
    cout<<"\nEL CARRO QUE SE RETORNA ES: "<<carroSelec->nomEsp<<endl; system("PAUSE");
    return carroSelec;
    }
}

void menuModificar(Tlista &lCarros, NodoCabeza &infoCarros,int &cantCarros){
    string nomEsp,nomEng,nomConductores;
    Tlista carroSelec;
    int carro=0,opcion=-1,tipoCaucho,velocidad,resistencia;
    if (lCarros){ 
        while ((carro<1)||(carro>cantCarros)){
            system("cls");
            cout<<"CARROS DISPONIBLES:"<<endl;
            nomCarrosDisp(lCarros);
            cout<<"Seleccione el vehiculo que desea modificar."<<endl;
            cin>>carro;
            if ((carro<1)||(carro>cantCarros)){
                cout<<"Opcion invalida, debe elegir un carro existente, introduzca un numero entre 1 y "<<cantCarros<<endl;    
                system("PAUSE");            
            }else{
                carroSelec=seleccionarCarro(lCarros,carro);
                while ((opcion!=0)){
                    system("cls");
                    cout<<"SELECCIONE LO QUE DESEA MODIFICAR DEL CARRO ["<<carro<<"]"<<endl;
                    cout<<"1) Nombre en espa"<<(char)164<<"ol."<<endl;
                    cout<<"2) Nombre en ingles."<<endl;
                    cout<<"3) Nombre de los conductores."<<endl;
                    cout<<"4) Tipo de cauchos."<<endl;
                    cout<<"5) Tipo de velocidad."<<endl;
                    cout<<"6) Tipo de resistencia."<<endl;
                    cout<<"0) Dejar de modificar."<<endl;
                    cin>>opcion;
                    fflush(stdin);
                    if ((opcion<0)||(opcion>6)){
                        cout<<"Opcion invalida, por favor seleccione una opcion de 0-6."<<endl;
                        system("PAUSE");
                    }
                }
                cout<<"\nEL CARRO QUE SE VA A MODIFICAR ES: "<<carroSelec->nomEsp<<endl;
                modificarInfo (opcion,nomEsp,nomEng,nomConductores,tipoCaucho,velocidad,resistencia);
                modificarCarro (carroSelec,opcion,nomEsp,nomEng,nomConductores,tipoCaucho,velocidad,resistencia);    
            }
            
        }
        
        
    }
}


int validarInfo (){
    int opcion = 1;
    char tecla;
    while (tecla != 13)
    {
        system("cls");
        if (opcion == 1)
        {
            pintarTexto(64);
        }
        else
        {
            pintarTexto(128);
        }
        gotoxy(33, 21);
        cout << "    DATOS CORRECTOS    " << endl;
        if (opcion == 0)
        {
            pintarTexto(64);
        }
        else
        {
            pintarTexto(128);
        }
        gotoxy(58, 20);
        gotoxy(58, 21);
        cout << "    MODIFICAR CAMPO    " << endl;
        gotoxy(58, 22);
        tecla = getch();
        pintarTexto(15);
        switch (tecla)
        {
        case 75:
            opcion--;
            if (opcion < 0)
                opcion = 1;
            break;

        case 77:
            opcion++;
            if (opcion > 1)
                opcion = 0;
            break;
        }
    }
    return opcion;
    
}
     


void mostrarInfo(string nomEsp, string nomEng, string nomConductores, int tipoCaucho, int velocidad, int resistencia)
{
    system("cls");
    cout << "VERIFIQUE SI LA INFORMACION ES CORRECTA:"<<endl;
    cout << "Nombre en espa" << (char)164 << "ol: " << nomEsp << endl;
    cout << "Nombre en ingles: " << nomEng << endl;
    cout << "Nombre de los conductores: " << nomConductores << endl;
    cout << "Velocidad: " << velocidad << endl;
    cout << "Tipo de cauchos: " << tipoCaucho << endl;
    cout << "Resistencia: " << resistencia << endl;
}

void menuAgregarCarro(Tlista &listaDeCarros, NodoCabeza &infoCarros, string nomEsp, string nomEng, string nomConductores, int tipoCaucho, int velocidad, int resistencia,int &cantCarros)
{
    fflush(stdin);
    int opcion = -1;
    cout << "INGRESE LA INFORMACION DEL CARRO QUE DESEA AGREGAR" << endl;
    cout << "Nombre en espa" << (char)164 << "ol: ";
    getline(cin, nomEsp);
    cout << "Nombre en ingles: ";
    getline(cin, nomEng);
    cout << "Nombre de los conductores: ";
    getline(cin, nomConductores);
    cout << "Indique el tipo de caucho: ";
    cin >> (tipoCaucho);
    cout << "Indique la velocidad: ";
    cin >> (velocidad);
    cout << "Indique la resistencia: ";
    cin >> (resistencia);
    while ((opcion < 0) || (opcion > 1))
    {
        system("cls");
        mostrarInfo(nomEsp, nomEng, nomConductores, tipoCaucho, velocidad, resistencia);
        fflush(stdin);
        cin >> opcion;
        if ((opcion < 0) || (opcion > 1))
        {
            cout << "Opcion invalida, seleccione una opcion entre 0 - 1.\n";
            system("PAUSE");
        }
    }
    switch (opcion)
    {
    case 0:
        break;
    case 1:
        opcion = -1;
        fflush(stdin);
        while (opcion)
        {
            system("cls");
            cout << "SELECCIONE LO QUE DESEA MODIFICAR." << endl;
            cout << "1) Nombre en espa" << (char)164 << "ol." << endl;
            cout << "2) Nombre en ingles." << endl;
            cout << "3) Nombre de los conductores." << endl;
            cout << "4) Tipo de cauchos." << endl;
            cout << "5) Tipo de velocidad." << endl;
            cout << "6) Tipo de resistencia." << endl;
            cout << "0) Dejar de modificar." << endl;
            cin >> opcion;
            fflush(stdin);
            modificarInfo(opcion, nomEsp, nomEng, nomConductores, tipoCaucho, velocidad, resistencia);
        }
        cout << "Informacion modificada correctamente..." << endl;
        break;
    default:
        cout << "Opcion invalida, seleccione un numero del 1 al 2" << endl;
        break;
    }
    agregarVehiculo(listaDeCarros, infoCarros, nomEsp, nomEng, nomConductores, tipoCaucho, velocidad, resistencia,cantCarros);
    mostrarInfo(nomEsp, nomEng, nomConductores, tipoCaucho, velocidad, resistencia);
    cout << "Carro registrado correctamente...\n";
    system("PAUSE");
}

void menuAutos(){
    Tlista listaDeCarros = NULL;
    NodoCabeza infoCarros = crearNodoCabeza();
    int cantCarros=0;
    system("cls");
    string nomEsp, nomEng, nomConductores;
    int tipoCaucho, velocidad, resistencia;
    int opcionMenu = -1;
    while (opcionMenu != 0)
    {
        opcionMenu=selecMenuPrin();
        system("cls");
        switch (opcionMenu)
        {
        case 0:

            break;
        case 1:
            menuAgregarCarro(listaDeCarros, infoCarros, nomEsp, nomEng, nomConductores, tipoCaucho, velocidad, resistencia, cantCarros);
            break;
        case 2:
            menuModificar(listaDeCarros, infoCarros,cantCarros);
            break;
        case 3:
            //ELIMINAR CARRO
            break;
        case 4:
            mostrarInfoVehiculos(listaDeCarros);
            system("PAUSE");
        break;
        }
    }
    system("PAUSE");
}

int main()
{
    ocultarCursor();
    system("cls");
    switch (menuInicio())
    {
    case 0:
        break;
    case 1:
        menuAutos();
        break;
    }
    system("cls");
    return 0;
}