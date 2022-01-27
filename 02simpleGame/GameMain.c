/*#include "orokorrak.h"
#include "sarrera.h"
#include "errealitateFisikoa.h"
#include "jokoa.h"
#include "bukaera.h"*/

//---------------------------------------------------------------------------------
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
//---------------------------------------------------------------------------------

#include <stdio.h>
#include "Menua.h"
#include "ourTypes.h"
#include "game02.h"

int main(int argc, char * str[]) {
    int jarraitu = 0, irten = 0,pertsonaia=4;
    int  balioa = 1;
  EGOERA egoera;
 
  if (sgHasieratu() == -1) 
  {
    fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
    return 1;
  }
  textuaGaitu(); 
  do{
  //Menua
        if (balioa == 1)balioa = jokoaAurkeztu();
  //nibel menu
        if (balioa == 2)balioa = Nibelak();
  //nibelak
        if (balioa == 3)
        {
            egoera = bat_jokatu(pertsonaia);
            if (egoera != 3)balioa = jokoAmaierakoa(egoera);
            else balioa = 1;
        }
        if (balioa == 4) {
            egoera = bi_jokatu(pertsonaia);
            if (egoera != 3)balioa = jokoAmaierakoa2(egoera);
            else balioa = 1;
        }
        if (balioa == 5) {
            egoera = hiru_jokatu(pertsonaia);
            if (egoera != 3)balioa = jokoAmaierakoa3(egoera);
            else balioa = 1;
        }
        if (balioa == 6) {
            egoera = lau_jokatu(pertsonaia);
            if (egoera != 3)balioa = jokoAmaierakoa4(egoera);
            else balioa = 1;
        }
        if (balioa == 7) {
            egoera = bost_jokatu(pertsonaia);
            if (egoera != 3)balioa = jokoAmaierakoa5(egoera);
            else balioa = 1;
        }
        if (balioa == 8) {
            egoera = sei_jokatu(pertsonaia);
            if (egoera != 3)balioa = jokoAmaierakoa6(egoera);
            else balioa = 1;
        }
        if (balioa == 9) {
            egoera = sei_jokatu(pertsonaia);
            balioa = jokoAmaierakoa(egoera);
        }
  //kredituak
        if (balioa == 10)balioa = Kredituak();
  //pertsonaiak
        if (balioa == 11)
        {
        pertsonaia = Pertsonaiak();
        if (pertsonaia < 10)balioa = 1;
        }
  //Instrukzioak
        if (balioa == 12 || pertsonaia == 10) {
            balioa = Instrukzioak();
        }
  } while (!jarraitu);
  sgItxi();
  return 0;
}

