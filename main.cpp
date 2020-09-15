#include <iostream>
using namespace std;

int* descomponerDigitos(long int numero,int & n)
{
  //contar digitos
  n=0;
  long int numero2 = numero;
  while(numero2 > 0)
  { n++; numero2 = numero2 / 10;}
  //inicializar
  int* digitos = new int[n];  
  //llenar digitos 
  int i=0;
  while(numero > 0)
  { digitos[i++] = numero%10; numero = numero / 10;}
  return digitos;
}

int* llenarTanques(int* digitos,int  n, int &m)
{
  m = n / 2;
  int* tanques = new int[m];
  for(int i=0;i<m;i++)
    tanques[i] = digitos[i] + digitos[n-i-1];
  return tanques;
}

void mostrarTanques(int* tanques, int m)
{
  cout<<"----------\n";
  cout<<"Numero de tanques: "<<m<<endl;  
  for(int i=0;i<m;i++)
    cout<<"Tanque "<<i+1<<": "
        <<tanques[i]<<" soldados\n"; 
}
int main() {
  long int numero;
  cout<<"Numero encriptado:";  cin>>numero;
  int n = 0, m = 0;
  int *digitos = descomponerDigitos(numero, n);
  int *tanques = llenarTanques(digitos, n, m);
  mostrarTanques(tanques, m);
  return 0;
}