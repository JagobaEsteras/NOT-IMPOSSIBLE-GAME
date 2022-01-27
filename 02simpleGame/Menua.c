#include "game02.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>
#include "Menua.h"

#define MENU_SOUND ".\\sound\\MenuSound.wav"

//Menua
#define JOKOA_LOGOA ".\\img\\LogoSarrera.bmp"

#define JOKOA_MENUA_PLAY1 ".\\img\\Botoiak\\JOLASTU1botoia.bmp"
#define JOKOA_MENUA_PLAY ".\\img\\Botoiak\\JOLASTUbotoia.bmp"

#define JOKOA_MENUA_HELP ".\\img\\Botoiak\\MAILAKpbotoia.bmp"
#define JOKOA_MENUA_HELP1 ".\\img\\Botoiak\\MAILAK1botoia.bmp"

#define JOKOA_MENUA_CREDITS ".\\img\\Botoiak\\EGILEAKbotoia.bmp"
#define JOKOA_MENUA_CREDITS1 ".\\img\\Botoiak\\EGILEAK1botoia.bmp"

#define JOKOA_MENUA_HOME ".\\img\\Botoiak\\casita.bmp"
#define JOKOA_MENUA_PERCHA ".\\img\\Botoiak\\percha.bmp"
#define JOKOA_MENUA_AJUSTES ".\\img\\Botoiak\\ajustes.bmp"



//Instrukzioak
#define HELP_ARGAZKIA ".\\img\\Instrukzioak.bmp"

//Kredituak
#define KREDIT_PERTSONAIA ".\\img\\creditsirudia.bmp"

//Nivelak
#define JOKOA_MENUA_NIVEL ".\\img\\Maila\\mailak.bmp"
#define JOKOA_MENUA_1NIVEL ".\\img\\Maila\\1nivel.bmp"
#define JOKOA_MENUA_2NIVEL ".\\img\\Maila\\2nivel.bmp"
#define JOKOA_MENUA_3NIVEL ".\\img\\Maila\\3nivel.bmp"
#define JOKOA_MENUA_4NIVEL ".\\img\\Maila\\4nivel.bmp"
#define JOKOA_MENUA_5NIVEL ".\\img\\Maila\\5nivel.bmp"
#define JOKOA_MENUA_6NIVEL ".\\img\\Maila\\6nivel.bmp"

#define JOKOA_MENUA_1NIVELG ".\\img\\Maila\\1nivelg.bmp"
#define JOKOA_MENUA_2NIVELG ".\\img\\Maila\\2nivelg.bmp"
#define JOKOA_MENUA_3NIVELG ".\\img\\Maila\\3nivelg.bmp"
#define JOKOA_MENUA_4NIVELG ".\\img\\Maila\\4nivelg.bmp"
#define JOKOA_MENUA_5NIVELG ".\\img\\Maila\\5nivelg.bmp"
#define JOKOA_MENUA_6NIVELG ".\\img\\Maila\\6nivelg.bmp"

//Pertsonaiak
#define JOKOA_MENUA_PERTSONAIAK ".\\img\\PersonajesGrande\\Pertsonaiakmezua.bmp"
#define JOKOA_PER_GORRIA ".\\img\\PersonajesGrande\\Personaje_Rojog.bmp"
#define JOKOA_PER_BERDEA ".\\img\\PersonajesGrande\\Personaje_Verdeg.bmp"
#define JOKOA_PER_URDINA ".\\img\\PersonajesGrande\\Personaje_Azulg.bmp"
#define JOKOA_PER_TXURIA ".\\img\\PersonajesGrande\\Personaje_Blancog.bmp"
#define JOKOA_PER_URDINARGIA ".\\img\\PersonajesGrande\\Personaje_Azulg-Claro.bmp"
#define JOKOA_PER_NARANJA ".\\img\\PersonajesGrande\\Personaje_Naranjag.bmp"
#define JOKOA_PER_MOREA ".\\img\\PersonajesGrande\\Personaje_Moradog.bmp"
#define JOKOA_PER_ARROSA ".\\img\\PersonajesGrande\\Personaje_Rosag.bmp"


#define JOKOA_PER_GORRIAG ".\\img\\PersonajesGrande\\Personaje_Rojomg.bmp"
#define JOKOA_PER_BERDEAG ".\\img\\PersonajesGrande\\Personaje_Verdemg.bmp"
#define JOKOA_PER_URDINAG ".\\img\\PersonajesGrande\\Personaje_Azulmg.bmp"
#define JOKOA_PER_TXURIAG ".\\img\\PersonajesGrande\\Personaje_Blancomg.bmp"
#define JOKOA_PER_URDINARGIAG ".\\img\\PersonajesGrande\\Personaje_Azulmg-Claro.bmp"
#define JOKOA_PER_NARANJAG ".\\img\\PersonajesGrande\\Personaje_Naranjamg.bmp"
#define JOKOA_PER_MOREAG ".\\img\\PersonajesGrande\\Personaje_Moradomg.bmp"
#define JOKOA_PER_ARROSAG ".\\img\\PersonajesGrande\\Personaje_Rosamg.bmp"

int jokoaAurkeztu()
{
    int ebentu = 0, ebentu2 = 0, balioa=0, menuaArgazki,creditsbotoia,percha,galdera;
    int jolastu = 0, jolastu1 = 0, maila = 0, maila1 = 0, kreditu = 0, kreditu1 = 0;
    int dauka = 0;

    audioInit();
    loadTheMusic(MENU_SOUND);
    playMusic();
    POSIZIOA pos, pos1,pos2,pos3;

    menuaArgazki = irudiaKargatu(JOKOA_LOGOA);
    creditsbotoia = irudiaKargatu(JOKOA_MENUA_CREDITS);
    percha = irudiaKargatu(JOKOA_MENUA_PERCHA);
    galdera = irudiaKargatu(JOKOA_MENUA_AJUSTES);

    irudiaMugitu(menuaArgazki, 148, 5);
    irudiaMugitu(creditsbotoia, 440, 340);
    irudiaMugitu(percha, 500, 410);
    irudiaMugitu(galdera, 570, 410);
    pantailaGarbitu();
    irudiakMarraztu();
    
    jolastu1 = irudiaKargatu(JOKOA_MENUA_PLAY1);
    jolastu = irudiaKargatu(JOKOA_MENUA_PLAY);
    maila1 = irudiaKargatu(JOKOA_MENUA_HELP1);
    maila = irudiaKargatu(JOKOA_MENUA_HELP);
    kreditu1 = irudiaKargatu(JOKOA_MENUA_CREDITS1);
    kreditu = irudiaKargatu(JOKOA_MENUA_CREDITS);
    
    irudiaMugitu(jolastu, 60, 340);
    irudiaMugitu(jolastu1, 60, 340);
    irudiaMugitu(maila, 250, 340);
    irudiaMugitu(maila1, 250, 340);
    irudiaMugitu(kreditu, 440, 340);
    irudiaMugitu(kreditu1, 440, 340);
    irudiakMarraztu();
    pantailaBerriztu();
    do
    {
            pos1 = saguarenPosizioa();
            pos2 = saguarenPosizioa();
            pos3 = saguarenPosizioa();
            if ((pos1.x > 60) && (pos1.x < 60 + 136) && (pos1.y > 340) && (pos1.y < 399) && !dauka)
            {
                irudiaMugitu(jolastu, 700, 340);
                irudiakMarraztu();
                pantailaBerriztu();
                dauka = 1;
            }
            if ((pos1.x < 60) || (pos1.x > 60 + 136) || (pos1.y < 340) || (pos1.y > 399) && dauka)
            {
                dauka = 0;
                irudiaMugitu(jolastu, 60, 340);
                irudiakMarraztu();
                pantailaBerriztu();
            }
            
            if ((pos2.x > 250) && (pos2.x < 250 + 136) && (pos2.y > 340) && (pos2.y < 399) && !dauka)
            {
                irudiaMugitu(maila, 700, 340);
                irudiakMarraztu();
                pantailaBerriztu();
                dauka = 1;
            }
            if ((pos2.x < 250) || (pos2.x > 250 + 136) || (pos2.y < 340) || (pos2.y > 399) && dauka)
            {
                dauka = 0;
                irudiaMugitu(maila, 250, 340);
                irudiakMarraztu();
                pantailaBerriztu();
            }
            
            if ((pos3.x > 440) && (pos3.x < 400 + 136) && (pos3.y > 340) && (pos3.y < 399) && !dauka)
            {
                irudiaMugitu(kreditu, 700, 340);
                irudiakMarraztu();
                pantailaBerriztu();
                dauka = 1;
            }
            if ((pos3.x < 440) || (pos3.x > 440 + 136) || (pos3.y < 340) || (pos3.y > 399) && dauka)
            {
                dauka = 0;
                irudiaMugitu(kreditu, 440, 340);
                irudiakMarraztu();
                pantailaBerriztu();
            }     

            ebentu = ebentuaJasoGertatuBada();
   
            if (ebentu == SAGU_BOTOIA_EZKERRA) {
                pos = saguarenPosizioa();
                if ((pos.x > 60) && (pos.x < 60 + 136) && (pos.y > 340) && (pos.y < 399))balioa = 3;
                if ((pos.x > 250) && (pos.x < 250 + 136) && (pos.y > 340) && (pos.y < 399)) balioa = 2;
                if ((pos.x > 440) && (pos.x < 440 + 136) && (pos.y > 340) && (pos.y < 399)) balioa = 10;
                if ((pos.x > 500) && (pos.x < 500 + 43) && (pos.y > 410) && (pos.y < 453)) balioa = 11;
                if ((pos.x > 570) && (pos.x < 570 + 43) && (pos.y > 410) && (pos.y < 453)) balioa = 12;
            }
    } while (!balioa);
    
    pantailaGarbitu();
    irudiaKendu(jolastu);
    irudiaKendu(jolastu1);
    irudiaKendu(maila);
    irudiaKendu(maila1);
    irudiaKendu(kreditu);
    irudiaKendu(kreditu1);
    irudiaKendu(menuaArgazki);
    irudiaKendu(creditsbotoia);
    irudiaKendu(galdera);
    irudiaKendu(percha);
    pantailaBerriztu();
    return balioa;
}
int Instrukzioak()
{
    int balioa = 0, ebentu = 0, irten = 0;
    POSIZIOA pos;

    pantailaGarbitu();

    int hasieraArgazki = irudiaKargatu(JOKOA_MENUA_HOME);
    int helpARGAZKIAK = irudiaKargatu(HELP_ARGAZKIA);
    irudiaMugitu(hasieraArgazki, 430, 410);
    irudiaMugitu(helpARGAZKIAK, 20, 15);
    int percha = irudiaKargatu(JOKOA_MENUA_PERCHA);
    int galdera = irudiaKargatu(JOKOA_MENUA_AJUSTES);
    irudiaMugitu(percha, 500, 410);
    irudiaMugitu(galdera, 570, 410);
    irudiakMarraztu();
    irudiaKendu(hasieraArgazki);
    irudiaKendu(helpARGAZKIAK);
    irudiaKendu(percha);
    irudiaKendu(galdera);
    pantailaBerriztu();

    do {
        ebentu = ebentuaJasoGertatuBada();
        if (ebentu == SAGU_BOTOIA_EZKERRA) {
            pos = saguarenPosizioa();
            if ((pos.x > 430) && (pos.x < 430 + 43) && (pos.y > 410) && (pos.y < 453)) balioa = 1;
            if ((pos.x > 570) && (pos.x < 570 + 43) && (pos.y > 410) && (pos.y < 453)) balioa = 12;
            if ((pos.x > 500) && (pos.x < 500 + 43) && (pos.y > 410) && (pos.y < 453)) balioa = 11;
        }
    } while (!balioa);
    return balioa;
}
int Kredituak()
{
    int irten = 0, ebentu = 0, balioa = 0;
    POSIZIOA pos;

    pantailaGarbitu();
    int hasieraArgazki = irudiaKargatu(JOKOA_MENUA_HOME);
    int kreditupertsona = irudiaKargatu(KREDIT_PERTSONAIA);
    irudiaMugitu(hasieraArgazki, 430, 410);
    irudiaMugitu(kreditupertsona, 20, 15);
    int percha = irudiaKargatu(JOKOA_MENUA_PERCHA);
    int galdera = irudiaKargatu(JOKOA_MENUA_AJUSTES);
    irudiaMugitu(percha, 500, 410);
    irudiaMugitu(galdera, 570, 410);
    irudiakMarraztu();
    irudiaKendu(hasieraArgazki);
    irudiaKendu(kreditupertsona);
    irudiaKendu(percha);
    irudiaKendu(galdera);
    pantailaBerriztu();

    do {
        ebentu = ebentuaJasoGertatuBada();
        if (ebentu == SAGU_BOTOIA_EZKERRA) {
            pos = saguarenPosizioa();
            if ((pos.x > 430) && (pos.x < 430 + 43) && (pos.y > 410) && (pos.y < 453)) balioa = 1;
            if ((pos.x > 570) && (pos.x < 570 + 43) && (pos.y > 410) && (pos.y < 453)) balioa = 12;
            if ((pos.x > 500) && (pos.x < 500 + 43) && (pos.y > 410) && (pos.y < 453)) balioa = 11;
        }
    } while (!balioa);
    return balioa;
}
int Nibelak()
{
    int atera = 0, ebentu = 0, dauka=0, dauka1=0, dauka4 = 0, dauka2 = 0, dauka3 = 0, dauka5 = 0 ;
    int balioa = 0;
    POSIZIOA pos,pos1;

    pantailaGarbitu();

    int nivel = irudiaKargatu(JOKOA_MENUA_NIVEL);
    int bat_nivel = irudiaKargatu(JOKOA_MENUA_1NIVEL);
    int bi_nivel = irudiaKargatu(JOKOA_MENUA_2NIVEL);
    int hiru_nivel = irudiaKargatu(JOKOA_MENUA_3NIVEL);
    int lau_nivel = irudiaKargatu(JOKOA_MENUA_4NIVEL);
    int bost_nivel = irudiaKargatu(JOKOA_MENUA_5NIVEL);
    int sei_nivel = irudiaKargatu(JOKOA_MENUA_6NIVEL);

    int bat_nivelG = irudiaKargatu(JOKOA_MENUA_1NIVELG);
    int bi_nivelG = irudiaKargatu(JOKOA_MENUA_2NIVELG);
    int hiru_nivelG = irudiaKargatu(JOKOA_MENUA_3NIVELG);
    int lau_nivelG = irudiaKargatu(JOKOA_MENUA_4NIVELG);
    int bost_nivelG = irudiaKargatu(JOKOA_MENUA_5NIVELG);
    int sei_nivelG = irudiaKargatu(JOKOA_MENUA_6NIVELG);

    int hasieraArgazki = irudiaKargatu(JOKOA_MENUA_HOME);
    int percha = irudiaKargatu(JOKOA_MENUA_PERCHA);
    int galdera = irudiaKargatu(JOKOA_MENUA_AJUSTES);
    irudiaMugitu(percha, 500, 410);
    irudiaMugitu(galdera, 570, 410);
    irudiaMugitu(hasieraArgazki, 430, 410);
    irudiaMugitu(nivel, 175, 55);
    irudiaMugitu(bat_nivel, 75, 175);
    irudiaMugitu(bi_nivel, 275, 175);
    irudiaMugitu(hiru_nivel, 475, 175);
    irudiaMugitu(lau_nivel, 75, 300);
    irudiaMugitu(bost_nivel, 275, 300);
    irudiaMugitu(sei_nivel, 475, 300);

    irudiaMugitu(bat_nivelG, 775, 175);
    irudiaMugitu(bi_nivelG, 775, 175);
    irudiaMugitu(hiru_nivelG, 775, 175);
    irudiaMugitu(lau_nivelG, 775, 300);
    irudiaMugitu(bost_nivelG, 775, 300);
    irudiaMugitu(sei_nivelG, 775, 300);
    irudiakMarraztu();
    
    pantailaBerriztu();

    do {
        pos1 = saguarenPosizioa();
        if ((pos1.x > 75) && (pos1.x < 155) && (pos1.y > 175) && (pos1.y < 225) && !dauka) {
            irudiaMugitu(bat_nivelG, 40, 145);
            pantailaGarbitu();
            irudiakMarraztu();
            pantailaBerriztu();
            dauka = 1;
        }
        if ((pos1.x < 75) || (pos1.x > 155) || (pos1.y < 175) || (pos1.y > 175 + 50) && dauka)
        {
            
            irudiaMugitu(bat_nivelG, 700, 540);
            pantailaGarbitu();
            irudiakMarraztu();
            pantailaBerriztu();
            dauka = 0;
        }


        if ((pos1.x > 275) && (pos1.x < 275 + 80) && (pos1.y > 175) && (pos1.y < 225) && !dauka2) {
            irudiaMugitu(bi_nivelG, 240, 145);
            irudiakMarraztu();
            pantailaBerriztu();
            dauka2 = 1;
        }
        if ((pos1.x < 275) || (pos1.x > 275 + 80) || (pos1.y < 175) || (pos1.y > 225) && dauka2)
        {
            dauka2 = 0;
            irudiaMugitu(bi_nivelG, 700, 540);
            pantailaGarbitu();
            irudiakMarraztu();
            pantailaBerriztu();
        }


        if ((pos1.x > 475) && (pos1.x < 475 + 80) && (pos1.y > 175) && (pos1.y < 225) && !dauka3) {
            irudiaMugitu(hiru_nivelG, 440, 145);
            irudiakMarraztu();
            pantailaBerriztu();
            dauka3 = 1;
        }
        if ((pos1.x < 475) || (pos1.x > 475 + 80) || (pos1.y < 175) || (pos1.y > 225) && dauka3)
        {
            dauka3 = 0;
            irudiaMugitu(hiru_nivelG, 700, 540);
            pantailaGarbitu();
            irudiakMarraztu();
            pantailaBerriztu();
        }


        if ((pos1.x > 75) && (pos1.x < 75 + 80) && (pos1.y > 300) && (pos1.y < 350) && !dauka1) {
            irudiaMugitu(lau_nivelG, 40, 270);
            irudiakMarraztu();
            pantailaBerriztu();
            dauka1 = 1;
        }
        if ((pos1.x < 75) || (pos1.x > 75 + 80) || (pos1.y < 300) || (pos1.y > 350) && dauka1)
        {
            dauka1 = 0;
            irudiaMugitu(lau_nivelG, 700, 540);
            pantailaGarbitu();
            irudiakMarraztu();
            pantailaBerriztu();
        }


        if ((pos1.x > 275) && (pos1.x < 275 + 80) && (pos1.y > 300) && (pos1.y < 350) && !dauka1) {
            irudiaMugitu(bost_nivelG, 240, 270);
            irudiakMarraztu();
            pantailaBerriztu();
            dauka1 = 1;
        }
        if ((pos1.x < 275) || (pos1.x > 275 + 80) || (pos1.y < 300) || (pos1.y > 350) && dauka1)
        {
            dauka1 = 0;
            irudiaMugitu(bost_nivelG, 700, 540);
            pantailaGarbitu();
            irudiakMarraztu();
            pantailaBerriztu();
        }


        if ((pos1.x > 475) && (pos1.x < 475 + 80) && (pos1.y > 300) && (pos1.y < 350) && !dauka1) {
            irudiaMugitu(sei_nivelG, 440, 270);
            irudiakMarraztu();
            pantailaBerriztu();
            dauka1 = 1;
        }
        if ((pos1.x < 475) || (pos1.x > 475 + 80) || (pos1.y < 300) || (pos1.y > 350) && dauka1)
        {
            dauka1 = 0;
            irudiaMugitu(sei_nivelG, 700, 540);
            pantailaGarbitu();
            irudiakMarraztu();
            pantailaBerriztu();
        }

        ebentu = ebentuaJasoGertatuBada();
        if (ebentu == SAGU_BOTOIA_EZKERRA) {
            pos = saguarenPosizioa();
            if ((pos.x > 430) && (pos.x < 430 + 43) && (pos.y > 410) && (pos.y < 453)) balioa = 1;
            if ((pos.x > 75) && (pos.x < 75 + 80) && (pos.y > 175) && (pos.y < 225)) balioa = 3;
            if ((pos.x > 275) && (pos.x < 275 + 80) && (pos.y > 175) && (pos.y < 225)) balioa = 4;
            if ((pos.x > 475) && (pos.x < 475 + 80) && (pos.y > 175) && (pos.y < 225)) balioa = 5;
            if ((pos.x > 75) && (pos.x < 75 + 80) && (pos.y > 300) && (pos.y < 350)) balioa = 6;
            if ((pos.x > 275) && (pos.x < 275 + 80) && (pos.y > 300) && (pos.y < 350)) balioa = 7;
            if ((pos.x > 475) && (pos.x < 475 + 80) && (pos.y > 300) && (pos.y < 350)) balioa = 8;
            if ((pos.x > 570) && (pos.x < 570 + 80) && (pos.y > 410) && (pos.y < 453)) balioa = 12;
            if ((pos.x > 500) && (pos.x < 500 + 80) && (pos.y > 410) && (pos.y < 453)) balioa = 11;
            
        }
    } while (!balioa);
    irudiaKendu(hasieraArgazki);
    irudiaKendu(nivel);
    irudiaKendu(bat_nivel);
    irudiaKendu(bi_nivel);
    irudiaKendu(hiru_nivel);
    irudiaKendu(lau_nivel);
    irudiaKendu(bost_nivel);
    irudiaKendu(sei_nivel);

    irudiaKendu(bat_nivelG);
    irudiaKendu(bi_nivelG);
    irudiaKendu(hiru_nivelG);
    irudiaKendu(lau_nivelG);
    irudiaKendu(bost_nivelG);
    irudiaKendu(sei_nivelG);
    irudiaKendu(galdera);
    irudiaKendu(percha);
    return balioa;
}
int Pertsonaiak()
{
    int atera = 0, ebentu = 0, pertsonaia = 0, dauka1 = 0, dauka2 = 0, dauka3 = 0, dauka4 = 0, dauka5 = 0, dauka6 = 0, dauka7 = 0, dauka8 = 0;

    POSIZIOA pos, pos1;

    pantailaGarbitu();

    int pertsonaiakmezua = irudiaKargatu(JOKOA_MENUA_PERTSONAIAK);
    int Gorria = irudiaKargatu(JOKOA_PER_GORRIA);
    int Berdea = irudiaKargatu(JOKOA_PER_BERDEA);
    int Urdina = irudiaKargatu(JOKOA_PER_URDINA);
    int Txuria = irudiaKargatu(JOKOA_PER_TXURIA);
    int Arrosa = irudiaKargatu(JOKOA_PER_ARROSA);
    int UrdinArgia = irudiaKargatu(JOKOA_PER_URDINARGIA);
    int Naranja = irudiaKargatu(JOKOA_PER_NARANJA);
    int Morea = irudiaKargatu(JOKOA_PER_MOREA);

    int mGorria = irudiaKargatu(JOKOA_PER_GORRIAG);
    int mBerdea = irudiaKargatu(JOKOA_PER_BERDEAG);
    int mUrdina = irudiaKargatu(JOKOA_PER_URDINAG);
    int mTxuria = irudiaKargatu(JOKOA_PER_TXURIAG);
    int mArrosa = irudiaKargatu(JOKOA_PER_ARROSAG);
    int mUrdinArgia = irudiaKargatu(JOKOA_PER_URDINARGIAG);
    int mNaranja = irudiaKargatu(JOKOA_PER_NARANJAG);
    int mMorea = irudiaKargatu(JOKOA_PER_MOREAG);
    int back = irudiaKargatu(JOKOA_MENUA_HOME);
    int percha = irudiaKargatu(JOKOA_MENUA_PERCHA);
    int galdera = irudiaKargatu(JOKOA_MENUA_AJUSTES);
    irudiaMugitu(percha, 500, 410);
    irudiaMugitu(galdera, 570, 410);
    irudiaMugitu(back, 430, 410);
    irudiaMugitu(pertsonaiakmezua, 105, 25);
    irudiaMugitu(Gorria, 75, 150);
    irudiaMugitu(Berdea, 225, 150);
    irudiaMugitu(Urdina, 375, 150);
    irudiaMugitu(Txuria, 525, 150);
    irudiaMugitu(Arrosa, 75, 275);
    irudiaMugitu(Morea, 225, 275);
    irudiaMugitu(Naranja, 375, 275);
    irudiaMugitu(UrdinArgia, 525, 275);

    irudiaMugitu(mGorria, 775, 150);
    irudiaMugitu(mBerdea, 725, 150);
    irudiaMugitu(mUrdina, 775, 150);
    irudiaMugitu(mTxuria, 725, 150);
    irudiaMugitu(mArrosa, 775, 275);
    irudiaMugitu(mMorea, 725, 275);
    irudiaMugitu(mNaranja, 775, 275);
    irudiaMugitu(mUrdinArgia, 725, 275);
    irudiakMarraztu();
    pantailaBerriztu();

    do {

        pos1 = saguarenPosizioa();

        if ((pos1.x > 75) && (pos1.x < 75 + 95) && (pos1.y > 150) && (pos1.y < 245) && !dauka1) {
            irudiaMugitu(mGorria, 69, 145);
            irudiakMarraztu();
            pantailaBerriztu();
            dauka1 = 1;
        }
        if ((pos1.x < 75) || (pos1.x > 75 + 95) || (pos1.y < 150) || (pos1.y > 245) && dauka1)
        {
            dauka1 = 0;
            irudiaMugitu(mGorria, 700, 540);
            pantailaGarbitu();
            irudiakMarraztu();
            pantailaBerriztu();
        }

        if ((pos1.x > 225) && (pos1.x < 225 + 95) && (pos1.y > 150) && (pos1.y < 245) && !dauka2) {
            irudiaMugitu(mBerdea, 219, 145);
            irudiakMarraztu();
            pantailaBerriztu();
            dauka2 = 1;
        }
        if ((pos1.x < 225) || (pos1.x > 225 + 95) || (pos1.y < 150) || (pos1.y > 245) && dauka2)
        {
            dauka2 = 0;
            irudiaMugitu(mBerdea, 700, 540);
            pantailaGarbitu(); 
            irudiakMarraztu();
            pantailaBerriztu();
        }

        if ((pos1.x > 375) && (pos1.x < 375 + 95) && (pos1.y > 150) && (pos1.y < 245) && !dauka3) {
            irudiaMugitu(mUrdina, 369, 145);
            irudiakMarraztu();
            pantailaBerriztu();
            dauka3 = 1;
        }
        if ((pos1.x < 375) || (pos1.x > 375 + 95) || (pos1.y < 150) || (pos1.y > 245) && dauka3)
        {
            dauka3 = 0;
            irudiaMugitu(mUrdina, 700, 540);
            pantailaGarbitu();
            irudiakMarraztu();
            pantailaBerriztu();
        }

        if ((pos1.x > 525) && (pos1.x < 525 + 95) && (pos1.y > 150) && (pos1.y < 245) && !dauka4) {
            irudiaMugitu(mTxuria, 519, 145);
            irudiakMarraztu();
            pantailaBerriztu();
            dauka4 = 1;
        }
        if ((pos1.x < 525) || (pos1.x > 525 + 95) || (pos1.y < 150) || (pos1.y > 245) && dauka4)
        {
            dauka4 = 0;
            irudiaMugitu(mTxuria, 700, 540);
            pantailaGarbitu();
            irudiakMarraztu();
            pantailaBerriztu();
        }

        if ((pos1.x > 75) && (pos1.x < 75 + 95) && (pos1.y > 275) && (pos1.y < 370) && !dauka5) {
            irudiaMugitu(mArrosa, 69, 270);
            irudiakMarraztu();
            pantailaBerriztu();
            dauka5 = 1;
        }
        if ((pos1.x < 75) || (pos1.x > 75 + 95) || (pos1.y < 275) || (pos1.y > 370) && dauka5)
        {
            dauka5 = 0;
            irudiaMugitu(mArrosa, 700, 540);
            pantailaGarbitu();
            irudiakMarraztu();
            pantailaBerriztu();
        }

        if ((pos1.x > 225) && (pos1.x < 225 + 95) && (pos1.y > 275) && (pos1.y < 370) && !dauka6) {
            irudiaMugitu(mMorea, 219, 270);
            irudiakMarraztu();
            pantailaBerriztu();
            dauka6 = 1;
        }
        if ((pos1.x < 225) || (pos1.x > 225 + 95) || (pos1.y < 275) || (pos1.y > 370) && dauka6)
        {
            dauka6 = 0;
            irudiaMugitu(mMorea, 700, 540);
            pantailaGarbitu();
            irudiakMarraztu();
            pantailaBerriztu();
        }

        if ((pos1.x > 375) && (pos1.x < 375 + 95) && (pos1.y > 275) && (pos1.y < 370) && !dauka7) {
            irudiaMugitu(mNaranja, 369, 270);
            irudiakMarraztu();
            pantailaBerriztu();
            dauka7 = 1;
        }
        if ((pos1.x < 375) || (pos1.x > 375 + 95) || (pos1.y < 275) || (pos1.y > 370) && dauka7)
        {
            dauka7 = 0;
            irudiaMugitu(mNaranja, 700, 540);
            pantailaGarbitu();
            irudiakMarraztu();
            pantailaBerriztu();
        }

        if ((pos1.x > 525) && (pos1.x < 525 + 95) && (pos1.y > 275) && (pos1.y < 370) && !dauka8) {
            irudiaMugitu(mUrdinArgia, 519, 269);
            irudiakMarraztu();
            pantailaBerriztu();
            dauka8 = 1;
        }
        if ((pos1.x < 525) || (pos1.x > 525 + 95) || (pos1.y < 275) || (pos1.y > 370) && dauka8)
        {
            dauka8 = 0;
            irudiaMugitu(mUrdinArgia, 700, 540);
            pantailaGarbitu();
            irudiakMarraztu();
            pantailaBerriztu();
        }    

        ebentu = ebentuaJasoGertatuBada();

        if (ebentu == SAGU_BOTOIA_EZKERRA) {
            


            pos = saguarenPosizioa();

            if ((pos.x > 430) && (pos.x < 430 + 43) && (pos.y > 410) && (pos.y < 453)) pertsonaia = 1;  //back
            if ((pos.x > 75) && (pos.x < 75 + 95) && (pos.y > 150) && (pos.y < 245)) pertsonaia = 2;    //gorria
            if ((pos.x > 225) && (pos.x < 225 + 95) && (pos.y > 150) && (pos.y < 245)) pertsonaia = 3;  //berdea
            if ((pos.x > 375) && (pos.x < 375 + 95) && (pos.y > 150) && (pos.y < 245)) pertsonaia = 4;  //urdina
            if ((pos.x > 525) && (pos.x < 525 + 95) && (pos.y > 150) && (pos.y < 245)) pertsonaia = 5;    //txuria
            if ((pos.x > 75) && (pos.x < 75 + 95) && (pos.y > 275) && (pos.y < 370)) pertsonaia = 6; //arrosa
            if ((pos.x > 225) && (pos.x < 225 + 95) && (pos.y > 275) && (pos.y < 370)) pertsonaia = 7; //urdinargia
            if ((pos.x > 375) && (pos.x < 375 + 95) && (pos.y > 275) && (pos.y < 370)) pertsonaia = 8;    //naranja
            if ((pos.x > 525) && (pos.x < 525 + 95) && (pos.y > 275) && (pos.y < 370)) pertsonaia = 9;   //morea
            if ((pos.x > 570) && (pos.x < 570 + 43) && (pos.y > 410) && (pos.y < 453)) pertsonaia = 10;//instrukzioak
        }
        } while (!pertsonaia);

        irudiaKendu(pertsonaiakmezua);
        irudiaKendu(Gorria);
        irudiaKendu(Berdea);
        irudiaKendu(Urdina);
        irudiaKendu(Txuria);
        irudiaKendu(UrdinArgia);
        irudiaKendu(Morea);
        irudiaKendu(Naranja);
        irudiaKendu(Arrosa);
        irudiaKendu(back);
       
        irudiaKendu(mGorria);
        irudiaKendu(mBerdea);
        irudiaKendu(mUrdina);
        irudiaKendu(mTxuria);
        irudiaKendu(mUrdinArgia);
        irudiaKendu(mMorea);
        irudiaKendu(mNaranja);
        irudiaKendu(mArrosa);
        
        return pertsonaia;
    }

