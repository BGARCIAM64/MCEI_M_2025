#include <stdio.h>
#include <math.h> // <cmath>

double funcion(double t, double m, double c){
  return 9.8 * m / c * (1 - exp( -c/m*t ) );
}

int main(int argc, char** argv){
  int entera = 525;
  double doble = 525.0;
  printf("Hola mundo MCEI_M\n");
  printf("El entero: %d\n", entera);
  printf("El real: %f\n", doble);
  doble = doble + 5.5;
  printf("El nuevo valor: %f\n", doble);
  entera = entera + 5.5;
  printf("El nuevo entero: %d\n", entera);
   
  // Resolviendo el problema del paracaidista
  double veloant = 0.0;
  double velo = 0.0;
  double tiempo = 0.0;
  velo = funcion(tiempo, 68.1, 12.5);
  tiempo = 2.0;
  printf("t= %f \t vel= %f\n", 0.0, velo);
  do{
    veloant = velo;
    velo = funcion(tiempo, 68.1, 12.5);
    printf("t= %f \t vel= %f\n",tiempo,velo);
    tiempo = tiempo + 2.0;
  }while( veloant != velo );
  return 0;
}
