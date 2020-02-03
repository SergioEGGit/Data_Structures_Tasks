#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
typedef char _TCHAR;
#define _tmain main
#endif

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <locale>
using namespace std;

int idPersona = 0;
int idPersonaR = 0;


//-------------------------TDA Listas Enlazadas Simples-----------------------

  //-----------------------------TDA Moneda-----------------------------------

  //------------------------Estructura Moneda---------------------------------

		struct Moneda
		{
			 int idM;
			 string nombreM;
			 int cantidadM;
			 struct Moneda *sgte;
		};

		typedef struct Moneda *ListaMoneda;

  //----------------------------Métodos Moneda--------------------------------

		void InsertarMoneda(ListaMoneda &lista, int idM, string nombreM, int cantidadM)
		{
			ListaMoneda t, q = new(struct Moneda);

			q -> idM  = idM;
			q -> nombreM = nombreM;
			q -> cantidadM = cantidadM;
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

		void ImprimirLista(ListaMoneda lista)
		{
			while(lista != NULL)
			{
				cout << ' ' << lista -> idM << ". " << lista -> nombreM << ' ' << lista -> cantidadM << endl;
				lista = lista -> sgte;
			}
		}

		int BuscarMoneda(ListaMoneda lista, string nombreM)
		{
		   int i = 1, band = 0, cantidadM = 0;

		   while(lista != NULL)
		   {
			   if(lista -> nombreM == nombreM)
			   {
				  if(lista -> idM == i){
					cantidadM = lista -> cantidadM;
				  }
				  band = 1;
			   }
			   lista = lista -> sgte;
			   i++;
		   }
		   return cantidadM;
		}

		void ModificarMonedero(ListaMoneda &lista, string _nombreM,int CantidadRes)
		{
			  ListaMoneda q;
			  q = lista;
			  while(q != NULL)
			  {
				if(q -> nombreM == _nombreM)
				{
					  q -> cantidadM = CantidadRes;
				}
				q = q -> sgte;
			  }
		}

  //------------------------------TDA Persona---------------------------------

  //---------------------------Estructura Persona-----------------------------

		struct Persona
		 {
			 int idP;
			 string nombreP;
			 string MonedaP[50][3];
			 struct Persona *sgte;
		 };

		typedef struct Persona *ListaPersona;

  //----------------------------Métodos Persona-------------------------------

		void InsertarPersona(ListaPersona &lista, int idP, string nombreP)
	  {
		   ListaPersona t, q = new(struct Persona);

		   q -> idP  = idP;
		   q -> nombreP = nombreP;
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

		void ImprimirListaP(ListaPersona lista)
		{
			while(lista != NULL)
			{
				cout << ' ' << lista -> idP << ". " << lista -> nombreP<<endl;
				for(int i = 0;i<50;i++)
				{
					if(lista -> MonedaP[i][0] != "")
					{
					  cout<<"             "<<lista -> MonedaP[i][0]<<"  " <<lista -> MonedaP[i][1]<< "  "<< lista -> MonedaP[i][2]<<endl;
					}
				}
				lista = lista -> sgte;
			}
		}

		string BuscarPersona(ListaPersona lista, string nombreP)
		{
		   int i = 1, band = 0;
		   string nombrePersona = "";

		   while(lista != NULL)
		   {
			   if(lista -> nombreP == nombreP)
			   {
				  if(lista -> idP == i){
					 idPersona = lista -> idP;
					 nombrePersona = lista -> nombreP;
				  }
				  band = 1;
			   }
			   lista = lista -> sgte;
			   i++;
		   }
		   return nombrePersona;
		}

		string BuscarPersonaR(ListaPersona lista, string nombreP)
		{
		   int i = 1, band = 0;
		   string nombrePersona = "";

		   while(lista != NULL)
		   {
			   if(lista -> nombreP == nombreP)
			   {
				  if(lista -> idP == i){
					 idPersonaR = lista -> idP;
					 nombrePersona = lista -> nombreP;
				  }
				  band = 1;
			   }
			   lista = lista -> sgte;
			   i++;
		   }
		   return nombrePersona;
		}

		string BuscarPersonaCantidad(ListaPersona lista, string nombreP, string _nombreM)
		{
		   int i = 1, band = 0;
		   string cantidadRes = "";

		   while(lista != NULL)
		   {
			   if(lista -> nombreP == nombreP)
			   {
				  if(lista -> idP == i){
					 for(int i = 0;i<49;i++)
					 {
						 if(lista -> MonedaP[i][1] == _nombreM)
						 {
							   cantidadRes = lista -> MonedaP[i][2];
						 }
					 }
				  }
				  band = 1;
			   }
			   lista = lista -> sgte;
			   i++;
		   }
		   return cantidadRes;
		}

		void ModificarPersonaCantidad(ListaPersona &listaP, int idPersona, string _nombreM, int CantidadRes)
		{
			  ListaPersona q;
			  q = listaP;
			  while(q != NULL)
			  {
				if(q -> idP == idPersona)
				{
					  for(int i = 0;i<49;i++)
					  {
						  if(q -> MonedaP[i][1] == _nombreM)
						  {
							 q -> MonedaP[i][2] = to_string(CantidadRes);
                          }
					  }

				}
				q = q -> sgte;
			  }
		}

		void TransferirCliente(ListaPersona &listaP, ListaMoneda &lista, int idPersona, string _nombreM, int _cantidadTransferir, int CantidadTotal)
		{
			  string index = "";
			  int x = 1;
			  int cantidadRes = 0;
			  ListaPersona q;
			  q = listaP;
			  while(q != NULL)
			  {
				if(q -> idP == idPersona)
				{
					for(int i = 0;i<49;i++)
					{
						if(q -> idP == idPersona)
						{
						   if(q -> MonedaP[i][0] != "")
						   {
							  index = q -> MonedaP[i][0];
						   }
						}
					}
					if(index != "")
					{
						x = x + stoi(index);
						q -> MonedaP[x - 1][0] = "2";
						q -> MonedaP[x - 1][1] = _nombreM;
						q -> MonedaP[x - 1][2] = to_string(_cantidadTransferir);
						cantidadRes = CantidadTotal - _cantidadTransferir;
						ModificarMonedero(lista, _nombreM, cantidadRes);
					}
					else
					{
						q -> MonedaP[0][0] = "1";
						q -> MonedaP[0][1] = _nombreM;
						q -> MonedaP[0][2] = to_string(_cantidadTransferir);
                        cantidadRes = CantidadTotal - _cantidadTransferir;
						ModificarMonedero(lista, _nombreM, cantidadRes);
					}
				}

				   q = q -> sgte;
			  }
		}

		void TransferirentreCliente(ListaPersona &listaP, int idPersona, int idPersonaR, string _nombreM, int _cantidadTransferir, string CantidadRemitente)
		{
			  string index = "";
			  int x = 1;
			  int cantidadRes = 0;
			  ListaPersona q;
			  q = listaP;
			  while(q != NULL)
			  {
				if(q -> idP == idPersona)
				{
					for(int i = 0;i<49;i++)
					{
						if(q -> idP == idPersona)
						{
						   if(q -> MonedaP[i][0] != "")
						   {
							  index = q -> MonedaP[i][0];
						   }
						}
					}
					if(index != "")
					{
						x = x + stoi(index);
						q -> MonedaP[x - 1][0] = "2";
						q -> MonedaP[x - 1][1] = _nombreM;
						q -> MonedaP[x - 1][2] = to_string(_cantidadTransferir);
						cout<< stoi(CantidadRemitente);
						cantidadRes = stoi(CantidadRemitente) - _cantidadTransferir;
						ModificarPersonaCantidad(listaP, idPersonaR, _nombreM, cantidadRes);
					}
					else
					{
						q -> MonedaP[0][0] = "1";
						q -> MonedaP[0][1] = _nombreM;
						q -> MonedaP[0][2] = to_string(_cantidadTransferir);
						cantidadRes = stoi(CantidadRemitente) - _cantidadTransferir;
						ModificarPersonaCantidad(listaP, idPersonaR, _nombreM, cantidadRes);
					}
				}

				   q = q -> sgte;
			  }
		}


//------------------------------Aplicación------------------------------------

  //-------------------------------Menú---------------------------------------

		void menu()
		{
			cout<<"\n\t\tTarea 2\n\n";
			cout<<" 1. Crear Moneda                     "<<endl;
			cout<<" 2. Agregar Fondos A Moneda          "<<endl;
			cout<<" 3. Ver Lista De Monedas             "<<endl;
			cout<<" 4. Crear Cliente                    "<<endl;
			cout<<" 5. Ver Lista De Clientes            "<<endl;
			cout<<" 6. Transeferencias A Clientes       "<<endl;
			cout<<" 7. Transeferencias Entre Clientes   "<<endl;
			cout<<" 8. Salir                            "<<endl;

			cout<<"\n Ingrese El Numero De La Opcion A Elegir: ";
		};

   //-------------------------Id Autoincrementable Moneda---------------------

		int autoid(ListaMoneda lista)
		{
		   int temp;
		   if(lista != NULL)
		   {
			  while(lista != NULL)
			  {
				 temp = lista -> idM + 1;
				 lista = lista -> sgte;
			  }

		   }
		   else
		   {
			  temp = 1;
		   }
		   return temp;
	  };

   //-------------------------Id Autoincrementable Persona--------------------

		int autoidP(ListaPersona lista)
		{
		   int temp;
		   if(lista != NULL)
		   {
			  while(lista != NULL)
			  {
				  temp = lista -> idP + 1;
				  lista = lista -> sgte;
			  }

		   }
		   else
		   {
			  temp = 1;
		   }
		   return temp;
	  };

   //---------------------------------To Lower--------------------------------

		string ToLower(string _nombreM)
		{
		   locale loc;
		   string _Nombre = "";
		   for(auto elem : _nombreM)
		   {
			 _Nombre = _Nombre + tolower(elem, loc);
		   }
		   return _Nombre;
		}

//---------------------------------Método Main--------------------------------

	int _tmain(int argc, _TCHAR* argv[])
	{
		   ListaMoneda lista = NULL;
		   ListaPersona listaP = NULL;
		   int opcion;
		   int _idM = 0;
		   int _idP = 0;
		   string _nombreM;
		   string _nombreP;
		   int _cantidadM;
		   int _cantidadTransferir;
		   int _cantidadModificar;
		   string _nombrePRemitente;
		   string _nombrePDestinatario;
		   string _cantidadTotalCliente;


		   int posicion;

		   system("color 0b");

		 do
		 {
			  menu();  cin>> opcion;

		   switch(opcion)
		   {
				case 1:
					 _idM = autoid(lista);
					 cout<<"\n\t\tCrear Moneda\n\n";
					 cout<< "\n Ingrese Nombre: "; cin>> _nombreM;
					 _nombreM = ToLower(_nombreM);
					 if(BuscarMoneda(lista, _nombreM) == 0)
					 {
						cout<< "\n Ingrese Cantidad: "; cin>> _cantidadM;
						cout<< "\n";
						InsertarMoneda(lista, _idM, _nombreM, _cantidadM);
						system("pause");
					 }
					 else
					 {
						cout<< "\n";
						cout<< "La Moneda Ya Existe En El Sistema";
						cout<< "\n";
						cout<< "\n";
						system("pause");
					 }
				break;

				case 2:
					  cout << "\n\n Lista De Monedas\n\n";
					  ImprimirLista(lista);
					  cout<< "\n";
					  cout<< "A Que Moneda Desea Agregar Fondos: "; cin>> _nombreM;
					  cout<< "\n";
					  BuscarMoneda(lista, _nombreM);
					  cout<< "Cuanto Desea Agregar: "; cin>> _cantidadM;
					  _cantidadModificar = BuscarMoneda(lista, _nombreM) + _cantidadM;
					  ModificarMonedero(lista, _nombreM, _cantidadModificar);
					  cout<< "\n";
					  cout<< "\n";
					  cout<< "\n Cantidad Agregada Con Exito";
					  system("pause");
				break;

				case 3:
					  cout << "\n\n Lista De Monedas\n\n";
					  ImprimirLista(lista);
					  cout<< "\n";
					  system("pause");
				break;

				case 4:
					 _idP = autoidP(listaP);
					 cout<<"\n\t\tCrear Cliente\n\n";
					 cout<< "\n Ingrese Nombre: "; cin>> _nombreP;
					 _nombreP = ToLower(_nombreP);
					 if(BuscarPersona(listaP, _nombreP) == "")
					 {
						InsertarPersona(listaP, _idP, _nombreP);
						cout<< "\n";
						system("pause");
					 }
					 else
					 {
						cout<< "\n";
						cout<< "El Cliente Ya Existe En El Sistema";
						cout<< "\n";
						cout<< "\n";
						system("pause");
					 }
				break;

				case 5:
					  cout << "\n\n Lista De Clientes\n\n";
					  ImprimirListaP(listaP);
					  cout<< "\n";
					  system("pause");
				break;

				case 6:
					  cout << "\n\n Lista De Monedas\n\n";
					  ImprimirLista(lista);
					  cout<< "\n";
					  cout<<"\n Que Tipo De Moneda Quiere Transferir: "; cin>> _nombreM;
					  _nombreM = ToLower(_nombreM);
					  system("cls");
					  if(BuscarMoneda(lista, _nombreM) == 0)
					  {
						  cout<< "Este Tipo De Moneda No Existe En El Sistema";
						  cout<< "\n";
						  system("pause");
					  }
					  else
					  {
						  cout<< "La Cantidad Disponible Es De: " <<' ' << BuscarMoneda(lista, _nombreM);
						  cout<< "\n";
						  cout<< "\n";
						  cout<< "Cuanto Desea Transferir: "; cin>> _cantidadTransferir;
						  if(_cantidadTransferir > BuscarMoneda(lista, _nombreM))
						  {
							 cout<< "La Cantidad Indicada Excede La Cantidad Disponible";
							 cout<< "\n";
							 system("pause");
						  }
						  else
						  {
							 cout<< "\n";
							 cout<< "\n";
							 cout << "\n\n Lista De Clientes\n\n";
							 ImprimirListaP(listaP);
							 cout<< "\n";
							 cout<< "\n A Quien Desea Transferir El Dinero: "; cin>> _nombreP;
							 _nombreP = ToLower(_nombreP);
							 BuscarPersona(listaP, _nombreP);
							 TransferirCliente(listaP, lista, idPersona, _nombreM, _cantidadTransferir, BuscarMoneda(lista, _nombreM));
							 cout<< "\n Dinero Transferido Con Exito";
							 cout<< "\n";
							 system("pause");
						  }
					  }
				break;

				case 7:
							 cout << "\n\n Lista De Clientes\n\n";
							 ImprimirListaP(listaP);
							 cout<< "\n";
							 cout<< "\n Cliente Remitente: "; cin>> _nombrePRemitente;
							 cout<< "\n Cliente Destinatario: "; cin>> _nombrePDestinatario;
							 _nombrePRemitente = ToLower(_nombrePRemitente);
							 _nombrePDestinatario = ToLower(_nombrePDestinatario);
							 cout<< "\n";
							 cout<< "\n Que Tipo De Moneda Quiere Transferir: "; cin>> _nombreM;
							 cout<< "\n";
							 if(BuscarPersonaCantidad(listaP, _nombrePRemitente, _nombreM) == "")
							 {
								  cout<< "\n El Cliente Remitente Aun No Cuenta Con Este Tipo De Moneda En Su Cuenta";
								  cout<< "\n";
								  system("pause");
							 }
							 else
							 {

							   cout<< "\n Cuanto Desea Transferir: "; cin>> _cantidadTransferir;
							   cout<< "\n";
							   if(_cantidadTransferir > stoi(BuscarPersonaCantidad(listaP, _nombrePRemitente, _nombreM)))
							   {
								  cout<< "\n La Cantidad Indicada Excede La Cantidad Disponible";
								  cout<< "\n";
								  system("pause");
							   }
							   else
							   {
                                  _cantidadTotalCliente = BuscarPersonaCantidad(listaP, _nombrePRemitente, _nombreM);
								  BuscarPersona(listaP, _nombrePDestinatario);
								  BuscarPersonaR(listaP, _nombrePRemitente);
								  TransferirentreCliente(listaP, idPersona, idPersonaR, _nombreM, _cantidadTransferir, _cantidadTotalCliente);
								  cout<< "\n Dinero Transferido Con Exito";
								  cout<< "\n";
								  system("pause");
							   }
							 }
				break;

			}

			cout<<endl<<endl;
			system("cls");

		 }

			while(opcion != 8);
			cout<< "\n";
			cout<< "\n";
			cout<< "Aplicacion Finalizada";
			cout<< "\n";
			cout<< "\n";
			cout<< "\n";
			system("pause");

		 return 0;
	}