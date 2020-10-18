#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;

string lectura();
void binario(string texto);




int main(){

  string texto=lectura();
  binario(texto);

 return 0;
}





string lectura(){                 //leer un txt y guardarlo en un string
    string texto;
    ifstream archivo;

 archivo.open("probando.txt",ios::in);

 if(archivo.fail()){
  cout<<"\nNo se pudo abrir el archivo.";
  exit(1);
 }
 cout<<"\n";

 while(!archivo.eof()){
  getline(archivo,texto);           //deja el texto guardado en un string

 }

 archivo.close();
 return texto;
}



void binario(string texto){
    string binario="";
    for (float i=0;i<texto.size();i++ ) {
        int ascii= int(texto[i]);
        for (int j=0;j<8 ;j++ ) {
            if (ascii%2==0) binario= '0' + binario;

            if(ascii%2==1) binario= '1' + binario;

            ascii/=2;
        }


    }
    cout<<binario;

}
