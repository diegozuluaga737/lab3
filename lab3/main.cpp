#include <funciones.h>


//Primer metodo.....

int main(){





    int met;
    int dec;
    cout<<"ingrese 1.para el metodo numero uno, 2. para el metodo numero 2"<<endl;
    cin>>met;

    switch (met) {

    case 1: {
        cout<<"ingrese 1.para codificar, 2. para decodificar"<<endl;
        cin>>dec;

        switch (dec) {

        case 1: {
            string nombre;
            cout<<"ingrese el nombre del archivo a codificar"<<endl;
            cin>>nombre;

           string texto=lectura(nombre);
           string strbinario=binario(texto);


           int n;
           cout<<"ingrese la semilla de codificacion"<<endl;
           cin>>n;

          string bincod= metodo(n, strbinario);
         string cod=Binary_to_Str( bincod);
          cout<<"ingrese el nombre que tendra el archivo codificado"<<endl;
          cin>>nombre;


          archivobinario(cod, nombre);

            break;
        }
        case 2:{
            string nombre;
            cout<<"ingrese el nombre del archivo a decodificar"<<endl;
            cin>>nombre;



          string    texto=lectura(nombre);
          string  strbinario=binario(texto);


          int n;
           cout<<"ingrese la semilla de decodificacion"<<endl;
           cin>>n;

          string bincod=metododecodificacion(n,strbinario);
          string cod=Binary_to_Str( bincod);
           cout<<"ingrese el nombre que tendra el archivo decodificado"<<endl;
           cin>>nombre;


           archivobinario(cod, nombre);

            break;
             }

        }

        break;
    }
    case 2:{

        break;
    }

    }

 return 0;
}
