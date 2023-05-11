#include <stdlib.h>
#include <string.h>
#include "comprimir.h"
uint comprimir(uint a[], int nbits) {
  unsigned resultado = 0;
  int i = 0;
  while ( (i+1)*nbits<= sizeof(uint)<<3){
    //printf("%d\n", i);
    //mascara
    uint z = -1;
    uint mask = ~( (z<<(nbits-1))<<1 );
    // x = x31 x30 ... x1 x0
    uint x = a[i];
    x &= mask;
    //printf("%d el x \n", x);
    // queda x = 0 ... 0 x(nbits-1) ... x1 x0
    resultado = resultado << (nbits-1)<<1;
    // concateno
    resultado = resultado | x;
    i++;
  }
  return resultado;
}
