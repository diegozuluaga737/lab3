#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;

void lectura();



int main(){
 lectura();

 return 0;
}


void lectura(){
 ifstream archivo;
 string  texto;

 archivo.open("probando.txt",ios::in);

 if(archivo.fail()){
  cout<<"\nNo se pudo abrir el archivo.";
  exit(1);
 }
 cout<<"\n";

 while(!archivo.eof()){
  getline(archivo,texto);           //deja el texto guardado en un string
  cout<<texto<<endl;
 }

 archivo.close();
}
