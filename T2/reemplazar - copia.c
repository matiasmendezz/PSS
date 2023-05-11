#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "reemplazar.h"

char *reemplazo(char *s, char c, char *pal) {
   int cont_c = 0;
   char *ptr_s = s;
   //1er recorrido
   while ( *ptr_s != '\0' ){
    if (*ptr_s ==c ){
      cont_c++;
    }
    ptr_s++;
   }
   int largo_new_str = strlen(s) + cont_c * (strlen(pal)-1); 
   //se agrega el -1 ya que de otra forma se estaria contando dos veces 
   //el 1er caracter de pal
   char *new_str = malloc(largo_new_str+1);
   char *ptr_new_str = new_str;
   char *ptr_s2 = s;
   char *ptr_pal = pal;

    while ( *ptr_s2 != '\0' ){
      if ( *ptr_s2 == c ){
        //insertamos pal
        while( *ptr_pal != '\0' ){
          *ptr_new_str = *ptr_pal;
          ptr_new_str++;
          ptr_pal++;
        }
        //"reiniciamos" el puntero de pal para volver usarlo dps
        ptr_pal = ptr_pal - strlen(pal);
      } else {
        *ptr_new_str = *ptr_s2;
        ptr_new_str++;
        
      }
      ptr_s2++;
   }
   *ptr_new_str = '\0';  
   return new_str;
}

void reemplazar(char *s, char c, char *pal) {
  int cont_c = 0;
  char *ptr_s = s;
  char *ptr_pal = pal;
  //1er recorrido
  while( *ptr_s != '\0'){
    if ( *ptr_s == c )
      cont_c++;
    ptr_s++;
  }
  //volvemos apuntar al inicio
  ptr_s = ptr_s-( strlen(s)-1 );
  //si el largo de pal es 0
  if (strlen(pal) == 0){
    
  } 
  // si largo de pal es  1
  if ( strlen(pal) <= 1 ){
    if (strlen(pal) == 0){
    char *p = s; // Puntero para recorrer el string original
    char *q = s; // Puntero para escribir el string modificado
    while (*p) {
        if (*p != c) {
            *q = *p; // Copiar el caracter actual si no es el caracter a eliminar
            q++; // Mover el puntero de escritura
        }
        p++; // Mover el puntero de lectura
    }
    *q = '\0'; // Agregar el carácter nulo para terminar el string modificado
    } else{
    while ( *ptr_s != '\0'){
      if (*ptr_s == c)
        *ptr_s = *ptr_pal;
      ptr_s++;
      }
    }
  } 
  if (strlen(pal)>1){
    printf("XD\n");
    //largo de pal mayor que 1
    //apuntamos al final de s
    ptr_s = s + strlen(s)-1;
    //puntero inicializado al final del nuevo s
    int largo_new_s = strlen(s) + cont_c * (strlen(pal)-1);
    char *ptr_new_s = s + largo_new_s;
    ptr_new_s--;
    while (s <= ptr_s){
      if (*ptr_s == c){
        //insertamos pal
        ptr_new_s = ptr_new_s - (strlen(pal) - 1 );
        printf("el string es  %s\n", s);
        strcpy(ptr_new_s, pal);
        printf("el string queda como %s\n", s);
        /*
        while( *ptr_pal != '\0' ){
          *ptr_new_s = *ptr_pal;
          ptr_new_s++;
          ptr_pal++;
        }
        */
        ptr_s--;
        //siguiente posicion en el nuevo s
        ptr_new_s = ptr_new_s -1;
        //"reiniciamos" el puntero de pal para volver usarlo dps
        ptr_pal = pal;
      } else {
        printf("Normal: el string es %s\n", s);
        *ptr_new_s = *ptr_s;
        printf("un dorito dps: el string es %s\n", s);
        ptr_new_s--;
        ptr_s--;
      }
    }
    ptr_new_s = s + largo_new_s;
    *ptr_new_s = '\0';
  }
  

}
