#include <stdio.h>
#include <stdlib.h>

#include "elim-rango.h"

void eliminarRango(Nodo **phead, double y, double z) {
  Nodo *p_actual = *phead;
  Nodo *p_previo = NULL;
  while ( p_actual != NULL){
    if ((p_actual -> x) > z){
      break;
    }
    int valor = p_actual -> x;
    if ( (y <= (double)valor) && ((double)valor <= z)){
      //guardamos el nodo a eliminar en temp
      Nodo *temp = p_actual;
      //pasamos al sgte nodo
      p_actual = p_actual ->prox;
      if (p_previo == NULL){
        //caso que el primer nodo se elimina
        *phead = p_actual;
      }else{
        //caso normal
        p_previo -> prox = p_actual;
      } 
      free(temp);
    }else{
    //caso que aun no se llega a un nodo para eliminar
    p_previo = p_actual;
    p_actual = p_actual -> prox;
    }
  }
}
