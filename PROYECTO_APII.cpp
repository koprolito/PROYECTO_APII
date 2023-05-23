#include <iostream>  
#include <windows.h>  
#include <stdlib.h> 
#include <string>
#include <time.h>
#include <cstdlib>
#include "carros.h"
#include "menu.h"
using namespace std;


int main(){  

    int op;
    pantallaInicio();
    while(op!=0){
        op = principal();
    }

    return 0;  
}