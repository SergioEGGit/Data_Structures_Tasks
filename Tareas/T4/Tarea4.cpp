   #pragma hdrstop
   #pragma argsused
   #ifdef _WIN32
   #else
   #define _tmain main
   #endif
//----------------------------------Librerias-------------------------------
   #include <iostream>
   #include <stdio.h>
   #include <stdlib.h>
   #include <string>
   #include <tchar.h>
   #include <locale>
   #include <cstdlib>
   #include <istream>
   using namespace std;

//-------------------------------Estructura----------------------------------
   
   struct CaracteresLD
   {
      char *Caracter;
      struct CaracteresLD *ante;
      struct CaracteresLD *sgte;
    };

    typedef struct CaracteresLD *ListaLD;

//--------------------------------Métodos------------------------------------       
    
   void InsertarLDInicio(ListaLD &Cabeza, ListaLD &Cola, char *Caracter)
   {
      ListaLD aux = new(struct CaracteresLD);

      aux -> Caracter = C;
      if(Cabeza == NULL)
      {
         Cabeza = aux;
         Cola = aux;
      }
      else
      {
         aux -> sig = Cabeza;
         Cabeza -> ante = aux;
         Cabeza = aux;
      }
   }
    
   void EliminarUltimo(ListaLD &Cabeza, ListaLD& Cola)
   {
      ListaLD aux = new(struct CaracteresLD);

      if(Cabeza -> sgte == NULL)
      {
         aux = Cabeza;
         Cabeza = NULL;
      }
      else
      {
         aux = Cabeza -> sgte;
         aux -> ante = NULL;
         Cabeza -> sgte = NULL;
         Cabeza = aux;
        }
    }
    
    
    int Menu()
    {
        cout<<"1. Insertar \n";
        cout<<"2. Eliminar \n";
        cout<<"3. Buscar \n";
        cout<<"4. Ver Lista \n";
        cout<<"5. Salir \n";

        cout<<"Ingrese La Opción Que Desea: ";
    }

    void Mostrar(ListaLD &Cabeza)
    {
        ListaLD aux = Cabeza;
        while(aux != NULL)
        {
           cout<< "Caratcter: "<< aux -> Caracter <<endl;
           aux = aux -> sgte;
        }            
    }
    
    void Buscar(ListaLD &Cabeza, ListaLD &Cola, string Palabra)
    {
    
    }
    
    int _tmain() 
    {
       int Opcion=0;
       string Palabra;
       ListaLD Cabeza = NULL;
       ListaLD Cola = NULL;
       do
       {
          Menu(); cin<< Opcion;
          switch(Opcion)
          {
             case 1:
                char *C;
                cout << "Ingrese Caracter: "; cin>>c;                
                InsertarLDInicio(Cabeza, Cola, C);
                system("pause");
                break;
            case 2:
                EliminarUltimoIngresado(Cabeza, Cola);
                break;
            case 3:
                cout << "Ingrese Palabra A Buscar"; cin>>Palabra;
                Buscar(Cabeza, Cola, Palabra);
                break;
            case 4:
                cout << "Lista De Caracteres \n";
                Mostrar(Cabeza);
                break;
            default:
          }
       }
       while(Opcion!=5);
       return 0;
    }