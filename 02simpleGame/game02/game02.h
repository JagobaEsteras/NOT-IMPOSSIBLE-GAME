#ifndef GAME10_H
#define GAME10_H
#include "ourTypes.h"

EGOERA bat_jokatu(int personajea);
EGOERA bi_jokatu(int personajea);
EGOERA hiru_jokatu(int personajea);
EGOERA lau_jokatu(int personajea);
EGOERA bost_jokatu(int personajea);
EGOERA sei_jokatu(int personajea);

EGOERA JOKOA_egoera_1(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA oztopoa1, JOKO_ELEMENTUA oztopoa2, JOKO_ELEMENTUA oztopoa3, JOKO_ELEMENTUA amaiera, int dauka);
EGOERA JOKOA_egoera_2(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA oztopoa1, JOKO_ELEMENTUA oztopoa2, JOKO_ELEMENTUA oztopoa3, JOKO_ELEMENTUA oztopoa4, JOKO_ELEMENTUA oztopoa5, JOKO_ELEMENTUA oztopoa6);
EGOERA JOKOA_egoera_3(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA oztopoa1, JOKO_ELEMENTUA oztopoa2, JOKO_ELEMENTUA oztopoa3, int dauka);
EGOERA JOKOA_egoera_4(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA oztopoa1, JOKO_ELEMENTUA oztopoa2, JOKO_ELEMENTUA amaiera, int obj);
EGOERA JOKOA_egoera_5(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA oztopoa1, JOKO_ELEMENTUA oztopoa2, JOKO_ELEMENTUA oztopoa3, JOKO_ELEMENTUA oztopoa4, JOKO_ELEMENTUA proyectil1, JOKO_ELEMENTUA proyectil2, JOKO_ELEMENTUA proyectil3, JOKO_ELEMENTUA proyectil4, JOKO_ELEMENTUA amaiera);
EGOERA JOKOA_egoera_6(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA oztopoa1, JOKO_ELEMENTUA oztopoa2, JOKO_ELEMENTUA oztopoa3, JOKO_ELEMENTUA amaiera, int obj);

int  jokoAmaierakoa(EGOERA egoera);
int  jokoAmaierakoa2(EGOERA egoera);
int  jokoAmaierakoa3(EGOERA egoera);
int  jokoAmaierakoa4(EGOERA egoera);
int  jokoAmaierakoa5(EGOERA egoera);
int  jokoAmaierakoa6(EGOERA egoera);

#endif