#include <iostream>
#include <cmath> // <cmath>
#include <float.h>
#include <iomanip>

double funcion(double Vant, double paso, double m, double c){
  return Vant + (9.8 - c/m * Vant) * paso;
}

int main(int argc, char** argv){
   
  // Resolviendo el problema del paracaidista
  double veloant = 0.0;
  double velo = 0.0;
  double tiempo = 0.0, paso = 1.0;
  velo = 0.0;
  tiempo = 0.0;

  std::cout << std::setprecision(16) << "t = 0.0\t" <<  "vel = " << velo << std::endl;
  do{
    veloant = velo;
    tiempo = tiempo + paso;
    velo = funcion(veloant, paso, 68.1, 12.5);
    std::cout << "t = " << tiempo << " vel = " << velo << std::endl;
  }while(veloant != velo);
//  }while( ( velo - veloant) > 0.000000001 );
  return 0;
}
