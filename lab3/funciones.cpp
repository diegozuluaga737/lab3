#include "funciones.h"




string Binary_to_Str(string binario)
{
    string caracter,texto;
    for(int i=0; i<int(binario.length());i+=8){
        caracter = binario.substr(i,8);
        caracter = stoi(caracter, nullptr, 2);
        texto.append(caracter);
    }
    return texto;
}

string lectura(string nombre){                 //leer un arcrivo y guardarlo en un string
    string texto0="",texto="";
   // nombre=nombre+".txt";

    ifstream archivo;

 archivo.open(nombre,ios::in);

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




void archivobinario(string bincod, string nombin){         //reemplaza el texto original y lo combierte a un archivo codificado

    ofstream archivobinario;

   // nombin=nombin+".dat";

    archivobinario.open(nombin,ios::out|ios::binary);

    if(archivobinario.fail()){
     cout<<"No se pudo abrir el archivo."<<endl;
     exit(1);
    }

    archivobinario<<bincod;


    archivobinario.close();

}

string metododecodificacion(int n, string bin){
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
      if(bincod[j]==48) cont0+=1;
      if(bincod[j]==49) cont1+=1;

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

  cont0=0;
  cont1=0;



  }

  return bincod;

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
