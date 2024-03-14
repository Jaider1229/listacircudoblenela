#include<iostream>

using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
} *primero, *ultimo;

void insertarnodo();
void mostrardatos();
void sumar();
void encontrarmenormayor(int& menor, int& mayor);

int main(){
	
	insertarnodo();
	insertarnodo();
	insertarnodo();
	insertarnodo();
	insertarnodo();
	
	cout<<"\nLISTA CIRCULAR INGRESADA: ";
	
	mostrardatos();
    cout<<"\n";
	int menor, mayor;
	
	encontrarmenormayor(menor, mayor);
	
	cout<<"La suma de los numero ingresados es:  ";
	sumar();
	cout<<"\n";
	cout<<"El menor de los numeros ingresados es:  "<<menor<<endl;
	cout<<"El mayor de los numeros ingresados es:  "<<mayor<<endl;
	
	return 0;
}

void insertarnodo(){
Nodo *nuevo = new Nodo();
cout<<"\nIngrese el dato del nuevo nodo:  ";
cin >> nuevo->dato;


 if(primero == NULL){
   primero = nuevo;
   primero->siguiente = primero;
   ultimo = primero;
 }
 
 else{
 ultimo->siguiente = nuevo;
 nuevo->siguiente = primero;
 ultimo = nuevo;
 }
 cout<<"\nNODO INGRESADO "<<endl;
}

void mostrardatos(){
Nodo *actual = new Nodo();
actual = primero;

if(primero != NULL){
do{
	cout<<actual->dato;
	actual = actual->siguiente;
}while(actual!=primero);
}

}

void sumar(){
	int suma=0;
	Nodo *actual = primero;
	
	if(primero != NULL){
		do{
			suma += actual->dato;
			actual = actual->siguiente;
		}while(actual != primero);
	}
	cout<<suma;
}

void encontrarmenormayor(int& menor, int& mayor){
	Nodo *actual = primero;
	menor = mayor = actual->dato;
	if(primero != NULL){
		do{
			if(actual->dato < menor){
				menor = actual->dato;
			}
			if(actual->dato > mayor){
				mayor = actual->dato;
			}
			actual = actual->siguiente;
			
		}while(actual != primero);
	}
}
