#include <funciones.h>


//Primer metodo.....

int main(){
//-----------------------codificacion------------------------------------//
   string nombre;
   cout<<"ingrese el nombre del archivo a codificar"<<endl;
   cin>>nombre;

  string texto=lectura(nombre);
  string strbinario=binario(texto);


  int n;
  cout<<"ingrese la semilla de codificacion"<<endl;
  cin>>n;

 string bincod= metodo(n, strbinario);
 string cod=codificado(bincod);

 cout<<"ingrese el nombre que tendra el archivo codificado"<<endl;
 cin>>nombre;


 archivobinario(cod, nombre);

 //-------------------------------decodificacion------------------------------//


 cout<<"ingrese el nombre del archivo a decodificar"<<endl;
 cin>>nombre;



 texto=lectura(nombre);
 strbinario=binario(texto);

cout<<"ingrese la semilla de decodificacion"<<endl;
cin>>n;

bincod=metododecodificacion(n,strbinario);
cod=codificado(bincod);

cout<<"ingrese el nombre que tendra el archivo decodificado"<<endl;
cin>>nombre;


archivobinario(cod, nombre);

 return 0;
}
