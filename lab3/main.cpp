#include<iostream>
#include<stdlib.h>
#include<fstream>
#include <cmath>


using namespace std;

string lectura();
string binario(string );
void archivobinario(string );
string metodo(int n, string);
string codificado(string bincod);


//Primer metodo.....

int main(){

  string texto=lectura();
  string strbinario=binario(texto);


  int n;
  cout<<"ingrese la semilla de codificacion"<<endl;
  cin>>n;

 string bincod= metodo(n, strbinario);

 string cod=codificado(bincod);


archivobinario(cod);


 return 0;
}


string codificado(string bincod){               //convertir binario a caracteres

        string codificado;
        int aux;

        float i=0;

        for (;i<bincod.size(); ) {
            for (int j=0,cont=0;j<8 ;j++,i++,cont++ ) {

                if (bincod[i]=='1'){
                    if(cont==0) aux=aux+ pow(2, 7);
                    if(cont==1) aux=aux+ pow(2, 6);
                    if(cont==2) aux=aux+ pow(2, 5);
                    if(cont==3) aux=aux+ pow(2, 4);
                    if(cont==4) aux=aux+ pow(2, 3);
                    if(cont==5) aux=aux+ pow(2, 2);
                    if(cont==6) aux=aux+ pow(2, 1);
                    if(cont==7) aux=aux+ pow(2, 0);



                }

            }
            char ascii=char(aux);
            codificado=codificado + ascii;
            aux=0;

        }




return codificado;


}











string lectura(){                 //leer un txt y guardarlo en un string
    string texto0="",texto="";
    ifstream archivo;

 archivo.open("probando.txt",ios::in);

 if(archivo.fail()){
  cout<<"\nNo se pudo abrir el archivo.";
  exit(1);
 }
 cout<<"\n";

 while(archivo.good()){
getline(archivo,texto0);
texto.append(texto0);
texto.append("\n");

 }
 texto.pop_back();


 archivo.close();
 return texto;
}



string binario(string texto){           //lee el texto y devuelve un string con el binario
    string binario;
    for(unsigned long long int i=0;i<texto.length();i++){
        for(int j=0;j<8;j++)binario.push_back(char((((texto[i]<<j)&(0x80))/128)+48));
    }


return binario;
}


void archivobinario(string bincod){         //reemplaza el texto original y lo combierte a un archivo de binarios

    ofstream archivobinario;

    archivobinario.open("binario.dat",ios::out|ios::binary);

    if(archivobinario.fail()){
     cout<<"No se pudo abrir el archivo."<<endl;
     exit(1);
    }

    archivobinario<<bincod;


    archivobinario.close();

}

string metodo(int n, string bin){                 //codifica el texto
    string bincod;

    for (int i=0;i<n ;i++ ) {
        if (bin.size()==bincod.size()) break;

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



            if (bin.size()==bincod.size()) break;
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
            if (bin.size()==bincod.size()) break;


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

            if (bin.size()==bincod.size()) break;

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

    return bincod;

}

