#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

//---------------------------------Librerias------------------------------------

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

//-----------------------------------TDA----------------------------------------

   //------------------------------Estructura-----------------------------------

	  struct Estudiante
	  {
		 int Id;
		 int Carne;
		 string Nombre;
		 struct Estudiante *sgte;
	  };

	  typedef struct Estudiante *ListaEstudiante;

   //-------------------------------Métodos-------------------------------------

	  void InsertarInicio(ListaEstudiante &lista, int Id, int Carne, string Nombre)
	  {
		 ListaEstudiante q = new(struct Estudiante);
		 q -> Id = Id;
		 q -> Carne = Carne;
		 q -> Nombre = Nombre;
		 q -> sgte = lista;
		 lista  = q;
	  }

	  void InsertarFinal(ListaEstudiante &lista, int Id, int Carne, string Nombre)
	  {
		 ListaEstudiante t, q = new(struct Estudiante);

		 q -> Id = Id;
		 q -> Carne = Carne;
		 q -> Nombre = Nombre;
		 q -> sgte = NULL;

		 if(lista == NULL)
		 {
			lista = q;
		 }
		 else
		 {
			t = lista;
			while(t -> sgte != NULL)
			{
			   t = t -> sgte;
			}

			t -> sgte = q;
		 }
	  }

	  int InsertarAD()
	  {
		 int _op, band;
		 cout<<endl;
		 cout<<"\t 1. Antes De La Posicion           "<<endl;
		 cout<<"\t 2. Despues De La Posicion         "<<endl;
		 cout<<"\n\t Opcion : "; cin>> _op;

		 if(_op == 1)
		 {
			band = -1;
		 }
		 else
		 {
			band = 0;
		 }

		 return band;
	  }

	  void Insertar(ListaEstudiante &lista, int Id, int Carne, string Nombre, int Pos)
	  {
		 ListaEstudiante q, t;
		 int i;
		 q = new(struct Estudiante);
         q -> Id = Id;
		 q -> Carne = Carne;
		 q -> Nombre = Nombre;

		 if(Pos == 1)
		 {
			q -> sgte = lista;
			lista = q;
		 }
		 else
		 {
			int x = InsertarAD();
			t = lista;

			for(i = 1; t != NULL; i++)
			{
			   if(i == Pos + x)
			   {
				  q -> sgte = t -> sgte;
				  t -> sgte = q;
				  return;
			   }
			   t = t -> sgte;
			}
		 }
		 cout<<endl<<" \n";
		 cout<<"   Error...Posicion No Encontrada..!"<<endl;
	  }

	  void BuscarId(ListaEstudiante lista, int Id)
	  {
		 ListaEstudiante q = lista;
		 int i = 1, band = 0;

		 while(q != NULL)
		 {
			if(q -> Id == Id)
			{
			   cout<<endl<<" Resultado Busqueda";
			   cout<<endl<<" \n";
			   cout<<endl<<" Id: "<< q -> Id <<endl;
			   cout<<endl<<" Carne: "<< q -> Carne <<endl;
			   cout<<endl<<" Nombre: "<< q -> Nombre <<endl;
			   band = 1;
			}
			q = q -> sgte;
			i++;
		 }

		 if(band == 0)
		 {
			cout<<"\n\n Id No Encontrado..!"<< endl;
		 }
	  }

	  void BuscarCarne(ListaEstudiante lista, int Carne)
	  {
		 ListaEstudiante q = lista;
		 int i = 1, band = 0;

		 while(q != NULL)
		 {
			if(q -> Carne == Carne)
			{
			   cout<<endl<<" Resultado Busqueda";
			   cout<<endl<<" \n";
			   cout<<endl<<" Id: "<< q -> Id <<endl;
			   cout<<endl<<" Carne: "<< q -> Carne <<endl;
			   cout<<endl<<" Nombre: "<< q -> Nombre <<endl;
			   band = 1;
			}
			q = q -> sgte;
			i++;
		 }

		 if(band == 0)
		 {
			cout<<"\n\n Carne No Encontrado..!"<< endl;
		 }
	  }

	  void BuscarNombre(ListaEstudiante lista, string Nombre)
	  {
		 ListaEstudiante q = lista;
		 int i = 1, band = 0;

		 while(q != NULL)
		 {
			if(q -> Nombre == Nombre)
			{
			   cout<<endl<<" Resultado Busqueda";
			   cout<<endl<<" \n";
			   cout<<endl<<" Id: "<< q -> Id <<endl;
			   cout<<endl<<" Carne: "<< q -> Carne <<endl;
			   cout<<endl<<" Nombre: "<< q -> Nombre <<endl;
			   band = 1;
			}
			q = q -> sgte;
			i++;
		 }

		 if(band == 0)
		 {
			cout<<"\n\n Nombre No Encontrado..!"<< endl;
		 }
	  }

	  void Eliminar(ListaEstudiante &lista, int Id)
	  {
		 ListaEstudiante p, ant;
		 p = lista;

		 if(lista != NULL)
		 {
			while(p != NULL)
			{
			   if(p -> Id == Id)
			   {
				  if(p == lista)
				  {
					 lista = lista -> sgte;
				  }
				  else
				  {
					 ant -> sgte = p -> sgte;
				  }

				  delete(p);
                  cout<<endl<<" \n";
				  cout<< "Eliminado Con Exito";
				  return;
			   }
			   else
			   {
				  cout<< "Elemento No Encontrado";
			   }
			   ant = p;
			   p = p -> sgte;
			}
		 }
		 else
		 {
			cout<<endl<<" \n";
			cout<<" Lista Vacia..!";
		 }
	  }

	  void Imprimir(ListaEstudiante lista)
	  {
		 int i = 0;

		 while(lista != NULL)
		 {
			cout << ' ' << i + 1 << ". " << lista -> Carne << ' ' << lista -> Nombre << endl;
			lista = lista -> sgte;
			i++;
		 }
	  }

   //-------------------------------Menú----------------------------------------

	  void Menu()
	  {
		 cout<<"\n\t\tTarea 3\n\n";
		 cout<<" 1. Insertar Al Inicio               "<<endl;
		 cout<<" 2. Insertar Al Final                "<<endl;
		 cout<<" 3. Insertar En Posicion Especifica  "<<endl;
		 cout<<" 4. Buscar Por Id                    "<<endl;
		 cout<<" 5. Buscar Por Carne                 "<<endl;
		 cout<<" 6. Buscar Por Nombre                "<<endl;
		 cout<<" 7. Eliminar                         "<<endl;
		 cout<<" 8. Lista De Estudiantes             "<<endl;
		 cout<<" 9. Salir                            "<<endl;

		 cout<<"\n Ingrese El Numero De La Opcion A Elegir: ";
	  };

   //-------------------------Id Autoincrementable------------------------------

	  int Autoid(ListaEstudiante lista)
	  {
		 int temp;
		 if(lista != NULL)
		  {
			 while(lista != NULL)
			 {
				temp = lista -> Id + 1;
				lista = lista -> sgte;
			 }

		  }
		  else
		  {
			 temp = 1;
		  }
		  return temp;
	  };

//----------------------------------Método Main---------------------------------


	int _tmain(int argc, _TCHAR* argv[])
	{
	   ListaEstudiante lista = NULL;
	   int Opcion;
	   int _Id;
	   int _Carne;
	   string _Nombre;
	   int Posicion = 0;

	   system("color 0b");

	   do
	   {
		  Menu();  cin>> Opcion;

		  switch(Opcion)
		  {
			 case 1:
				_Id = Autoid(lista);
				cout<< "\n Carne: "; cin>> _Carne;
				cout<< "\n Nombre: "; cin>> _Nombre;
				InsertarInicio(lista, _Id, _Carne, _Nombre);
				cout << "\n";
				system("pause");
			 break;

			 case 2:
				_Id = Autoid(lista);
				cout<< "\n Carne: "; cin>> _Carne;
				cout<< "\n Nombre: "; cin>> _Nombre;
				InsertarFinal(lista, _Id, _Carne, _Nombre);
				cout << "\n";
				system("pause");
			 break;

			 case 3:
				_Id = Autoid(lista);
				cout<< "\n Carne: "; cin>> _Carne;
				cout<< "\n Nombre: "; cin>> _Nombre;
				cout<< "\n Posicion: "; cin>> Posicion;
				cout << "\n";
				Insertar(lista, _Id, _Carne, _Nombre, Posicion);
				cout << "\n";
				system("pause");
			 break;

			 case 4:
				cout<<"\n Id: "; cin>> _Id;
				BuscarId(lista, _Id);
				cout << "\n";
				system("pause");
			 break;

			 case 5:
				cout<<"\n Carne: "; cin>> _Carne;
				BuscarCarne(lista, _Carne);
				cout << "\n";
				system("pause");
			 break;

			 case 6:
				cout<<"\n Nombre: "; cin>> _Nombre;
				BuscarNombre(lista, _Nombre);
				cout << "\n";
				system("pause");
			 break;

			 case 7:
				cout<<"\n Id: "; cin>> _Id;
				Eliminar(lista, _Id);
				cout << "\n";
				system("pause");
			 break;

			 case 8:
				cout << "\n\n Lista Estudiantes \n\n";
				Imprimir(lista);
				cout << "\n";
                system("pause");
			 break;
		  }

		  cout<<endl<<endl;
		  system("cls");

	   }
	   while(Opcion != 9);
       cout << "\n";
	   cout << "Aplicacion Finalizada";
	   cout << "\n";
	   system("pause");
	   return 0;
	}
