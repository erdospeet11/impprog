#include <stdio.h>
#include <stdlib.h>
#include "reverse.h"

int main( int argc, char *argv[])
{
  if ( argc < 2 )
  {
    reverse(stdin, "stdin");	  
  }
  else
  {
    int i;
    for ( i = 1; i < argc; ++i )  
    {
      FILE *fajl = fopen( argv[i], "r");
      if (fajl != NULL)
      {
         reverse(fajl, argv[i]);
         fclose(fajl);
      }
      else
      {
        perror("File opening unsuccessful!");
        exit(1);	      
      }
    }
  }
  return 0;
}