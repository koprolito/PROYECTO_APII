#include <iostream>  
#include <windows.h>  
#include <stdlib.h> 
#include <time.h>
#include <cstdlib>
#include <string.h>
#include <conio.h>

using namespace std;

struct vehiculos {
    string nomEsp;
    string nomEng;
    string nomConductores;
    int tipoCaucho;
    int velocidad;
    int resistencia;
    struct vehiculos *anterior;
    struct vehiculos *prox;
};

struct infoVehiculos {
    struct vehiculos *primerCarro;
    struct vehiculos *ultimoCarro;    
    struct vehiculos *carroSelec; 
    int cantCarros=0;
};

typedef struct vehiculos *Tlista;
typedef struct infoVehiculos *NodoCabeza;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void ocultarCursor(){
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void pintarTexto(int codColor){
    HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, codColor);
}

void limitesPantalla(){
    gotoxy(4,2);cout<<"___________________________________________________________________________________________________";
    for (int i=0;i<20;i++){
   gotoxy(3,3+i);cout<<"|";  
    gotoxy(103,3+i);cout<<"|";   
    }
    gotoxy(3,23);cout<<"|___________________________________________________________________________________________________|";
    
}

void pantallaInicio(){
        limitesPantalla();
        gotoxy(15,4);cout<<"       ___         __        __    __________    _________      ________"<<endl;
        gotoxy(15,5);cout<<"      /   \\       |  |      |  |  |___    ___|  /         \\    |  ______|"<<endl;
        gotoxy(15,6);cout<<"     /     \\      |  |      |  |      |  |     |     _     |   |  |______        "<<endl;
        gotoxy(15,7);cout<<"    /  /_\\  \\     |  |      |  |      |  |     |    | |    |   |         |     "<<endl;
        gotoxy(15,8);cout<<"   /  _____  \\    |  |      |  |      |  |     |    |_|    |   |_____    |    "<<endl;
        gotoxy(15,9);cout<<"  /  /     \\  \\   |   \\____/   |      |  |     |           |    _____|   |   "<<endl;
        gotoxy(15,10);cout<<" /__/       \\__\\   \\__________/       |__|      \\_________/    |_________|   "<<endl;
        gotoxy(15,11);cout<<"      ___          _________      ________     _________     ________           "<<endl;
        gotoxy(15,12);cout<<"     |   |        /         \\    /  ______|   /         \\   |  ______| "<<endl;
        gotoxy(15,13);cout<<"     |   |       |     _     |  |  |         |     _     |  |  |______          "<<endl;
        gotoxy(15,14);cout<<"     |   |       |    | |    |  |  |         |    | |    |  |         |      "<<endl;
        gotoxy(15,15);cout<<"     |   |       |    |_|    |  |  |         |    |_|    |  |_____    |        "<<endl;
        gotoxy(15,16);cout<<"     |   |____   |           |  |  |______   |           |   _____|   |          "<<endl;
        gotoxy(15,17);cout<<"     |________|   \\_________/    \\________|   \\_________/   |_________|          "<<endl<<endl<<endl;
}

NodoCabeza crearNodoCabeza (){
    NodoCabeza nodoCab= new infoVehiculos();
    nodoCab->primerCarro=NULL;
    nodoCab->ultimoCarro=NULL;
    return nodoCab;
}

Tlista crearVehiculo (string nomEsp,string nomEng,string nomConductores,int tipoCaucho,int velocidad,int resistencia){
    Tlista nuevoVehiculo = new vehiculos ();
    nuevoVehiculo->nomEsp=nomEsp;
    nuevoVehiculo->nomEng=nomEng;
    nuevoVehiculo->nomConductores=nomConductores;
    nuevoVehiculo->tipoCaucho=tipoCaucho;
    nuevoVehiculo->velocidad=velocidad;
    nuevoVehiculo->resistencia=resistencia;
    nuevoVehiculo->anterior=NULL;
    nuevoVehiculo->prox=NULL;
    return nuevoVehiculo;
}

void agregarVehiculo (Tlista &lCarros,NodoCabeza &infoCarros,string nomEsp,string nomEng,string nomConductores,int tipoCaucho,int velocidad,int resistencia){
    Tlista carroNuevo = new vehiculos();
    carroNuevo = crearVehiculo (nomEsp,nomEng,nomConductores,tipoCaucho,velocidad,resistencia);
    if(lCarros==NULL){
        lCarros=carroNuevo;
        cout<<"primer carro creado";
        infoCarros->primerCarro=lCarros;
        infoCarros->ultimoCarro=lCarros;
    }else{
        carroNuevo->anterior=infoCarros->ultimoCarro;  
        infoCarros->ultimoCarro->prox=carroNuevo;
        infoCarros->ultimoCarro=carroNuevo;
    }
    infoCarros->cantCarros=infoCarros->cantCarros++;
}

void mostrarInfoVehiculos(Tlista &lCarros){
    system("cls");
    if (lCarros){
        Tlista auxMostrar = lCarros;
        int contCarros=1;
        while (auxMostrar!=NULL){
            cout<<"\nCarro ["<<contCarros<<"]:\n";
            cout<<"  Nombre en espa"<<(char)164<<"ol: "<<auxMostrar->nomEsp<<endl;
            cout<<"  Nombre en ingles: "<<auxMostrar->nomEng<<endl;
            cout<<"  Nombres de los conductores: "<<auxMostrar->nomConductores<<endl;
            cout<<"  Tipo de caucho: "<<auxMostrar->tipoCaucho<<endl;
            cout<<"  Velocidad del carro: "<<auxMostrar->velocidad<<endl;
            cout<<"  Resistencia del carro: "<<auxMostrar->resistencia<<endl<<endl;
            auxMostrar=auxMostrar->prox;
            contCarros++;
        }

    }else{
        cout<<"No se ha registrado ningun carro por los momentos."<<endl;
    }
    
}

int elegirCarro (Tlista &lCarros){
    Tlista auxlCarros=lCarros;
    int numCarro=1,carro=0;
    while ((carro<1)||(carro>numCarro)){
        system("cls");
        cout<<"CARROS DISPONIBLES:"<<endl;
        while (auxlCarros!=NULL){
            cout<<numCarro<<") "<<auxlCarros->nomEsp<<"."<<endl;
            auxlCarros=auxlCarros->prox;
            numCarro++;
        }
            cout<<"\n\n    Selecciona un carro:\n-> ";
            cin>>carro; 
            if ((carro<1)||(carro>numCarro)){
                cout<<"Carro no disponible, por favor seleccione uno de los que se muestre en pantalla."<<endl;    
                system("PAUSE");
            }else {
                cout<<"Selecciono el carro #"<<carro<<endl;    
                return carro;    
            }
    }
}

void modificarInfo (int opcion,string &nomEsp, string &nomEng, string &nomConductores, int &tipoCaucho,int &velocidad,int &resistencia){
    switch (opcion){
        case 1:
            cout<<"Ingrese el nuevo nombre en espanol: ";
            getline(cin,nomEsp);
        break;
        case 2:
            cout<<"Ingrese el nuevo nombre en ingles: ";
            getline(cin,nomEng);
        break;
        case 3:
            cout<<"Ingrese el nuevo nombre de los conductores: "; 
            getline(cin,nomConductores);
        break;
        case 4:
            cout<<"Ingrese el nuevo valor del tipo de Cauchos:";
            cin>>tipoCaucho;
        break;
        case 5:
            cout<<"Ingrese el nuevo valor de la velocidad: ";
            cin>>velocidad;
        break;
        case 6:
            cout<<"Ingrese el nuevo valor de la resistencia: "; 
            cin>>resistencia;
        break;
        case 0:
        break;
        default:
            cout<<"Opcion invalida, introduzca un numero del 0-6."<<endl;
        break;

    }
}

void mostrarInfo (string nomEsp, string nomEng, string nomConductores, int tipoCaucho,int velocidad,int resistencia){
   system ("cls");
    cout <<"La informacion del auto es: \n"<<endl;
    cout <<"Nombre en espa"<<(char)164<<"ol: "<<nomEsp<<endl;
    cout <<"Nombre en ingles: "<<nomEng<<endl;
    cout <<"Nombre de los conductores: "<<nomConductores<<endl;
    cout <<"Velocidad: "<<velocidad<<endl;
    cout <<"Tipo de cauchos: "<<tipoCaucho<<endl;
    cout <<"Resistencia: "<<resistencia<<endl;
 }

void seleccionarCarro (Tlista &carroSelec, int carro){
    if (carroSelec!=NULL){
        for (int i=0;i==carro;i++){
            carroSelec=carroSelec->prox;            
        }
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

void menuModificar (Tlista &lCarros){
    Tlista carroSelec=lCarros;
    int carro,opcion=-1,tipoCaucho, velocidad,resistencia;
    string nomEsp, nomEng, nomConductores;
    if (lCarros){
    carro= elegirCarro (lCarros);
    seleccionarCarro (carroSelec, carro);
    while ((opcion<0)||(opcion>6)){
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
    modificarInfo (opcion,nomEsp,nomEng,nomConductores,tipoCaucho,velocidad,resistencia);      
    modificarCarro (carroSelec,opcion,nomEsp,nomEng,nomConductores,tipoCaucho,velocidad,resistencia);
    }
}

void menuAgregarCarro (Tlista &listaDeCarros, NodoCabeza &infoCarros,string nomEsp, string nomEng, string nomConductores, int tipoCaucho,int velocidad,int resistencia){
    fflush(stdin);
    int opcion=-1;
    cout<<"INGRESE LA INFORMACION DEL CARRO QUE DESEA AGREGAR"<<endl;
    cout<<"Nombre en espa"<<(char)164<<"ol: "; 
    getline(cin,nomEsp);
    cout<<"Nombre en ingles: "; 
    getline(cin,nomEng);
    cout<<"Nombre de los conductores: "; 
    getline(cin,nomConductores);
    cout<<"Indique el tipo de caucho: "; 
    cin>>(tipoCaucho);
    cout<<"Indique la velocidad: ";
    cin>>(velocidad);
    cout<<"Indique la resistencia: ";
    cin>>(resistencia);
    while ((opcion<0)||(opcion>1)){
        system("cls");
        mostrarInfo (nomEsp,nomEng,nomConductores,tipoCaucho,velocidad,resistencia);
        cout <<"\t\tSi la informacion que se establece es correcta presione 0, sino, presione 1"<<endl<<endl;
        fflush(stdin);
        cin>>opcion;
        if((opcion<0) || (opcion>1)){
            cout<<"Opcion invalida, seleccione una opcion entre 0 - 1.\n";
            system("PAUSE");   
        }
    }
    switch (opcion){
        case 0:               
        break;
        case 1:
            opcion=-1;
            fflush(stdin);
            while (opcion){
                system("cls");
                cout<<"SELECCIONE LO QUE DESEA MODIFICAR."<<endl;
                cout<<"1) Nombre en espa"<<(char)164<<"ol."<<endl;
                cout<<"2) Nombre en ingles."<<endl;
                cout<<"3) Nombre de los conductores."<<endl;
                cout<<"4) Tipo de cauchos."<<endl;
                cout<<"5) Tipo de velocidad."<<endl;
                cout<<"6) Tipo de resistencia."<<endl;
                cout<<"0) Dejar de modificar."<<endl;
                cin>>opcion;
                fflush(stdin);
                modificarInfo (opcion,nomEsp,nomEng,nomConductores,tipoCaucho,velocidad,resistencia);
            }
            cout<<"Informacion modificada correctamente..."<<endl;
        break;
        default:
            cout<<"Opcion invalida, seleccione un numero del 1 al 2"<<endl; 
        break;
    }  
    agregarVehiculo (listaDeCarros,infoCarros,nomEsp,nomEng,nomConductores,tipoCaucho,velocidad,resistencia);
    mostrarInfo (nomEsp,nomEng,nomConductores,tipoCaucho,velocidad,resistencia);
    cout<<"Carro registrado correctamente...\n";
    system("PAUSE"); 
}

void menuAutos(Tlista &listaDeCarros, NodoCabeza &infoCarros){
    system("cls");
    string nomEsp,nomEng,nomConductores;       
    int tipoCaucho,velocidad,resistencia;       
    int opcionMenu=-1;        
    while (opcionMenu != 0){
            system("cls");
            cout<<"INTRODUZCA UNA OPCION:\n";
            cout<<"1) Agregar carro a la carrera.\n";
            cout<<"2) Modificar datos de un carro.\n";
            cout<<"3) Mostrar carros disponibles.\n";
            cout<<"0) Salir.\n";
            cin>>opcionMenu;
            system("cls");
            switch (opcionMenu){
                case 0:
        
                break;
                case 1:
                    menuAgregarCarro (listaDeCarros,infoCarros,nomEsp,nomEng,nomConductores,tipoCaucho,velocidad,resistencia);   
                break;
                case 2:
                    menuModificar (listaDeCarros);
                break;
                case 3:
                    mostrarInfoVehiculos(listaDeCarros);
                    system("PAUSE");
                break;
                default:

                break;
            }    
        }
    system("PAUSE");
}

void menuInicio (Tlista listaDeCarros, NodoCabeza infoCarros){
    int opcion = 1;
    char tecla;
    while (tecla != 13) 
    {
        system("cls");
        pantallaInicio();
        if (opcion == 1){
            pintarTexto(64);
        } else{
            pintarTexto(128);
        }
        gotoxy(33,20); cout << "             " << endl;
        gotoxy(33,21); cout << "    JUGAR    " << endl;
        gotoxy(33,22); cout << "             " << endl;
        if (opcion == 0){
            pintarTexto(64);
        }else{
            pintarTexto(128);
        }
        gotoxy(58,20); cout << "             " << endl;
        gotoxy(58,21); cout << "    SALIR    " << endl;
        gotoxy(58,22); cout << "             " << endl;
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
    switch (opcion){
        case 0:
        break;
        case 1:
        menuAutos(listaDeCarros,infoCarros);
        break;
    }
}

int main (){
        Tlista listaDeCarros=NULL;
        NodoCabeza infoCarros=crearNodoCabeza();
        ocultarCursor();
        menuInicio(listaDeCarros,infoCarros);
    system("cls");
    return 0;
}