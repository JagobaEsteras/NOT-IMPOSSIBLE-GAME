#include "game02.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>

//Menua


#define JOKOA_LOGOA ".\\img\\LogoSarrera.bmp"

#define JOKOA_MENUA_HOME ".\\img\\Botoiak\\casita2.bmp"
#define JOKOA_MENUA_PERCHA ".\\img\\Botoiak\\percha2.bmp"
#define JOKOA_MENUA_AJUSTES ".\\img\\Botoiak\\ajustes1.bmp"
#define JOKOA_MENUA_JOLASTU ".\\img\\Botoiak\\aurrerabotoia.bmp"
#define MUERTE ".\\img\\Elementuak\\skull.bmp"

//MUSIKA
#define JOKOA_SOUND ".\\sound\\GameSound.wav"
#define JOKOA_SOUND_WIN ".\\sound\\Irabazi.wav"
#define JOKOA_SOUND_LOOSE ".\\sound\\Galdu.wav"

//Irabazi
#define BUKAERA_IMAGE_IRABAZI ".\\img\\Winblue.bmp"
#define JOKOA_NIVEL_FLECHA ".\\img\\Botoiak\\flecha.bmp"
#define JOKOA_NIVEL_BOTON ".\\img\\Botoiak\\nivelboton.bmp"
#define JOKOA_NIVEL_ERREPIKATU ".\\img\\Botoiak\\errepikatu.bmp"

//Zirkuituak
#define FONDO ".\\img\\Zirkuituak\\zirkuitu.bmp"
#define FONDObi ".\\img\\Zirkuituak\\fondo2.bmp"
#define FONDOhiru ".\\img\\Zirkuituak\\fondo3.bmp"
#define FONDOLAU ".\\img\\Zirkuituak\\fondo4.bmp"
#define FONDOBOST ".\\img\\Zirkuituak\\fondo5.bmp"
#define FONDOsei ".\\img\\Zirkuituak\\fondo6.bmp"

//Elementuak

#define OBJEKTUA_MASCARILLA ".\\img\\Elementuak\\mascarilla.bmp"
#define AMAIERA ".\\img\\Elementuak\\Vial.bmp"
#define JOKOA_ENEMY_IMAGE ".\\img\\Elementuak\\covid.bmp"

#define JOKOA_ENEMY_CARBON ".\\img\\Elementuak\\Carbon.bmp"
#define OBJEKTUA_EGUZKIA ".\\img\\Elementuak\\Eguzkia.bmp"
#define JOKOA_ENEMY_EGUZKIA1 ".\\img\\Elementuak\\eguzkia1.bmp"

#define TOXIC ".\\img\\Elementuak\\Toxic.bmp"
#define URAHARTU ".\\img\\Elementuak\\URA1.bmp"

#define PISTOLA ".\\img\\Elementuak\\Pistola.bmp"
#define PETROLEO ".\\img\\Elementuak\\Liquido.bmp"

//Pertsonaiak

#define JOKOA_PLAYER_URDINA2 ".\\img\\personajespequenos\\PersonajeAzul.bmp"
#define JOKOA_PLAYER_GORRIA ".\\img\\personajespequenos\\PersonajeRojo.bmp"
#define JOKOA_PLAYER_URDINA ".\\img\\personajespequenos\\PersonajeAzul.bmp"
#define JOKOA_PLAYER_BERDEA ".\\img\\personajespequenos\\PersonajeVerde.bmp"
#define JOKOA_PLAYER_TXURIA ".\\img\\personajespequenos\\PersonajeBlanco.bmp"
#define JOKOA_PLAYER_NARANJA ".\\img\\personajespequenos\\PersonajeNaranja.bmp"
#define JOKOA_PLAYER_ARROSA ".\\img\\personajespequenos\\PersonajeRosa.bmp"
#define JOKOA_PLAYER_MOREA ".\\img\\personajespequenos\\PersonajeMorado.bmp"
#define JOKOA_PLAYER_URDINARGIA ".\\img\\personajespequenos\\PersonajeAzulClaro.bmp"



//mezuak
#define MEZUA_ONDO1 ".\\img\\Mezuak\\1mezuaondo.bmp"
#define MEZUA_ONDO2 ".\\img\\Mezuak\\2mezuaondo.bmp"
#define MEZUA_ONDO3 ".\\img\\Mezuak\\3mezuaondo.bmp"
#define MEZUA_ONDO4 ".\\img\\Mezuak\\4mezuaondo.bmp"
#define MEZUA_ONDO5 ".\\img\\Mezuak\\5mezuaondo.bmp"
#define MEZUA_ONDO6 ".\\img\\Mezuak\\6mezuaondo.bmp"

#define MEZUA_GAIZKI1 ".\\img\\Mezuak\\mezuagaizki_bat.bmp"
#define MEZUA_GAIZKI2 ".\\img\\Mezuak\\mezuagaizki_bi.bmp"
#define MEZUA_GAIZKI3 ".\\img\\Mezuak\\mezuagaizki_hiru.bmp"
#define MEZUA_GAIZKI4 ".\\img\\Mezuak\\mezuagaizki_lau.bmp"
#define MEZUA_GAIZKI5 ".\\img\\Mezuak\\mezuagaizki_bost.bmp"
#define MEZUA_GAIZKI6 ".\\img\\Mezuak\\mezuagaizki_sei.bmp"

int JOKOA_jokalariaIrudiaSortu(int);
POSIZIOA ERREALITATE_FISIKOA_mugimendua(POSIZIOA posizioa);
POSIZIOA ERREALITATE_FISIKOA_mugimendua_negatiboa(POSIZIOA posizioa);

int kontondo1 = 0, kontondo2 = 0, kontondo3 = 0, kontondo4 = 0, kontondo5 = 0, kontondo6 = 0, kont = 0;
int  konterror1 = 0, konterror2 = 0, konterror3 = 0, konterror4 = 0, konterror5 = 0, konterror6 = 0;
char str[10];

EGOERA bat_jokatu(int personajea) 
{
    int hasi = 0, ebentu = 0, irten = 0, atera = 0;
    
    POSIZIOA pos;
    if (kontondo1 == 0)
    {
        kontondo1 = 1;
        pantailaGarbitu();
        int motibazio = irudiaKargatu(MEZUA_ONDO1);
        int jolastu = irudiaKargatu(JOKOA_MENUA_JOLASTU);
        
        irudiaMugitu(motibazio, 85, 30);
        irudiaMugitu(jolastu, 500, 405);
        irudiakMarraztu();
        irudiaKendu(motibazio);
        irudiaKendu(jolastu);
        pantailaBerriztu();
        //Hasi
        do {
            ebentu = ebentuaJasoGertatuBada();
            if (ebentu == SAGU_BOTOIA_EZKERRA) {
                pos = saguarenPosizioa();
                if ((pos.x > 440) && (pos.x < 440 + 136) && (pos.y > 405) && (pos.y < 405 + 59))
                    hasi = 1;
            }
        } while (!hasi);
    }
        pantailaGarbitu();
        int fondo = 0;
        int xenemy[3] = { 210, 310,410 };
        int yenemy[3] = { 150,100,200 };
        int i, behera2 = 0, behera1 = 0, behera3 = 0, behera = 0, dauka = 0, karratu;
        int mugitu = 0;
        EGOERA  egoera = JOLASTEN;
        JOKO_ELEMENTUA jokalaria, enemy1, enemy2, enemy3, amaiera, objektua;
        POSIZIOA aux;
        jokalaria.pos.x = 90;
        jokalaria.pos.y = 190;
        enemy1.pos.x = xenemy[0];
        enemy1.pos.y = yenemy[0];
        enemy2.pos.x = xenemy[1];
        enemy2.pos.y = yenemy[1];
        enemy3.pos.x = xenemy[2];
        enemy3.pos.y = yenemy[2];
        objektua.pos.x = 310;
        objektua.pos.y = 200;
        amaiera.pos.x = 520;
        amaiera.pos.y = 165;
        audioInit();
        loadTheMusic(JOKOA_SOUND);
        playMusic();
        fondo = irudiaKargatu(FONDO);
        jokalaria.id = JOKOA_jokalariaIrudiaSortu(personajea);
        enemy1.id = irudiaKargatu(JOKOA_ENEMY_IMAGE);
        enemy2.id = irudiaKargatu(JOKOA_ENEMY_IMAGE);
        enemy3.id = irudiaKargatu(JOKOA_ENEMY_IMAGE);
        amaiera.id = irudiaKargatu(AMAIERA);
        objektua.id = irudiaKargatu(OBJEKTUA_MASCARILLA);
        int muerte = irudiaKargatu(MUERTE);
        int hasieraArgazki = irudiaKargatu(JOKOA_MENUA_HOME);
        irudiaMugitu(hasieraArgazki, 570, 410);
        do {
            Sleep(3);
            pantailaGarbitu();
            irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
            irudiaMugitu(enemy1.id, enemy1.pos.x, enemy1.pos.y);
            irudiaMugitu(enemy2.id, enemy2.pos.x, enemy2.pos.y);
            irudiaMugitu(enemy3.id, enemy3.pos.x, enemy3.pos.y);
            irudiaMugitu(objektua.id, objektua.pos.x, objektua.pos.y);
            irudiaMugitu(amaiera.id, amaiera.pos.x, amaiera.pos.y);
            irudiaMugitu(muerte,20,28);
            irudiakMarraztu();
            sprintf(str, "%d", kont);
            textuaIdatzi(50, 20, str);
            textuaIdatzi(51, 21, str);
            pantailaBerriztu();
            ebentu = ebentuaJasoGertatuBada();

            if (jokalaria.pos.x <= 140 && jokalaria.pos.x >= 50 && jokalaria.pos.y >= 160 && jokalaria.pos.y <= 220)karratu = 1;
            if (jokalaria.pos.x <= 140 && jokalaria.pos.x >= 50 && jokalaria.pos.y >= 220 && jokalaria.pos.y <= 250)karratu = 2;
            if (jokalaria.pos.x <= 160 && jokalaria.pos.x >= 140 && jokalaria.pos.y >= 220 && jokalaria.pos.y <= 250)karratu = 3;
            if ((jokalaria.pos.x <= 470 && jokalaria.pos.x >= 180 && jokalaria.pos.y >= 250 && jokalaria.pos.y <= 280) || (jokalaria.pos.x <= 470 && jokalaria.pos.x >= 180 && jokalaria.pos.y >= 200 && jokalaria.pos.y <= 220) || ((jokalaria.pos.x <= 470 && jokalaria.pos.x >= 180 && jokalaria.pos.y >= 110 && jokalaria.pos.y <= 160)))karratu = 4;
            if (jokalaria.pos.x <= 470 && jokalaria.pos.x >= 180 && jokalaria.pos.y >= 220 && jokalaria.pos.y <= 250)karratu = 5;
            if (jokalaria.pos.x <= 470 && jokalaria.pos.x >= 180 && jokalaria.pos.y >= 160 && jokalaria.pos.y <= 200)karratu = 6;
            if (jokalaria.pos.x <= 590 && jokalaria.pos.x >= 470 && jokalaria.pos.y >= 160 && jokalaria.pos.y <= 220)karratu = 7;
            if (ebentu == TECLA_d)
            {
                if ((karratu == 1 && jokalaria.pos.x < 140) || (karratu == 2 && jokalaria.pos.x < 140) || (karratu == 3) || (karratu == 4 && jokalaria.pos.x < 470) || (karratu == 5 && jokalaria.pos.x < 470) || (karratu == 6) || (karratu == 7 && jokalaria.pos.x < 590))
                {
                    jokalaria.pos.x = jokalaria.pos.x + 4;
                }
            }
            if (ebentu == TECLA_a)
            {
                if ((karratu == 1 && jokalaria.pos.x > 50) || (karratu == 2 && jokalaria.pos.x > 50) || (karratu == 3) || (karratu == 4 && jokalaria.pos.x > 180) || (karratu == 5) || (karratu == 6 && jokalaria.pos.x > 190) || (karratu == 7))
                {
                    jokalaria.pos.x = jokalaria.pos.x - 4;
                }
            }
            if (ebentu == TECLA_w)
            {

                if ((jokalaria.pos.y > 160 && karratu == 1) || (karratu == 2) || (karratu == 3 && jokalaria.pos.y >= 230) || (karratu == 4 && jokalaria.pos.y > 110) || (karratu == 5) || (karratu == 6) || (karratu == 7 && jokalaria.pos.y > 160))
                {
                    jokalaria.pos.y = jokalaria.pos.y - 4;
                }
            }
            if (ebentu == TECLA_s)
            {
                if ((karratu == 1 && jokalaria.pos.y < 220) || (karratu == 2 && jokalaria.pos.y < 250) || (karratu == 3 && jokalaria.pos.y <= 250) || (karratu == 4 && jokalaria.pos.y < 280) || (karratu == 5) || (karratu == 6) || (karratu == 7 && jokalaria.pos.y < 200))
                {
                    jokalaria.pos.y = jokalaria.pos.y + 4;
                }
            }
            if (enemy1.pos.y == 100 || behera1 == 0)
            {
                behera1 = 0;
                aux = ERREALITATE_FISIKOA_mugimendua(enemy1.pos);
                enemy1.pos.y = aux.y;
            }
            if (enemy1.pos.y == 280 || behera1 == 1)
            {
                behera1 = 1;
                aux = ERREALITATE_FISIKOA_mugimendua_negatiboa(enemy1.pos);
                enemy1.pos.y = aux.y;
            }
            if (enemy2.pos.y == 100 || behera2 == 0)
            {
                behera2 = 0;
                aux = ERREALITATE_FISIKOA_mugimendua(enemy2.pos);
                enemy2.pos.y = aux.y;
            }
            if (enemy2.pos.y == 280 || behera2 == 1)
            {
                behera2 = 1;
                aux = ERREALITATE_FISIKOA_mugimendua_negatiboa(enemy2.pos);
                enemy2.pos.y = aux.y;
            }
            if (enemy3.pos.y == 100 || behera3 == 0)
            {
                behera3 = 0;
                aux = ERREALITATE_FISIKOA_mugimendua(enemy3.pos);
                enemy3.pos.y = aux.y;
            }
            if (enemy3.pos.y == 280 || behera3 == 1)
            {
                behera3 = 1;
                aux = ERREALITATE_FISIKOA_mugimendua_negatiboa(enemy3.pos);
                enemy3.pos.y = aux.y;
            }
            if (mugitu) {
                aux = ERREALITATE_FISIKOA_mugimendua(jokalaria.pos);
                jokalaria.pos.x = aux.x;
            }
            if ((jokalaria.pos.x > objektua.pos.x - 15 && jokalaria.pos.x <objektua.pos.x + 15 && jokalaria.pos.y >objektua.pos.y - 15 && jokalaria.pos.y < objektua.pos.y + 15) && (dauka == 0))
            {
                dauka = 1;
                irudiaKendu(objektua.id);
            }
            egoera = JOKOA_egoera_1(jokalaria, enemy1, enemy2, enemy3, amaiera, dauka);

            if (ebentu == SAGU_BOTOIA_EZKERRA) {
                pos = saguarenPosizioa();
                if ((pos.x > 570) && (pos.x < 570 + 43) && (pos.y > 410) && (pos.y < 453)) egoera = ATERA;
            }
           
        } while (egoera == JOLASTEN);

        if (egoera == GALDU)kont++;
        irudiaKendu(jokalaria.id);
        irudiaKendu(enemy1.id);
        irudiaKendu(enemy2.id);
        irudiaKendu(enemy3.id);
        irudiaKendu(amaiera.id);
        irudiaKendu(fondo);
        irudiaKendu(hasieraArgazki);
        irudiaKendu(muerte);

        if (dauka == 0)irudiaKendu(objektua.id);
        toggleMusic();
        audioTerminate();
        pantailaGarbitu();
        pantailaBerriztu();
        return egoera;
   
}
EGOERA bi_jokatu(int personajea)
{
    int hasi = 0, irten = 0, ebentu = 0, atera = 0, motibazio = 0 , jolastu = 0;
    POSIZIOA pos;
    //esaldia
    if (kontondo2 == 0)
    {
        kontondo2 = 1;
        pantailaGarbitu();
        motibazio = irudiaKargatu(MEZUA_ONDO2);
        jolastu = irudiaKargatu(JOKOA_MENUA_JOLASTU);
        irudiaMugitu(motibazio, 30, 30);
        irudiaMugitu(jolastu, 500, 405);
        irudiakMarraztu();
        irudiaKendu(motibazio);
        irudiaKendu(jolastu);
        pantailaBerriztu();
        //Hasi
        do {
            ebentu = ebentuaJasoGertatuBada();
            if (ebentu == SAGU_BOTOIA_EZKERRA) {
                pos = saguarenPosizioa();
                if ((pos.x > 440) && (pos.x < 440 + 136) && (pos.y > 405) && (pos.y < 405 + 59))
                    hasi = 1;
            }
        } while (!hasi);
    }
        pantailaGarbitu();
        int xenemy[6] = { 180, 275,370, 180, 180, 465 };
        int yenemy[6] = { 110,110,110, 120, 270, 110 };
        int behera = 0, ezkerra = 0;
        int mugitu = 0, dauka = 0, karratu, fondobi;
        EGOERA  egoera = JOLASTEN;
        JOKO_ELEMENTUA jokalaria, enemy1, enemy2, enemy3, enemy4, enemy5, enemy6, amaiera, objektua;
        POSIZIOA aux; 
        fondobi=irudiaKargatu(FONDObi);
        jokalaria.pos.x = 90;
        jokalaria.pos.y = 205;
        enemy1.pos.x = xenemy[0];
        enemy1.pos.y = yenemy[0];
        enemy2.pos.x = xenemy[1];
        enemy2.pos.y = yenemy[1];
        enemy3.pos.x = xenemy[2];
        enemy3.pos.y = yenemy[2];
        enemy4.pos.x = xenemy[3];
        enemy4.pos.y = yenemy[3];
        enemy5.pos.x = xenemy[4];
        enemy5.pos.y = yenemy[4];
        enemy6.pos.x = xenemy[5];
        enemy6.pos.y = yenemy[5];
        
        objektua.pos.x = 310;
        objektua.pos.y = 200;
        audioInit();
        loadTheMusic(JOKOA_SOUND);
        playMusic();
        jokalaria.id = JOKOA_jokalariaIrudiaSortu(personajea);
        enemy1.id = irudiaKargatu(JOKOA_ENEMY_CARBON);
        enemy2.id = irudiaKargatu(JOKOA_ENEMY_CARBON);
        enemy3.id = irudiaKargatu(JOKOA_ENEMY_CARBON);
        enemy4.id = irudiaKargatu(JOKOA_ENEMY_CARBON);
        enemy5.id = irudiaKargatu(JOKOA_ENEMY_CARBON);
        enemy6.id = irudiaKargatu(JOKOA_ENEMY_CARBON);
        
        objektua.id = irudiaKargatu(OBJEKTUA_EGUZKIA);
        int hasieraArgazki = irudiaKargatu(JOKOA_MENUA_HOME);
        int muerte = irudiaKargatu(MUERTE);
        irudiaMugitu(hasieraArgazki, 570, 410);
       
        do {
            Sleep(3);
            pantailaGarbitu();
           
            irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
            irudiaMugitu(enemy1.id, enemy1.pos.x, enemy1.pos.y);
            irudiaMugitu(enemy2.id, enemy2.pos.x, enemy2.pos.y);
            irudiaMugitu(enemy3.id, enemy3.pos.x, enemy3.pos.y);
            irudiaMugitu(enemy4.id, enemy4.pos.x, enemy4.pos.y);
            irudiaMugitu(enemy5.id, enemy5.pos.x, enemy5.pos.y);
            irudiaMugitu(enemy6.id, enemy6.pos.x, enemy6.pos.y);
            irudiaMugitu(objektua.id, objektua.pos.x, objektua.pos.y);
            irudiaMugitu(muerte, 20,28);
            irudiakMarraztu();
            sprintf(str, "%d", kont);
            textuaIdatzi(50, 20, str);
            textuaIdatzi(51, 21, str);
            pantailaBerriztu();
            ebentu = ebentuaJasoGertatuBada();
            if (jokalaria.pos.x <= 570 && jokalaria.pos.x >= 70 && jokalaria.pos.y >= 160 && jokalaria.pos.y <= 240)
            {
                karratu = 1;
            }
            if (jokalaria.pos.x <= 500 && jokalaria.pos.x >= 115 && jokalaria.pos.y >= 90 && jokalaria.pos.y <= 160)
            {
                karratu = 2;
            }
            if (jokalaria.pos.x <= 500 && jokalaria.pos.x >= 115 && jokalaria.pos.y >= 160 && jokalaria.pos.y <= 260)
            {
                karratu = 3;
            }
            if (jokalaria.pos.x <= 500 && jokalaria.pos.x >= 115 && jokalaria.pos.y >= 260 && jokalaria.pos.y <= 305)
            {
                karratu = 4;
            }
            if (ebentu == TECLA_d)
            {
                if ((karratu == 1 && jokalaria.pos.x < 570) || (karratu == 2 && jokalaria.pos.x < 500) || (karratu == 3) || (karratu == 4 && jokalaria.pos.x < 500))
                {
                    jokalaria.pos.x = jokalaria.pos.x + 4;
                }
            }
            if (ebentu == TECLA_a)
            {
                if ((karratu == 1 && jokalaria.pos.x > 70) || (karratu == 2 && jokalaria.pos.x > 115) || (karratu == 3) || (karratu == 4 && jokalaria.pos.x > 115))
                {
                    jokalaria.pos.x = jokalaria.pos.x - 4;
                }
            }
            if (ebentu == TECLA_w)
            {
                if ((karratu == 1 && jokalaria.pos.y > 160) || (karratu == 2 && jokalaria.pos.y > 90) || (karratu == 3) || (karratu == 4))
                {
                    jokalaria.pos.y = jokalaria.pos.y - 4;
                }
            }
            if (ebentu == TECLA_s)
            {
                if ((karratu == 1 && jokalaria.pos.y < 240) || (karratu == 2) || (karratu == 3) || (karratu == 4 && jokalaria.pos.y < 305))
                {
                    jokalaria.pos.y = jokalaria.pos.y + 4;
                }
            }
            if (enemy1.pos.y == 90 || behera == 0)
            {
                behera = 0;
                aux = ERREALITATE_FISIKOA_mugimendua(enemy1.pos);
                enemy1.pos.y = aux.y;
            }
            if (enemy1.pos.y == 300 || behera == 1)
            {
                behera = 1;
                aux = ERREALITATE_FISIKOA_mugimendua_negatiboa(enemy1.pos);
                enemy1.pos.y = aux.y;
            }
            if (enemy2.pos.y == 90 || behera == 0)
            {
                behera = 0;
                aux = ERREALITATE_FISIKOA_mugimendua(enemy2.pos);
                enemy2.pos.y = aux.y;
            }
            if (enemy2.pos.y == 300 || behera == 1)
            {
                behera = 1;
                aux = ERREALITATE_FISIKOA_mugimendua_negatiboa(enemy2.pos);
                enemy2.pos.y = aux.y;
            }
            if (enemy3.pos.y == 90 || behera == 0)
            {
                behera = 0;
                aux = ERREALITATE_FISIKOA_mugimendua(enemy3.pos);
                enemy3.pos.y = aux.y;
            }
            if (enemy3.pos.y == 300 || behera == 1)
            {
                behera = 1;
                aux = ERREALITATE_FISIKOA_mugimendua_negatiboa(enemy3.pos);
                enemy3.pos.y = aux.y;
            }
            if (enemy4.pos.x == 120 || ezkerra == 0)
            {
                ezkerra = 0;
                aux = ERREALITATE_FISIKOA_mugimendua(enemy4.pos);
                enemy4.pos.x = aux.x;
            }
            if (enemy4.pos.x == 490 || ezkerra == 1)
            {
                ezkerra = 1;
                aux = ERREALITATE_FISIKOA_mugimendua_negatiboa(enemy4.pos);
                enemy4.pos.x = aux.x;
            }
            if (enemy5.pos.x == 120 || ezkerra == 0)
            {
                ezkerra = 0;
                aux = ERREALITATE_FISIKOA_mugimendua(enemy5.pos);
                enemy5.pos.x = aux.x;
            }
            if (enemy5.pos.x == 490 || ezkerra == 1)
            {
                ezkerra = 1;
                aux = ERREALITATE_FISIKOA_mugimendua_negatiboa(enemy5.pos);
                enemy5.pos.x = aux.x;
            }
            if (enemy6.pos.y == 90 || behera == 0)
            {
                behera = 0;
                aux = ERREALITATE_FISIKOA_mugimendua(enemy6.pos);
                enemy6.pos.y = aux.y;
            }
            if (enemy6.pos.y == 300 || behera == 1)
            {
                behera = 1;
                aux = ERREALITATE_FISIKOA_mugimendua_negatiboa(enemy6.pos);
                enemy6.pos.y = aux.y;
            }
            if ((jokalaria.pos.x > objektua.pos.x - 15 && jokalaria.pos.x <objektua.pos.x + 15 && jokalaria.pos.y >objektua.pos.y - 15 && jokalaria.pos.y < objektua.pos.y + 15) && (dauka == 0))
            {
                dauka = 1;
                irudiaKendu(objektua.id);
            }
            if (mugitu) {
                aux = ERREALITATE_FISIKOA_mugimendua(jokalaria.pos);
                jokalaria.pos.x = aux.x;
            }
            egoera = JOKOA_egoera_2(jokalaria, enemy1, enemy2, enemy3, enemy4, enemy5,enemy6);
            if (ebentu == SAGU_BOTOIA_EZKERRA) {
                pos = saguarenPosizioa();
                if ((pos.x > 570) && (pos.x < 570 + 43) && (pos.y > 410) && (pos.y < 453)) egoera = ATERA;
            }
        } while (egoera == JOLASTEN);

        if (egoera == GALDU)kont++;
        irudiaKendu(jokalaria.id);
        irudiaKendu(enemy1.id);
        irudiaKendu(enemy2.id);
        irudiaKendu(enemy3.id);
        irudiaKendu(enemy4.id);
        irudiaKendu(enemy5.id);
        irudiaKendu(enemy6.id);
        
        irudiaKendu(hasieraArgazki);
        irudiaKendu(fondobi);
        irudiaKendu(muerte);
        if (dauka == 0)irudiaKendu(objektua.id);
        toggleMusic();
        audioTerminate();
        pantailaGarbitu();
        pantailaBerriztu();
        return egoera;
}
EGOERA hiru_jokatu(int personajea)
{
    int hasi = 0, ebentu = 0, irten = 0, atera = 0, motibazio = 0, jolastu = 0;
    POSIZIOA pos;
    //esaldia
    if (kontondo3 == 0)
    {
        kontondo3 = 1;

        pantailaGarbitu();
        motibazio = irudiaKargatu(MEZUA_ONDO3);
        jolastu = irudiaKargatu(JOKOA_MENUA_JOLASTU);
        irudiaMugitu(motibazio, 30, 30);
        irudiaMugitu(jolastu, 500, 405);
        irudiakMarraztu();
        irudiaKendu(motibazio);
        irudiaKendu(jolastu);
        pantailaBerriztu();
        //Hasi
        do {
            ebentu = ebentuaJasoGertatuBada();
            if (ebentu == SAGU_BOTOIA_EZKERRA) {
                pos = saguarenPosizioa();
                if ((pos.x > 440) && (pos.x < 440 + 136) && (pos.y > 405) && (pos.y < 405 + 59))
                    hasi = 1;
            }
        } while (!hasi);
    }
        pantailaGarbitu();
        int xenemy[1] = { 330 };
        int yenemy[1] = { 250 };
        int i, behera = 0, ezkerra = 0, karratu = 1,fondohiru;
        int mugitu = 0, dauka = 0;
        EGOERA  egoera = JOLASTEN;
        float t = 0;
        JOKO_ELEMENTUA jokalaria, enemy1, enemy2, enemy3, amaiera, objektua;
        POSIZIOA aux;

        fondohiru=irudiaKargatu(FONDOhiru);
        jokalaria.pos.x = 340;
        jokalaria.pos.y = 100;
        enemy1.pos.x = xenemy[0];
        enemy1.pos.y = yenemy[0];
        enemy2.pos.x = xenemy[0];
        enemy2.pos.y = yenemy[0];
        enemy3.pos.x = xenemy[0];
        enemy3.pos.y = yenemy[0];
        
        objektua.pos.x = 330;
        objektua.pos.y = 250;
        audioInit();
        loadTheMusic(JOKOA_SOUND);
        playMusic();
        jokalaria.id = JOKOA_jokalariaIrudiaSortu(personajea);
        enemy1.id = irudiaKargatu(TOXIC);
        enemy2.id = irudiaKargatu(TOXIC);
        enemy3.id = irudiaKargatu(TOXIC);
        
        objektua.id = irudiaKargatu(URAHARTU);
        int hasieraArgazki = irudiaKargatu(JOKOA_MENUA_HOME);
        int muerte = irudiaKargatu(MUERTE);
        irudiaMugitu(hasieraArgazki, 570, 410);
        do {
            Sleep(3);
            pantailaGarbitu();
            arkatzKoloreaEzarri(100, 100, 100);
            irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
            irudiaMugitu(enemy1.id, enemy1.pos.x, enemy1.pos.y);
            irudiaMugitu(enemy2.id, enemy2.pos.x, enemy2.pos.y);
            irudiaMugitu(enemy3.id, enemy3.pos.x, enemy3.pos.y);
            
            irudiaMugitu(objektua.id, objektua.pos.x, objektua.pos.y);
            irudiaMugitu(muerte, 20, 28);
            irudiakMarraztu();
            sprintf(str, "%d", kont);
            textuaIdatzi(50, 20, str);
            textuaIdatzi(51, 21, str);
            
            pantailaBerriztu();
            ebentu = ebentuaJasoGertatuBada();
            //Personaje mugitu
            if (jokalaria.pos.x <= 350 && jokalaria.pos.x >= 315 && jokalaria.pos.y >= 75 && jokalaria.pos.y <= 125)
            {
                karratu = 1;
            }
            if ((jokalaria.pos.x <= 300 && jokalaria.pos.x >= 285 && jokalaria.pos.y >= 145 && jokalaria.pos.y <= 160) || (jokalaria.pos.x <= 270 && jokalaria.pos.x >= 255 && jokalaria.pos.y >= 175 && jokalaria.pos.y <= 190) || (jokalaria.pos.x <= 240 && jokalaria.pos.x >= 225 && jokalaria.pos.y >= 205 && jokalaria.pos.y <= 220))
            {
                karratu = 2;
            }
            if ((jokalaria.pos.x <= 240 && jokalaria.pos.x >= 225 && jokalaria.pos.y >= 280 && jokalaria.pos.y <= 295) || (jokalaria.pos.x <= 270 && jokalaria.pos.x >= 255 && jokalaria.pos.y >= 310 && jokalaria.pos.y <= 325) || (jokalaria.pos.x <= 300 && jokalaria.pos.x >= 285 && jokalaria.pos.y >= 340 && jokalaria.pos.y <= 355))
            {
                karratu = 3;
            }
            if ((jokalaria.pos.x <= 440 && jokalaria.pos.x >= 425 && jokalaria.pos.y >= 280 && jokalaria.pos.y <= 295) || (jokalaria.pos.x <= 410 && jokalaria.pos.x >= 395 && jokalaria.pos.y >= 310 && jokalaria.pos.y <= 325) || (jokalaria.pos.x <= 380 && jokalaria.pos.x >= 365 && jokalaria.pos.y >= 340 && jokalaria.pos.y <= 355))
            {
                karratu = 4;
            }
            if ((jokalaria.pos.x <= 380 && jokalaria.pos.x >= 365 && jokalaria.pos.y >= 145 && jokalaria.pos.y <= 160) || (jokalaria.pos.x <= 410 && jokalaria.pos.x >= 395 && jokalaria.pos.y >= 175 && jokalaria.pos.y <= 190) || (jokalaria.pos.x <= 440 && jokalaria.pos.x >= 425 && jokalaria.pos.y >= 205 && jokalaria.pos.y <= 220))
            {
                karratu = 5;
            }
            if ((jokalaria.pos.x <= 350 && jokalaria.pos.x >= 315 && jokalaria.pos.y >= 145 && jokalaria.pos.y <= 160) || (jokalaria.pos.x <= 380 && jokalaria.pos.x >= 285 && jokalaria.pos.y >= 175 && jokalaria.pos.y <= 190) || (jokalaria.pos.x <= 350 && jokalaria.pos.x >= 255 && jokalaria.pos.y >= 205 && jokalaria.pos.y <= 220) || (jokalaria.pos.x <= 440 && jokalaria.pos.x >= 225 && jokalaria.pos.y >= 230 && jokalaria.pos.y <= 265) || (jokalaria.pos.x <= 410 && jokalaria.pos.x >= 255 && jokalaria.pos.y >= 280 && jokalaria.pos.y <= 295) || (jokalaria.pos.x <= 380 && jokalaria.pos.x >= 285 && jokalaria.pos.y >= 310 && jokalaria.pos.y <= 325) || (jokalaria.pos.x <= 350 && jokalaria.pos.x >= 315 && jokalaria.pos.y >= 340 && jokalaria.pos.y <= 355))
            {
                karratu = 6;
            }
            if (jokalaria.pos.x <= 210 && jokalaria.pos.x >= 155 && jokalaria.pos.y >= 230 && jokalaria.pos.y <= 265)
            {
                karratu = 7;
            }
            if (ebentu == TECLA_d)
            {
                if ((karratu == 1 && jokalaria.pos.x < 350) || (karratu == 2) || (karratu == 3) || (karratu == 4 && jokalaria.pos.y < 295 && jokalaria.pos.x < 440) || (karratu == 4 && jokalaria.pos.y < 325 && jokalaria.pos.x < 410) || (karratu == 4 && jokalaria.pos.y < 355 && jokalaria.pos.x < 380) || (karratu == 5 && jokalaria.pos.y > 205 && jokalaria.pos.x < 440) || (karratu == 5 && jokalaria.pos.y > 175 && jokalaria.pos.x < 410) || (karratu == 5 && jokalaria.pos.y > 145 && jokalaria.pos.x < 380) || (karratu == 6 && jokalaria.pos.x < 440) || (karratu == 7))
                {
                    jokalaria.pos.x = jokalaria.pos.x + 4;
                }
            }
            if (ebentu == TECLA_a)
            {
                if ((karratu == 1 && jokalaria.pos.x > 315) || (karratu == 2 && jokalaria.pos.y > 145 && jokalaria.pos.x > 285) || (karratu == 2 && jokalaria.pos.y > 175 && jokalaria.pos.x > 255) || (karratu == 2 && jokalaria.pos.y > 205 && jokalaria.pos.x > 225) || (karratu == 3 && jokalaria.pos.y < 295 && jokalaria.pos.x > 225) || (karratu == 3 && jokalaria.pos.y < 325 && jokalaria.pos.x > 255) || (karratu == 3 && jokalaria.pos.y < 355 && jokalaria.pos.x > 285) || (karratu == 4) || (karratu == 5) || (karratu == 6) || (karratu == 7 && jokalaria.pos.x > 155))
                {
                    jokalaria.pos.x = jokalaria.pos.x - 4;
                }
            }
            if (ebentu == TECLA_w)
            {
                if ((karratu == 1 && jokalaria.pos.y > 75) || (karratu == 2 && jokalaria.pos.y > 145 && jokalaria.pos.x > 285) || (karratu == 2 && jokalaria.pos.y > 175 && jokalaria.pos.x > 255) || (karratu == 2 && jokalaria.pos.y > 205 && jokalaria.pos.x > 225) || (karratu == 3) || (karratu == 4) || (karratu == 5 && jokalaria.pos.y > 205 && jokalaria.pos.x < 440) || (karratu == 5 && jokalaria.pos.y > 175 && jokalaria.pos.x < 410) || (karratu == 5 && jokalaria.pos.y > 145 && jokalaria.pos.x < 380) || (karratu == 6) || (karratu == 7 && jokalaria.pos.y > 230))
                {
                    jokalaria.pos.y = jokalaria.pos.y - 4;
                }
            }
            if (ebentu == TECLA_s)
            {
                if ((karratu == 1) || (karratu == 2) || (karratu == 3 && jokalaria.pos.y < 295 && jokalaria.pos.x > 225) || (karratu == 3 && jokalaria.pos.y < 325 && jokalaria.pos.x > 255) || (karratu == 3 && jokalaria.pos.y < 350 && jokalaria.pos.x > 285) || (karratu == 4 && jokalaria.pos.y < 295 && jokalaria.pos.x < 440) || (karratu == 4 && jokalaria.pos.y < 325 && jokalaria.pos.x < 410) || (karratu == 4 && jokalaria.pos.y < 350 && jokalaria.pos.x < 380) || (karratu == 5) || (karratu == 6 && jokalaria.pos.y < 350) || (karratu == 7 && jokalaria.pos.y < 265))
                {
                    jokalaria.pos.y = jokalaria.pos.y + 4;
                }
            }
            t = t + 0.013;
            enemy1.pos.x = 330 + 95 * cos(t);
            enemy1.pos.y = 250 + 95 * sin(t);
            enemy2.pos.x = (330 + 65 * cos(t) * -1);
            enemy2.pos.y = (250 + 65 * sin(t));
            enemy3.pos.x = 330 + 35 * cos(t);
            enemy3.pos.y = 250 + 35 * sin(t);
            if ((jokalaria.pos.x > objektua.pos.x - 15 && jokalaria.pos.x <objektua.pos.x + 15 && jokalaria.pos.y >objektua.pos.y - 15 && jokalaria.pos.y < objektua.pos.y + 15) && (dauka == 0))
            {
                dauka = 1;
                irudiaKendu(objektua.id);
            }
            if (mugitu) {
                aux = ERREALITATE_FISIKOA_mugimendua(jokalaria.pos);
                jokalaria.pos.x = aux.x;
            }
            egoera = JOKOA_egoera_3(jokalaria, enemy1, enemy2, enemy3, dauka);
            if (ebentu == SAGU_BOTOIA_EZKERRA) {
                pos = saguarenPosizioa();
                if ((pos.x > 570) && (pos.x < 570 + 43) && (pos.y > 410) && (pos.y < 453)) egoera = ATERA;
            }
        } while (egoera == JOLASTEN);

        if (egoera == GALDU)kont++;
        irudiaKendu(jokalaria.id);
        irudiaKendu(enemy1.id);
        irudiaKendu(enemy2.id);
        irudiaKendu(enemy3.id);
        
        irudiaKendu(hasieraArgazki);
        irudiaKendu(muerte);
        if (dauka == 0)irudiaKendu(objektua.id);
        irudiaKendu(fondohiru);
        toggleMusic();
        audioTerminate();
        pantailaGarbitu();
        pantailaBerriztu();
        return egoera;
    }
EGOERA lau_jokatu(int personajea)
{
    int hasi = 0, ebentu = 0, irten = 0, atera = 0, motibazio =0,jolastu=0;
    POSIZIOA pos;
    
    if (kontondo4 == 0)
    {
        kontondo4 = 1;
        pantailaGarbitu();
        motibazio = irudiaKargatu(MEZUA_ONDO4);
        jolastu = irudiaKargatu(JOKOA_MENUA_JOLASTU);
        irudiaMugitu(motibazio, 30, 30);
        irudiaMugitu(jolastu, 500, 405);
        irudiakMarraztu();
        pantailaBerriztu();
        do {
            ebentu = ebentuaJasoGertatuBada();
            if (ebentu == SAGU_BOTOIA_EZKERRA) {
                pos = saguarenPosizioa();
                if ((pos.x > 440) && (pos.x < 440 + 136) && (pos.y > 405) && (pos.y < 405 + 59))
                    hasi = 1;
            }
        } while (!hasi);
        irudiaKendu(motibazio);
        irudiaKendu(jolastu);
        pantailaBerriztu();
    }
        pantailaGarbitu();
        int xenemy[2] = { 220, 500 };
        int yenemy[2] = { 50,350 };
        int i,dauka=0,obj=0, behera1 = 0, behera2 = 0, ezkerra1 = 0, ezkerra2 = 0, fondo4=0;
        int mugitu = 0, karratu, fondobi; //boolean
        EGOERA  egoera = JOLASTEN;
        JOKO_ELEMENTUA jokalaria, enemy1, enemy2, amaiera, objektua, objektua2;
        POSIZIOA aux;
        jokalaria.pos.x = 135;
        jokalaria.pos.y = 100;
        enemy1.pos.x = xenemy[0];
        enemy1.pos.y = yenemy[0];
        enemy2.pos.x = xenemy[1];
        enemy2.pos.y = yenemy[1];
        amaiera.pos.x = 135;
        amaiera.pos.y = 300;
        objektua.pos.x = 530;
        objektua.pos.y = 56;
        objektua2.pos.x = 530;
        objektua2.pos.y = 345;
        audioInit();
        loadTheMusic(JOKOA_SOUND);
        playMusic();
        fondo4 = irudiaKargatu(FONDOLAU);
        enemy1.id = irudiaKargatu(JOKOA_ENEMY_IMAGE);
        enemy2.id = irudiaKargatu(JOKOA_ENEMY_IMAGE);
        amaiera.id = irudiaKargatu(AMAIERA);
        objektua.id = irudiaKargatu(OBJEKTUA_MASCARILLA);
        objektua2.id = irudiaKargatu(OBJEKTUA_MASCARILLA);
        int hasieraArgazki = irudiaKargatu(JOKOA_MENUA_HOME);
        int muerte = irudiaKargatu(MUERTE);
        jokalaria.id = JOKOA_jokalariaIrudiaSortu(personajea);
        irudiaMugitu(hasieraArgazki, 570, 410);
        do {
            Sleep(3);
            pantailaGarbitu();
            irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
            irudiaMugitu(enemy1.id, enemy1.pos.x, enemy1.pos.y);
            irudiaMugitu(enemy2.id, enemy2.pos.x, enemy2.pos.y);
            irudiaMugitu(amaiera.id, amaiera.pos.x, amaiera.pos.y);
            irudiaMugitu(objektua.id, objektua.pos.x, objektua.pos.y);
            irudiaMugitu(objektua2.id, objektua2.pos.x, objektua2.pos.y);
            irudiaMugitu(muerte, 20, 28);
            irudiakMarraztu();
            sprintf(str, "%d", kont);
            textuaIdatzi(50, 20, str);
            textuaIdatzi(51, 21, str);
            pantailaBerriztu();
            ebentu = ebentuaJasoGertatuBada();
            
            if (jokalaria.pos.x <= 430 && jokalaria.pos.x >= 95 && jokalaria.pos.y >= 56 && jokalaria.pos.y <= 140)
            {
                karratu = 1;
            }
            if (jokalaria.pos.x <= 555 && jokalaria.pos.x >= 443 && jokalaria.pos.y >= 56 && jokalaria.pos.y <= 140)
            {
                karratu = 2;
            }
            if (jokalaria.pos.x <= 555 && jokalaria.pos.x >= 443 && jokalaria.pos.y >= 150 && jokalaria.pos.y <= 260)
            {
                karratu = 3;
            }
            if (jokalaria.pos.x <= 555 && jokalaria.pos.x >= 443 && jokalaria.pos.y >= 276 && jokalaria.pos.y <= 360)
            {
                karratu = 4;
            }
            if (jokalaria.pos.x <= 430 && jokalaria.pos.x >= 95 && jokalaria.pos.y >= 276 && jokalaria.pos.y <= 360)
            {
                karratu = 5;
            }
            if (enemy1.pos.x == 190 || ezkerra1 == 0)
            {
                ezkerra1 = 0;
                if (enemy1.pos.y == 50 || behera1 == 0)
                {
                    behera1 = 0;
                    aux = ERREALITATE_FISIKOA_mugimendua(enemy1.pos);
                    enemy1.pos.y = aux.y;
                    enemy1.pos.x = aux.x;
                }
                if (enemy1.pos.y == 140 || behera1 == 1)
                {
                    behera1 = 1;
                    aux = ERREALITATE_FISIKOA_mugimendua_negatiboa(enemy1.pos);
                    enemy1.pos.y = aux.y;
                    aux = ERREALITATE_FISIKOA_mugimendua(enemy1.pos);
                    enemy1.pos.x = aux.x;
                }
            }
            if (enemy1.pos.x == 550 || ezkerra1 == 1)
            {
                ezkerra1 = 1;
                if (enemy1.pos.y == 50 || behera1 == 0)
                {
                    behera1 = 0;
                    aux = ERREALITATE_FISIKOA_mugimendua(enemy1.pos);
                    enemy1.pos.y = aux.y;
                    aux = ERREALITATE_FISIKOA_mugimendua_negatiboa(enemy1.pos);
                    enemy1.pos.x = aux.x;
                }
                if (enemy1.pos.y == 140 || behera1 == 1)
                {
                    behera1 = 1;
                    aux = ERREALITATE_FISIKOA_mugimendua_negatiboa(enemy1.pos);
                    enemy1.pos.y = aux.y;
                    enemy1.pos.x = aux.x;
                }
            }
            if (enemy2.pos.x == 190 || ezkerra2 == 0)
            {
                ezkerra2 = 0;
                if (enemy2.pos.y == 260 || behera2 == 0)
                {
                    behera2 = 0;
                    aux = ERREALITATE_FISIKOA_mugimendua(enemy2.pos);
                    enemy2.pos.y = aux.y;
                    enemy2.pos.x = aux.x;
                }
                if (enemy2.pos.y == 361 || behera2 == 1)
                {
                    behera2 = 1;
                    aux = ERREALITATE_FISIKOA_mugimendua_negatiboa(enemy2.pos);
                    enemy2.pos.y = aux.y;
                    aux = ERREALITATE_FISIKOA_mugimendua(enemy2.pos);
                    enemy2.pos.x = aux.x;
                }
            }
            if (enemy2.pos.x == 550 || ezkerra2 == 1)
            {
                ezkerra2 = 1;
                if (enemy2.pos.y == 260 || behera2 == 0)
                {
                    behera2 = 0;
                    aux = ERREALITATE_FISIKOA_mugimendua(enemy2.pos);
                    enemy2.pos.y = aux.y;
                    aux = ERREALITATE_FISIKOA_mugimendua_negatiboa(enemy2.pos);
                    enemy2.pos.x = aux.x;
                }
                if (enemy2.pos.y == 361 || behera2 == 1)
                {
                    behera2 = 1;
                    aux = ERREALITATE_FISIKOA_mugimendua_negatiboa(enemy2.pos);
                    enemy2.pos.y = aux.y;
                    enemy2.pos.x = aux.x;
                }
            }
            if (ebentu == TECLA_d)
            {
                if ((karratu == 1) || ((karratu == 2 || karratu == 3 || karratu == 4) && jokalaria.pos.x < 555) || (karratu == 5))
                {
                    jokalaria.pos.x = jokalaria.pos.x + 4;
                }
            }
            if (ebentu == TECLA_a)
            {
                if (((karratu == 1 || karratu == 5) && jokalaria.pos.x > 95) || (karratu == 2) || (karratu == 3 && jokalaria.pos.x > 443) || (karratu == 4))
                {
                    jokalaria.pos.x = jokalaria.pos.x - 4;
                }
            }
            if (ebentu == TECLA_w)
            {
                if (((karratu == 1 || karratu == 2) && jokalaria.pos.y > 56) || (karratu == 3) || (karratu == 4) || (karratu == 5 && jokalaria.pos.y > 276))
                {
                    jokalaria.pos.y = jokalaria.pos.y - 4;
                }
            }
            if (ebentu == TECLA_s)
            {
                if ((karratu == 1 && jokalaria.pos.y < 140) || (karratu == 2) || (karratu == 3) || ((karratu == 4 || karratu == 5) && jokalaria.pos.y < 360))
                {
                    jokalaria.pos.y = jokalaria.pos.y + 4;
                }
            }
            if (mugitu)
            {
                aux = ERREALITATE_FISIKOA_mugimendua(jokalaria.pos);
                jokalaria.pos.x = aux.x;
            }
            if ((jokalaria.pos.x > objektua.pos.x - 15 && jokalaria.pos.x <objektua.pos.x + 15 && jokalaria.pos.y >objektua.pos.y - 15 && jokalaria.pos.y < objektua.pos.y + 15) && (dauka == 0 || dauka == 2) && (obj < 2))
            {
                dauka = 1;
                obj++;
                irudiaKendu(objektua.id);
            }
            if ((jokalaria.pos.x > objektua2.pos.x - 15 && jokalaria.pos.x <objektua2.pos.x + 15 && jokalaria.pos.y >objektua2.pos.y - 15 && jokalaria.pos.y < objektua2.pos.y + 15) && (dauka == 1 || dauka == 0) && (obj < 2))
            {
                dauka = 2;
                obj++;
                irudiaKendu(objektua2.id);
            }
            egoera = JOKOA_egoera_4(jokalaria, enemy1, enemy2, amaiera,obj);
            if (ebentu == SAGU_BOTOIA_EZKERRA) {
                pos = saguarenPosizioa();
                if ((pos.x > 570) && (pos.x < 570 + 43) && (pos.y > 410) && (pos.y < 453)) egoera = ATERA;
            }
        } while (egoera == JOLASTEN);
        
        if (egoera == GALDU)kont++;

        if (dauka == 0) {
            irudiaKendu(objektua.id);
            irudiaKendu(objektua2.id);
        }
        if ((dauka == 1) && (obj < 2))irudiaKendu(objektua2.id);
        if ((dauka == 2) && (obj < 2))irudiaKendu(objektua.id);
       

        irudiaKendu(jokalaria.id);
        irudiaKendu(enemy1.id);
        irudiaKendu(enemy2.id);
        irudiaKendu(amaiera.id);
        irudiaKendu(fondo4);
        irudiaKendu(hasieraArgazki);
        irudiaKendu(muerte);
        toggleMusic();
        audioTerminate();
        pantailaGarbitu();
        pantailaBerriztu();
        return egoera;
    }
EGOERA bost_jokatu(int personajea){
       
        int hasi = 0, ebentu = 0, irten = 0, atera = 0,motibazio=0,jolastu=0, fondo5;
        POSIZIOA pos;
       
        if (kontondo5 == 0)
        {
            kontondo5 = 1;
            pantailaGarbitu();
            motibazio = irudiaKargatu(MEZUA_ONDO5);
            jolastu = irudiaKargatu(JOKOA_MENUA_JOLASTU);
            irudiaMugitu(motibazio, 30, 30);
            irudiaMugitu(jolastu, 500, 405);
            irudiakMarraztu();
            pantailaBerriztu();
            //Hasi
            do {
                ebentu = ebentuaJasoGertatuBada();
                if (ebentu == SAGU_BOTOIA_EZKERRA) {
                    pos = saguarenPosizioa();
                    if ((pos.x > 440) && (pos.x < 440 + 136) && (pos.y > 405) && (pos.y < 405 + 59))
                        hasi = 1;
                }
            } while (!hasi);
            irudiaKendu(motibazio);
            irudiaKendu(jolastu);
            pantailaBerriztu();
        }
            pantailaGarbitu();
            int xenemy[4] = { 510,510,510, 510 };
            int yenemy[4] = { 200,240,280,320 };
            int i, behera = 0, ezkerra = 0, karratu = 1, aurreratua = 0, fondohiru;
            int mugitu = 0, dauka = 0; //boolean
            EGOERA  egoera = JOLASTEN;
            float t = 0;
            int  fondo;
            JOKO_ELEMENTUA jokalaria, enemy1, enemy2, enemy3, enemy4, proyectil1, proyectil2, proyectil3, proyectil4, amaiera, objektua;
            POSIZIOA aux; 
            jokalaria.pos.x = 140;
            jokalaria.pos.y = 260;
            enemy1.pos.x = xenemy[0];
            enemy1.pos.y = yenemy[0];
            enemy2.pos.x = xenemy[1];
            enemy2.pos.y = yenemy[1];
            enemy3.pos.x = xenemy[2];
            enemy3.pos.y = yenemy[2];
            enemy4.pos.x = xenemy[3];
            enemy4.pos.y = yenemy[3];
            proyectil1.pos.x = 510;
            proyectil1.pos.y = 190;
            proyectil2.pos.x = 510;
            proyectil2.pos.y = 240;
            proyectil3.pos.x = 510;
            proyectil3.pos.y = 280;
            proyectil4.pos.x = 510;
            proyectil4.pos.y = 320;
            amaiera.pos.x = 370;
            amaiera.pos.y = 45;
            audioInit();
            loadTheMusic(JOKOA_SOUND);
            playMusic();
            fondo5 = irudiaKargatu(FONDOBOST);
            
            enemy1.id = irudiaKargatu(PISTOLA);
            enemy2.id = irudiaKargatu(PISTOLA);
            enemy3.id = irudiaKargatu(PISTOLA);
            enemy4.id = irudiaKargatu(PISTOLA);
            proyectil1.id = irudiaKargatu(PETROLEO);
            proyectil2.id = irudiaKargatu(PETROLEO);
            proyectil3.id = irudiaKargatu(PETROLEO);
            proyectil4.id = irudiaKargatu(PETROLEO);
            amaiera.id = irudiaKargatu(JOKOA_ENEMY_EGUZKIA1);
            int hasieraArgazki = irudiaKargatu(JOKOA_MENUA_HOME);
            int muerte = irudiaKargatu(MUERTE);
            jokalaria.id = JOKOA_jokalariaIrudiaSortu(personajea);
            irudiaMugitu(proyectil2.id, 510,230);
            irudiaMugitu(proyectil4.id, 510, 310);
            irudiaMugitu(hasieraArgazki, 570, 410);
            do {
                Sleep(8);
                pantailaGarbitu();
                irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
                irudiaMugitu(enemy1.id, enemy1.pos.x, enemy1.pos.y);
                irudiaMugitu(enemy2.id, enemy2.pos.x, enemy2.pos.y);
                irudiaMugitu(enemy3.id, enemy3.pos.x, enemy3.pos.y);
                irudiaMugitu(enemy4.id, enemy4.pos.x, enemy4.pos.y);
                irudiaMugitu(amaiera.id, amaiera.pos.x, amaiera.pos.y);
                irudiaMugitu(muerte, 20, 28);
                irudiakMarraztu();
                sprintf(str, "%d", kont);
                textuaIdatzi(50, 20, str);
                textuaIdatzi(51, 21, str);
                
                pantailaBerriztu();
                ebentu = ebentuaJasoGertatuBada();
                if (jokalaria.pos.x <= 358 && jokalaria.pos.x >= 94 && jokalaria.pos.y >= 184 && jokalaria.pos.y <= 340)
                {
                    karratu = 1;
                }
                if (jokalaria.pos.x <= 434 && jokalaria.pos.x >= 358 && jokalaria.pos.y >= 184 && jokalaria.pos.y <= 340)
                {
                    karratu = 2;
                }
                if (jokalaria.pos.x <= 522 && jokalaria.pos.x >= 450 && jokalaria.pos.y >= 184 && jokalaria.pos.y <= 340)
                {
                    karratu = 3;
                }
                if (jokalaria.pos.x <= 434 && jokalaria.pos.x >= 358 && jokalaria.pos.y >= 144 && jokalaria.pos.y <= 164)
                {
                    karratu = 4;
                }
                if (jokalaria.pos.x <= 434 && jokalaria.pos.x >= 374 && jokalaria.pos.y >= 56 && jokalaria.pos.y <= 120)
                {
                    karratu = 5;
                }
                if (jokalaria.pos.x <= 358 && jokalaria.pos.x >= 334 && jokalaria.pos.y >= 56 && jokalaria.pos.y <= 120)
                {
                    karratu = 6;
                }
                if (jokalaria.pos.x <= 474 && jokalaria.pos.x >= 450 && jokalaria.pos.y >= 56 && jokalaria.pos.y <= 120)
                {
                    karratu = 7;
                }
                if (ebentu == TECLA_d)
                {
                    if ((karratu == 1) || (karratu == 2) || (karratu == 3 && jokalaria.pos.x < 522) || (karratu == 4 && jokalaria.pos.x < 434) || (karratu == 5) || (karratu == 6) || (karratu == 7 && jokalaria.pos.x < 474))
                    {
                        jokalaria.pos.x = jokalaria.pos.x + 4;
                    }
                }
                if (ebentu == TECLA_a)
                {
                    if ((karratu == 1 && jokalaria.pos.x > 94) || (karratu == 2) || (karratu == 3) || (karratu == 4 && jokalaria.pos.x > 374) || (karratu == 5) || (karratu == 6 && jokalaria.pos.x > 334) || (karratu == 7))
                    {
                        jokalaria.pos.x = jokalaria.pos.x - 4;
                    }
                }
                if (ebentu == TECLA_w)
                {
                    if (((karratu == 1 || karratu == 3) && jokalaria.pos.y > 184) || (karratu == 2) || (karratu == 4) || ((karratu == 5 || karratu == 6 || karratu == 7) && jokalaria.pos.y > 56))
                    {
                        jokalaria.pos.y = jokalaria.pos.y - 4;
                    }
                }
                if (ebentu == TECLA_s)
                {
                    if (((karratu == 1 || karratu == 2 || karratu == 3) && jokalaria.pos.y < 340) || (karratu == 4) || (karratu == 5) || ((karratu == 6 || karratu == 7) && jokalaria.pos.y < 120))
                    {
                        jokalaria.pos.y = jokalaria.pos.y + 4;
                    }
                }
                if (proyectil1.pos.x >= 200)
                {
                    irudiaMugitu(proyectil1.id, proyectil1.pos.x, proyectil1.pos.y);
                    aux = ERREALITATE_FISIKOA_mugimendua_negatiboa(proyectil1.pos);
                    proyectil1.pos.x = aux.x;
                }
                if (proyectil1.pos.x == 200)
                {
                    proyectil1.pos.x = 510;
                    irudiaMugitu(proyectil1.id, proyectil1.pos.x, proyectil1.pos.y);
                }
                
                if (proyectil1.pos.x <= 370 || aurreratua == 1)
                {
                    aurreratua = 1;
                    if (proyectil2.pos.x >= 200)
                    {
                        irudiaMugitu(proyectil2.id, proyectil2.pos.x, proyectil2.pos.y);
                        aux = ERREALITATE_FISIKOA_mugimendua_negatiboa(proyectil2.pos);
                        proyectil2.pos.x = aux.x;
                    }
                    if (proyectil2.pos.x == 200)
                    {
                        proyectil2.pos.x = 510;
                        irudiaMugitu(proyectil2.id, proyectil2.pos.x, proyectil2.pos.y);
                    }
                    if (proyectil4.pos.x >= 200)
                    {
                        irudiaMugitu(proyectil4.id, proyectil4.pos.x, proyectil4.pos.y);
                        aux = ERREALITATE_FISIKOA_mugimendua_negatiboa(proyectil4.pos);
                        proyectil4.pos.x = aux.x;
                    }
                    if (proyectil4.pos.x == 200)
                    {
                        proyectil4.pos.x = 510;
                        irudiaMugitu(proyectil4.id, proyectil4.pos.x, proyectil4.pos.y);
                    }

                }
                if (proyectil3.pos.x >= 200)
                {
                    irudiaMugitu(proyectil3.id, proyectil3.pos.x, proyectil3.pos.y);
                    aux = ERREALITATE_FISIKOA_mugimendua_negatiboa(proyectil3.pos);
                    proyectil3.pos.x = aux.x;
                }
                if (proyectil3.pos.x == 200)
                {
                    proyectil3.pos.x = 510;
                    irudiaMugitu(proyectil3.id, proyectil3.pos.x, proyectil3.pos.y);
                }
                if (mugitu) {
                    aux = ERREALITATE_FISIKOA_mugimendua(jokalaria.pos);
                    jokalaria.pos.x = aux.x;
                }
                egoera = JOKOA_egoera_5(jokalaria, enemy1, enemy2, enemy3, enemy4, proyectil1, proyectil2, proyectil3, proyectil4, amaiera);
                if (ebentu == SAGU_BOTOIA_EZKERRA) {
                    pos = saguarenPosizioa();
                    if ((pos.x > 570) && (pos.x < 570 + 43) && (pos.y > 410) && (pos.y < 453)) egoera = ATERA;
                }
            } while (egoera == JOLASTEN);

            if (egoera == GALDU)kont++;
            irudiaKendu(jokalaria.id);
            irudiaKendu(enemy1.id);
            irudiaKendu(enemy2.id);
            irudiaKendu(enemy3.id);
            irudiaKendu(enemy4.id);
            irudiaKendu(proyectil1.id);
            irudiaKendu(proyectil2.id);
            irudiaKendu(proyectil3.id);
            irudiaKendu(proyectil4.id);
            irudiaKendu(amaiera.id);
            irudiaKendu(muerte);
            irudiaKendu(hasieraArgazki);
            irudiaKendu(fondo5);
            toggleMusic();
            audioTerminate();
            pantailaGarbitu();
            pantailaBerriztu();
            return egoera;
 }
EGOERA sei_jokatu(int personajea)
{

    int hasi = 0, ebentu = 0, irten = 0, atera = 0;
    POSIZIOA pos;
    
    if (kontondo6 == 0)
    {
        kontondo6 = 1;
        pantailaGarbitu();
        int motibazio = irudiaKargatu(MEZUA_ONDO6);
        int jolastu = irudiaKargatu(JOKOA_MENUA_JOLASTU);
        irudiaMugitu(motibazio, 30, 30);
        irudiaMugitu(jolastu, 500, 405);
        irudiakMarraztu();
        irudiaKendu(motibazio);
        irudiaKendu(jolastu);
        pantailaBerriztu();
        //Hasi
        do
        {
            ebentu = ebentuaJasoGertatuBada();
            if (ebentu == SAGU_BOTOIA_EZKERRA)
            {
                pos = saguarenPosizioa();
                if ((pos.x > 440) && (pos.x < 440 + 136) && (pos.y > 405) && (pos.y < 405 + 59)) {
                    hasi = 1;
                }
            }
        } while (!hasi);
    }
    
    pantailaGarbitu();
    int fondo6;
    int xenemy[3] = { 210, 310, 340 };
    int yenemy[3] = { 150,100, 190 };
    int i, ezkerra1 = 0, ezkerra2 = 0, behera = 0, dauka = 0, karratu, t1 = 0, t2 = 0, t3 = 0, obj = 0;

    int mugitu = 0; //boolean
    EGOERA  egoera = JOLASTEN;
    JOKO_ELEMENTUA jokalaria, enemy1, enemy2, enemy3, amaiera, objektua, objektua2;
    POSIZIOA aux; 

    jokalaria.pos.x = 140;
    jokalaria.pos.y = 115;
    objektua.pos.x = 330;
    objektua.pos.y = 340;
    objektua2.pos.x = 505;
    objektua2.pos.y = 100;
    enemy1.pos.x = xenemy[0];
    enemy1.pos.y = yenemy[0];
    enemy2.pos.x = xenemy[1];
    enemy2.pos.y = yenemy[1];
    enemy3.pos.x = xenemy[2];
    enemy3.pos.y = yenemy[2];
    amaiera.pos.x = 480;
    amaiera.pos.y = 340;
    audioInit();
    loadTheMusic(JOKOA_SOUND);
    playMusic();
    fondo6 = irudiaKargatu(FONDOsei);
    jokalaria.id = JOKOA_jokalariaIrudiaSortu(personajea);
    enemy1.id = irudiaKargatu(TOXIC);
    enemy2.id = irudiaKargatu(TOXIC);
    enemy3.id = irudiaKargatu(TOXIC);
    objektua.id = irudiaKargatu(URAHARTU);
    objektua2.id = irudiaKargatu(URAHARTU);
    int muerte = irudiaKargatu(MUERTE);
    int hasieraArgazki = irudiaKargatu(JOKOA_MENUA_HOME);
    irudiaMugitu(hasieraArgazki, 570, 410);
    do
    {
        Sleep(3);
        pantailaGarbitu();
     
        irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
        irudiaMugitu(enemy1.id, enemy1.pos.x, enemy1.pos.y);
        irudiaMugitu(enemy2.id, enemy2.pos.x, enemy2.pos.y);
        irudiaMugitu(enemy3.id, enemy3.pos.x, enemy3.pos.y);
        irudiaMugitu(muerte, 20, 28);
        irudiaMugitu(objektua.id, objektua.pos.x, objektua.pos.y);
        irudiaMugitu(objektua2.id, objektua2.pos.x, objektua2.pos.y);
        irudiakMarraztu();
        sprintf(str, "%d", kont);
        textuaIdatzi(0, 20, str);
        textuaIdatzi541, 21, str);
        pantailaBerriztu();
        ebentu = ebentuaJasoGertatuBada();
        //Personaje mugitu
        if (jokalaria.pos.x <= 176 && jokalaria.pos.x >= 92 && jokalaria.pos.y >= 95 && jokalaria.pos.y <= 255)
        {
            karratu = 1;
        }
        if (jokalaria.pos.x <= 176 && jokalaria.pos.x >= 92 && jokalaria.pos.y >= 275 && jokalaria.pos.y <= 355)
        {
            karratu = 2;
        }
        if (jokalaria.pos.x <= 250 && jokalaria.pos.x >= 195 && jokalaria.pos.y >= 275 && jokalaria.pos.y <= 355)
        {
            karratu = 3;
        }
        if (jokalaria.pos.x <= 352 && jokalaria.pos.x >= 264 && jokalaria.pos.y >= 275 && jokalaria.pos.y <= 355)
        {
            karratu = 4;
        }
        if (jokalaria.pos.x <= 352 && jokalaria.pos.x >= 264 && jokalaria.pos.y >= 195 && jokalaria.pos.y <= 255)
        {
            karratu = 5;
        }
        if (jokalaria.pos.x <= 352 && jokalaria.pos.x >= 264 && jokalaria.pos.y >= 95 && jokalaria.pos.y <= 175)
        {
            karratu = 6;
        }
        if (jokalaria.pos.x <= 420 && jokalaria.pos.x >= 365 && jokalaria.pos.y >= 95 && jokalaria.pos.y <= 175)
        {
            karratu = 7;
        }
        if (jokalaria.pos.x <= 520 && jokalaria.pos.x >= 435 && jokalaria.pos.y >= 95 && jokalaria.pos.y <= 175)
        {
            karratu = 8;
        }
        if (jokalaria.pos.x <= 520 && jokalaria.pos.x >= 435 && jokalaria.pos.y >= 195 && jokalaria.pos.y <= 355)
        {
            karratu = 9;
        }
        if (ebentu == TECLA_d)
        {
            if ((karratu == 1 && jokalaria.pos.x < 176) || (karratu == 2) || (karratu == 3) || ((karratu == 4 || karratu == 5) && jokalaria.pos.x < 352) || (karratu == 6) || (karratu == 7) || ((karratu == 8 || karratu == 9) && jokalaria.pos.x < 520))
            {
                jokalaria.pos.x = jokalaria.pos.x + 4;
            }
        }
        if (ebentu == TECLA_a)
        {
            if (((karratu == 1 || karratu == 2) && jokalaria.pos.x > 92) || (karratu == 3) || (karratu == 4) || ((karratu == 5 || karratu == 6) && jokalaria.pos.x > 264) || (karratu == 7) || (karratu == 8) || ((karratu == 9) && jokalaria.pos.x > 435))
            {
                jokalaria.pos.x = jokalaria.pos.x - 4;
            }
        }
        if (ebentu == TECLA_w)
        {
            if (((karratu == 1 || karratu == 6 || karratu == 7 || karratu == 8) && jokalaria.pos.y > 95) || (karratu == 2) || ((karratu == 3) && jokalaria.pos.y > 275) || (karratu == 4) || (karratu == 5) || (karratu == 9))
            {
                jokalaria.pos.y = jokalaria.pos.y - 4;
            }
        }
        if (ebentu == TECLA_s)
        {
            if ((karratu == 1) || ((karratu == 2 || karratu == 3 || karratu == 4 || karratu == 9) && jokalaria.pos.y < 355) || (karratu == 5) || (karratu == 6) || ((karratu == 7) && jokalaria.pos.y < 175) || (karratu == 8))
            {
                jokalaria.pos.y = jokalaria.pos.y + 4;
            }
        }
        t1++;
        t2++;
        t3++;
        if (enemy1.pos.x == 90 || ezkerra1 == 0)
        {
            if (enemy1.pos.x == 90) t1 = 180;
            ezkerra1 = 0;
            aux = ERREALITATE_FISIKOA_mugimendua(enemy1.pos);
            enemy1.pos.x = aux.x;
            enemy1.pos.y = 310 + (35 * sin(1.02 * t1 - 1 * enemy1.pos.x));
        }
        if (enemy1.pos.x == 340 || ezkerra1 == 1)
        {
            if (enemy1.pos.x == 340) t1 = 0;
            ezkerra1 = 1;
            aux = ERREALITATE_FISIKOA_mugimendua_negatiboa(enemy1.pos);
            enemy1.pos.x = aux.x;
            enemy1.pos.y = 310 + (35 * sin(1.02 * t1 + 1 * enemy1.pos.x));
        }
        if (enemy2.pos.x == 260 || ezkerra2 == 0)
        {
            if (enemy2.pos.x == 260) t2 = 180;
            ezkerra2 = 0;
            aux = ERREALITATE_FISIKOA_mugimendua(enemy2.pos);
            enemy2.pos.x = aux.x;
            enemy2.pos.y = 125 + (35 * sin(1.02 * t2 - 1 * enemy2.pos.x));
        }
        if (enemy2.pos.x == 510 || ezkerra2 == 1)
        {
            if (enemy2.pos.x == 510) t2 = 0;
            ezkerra2 = 1;
            aux = ERREALITATE_FISIKOA_mugimendua_negatiboa(enemy2.pos);
            enemy2.pos.x = aux.x;
            enemy2.pos.y = 125 + (35 * sin(1.02 * t2 + 1 * enemy2.pos.x));
        }
        if (enemy3.pos.y == 90 || behera == 0)
        {
            if (enemy3.pos.y == 90) t3 = 180;
            behera = 0;
            aux = ERREALITATE_FISIKOA_mugimendua(enemy3.pos);
            enemy3.pos.y = aux.y;
            enemy3.pos.x = 300 + (35 * sin(1.02 * t3 - 1 * enemy3.pos.y));
        }
        if (enemy3.pos.y == 340 || behera == 1)
        {
            if (enemy3.pos.y == 340) t3 = 0;
            behera = 1;
            aux = ERREALITATE_FISIKOA_mugimendua_negatiboa(enemy3.pos);
            enemy3.pos.y = aux.y;
            enemy3.pos.x = 300 + (35 * sin(1.02 * t3 + 1 * enemy3.pos.y));
        }
        if (mugitu)
        {
            aux = ERREALITATE_FISIKOA_mugimendua(jokalaria.pos);
            jokalaria.pos.x = aux.x;
        }
        if ((jokalaria.pos.x > objektua.pos.x - 15 && jokalaria.pos.x <objektua.pos.x + 15 && jokalaria.pos.y >objektua.pos.y - 15 && jokalaria.pos.y < objektua.pos.y + 15) && (dauka == 0 || dauka == 2 ))
        {
            dauka=1;
            obj++;
            irudiaKendu(objektua.id);
        }
        if ((jokalaria.pos.x > objektua2.pos.x - 15 && jokalaria.pos.x <objektua2.pos.x + 15 && jokalaria.pos.y >objektua2.pos.y - 15 && jokalaria.pos.y < objektua2.pos.y + 15) && (dauka == 1 || dauka==0))
        {
            dauka=2;
            obj++;
            irudiaKendu(objektua2.id);
        }
        egoera = JOKOA_egoera_6(jokalaria, enemy1, enemy2, enemy3, amaiera, obj);
        if (ebentu == SAGU_BOTOIA_EZKERRA) {
            pos = saguarenPosizioa();
            if ((pos.x > 570) && (pos.x < 570 + 43) && (pos.y > 410) && (pos.y < 453)) egoera = ATERA;
        }
        
    } while (egoera == JOLASTEN);

    if (egoera == GALDU)kont++;
    if (dauka == 0) {
        irudiaKendu(objektua.id);
        irudiaKendu(objektua2.id);
    }
    if ((dauka == 1) && (obj < 2))irudiaKendu(objektua2.id);
    if ((dauka == 2) && (obj < 2))irudiaKendu(objektua.id);
    irudiaKendu(jokalaria.id);
    irudiaKendu(enemy1.id);
    irudiaKendu(enemy2.id);
    irudiaKendu(enemy3.id);
   
    irudiaKendu(fondo6);
    irudiaKendu(muerte);
    toggleMusic();
    audioTerminate();
    pantailaGarbitu();
    pantailaBerriztu();
    return egoera;
}

EGOERA JOKOA_egoera_1(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA oztopoa1, JOKO_ELEMENTUA oztopoa2, JOKO_ELEMENTUA oztopoa3, JOKO_ELEMENTUA amaiera, int dauka) {
    EGOERA  ret = JOLASTEN;
    if ((jokalaria.pos.x > oztopoa1.pos.x - 25 && jokalaria.pos.x <oztopoa1.pos.x + 25 && jokalaria.pos.y >oztopoa1.pos.y - 25 && jokalaria.pos.y < oztopoa1.pos.y + 25) || (jokalaria.pos.x > oztopoa2.pos.x - 25 && jokalaria.pos.x <oztopoa2.pos.x + 25 && jokalaria.pos.y >oztopoa2.pos.y - 25 && jokalaria.pos.y < oztopoa2.pos.y + 25) || (jokalaria.pos.x > oztopoa3.pos.x - 25 && jokalaria.pos.x <oztopoa3.pos.x + 25 && jokalaria.pos.y >oztopoa3.pos.y - 25 && jokalaria.pos.y < oztopoa3.pos.y + 25))
    {
        ret = GALDU;
    }
    if ((jokalaria.pos.x > amaiera.pos.x - 30 && jokalaria.pos.x <amaiera.pos.x + 30 && jokalaria.pos.y >amaiera.pos.y - 30 && jokalaria.pos.y < amaiera.pos.y + 30) && (dauka == 1))
    {
        
        ret = IRABAZI;
        printf("%d", ret);
    }
    
    return ret;
}
EGOERA JOKOA_egoera_2(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA oztopoa1, JOKO_ELEMENTUA oztopoa2, JOKO_ELEMENTUA oztopoa3, JOKO_ELEMENTUA oztopoa4, JOKO_ELEMENTUA oztopoa5, JOKO_ELEMENTUA oztopoa6) {
    EGOERA  ret = JOLASTEN;
    
    if ((jokalaria.pos.x > oztopoa1.pos.x - 25 && jokalaria.pos.x <oztopoa1.pos.x + 25 && jokalaria.pos.y >oztopoa1.pos.y - 25 && jokalaria.pos.y < oztopoa1.pos.y + 25) || (jokalaria.pos.x > oztopoa2.pos.x - 25 && jokalaria.pos.x <oztopoa2.pos.x + 25 && jokalaria.pos.y >oztopoa2.pos.y - 25 && jokalaria.pos.y < oztopoa2.pos.y + 25) || (jokalaria.pos.x > oztopoa3.pos.x - 25 && jokalaria.pos.x <oztopoa3.pos.x + 25 && jokalaria.pos.y >oztopoa3.pos.y - 25 && jokalaria.pos.y < oztopoa3.pos.y + 25) || (jokalaria.pos.x > oztopoa4.pos.x - 25 && jokalaria.pos.x <oztopoa4.pos.x + 25 && jokalaria.pos.y >oztopoa4.pos.y - 25 && jokalaria.pos.y < oztopoa4.pos.y + 25) || (jokalaria.pos.x > oztopoa5.pos.x - 25 && jokalaria.pos.x <oztopoa5.pos.x + 25 && jokalaria.pos.y >oztopoa5.pos.y - 25 && jokalaria.pos.y < oztopoa5.pos.y + 25) || (jokalaria.pos.x > oztopoa6.pos.x - 25 && jokalaria.pos.x <oztopoa6.pos.x + 25 && jokalaria.pos.y >oztopoa6.pos.y - 25 && jokalaria.pos.y < oztopoa6.pos.y + 25))
    {
        ret = GALDU;
    }
    if (jokalaria.pos.x > 520 && jokalaria.pos.x < 570 && jokalaria.pos.y > 160 && jokalaria.pos.y < 240)
    {
        ret = IRABAZI;
    }
    return ret;
}
EGOERA JOKOA_egoera_3(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA oztopoa1, JOKO_ELEMENTUA oztopoa2, JOKO_ELEMENTUA oztopoa3,  int dauka) {
    EGOERA  ret = JOLASTEN;
    if ((jokalaria.pos.x > oztopoa1.pos.x - 25 && jokalaria.pos.x <oztopoa1.pos.x + 25 && jokalaria.pos.y >oztopoa1.pos.y - 25 && jokalaria.pos.y < oztopoa1.pos.y + 25) || (jokalaria.pos.x > oztopoa2.pos.x - 25 && jokalaria.pos.x <oztopoa2.pos.x + 25 && jokalaria.pos.y >oztopoa2.pos.y - 25 && jokalaria.pos.y < oztopoa2.pos.y + 25) || (jokalaria.pos.x > oztopoa3.pos.x - 25 && jokalaria.pos.x <oztopoa3.pos.x + 25 && jokalaria.pos.y >oztopoa3.pos.y - 25 && jokalaria.pos.y < oztopoa3.pos.y + 25))
    {
        ret = GALDU;
    }
    if ((jokalaria.pos.x > 155 && jokalaria.pos.x <190 && jokalaria.pos.y >230 - 30 && jokalaria.pos.y < 265) && (dauka == 1))
    {
        ret = IRABAZI;
    }
    return ret;
}
EGOERA JOKOA_egoera_4(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA oztopoa1, JOKO_ELEMENTUA oztopoa2, JOKO_ELEMENTUA amaiera, int obj) {
    EGOERA  ret = JOLASTEN;
    if ((jokalaria.pos.x > oztopoa1.pos.x - 20 && jokalaria.pos.x <oztopoa1.pos.x + 20 && jokalaria.pos.y >oztopoa1.pos.y - 20 && jokalaria.pos.y < oztopoa1.pos.y + 20) || (jokalaria.pos.x > oztopoa2.pos.x - 20 && jokalaria.pos.x <oztopoa2.pos.x + 20 && jokalaria.pos.y >oztopoa2.pos.y - 20 && jokalaria.pos.y < oztopoa2.pos.y + 20))
    {
        ret = GALDU;
    }
    if ((jokalaria.pos.x > amaiera.pos.x - 30 && jokalaria.pos.x <amaiera.pos.x + 30 && jokalaria.pos.y >amaiera.pos.y - 30 && jokalaria.pos.y < amaiera.pos.y + 30) && (obj == 2))
    {
        ret = IRABAZI;
    }
    return ret;
}
EGOERA JOKOA_egoera_5(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA oztopoa1, JOKO_ELEMENTUA oztopoa2, JOKO_ELEMENTUA oztopoa3, JOKO_ELEMENTUA oztopoa4, JOKO_ELEMENTUA proyectil1, JOKO_ELEMENTUA proyectil2, JOKO_ELEMENTUA proyectil3, JOKO_ELEMENTUA proyectil4, JOKO_ELEMENTUA amaiera) {
    EGOERA  ret = JOLASTEN;
    if ((jokalaria.pos.x > oztopoa1.pos.x - 20 && jokalaria.pos.x <oztopoa1.pos.x + 20 && jokalaria.pos.y >oztopoa1.pos.y - 20 && jokalaria.pos.y < oztopoa1.pos.y + 20) || (jokalaria.pos.x > oztopoa2.pos.x - 20 && jokalaria.pos.x <oztopoa2.pos.x + 20 && jokalaria.pos.y >oztopoa2.pos.y - 20 && jokalaria.pos.y < oztopoa2.pos.y + 20) || (jokalaria.pos.x > oztopoa3.pos.x - 20 && jokalaria.pos.x <oztopoa3.pos.x + 20 && jokalaria.pos.y >oztopoa3.pos.y - 20 && jokalaria.pos.y < oztopoa3.pos.y + 20) || (jokalaria.pos.x > oztopoa4.pos.x - 20 && jokalaria.pos.x <oztopoa4.pos.x + 20 && jokalaria.pos.y >oztopoa4.pos.y - 20 && jokalaria.pos.y < oztopoa4.pos.y + 20) || (jokalaria.pos.x > proyectil1.pos.x - 20 && jokalaria.pos.x <proyectil1.pos.x + 20 && jokalaria.pos.y >proyectil1.pos.y - 20 && jokalaria.pos.y < proyectil1.pos.y + 20) || (jokalaria.pos.x > proyectil2.pos.x - 20 && jokalaria.pos.x <proyectil2.pos.x + 20 && jokalaria.pos.y >proyectil2.pos.y - 20 && jokalaria.pos.y < proyectil2.pos.y + 20) || (jokalaria.pos.x > proyectil3.pos.x - 20 && jokalaria.pos.x <proyectil3.pos.x + 20 && jokalaria.pos.y >proyectil3.pos.y - 20 && jokalaria.pos.y < proyectil3.pos.y + 20) || (jokalaria.pos.x > proyectil4.pos.x - 20 && jokalaria.pos.x <proyectil4.pos.x + 20 && jokalaria.pos.y >proyectil4.pos.y - 20 && jokalaria.pos.y < proyectil4.pos.y + 20))
    {
        ret = GALDU;
    }
    if (jokalaria.pos.x > 380 && jokalaria.pos.x <440 && jokalaria.pos.y > 50 && jokalaria.pos.y < 115)
    {
        ret = IRABAZI;
    }
    return ret;
}
EGOERA JOKOA_egoera_6(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA oztopoa1, JOKO_ELEMENTUA oztopoa2, JOKO_ELEMENTUA oztopoa3, JOKO_ELEMENTUA amaiera, int obj) {
    EGOERA  ret = JOLASTEN;
    if ((jokalaria.pos.x > oztopoa1.pos.x - 20 && jokalaria.pos.x <oztopoa1.pos.x + 20 && jokalaria.pos.y >oztopoa1.pos.y - 20 && jokalaria.pos.y < oztopoa1.pos.y + 20) || (jokalaria.pos.x > oztopoa2.pos.x - 20 && jokalaria.pos.x <oztopoa2.pos.x + 20 && jokalaria.pos.y >oztopoa2.pos.y - 20 && jokalaria.pos.y < oztopoa2.pos.y + 20) || (jokalaria.pos.x > oztopoa3.pos.x - 20 && jokalaria.pos.x <oztopoa3.pos.x + 20 && jokalaria.pos.y >oztopoa3.pos.y - 20 && jokalaria.pos.y < oztopoa3.pos.y + 20))
    {
        ret = GALDU;
    }
    if ((jokalaria.pos.x > amaiera.pos.x - 30 && jokalaria.pos.x <amaiera.pos.x + 30 && jokalaria.pos.y >amaiera.pos.y - 30 && jokalaria.pos.y < amaiera.pos.y + 30) && (obj==2))
    {
        ret = IRABAZI;
    }
    return ret;
}

POSIZIOA ERREALITATE_FISIKOA_mugimendua(POSIZIOA posizioa) {
  posizioa.y = posizioa.y + 1;
  posizioa.x = posizioa.x + 1;
  return posizioa;
}
POSIZIOA ERREALITATE_FISIKOA_mugimendua_negatiboa(POSIZIOA posizioa) {
    posizioa.y = posizioa.y - 1;
    posizioa.x = posizioa.x - 1;
    return posizioa;
}

int  jokoAmaierakoa(EGOERA egoera){
    int ebentu = 0, balioa=0 ,irabazi = 0,flecha=0,errepikatu=0,boton=0,hasi = 0, motibazio=0, jolastu=0;
    int idAudioGame,idAudioGame1;
    POSIZIOA pos;
        if (egoera == IRABAZI) {
            idAudioGame1 = loadSound(JOKOA_SOUND_WIN);
            playSound(idAudioGame1);
            pantailaGarbitu();
            irabazi = irudiaKargatu(BUKAERA_IMAGE_IRABAZI);
            flecha = irudiaKargatu(JOKOA_NIVEL_FLECHA);
            errepikatu = irudiaKargatu(JOKOA_NIVEL_ERREPIKATU);
            boton = irudiaKargatu(JOKOA_NIVEL_BOTON);
            
            irudiaMugitu(irabazi, 0, 0);
            irudiaMugitu(boton, 175, 385);
            irudiaMugitu(errepikatu, 300, 385);
            irudiaMugitu(flecha, 425, 385);
            irudiakMarraztu();
            pantailaBerriztu();
            do {
                ebentu = ebentuaJasoGertatuBada();
                if (ebentu == SAGU_BOTOIA_EZKERRA) {
                    pos = saguarenPosizioa();
                    if ((pos.x > 175) && (pos.x < 175 + 65) && (pos.y > 385) && (pos.y < 385 + 59))balioa = 2;
                    if ((pos.x > 300) && (pos.x < 300 + 65) && (pos.y > 385) && (pos.y < 385 + 59))balioa = 3;
                    if ((pos.x > 425) && (pos.x < 425 + 65) && (pos.y > 385) && (pos.y < 385 + 59))balioa = 4;
                }
            } while (!balioa);
            irudiaKendu(irabazi);
            irudiaKendu(flecha);
            irudiaKendu(errepikatu);
            irudiaKendu(boton);
            audioTerminate(idAudioGame1);
        }
        else
        {
            idAudioGame = loadSound(JOKOA_SOUND_LOOSE);
            playSound(idAudioGame);
            if (konterror1 == 0)
            {
                konterror1 = 1;
                pantailaGarbitu();   
                motibazio = irudiaKargatu(MEZUA_GAIZKI1);
                jolastu = irudiaKargatu(JOKOA_MENUA_JOLASTU);
                irudiaMugitu(motibazio, 40, 40);
                irudiaMugitu(jolastu, 500, 405);
                irudiakMarraztu();
                pantailaBerriztu();
                
                do {
                    ebentu = ebentuaJasoGertatuBada();
                    if (ebentu == SAGU_BOTOIA_EZKERRA) {
                        pos = saguarenPosizioa();
                        if ((pos.x > 500) && (pos.x < 500 + 136) && (pos.y > 405) && (pos.y < 405 + 59)) {
                            hasi = 1;
                            balioa = 3;
                        }
                    }
                } while (!hasi);
                irudiaKendu(motibazio);
                irudiaKendu(jolastu);
            }
            if (hasi == 0) {
                balioa = 3;
            }
        }
        pantailaBerriztu();
        
            return balioa;
        }
int  jokoAmaierakoa2(EGOERA egoera){
    int ebentu = 0, balioa = 0, irabazi = 0, flecha = 0, errepikatu = 0, boton = 0, hasi = 0, motibazio = 0, jolastu = 0;
    int idAudioGame,idAudioGame1;
    POSIZIOA pos;

   
        if (egoera == IRABAZI) {
            idAudioGame1 = loadSound(JOKOA_SOUND_WIN);
            playSound(idAudioGame1);
            pantailaGarbitu();
            irabazi = irudiaKargatu(BUKAERA_IMAGE_IRABAZI);
            flecha = irudiaKargatu(JOKOA_NIVEL_FLECHA);
            errepikatu = irudiaKargatu(JOKOA_NIVEL_ERREPIKATU);
            boton = irudiaKargatu(JOKOA_NIVEL_BOTON);

            irudiaMugitu(irabazi, 0, 0);
            irudiaMugitu(boton, 175, 385);
            irudiaMugitu(errepikatu, 300, 385);
            irudiaMugitu(flecha, 425, 385);
            irudiakMarraztu();
            pantailaBerriztu();
            do {
                ebentu = ebentuaJasoGertatuBada();
                if (ebentu == SAGU_BOTOIA_EZKERRA) {
                    pos = saguarenPosizioa();
                    if ((pos.x > 175) && (pos.x < 175 + 65) && (pos.y > 385) && (pos.y < 385 + 59))balioa = 2;
                    if ((pos.x > 300) && (pos.x < 300 + 65) && (pos.y > 385) && (pos.y < 385 + 59))balioa = 4;
                    if ((pos.x > 425) && (pos.x < 425 + 65) && (pos.y > 385) && (pos.y < 385 + 59))balioa = 5;
                }
            } while (!balioa);
            irudiaKendu(irabazi);
            irudiaKendu(flecha);
            irudiaKendu(errepikatu);
            irudiaKendu(boton);
            audioTerminate(idAudioGame1);
        }
        else
        {
            idAudioGame = loadSound(JOKOA_SOUND_LOOSE);
            playSound(idAudioGame);
                if (konterror2 == 0)
                {
                    konterror2 = 1;
                    pantailaGarbitu();
                    motibazio = irudiaKargatu(MEZUA_GAIZKI2);
                    jolastu = irudiaKargatu(JOKOA_MENUA_JOLASTU);
                    irudiaMugitu(motibazio, 40, 40);
                    irudiaMugitu(jolastu, 500, 405);
                    irudiakMarraztu();
                    pantailaBerriztu();
                    do {
                        ebentu = ebentuaJasoGertatuBada();
                        if (ebentu == SAGU_BOTOIA_EZKERRA) {
                            pos = saguarenPosizioa();
                            if ((pos.x > 500) && (pos.x < 500 + 136) && (pos.y > 405) && (pos.y < 405 + 59))
                            hasi = 1;
                            balioa = 4;
                        }
                    } while (!hasi);
                    irudiaKendu(motibazio);
                    irudiaKendu(jolastu);
                }
                if (hasi == 0)balioa = 4;           
        }
        pantailaBerriztu();
        
    return balioa;
}
int  jokoAmaierakoa3(EGOERA egoera)
{
    int ebentu = 0, balioa = 0, irabazi = 0, flecha = 0, errepikatu = 0, boton = 0, hasi = 0, motibazio = 0, jolastu = 0;
    int idAudioGame, idAudioGame1;
    POSIZIOA pos;

    if (egoera == IRABAZI) {
        idAudioGame1 = loadSound(JOKOA_SOUND_WIN);
        playSound(idAudioGame1);
        pantailaGarbitu();
        irabazi = irudiaKargatu(BUKAERA_IMAGE_IRABAZI);
        flecha = irudiaKargatu(JOKOA_NIVEL_FLECHA);
        errepikatu = irudiaKargatu(JOKOA_NIVEL_ERREPIKATU);
        boton = irudiaKargatu(JOKOA_NIVEL_BOTON);

        irudiaMugitu(irabazi, 0, 0);
        irudiaMugitu(boton, 175, 385);
        irudiaMugitu(errepikatu, 300, 385);
        irudiaMugitu(flecha, 425, 385);
        irudiakMarraztu();
        pantailaBerriztu();
        do {
            ebentu = ebentuaJasoGertatuBada();
            if (ebentu == SAGU_BOTOIA_EZKERRA) {
                pos = saguarenPosizioa();
                if ((pos.x > 175) && (pos.x < 175 + 65) && (pos.y > 385) && (pos.y < 385 + 59))balioa = 2;
                if ((pos.x > 300) && (pos.x < 300 + 65) && (pos.y > 385) && (pos.y < 385 + 59))balioa = 5;
                if ((pos.x > 425) && (pos.x < 425 + 65) && (pos.y > 385) && (pos.y < 385 + 59))balioa = 6;
            }
        } while (!balioa);
        irudiaKendu(irabazi);
        irudiaKendu(flecha);
        irudiaKendu(errepikatu);
        irudiaKendu(boton);
        audioTerminate(idAudioGame1);
    }
    else
    {
        idAudioGame = loadSound(JOKOA_SOUND_LOOSE);
        playSound(idAudioGame);
            if (konterror3 == 0)
            {
                konterror3 = 1;
                pantailaGarbitu();
                
                motibazio = irudiaKargatu(MEZUA_GAIZKI3);
                jolastu = irudiaKargatu(JOKOA_MENUA_JOLASTU);
                irudiaMugitu(motibazio, 40, 40);
                irudiaMugitu(jolastu, 500, 405);
                irudiakMarraztu();
                pantailaBerriztu();
                
                do {
                    ebentu = ebentuaJasoGertatuBada();
                    if (ebentu == SAGU_BOTOIA_EZKERRA) {
                        pos = saguarenPosizioa();
                        if ((pos.x > 500) && (pos.x < 500 + 136) && (pos.y > 405) && (pos.y < 405 + 59)) {
                            hasi = 1;
                            balioa = 5;
                        }
                    }
                } while (!hasi);
               
                irudiaKendu(motibazio);
                irudiaKendu(jolastu);
            }
            if (hasi == 0)balioa = 5;
    }
    pantailaBerriztu();
    
    return balioa;
}
int  jokoAmaierakoa4(EGOERA egoera)
{
    int ebentu = 0, balioa = 0, irabazi = 0, flecha = 0, errepikatu = 0, boton = 0, hasi = 0, motibazio = 0, jolastu = 0;
    int idAudioGame,idAudioGame1;
    POSIZIOA pos;

    if (egoera == IRABAZI) {
        idAudioGame1 = loadSound(JOKOA_SOUND_WIN);
        playSound(idAudioGame1);
        pantailaGarbitu();
        irabazi = irudiaKargatu(BUKAERA_IMAGE_IRABAZI);
        flecha = irudiaKargatu(JOKOA_NIVEL_FLECHA);
        errepikatu = irudiaKargatu(JOKOA_NIVEL_ERREPIKATU);
        boton = irudiaKargatu(JOKOA_NIVEL_BOTON);

        irudiaMugitu(irabazi, 0, 0);
        irudiaMugitu(boton, 175, 385);
        irudiaMugitu(errepikatu, 300, 385);
        irudiaMugitu(flecha, 425, 385);
        irudiakMarraztu();
        pantailaBerriztu();
        do {
            ebentu = ebentuaJasoGertatuBada();
            if (ebentu == SAGU_BOTOIA_EZKERRA) {
                pos = saguarenPosizioa();
                if ((pos.x > 175) && (pos.x < 175 + 65) && (pos.y > 385) && (pos.y < 385 + 59))balioa = 2;
                if ((pos.x > 300) && (pos.x < 300 + 65) && (pos.y > 385) && (pos.y < 385 + 59))balioa = 6;
                if ((pos.x > 425) && (pos.x < 425 + 65) && (pos.y > 385) && (pos.y < 385 + 59))balioa = 7;
            }
        } while (!balioa);
        irudiaKendu(irabazi);
        irudiaKendu(flecha);
        irudiaKendu(errepikatu);
        irudiaKendu(boton);
        audioTerminate(idAudioGame1);
    }
    else
    {
        idAudioGame = loadSound(JOKOA_SOUND_LOOSE);
        playSound(idAudioGame);
        if (konterror4 == 0)
        {
            konterror4 = 1;
            pantailaGarbitu();
            pantailaBerriztu();
            int motibazio = irudiaKargatu(MEZUA_GAIZKI4);
            int jolastu = irudiaKargatu(JOKOA_MENUA_JOLASTU);
            irudiaMugitu(motibazio, 40, 40);
            irudiaMugitu(jolastu, 500, 405);
            irudiakMarraztu();
            pantailaBerriztu();
            do {
                ebentu = ebentuaJasoGertatuBada();
                if (ebentu == SAGU_BOTOIA_EZKERRA) {
                    pos = saguarenPosizioa();
                    if ((pos.x > 500) && (pos.x < 500 + 136) && (pos.y > 405) && (pos.y < 405 + 59)) {
                        hasi = 1;
                        balioa = 6;
                    }
                }
            } while (!hasi);
            irudiaKendu(motibazio);
            irudiaKendu(jolastu);
        }
        if (hasi == 0)balioa = 6;
    }
    pantailaBerriztu();
    
    return balioa;
}
int  jokoAmaierakoa5(EGOERA egoera) {
    int ebentu = 0, balioa = 0, irabazi = 0, flecha = 0, errepikatu = 0, boton = 0, hasi = 0, motibazio = 0, jolastu = 0;
    int idAudioGame, idAudioGame1;
    POSIZIOA pos;
    if (egoera == IRABAZI) {
        idAudioGame1 = loadSound(JOKOA_SOUND_WIN);
        playSound(idAudioGame1);
        pantailaGarbitu();
        irabazi = irudiaKargatu(BUKAERA_IMAGE_IRABAZI);
        flecha = irudiaKargatu(JOKOA_NIVEL_FLECHA);
        errepikatu = irudiaKargatu(JOKOA_NIVEL_ERREPIKATU);
        boton = irudiaKargatu(JOKOA_NIVEL_BOTON);

        irudiaMugitu(irabazi, 0, 0);
        irudiaMugitu(boton, 175, 385);
        irudiaMugitu(errepikatu, 300, 385);
        irudiaMugitu(flecha, 425, 385);
        irudiakMarraztu();
        pantailaBerriztu();
        do {
            ebentu = ebentuaJasoGertatuBada();
            if (ebentu == SAGU_BOTOIA_EZKERRA) {
                pos = saguarenPosizioa();
                if ((pos.x > 175) && (pos.x < 175 + 65) && (pos.y > 385) && (pos.y < 385 + 59))balioa = 2;
                if ((pos.x > 300) && (pos.x < 300 + 65) && (pos.y > 385) && (pos.y < 385 + 59))balioa = 7;
                if ((pos.x > 425) && (pos.x < 425 + 65) && (pos.y > 385) && (pos.y < 385 + 59))balioa = 8;
            }
        } while (!balioa);
        irudiaKendu(irabazi);
        irudiaKendu(flecha);
        irudiaKendu(errepikatu);
        irudiaKendu(boton);
        audioTerminate(idAudioGame1);
    }
    else
    {
        idAudioGame = loadSound(JOKOA_SOUND_LOOSE);
        playSound(idAudioGame);
        if (konterror5 == 0)
        {
            konterror5 = 1;
            pantailaGarbitu();
            motibazio = irudiaKargatu(MEZUA_GAIZKI5);
            jolastu = irudiaKargatu(JOKOA_MENUA_JOLASTU);
            irudiaMugitu(motibazio, 40, 40);
            irudiaMugitu(jolastu, 500, 405);
            irudiakMarraztu();
            pantailaBerriztu();

            do {
                ebentu = ebentuaJasoGertatuBada();
                if (ebentu == SAGU_BOTOIA_EZKERRA) {
                    pos = saguarenPosizioa();
                    if ((pos.x > 500) && (pos.x < 500 + 136) && (pos.y > 405) && (pos.y < 405 + 59)) {
                        hasi = 1;
                        balioa = 7;
                    }
                }
            } while (!hasi);
            irudiaKendu(motibazio);
            irudiaKendu(jolastu);
        }
        if (hasi == 0) {
            balioa = 7;
           
        }
    }
    pantailaBerriztu();
    
    return balioa;
}
int  jokoAmaierakoa6(EGOERA egoera) {
    int ebentu = 0, balioa = 0, irabazi = 0, flecha = 0, errepikatu = 0, boton = 0, hasi = 0, motibazio = 0, jolastu = 0;
    int idAudioGame, idAudioGame1;
    POSIZIOA pos;
    if (egoera == IRABAZI) {
        idAudioGame1 = loadSound(JOKOA_SOUND_WIN);
        playSound(idAudioGame1);
        pantailaGarbitu();
        irabazi = irudiaKargatu(BUKAERA_IMAGE_IRABAZI);
        flecha = irudiaKargatu(JOKOA_NIVEL_FLECHA);
        errepikatu = irudiaKargatu(JOKOA_NIVEL_ERREPIKATU);
        boton = irudiaKargatu(JOKOA_NIVEL_BOTON);

        irudiaMugitu(irabazi, 0, 0);
        irudiaMugitu(boton, 175, 385);
        irudiaMugitu(errepikatu, 300, 385);
        irudiaMugitu(flecha, 425, 385);
        irudiakMarraztu();
        pantailaBerriztu();
        do {
            ebentu = ebentuaJasoGertatuBada();
            if (ebentu == SAGU_BOTOIA_EZKERRA) {
                pos = saguarenPosizioa();
                if ((pos.x > 175) && (pos.x < 175 + 65) && (pos.y > 385) && (pos.y < 385 + 59))balioa = 2;
                if ((pos.x > 300) && (pos.x < 300 + 65) && (pos.y > 385) && (pos.y < 385 + 59))balioa = 8;
                if ((pos.x > 425) && (pos.x < 425 + 65) && (pos.y > 385) && (pos.y < 385 + 59))balioa = 1;
            }
        } while (!balioa);
        irudiaKendu(irabazi);
        irudiaKendu(flecha);
        irudiaKendu(errepikatu);
        irudiaKendu(boton);
        audioTerminate(idAudioGame1);
    }
    else
    {
        idAudioGame = loadSound(JOKOA_SOUND_LOOSE);
        playSound(idAudioGame);
        if (konterror6 == 0)
        {
            konterror6 = 1;
            pantailaGarbitu();
            motibazio = irudiaKargatu(MEZUA_GAIZKI6);
            jolastu = irudiaKargatu(JOKOA_MENUA_JOLASTU);
            irudiaMugitu(motibazio, 40, 40);
            irudiaMugitu(jolastu, 500, 405);
            irudiakMarraztu();
            pantailaBerriztu();

            do {
                ebentu = ebentuaJasoGertatuBada();
                if (ebentu == SAGU_BOTOIA_EZKERRA) {
                    pos = saguarenPosizioa();
                    if ((pos.x > 500) && (pos.x < 500 + 136) && (pos.y > 405) && (pos.y < 405 + 59)) {
                        hasi = 1;
                        balioa = 8;
                    }
                }
            } while (!hasi);
            irudiaKendu(motibazio);
            irudiaKendu(jolastu);
        }
        if (hasi == 0) {
            balioa = 8;

        }
    }
   
    pantailaBerriztu();
    return balioa;
}

int JOKOA_jokalariaIrudiaSortu(int personajea)
{
    int martzianoId = -1;

    if (personajea == 2) {
        martzianoId = irudiaKargatu(JOKOA_PLAYER_GORRIA);
    }
    if (personajea == 3) {
        martzianoId = irudiaKargatu(JOKOA_PLAYER_BERDEA);
    }
    if (personajea == 4 || personajea == 1) {
        martzianoId = irudiaKargatu(JOKOA_PLAYER_URDINA);
    }
    if (personajea == 5) {
        martzianoId = irudiaKargatu(JOKOA_PLAYER_TXURIA);
    }
    if (personajea == 6) {
        martzianoId = irudiaKargatu(JOKOA_PLAYER_ARROSA);
    }
    if (personajea == 7) {
        martzianoId = irudiaKargatu(JOKOA_PLAYER_MOREA);
    }
    if (personajea == 8) {
        martzianoId = irudiaKargatu(JOKOA_PLAYER_NARANJA);
    }
    if (personajea == 9) {
        martzianoId = irudiaKargatu(JOKOA_PLAYER_URDINARGIA);
    }
    irudiaMugitu(martzianoId, 10, 239);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return martzianoId;
}