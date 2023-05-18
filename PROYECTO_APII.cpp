 #include <iostream>  
 #include <windows.h>  
 #include <stdlib.h> 
 #include <string>
 #include <time.h>
 using namespace std;

struct nodo{
int car;
int i=0;
int wini=0;
int r;
int rpos, rpos1, rpos12;
string vel="";
int cvel;
int pos;
struct nodo* prox;
};

typedef struct nodo* TLista;


TLista crearNodo(int Tcar, string Tvel, int Tcvel, int Ttpos){
TLista q;
q= new(struct nodo);
q->car=Tcar;
q->vel=Tvel;
q->cvel=Tcvel;
q->pos=Ttpos;
return q;
}

void insertarFinal(TLista &lista,int Tcar1, string Tvel1, int Tcvel1, int Ttpos1){
  TLista q= crearNodo(Tcar1, Tvel1,Tcvel1, Ttpos1);
  if (lista==NULL){
    lista=q;
  }
  else{
  /*TLista aux= lista;
    while (aux->prox != NULL){
        aux= aux->prox;
    }
    aux->prox=q; */
    q->prox=lista;
    lista=q;
  }
}



 void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }  


void moverCarro(TLista &lista1){
     lista1->i=lista1->i+1;
      if (lista1->i<80){ 
      gotoxy(lista1->i,lista1->pos);  
      cout<<lista1->vel<<"*";
      }
}

void limpiar(TLista &lista1){
    if (lista1->i<=80){ 
      gotoxy(lista1->i,lista1->pos);  
      cout<<lista1->vel<<" ";
      }
}


void ganador(TLista lista1, int *twin){
    if ((lista1->i>=80)){
          if (lista1->wini==0){
          gotoxy(80,lista1->pos);
          *twin=*twin+1;
          cout<<"| #"<<*twin<<" lugar";
          lista1->wini=1;     
      }
    }

}

void obstaculos(TLista &lista1){
    lista1->r=rand()%2;
    if (lista1->r==1){
        lista1->rpos=(rand()%77)+2;
        gotoxy(lista1->rpos,lista1->pos);
        cout<<"#";
        lista1->rpos1=lista1->rpos-lista1->cvel;
        if (lista1->rpos1<0){lista1->rpos1=0;} 
        lista1->rpos12=lista1->rpos+lista1->cvel;     
    }
}



void Carre(TLista &lista, int tcant, int tposUlt){
    int win=0;


     //obstaculos
    TLista n1=lista;
    for (int v=1; v<=tcant; v++){
        obstaculos(n1);
        n1=n1->prox;
    }


    tposUlt+=1;
    int ult=tposUlt;
	int m=0,s=0;


 //meta
n1=lista;
for (int v=1; v<=tcant;v++){
    gotoxy(80,n1->pos); cout<<"|"; 
    n1=n1->prox;
}

n1=lista;
    do{
        for (int v=1;v<=tcant;v++){
            moverCarro(n1);
            n1=n1->prox;
        }
        n1=lista;


       //temp
            
    for (int v=1;v<=tcant;v++){
        ult+=2;
            if (n1->i<=80){
                gotoxy(2,ult);
                cout<<"Carrito "<<v<<": "<<endl;
		        cout << m << ":" << s << endl;
            }

    }
            ult=tposUlt;


			

s++;
if (s==60){s=0;m=m+1;}

      Sleep(500); //intentar sleep en 600


      //limpiar el * de la pantalla
    for (int v=1; v<=tcant;v++){
        limpiar(n1); 
        n1=n1->prox;
        //puede q sea eso y si n1->prox = null, hacer break
    }
    n1=lista;

    

      //obstaculo
    for (int v=1; v<=tcant;v++){
    if (n1->r==1){
        if ((n1->i<n1->rpos1)||(n1->i>n1->rpos12)){
        n1->i=n1->i+n1->cvel;}
    }
    else{n1->i=n1->i+n1->cvel;}
        n1=n1->prox;
    }
    n1=lista;
    

      //limpiar cronometro
    for (int v=1; v<=tcant;v++){
        ult+=2;
        if (n1->i<80){gotoxy(2,ult); cout<<"          ";}
        n1=n1->prox;
    }
    n1=lista;
    ult=tposUlt;


      //verificar ganador
    for (int v=1; v<=tcant;v++){
        ganador(n1,&win);
        n1=n1->prox;
    }
    n1=lista;
    




      //cuando todos terminen, terminar el ciclo          
        }while(win<tcant);

}


int main(){  

    srand(time(0));
    int Bcvel,Bpos,res2;
    string Bvel, res;
    int cant, h, g, Bcar;
    int posUlt;

    do{
        system("cls");
        cout<<"Indique la cantidad de carritos. Minimo 2 y maximo 12"<<endl;
        cin>>cant;
        h=2;
        TLista p=NULL;
        for (int b=1; b<=cant; b++){
            g=0;
            cout<<"Indique velocidad del carrito "<<b<<": ";
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

            insertarFinal(p,Bcar, Bvel,Bcvel, Bpos);
            
        }
        TLista n=p;
        for (int f=1;f<=cant;f++){
            gotoxy(1,n->pos);cout<<"*"; gotoxy(80,n->pos);cout<<"|";
            n=n->prox;
        }
        n=p;
        system("cls");
        cout<<"pulse cualquier tecla para iniciar la carrera"<<endl;
        system("pause");
        system("cls");
        
        Carre(n,cant,posUlt);
        
        cout<<endl;
        cout<<endl;
        cout<<"iniciar de nuevo? 1 Si y 2 No"<<endl;
        cin>>res2;
}while(res2==1);

    return 0;  
}