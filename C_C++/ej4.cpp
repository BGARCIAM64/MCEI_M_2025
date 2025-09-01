#include <iostream>
#include <cmath> // <cmath>
#include <float.h>
#include <iomanip>

float funcion(float Vant, float paso, float m, float c){
  return Vant + (9.8 - c/m * Vant) * paso;
}

int main(int argc, char** argv){
   
  // Resolviendo el problema del paracaidista
  float veloant = 0.0;
  float velo = 0.0;
  float tiempo = 0.0, paso = 1.0;
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
