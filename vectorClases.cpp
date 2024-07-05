#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
//Clase.h
class Libro{
	private:
		string titulo;
		string autor;
		int anio;
	public:
		//constructor
		Libro();
		//ingreso - set
		void ingresoNombre(string titulo);
		void ingresoAutor(string autor);
		void ingresoAnio(int anio);
		//obtener - get
		string obtenerNombre();
		string obtenerAutor();
		int obtenerAnio();
};
//Clase.cpp
Libro::Libro(){
	titulo="S/T";
	autor="S/A";
	anio=9999;
};
void Libro::ingresoNombre(string titulo){
	this->titulo=titulo;	
};
void Libro::ingresoAutor(string autor){
	this->autor=autor;
};
void Libro::ingresoAnio(int anio){
	this->anio=anio;
};
string Libro::obtenerNombre(){
	return titulo;	
};
string Libro::obtenerAutor(){
	return autor;
};
int Libro::obtenerAnio(){
	return anio;
};
//funciones.h
void menu();
void ingresoDatos(vector<Libro> &lista);
void listraDatos(vector<Libro> lista);
void ordenarDatos(vector<Libro> &lista);
int main(){
	int op;
	vector<Libro> lista;
	
	do{
		menu();
		cin>>op;
		switch (op){
			case 1:
				ingresoDatos(lista);
				break;
			case 2:
				listraDatos(lista);
				break;
			case 3:
				ordenarDatos(lista);
				break;
			case 4: 
				cout<<"\tFin de programa\n";
				break;
			default:
				break;													
		}
	}while(op!=4);
	return 0;
}
//funciones.cpp
void menu(){
	cout<<"1.- Ingreso de datos\n";
	cout<<"2.- Mostrar datos\n";
	cout<<"3.- Ordenar datos\n";
	cout<<"4.- Salir\n";
	cout<<"Seleccione un item: \n";
};
void ingresoDatos(vector<Libro> &lista){
	string titulo;
	string autor;
	int anio;
	Libro libro;// un solo objeto
	//ingreso datos teclado
	cout<<"Nombre Titulo: ";
	getline(cin>>ws,titulo);
	cout<<"Autor: ";
	getline(cin>>ws,autor);
	cout<<"Año: ";
	cin>>anio;
	//guardar datos en la clase
	libro.ingresoNombre(titulo);
	libro.ingresoAutor(autor);
	libro.ingresoAnio(anio);
	//guardar el objeto
	lista.push_back(libro);
};
void listraDatos(vector<Libro> lista){
	cout<<setw(10)<<"Titulo"<<setw(10)<<"Autor"<<setw(10)<<"Año"<<endl;
	if(lista.size()>0){
		for(auto i:lista){
			cout<<setw(15)<<right<<i.obtenerNombre()<<" "<<setw(15)<<right<<i.obtenerAutor()<<" "<<setw(10)<<right<<i.obtenerAnio()<<endl;
		}
	}else{
		cout<<"\tLista vacia....!!!!!!\n";
	}
};
void ordenarDatos(vector<Libro> &lista){
	
     for (int i = 0; i < lista.size() - 1; i++) { 
         int minimo = i; 
         for (int j = i + 1; j < lista.size(); j++) { 
              if (lista[j].obtenerNombre() < lista[minimo].obtenerNombre()) { 
                  minimo = j; 
              } 
         } 
         if (minimo != i) { 
             swap(lista[i], lista[minimo]); 
          } 
     }
	
};