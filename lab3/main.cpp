#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;

string lectura();
string binario(string );
void archivobinario(string );
void metodo(int n, string);


//Primer metodo.....

int main(){

  string texto=lectura();
  string strbinario=binario(texto);
  archivobinario(strbinario);

  int n;
  cout<<"ingrese la semilla de codificacion"<<endl;
  cin>>n;

  string bin=lectura();
  metodo(n, bin);



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



string binario(string texto){           //lee el texto y devuelve un string con el binario
    string binario="";
    string binario1="";

    for (float i=0;i<texto.size();i++ ) {
        int ascii= int(texto[i]);
        for (int j=0;j<8 ;j++ ) {
            if (ascii%2==0) binario= '0' + binario;

            if(ascii%2==1) binario= '1' + binario;

            ascii/=2;
        }
        binario1=  binario1+ binario;
        binario="";

    }

return binario1;
}


void archivobinario(string strbinario){         //reemplaza el texto original y lo combierte a numeros binarios

    ofstream archivobinario;

    archivobinario.open("probando.txt",ios::out);

    if(archivobinario.fail()){
     cout<<"No se pudo abrir el archivo."<<endl;
     exit(1);
    }

    archivobinario<<strbinario;


    archivobinario.close();

}

void metodo(int n, string bin){                 //codifica el texto y crea uno nuevo

    ofstream archivocod;
    string bincod="";

    archivocod.open("probandocod.txt",ios::out);

    if(archivocod.fail()){
     cout<<"No se pudo abrir el archivo."<<endl;
     exit(1);
    }

    for (int i=0;i<n ;i++ ) {
        if(bin[i]==49) bincod=bincod + '0';
        else {
            bincod=bincod + '1';
        }
    }

    float j=0;
    int cont0=0,cont1=0;

    while (j+n<bin.size()) {
        int con=0;


    for (int  k=0;k<n ;k++,j++ ) {
        if(bin[j]==48) cont0+=1;
        if(bin[j]==49) cont1+=1;

    }




    if(cont0>cont1){
        for (int num=0;num<n ;j++,num++ ) {


            if (con==1) {
                if(bin[j]==49) bincod=bincod + '0';
                else {
                    bincod=bincod + '1';
                }
                con=0;

            }
            else{
            bincod=bincod + bin[j];
            con=con+1;}
        }
        j=j-n;
    }
    if(cont0<cont1){
        for (int num=0;num<n ;j++,num++ ) {

          if (con==2) {
                if(bin[j]==49) bincod=bincod + '0';
                else {
                    bincod=bincod + '1';
                }
                con=0;

            }
          else{
            bincod=bincod + bin[j];
            con=con+1;
          }
        }
        j=j-n;
    }
    if(cont0==cont1){
        for (int num=0;num<n ;j++,num++ ) {
            if(bin[j]==49) bincod=bincod + '0';
            else {
                bincod=bincod + '1';
            }
        }
        j=j-n;
    }
    cont0=0;
    cont1=0;

}
    archivocod<<bincod;


    archivocod.close();

}

