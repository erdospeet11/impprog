#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reverse.h"

void teszt_allocc(void *p);
char **beolvas(FILE *fajl, int *pLines);
void kiiras(char **sorok, int mar_beolvasott_sorok);
void reverse(FILE *fajl);
char* reverse_sor(char* str);

//--------------------------------------------------------------------------------------------------------
void teszt_allocc( void *p)
{
  if (p == NULL)
  {
    perror("Out of memory\n");
    exit(2);    
  }	  
}
//--------------------------------------------------------------------------------------------------------
char* reverse_sor(char* str) {
  size_t length = strlen(str);

  char* uj_str = malloc(length * sizeof(char));

  size_t i = 0;

  for (i = 0; i < length;i++){
    uj_str[i] = str[length - i - 1];
  }

  return uj_str;
}
//--------------------------------------------------------------------------------------------------------

void reverse(FILE *fajl)
{
  int mar_beolvasott_sorok = 0;
  char **sorok = beolvas(fajl, &mar_beolvasott_sorok);	
  kiiras(sorok, mar_beolvasott_sorok); 
}

char **beolvas(FILE *fajl, int *pLines)
{
  int kezdeti = 8;
  int mar_beolvasott_sorok = 0;
  char sorhossz[1024]; 
  
  char **sorok = (char **)malloc(kezdeti * sizeof(char*));
  teszt_allocc(sorok);
  
  while (fgets(sorhossz, 1024, fajl) != NULL)
  {
    int len = strlen(sorhossz);
    if ('\n' == sorhossz[len-1]){
      sorhossz[len-1] = '\0';
    }
    if (mar_beolvasott_sorok == kezdeti){
      kezdeti *= 2;
      sorok = realloc(sorok, kezdeti * sizeof(char *));
      teszt_allocc(sorok);
    }

    sorok[mar_beolvasott_sorok] = (char *)malloc(len+1);    
    teszt_allocc(sorok[mar_beolvasott_sorok]);
    strcpy(sorok[mar_beolvasott_sorok], sorhossz);
    ++mar_beolvasott_sorok;

  }
  
  *pLines = mar_beolvasott_sorok;  
  return sorok;
}

void kiiras(char **sorok, int mar_beolvasott_sorok)
{
  int i;
  for (i = mar_beolvasott_sorok-1; i >= 0; --i){
    char *aktualis_sor = sorok[i];
    printf("%d %s\n", i+1, reverse_sor(aktualis_sor));

    free(aktualis_sor);
  }
  free(sorok);
}