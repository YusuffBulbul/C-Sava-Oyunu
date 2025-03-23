#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <raylib.h>
struct unit_ortak
{
    int saldiri;
    int savunma;
    double saglik;
    double kritik_sans;
};
struct unit_I
{
    struct unit_ortak piyadeler;
    struct unit_ortak okcular;
    struct unit_ortak suvariler;
    struct unit_ortak kusatma_makineleri;
};
struct unit_O
{
    struct unit_ortak ork_dovusculeri;
    struct unit_ortak mizrakcilar;
    struct unit_ortak varg_binicileri;
    struct unit_ortak troller;
};
struct hero_crea_ortak
{
    char bonus_turu[100];
    int bonus_degeri;
    char etkiledigi_birim[100];
};
struct heroes_I
{
    struct hero_crea_ortak alparslan;
    struct hero_crea_ortak fatih_Sultan_Mehmet;
    struct hero_crea_ortak mete_Han;
    struct hero_crea_ortak yavuz_Sultan_Selim;
    struct hero_crea_ortak tugrul_Bey;
};
struct heroes_O
{
    struct hero_crea_ortak goruk_Vahsi;
    struct hero_crea_ortak thruk_Kemikkiran;
    struct hero_crea_ortak vrog_Kafakiran;
    struct hero_crea_ortak ugar_Zalim;
};
struct creatures_I
{
    struct hero_crea_ortak ejderha;
    struct hero_crea_ortak agri_Dagi_Devleri;
    struct hero_crea_ortak tepegoz;
    struct hero_crea_ortak karakurt;
    struct hero_crea_ortak samur;
};
struct creatures_O
{
    struct hero_crea_ortak kara_Troll;
    struct hero_crea_ortak golge_Kurtlari;
    struct hero_crea_ortak camur_Devleri;
    struct hero_crea_ortak ates_Iblisi;
    struct hero_crea_ortak makrog_Savas_Beyi;
    struct hero_crea_ortak buz_Devleri;
};
struct seviye
{
    int deger;
    char etkiledigi_birim[50] ;
    char etki_turu[50] ;
};
struct seviyeler
{
    struct seviye level1;
    struct seviye level2;
    struct seviye level3;
};
struct research
{
    struct seviyeler savunma_ustaligi;
    struct seviyeler saldiri_gelistirmesi;
    struct seviyeler elit_egitim;
    struct seviyeler kusatma_ustaligi;
};
struct insan_imparatorlugu
{
    struct research i_research;
    struct creatures_I i_creatures;
    struct heroes_I i_heroes;
    struct unit_I i_unit;
};
struct ork_lejyonu
{
    struct research o_research;
    struct creatures_O o_creatures;
    struct heroes_O o_heroes;
    struct unit_O o_unit;
};
struct unit_I_sayi
{
    int piyade_sayi;
    int okcu_sayi;
    int suvari_sayi;
    int kusatma_makine_sayi;
};
struct unit_O_sayi
{
    int ork_dovuscu_sayi;
    int mizrakci_sayi;
    int varg_binici_sayi;
    int troller_sayi;
};
struct heroes_I_sayi
{
    int alparslan_sayi;
    int fatih_sultan_mehmet_sayi;
    int mete_han_sayi;
    int yavuz_sultan_selim_sayi;
    int tugrul_bey_sayi;
};
struct heroes_O_sayi
{
    int goruk_vahsi_sayi;
    int thruk_kemikkiran_sayi;
    int vrog_kafakiran_sayi;
    int ugar_zalim_sayi;
};
struct creatures_I_sayi
{
    int ejderha_sayi;
    int agri_dagi_devi_sayi;
    int tepegoz_sayi;
    int karakurt_sayi;
    int samur_sayi;
};
struct creatures_O_sayi
{
    int kara_trol_sayi;
    int golge_kurtlari_sayi;
    int camur_devleri_sayi;
    int ates_iblisi_sayi;
    int makrog_savas_beyi_sayi;
    int buz_devleri_sayi;
};
struct research_sayi
{
    int savunma_ustaligi_sayi;
    int saldiri_gelistirmesi_sayi;
    int elit_egitim_sayi;
    int kusatma_ustaligi_sayi;
};
struct insan_imparatorlugu_sayi
{
    struct unit_I_sayi unit_i_sayi;
    struct heroes_I_sayi heroes_i_sayi;
    struct creatures_I_sayi creatures_i_sayi;
    struct research_sayi research_i_sayi;
};
struct ork_lejyonu_sayi
{
    struct unit_O_sayi unit_o_sayi;
    struct heroes_O_sayi heroes_o_sayi;
    struct creatures_O_sayi creatures_o_sayi;
    struct research_sayi research_o_sayi;
};
struct birim_ortak
{
    double toplam_saldiri_gucu;
    double toplam_savunma_gucu;
    int kritik_vurus_tur_sayisi;
    double toplam_saglik;
};
struct insan_savas_ani
{
    struct birim_ortak piyade_savas;
    struct birim_ortak okcu_savas;
    struct birim_ortak suvari_savas;
    struct birim_ortak kusatma_makineleri_savas;
};
struct ork_savas_ani
{
    struct birim_ortak ork_dovuscu_savas;
    struct birim_ortak mizrakci_savas;
    struct birim_ortak varg_binici_savas;
    struct birim_ortak troller_savas;
};
char* sola_dayama(char* satir)
{

    while (*satir == ' ' )
    {
        satir++;
    }
    return satir;
}
int satira_git(FILE *fptr, int istenilen_satir)
{
    rewind(fptr);
    char satir[100];
    int bulunulan_satir = 1;


    while (fgets(satir, sizeof(satir), fptr) != NULL)
    {
        if (bulunulan_satir == istenilen_satir)
        {
            return 1;
        }
        bulunulan_satir++;
    }

    return 0;
}
void insan_kahraman_etkisi(struct insan_imparatorlugu *insan, struct insan_savas_ani *i_savas_ani, const char *kahraman_birimi, const char *bonus_turu, int bonus_degeri)
{
    if (strstr(kahraman_birimi, "piyade") != NULL)
    {
        if (strstr(bonus_turu, "saldiri") != NULL)
        {
            i_savas_ani->piyade_savas.toplam_saldiri_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "savunma") != NULL)
        {
            i_savas_ani->piyade_savas.toplam_savunma_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "kritik_sans") != NULL)
        {
            insan->i_unit.piyadeler.kritik_sans += (insan->i_unit.piyadeler.kritik_sans * (bonus_degeri / 100.0));
        }
    }
    if (strstr(kahraman_birimi, "okcular") != NULL)
    {
        if (strstr(bonus_turu, "saldiri") != NULL)
        {
            i_savas_ani->okcu_savas.toplam_saldiri_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "savunma") != NULL)
        {
            i_savas_ani->okcu_savas.toplam_savunma_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "kritik_sans") != NULL)
        {
            insan->i_unit.okcular.kritik_sans += (insan->i_unit.okcular.kritik_sans * (bonus_degeri / 100.0));
        }
    }
    if (strstr(kahraman_birimi, "suvariler") != NULL)
    {
        if (strstr(bonus_turu, "saldiri") != NULL)
        {
            i_savas_ani->suvari_savas.toplam_saldiri_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "savunma") != NULL)
        {
            i_savas_ani->suvari_savas.toplam_savunma_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "kritik_sans") != NULL)
        {
            insan->i_unit.suvariler.kritik_sans += (insan->i_unit.suvariler.kritik_sans * (bonus_degeri / 100.0));
        }
    }
    if (strstr(kahraman_birimi, "kusatma_makineler") != NULL)
    {
        if (strstr(bonus_turu, "saldiri") != NULL)
        {
            i_savas_ani->kusatma_makineleri_savas.toplam_saldiri_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "savunma") != NULL)
        {
            i_savas_ani->kusatma_makineleri_savas.toplam_savunma_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "kritik_sans") != NULL)
        {
            insan->i_unit.kusatma_makineleri.kritik_sans += (insan->i_unit.kusatma_makineleri.kritik_sans * (bonus_degeri / 100.0));
        }
    }
    if (strstr(kahraman_birimi, "tum_birimler") != NULL)
    {
        if (strstr(bonus_turu, "saldiri") != NULL)
        {
            i_savas_ani->kusatma_makineleri_savas.toplam_saldiri_gucu *= (1 + (bonus_degeri / 100.0));
            i_savas_ani->suvari_savas.toplam_saldiri_gucu *= (1 + (bonus_degeri / 100.0));
            i_savas_ani->okcu_savas.toplam_saldiri_gucu *= (1 + (bonus_degeri / 100.0));
            i_savas_ani->piyade_savas.toplam_saldiri_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "savunma") != NULL)
        {
            i_savas_ani->kusatma_makineleri_savas.toplam_savunma_gucu *= (1 + (bonus_degeri / 100.0));
            i_savas_ani->suvari_savas.toplam_savunma_gucu *= (1 + (bonus_degeri / 100.0));
            i_savas_ani->okcu_savas.toplam_savunma_gucu *= (1 + (bonus_degeri / 100.0));
            i_savas_ani->piyade_savas.toplam_savunma_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "kritik_sans") != NULL)
        {
            insan->i_unit.kusatma_makineleri.kritik_sans += (insan->i_unit.kusatma_makineleri.kritik_sans * (bonus_degeri / 100.0));
            insan->i_unit.suvariler.kritik_sans += (insan->i_unit.suvariler.kritik_sans * (bonus_degeri / 100.0));
            insan->i_unit.okcular.kritik_sans += (insan->i_unit.okcular.kritik_sans * (bonus_degeri / 100.0));
            insan->i_unit.piyadeler.kritik_sans += (insan->i_unit.piyadeler.kritik_sans * (bonus_degeri / 100.0));
        }
    }
}
void ork_kahraman_etkisi(struct ork_lejyonu *ork, struct ork_savas_ani *o_savas_ani, const char *kahraman_birimi, const char *bonus_turu, int bonus_degeri)
{
    if (strstr(kahraman_birimi, "ork_dovusculer") != NULL)
    {
        if (strstr(bonus_turu, "saldiri") != NULL)
        {
            o_savas_ani->ork_dovuscu_savas.toplam_saldiri_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "savunma") != NULL)
        {
            o_savas_ani->ork_dovuscu_savas.toplam_savunma_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "kritik_sans") != NULL)
        {
            ork->o_unit.ork_dovusculeri.kritik_sans += (ork->o_unit.ork_dovusculeri.kritik_sans * (bonus_degeri / 100.0));
        }
    }
    if (strstr(kahraman_birimi, "mizrakcilar") != NULL)
    {
        if (strstr(bonus_turu, "saldiri") != NULL)
        {
            o_savas_ani->mizrakci_savas.toplam_saldiri_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "savunma") != NULL)
        {
            o_savas_ani->mizrakci_savas.toplam_savunma_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "kritik_sans") != NULL)
        {
            ork->o_unit.mizrakcilar.kritik_sans += (ork->o_unit.mizrakcilar.kritik_sans * (bonus_degeri / 100.0));
        }
    }
    if (strstr(kahraman_birimi, "varg_biniciler") != NULL)
    {
        if (strstr(bonus_turu, "saldiri") != NULL)
        {
            o_savas_ani->varg_binici_savas.toplam_saldiri_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "savunma") != NULL)
        {
            o_savas_ani->varg_binici_savas.toplam_savunma_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "kritik_sans") != NULL)
        {
            ork->o_unit.varg_binicileri.kritik_sans += (ork->o_unit.varg_binicileri.kritik_sans * (bonus_degeri / 100.0));
        }
    }
    if (strstr(kahraman_birimi, "troller") != NULL)
    {
        if (strstr(bonus_turu, "saldiri") != NULL)
        {
            o_savas_ani->troller_savas.toplam_saldiri_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "savunma") != NULL)
        {
            o_savas_ani->troller_savas.toplam_savunma_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "kritik_sans") != NULL)
        {
            ork->o_unit.troller.kritik_sans += (ork->o_unit.troller.kritik_sans * (bonus_degeri / 100.0));
        }
    }
    if (strstr(kahraman_birimi, "tum_birimler") != NULL)
    {
        if (strstr(bonus_turu, "saldiri") != NULL)
        {
            o_savas_ani->ork_dovuscu_savas.toplam_saldiri_gucu *= (1 + (bonus_degeri / 100.0));
            o_savas_ani->mizrakci_savas.toplam_saldiri_gucu *= (1 + (bonus_degeri / 100.0));
            o_savas_ani->varg_binici_savas.toplam_saldiri_gucu *= (1 + (bonus_degeri / 100.0));
            o_savas_ani->troller_savas.toplam_saldiri_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "savunma") != NULL)
        {
            o_savas_ani->ork_dovuscu_savas.toplam_savunma_gucu *= (1 + (bonus_degeri / 100.0));
            o_savas_ani->mizrakci_savas.toplam_savunma_gucu *= (1 + (bonus_degeri / 100.0));
            o_savas_ani->varg_binici_savas.toplam_savunma_gucu *= (1 + (bonus_degeri / 100.0));
            o_savas_ani->troller_savas.toplam_savunma_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "kritik_sans") != NULL)
        {
            ork->o_unit.ork_dovusculeri.kritik_sans += (ork->o_unit.ork_dovusculeri.kritik_sans * (bonus_degeri / 100.0));
            ork->o_unit.mizrakcilar.kritik_sans += (ork->o_unit.mizrakcilar.kritik_sans * (bonus_degeri / 100.0));
            ork->o_unit.varg_binicileri.kritik_sans += (ork->o_unit.varg_binicileri.kritik_sans * (bonus_degeri / 100.0));
            ork->o_unit.troller.kritik_sans += (ork->o_unit.troller.kritik_sans * (bonus_degeri / 100.0));
        }
    }
}
void insan_canavar_etkisi(struct insan_imparatorlugu *insan, struct insan_savas_ani *i_savas_ani, const char *canavar_birimi, const char *bonus_turu, int bonus_degeri)
{
    if (strstr(canavar_birimi, "piyade") != NULL)
    {
        if (strstr(bonus_turu, "saldiri") != NULL)
        {
            i_savas_ani->piyade_savas.toplam_saldiri_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "savunma") != NULL)
        {
            i_savas_ani->piyade_savas.toplam_savunma_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "kritik_sans") != NULL)
        {
            insan->i_unit.piyadeler.kritik_sans += (insan->i_unit.piyadeler.kritik_sans * (bonus_degeri / 100.0));
        }
    }
    if (strstr(canavar_birimi, "okcular") != NULL)
    {
        if (strstr(bonus_turu, "saldiri") != NULL)
        {
            i_savas_ani->okcu_savas.toplam_saldiri_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "savunma") != NULL)
        {
            i_savas_ani->okcu_savas.toplam_savunma_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "kritik_sans") != NULL)
        {
            insan->i_unit.okcular.kritik_sans += (insan->i_unit.okcular.kritik_sans * (bonus_degeri / 100.0));
        }
    }
    if (strstr(canavar_birimi, "suvariler") != NULL)
    {
        if (strstr(bonus_turu, "saldiri") != NULL)
        {
            i_savas_ani->suvari_savas.toplam_saldiri_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "savunma") != NULL)
        {
            i_savas_ani->suvari_savas.toplam_savunma_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "kritik_sans") != NULL)
        {
            insan->i_unit.suvariler.kritik_sans += (insan->i_unit.suvariler.kritik_sans * (bonus_degeri / 100.0));
        }
    }
    if (strstr(canavar_birimi, "kusatma_makineler") != NULL)
    {
        if (strstr(bonus_turu, "saldiri") != NULL)
        {
            i_savas_ani->kusatma_makineleri_savas.toplam_saldiri_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "savunma") != NULL)
        {
            i_savas_ani->kusatma_makineleri_savas.toplam_savunma_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "kritik_sans") != NULL)
        {
            insan->i_unit.kusatma_makineleri.kritik_sans += (insan->i_unit.kusatma_makineleri.kritik_sans * (bonus_degeri / 100.0));
        }
    }
    if (strstr(canavar_birimi, "tum_birimler") != NULL)
    {
        if (strstr(bonus_turu, "saldiri") != NULL)
        {
            i_savas_ani->kusatma_makineleri_savas.toplam_saldiri_gucu *= (1 + (bonus_degeri / 100.0));
            i_savas_ani->suvari_savas.toplam_saldiri_gucu *= (1 + (bonus_degeri / 100.0));
            i_savas_ani->okcu_savas.toplam_saldiri_gucu *= (1 + (bonus_degeri / 100.0));
            i_savas_ani->piyade_savas.toplam_saldiri_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "savunma") != NULL)
        {
            i_savas_ani->kusatma_makineleri_savas.toplam_savunma_gucu *= (1 + (bonus_degeri / 100.0));
            i_savas_ani->suvari_savas.toplam_savunma_gucu *= (1 + (bonus_degeri / 100.0));
            i_savas_ani->okcu_savas.toplam_savunma_gucu *= (1 + (bonus_degeri / 100.0));
            i_savas_ani->piyade_savas.toplam_savunma_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "kritik_sans") != NULL)
        {
            insan->i_unit.kusatma_makineleri.kritik_sans += (insan->i_unit.kusatma_makineleri.kritik_sans * (bonus_degeri / 100.0));
            insan->i_unit.suvariler.kritik_sans += (insan->i_unit.suvariler.kritik_sans * (bonus_degeri / 100.0));
            insan->i_unit.okcular.kritik_sans += (insan->i_unit.okcular.kritik_sans * (bonus_degeri / 100.0));
            insan->i_unit.piyadeler.kritik_sans += (insan->i_unit.piyadeler.kritik_sans * (bonus_degeri / 100.0));
        }
    }
}
void ork_canavar_etkisi(struct ork_lejyonu *ork, struct ork_savas_ani *o_savas_ani, const char *canavar_birimi, const char *bonus_turu, int bonus_degeri)
{
    if (strstr(canavar_birimi, "ork_dovusculer") != NULL)
    {
        if (strstr(bonus_turu, "saldiri") != NULL)
        {
            o_savas_ani->ork_dovuscu_savas.toplam_saldiri_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "savunma") != NULL)
        {
            o_savas_ani->ork_dovuscu_savas.toplam_savunma_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "kritik_sans") != NULL)
        {
            ork->o_unit.ork_dovusculeri.kritik_sans += (ork->o_unit.ork_dovusculeri.kritik_sans * (bonus_degeri / 100.0));
        }
    }
    if (strstr(canavar_birimi, "mizrakcilar") != NULL)
    {
        if (strstr(bonus_turu, "saldiri") != NULL)
        {
            o_savas_ani->mizrakci_savas.toplam_saldiri_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "savunma") != NULL)
        {
            o_savas_ani->mizrakci_savas.toplam_savunma_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "kritik_sans") != NULL)
        {
            ork->o_unit.mizrakcilar.kritik_sans += (ork->o_unit.mizrakcilar.kritik_sans * (bonus_degeri / 100.0));
        }
    }
    if (strstr(canavar_birimi, "varg_biniciler") != NULL)
    {
        if (strstr(bonus_turu, "saldiri") != NULL)
        {
            o_savas_ani->varg_binici_savas.toplam_saldiri_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "savunma") != NULL)
        {
            o_savas_ani->varg_binici_savas.toplam_savunma_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "kritik_sans") != NULL)
        {
            ork->o_unit.varg_binicileri.kritik_sans += (ork->o_unit.varg_binicileri.kritik_sans * (bonus_degeri / 100.0));
        }
    }
    if (strstr(canavar_birimi, "troller") != NULL)
    {
        if (strstr(bonus_turu, "saldiri") != NULL)
        {
            o_savas_ani->troller_savas.toplam_saldiri_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "savunma") != NULL)
        {
            o_savas_ani->troller_savas.toplam_savunma_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "kritik_sans") != NULL)
        {
            ork->o_unit.troller.kritik_sans += (ork->o_unit.troller.kritik_sans * (bonus_degeri / 100.0));
        }
    }
    if (strstr(canavar_birimi, "tum_birimler") != NULL)
    {
        if (strstr(bonus_turu, "saldiri") != NULL)
        {
            o_savas_ani->ork_dovuscu_savas.toplam_saldiri_gucu *= (1 + (bonus_degeri / 100.0));
            o_savas_ani->mizrakci_savas.toplam_saldiri_gucu *= (1 + (bonus_degeri / 100.0));
            o_savas_ani->varg_binici_savas.toplam_saldiri_gucu *= (1 + (bonus_degeri / 100.0));
            o_savas_ani->troller_savas.toplam_saldiri_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "savunma") != NULL)
        {
            o_savas_ani->ork_dovuscu_savas.toplam_savunma_gucu *= (1 + (bonus_degeri / 100.0));
            o_savas_ani->mizrakci_savas.toplam_savunma_gucu *= (1 + (bonus_degeri / 100.0));
            o_savas_ani->varg_binici_savas.toplam_savunma_gucu *= (1 + (bonus_degeri / 100.0));
            o_savas_ani->troller_savas.toplam_savunma_gucu *= (1 + (bonus_degeri / 100.0));
        }
        if (strstr(bonus_turu, "kritik_sans") != NULL)
        {
            ork->o_unit.ork_dovusculeri.kritik_sans += (ork->o_unit.ork_dovusculeri.kritik_sans * (bonus_degeri / 100.0));
            ork->o_unit.mizrakcilar.kritik_sans += (ork->o_unit.mizrakcilar.kritik_sans * (bonus_degeri / 100.0));
            ork->o_unit.varg_binicileri.kritik_sans += (ork->o_unit.varg_binicileri.kritik_sans * (bonus_degeri / 100.0));
            ork->o_unit.troller.kritik_sans += (ork->o_unit.troller.kritik_sans * (bonus_degeri / 100.0));
        }
    }
}
void insan_arastirma_etkisi(struct insan_imparatorlugu *insan, struct insan_savas_ani *i_savas_ani, struct seviye *seviyeler, int seviye)
{
    if ( seviyeler != NULL)
    {
        if (strstr(seviyeler->etkiledigi_birim, "piyade") != NULL)
        {
            if (strstr(seviyeler->etki_turu, "saldiri"))
            {
                i_savas_ani->piyade_savas.toplam_saldiri_gucu *= (1 + (seviyeler->deger / 100.0));
            }
            if (strstr(seviyeler->etki_turu, "savunma"))
            {
                i_savas_ani->piyade_savas.toplam_savunma_gucu *= (1 + (seviyeler->deger / 100.0));
            }
            if (strstr(seviyeler->etki_turu, "kritik"))
            {
                insan->i_unit.piyadeler.kritik_sans += (insan->i_unit.piyadeler.kritik_sans * (seviyeler->deger / 100.0));
            }
        }
        if (strstr(seviyeler->etkiledigi_birim, "okcu") != NULL)
        {
            if (strstr(seviyeler->etki_turu, "saldiri"))
            {
                i_savas_ani->okcu_savas.toplam_saldiri_gucu *= (1 + (seviyeler->deger / 100.0));
            }
            if (strstr(seviyeler->etki_turu, "savunma"))
            {
                i_savas_ani->okcu_savas.toplam_savunma_gucu *= (1 + (seviyeler->deger / 100.0));
            }
            if (strstr(seviyeler->etki_turu, "kritik"))
            {
                insan->i_unit.okcular.kritik_sans += (insan->i_unit.okcular.kritik_sans * (seviyeler->deger / 100.0));
            }
        }
        if (strstr(seviyeler->etkiledigi_birim, "suvari") != NULL)
        {
            if (strstr(seviyeler->etki_turu, "saldiri"))
            {
                i_savas_ani->suvari_savas.toplam_saldiri_gucu *= (1 + (seviyeler->deger / 100.0));
            }
            if (strstr(seviyeler->etki_turu, "savunma"))
            {
                i_savas_ani->suvari_savas.toplam_savunma_gucu *= (1 + (seviyeler->deger / 100.0));
            }
            if (strstr(seviyeler->etki_turu, "kritik"))
            {
                insan->i_unit.suvariler.kritik_sans += (insan->i_unit.suvariler.kritik_sans * (seviyeler->deger / 100.0));
            }
        }
        if (strstr(seviyeler->etkiledigi_birim, "kusatma_makine") != NULL)
        {
            if (strstr(seviyeler->etki_turu, "saldiri"))
            {
                i_savas_ani->kusatma_makineleri_savas.toplam_saldiri_gucu *= (1 + (seviyeler->deger / 100.0));
            }
            if (strstr(seviyeler->etki_turu, "savunma"))
            {
                i_savas_ani->kusatma_makineleri_savas.toplam_savunma_gucu *= (1 + (seviyeler->deger / 100.0));
            }
            if (strstr(seviyeler->etki_turu, "kritik"))
            {
                insan->i_unit.kusatma_makineleri.kritik_sans += (insan->i_unit.kusatma_makineleri.kritik_sans * (seviyeler->deger / 100.0));
            }
        }
        if (strstr(seviyeler->etkiledigi_birim, "tum_birimler") != NULL)
        {
            if (strstr(seviyeler->etki_turu, "saldiri"))
            {
                i_savas_ani->piyade_savas.toplam_saldiri_gucu *= (1 + (seviyeler->deger / 100.0));
                i_savas_ani->okcu_savas.toplam_saldiri_gucu *= (1 + (seviyeler->deger / 100.0));
                i_savas_ani->suvari_savas.toplam_saldiri_gucu *= (1 + (seviyeler->deger / 100.0));

                i_savas_ani->kusatma_makineleri_savas.toplam_saldiri_gucu *= (1 + (seviyeler->deger / 100.0));
            }
            if (strstr(seviyeler->etki_turu, "savunma"))
            {
                i_savas_ani->piyade_savas.toplam_savunma_gucu *= (1 + (seviyeler->deger / 100.0));
                i_savas_ani->okcu_savas.toplam_savunma_gucu *= (1 + (seviyeler->deger / 100.0));
                i_savas_ani->suvari_savas.toplam_savunma_gucu *= (1 + (seviyeler->deger / 100.0));
                i_savas_ani->kusatma_makineleri_savas.toplam_savunma_gucu *= (1 + (seviyeler->deger / 100.0));
            }
            if (strstr(seviyeler->etki_turu, "kritik"))
            {
                insan->i_unit.piyadeler.kritik_sans += (insan->i_unit.piyadeler.kritik_sans * (seviyeler->deger / 100.0));
                insan->i_unit.okcular.kritik_sans += (insan->i_unit.okcular.kritik_sans * (seviyeler->deger / 100.0));
                insan->i_unit.suvariler.kritik_sans += (insan->i_unit.suvariler.kritik_sans * (seviyeler->deger / 100.0));
                insan->i_unit.kusatma_makineleri.kritik_sans += (insan->i_unit.kusatma_makineleri.kritik_sans * (seviyeler->deger / 100.0));
            }
        }
    }
}

void ork_arastirma_etkisi(struct ork_lejyonu *ork, struct ork_savas_ani *o_savas_ani, struct seviye *seviyeler, int seviye)
{

    if (seviyeler != NULL)
    {
        if (strstr(seviyeler->etkiledigi_birim, "ork_dovusculeri") != NULL)
        {
            if (strstr(seviyeler->etki_turu, "saldiri"))
            {
                o_savas_ani->ork_dovuscu_savas.toplam_saldiri_gucu *= (1 + (seviyeler->deger / 100.0));
            }
            if (strstr(seviyeler->etki_turu, "savunma"))
            {
                o_savas_ani->ork_dovuscu_savas.toplam_savunma_gucu *= (1 + (seviyeler->deger / 100.0));
            }
            if (strstr(seviyeler->etki_turu, "kritik"))
            {
                ork->o_unit.ork_dovusculeri.kritik_sans += (ork->o_unit.ork_dovusculeri.kritik_sans * (seviyeler->deger / 100.0));
            }
        }
        if (strstr(seviyeler->etkiledigi_birim, "mizrakcilar") != NULL)
        {
            if (strstr(seviyeler->etki_turu, "saldiri"))
            {
                o_savas_ani->mizrakci_savas.toplam_saldiri_gucu *= (1 + (seviyeler->deger / 100.0));
            }
            if (strstr(seviyeler->etki_turu, "savunma"))
            {
                o_savas_ani->mizrakci_savas.toplam_savunma_gucu *= (1 + (seviyeler->deger / 100.0));
            }
            if (strstr(seviyeler->etki_turu, "kritik"))
            {
                ork->o_unit.mizrakcilar.kritik_sans += (ork->o_unit.mizrakcilar.kritik_sans * (seviyeler->deger / 100.0));
            }
        }
        if (strstr(seviyeler->etkiledigi_birim, "varg_binicileri") != NULL)
        {
            if (strstr(seviyeler->etki_turu, "saldiri"))
            {
                o_savas_ani->varg_binici_savas.toplam_saldiri_gucu *= (1 + (seviyeler->deger / 100.0));
            }
            if (strstr(seviyeler->etki_turu, "savunma"))
            {
                o_savas_ani->varg_binici_savas.toplam_savunma_gucu *= (1 + (seviyeler->deger / 100.0));
            }
            if (strstr(seviyeler->etki_turu, "kritik"))
            {
                ork->o_unit.varg_binicileri.kritik_sans += (ork->o_unit.varg_binicileri.kritik_sans * (seviyeler->deger / 100.0));
            }
        }
        if (strstr(seviyeler->etkiledigi_birim, "troller") != NULL)
        {
            if (strstr(seviyeler->etki_turu, "saldiri"))
            {
                o_savas_ani->troller_savas.toplam_saldiri_gucu *= (1 + (seviyeler->deger / 100.0));
            }
            if (strstr(seviyeler->etki_turu, "savunma"))
            {
                o_savas_ani->troller_savas.toplam_savunma_gucu *= (1 + (seviyeler->deger / 100.0));
            }
            if (strstr(seviyeler->etki_turu, "kritik"))
            {
                ork->o_unit.troller.kritik_sans += (ork->o_unit.troller.kritik_sans * (seviyeler->deger / 100.0));
            }
        }
        if (strstr(seviyeler->etkiledigi_birim, "tum_birimler") != NULL)
        {
            if (strstr(seviyeler->etki_turu, "saldiri"))
            {
                o_savas_ani->ork_dovuscu_savas.toplam_saldiri_gucu *= (1 + (seviyeler->deger / 100.0));
                o_savas_ani->mizrakci_savas.toplam_saldiri_gucu *= (1 + (seviyeler->deger / 100.0));
                o_savas_ani->varg_binici_savas.toplam_saldiri_gucu *= (1 + (seviyeler->deger / 100.0));
                o_savas_ani->troller_savas.toplam_saldiri_gucu *= (1 + (seviyeler->deger / 100.0));
            }
            if (strstr(seviyeler->etki_turu, "savunma"))
            {
                o_savas_ani->ork_dovuscu_savas.toplam_savunma_gucu *= (1 + (seviyeler->deger / 100.0));
                o_savas_ani->mizrakci_savas.toplam_savunma_gucu *= (1 + (seviyeler->deger / 100.0));
                o_savas_ani->varg_binici_savas.toplam_savunma_gucu *= (1 + (seviyeler->deger / 100.0));
                o_savas_ani->troller_savas.toplam_savunma_gucu *= (1 + (seviyeler->deger / 100.0));
            }
            if (strstr(seviyeler->etki_turu, "kritik"))
            {
                ork->o_unit.ork_dovusculeri.kritik_sans += (ork->o_unit.ork_dovusculeri.kritik_sans * (seviyeler->deger / 100.0));
                ork->o_unit.mizrakcilar.kritik_sans += (ork->o_unit.mizrakcilar.kritik_sans * (seviyeler->deger / 100.0));
                ork->o_unit.varg_binicileri.kritik_sans += (ork->o_unit.varg_binicileri.kritik_sans * (seviyeler->deger / 100.0));
                ork->o_unit.troller.kritik_sans += (ork->o_unit.troller.kritik_sans * (seviyeler->deger / 100.0));
            }
        }
    }
}
void efect_belirleme_insan(struct insan_imparatorlugu_sayi* insan_sayi,struct insan_imparatorlugu* insan,int* piyade_efect,int* okcu_efect,int* suvari_efect, int* kusatma_makine_efect)
{
    if(insan_sayi->heroes_i_sayi.alparslan_sayi==1)
    {
        if(strstr(insan->i_heroes.alparslan.etkiledigi_birim,"piyade") !=NULL)
        {
            if(strstr(insan->i_heroes.alparslan.bonus_turu,"savunma") !=NULL)
            {
                if(*piyade_efect == 0)
                    *piyade_efect = 1;
                else
                    *piyade_efect = 3;
            }
            if(strstr(insan->i_heroes.alparslan.bonus_turu,"saldiri") !=NULL)
            {
                if(*piyade_efect == 0)
                    *piyade_efect = 2;
                else
                    *piyade_efect = 3;
            }
            if(strstr(insan->i_heroes.alparslan.bonus_turu,"kritik_sans"))
            {
                if(*piyade_efect == 0)
                    *piyade_efect = 4;
                else
                    *piyade_efect = 3;
            }
        }
        if(strstr(insan->i_heroes.alparslan.etkiledigi_birim,"okcu") !=NULL)
        {
            if(strstr(insan->i_heroes.alparslan.bonus_turu,"savunma") !=NULL)
            {
                if(*okcu_efect == 0)
                    *okcu_efect = 1;
                else
                    *okcu_efect = 3;
            }
            if(strstr(insan->i_heroes.alparslan.bonus_turu,"saldiri") !=NULL)
            {
                if(*okcu_efect == 0)
                    *okcu_efect = 2;
                else
                    *okcu_efect = 3;
            }
            if(strstr(insan->i_heroes.alparslan.bonus_turu,"kritik_sans"))
            {
                if(*okcu_efect == 0)
                    *okcu_efect = 4;
                else
                    *okcu_efect = 3;
            }
        }
        if(strstr(insan->i_heroes.alparslan.etkiledigi_birim,"suvari") !=NULL)
        {
            if(strstr(insan->i_heroes.alparslan.bonus_turu,"savunma") !=NULL)
            {
                if(*suvari_efect == 0)
                    *suvari_efect = 1;
                else
                    *suvari_efect = 3;
            }
            if(strstr(insan->i_heroes.alparslan.bonus_turu,"saldiri") !=NULL)
            {
                if(*suvari_efect == 0)
                    *suvari_efect = 2;
                else
                    *suvari_efect = 3;
            }
            if(strstr(insan->i_heroes.alparslan.bonus_turu,"kritik_sans"))
            {
                if(*suvari_efect == 0)
                    *suvari_efect = 4;
                else
                    *suvari_efect = 3;
            }
        }
        if(strstr(insan->i_heroes.alparslan.etkiledigi_birim,"kusatma_makine") !=NULL)
        {
            if(strstr(insan->i_heroes.alparslan.bonus_turu,"savunma") !=NULL)
            {
                if(*kusatma_makine_efect == 0)
                    *kusatma_makine_efect = 1;
                else
                    *kusatma_makine_efect = 3;
            }
            if(strstr(insan->i_heroes.alparslan.bonus_turu,"saldiri") !=NULL)
            {
                if(*kusatma_makine_efect == 0)
                    *kusatma_makine_efect = 2;
                else
                    *kusatma_makine_efect = 3;
            }
            if(strstr(insan->i_heroes.alparslan.bonus_turu,"kritik_sans"))
            {
                if(*kusatma_makine_efect == 0)
                    *kusatma_makine_efect = 4;
                else
                    *kusatma_makine_efect = 3;
            }
        }

    }
    if(insan_sayi->heroes_i_sayi.fatih_sultan_mehmet_sayi==1)
    {
        if(strstr(insan->i_heroes.fatih_Sultan_Mehmet.etkiledigi_birim,"piyade") !=NULL)
        {
            if(strstr(insan->i_heroes.fatih_Sultan_Mehmet.bonus_turu,"savunma") !=NULL)
            {
                if(*piyade_efect == 0)
                    *piyade_efect = 1;
                else
                    *piyade_efect = 3;
            }
            if(strstr(insan->i_heroes.fatih_Sultan_Mehmet.bonus_turu,"saldiri") !=NULL)
            {
                if(*piyade_efect == 0)
                    *piyade_efect = 2;
                else
                    *piyade_efect = 3;
            }
            if(strstr(insan->i_heroes.fatih_Sultan_Mehmet.bonus_turu,"kritik_sans"))
            {
                if(*piyade_efect == 0)
                    *piyade_efect = 4;
                else
                    *piyade_efect = 3;
            }
        }
        if(strstr(insan->i_heroes.fatih_Sultan_Mehmet.etkiledigi_birim,"okcu") !=NULL)
        {
            if(strstr(insan->i_heroes.fatih_Sultan_Mehmet.bonus_turu,"savunma") !=NULL)
            {
                if(*okcu_efect == 0)
                    *okcu_efect = 1;
                else
                    *okcu_efect = 3;
            }
            if(strstr(insan->i_heroes.fatih_Sultan_Mehmet.bonus_turu,"saldiri") !=NULL)
            {
                if(*okcu_efect == 0)
                    *okcu_efect = 2;
                else
                    *okcu_efect = 3;
            }
            if(strstr(insan->i_heroes.fatih_Sultan_Mehmet.bonus_turu,"kritik_sans"))
            {
                if(*okcu_efect == 0)
                    *okcu_efect = 4;
                else
                    *okcu_efect = 3;
            }
        }
        if(strstr(insan->i_heroes.fatih_Sultan_Mehmet.etkiledigi_birim,"suvari") !=NULL)
        {
            if(strstr(insan->i_heroes.fatih_Sultan_Mehmet.bonus_turu,"savunma") !=NULL)
            {
                if(*suvari_efect == 0)
                    *suvari_efect = 1;
                else
                    *suvari_efect = 3;
            }
            if(strstr(insan->i_heroes.fatih_Sultan_Mehmet.bonus_turu,"saldiri") !=NULL)
            {
                if(*suvari_efect == 0)
                    *suvari_efect = 2;
                else
                    *suvari_efect = 3;
            }
            if(strstr(insan->i_heroes.fatih_Sultan_Mehmet.bonus_turu,"kritik_sans"))
            {
                if(*suvari_efect == 0)
                    *suvari_efect = 4;
                else
                    *suvari_efect = 3;
            }
        }
        if(strstr(insan->i_heroes.fatih_Sultan_Mehmet.etkiledigi_birim,"kusatma_makine") !=NULL)
        {
            if(strstr(insan->i_heroes.fatih_Sultan_Mehmet.bonus_turu,"savunma") !=NULL)
            {
                if(*kusatma_makine_efect == 0)
                    *kusatma_makine_efect = 1;
                else
                    *kusatma_makine_efect = 3;
            }
            if(strstr(insan->i_heroes.fatih_Sultan_Mehmet.bonus_turu,"saldiri") !=NULL)
            {
                if(*kusatma_makine_efect == 0)
                    *kusatma_makine_efect = 2;
                else
                    *kusatma_makine_efect = 3;
            }
            if(strstr(insan->i_heroes.fatih_Sultan_Mehmet.bonus_turu,"kritik_sans"))
            {
                if(*kusatma_makine_efect == 0)
                    *kusatma_makine_efect = 4;
                else
                    *kusatma_makine_efect = 3;
            }
        }
    }
    if(insan_sayi->heroes_i_sayi.mete_han_sayi==1)
    {
        if(strstr(insan->i_heroes.mete_Han.etkiledigi_birim,"piyade") !=NULL)
        {
            if(strstr(insan->i_heroes.mete_Han.bonus_turu,"savunma") !=NULL)
            {
                if(*piyade_efect == 0)
                    *piyade_efect = 1;
                else
                    *piyade_efect = 3;
            }
            if(strstr(insan->i_heroes.mete_Han.bonus_turu,"saldiri") !=NULL)
            {
                if(*piyade_efect == 0)
                    *piyade_efect = 2;
                else
                    *piyade_efect = 3;
            }
            if(strstr(insan->i_heroes.mete_Han.bonus_turu,"kritik_sans"))
            {
                if(*piyade_efect == 0)
                    *piyade_efect = 4;
                else
                    *piyade_efect = 3;
            }
        }
        if(strstr(insan->i_heroes.mete_Han.etkiledigi_birim,"okcu") !=NULL)
        {
            if(strstr(insan->i_heroes.mete_Han.bonus_turu,"savunma") !=NULL)
            {
                if(*okcu_efect == 0)
                    *okcu_efect = 1;
                else
                    *okcu_efect = 3;
            }
            if(strstr(insan->i_heroes.mete_Han.bonus_turu,"saldiri") !=NULL)
            {
                if(*okcu_efect == 0)
                    *okcu_efect = 2;
                else
                    *okcu_efect = 3;
            }
            if(strstr(insan->i_heroes.mete_Han.bonus_turu,"kritik_sans"))
            {
                if(*okcu_efect == 0)
                    *okcu_efect = 4;
                else
                    *okcu_efect = 3;
            }
        }
        if(strstr(insan->i_heroes.mete_Han.etkiledigi_birim,"suvari") !=NULL)
        {
            if(strstr(insan->i_heroes.mete_Han.bonus_turu,"savunma") !=NULL)
            {
                if(*suvari_efect == 0)
                    *suvari_efect = 1;
                else
                    *suvari_efect = 3;
            }
            if(strstr(insan->i_heroes.mete_Han.bonus_turu,"saldiri") !=NULL)
            {
                if(*suvari_efect == 0)
                    *suvari_efect = 2;
                else
                    *suvari_efect = 3;
            }
            if(strstr(insan->i_heroes.mete_Han.bonus_turu,"kritik_sans"))
            {
                if(*suvari_efect == 0)
                    *suvari_efect = 4;
                else
                    *suvari_efect = 3;
            }
        }
        if(strstr(insan->i_heroes.mete_Han.etkiledigi_birim,"kusatma_makine") !=NULL)
        {
            if(strstr(insan->i_heroes.mete_Han.bonus_turu,"savunma") !=NULL)
            {
                if(*kusatma_makine_efect == 0)
                    *kusatma_makine_efect = 1;
                else
                    *kusatma_makine_efect = 3;
            }
            if(strstr(insan->i_heroes.mete_Han.bonus_turu,"saldiri") !=NULL)
            {
                if(*kusatma_makine_efect == 0)
                    *kusatma_makine_efect = 2;
                else
                    *kusatma_makine_efect = 3;
            }
            if(strstr(insan->i_heroes.mete_Han.bonus_turu,"kritik_sans"))
            {
                if(*kusatma_makine_efect == 0)
                    *kusatma_makine_efect = 4;
                else
                    *kusatma_makine_efect = 3;
            }
        }
    }
    if(insan_sayi->heroes_i_sayi.tugrul_bey_sayi==1)
    {
        if(strstr(insan->i_heroes.tugrul_Bey.etkiledigi_birim,"piyade") !=NULL)
        {
            if(strstr(insan->i_heroes.tugrul_Bey.bonus_turu,"savunma") !=NULL)
            {
                if(*piyade_efect == 0)
                    *piyade_efect = 1;
                else
                    *piyade_efect = 3;
            }
            if(strstr(insan->i_heroes.tugrul_Bey.bonus_turu,"saldiri") !=NULL)
            {
                if(*piyade_efect == 0)
                    *piyade_efect = 2;
                else
                    *piyade_efect = 3;
            }
            if(strstr(insan->i_heroes.tugrul_Bey.bonus_turu,"kritik_sans"))
            {
                if(*piyade_efect == 0)
                    *piyade_efect = 4;
                else
                    *piyade_efect = 3;
            }
        }
        if(strstr(insan->i_heroes.tugrul_Bey.etkiledigi_birim,"okcu") !=NULL)
        {
            if(strstr(insan->i_heroes.tugrul_Bey.bonus_turu,"savunma") !=NULL)
            {
                if(*okcu_efect == 0)
                    *okcu_efect = 1;
                else
                    *okcu_efect = 3;
            }
            if(strstr(insan->i_heroes.tugrul_Bey.bonus_turu,"saldiri") !=NULL)
            {
                if(*okcu_efect == 0)
                    *okcu_efect = 2;
                else
                    *okcu_efect = 3;
            }
            if(strstr(insan->i_heroes.tugrul_Bey.bonus_turu,"kritik_sans"))
            {
                if(*okcu_efect == 0)
                    *okcu_efect = 4;
                else
                    *okcu_efect = 3;
            }
        }
        if(strstr(insan->i_heroes.tugrul_Bey.etkiledigi_birim,"suvari") !=NULL)
        {
            if(strstr(insan->i_heroes.tugrul_Bey.bonus_turu,"savunma") !=NULL)
            {
                if(*suvari_efect == 0)
                    *suvari_efect = 1;
                else
                    *suvari_efect = 3;
            }
            if(strstr(insan->i_heroes.tugrul_Bey.bonus_turu,"saldiri") !=NULL)
            {
                if(*suvari_efect == 0)
                    *suvari_efect = 2;
                else
                    *suvari_efect = 3;
            }
            if(strstr(insan->i_heroes.tugrul_Bey.bonus_turu,"kritik_sans"))
            {
                if(*suvari_efect == 0)
                    *suvari_efect = 4;
                else
                    *suvari_efect = 3;
            }
        }
        if(strstr(insan->i_heroes.tugrul_Bey.etkiledigi_birim,"kusatma_makine") !=NULL)
        {
            if(strstr(insan->i_heroes.tugrul_Bey.bonus_turu,"savunma") !=NULL)
            {
                if(*kusatma_makine_efect == 0)
                    *kusatma_makine_efect = 1;
                else
                    *kusatma_makine_efect = 3;
            }
            if(strstr(insan->i_heroes.tugrul_Bey.bonus_turu,"saldiri") !=NULL)
            {
                if(*kusatma_makine_efect == 0)
                    *kusatma_makine_efect = 2;
                else
                    *kusatma_makine_efect = 3;
            }
            if(strstr(insan->i_heroes.tugrul_Bey.bonus_turu,"kritik_sans"))
            {
                if(*kusatma_makine_efect == 0)
                    *kusatma_makine_efect = 4;
                else
                    *kusatma_makine_efect = 3;
            }
        }
    }
    if(insan_sayi->heroes_i_sayi.yavuz_sultan_selim_sayi==1)
    {

        if(strstr(insan->i_heroes.yavuz_Sultan_Selim.etkiledigi_birim,"piyade") !=NULL)
        {
            if(strstr(insan->i_heroes.yavuz_Sultan_Selim.bonus_turu,"savunma") !=NULL)
            {
                if(*piyade_efect == 0)
                    *piyade_efect = 1;
                else
                    *piyade_efect = 3;
            }
            if(strstr(insan->i_heroes.yavuz_Sultan_Selim.bonus_turu,"saldiri") !=NULL)
            {
                if(*piyade_efect == 0)
                    *piyade_efect = 2;
                else
                    *piyade_efect = 3;
            }
            if(strstr(insan->i_heroes.yavuz_Sultan_Selim.bonus_turu,"kritik_sans"))
            {
                if(*piyade_efect == 0)
                    *piyade_efect = 4;
                else
                    *piyade_efect = 3;
            }
        }
        if(strstr(insan->i_heroes.yavuz_Sultan_Selim.etkiledigi_birim,"okcu") !=NULL)
        {
            if(strstr(insan->i_heroes.yavuz_Sultan_Selim.bonus_turu,"savunma") !=NULL)
            {
                if(*okcu_efect == 0)
                    *okcu_efect = 1;
                else
                    *okcu_efect = 3;
            }
            if(strstr(insan->i_heroes.yavuz_Sultan_Selim.bonus_turu,"saldiri") !=NULL)
            {
                if(*okcu_efect == 0)
                    *okcu_efect = 2;
                else
                    *okcu_efect = 3;
            }
            if(strstr(insan->i_heroes.yavuz_Sultan_Selim.bonus_turu,"kritik_sans"))
            {
                if(*okcu_efect == 0)
                    *okcu_efect = 4;
                else
                    *okcu_efect = 3;
            }
        }
        if(strstr(insan->i_heroes.yavuz_Sultan_Selim.etkiledigi_birim,"suvari") !=NULL)
        {
            if(strstr(insan->i_heroes.yavuz_Sultan_Selim.bonus_turu,"savunma") !=NULL)
            {
                if(*suvari_efect == 0)
                    *suvari_efect = 1;
                else
                    *suvari_efect = 3;
            }
            if(strstr(insan->i_heroes.yavuz_Sultan_Selim.bonus_turu,"saldiri") !=NULL)
            {
                if(*suvari_efect == 0)
                    *suvari_efect = 2;
                else
                    *suvari_efect = 3;
            }
            if(strstr(insan->i_heroes.yavuz_Sultan_Selim.bonus_turu,"kritik_sans"))
            {
                if(*suvari_efect == 0)
                    *suvari_efect = 4;
                else
                    *suvari_efect = 3;
            }
        }
        if(strstr(insan->i_heroes.yavuz_Sultan_Selim.etkiledigi_birim,"kusatma_makine") !=NULL)
        {
            if(strstr(insan->i_heroes.yavuz_Sultan_Selim.bonus_turu,"savunma") !=NULL)
            {
                if(*kusatma_makine_efect == 0)
                    *kusatma_makine_efect = 1;
                else
                    *kusatma_makine_efect = 3;
            }
            if(strstr(insan->i_heroes.yavuz_Sultan_Selim.bonus_turu,"saldiri") !=NULL)
            {
                if(*kusatma_makine_efect == 0)
                    *kusatma_makine_efect = 2;
                else
                    *kusatma_makine_efect = 3;
            }
            if(strstr(insan->i_heroes.yavuz_Sultan_Selim.bonus_turu,"kritik_sans"))
            {
                if(*kusatma_makine_efect == 0)
                    *kusatma_makine_efect = 4;
                else
                    *kusatma_makine_efect = 3;
            }
        }
    }
    if(insan_sayi->creatures_i_sayi.agri_dagi_devi_sayi==1)
    {
        if(strstr(insan->i_creatures.agri_Dagi_Devleri.etkiledigi_birim,"piyade") !=NULL)
        {
            if(strstr(insan->i_creatures.agri_Dagi_Devleri.bonus_turu,"savunma") !=NULL)
            {
                if(*piyade_efect == 0)
                    *piyade_efect = 1;
                else
                    *piyade_efect = 3;
            }
            if(strstr(insan->i_creatures.agri_Dagi_Devleri.bonus_turu,"saldiri") !=NULL)
            {
                if(*piyade_efect == 0)
                    *piyade_efect = 2;
                else
                    *piyade_efect = 3;
            }
            if(strstr(insan->i_creatures.agri_Dagi_Devleri.bonus_turu,"kritik_sans"))
            {
                if(*piyade_efect == 0)
                    *piyade_efect = 4;
                else
                    *piyade_efect = 3;
            }
        }
        if(strstr(insan->i_creatures.agri_Dagi_Devleri.etkiledigi_birim,"okcu") !=NULL)
        {
            if(strstr(insan->i_creatures.agri_Dagi_Devleri.bonus_turu,"savunma") !=NULL)
            {
                if(*okcu_efect == 0)
                    *okcu_efect = 1;
                else
                    *okcu_efect = 3;
            }
            if(strstr(insan->i_creatures.agri_Dagi_Devleri.bonus_turu,"saldiri") !=NULL)
            {
                if(*okcu_efect == 0)
                    *okcu_efect = 2;
                else
                    *okcu_efect = 3;
            }
            if(strstr(insan->i_creatures.agri_Dagi_Devleri.bonus_turu,"kritik_sans"))
            {
                if(*okcu_efect == 0)
                    *okcu_efect = 4;
                else
                    *okcu_efect = 3;
            }
        }
        if(strstr(insan->i_creatures.agri_Dagi_Devleri.etkiledigi_birim,"suvari") !=NULL)
        {
            if(strstr(insan->i_creatures.agri_Dagi_Devleri.bonus_turu,"savunma") !=NULL)
            {
                if(*suvari_efect == 0)
                    *suvari_efect = 1;
                else
                    *suvari_efect = 3;
            }
            if(strstr(insan->i_creatures.agri_Dagi_Devleri.bonus_turu,"saldiri") !=NULL)
            {
                if(*suvari_efect == 0)
                    *suvari_efect = 2;
                else
                    *suvari_efect = 3;
            }
            if(strstr(insan->i_creatures.agri_Dagi_Devleri.bonus_turu,"kritik_sans"))
            {
                if(*suvari_efect == 0)
                    *suvari_efect = 4;
                else
                    *suvari_efect = 3;
            }
        }
        if(strstr(insan->i_creatures.agri_Dagi_Devleri.etkiledigi_birim,"kusatma_makine") !=NULL)
        {
            if(strstr(insan->i_creatures.agri_Dagi_Devleri.bonus_turu,"savunma") !=NULL)
            {
                if(*kusatma_makine_efect == 0)
                    *kusatma_makine_efect = 1;
                else
                    *kusatma_makine_efect = 3;
            }
            if(strstr(insan->i_creatures.agri_Dagi_Devleri.bonus_turu,"saldiri") !=NULL)
            {
                if(*kusatma_makine_efect == 0)
                    *kusatma_makine_efect = 2;
                else
                    *kusatma_makine_efect = 3;
            }
            if(strstr(insan->i_creatures.agri_Dagi_Devleri.bonus_turu,"kritik_sans"))
            {
                if(*kusatma_makine_efect == 0)
                    *kusatma_makine_efect = 4;
                else
                    *kusatma_makine_efect = 3;
            }
        }
    }
    if(insan_sayi->creatures_i_sayi.ejderha_sayi==1)
    {
        if(strstr(insan->i_creatures.ejderha.etkiledigi_birim,"piyade") !=NULL)
        {
            if(strstr(insan->i_creatures.ejderha.bonus_turu,"savunma") !=NULL)
            {
                if(*piyade_efect == 0)
                    *piyade_efect = 1;
                else
                    *piyade_efect = 3;
            }
            if(strstr(insan->i_creatures.ejderha.bonus_turu,"saldiri") !=NULL)
            {
                if(*piyade_efect == 0)
                    *piyade_efect = 2;
                else
                    *piyade_efect = 3;
            }
            if(strstr(insan->i_creatures.ejderha.bonus_turu,"kritik_sans"))
            {
                if(*piyade_efect == 0)
                    *piyade_efect = 4;
                else
                    *piyade_efect = 3;
            }
        }
        if(strstr(insan->i_creatures.ejderha.etkiledigi_birim,"okcu") !=NULL)
        {
            if(strstr(insan->i_creatures.ejderha.bonus_turu,"savunma") !=NULL)
            {
                if(*okcu_efect == 0)
                    *okcu_efect = 1;
                else
                    *okcu_efect = 3;
            }
            if(strstr(insan->i_creatures.ejderha.bonus_turu,"saldiri") !=NULL)
            {
                if(*okcu_efect == 0)
                    *okcu_efect = 2;
                else
                    *okcu_efect = 3;
            }
            if(strstr(insan->i_creatures.ejderha.bonus_turu,"kritik_sans"))
            {
                if(*okcu_efect == 0)
                    *okcu_efect = 4;
                else
                    *okcu_efect = 3;
            }
        }
        if(strstr(insan->i_creatures.ejderha.etkiledigi_birim,"suvari") !=NULL)
        {
            if(strstr(insan->i_creatures.ejderha.bonus_turu,"savunma") !=NULL)
            {
                if(*suvari_efect == 0)
                    *suvari_efect = 1;
                else
                    *suvari_efect = 3;
            }
            if(strstr(insan->i_creatures.ejderha.bonus_turu,"saldiri") !=NULL)
            {
                if(*suvari_efect == 0)
                    *suvari_efect = 2;
                else
                    *suvari_efect = 3;
            }
            if(strstr(insan->i_creatures.ejderha.bonus_turu,"kritik_sans"))
            {
                if(*suvari_efect == 0)
                    *suvari_efect = 4;
                else
                    *suvari_efect = 3;
            }
        }
        if(strstr(insan->i_creatures.ejderha.etkiledigi_birim,"kusatma_makine") !=NULL)
        {
            if(strstr(insan->i_creatures.ejderha.bonus_turu,"savunma") !=NULL)
            {
                if(*kusatma_makine_efect == 0)
                    *kusatma_makine_efect = 1;
                else
                    *kusatma_makine_efect = 3;
            }
            if(strstr(insan->i_creatures.ejderha.bonus_turu,"saldiri") !=NULL)
            {
                if(*kusatma_makine_efect == 0)
                    *kusatma_makine_efect = 2;
                else
                    *kusatma_makine_efect = 3;
            }
            if(strstr(insan->i_creatures.ejderha.bonus_turu,"kritik_sans"))
            {
                if(*kusatma_makine_efect == 0)
                    *kusatma_makine_efect = 4;
                else
                    *kusatma_makine_efect = 3;
            }
        }
    }
    if(insan_sayi->creatures_i_sayi.karakurt_sayi==1)
    {
        if(strstr(insan->i_creatures.karakurt.etkiledigi_birim,"piyade") !=NULL)
        {
            if(strstr(insan->i_creatures.karakurt.bonus_turu,"savunma") !=NULL)
            {
                if(*piyade_efect == 0)
                    *piyade_efect = 1;
                else
                    *piyade_efect = 3;
            }
            if(strstr(insan->i_creatures.karakurt.bonus_turu,"saldiri") !=NULL)
            {
                if(*piyade_efect == 0)
                    *piyade_efect = 2;
                else
                    *piyade_efect = 3;
            }
            if(strstr(insan->i_creatures.karakurt.bonus_turu,"kritik_sans"))
            {
                if(*piyade_efect == 0)
                    *piyade_efect = 4;
                else
                    *piyade_efect = 3;
            }
        }
        if(strstr(insan->i_creatures.karakurt.etkiledigi_birim,"okcu") !=NULL)
        {
            if(strstr(insan->i_creatures.karakurt.bonus_turu,"savunma") !=NULL)
            {
                if(*okcu_efect == 0)
                    *okcu_efect = 1;
                else
                    *okcu_efect = 3;
            }
            if(strstr(insan->i_creatures.karakurt.bonus_turu,"saldiri") !=NULL)
            {
                if(*okcu_efect == 0)
                    *okcu_efect = 2;
                else
                    *okcu_efect = 3;
            }
            if(strstr(insan->i_creatures.karakurt.bonus_turu,"kritik_sans"))
            {
                if(*okcu_efect == 0)
                    *okcu_efect = 4;
                else
                    *okcu_efect = 3;
            }
        }
        if(strstr(insan->i_creatures.karakurt.etkiledigi_birim,"suvari") !=NULL)
        {
            if(strstr(insan->i_creatures.karakurt.bonus_turu,"savunma") !=NULL)
            {
                if(*suvari_efect == 0)
                    *suvari_efect = 1;
                else
                    *suvari_efect = 3;
            }
            if(strstr(insan->i_creatures.karakurt.bonus_turu,"saldiri") !=NULL)
            {
                if(*suvari_efect == 0)
                    *suvari_efect = 2;
                else
                    *suvari_efect = 3;
            }
            if(strstr(insan->i_creatures.karakurt.bonus_turu,"kritik_sans"))
            {
                if(*suvari_efect == 0)
                    *suvari_efect = 4;
                else
                    *suvari_efect = 3;
            }
        }
        if(strstr(insan->i_creatures.karakurt.etkiledigi_birim,"kusatma_makine") !=NULL)
        {
            if(strstr(insan->i_creatures.karakurt.bonus_turu,"savunma") !=NULL)
            {
                if(*kusatma_makine_efect == 0)
                    *kusatma_makine_efect = 1;
                else
                    *kusatma_makine_efect = 3;
            }
            if(strstr(insan->i_creatures.karakurt.bonus_turu,"saldiri") !=NULL)
            {
                if(*kusatma_makine_efect == 0)
                    *kusatma_makine_efect = 2;
                else
                    *kusatma_makine_efect = 3;
            }
            if(strstr(insan->i_creatures.karakurt.bonus_turu,"kritik_sans"))
            {
                if(*kusatma_makine_efect == 0)
                    *kusatma_makine_efect = 4;
                else
                    *kusatma_makine_efect = 3;
            }
        }
    }
    if(insan_sayi->creatures_i_sayi.samur_sayi==1)
    {
        if(strstr(insan->i_creatures.samur.etkiledigi_birim,"piyade") !=NULL)
        {
            if(strstr(insan->i_creatures.samur.bonus_turu,"savunma") !=NULL)
            {
                if(*piyade_efect == 0)
                    *piyade_efect = 1;
                else
                    *piyade_efect = 3;
            }
            if(strstr(insan->i_creatures.samur.bonus_turu,"saldiri") !=NULL)
            {
                if(*piyade_efect == 0)
                    *piyade_efect = 2;
                else
                    *piyade_efect = 3;
            }
            if(strstr(insan->i_creatures.samur.bonus_turu,"kritik_sans"))
            {
                if(*piyade_efect == 0)
                    *piyade_efect = 4;
                else
                    *piyade_efect = 3;
            }
        }
        if(strstr(insan->i_creatures.samur.etkiledigi_birim,"okcu") !=NULL)
        {
            if(strstr(insan->i_creatures.samur.bonus_turu,"savunma") !=NULL)
            {
                if(*okcu_efect == 0)
                    *okcu_efect = 1;
                else
                    *okcu_efect = 3;
            }
            if(strstr(insan->i_creatures.samur.bonus_turu,"saldiri") !=NULL)
            {
                if(*okcu_efect == 0)
                    *okcu_efect = 2;
                else
                    *okcu_efect = 3;
            }
            if(strstr(insan->i_creatures.samur.bonus_turu,"kritik_sans"))
            {
                if(*okcu_efect == 0)
                    *okcu_efect = 4;
                else
                    *okcu_efect = 3;
            }
        }
        if(strstr(insan->i_creatures.samur.etkiledigi_birim,"suvari") !=NULL)
        {
            if(strstr(insan->i_creatures.samur.bonus_turu,"savunma") !=NULL)
            {
                if(*suvari_efect == 0)
                    *suvari_efect = 1;
                else
                    *suvari_efect = 3;
            }
            if(strstr(insan->i_creatures.samur.bonus_turu,"saldiri") !=NULL)
            {
                if(*suvari_efect == 0)
                    *suvari_efect = 2;
                else
                    *suvari_efect = 3;
            }
            if(strstr(insan->i_creatures.samur.bonus_turu,"kritik_sans"))
            {
                if(*suvari_efect == 0)
                    *suvari_efect = 4;
                else
                    *suvari_efect = 3;
            }
        }
        if(strstr(insan->i_creatures.samur.etkiledigi_birim,"kusatma_makine") !=NULL)
        {
            if(strstr(insan->i_creatures.samur.bonus_turu,"savunma") !=NULL)
            {
                if(*kusatma_makine_efect == 0)
                    *kusatma_makine_efect = 1;
                else
                    *kusatma_makine_efect = 3;
            }
            if(strstr(insan->i_creatures.samur.bonus_turu,"saldiri") !=NULL)
            {
                if(*kusatma_makine_efect == 0)
                    *kusatma_makine_efect = 2;
                else
                    *kusatma_makine_efect = 3;
            }
            if(strstr(insan->i_creatures.samur.bonus_turu,"kritik_sans"))
            {
                if(*kusatma_makine_efect == 0)
                    *kusatma_makine_efect = 4;
                else
                    *kusatma_makine_efect = 3;
            }
        }
    }
    if(insan_sayi->creatures_i_sayi.tepegoz_sayi==1)
    {

        if(strstr(insan->i_creatures.tepegoz.etkiledigi_birim,"piyade") !=NULL)
        {
            if(strstr(insan->i_creatures.tepegoz.bonus_turu,"savunma") !=NULL)
            {
                if(*piyade_efect == 0)
                    *piyade_efect = 1;
                else
                    *piyade_efect = 3;
            }
            if(strstr(insan->i_creatures.tepegoz.bonus_turu,"saldiri") !=NULL)
            {
                if(*piyade_efect == 0)
                    *piyade_efect = 2;
                else
                    *piyade_efect = 3;
            }
            if(strstr(insan->i_creatures.tepegoz.bonus_turu,"kritik_sans"))
            {
                if(*piyade_efect == 0)
                    *piyade_efect = 4;
                else
                    *piyade_efect = 3;
            }
        }
        if(strstr(insan->i_creatures.tepegoz.etkiledigi_birim,"okcu") !=NULL)
        {
            if(strstr(insan->i_creatures.tepegoz.bonus_turu,"savunma") !=NULL)
            {
                if(*okcu_efect == 0)
                    *okcu_efect = 1;
                else
                    *okcu_efect = 3;
            }
            if(strstr(insan->i_creatures.tepegoz.bonus_turu,"saldiri") !=NULL)
            {
                if(*okcu_efect == 0)
                    *okcu_efect = 2;
                else
                    *okcu_efect = 3;
            }
            if(strstr(insan->i_creatures.tepegoz.bonus_turu,"kritik_sans"))
            {
                if(*okcu_efect == 0)
                    *okcu_efect = 4;
                else
                    *okcu_efect = 3;
            }
        }
        if(strstr(insan->i_creatures.tepegoz.etkiledigi_birim,"suvari") !=NULL)
        {
            if(strstr(insan->i_creatures.tepegoz.bonus_turu,"savunma") !=NULL)
            {
                if(*suvari_efect == 0)
                    *suvari_efect = 1;
                else
                    *suvari_efect = 3;
            }
            if(strstr(insan->i_creatures.tepegoz.bonus_turu,"saldiri") !=NULL)
            {
                if(*suvari_efect == 0)
                    *suvari_efect = 2;
                else
                    *suvari_efect = 3;
            }
            if(strstr(insan->i_creatures.tepegoz.bonus_turu,"kritik_sans"))
            {
                if(*suvari_efect == 0)
                    *suvari_efect = 4;
                else
                    *suvari_efect = 3;
            }
        }
        if(strstr(insan->i_creatures.tepegoz.etkiledigi_birim,"kusatma_makine") !=NULL)
        {
            if(strstr(insan->i_creatures.tepegoz.bonus_turu,"savunma") !=NULL)
            {
                if(*kusatma_makine_efect == 0)
                    *kusatma_makine_efect = 1;
                else
                    *kusatma_makine_efect = 3;
            }
            if(strstr(insan->i_creatures.tepegoz.bonus_turu,"saldiri") !=NULL)
            {
                if(*kusatma_makine_efect == 0)
                    *kusatma_makine_efect = 2;
                else
                    *kusatma_makine_efect = 3;
            }
            if(strstr(insan->i_creatures.tepegoz.bonus_turu,"kritik_sans"))
            {
                if(*kusatma_makine_efect == 0)
                    *kusatma_makine_efect = 4;
                else
                    *kusatma_makine_efect = 3;
            }
        }
    }
}
void efect_belirleme_ork(struct ork_lejyonu_sayi* ork_sayi,struct ork_lejyonu* ork,int* ork_dovuscu_efect,int* mizrakci_efect,int* varg_binici_efect, int* trol_efect)
{
    if(ork_sayi->heroes_o_sayi.goruk_vahsi_sayi==1)
    {
        if(strstr(ork->o_heroes.goruk_Vahsi.etkiledigi_birim,"ork_dovuscu") !=NULL)
        {
            if(strstr(ork->o_heroes.goruk_Vahsi.bonus_turu,"savunma") !=NULL)
            {
                if(*ork_dovuscu_efect == 0)
                    *ork_dovuscu_efect = 1;
                else
                    *ork_dovuscu_efect = 3;
            }
            if(strstr(ork->o_heroes.goruk_Vahsi.bonus_turu,"saldiri") !=NULL)
            {
                if(*ork_dovuscu_efect == 0)
                    *ork_dovuscu_efect = 2;
                else
                    *ork_dovuscu_efect = 3;
            }
            if(strstr(ork->o_heroes.goruk_Vahsi.bonus_turu,"kritik_sans"))
            {
                if(*ork_dovuscu_efect == 0)
                    *ork_dovuscu_efect = 4;
                else
                    *ork_dovuscu_efect = 3;
            }
        }
        if(strstr(ork->o_heroes.goruk_Vahsi.etkiledigi_birim,"mizrakci") !=NULL)
        {
            if(strstr(ork->o_heroes.goruk_Vahsi.bonus_turu,"savunma") !=NULL)
            {
                if(*mizrakci_efect == 0)
                    *mizrakci_efect = 1;
                else
                    *mizrakci_efect = 3;
            }
            if(strstr(ork->o_heroes.goruk_Vahsi.bonus_turu,"saldiri") !=NULL)
            {
                if(*mizrakci_efect == 0)
                    *mizrakci_efect = 2;
                else
                    *mizrakci_efect = 3;
            }
            if(strstr(ork->o_heroes.goruk_Vahsi.bonus_turu,"kritik_sans"))
            {
                if(*mizrakci_efect == 0)
                    *mizrakci_efect = 4;
                else
                    *mizrakci_efect = 3;
            }
        }
        if(strstr(ork->o_heroes.goruk_Vahsi.etkiledigi_birim,"varg_binici") !=NULL)
        {
            if(strstr(ork->o_heroes.goruk_Vahsi.bonus_turu,"savunma") !=NULL)
            {
                if(*varg_binici_efect == 0)
                    *varg_binici_efect = 1;
                else
                    *varg_binici_efect = 3;
            }
            if(strstr(ork->o_heroes.goruk_Vahsi.bonus_turu,"saldiri") !=NULL)
            {
                if(*varg_binici_efect == 0)
                    *varg_binici_efect = 2;
                else
                    *varg_binici_efect = 3;
            }
            if(strstr(ork->o_heroes.goruk_Vahsi.bonus_turu,"kritik_sans"))
            {
                if(*varg_binici_efect == 0)
                    *varg_binici_efect = 4;
                else
                    *varg_binici_efect = 3;
            }
        }
        if(strstr(ork->o_heroes.goruk_Vahsi.etkiledigi_birim,"trol") !=NULL)
        {
            if(strstr(ork->o_heroes.goruk_Vahsi.bonus_turu,"savunma") !=NULL)
            {
                if(*trol_efect == 0)
                    *trol_efect = 1;
                else
                    *trol_efect = 3;
            }
            if(strstr(ork->o_heroes.goruk_Vahsi.bonus_turu,"saldiri") !=NULL)
            {
                if(*trol_efect == 0)
                    *trol_efect = 2;
                else
                    *trol_efect = 3;
            }
            if(strstr(ork->o_heroes.goruk_Vahsi.bonus_turu,"kritik_sans"))
            {
                if(*trol_efect == 0)
                    *trol_efect = 4;
                else
                    *trol_efect = 3;
            }
        }
    }
    if(ork_sayi->heroes_o_sayi.thruk_kemikkiran_sayi==1)
    {
        if(strstr(ork->o_heroes.thruk_Kemikkiran.etkiledigi_birim,"ork_dovuscu") !=NULL)
        {
            if(strstr(ork->o_heroes.thruk_Kemikkiran.bonus_turu,"savunma") !=NULL)
            {
                if(*ork_dovuscu_efect == 0)
                    *ork_dovuscu_efect = 1;
                else
                    *ork_dovuscu_efect = 3;
            }
            if(strstr(ork->o_heroes.thruk_Kemikkiran.bonus_turu,"saldiri") !=NULL)
            {
                if(*ork_dovuscu_efect == 0)
                    *ork_dovuscu_efect = 2;
                else
                    *ork_dovuscu_efect = 3;
            }
            if(strstr(ork->o_heroes.thruk_Kemikkiran.bonus_turu,"kritik_sans"))
            {
                if(*ork_dovuscu_efect == 0)
                    *ork_dovuscu_efect = 4;
                else
                    *ork_dovuscu_efect = 3;
            }
        }
        if(strstr(ork->o_heroes.thruk_Kemikkiran.etkiledigi_birim,"mizrakci") !=NULL)
        {
            if(strstr(ork->o_heroes.thruk_Kemikkiran.bonus_turu,"savunma") !=NULL)
            {
                if(*mizrakci_efect == 0)
                    *mizrakci_efect = 1;
                else
                    *mizrakci_efect = 3;
            }
            if(strstr(ork->o_heroes.thruk_Kemikkiran.bonus_turu,"saldiri") !=NULL)
            {
                if(*mizrakci_efect == 0)
                    *mizrakci_efect = 2;
                else
                    *mizrakci_efect = 3;
            }
            if(strstr(ork->o_heroes.thruk_Kemikkiran.bonus_turu,"kritik_sans"))
            {
                if(*mizrakci_efect == 0)
                    *mizrakci_efect = 4;
                else
                    *mizrakci_efect = 3;
            }
        }
        if(strstr(ork->o_heroes.thruk_Kemikkiran.etkiledigi_birim,"varg_binici") !=NULL)
        {
            if(strstr(ork->o_heroes.thruk_Kemikkiran.bonus_turu,"savunma") !=NULL)
            {
                if(*varg_binici_efect == 0)
                    *varg_binici_efect = 1;
                else
                    *varg_binici_efect = 3;
            }
            if(strstr(ork->o_heroes.thruk_Kemikkiran.bonus_turu,"saldiri") !=NULL)
            {
                if(*varg_binici_efect == 0)
                    *varg_binici_efect = 2;
                else
                    *varg_binici_efect = 3;
            }
            if(strstr(ork->o_heroes.thruk_Kemikkiran.bonus_turu,"kritik_sans"))
            {
                if(*varg_binici_efect == 0)
                    *varg_binici_efect = 4;
                else
                    *varg_binici_efect = 3;
            }
        }
        if(strstr(ork->o_heroes.thruk_Kemikkiran.etkiledigi_birim,"trol") !=NULL)
        {
            if(strstr(ork->o_heroes.thruk_Kemikkiran.bonus_turu,"savunma") !=NULL)
            {
                if(*trol_efect == 0)
                    *trol_efect = 1;
                else
                    *trol_efect = 3;
            }
            if(strstr(ork->o_heroes.thruk_Kemikkiran.bonus_turu,"saldiri") !=NULL)
            {
                if(*trol_efect == 0)
                    *trol_efect = 2;
                else
                    *trol_efect = 3;
            }
            if(strstr(ork->o_heroes.thruk_Kemikkiran.bonus_turu,"kritik_sans"))
            {
                if(*trol_efect == 0)
                    *trol_efect = 4;
                else
                    *trol_efect = 3;
            }
        }
    }
    if(ork_sayi->heroes_o_sayi.ugar_zalim_sayi==1)
    {
        if(strstr(ork->o_heroes.ugar_Zalim.etkiledigi_birim,"ork_dovuscu") !=NULL)
        {
            if(strstr(ork->o_heroes.ugar_Zalim.bonus_turu,"savunma") !=NULL)
            {
                if(*ork_dovuscu_efect == 0)
                    *ork_dovuscu_efect = 1;
                else
                    *ork_dovuscu_efect = 3;
            }
            if(strstr(ork->o_heroes.ugar_Zalim.bonus_turu,"saldiri") !=NULL)
            {
                if(*ork_dovuscu_efect == 0)
                    *ork_dovuscu_efect = 2;
                else
                    *ork_dovuscu_efect = 3;
            }
            if(strstr(ork->o_heroes.ugar_Zalim.bonus_turu,"kritik_sans"))
            {
                if(*ork_dovuscu_efect == 0)
                    *ork_dovuscu_efect = 4;
                else
                    *ork_dovuscu_efect = 3;
            }
        }
        if(strstr(ork->o_heroes.ugar_Zalim.etkiledigi_birim,"mizrakci") !=NULL)
        {
            if(strstr(ork->o_heroes.ugar_Zalim.bonus_turu,"savunma") !=NULL)
            {
                if(*mizrakci_efect == 0)
                    *mizrakci_efect = 1;
                else
                    *mizrakci_efect = 3;
            }
            if(strstr(ork->o_heroes.ugar_Zalim.bonus_turu,"saldiri") !=NULL)
            {
                if(*mizrakci_efect == 0)
                    *mizrakci_efect = 2;
                else
                    *mizrakci_efect = 3;
            }
            if(strstr(ork->o_heroes.ugar_Zalim.bonus_turu,"kritik_sans"))
            {
                if(*mizrakci_efect == 0)
                    *mizrakci_efect = 4;
                else
                    *mizrakci_efect = 3;
            }
        }
        if(strstr(ork->o_heroes.ugar_Zalim.etkiledigi_birim,"varg_binici") !=NULL)
        {
            if(strstr(ork->o_heroes.ugar_Zalim.bonus_turu,"savunma") !=NULL)
            {
                if(*varg_binici_efect == 0)
                    *varg_binici_efect = 1;
                else
                    *varg_binici_efect = 3;
            }
            if(strstr(ork->o_heroes.ugar_Zalim.bonus_turu,"saldiri") !=NULL)
            {
                if(*varg_binici_efect == 0)
                    *varg_binici_efect = 2;
                else
                    *varg_binici_efect = 3;
            }
            if(strstr(ork->o_heroes.ugar_Zalim.bonus_turu,"kritik_sans"))
            {
                if(*varg_binici_efect == 0)
                    *varg_binici_efect = 4;
                else
                    *varg_binici_efect = 3;
            }
        }
        if(strstr(ork->o_heroes.ugar_Zalim.etkiledigi_birim,"trol") !=NULL)
        {
            if(strstr(ork->o_heroes.ugar_Zalim.bonus_turu,"savunma") !=NULL)
            {
                if(*trol_efect == 0)
                    *trol_efect = 1;
                else
                    *trol_efect = 3;
            }
            if(strstr(ork->o_heroes.ugar_Zalim.bonus_turu,"saldiri") !=NULL)
            {
                if(*trol_efect == 0)
                    *trol_efect = 2;
                else
                    *trol_efect = 3;
            }
            if(strstr(ork->o_heroes.ugar_Zalim.bonus_turu,"kritik_sans"))
            {
                if(*trol_efect == 0)
                    *trol_efect = 4;
                else
                    *trol_efect = 3;
            }
        }
        if(strstr(ork->o_heroes.ugar_Zalim.etkiledigi_birim,"tum_birim") !=NULL)
        {
            if(strstr(ork->o_heroes.ugar_Zalim.bonus_turu,"savunma") !=NULL)
            {
                if(*ork_dovuscu_efect == 0)
                    *ork_dovuscu_efect = 1;
                else
                    *ork_dovuscu_efect = 3;
                if(*mizrakci_efect == 0)
                    *mizrakci_efect = 1;
                else
                    *mizrakci_efect = 3;
                if(*varg_binici_efect == 0)
                    *varg_binici_efect = 1;
                else
                    *varg_binici_efect = 3;
                if(*trol_efect == 0)
                    *trol_efect = 1;
                else
                    *trol_efect = 3;
            }
            if(strstr(ork->o_heroes.ugar_Zalim.bonus_turu,"saldiri") !=NULL)
            {
                if(*ork_dovuscu_efect == 0)
                    *ork_dovuscu_efect = 2;
                else
                    *ork_dovuscu_efect = 3;
                if(*mizrakci_efect == 0)
                    *mizrakci_efect = 2;
                else
                    *mizrakci_efect = 3;
                if(*varg_binici_efect == 0)
                    *varg_binici_efect = 2;
                else
                    *varg_binici_efect = 3;
                if(*trol_efect == 0)
                    *trol_efect = 2;
                else
                    *trol_efect = 3;
            }
            if(strstr(ork->o_heroes.ugar_Zalim.bonus_turu,"kritik_sans"))
            {
                if(*ork_dovuscu_efect == 0)
                    *ork_dovuscu_efect = 4;
                else
                    *ork_dovuscu_efect = 3;
                if(*mizrakci_efect == 0)
                    *mizrakci_efect = 4;
                else
                    *mizrakci_efect = 3;
                if(*varg_binici_efect == 0)
                    *varg_binici_efect = 4;
                else
                    *varg_binici_efect = 3;
                if(*trol_efect == 0)
                    *trol_efect = 4;
                else
                    *trol_efect = 3;
            }
        }
    }
    if(ork_sayi->heroes_o_sayi.vrog_kafakiran_sayi==1)
    {
        if(strstr(ork->o_heroes.vrog_Kafakiran.etkiledigi_birim,"ork_dovuscu") !=NULL)
        {
            if(strstr(ork->o_heroes.vrog_Kafakiran.bonus_turu,"savunma") !=NULL)
            {
                if(*ork_dovuscu_efect == 0)
                    *ork_dovuscu_efect = 1;
                else
                    *ork_dovuscu_efect = 3;
            }
            if(strstr(ork->o_heroes.vrog_Kafakiran.bonus_turu,"saldiri") !=NULL)
            {
                if(*ork_dovuscu_efect == 0)
                    *ork_dovuscu_efect = 2;
                else
                    *ork_dovuscu_efect = 3;
            }
            if(strstr(ork->o_heroes.vrog_Kafakiran.bonus_turu,"kritik_sans"))
            {
                if(*ork_dovuscu_efect == 0)
                    *ork_dovuscu_efect = 4;
                else
                    *ork_dovuscu_efect = 3;
            }
        }
        if(strstr(ork->o_heroes.vrog_Kafakiran.etkiledigi_birim,"mizrakci") !=NULL)
        {
            if(strstr(ork->o_heroes.vrog_Kafakiran.bonus_turu,"savunma") !=NULL)
            {
                if(*mizrakci_efect == 0)
                    *mizrakci_efect = 1;
                else
                    *mizrakci_efect = 3;
            }
            if(strstr(ork->o_heroes.vrog_Kafakiran.bonus_turu,"saldiri") !=NULL)
            {
                if(*mizrakci_efect == 0)
                    *mizrakci_efect = 2;
                else
                    *mizrakci_efect = 3;
            }
            if(strstr(ork->o_heroes.vrog_Kafakiran.bonus_turu,"kritik_sans"))
            {
                if(*mizrakci_efect == 0)
                    *mizrakci_efect = 4;
                else
                    *mizrakci_efect = 3;
            }
        }
        if(strstr(ork->o_heroes.vrog_Kafakiran.etkiledigi_birim,"varg_binici") !=NULL)
        {
            if(strstr(ork->o_heroes.vrog_Kafakiran.bonus_turu,"savunma") !=NULL)
            {
                if(*varg_binici_efect == 0)
                    *varg_binici_efect = 1;
                else
                    *varg_binici_efect = 3;
            }
            if(strstr(ork->o_heroes.vrog_Kafakiran.bonus_turu,"saldiri") !=NULL)
            {
                if(*varg_binici_efect == 0)
                    *varg_binici_efect = 2;
                else
                    *varg_binici_efect = 3;
            }
            if(strstr(ork->o_heroes.vrog_Kafakiran.bonus_turu,"kritik_sans"))
            {
                if(*varg_binici_efect == 0)
                    *varg_binici_efect = 4;
                else
                    *varg_binici_efect = 3;
            }
        }
        if(strstr(ork->o_heroes.vrog_Kafakiran.etkiledigi_birim,"trol") !=NULL)
        {
            if(strstr(ork->o_heroes.vrog_Kafakiran.bonus_turu,"savunma") !=NULL)
            {
                if(*trol_efect == 0)
                    *trol_efect = 1;
                else
                    *trol_efect = 3;
            }
            if(strstr(ork->o_heroes.vrog_Kafakiran.bonus_turu,"saldiri") !=NULL)
            {
                if(*trol_efect == 0)
                    *trol_efect = 2;
                else
                    *trol_efect = 3;
            }
            if(strstr(ork->o_heroes.vrog_Kafakiran.bonus_turu,"kritik_sans"))
            {
                if(*trol_efect == 0)
                    *trol_efect = 4;
                else
                    *trol_efect = 3;
            }
        }
    }
    if(ork_sayi->creatures_o_sayi.ates_iblisi_sayi==1)
    {
        if(strstr(ork->o_creatures.ates_Iblisi.etkiledigi_birim,"ork_dovuscu") !=NULL)
        {
            if(strstr(ork->o_creatures.ates_Iblisi.bonus_turu,"savunma") !=NULL)
            {
                if(*ork_dovuscu_efect == 0)
                    *ork_dovuscu_efect = 1;
                else
                    *ork_dovuscu_efect = 3;
            }
            if(strstr(ork->o_creatures.ates_Iblisi.bonus_turu,"saldiri") !=NULL)
            {
                if(*ork_dovuscu_efect == 0)
                    *ork_dovuscu_efect = 2;
                else
                    *ork_dovuscu_efect = 3;
            }
            if(strstr(ork->o_creatures.ates_Iblisi.bonus_turu,"kritik_sans"))
            {
                if(*ork_dovuscu_efect == 0)
                    *ork_dovuscu_efect = 4;
                else
                    *ork_dovuscu_efect = 3;
            }
        }
        if(strstr(ork->o_creatures.ates_Iblisi.etkiledigi_birim,"mizrakci") !=NULL)
        {
            if(strstr(ork->o_creatures.ates_Iblisi.bonus_turu,"savunma") !=NULL)
            {
                if(*mizrakci_efect == 0)
                    *mizrakci_efect = 1;
                else
                    *mizrakci_efect = 3;
            }
            if(strstr(ork->o_creatures.ates_Iblisi.bonus_turu,"saldiri") !=NULL)
            {
                if(*mizrakci_efect == 0)
                    *mizrakci_efect = 2;
                else
                    *mizrakci_efect = 3;
            }
            if(strstr(ork->o_creatures.ates_Iblisi.bonus_turu,"kritik_sans"))
            {
                if(*mizrakci_efect == 0)
                    *mizrakci_efect = 4;
                else
                    *mizrakci_efect = 3;
            }
        }
        if(strstr(ork->o_creatures.ates_Iblisi.etkiledigi_birim,"varg_binici") !=NULL)
        {
            if(strstr(ork->o_creatures.ates_Iblisi.bonus_turu,"savunma") !=NULL)
            {
                if(*varg_binici_efect == 0)
                    *varg_binici_efect = 1;
                else
                    *varg_binici_efect = 3;
            }
            if(strstr(ork->o_creatures.ates_Iblisi.bonus_turu,"saldiri") !=NULL)
            {
                if(*varg_binici_efect == 0)
                    *varg_binici_efect = 2;
                else
                    *varg_binici_efect = 3;
            }
            if(strstr(ork->o_creatures.ates_Iblisi.bonus_turu,"kritik_sans"))
            {
                if(*varg_binici_efect == 0)
                    *varg_binici_efect = 4;
                else
                    *varg_binici_efect = 3;
            }
        }
        if(strstr(ork->o_creatures.ates_Iblisi.etkiledigi_birim,"trol") !=NULL)
        {
            if(strstr(ork->o_creatures.ates_Iblisi.bonus_turu,"savunma") !=NULL)
            {
                if(*trol_efect == 0)
                    *trol_efect = 1;
                else
                    *trol_efect = 3;
            }
            if(strstr(ork->o_creatures.ates_Iblisi.bonus_turu,"saldiri") !=NULL)
            {
                if(*trol_efect == 0)
                    *trol_efect = 2;
                else
                    *trol_efect = 3;
            }
            if(strstr(ork->o_creatures.ates_Iblisi.bonus_turu,"kritik_sans"))
            {
                if(*trol_efect == 0)
                    *trol_efect = 4;
                else
                    *trol_efect = 3;
            }
        }
    }
    if(ork_sayi->creatures_o_sayi.buz_devleri_sayi==1)
    {
        if(strstr(ork->o_creatures.buz_Devleri.etkiledigi_birim,"ork_dovuscu") !=NULL)
        {
            if(strstr(ork->o_creatures.buz_Devleri.bonus_turu,"savunma") !=NULL)
            {
                if(*ork_dovuscu_efect == 0)
                    *ork_dovuscu_efect = 1;
                else
                    *ork_dovuscu_efect = 3;
            }
            if(strstr(ork->o_creatures.buz_Devleri.bonus_turu,"saldiri") !=NULL)
            {
                if(*ork_dovuscu_efect == 0)
                    *ork_dovuscu_efect = 2;
                else
                    *ork_dovuscu_efect = 3;
            }
            if(strstr(ork->o_creatures.buz_Devleri.bonus_turu,"kritik_sans"))
            {
                if(*ork_dovuscu_efect == 0)
                    *ork_dovuscu_efect = 4;
                else
                    *ork_dovuscu_efect = 3;
            }
        }
        if(strstr(ork->o_creatures.buz_Devleri.etkiledigi_birim,"mizrakci") !=NULL)
        {
            if(strstr(ork->o_creatures.buz_Devleri.bonus_turu,"savunma") !=NULL)
            {
                if(*mizrakci_efect == 0)
                    *mizrakci_efect = 1;
                else
                    *mizrakci_efect = 3;
            }
            if(strstr(ork->o_creatures.buz_Devleri.bonus_turu,"saldiri") !=NULL)
            {
                if(*mizrakci_efect == 0)
                    *mizrakci_efect = 2;
                else
                    *mizrakci_efect = 3;
            }
            if(strstr(ork->o_creatures.buz_Devleri.bonus_turu,"kritik_sans"))
            {
                if(*mizrakci_efect == 0)
                    *mizrakci_efect = 4;
                else
                    *mizrakci_efect = 3;
            }
        }
        if(strstr(ork->o_creatures.buz_Devleri.etkiledigi_birim,"varg_binici") !=NULL)
        {
            if(strstr(ork->o_creatures.buz_Devleri.bonus_turu,"savunma") !=NULL)
            {
                if(*varg_binici_efect == 0)
                    *varg_binici_efect = 1;
                else
                    *varg_binici_efect = 3;
            }
            if(strstr(ork->o_creatures.buz_Devleri.bonus_turu,"saldiri") !=NULL)
            {
                if(*varg_binici_efect == 0)
                    *varg_binici_efect = 2;
                else
                    *varg_binici_efect = 3;
            }
            if(strstr(ork->o_creatures.buz_Devleri.bonus_turu,"kritik_sans"))
            {
                if(*varg_binici_efect == 0)
                    *varg_binici_efect = 4;
                else
                    *varg_binici_efect = 3;
            }
        }
        if(strstr(ork->o_creatures.buz_Devleri.etkiledigi_birim,"trol") !=NULL)
        {
            if(strstr(ork->o_creatures.buz_Devleri.bonus_turu,"savunma") !=NULL)
            {
                if(*trol_efect == 0)
                    *trol_efect = 1;
                else
                    *trol_efect = 3;
            }
            if(strstr(ork->o_creatures.buz_Devleri.bonus_turu,"saldiri") !=NULL)
            {
                if(*trol_efect == 0)
                    *trol_efect = 2;
                else
                    *trol_efect = 3;
            }
            if(strstr(ork->o_creatures.buz_Devleri.bonus_turu,"kritik_sans"))
            {
                if(*trol_efect == 0)
                    *trol_efect = 4;
                else
                    *trol_efect = 3;
            }
        }
    }
    if(ork_sayi->creatures_o_sayi.camur_devleri_sayi==1)
    {
        if(strstr(ork->o_creatures.camur_Devleri.etkiledigi_birim,"ork_dovuscu") !=NULL)
        {
            if(strstr(ork->o_creatures.camur_Devleri.bonus_turu,"savunma") !=NULL)
            {
                if(*ork_dovuscu_efect == 0)
                    *ork_dovuscu_efect = 1;
                else
                    *ork_dovuscu_efect = 3;
            }
            if(strstr(ork->o_creatures.camur_Devleri.bonus_turu,"saldiri") !=NULL)
            {
                if(*ork_dovuscu_efect == 0)
                    *ork_dovuscu_efect = 2;
                else
                    *ork_dovuscu_efect = 3;
            }
            if(strstr(ork->o_creatures.camur_Devleri.bonus_turu,"kritik_sans"))
            {
                if(*ork_dovuscu_efect == 0)
                    *ork_dovuscu_efect = 4;
                else
                    *ork_dovuscu_efect = 3;
            }
        }
        if(strstr(ork->o_creatures.camur_Devleri.etkiledigi_birim,"mizrakci") !=NULL)
        {
            if(strstr(ork->o_creatures.camur_Devleri.bonus_turu,"savunma") !=NULL)
            {
                if(*mizrakci_efect == 0)
                    *mizrakci_efect = 1;
                else
                    *mizrakci_efect = 3;
            }
            if(strstr(ork->o_creatures.camur_Devleri.bonus_turu,"saldiri") !=NULL)
            {
                if(*mizrakci_efect == 0)
                    *mizrakci_efect = 2;
                else
                    *mizrakci_efect = 3;
            }
            if(strstr(ork->o_creatures.camur_Devleri.bonus_turu,"kritik_sans"))
            {
                if(*mizrakci_efect == 0)
                    *mizrakci_efect = 4;
                else
                    *mizrakci_efect = 3;
            }
        }
        if(strstr(ork->o_creatures.camur_Devleri.etkiledigi_birim,"varg_binici") !=NULL)
        {
            if(strstr(ork->o_creatures.camur_Devleri.bonus_turu,"savunma") !=NULL)
            {
                if(*varg_binici_efect == 0)
                    *varg_binici_efect = 1;
                else
                    *varg_binici_efect = 3;
            }
            if(strstr(ork->o_creatures.camur_Devleri.bonus_turu,"saldiri") !=NULL)
            {
                if(*varg_binici_efect == 0)
                    *varg_binici_efect = 2;
                else
                    *varg_binici_efect = 3;
            }
            if(strstr(ork->o_creatures.camur_Devleri.bonus_turu,"kritik_sans"))
            {
                if(*varg_binici_efect == 0)
                    *varg_binici_efect = 4;
                else
                    *varg_binici_efect = 3;
            }
        }
        if(strstr(ork->o_creatures.camur_Devleri.etkiledigi_birim,"trol") !=NULL)
        {
            if(strstr(ork->o_creatures.camur_Devleri.bonus_turu,"savunma") !=NULL)
            {
                if(*trol_efect == 0)
                    *trol_efect = 1;
                else
                    *trol_efect = 3;
            }
            if(strstr(ork->o_creatures.camur_Devleri.bonus_turu,"saldiri") !=NULL)
            {
                if(*trol_efect == 0)
                    *trol_efect = 2;
                else
                    *trol_efect = 3;
            }
            if(strstr(ork->o_creatures.camur_Devleri.bonus_turu,"kritik_sans"))
            {
                if(*trol_efect == 0)
                    *trol_efect = 4;
                else
                    *trol_efect = 3;
            }
        }
    }
    if(ork_sayi->creatures_o_sayi.golge_kurtlari_sayi==1)
    {
        if(strstr(ork->o_creatures.golge_Kurtlari.etkiledigi_birim,"ork_dovuscu") !=NULL)
        {
            if(strstr(ork->o_creatures.golge_Kurtlari.bonus_turu,"savunma") !=NULL)
            {
                if(*ork_dovuscu_efect == 0)
                    *ork_dovuscu_efect = 1;
                else
                    *ork_dovuscu_efect = 3;
            }
            if(strstr(ork->o_creatures.golge_Kurtlari.bonus_turu,"saldiri") !=NULL)
            {
                if(*ork_dovuscu_efect == 0)
                    *ork_dovuscu_efect = 2;
                else
                    *ork_dovuscu_efect = 3;
            }
            if(strstr(ork->o_creatures.golge_Kurtlari.bonus_turu,"kritik_sans"))
            {
                if(*ork_dovuscu_efect == 0)
                    *ork_dovuscu_efect = 4;
                else
                    *ork_dovuscu_efect = 3;
            }
        }
        if(strstr(ork->o_creatures.golge_Kurtlari.etkiledigi_birim,"mizrakci") !=NULL)
        {
            if(strstr(ork->o_creatures.golge_Kurtlari.bonus_turu,"savunma") !=NULL)
            {
                if(*mizrakci_efect == 0)
                    *mizrakci_efect = 1;
                else
                    *mizrakci_efect = 3;
            }
            if(strstr(ork->o_creatures.golge_Kurtlari.bonus_turu,"saldiri") !=NULL)
            {
                if(*mizrakci_efect == 0)
                    *mizrakci_efect = 2;
                else
                    *mizrakci_efect = 3;
            }
            if(strstr(ork->o_creatures.golge_Kurtlari.bonus_turu,"kritik_sans"))
            {
                if(*mizrakci_efect == 0)
                    *mizrakci_efect = 4;
                else
                    *mizrakci_efect = 3;
            }
        }
        if(strstr(ork->o_creatures.golge_Kurtlari.etkiledigi_birim,"varg_binici") !=NULL)
        {
            if(strstr(ork->o_creatures.golge_Kurtlari.bonus_turu,"savunma") !=NULL)
            {
                if(*varg_binici_efect == 0)
                    *varg_binici_efect = 1;
                else
                    *varg_binici_efect = 3;
            }
            if(strstr(ork->o_creatures.golge_Kurtlari.bonus_turu,"saldiri") !=NULL)
            {
                if(*varg_binici_efect == 0)
                    *varg_binici_efect = 2;
                else
                    *varg_binici_efect = 3;
            }
            if(strstr(ork->o_creatures.golge_Kurtlari.bonus_turu,"kritik_sans"))
            {
                if(*varg_binici_efect == 0)
                    *varg_binici_efect = 4;
                else
                    *varg_binici_efect = 3;
            }
        }
        if(strstr(ork->o_creatures.golge_Kurtlari.etkiledigi_birim,"trol") !=NULL)
        {
            if(strstr(ork->o_creatures.golge_Kurtlari.bonus_turu,"savunma") !=NULL)
            {
                if(*trol_efect == 0)
                    *trol_efect = 1;
                else
                    *trol_efect = 3;
            }
            if(strstr(ork->o_creatures.golge_Kurtlari.bonus_turu,"saldiri") !=NULL)
            {
                if(*trol_efect == 0)
                    *trol_efect = 2;
                else
                    *trol_efect = 3;
            }
            if(strstr(ork->o_creatures.golge_Kurtlari.bonus_turu,"kritik_sans"))
            {
                if(*trol_efect == 0)
                    *trol_efect = 4;
                else
                    *trol_efect = 3;
            }
        }
    }
    if(ork_sayi->creatures_o_sayi.kara_trol_sayi==1)
    {
        if(strstr(ork->o_creatures.kara_Troll.etkiledigi_birim,"ork_dovuscu") !=NULL)
        {
            if(strstr(ork->o_creatures.kara_Troll.bonus_turu,"savunma") !=NULL)
            {
                if(*ork_dovuscu_efect == 0)
                    *ork_dovuscu_efect = 1;
                else
                    *ork_dovuscu_efect = 3;
            }
            if(strstr(ork->o_creatures.kara_Troll.bonus_turu,"saldiri") !=NULL)
            {
                if(*ork_dovuscu_efect == 0)
                    *ork_dovuscu_efect = 2;
                else
                    *ork_dovuscu_efect = 3;
            }
            if(strstr(ork->o_creatures.kara_Troll.bonus_turu,"kritik_sans"))
            {
                if(*ork_dovuscu_efect == 0)
                    *ork_dovuscu_efect = 4;
                else
                    *ork_dovuscu_efect = 3;
            }
        }
        if(strstr(ork->o_creatures.kara_Troll.etkiledigi_birim,"mizrakci") !=NULL)
        {
            if(strstr(ork->o_creatures.kara_Troll.bonus_turu,"savunma") !=NULL)
            {
                if(*mizrakci_efect == 0)
                    *mizrakci_efect = 1;
                else
                    *mizrakci_efect = 3;
            }
            if(strstr(ork->o_creatures.kara_Troll.bonus_turu,"saldiri") !=NULL)
            {
                if(*mizrakci_efect == 0)
                    *mizrakci_efect = 2;
                else
                    *mizrakci_efect = 3;
            }
            if(strstr(ork->o_creatures.kara_Troll.bonus_turu,"kritik_sans"))
            {
                if(*mizrakci_efect == 0)
                    *mizrakci_efect = 4;
                else
                    *mizrakci_efect = 3;
            }
        }
        if(strstr(ork->o_creatures.kara_Troll.etkiledigi_birim,"varg_binici") !=NULL)
        {
            if(strstr(ork->o_creatures.kara_Troll.bonus_turu,"savunma") !=NULL)
            {
                if(*varg_binici_efect == 0)
                    *varg_binici_efect = 1;
                else
                    *varg_binici_efect = 3;
            }
            if(strstr(ork->o_creatures.kara_Troll.bonus_turu,"saldiri") !=NULL)
            {
                if(*varg_binici_efect == 0)
                    *varg_binici_efect = 2;
                else
                    *varg_binici_efect = 3;
            }
            if(strstr(ork->o_creatures.kara_Troll.bonus_turu,"kritik_sans"))
            {
                if(*varg_binici_efect == 0)
                    *varg_binici_efect = 4;
                else
                    *varg_binici_efect = 3;
            }
        }
        if(strstr(ork->o_creatures.kara_Troll.etkiledigi_birim,"trol") !=NULL)
        {
            if(strstr(ork->o_creatures.kara_Troll.bonus_turu,"savunma") !=NULL)
            {
                if(*trol_efect == 0)
                    *trol_efect = 1;
                else
                    *trol_efect = 3;
            }
            if(strstr(ork->o_creatures.kara_Troll.bonus_turu,"saldiri") !=NULL)
            {
                if(*trol_efect == 0)
                    *trol_efect = 2;
                else
                    *trol_efect = 3;
            }
            if(strstr(ork->o_creatures.kara_Troll.bonus_turu,"kritik_sans"))
            {
                if(*trol_efect == 0)
                    *trol_efect = 4;
                else
                    *trol_efect = 3;
            }
        }
    }
    if(ork_sayi->creatures_o_sayi.makrog_savas_beyi_sayi==1)
    {
        if(strstr(ork->o_creatures.makrog_Savas_Beyi.etkiledigi_birim,"ork_dovuscu") !=NULL)
        {
            if(strstr(ork->o_creatures.makrog_Savas_Beyi.bonus_turu,"savunma") !=NULL)
            {
                if(*ork_dovuscu_efect == 0)
                    *ork_dovuscu_efect = 1;
                else
                    *ork_dovuscu_efect = 3;
            }
            if(strstr(ork->o_creatures.makrog_Savas_Beyi.bonus_turu,"saldiri") !=NULL)
            {
                if(*ork_dovuscu_efect == 0)
                    *ork_dovuscu_efect = 2;
                else
                    *ork_dovuscu_efect = 3;
            }
            if(strstr(ork->o_creatures.makrog_Savas_Beyi.bonus_turu,"kritik_sans"))
            {
                if(*ork_dovuscu_efect == 0)
                    *ork_dovuscu_efect = 4;
                else
                    *ork_dovuscu_efect = 3;
            }
        }
        if(strstr(ork->o_creatures.makrog_Savas_Beyi.etkiledigi_birim,"mizrakci") !=NULL)
        {
            if(strstr(ork->o_creatures.makrog_Savas_Beyi.bonus_turu,"savunma") !=NULL)
            {
                if(*mizrakci_efect == 0)
                    *mizrakci_efect = 1;
                else
                    *mizrakci_efect = 3;
            }
            if(strstr(ork->o_creatures.makrog_Savas_Beyi.bonus_turu,"saldiri") !=NULL)
            {
                if(*mizrakci_efect == 0)
                    *mizrakci_efect = 2;
                else
                    *mizrakci_efect = 3;
            }
            if(strstr(ork->o_creatures.makrog_Savas_Beyi.bonus_turu,"kritik_sans"))
            {
                if(*mizrakci_efect == 0)
                    *mizrakci_efect = 4;
                else
                    *mizrakci_efect = 3;
            }
        }
        if(strstr(ork->o_creatures.makrog_Savas_Beyi.etkiledigi_birim,"varg_binici") !=NULL)
        {
            if(strstr(ork->o_creatures.makrog_Savas_Beyi.bonus_turu,"savunma") !=NULL)
            {
                if(*varg_binici_efect == 0)
                    *varg_binici_efect = 1;
                else
                    *varg_binici_efect = 3;
            }
            if(strstr(ork->o_creatures.makrog_Savas_Beyi.bonus_turu,"saldiri") !=NULL)
            {
                if(*varg_binici_efect == 0)
                    *varg_binici_efect = 2;
                else
                    *varg_binici_efect = 3;
            }
            if(strstr(ork->o_creatures.makrog_Savas_Beyi.bonus_turu,"kritik_sans"))
            {
                if(*varg_binici_efect == 0)
                    *varg_binici_efect = 4;
                else
                    *varg_binici_efect = 3;
            }
        }
        if(strstr(ork->o_creatures.makrog_Savas_Beyi.etkiledigi_birim,"trol") !=NULL)
        {
            if(strstr(ork->o_creatures.makrog_Savas_Beyi.bonus_turu,"savunma") !=NULL)
            {
                if(*trol_efect == 0)
                    *trol_efect = 1;
                else
                    *trol_efect = 3;
            }
            if(strstr(ork->o_creatures.makrog_Savas_Beyi.bonus_turu,"saldiri") !=NULL)
            {
                if(*trol_efect == 0)
                    *trol_efect = 2;
                else
                    *trol_efect = 3;
            }
            if(strstr(ork->o_creatures.makrog_Savas_Beyi.bonus_turu,"kritik_sans"))
            {
                if(*trol_efect == 0)
                    *trol_efect = 4;
                else
                    *trol_efect = 3;
            }
        }
    }

}




int main(int argc, char *argv[])
{
    int senaryo_no;
    do
    {
        printf("Senaryo no secin: ");
        scanf("%d",&senaryo_no);
    }
    while(senaryo_no>10 || senaryo_no<=0);

    FILE* fptr;
    char satir[150];
    int i,sayac=0,unit_sayac=0;
    struct insan_imparatorlugu insan;
    struct ork_lejyonu ork;
    struct research research;

    fptr= fopen("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\unit_types.json","r");
    if(fptr == NULL)
    {
        printf("Dosya '230202050_230202058/unit_types.json' bulunamadi. Lütfen dosyanin dogru isimde ve dogru dizinde oldugundan emin olun.");
    }
    else
    {
        while(fgets(satir,sizeof(satir),fptr) != NULL)
        {
            sayac++;
            strcpy(satir,sola_dayama(satir));
            if(strstr(satir,"insan_imparatorlugu") != NULL)
            {
                while(fgets(satir,sizeof(satir),fptr) != NULL)
                {
                    sayac++;
                    strcpy(satir,sola_dayama(satir));
                    if(strstr(satir,"piyadeler") != NULL)
                    {
                        unit_sayac++;
                        for(i=0; i<4; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"saldiri\": %d",&insan.i_unit.piyadeler.saldiri);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<4; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"saglik\": %lf",&insan.i_unit.piyadeler.saglik);
                            }
                        }

                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<4; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"savunma\": %d",&insan.i_unit.piyadeler.savunma);
                            }
                        }

                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<4; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"kritik_sans\": %lf",&insan.i_unit.piyadeler.kritik_sans);
                            }
                        }

                        sayac+=4;
                    }
                    if(strstr(satir,"okcular") != NULL)
                    {
                        unit_sayac++;
                        for(i=0; i<4; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"saldiri\": %d",&insan.i_unit.okcular.saldiri);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<4; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"saglik\": %lf",&insan.i_unit.okcular.saglik);
                            }
                        }

                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<4; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"savunma\": %d",&insan.i_unit.okcular.savunma);
                            }
                        }

                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<4; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"kritik_sans\": %lf",&insan.i_unit.okcular.kritik_sans);
                            }
                        }
                        sayac+=4;
                    }
                    if(strstr(satir,"suvariler") != NULL)
                    {
                        unit_sayac++;
                        for(i=0; i<4; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"saldiri\": %d",&insan.i_unit.suvariler.saldiri);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<4; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"saglik\": %lf",&insan.i_unit.suvariler.saglik);
                            }
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<4; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"savunma\": %d",&insan.i_unit.suvariler.savunma);
                            }
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<4; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"kritik_sans\": %lf",&insan.i_unit.suvariler.kritik_sans);
                            }
                        }
                        sayac+=4;
                    }
                    if(strstr(satir,"kusatma_makineleri") != NULL)
                    {
                        unit_sayac++;
                        for(i=0; i<4; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"saldiri\": %d",&insan.i_unit.kusatma_makineleri.saldiri);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<4; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"saglik\": %lf",&insan.i_unit.kusatma_makineleri.saglik);
                            }
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<4; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"savunma\": %d",&insan.i_unit.kusatma_makineleri.savunma);
                            }
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<4; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"kritik_sans\": %lf",&insan.i_unit.kusatma_makineleri.kritik_sans);
                            }
                        }
                        sayac+=4;
                    }
                    if(unit_sayac == 4)
                    {
                        break;
                    }
                }
            }
            unit_sayac=0;
            if(strstr(satir,"ork_legi") != NULL)
            {
                while(fgets(satir,sizeof(satir),fptr) != NULL)
                {
                    sayac++;
                    strcpy(satir,sola_dayama(satir));
                    if(strstr(satir,"ork_dovusculeri") != NULL)
                    {
                        unit_sayac++;
                        for(i=0; i<4; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"saldiri\": %d",&ork.o_unit.ork_dovusculeri.saldiri);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<4; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"saglik\": %lf",&ork.o_unit.ork_dovusculeri.saglik);
                            }
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<4; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"savunma\": %d",&ork.o_unit.ork_dovusculeri.savunma);
                            }
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<4; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"kritik_sans\": %lf",&ork.o_unit.ork_dovusculeri.kritik_sans);
                            }
                        }
                        sayac+=4;
                    }
                    if(strstr(satir,"mizrakcilar") != NULL)
                    {
                        unit_sayac++;
                        for(i=0; i<4; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"saldiri\": %d",&ork.o_unit.mizrakcilar.saldiri);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<4; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"saglik\": %lf",&ork.o_unit.mizrakcilar.saglik);
                            }
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<4; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"savunma\": %d",&ork.o_unit.mizrakcilar.savunma);
                            }
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<4; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"kritik_sans\": %lf",&ork.o_unit.mizrakcilar.kritik_sans);
                            }
                        }
                        sayac+=4;
                    }
                    if(strstr(satir,"varg_binicileri") != NULL)
                    {
                        unit_sayac++;
                        for(i=0; i<4; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"saldiri\": %d",&ork.o_unit.varg_binicileri.saldiri);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<4; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"saglik\": %lf",&ork.o_unit.varg_binicileri.saglik);
                            }
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<4; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"savunma\": %d",&ork.o_unit.varg_binicileri.savunma);
                            }
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<4; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"kritik_sans\": %lf",&ork.o_unit.varg_binicileri.kritik_sans);
                            }
                        }
                        sayac+=4;
                    }
                    if(strstr(satir,"troller") != NULL)
                    {
                        unit_sayac++;
                        for(i=0; i<4; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"saldiri\": %d",&ork.o_unit.troller.saldiri);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<4; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"saglik\": %lf",&ork.o_unit.troller.saglik);
                            }
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<4; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"savunma\": %d",&ork.o_unit.troller.savunma);
                            }
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<4; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"kritik_sans\": %lf",&ork.o_unit.troller.kritik_sans);
                            }
                        }
                        sayac+=4;
                    }
                    if(unit_sayac == 4)
                    {
                        break;
                    }
                }
            }
        }
    }
    fclose(fptr);

    fptr = fopen("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\heroes.json","r");
    sayac = 0;
    int hero_sayac=0;
    if(fptr == NULL)
    {
        printf("Dosya '230202050_230202058/heroes.json' bulunamadi. Lütfen dosyanin dogru isimde ve dogru dizinde oldugundan emin olun.");
    }
    else
    {
        while(fgets(satir,sizeof(satir),fptr) != NULL)
        {
            sayac++;
            strcpy(satir,sola_dayama(satir));
            if(strstr(satir,"insan_imparatorlugu") != NULL)
            {
                while(fgets(satir,sizeof(satir),fptr) != NULL)
                {
                    sayac++;
                    strcpy(satir,sola_dayama(satir));
                    if(strstr(satir,"Alparslan") != NULL)
                    {
                        hero_sayac++;
                        for(i=0; i<3; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"bonus_turu\": %s",insan.i_heroes.alparslan.bonus_turu);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"bonus_degeri\": \"%d\"",&insan.i_heroes.alparslan.bonus_degeri);
                            }
                        }

                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"aciklama\": %s",insan.i_heroes.alparslan.etkiledigi_birim);
                            }
                        }
                        sayac+=3;
                    }
                    else if(strstr(satir,"Fatih_Sultan_Mehmet") != NULL)
                    {
                        hero_sayac++;
                        for(i=0; i<3; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"bonus_turu\": %s",insan.i_heroes.fatih_Sultan_Mehmet.bonus_turu);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"bonus_degeri\": \"%d\"",&insan.i_heroes.fatih_Sultan_Mehmet.bonus_degeri);
                            }
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"aciklama\": %s",insan.i_heroes.fatih_Sultan_Mehmet.etkiledigi_birim);
                            }
                        }
                        sayac+=3;
                    }
                    else if(strstr(satir,"Mete_Han") != NULL)
                    {
                        hero_sayac++;
                        for(i=0; i<3; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"bonus_turu\": %s",insan.i_heroes.mete_Han.bonus_turu);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"bonus_degeri\": \"%d\"",&insan.i_heroes.mete_Han.bonus_degeri);
                            }
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"aciklama\": %s",insan.i_heroes.mete_Han.etkiledigi_birim);
                            }
                        }
                        sayac+=3;
                    }
                    else if(strstr(satir,"Yavuz_Sultan_Selim") != NULL)
                    {
                        hero_sayac++;
                        for(i=0; i<3; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"bonus_turu\": %s",insan.i_heroes.yavuz_Sultan_Selim.bonus_turu);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"bonus_degeri\": \"%d\"",&insan.i_heroes.yavuz_Sultan_Selim.bonus_degeri);
                            }
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"aciklama\": %s",insan.i_heroes.yavuz_Sultan_Selim.etkiledigi_birim);
                            }
                        }
                        sayac+=3;
                    }
                    else if(strstr(satir,"Tugrul_Bey") != NULL)
                    {
                        hero_sayac++;
                        for(i=0; i<3; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"bonus_turu\": %s",insan.i_heroes.tugrul_Bey.bonus_turu);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"bonus_degeri\": \"%d\"",&insan.i_heroes.tugrul_Bey.bonus_degeri);
                            }
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"aciklama\": %s",insan.i_heroes.tugrul_Bey.etkiledigi_birim);
                            }
                        }
                        sayac+=3;
                    }
                    if(hero_sayac == 5)
                    {
                        break;
                    }
                }
            }
            hero_sayac = 0;
            if(strstr(satir,"ork_legi") != NULL)
            {
                while(fgets(satir,sizeof(satir),fptr) != NULL)
                {
                    sayac++;
                    strcpy(satir,sola_dayama(satir));
                    if(strstr(satir,"Goruk_Vahsi") != NULL)
                    {
                        hero_sayac++;
                        for(i=0; i<3; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"bonus_turu\": %s",ork.o_heroes.goruk_Vahsi.bonus_turu);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"bonus_degeri\": \"%d\"",&ork.o_heroes.goruk_Vahsi.bonus_degeri);
                            }
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"aciklama\": %s",ork.o_heroes.goruk_Vahsi.etkiledigi_birim);
                            }
                        }
                        sayac+=3;
                    }
                    else if(strstr(satir,"Thruk_Kemikkiran") != NULL)
                    {
                        hero_sayac++;
                        for(i=0; i<3; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"bonus_turu\": %s",ork.o_heroes.thruk_Kemikkiran.bonus_turu);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"bonus_degeri\": \"%d\"",&ork.o_heroes.thruk_Kemikkiran.bonus_degeri);
                            }
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"aciklama\": %s",ork.o_heroes.thruk_Kemikkiran.etkiledigi_birim);
                            }
                        }
                        sayac+=3;
                    }
                    else if(strstr(satir,"Vrog_Kafakiran") != NULL)
                    {
                        hero_sayac++;
                        for(i=0; i<3; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"bonus_turu\": %s",ork.o_heroes.vrog_Kafakiran.bonus_turu);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"bonus_degeri\": \"%d\"",&ork.o_heroes.vrog_Kafakiran.bonus_degeri);
                            }
                        }

                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"aciklama\": %s",ork.o_heroes.vrog_Kafakiran.etkiledigi_birim);
                            }
                        }
                        sayac+=3;
                    }
                    else if(strstr(satir,"Ugar_Zalim") != NULL)
                    {
                        hero_sayac++;
                        for(i=0; i<3; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"bonus_turu\": %s",ork.o_heroes.ugar_Zalim.bonus_turu);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"bonus_degeri\": \"%d\"",&ork.o_heroes.ugar_Zalim.bonus_degeri);
                            }
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"aciklama\": %s",ork.o_heroes.ugar_Zalim.etkiledigi_birim);
                            }
                        }
                        sayac+=3;
                    }
                    if(hero_sayac == 4)
                    {
                        break;
                    }
                }
            }
        }
    }
    fclose(fptr);

    fptr = fopen("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\creatures.json","r");
    sayac=0;
    int creature_sayac=0;
    if(fptr == NULL)
    {
        printf("Dosya '230202050_230202058/creatures.json' bulunamadi. Lütfen dosyanin dogru isimde ve dogru dizinde oldugundan emin olun.");
    }
    else
    {
        while(fgets(satir,sizeof(satir),fptr) != NULL)
        {
            sayac++;
            strcpy(satir,sola_dayama(satir));
            if(strstr(satir,"insan_imparatorlugu") != NULL)
            {
                while(fgets(satir,sizeof(satir),fptr) != NULL)
                {
                    sayac++;
                    strcpy(satir,sola_dayama(satir));
                    if(strstr(satir,"Ejderha") != NULL)
                    {
                        creature_sayac++;
                        for(i=0; i<3; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"etki_degeri\": \"%d\"",&insan.i_creatures.ejderha.bonus_degeri);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"etki_turu\": \"%s\"",insan.i_creatures.ejderha.bonus_turu);
                            }
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"aciklama\": %s",insan.i_creatures.ejderha.etkiledigi_birim);
                            }
                        }
                        sayac+=3;
                    }
                    else if(strstr(satir,"Agri_Dagi_Devleri") != NULL)
                    {
                        creature_sayac++;
                        for(i=0; i<3; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"etki_degeri\": \"%d\"",&insan.i_creatures.agri_Dagi_Devleri.bonus_degeri);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"etki_turu\": \"%s\"",insan.i_creatures.agri_Dagi_Devleri.bonus_turu);
                            }
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"aciklama\": %s",insan.i_creatures.agri_Dagi_Devleri.etkiledigi_birim);
                            }
                        }
                        sayac+=3;
                    }
                    else if(strstr(satir,"Tepegoz") != NULL)
                    {
                        creature_sayac++;
                        for(i=0; i<3; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"etki_degeri\": \"%d\"",&insan.i_creatures.tepegoz.bonus_degeri);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"etki_turu\": \"%s\"",insan.i_creatures.tepegoz.bonus_turu);
                            }
                        }

                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"aciklama\": %s",insan.i_creatures.tepegoz.etkiledigi_birim);
                            }
                        }
                        sayac+=3;
                    }
                    else if(strstr(satir,"Karakurt") != NULL)
                    {
                        creature_sayac++;
                        for(i=0; i<3; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"etki_degeri\": \"%d\"",&insan.i_creatures.karakurt.bonus_degeri);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"etki_turu\": \"%s\"",insan.i_creatures.karakurt.bonus_turu);
                            }
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"aciklama\": %s",insan.i_creatures.karakurt.etkiledigi_birim);
                            }
                        }
                        sayac+=3;
                    }
                    else if(strstr(satir,"Samur") != NULL)
                    {
                        creature_sayac++;
                        for(i=0; i<3; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"etki_degeri\": \"%d\"",&insan.i_creatures.samur.bonus_degeri);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"etki_turu\": \"%s\"",insan.i_creatures.samur.bonus_turu);
                            }
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"aciklama\": %s",insan.i_creatures.samur.etkiledigi_birim);
                            }
                        }
                        sayac+=3;
                    }
                    if(creature_sayac == 5)
                    {
                        break;
                    }
                }
            }
            creature_sayac = 0;
            if(strstr(satir,"ork_legi") != NULL)
            {
                while(fgets(satir,sizeof(satir),fptr) != NULL)
                {
                    sayac++;
                    strcpy(satir,sola_dayama(satir));
                    if(strstr(satir,"Kara_Troll") != NULL)
                    {
                        creature_sayac++;
                        for(i=0; i<3; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"etki_degeri\": \"%d\"",&ork.o_creatures.kara_Troll.bonus_degeri);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"etki_turu\": \"%s\"",ork.o_creatures.kara_Troll.bonus_turu);
                            }
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"aciklama\": %s",ork.o_creatures.kara_Troll.etkiledigi_birim);
                            }
                        }
                        sayac+=3;
                    }
                    else if(strstr(satir,"Golge_Kurtlari") != NULL)
                    {
                        creature_sayac++;
                        for(i=0; i<3; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"etki_degeri\": \"%d\"",&ork.o_creatures.golge_Kurtlari.bonus_degeri);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"etki_turu\": \"%s\"",ork.o_creatures.golge_Kurtlari.bonus_turu);
                            }
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"aciklama\": %s",ork.o_creatures.golge_Kurtlari.etkiledigi_birim);
                            }
                        }
                        sayac+=3;
                    }
                    else if(strstr(satir,"Camur_Devleri") != NULL)
                    {
                        creature_sayac++;
                        for(i=0; i<3; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"etki_degeri\": \"%d\"",&ork.o_creatures.camur_Devleri.bonus_degeri);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"etki_turu\": \"%s\"",ork.o_creatures.camur_Devleri.bonus_turu);
                            }
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"aciklama\": %s",ork.o_creatures.camur_Devleri.etkiledigi_birim);
                            }
                        }
                        sayac+=3;
                    }
                    else if(strstr(satir,"Ates_Iblisi") != NULL)
                    {
                        creature_sayac++;
                        for(i=0; i<3; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"etki_degeri\": \"%d\"",&ork.o_creatures.ates_Iblisi.bonus_degeri);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"etki_turu\": \"%s\"",ork.o_creatures.ates_Iblisi.bonus_turu);
                            }
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"aciklama\": %s",ork.o_creatures.ates_Iblisi.etkiledigi_birim);
                            }
                        }
                        sayac+=3;
                    }
                    else if(strstr(satir,"Makrog_Savas_Beyi") != NULL)
                    {
                        creature_sayac++;
                        for(i=0; i<3; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"etki_degeri\": \"%d\"",&ork.o_creatures.makrog_Savas_Beyi.bonus_degeri);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"etki_turu\": \"%s\"",ork.o_creatures.makrog_Savas_Beyi.bonus_turu);
                            }
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"aciklama\": %s",ork.o_creatures.makrog_Savas_Beyi.etkiledigi_birim);
                            }
                        }
                        sayac+=3;
                    }
                    else if(strstr(satir,"Buz_Devleri") != NULL)
                    {
                        creature_sayac++;
                        for(i=0; i<3; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"etki_degeri\": \"%d\"",&ork.o_creatures.buz_Devleri.bonus_degeri);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"etki_turu\": \"%s\"",ork.o_creatures.buz_Devleri.bonus_turu);
                            }
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<3; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"aciklama\": %s",ork.o_creatures.buz_Devleri.etkiledigi_birim);
                            }
                        }
                        sayac+=3;
                    }
                    if(creature_sayac == 6)
                    {
                        break;
                    }
                }
            }
        }
    }
    fclose(fptr);

    fptr = fopen("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\research.json","r");
    sayac=0;
    int research_sayac=0;
    char gereksiz[5];
    if(fptr == NULL)
    {
        printf("Dosya '230202050_230202058/research.json' bulunamadi. Lütfen dosyanin dogru isimde ve dogru dizinde oldugundan emin olun.");
    }
    else
    {
        while(fgets(satir,sizeof(satir),fptr) != NULL)
        {
            sayac++;
            strcpy(satir,sola_dayama(satir));
            if(strstr(satir,"savunma_ustaligi") != NULL)
            {
                while(fgets(satir,sizeof(satir),fptr) != NULL)
                {
                    sayac++;
                    strcpy(satir,sola_dayama(satir));

                    if(strstr(satir,"seviye_1") != NULL)
                    {
                        research_sayac++;
                        for(i=0; i<2; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"deger\": \"%d\"",&research.savunma_ustaligi.level1.deger);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<2; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"aciklama\": \"%s %s",research.savunma_ustaligi.level1.etkiledigi_birim,research.savunma_ustaligi.level1.etki_turu);
                            }
                        }
                        sayac+=2;
                    }
                    if(strstr(satir,"seviye_2") != NULL)
                    {
                        research_sayac++;
                        for(i=0; i<2; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"deger\": \"%d\"",&research.savunma_ustaligi.level2.deger);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<2; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"aciklama\": \"%s %s",research.savunma_ustaligi.level2.etkiledigi_birim,research.savunma_ustaligi.level2.etki_turu);
                            }
                        }
                        sayac+=2;
                    }
                    if(strstr(satir,"seviye_3") != NULL)
                    {
                        research_sayac++;
                        for(i=0; i<2; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"deger\": \"%d\"",&research.savunma_ustaligi.level3.deger);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<2; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"aciklama\": \"%s %s",research.savunma_ustaligi.level3.etkiledigi_birim,research.savunma_ustaligi.level3.etki_turu);
                            }
                        }
                        sayac+=2;
                    }
                    if(research_sayac == 3)
                    {
                        break;
                    }
                }
            }
            research_sayac = 0;
            if(strstr(satir,"saldiri_gelistirmesi") != NULL)
            {
                while(fgets(satir,sizeof(satir),fptr) != NULL)
                {
                    sayac++;
                    strcpy(satir,sola_dayama(satir));
                    if(strstr(satir,"seviye_1") != NULL)
                    {
                        research_sayac++;
                        for(i=0; i<2; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"deger\": \"%d\"",&research.saldiri_gelistirmesi.level1.deger);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<2; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"aciklama\": \"%s %s",research.saldiri_gelistirmesi.level1.etkiledigi_birim,research.saldiri_gelistirmesi.level1.etki_turu);
                            }
                        }
                        sayac+=2;
                    }
                    else if(strstr(satir,"seviye_2") != NULL)
                    {
                        research_sayac++;
                        for(i=0; i<2; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"deger\": \"%d\"",&research.saldiri_gelistirmesi.level2.deger);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<2; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"aciklama\": \"%s %s",research.saldiri_gelistirmesi.level2.etkiledigi_birim,research.saldiri_gelistirmesi.level2.etki_turu);
                            }
                        }
                        sayac+=2;
                    }
                    else if(strstr(satir,"seviye_3") != NULL)
                    {
                        research_sayac++;
                        for(i=0; i<2; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"deger\": \"%d\"",&research.saldiri_gelistirmesi.level3.deger);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<2; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"aciklama\": \"%s %s",research.saldiri_gelistirmesi.level3.etkiledigi_birim,research.saldiri_gelistirmesi.level3.etki_turu);
                            }
                        }
                        sayac+=2;
                    }
                    if(research_sayac == 3)
                    {
                        break;
                    }
                }
            }
            research_sayac=0;
            if(strstr(satir,"elit_egitim") != NULL)
            {
                while(fgets(satir,sizeof(satir),fptr) != NULL)
                {
                    sayac++;
                    strcpy(satir,sola_dayama(satir));
                    if(strstr(satir,"seviye_1") != NULL)
                    {
                        research_sayac++;
                        for(i=0; i<2; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"deger\": \"%d\"",&research.elit_egitim.level1.deger);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<2; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"aciklama\": \"%s  %s  %s",research.elit_egitim.level1.etkiledigi_birim,gereksiz,research.elit_egitim.level1.etki_turu);
                            }
                        }
                        sayac+=2;
                    }
                    else if(strstr(satir,"seviye_2") != NULL)
                    {
                        research_sayac++;
                        for(i=0; i<2; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"deger\": \"%d\"",&research.elit_egitim.level2.deger);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<2; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"aciklama\": \"%s %s %s",research.elit_egitim.level2.etkiledigi_birim,gereksiz,research.elit_egitim.level2.etki_turu);
                            }
                        }
                        sayac+=2;
                    }
                    else if(strstr(satir,"seviye_3") != NULL)
                    {
                        research_sayac++;
                        for(i=0; i<2; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"deger\": \"%d\"",&research.elit_egitim.level3.deger);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<2; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"aciklama\": \"%s %s %s",research.elit_egitim.level3.etkiledigi_birim,gereksiz,research.elit_egitim.level3.etki_turu);
                            }
                        }
                        sayac+=2;
                    }
                    if(research_sayac == 3)
                    {
                        break;
                    }
                }
            }
            research_sayac=0;
            if(strstr(satir,"kusatma_ustaligi") != NULL)
            {
                while(fgets(satir,sizeof(satir),fptr) != NULL)
                {
                    sayac++;
                    strcpy(satir,sola_dayama(satir));
                    if(strstr(satir,"seviye_1") != NULL)
                    {
                        research_sayac++;
                        for(i=0; i<2; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"deger\": \"%d\"",&research.kusatma_ustaligi.level1.deger);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<2; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"aciklama\": \"%s %s",research.kusatma_ustaligi.level1.etkiledigi_birim,research.kusatma_ustaligi.level1.etki_turu);
                            }
                        }
                        sayac+=2;
                    }
                    else if(strstr(satir,"seviye_2") != NULL)
                    {
                        research_sayac++;
                        for(i=0; i<2; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"deger\": \"%d\"",&research.kusatma_ustaligi.level2.deger);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<2; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"aciklama\": \"%s %s",research.kusatma_ustaligi.level2.etkiledigi_birim,research.kusatma_ustaligi.level2.etki_turu);
                            }
                        }
                        sayac+=2;
                    }
                    else if(strstr(satir,"seviye_3") != NULL)
                    {
                        research_sayac++;
                        for(i=0; i<2; i++)
                        {
                            fgets(satir,sizeof(satir),fptr);
                            strcpy(satir,sola_dayama(satir));
                            sscanf(satir,"\"deger\": \"%d\"",&research.kusatma_ustaligi.level3.deger);
                        }
                        if(satira_git(fptr,sayac))
                        {
                            for(i=0; i<2; i++)
                            {
                                fgets(satir,sizeof(satir),fptr);
                                strcpy(satir,sola_dayama(satir));
                                sscanf(satir,"\"aciklama\": \"%s %s",research.kusatma_ustaligi.level3.etkiledigi_birim,research.kusatma_ustaligi.level3.etki_turu);
                            }
                        }
                        sayac+=2;
                    }
                    if(research_sayac == 3)
                    {
                        break;
                    }
                }
            }
        }
    }
    fclose(fptr);
    if(senaryo_no == 1)
    {
        system("  curl -o 1.json https://yapbenzet.org.tr/1.json");
    }
    if(senaryo_no == 2)
    {
        system("  curl -o 1.json https://yapbenzet.org.tr/2.json");
    }
    if(senaryo_no == 3)
    {
        system("  curl -o 1.json https://yapbenzet.org.tr/3.json");
    }
    if(senaryo_no == 4)
    {
        system("  curl -o 1.json https://yapbenzet.org.tr/4.json");
    }
    if(senaryo_no == 5)
    {
        system("  curl -o 1.json https://yapbenzet.org.tr/5.json");
    }
    if(senaryo_no == 6)
    {
        system("  curl -o 1.json https://yapbenzet.org.tr/6.json");
    }
    if(senaryo_no == 7)
    {
        system("  curl -o 1.json https://yapbenzet.org.tr/7.json");
    }
    if(senaryo_no == 8)
    {
        system("  curl -o 1.json https://yapbenzet.org.tr/8.json");
    }
    if(senaryo_no == 9)
    {
        system("  curl -o 1.json https://yapbenzet.org.tr/9.json");
    }
    if(senaryo_no == 10)
    {
        system("  curl -o 1.json https://yapbenzet.org.tr/10.json");
    }



    fptr = fopen("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\ProLab\\1.json","r");

    sayac = 0;
    int insan_girdi = 0, ork_girdi = 0;
    int arastirma_girdi_i = 0, arastirma_girdi_o = 0;
    struct insan_imparatorlugu_sayi insan_sayi = {0};
    struct ork_lejyonu_sayi ork_sayi = {0};
    if(fptr == NULL)
    {
        printf("Dosya 'ProLab\1.json' bulunamadi. Lütfen dosyanin dogru isimde ve dogru dizinde oldugundan emin olun.");
    }
    else
    {
        while((fgets(satir,sizeof(satir),fptr) != NULL ) && (insan_girdi!=1 || ork_girdi!=1))
        {
            sayac++;
            strcpy(satir,sola_dayama(satir));
            if((strstr(satir,"insan_imparatorlugu") != NULL) && insan_girdi==0)
            {
                insan_girdi=1;
                while(fgets(satir,sizeof(satir),fptr))
                {
                    sayac++;
                    strcpy(satir,sola_dayama(satir));
                    if(strstr(satir,"piyadeler") != NULL)
                    {
                        sscanf(satir,"\"piyadeler\": %d",&insan_sayi.unit_i_sayi.piyade_sayi);
                    }
                    if(strstr(satir,"okcular") != NULL)
                    {
                        sscanf(satir,"\"okcular\": %d",&insan_sayi.unit_i_sayi.okcu_sayi);
                    }
                    if(strstr(satir,"suvariler") != NULL)
                    {
                        sscanf(satir,"\"suvariler\": %d",&insan_sayi.unit_i_sayi.suvari_sayi);
                    }
                    if(strstr(satir,"kusatma_makineleri") != NULL)
                    {
                        sscanf(satir,"\"kusatma_makineleri\": %d",&insan_sayi.unit_i_sayi.kusatma_makine_sayi);
                    }
                    if(strstr(satir,"kahramanlar") != NULL)
                    {
                        if(strstr(satir,"Alparslan") != NULL)
                        {
                            insan_sayi.heroes_i_sayi.alparslan_sayi=1;
                        }
                        if(strstr(satir,"Fatih_Sultan_Mehmet") != NULL)
                        {
                            insan_sayi.heroes_i_sayi.fatih_sultan_mehmet_sayi=1;
                        }
                        if(strstr(satir,"Mete_Han") != NULL)
                        {
                            insan_sayi.heroes_i_sayi.mete_han_sayi=1;
                        }
                        if(strstr(satir,"Yavuz_Sultan_Selim") != NULL)
                        {
                            insan_sayi.heroes_i_sayi.yavuz_sultan_selim_sayi=1;
                        }
                        if(strstr(satir,"Tugrul_Bey") != NULL)
                        {
                            insan_sayi.heroes_i_sayi.tugrul_bey_sayi=1;
                        }
                    }
                    if(strstr(satir,"canavarlar") != NULL)
                    {
                        if(strstr(satir,"Ejderha") != NULL)
                        {
                            insan_sayi.creatures_i_sayi.ejderha_sayi=1;
                        }
                        if(strstr(satir,"Agri_Dagi_Devleri") != NULL)
                        {
                            insan_sayi.creatures_i_sayi.agri_dagi_devi_sayi=1;
                        }
                        if(strstr(satir,"Tepegoz") != NULL)
                        {
                            insan_sayi.creatures_i_sayi.tepegoz_sayi=1;
                        }
                        if(strstr(satir,"Karakurt") != NULL)
                        {
                            insan_sayi.creatures_i_sayi.karakurt_sayi=1;
                        }
                        if(strstr(satir,"Samur") != NULL)
                        {
                            insan_sayi.creatures_i_sayi.samur_sayi=1;
                        }
                    }
                    if(strstr(satir,"arastirma_seviyesi") != NULL && arastirma_girdi_i == 0)
                    {
                        arastirma_girdi_i++;
                        fgets(satir,sizeof(satir),fptr);
                        strcpy(satir,sola_dayama(satir));
                        if(strstr(satir,"savunma_ustaligi") != NULL)
                        {
                            sscanf(satir,"\"savunma_ustaligi\": %d",&insan_sayi.research_i_sayi.savunma_ustaligi_sayi);
                        }
                        if(strstr(satir,"saldiri_gelistirmesi") != NULL)
                        {
                            sscanf(satir,"\"saldiri_gelistirmesi\": %d",&insan_sayi.research_i_sayi.saldiri_gelistirmesi_sayi);
                        }
                        if(strstr(satir,"elit_egitim") != NULL)
                        {
                            sscanf(satir,"\"elit_egitim\": %d",&insan_sayi.research_i_sayi.elit_egitim_sayi);
                        }
                        if(strstr(satir,"kusatma_ustaligi") != NULL)
                        {
                            sscanf(satir,"\"kusatma_ustaligi\": %d",&insan_sayi.research_i_sayi.kusatma_ustaligi_sayi);
                        }
                        sayac++;
                    }
                }
                if(satira_git(fptr,1))
                {
                    sayac=1;
                }
            }
            if((strstr(satir,"ork_legi") != NULL) && ork_girdi == 0 )
            {
                ork_girdi=1;
                while(fgets(satir,sizeof(satir),fptr))
                {
                    sayac++;
                    strcpy(satir,sola_dayama(satir));
                    if(strstr(satir,"ork_dovusculeri"))
                    {
                        sscanf(satir,"\"ork_dovusculeri\": %d",&ork_sayi.unit_o_sayi.ork_dovuscu_sayi);
                    }
                    if(strstr(satir,"mizrakcilar"))
                    {
                        sscanf(satir,"\"mizrakcilar\": %d",&ork_sayi.unit_o_sayi.mizrakci_sayi);
                    }
                    if(strstr(satir,"varg_binicileri"))
                    {
                        sscanf(satir,"\"varg_binicileri\": %d",&ork_sayi.unit_o_sayi.varg_binici_sayi);
                    }
                    if(strstr(satir,"troller"))
                    {
                        sscanf(satir,"\"troller\": %d",&ork_sayi.unit_o_sayi.troller_sayi);
                    }
                    if(strstr(satir,"kahramanlar") != NULL)
                    {
                        if(strstr(satir,"Goruk_Vahsi") != NULL)
                        {
                            ork_sayi.heroes_o_sayi.goruk_vahsi_sayi=1;
                        }
                        if(strstr(satir,"Thruk_Kemikkiran") != NULL)
                        {
                            ork_sayi.heroes_o_sayi.thruk_kemikkiran_sayi=1;
                        }
                        if(strstr(satir,"Vrog_Kafakiran") != NULL)
                        {
                            ork_sayi.heroes_o_sayi.vrog_kafakiran_sayi=1;
                        }
                        if(strstr(satir,"Ugar_Zalim") != NULL)
                        {
                            ork_sayi.heroes_o_sayi.ugar_zalim_sayi=1;
                        }
                    }
                    if(strstr(satir,"canavarlar") != NULL)
                    {
                        if(strstr(satir,"Kara_Troll") != NULL)
                        {
                            ork_sayi.creatures_o_sayi.kara_trol_sayi=1;
                        }
                        if(strstr(satir,"Golge_Kurtlari") != NULL)
                        {
                            ork_sayi.creatures_o_sayi.golge_kurtlari_sayi=1;
                        }
                        if(strstr(satir,"Camur_Devleri") != NULL)
                        {
                            ork_sayi.creatures_o_sayi.camur_devleri_sayi=1;
                        }
                        if(strstr(satir,"Ates_Iblisi") != NULL)
                        {
                            ork_sayi.creatures_o_sayi.ates_iblisi_sayi=1;
                        }
                        if(strstr(satir,"Makrog_Savas_Beyi") != NULL)
                        {
                            ork_sayi.creatures_o_sayi.makrog_savas_beyi_sayi=1;
                        }
                        if(strstr(satir,"Buz_Devleri") != NULL)
                        {
                            ork_sayi.creatures_o_sayi.buz_devleri_sayi=1;
                        }
                    }
                    if(strstr(satir,"arastirma_seviyesi") != NULL && arastirma_girdi_o == 0)
                    {
                        arastirma_girdi_o=1;
                        fgets(satir,sizeof(satir),fptr);
                        strcpy(satir,sola_dayama(satir));
                        if(strstr(satir,"savunma_ustaligi") != NULL)
                        {
                            sscanf(satir,"\"savunma_ustaligi\": %d",&ork_sayi.research_o_sayi.savunma_ustaligi_sayi);
                        }
                        if(strstr(satir,"saldiri_gelistirmesi") != NULL)
                        {
                            sscanf(satir,"\"saldiri_gelistirmesi\": %d",&ork_sayi.research_o_sayi.saldiri_gelistirmesi_sayi);
                        }
                        if(strstr(satir,"elit_egitim") != NULL)
                        {
                            sscanf(satir,"\"elit_egitim\": %d",&ork_sayi.research_o_sayi.elit_egitim_sayi);
                        }
                        if(strstr(satir,"kusatma_ustaligi") != NULL)
                        {
                            sscanf(satir,"\"kusatma_ustaligi\": %d",&ork_sayi.research_o_sayi.kusatma_ustaligi_sayi);
                        }
                        sayac+=1;
                    }
                }
                if(satira_git(fptr,1))
                {
                    sayac=1;
                }
            }
        }
    }
    fclose(fptr);
    int bus_kontrol=0;
    float bas_saglik_piyade = insan.i_unit.piyadeler.saglik;
    float bas_saglik_okcu = insan.i_unit.okcular.saglik;
    float bas_saglik_suvari = insan.i_unit.suvariler.saglik;
    float bas_saglik_kusatma_makine = insan.i_unit.kusatma_makineleri.saglik;
    float bas_saglik_ork_dovuscu = ork.o_unit.ork_dovusculeri.saglik;
    float bas_saglik_mizrakci = ork.o_unit.mizrakcilar.saglik;
    float bas_saglik_varg_binici = ork.o_unit.varg_binicileri.saglik;
    float bas_saglik_trol = ork.o_unit.troller.saglik;
    int ekran_genisligi = 1920;
    int ekran_yuksekligi = 1080;
    int izgara_boyutu = 20;
    int hucre_boyutu = 40;
    int izgara_genisligi = izgara_boyutu * hucre_boyutu;
    int izgara_yuksekligi = izgara_boyutu * hucre_boyutu;
    int hucredeki_max_sayi = 100;
    int toplam_piyade = insan_sayi.unit_i_sayi.piyade_sayi;
    int toplam_okcu = insan_sayi.unit_i_sayi.okcu_sayi;
    int toplam_suvari = insan_sayi.unit_i_sayi.suvari_sayi;
    int toplam_kusatma = insan_sayi.unit_i_sayi.kusatma_makine_sayi;
    int toplam_orkDovuscu = ork_sayi.unit_o_sayi.ork_dovuscu_sayi;
    int toplam_mizrakci = ork_sayi.unit_o_sayi.mizrakci_sayi;
    int toplam_vargBinici = ork_sayi.unit_o_sayi.varg_binici_sayi;
    int toplam_trol = ork_sayi.unit_o_sayi.troller_sayi;

    float tam_saglik = 1.0f;

    char birlik_sayisi[10];

    int x_ekseni = (ekran_genisligi - izgara_genisligi) / 2;
    int y_ekseni = (ekran_yuksekligi - izgara_yuksekligi) / 2;
bus:
    if(bus_kontrol==1)
    {
        toplam_piyade = insan_sayi.unit_i_sayi.piyade_sayi;
        toplam_okcu = insan_sayi.unit_i_sayi.okcu_sayi;
        toplam_suvari = insan_sayi.unit_i_sayi.suvari_sayi;
        toplam_kusatma = insan_sayi.unit_i_sayi.kusatma_makine_sayi;
        toplam_orkDovuscu = ork_sayi.unit_o_sayi.ork_dovuscu_sayi;
        toplam_mizrakci = ork_sayi.unit_o_sayi.mizrakci_sayi;
        toplam_vargBinici = ork_sayi.unit_o_sayi.varg_binici_sayi;
        toplam_trol = ork_sayi.unit_o_sayi.troller_sayi;

    }
    if(bus_kontrol==0)
{
    InitWindow(ekran_genisligi, ekran_yuksekligi, "Oyun Menusu");

    SetTargetFPS(60);
    Texture2D menu_arkaplan = LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\arka_plan.png");
    Texture2D background = LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\arka_plan.png");
    Texture2D insan_kahraman1 = LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\fatih_sultan_mehmet.png");
    Texture2D insan_kahraman2 = LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\yavuz_sultan_selim.png");
    Texture2D insan_kahraman3 = LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\tugrul_bey.png");
    Texture2D insan_kahraman4 = LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\alparslan.png");
    Texture2D insan_kahraman5 = LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\mete_han.png");
    Texture2D insan_canavar1 = LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\ejderha.png");
    Texture2D insan_canavar2 = LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\agri_dagi_devleri.png");
    Texture2D insan_canavar3 = LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\tepegoz.png");
    Texture2D insan_canavar4 = LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\karakurt.png");
    Texture2D insan_canavar5 = LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\samur.png");
    Texture2D ork_kahraman1 = LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\goruk_vahsi.png");
    Texture2D ork_kahraman2 = LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\thruk_kemikkiran.png");
    Texture2D ork_kahraman3 = LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\vrog_kafakiran.png");
    Texture2D ork_kahraman4 = LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\ugar_zalim.png");
    Texture2D ork_canavar1 = LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\kara_trol.png");
    Texture2D ork_canavar2 = LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\golge_kurtlari.png");
    Texture2D ork_canavar3 = LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\camur_devleri.png");
    Texture2D ork_canavar4 = LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\ates_iblisi.png");
    Texture2D ork_canavar5 = LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\makrog_savas_beyi.png");
    Texture2D ork_canavar6 = LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\buz_devleri.png");
    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawTexture(menu_arkaplan, 0, 0, WHITE);

        DrawText("OYUN MENUSU", ekran_genisligi / 2 - MeasureText("OYUN MENUSU", 100) / 2 ,100, 100, WHITE);

        int kutucuk_genislik = 400;
        int kutucuk_yukseklik = 80;
        int kutucuk_x = (ekran_genisligi - kutucuk_genislik) / 2;
        int kutucuk_y_baslangic = (ekran_yuksekligi - 3 * kutucuk_yukseklik - 40) / 2;
        int kutucuk_aralik = 20;

        float resim_olcek = 0.14f;
        int resim_genislik = insan_kahraman1.width * resim_olcek;
        int resim_yukseklik = insan_kahraman1.height * resim_olcek;
        int resim_aralik = 120;
        int sol_resim_x = resim_aralik;
        int sol_resim_y_baslangic = 100;
        int sag_resim_x = ekran_genisligi - resim_genislik - resim_aralik;
        int resim_y_aralik = 30;
        int ork_canavar_y_aralik = 15;

        DrawText("INSAN IMPARATORLUGU", resim_aralik-40, sol_resim_y_baslangic - 65, 40, BLUE);
        DrawText("ORK LEJYONU", sag_resim_x -200, sol_resim_y_baslangic - 65, 40, ORANGE);

        int kutucuk_y = kutucuk_y_baslangic;
        DrawRectangle(kutucuk_x, kutucuk_y, kutucuk_genislik, kutucuk_yukseklik, Fade(LIGHTGRAY, 0.8f));
        DrawRectangleLines(kutucuk_x, kutucuk_y, kutucuk_genislik, kutucuk_yukseklik, DARKGRAY);
        DrawText("1 - Savasa Basla", kutucuk_x + 20, kutucuk_y + 20, 30, BLACK);

        kutucuk_y += kutucuk_yukseklik + kutucuk_aralik;
        DrawRectangle(kutucuk_x, kutucuk_y, kutucuk_genislik, kutucuk_yukseklik, Fade(LIGHTGRAY, 0.8f));
        DrawRectangleLines(kutucuk_x, kutucuk_y, kutucuk_genislik, kutucuk_yukseklik, DARKGRAY);
        DrawText("2 - Cikis", kutucuk_x + 20, kutucuk_y + 20, 30, BLACK);

        DrawTextureEx(insan_kahraman1, (Vector2){sol_resim_x, sol_resim_y_baslangic}, 0.0f, resim_olcek, WHITE);
        DrawTextureEx(insan_kahraman2, (Vector2){sol_resim_x, sol_resim_y_baslangic + resim_y_aralik + resim_yukseklik}, 0.0f, resim_olcek, WHITE);
        DrawTextureEx(insan_kahraman3, (Vector2){sol_resim_x, sol_resim_y_baslangic + 2 * (resim_y_aralik + resim_yukseklik)}, 0.0f, resim_olcek, WHITE);
        DrawTextureEx(insan_kahraman4, (Vector2){sol_resim_x, sol_resim_y_baslangic + 3 * (resim_y_aralik + resim_yukseklik)}, 0.0f, resim_olcek, WHITE);
        DrawTextureEx(insan_kahraman5, (Vector2){sol_resim_x, sol_resim_y_baslangic + 4 * (resim_y_aralik + resim_yukseklik)}, 0.0f, resim_olcek, WHITE);


        int insan_canavar_x = sol_resim_x + resim_genislik + resim_aralik;
        DrawTextureEx(insan_canavar1, (Vector2){insan_canavar_x, sol_resim_y_baslangic}, 0.0f, resim_olcek, WHITE);
        DrawTextureEx(insan_canavar2, (Vector2){insan_canavar_x, sol_resim_y_baslangic + resim_y_aralik + resim_yukseklik}, 0.0f, resim_olcek, WHITE);
        DrawTextureEx(insan_canavar3, (Vector2){insan_canavar_x, sol_resim_y_baslangic + 2 * (resim_y_aralik + resim_yukseklik)}, 0.0f, resim_olcek, WHITE);
        DrawTextureEx(insan_canavar4, (Vector2){insan_canavar_x, sol_resim_y_baslangic + 3 * (resim_y_aralik + resim_yukseklik)}, 0.0f, resim_olcek, WHITE);
        DrawTextureEx(insan_canavar5, (Vector2){insan_canavar_x, sol_resim_y_baslangic + 4 * (resim_y_aralik + resim_yukseklik)}, 0.0f, resim_olcek, WHITE);

        float ork_canavar_olcek = 0.13f;
        int ork_canavar_x = sag_resim_x - resim_genislik - resim_aralik;
        DrawTextureEx(ork_canavar1, (Vector2){ork_canavar_x, sol_resim_y_baslangic}, 0.0f, ork_canavar_olcek, WHITE);
        DrawTextureEx(ork_canavar2, (Vector2){ork_canavar_x, sol_resim_y_baslangic + ork_canavar_y_aralik + resim_yukseklik}, 0.0f, ork_canavar_olcek, WHITE);
        DrawTextureEx(ork_canavar3, (Vector2){ork_canavar_x, sol_resim_y_baslangic + 2 * (ork_canavar_y_aralik + resim_yukseklik)}, 0.0f, ork_canavar_olcek, WHITE);
        DrawTextureEx(ork_canavar4, (Vector2){ork_canavar_x, sol_resim_y_baslangic + 3 * (ork_canavar_y_aralik + resim_yukseklik)}, 0.0f, ork_canavar_olcek, WHITE);
        DrawTextureEx(ork_canavar5, (Vector2){ork_canavar_x, sol_resim_y_baslangic + 4 * (ork_canavar_y_aralik + resim_yukseklik)}, 0.0f, ork_canavar_olcek, WHITE);
        DrawTextureEx(ork_canavar6, (Vector2){ork_canavar_x, sol_resim_y_baslangic + 5 * (ork_canavar_y_aralik + resim_yukseklik)}, 0.0f, ork_canavar_olcek, WHITE);
        DrawTextureEx(ork_kahraman1, (Vector2){sag_resim_x, sol_resim_y_baslangic}, 0.0f, resim_olcek, WHITE);
        DrawTextureEx(ork_kahraman2, (Vector2){sag_resim_x, sol_resim_y_baslangic + resim_y_aralik + resim_yukseklik}, 0.0f, resim_olcek, WHITE);
        DrawTextureEx(ork_kahraman3, (Vector2){sag_resim_x, sol_resim_y_baslangic + 2 * (resim_y_aralik + resim_yukseklik)}, 0.0f, resim_olcek, WHITE);
        DrawTextureEx(ork_kahraman4, (Vector2){sag_resim_x, sol_resim_y_baslangic + 3 * (resim_y_aralik + resim_yukseklik)}, 0.0f, resim_olcek, WHITE);

        if (IsKeyPressed(KEY_ONE)) {
            break;
        }
        if (IsKeyPressed(KEY_TWO)) {
            return 0;
        }
        EndDrawing();
    }
    UnloadTexture(menu_arkaplan);
    UnloadTexture(insan_kahraman1);
    UnloadTexture(insan_kahraman2);
    UnloadTexture(insan_kahraman3);
    UnloadTexture(insan_kahraman4);
    UnloadTexture(insan_kahraman5);
    UnloadTexture(insan_canavar1);
    UnloadTexture(insan_canavar2);
    UnloadTexture(insan_canavar3);
    UnloadTexture(insan_canavar4);
    UnloadTexture(insan_canavar5);
    UnloadTexture(ork_kahraman1);
    UnloadTexture(ork_kahraman2);
    UnloadTexture(ork_kahraman3);
    UnloadTexture(ork_kahraman4);
    UnloadTexture(ork_canavar1);
    UnloadTexture(ork_canavar2);
    UnloadTexture(ork_canavar3);
    UnloadTexture(ork_canavar4);
    UnloadTexture(ork_canavar5);
    UnloadTexture(ork_canavar6);
    CloseWindow();
}

    InitWindow(ekran_genisligi, ekran_yuksekligi, "Savas Alani - Insan Imparatorlugu vs Ork Lejyonu");


    SetTargetFPS(60);

    Texture2D piyade = LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\piyade.png");
    Texture2D okcu = LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\okcu.png");
    Texture2D suvari = LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\suvari.png");
    Texture2D kusatma = LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\kusatma_makine.png");
    Texture2D orkDovuscu = LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\ork_dovuscu.png");
    Texture2D mizrakci = LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\mizrakci.png");
    Texture2D vargBinici = LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\varg_binici.png");
    Texture2D trol = LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\trol.png");

    float piyade_olcek = (float)hucre_boyutu / piyade.width;
    float okcu_olcek = (float)hucre_boyutu / okcu.width;
    float suvari_olcek = (float)hucre_boyutu / suvari.width;
    float kusatma_olcek = (float)hucre_boyutu / kusatma.width;
    float orkDovuscu_olcek = (float)hucre_boyutu / orkDovuscu.width;
    float mizrakci_olcek = (float)hucre_boyutu / mizrakci.width;
    float vargBinici_olcek = (float)hucre_boyutu / vargBinici.width;
    float trol_olcek = (float)hucre_boyutu / trol.width;

    Texture2D insan_kahramanlar[5];
    if(insan_sayi.heroes_i_sayi.fatih_sultan_mehmet_sayi == 1)
        insan_kahramanlar[0]=LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\fatih_sultan_mehmet.png");
    if(insan_sayi.heroes_i_sayi.yavuz_sultan_selim_sayi == 1)
        insan_kahramanlar[1]=LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\yavuz_sultan_selim.png");
    if(insan_sayi.heroes_i_sayi.tugrul_bey_sayi == 1)
        insan_kahramanlar[2]=LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\tugrul_bey.png");
    if(insan_sayi.heroes_i_sayi.alparslan_sayi == 1)
        insan_kahramanlar[3]=LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\alparslan.png");
    if(insan_sayi.heroes_i_sayi.mete_han_sayi == 1)
        insan_kahramanlar[4]=LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\mete_han.png");

    Texture2D insan_canavarlar[5];
    if(insan_sayi.creatures_i_sayi.ejderha_sayi == 1)
        insan_canavarlar[0]=LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\ejderha.png");
    if(insan_sayi.creatures_i_sayi.agri_dagi_devi_sayi == 1)
        insan_canavarlar[1]=LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\agri_dagi_devleri.png");
    if(insan_sayi.creatures_i_sayi.tepegoz_sayi == 1)
        insan_canavarlar[2]=LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\tepegoz.png");
    if(insan_sayi.creatures_i_sayi.karakurt_sayi == 1)
        insan_canavarlar[3]=LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\karakurt.png");
    if(insan_sayi.creatures_i_sayi.samur_sayi == 1)
        insan_canavarlar[4]=LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\samur.png");

    Texture2D ork_kahramanlar[4];
    if(ork_sayi.heroes_o_sayi.goruk_vahsi_sayi == 1)
        ork_kahramanlar[0]=LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\goruk_vahsi.png");
    if(ork_sayi.heroes_o_sayi.thruk_kemikkiran_sayi == 1)
        ork_kahramanlar[1]=LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\thruk_kemikkiran.png");
    if(ork_sayi.heroes_o_sayi.vrog_kafakiran_sayi == 1)
        ork_kahramanlar[2]=LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\vrog_kafakiran.png");
    if(ork_sayi.heroes_o_sayi.ugar_zalim_sayi == 1)
        ork_kahramanlar[3]=LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\Ugar_zalim.png");

    Texture2D ork_canavarlar[6];
    if(ork_sayi.creatures_o_sayi.kara_trol_sayi == 1)
        ork_canavarlar[0]=LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\kara_trol.png");
    if(ork_sayi.creatures_o_sayi.golge_kurtlari_sayi == 1)
        ork_canavarlar[1]=LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\golge_kurtlari.png");
    if(ork_sayi.creatures_o_sayi.camur_devleri_sayi == 1)
        ork_canavarlar[2]=LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\camur_devleri.png");
    if(ork_sayi.creatures_o_sayi.ates_iblisi_sayi == 1)
        ork_canavarlar[3]=LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\ates_iblisi.png");
    if(ork_sayi.creatures_o_sayi.makrog_savas_beyi_sayi == 1)
        ork_canavarlar[4]=LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\makrog_savas_beyi.png");
    if(ork_sayi.creatures_o_sayi.buz_devleri_sayi == 1)
        ork_canavarlar[5]=LoadTexture("C:\\Users\vyusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\buz_devleri.png");

    Texture2D background = LoadTexture("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\Görseller\\arka_plan.png");

    int sol_ekran_x = 0;
    int sol_ekran_y = 0;
    int sol_ekran_genislik =x_ekseni;
    int sol_ekran_yukseklik = ekran_yuksekligi;

    float i_canavar_olcek = 0.20f;
    float i_kahraman_olcek = 0.20f;

    float kahraman_olcek = 0.20f;
    float canavar_olcek = 0.20f;
    int kahraman_aralik = 150;
    int canavar_aralik = 150;

    int sag_ekran_x =   ekran_genisligi - 350;
    int sag_ekran_y = 0;

    int aralik = 150;


    int saglik_bar_yuksekligi = 5;
    float parlama_alpha = 0.5f;
    int parlama_artis_yonu = 1;
    int piyade_efect =0,okcu_efect=0,suvari_efect=0,kusatma_makine_efect=0;
    int ork_dovuscu_efect=0,mizrakci_efect=0,varg_binici_efect=0,trol_efect=0;
    efect_belirleme_insan(&insan_sayi,&insan,&piyade_efect,&okcu_efect,&suvari_efect,&kusatma_makine_efect);
    efect_belirleme_ork(&ork_sayi,&ork,&ork_dovuscu_efect,&mizrakci_efect,&varg_binici_efect,&trol_efect);
    while (!WindowShouldClose())
    {
        parlama_alpha += 0.01f * parlama_artis_yonu;
        if (parlama_alpha >= 1.0f) parlama_artis_yonu = -1;
        if (parlama_alpha <= 0.2f) parlama_artis_yonu = 1;
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(background, 0, 0, WHITE);
        if(bus_kontrol == 0)
        {
            DrawText("SAVAS ONCESI",ekran_genisligi/2-MeasureText("SAVAS ONCESI",40)/2,20,40,WHITE);
        }
        if(bus_kontrol == 1)
        {
            DrawText("SAVAS SONRASI",ekran_genisligi/2-MeasureText("SAVAS SONRASI",40)/2,20,40,WHITE);
        }

        DrawText("Insan Imparatorlugu", x_ekseni + 50, y_ekseni - 40, 30, BLUE);
        DrawText("Ork Lejyonu", x_ekseni + izgara_genisligi - 280, y_ekseni - 40, 30, ORANGE);

        for (int x = 0; x < izgara_boyutu; x++)
        {
            for (int y = 0; y < izgara_boyutu; y++)
            {
                if (x < 10)
                {
                    DrawRectangle((float)(x_ekseni + x * hucre_boyutu), (float)(y_ekseni + y * hucre_boyutu), (float)hucre_boyutu, (float)hucre_boyutu, Fade(SKYBLUE,0.75f));  // Kýrmýzý taraf
                }
                else
                {
                    DrawRectangle((float)(x_ekseni + x * hucre_boyutu), (float)(y_ekseni + y * hucre_boyutu), (float)hucre_boyutu, (float)hucre_boyutu, Fade(ORANGE,0.75f));  // Mavi taraf
                }
                DrawRectangleLines((float)(x_ekseni + x * hucre_boyutu), (float)(y_ekseni + y * hucre_boyutu), (float)hucre_boyutu, (float)hucre_boyutu, WHITE);
            }
        }
        int parlama_x = x_ekseni + 100;
        int parlama_y = y_ekseni + izgara_yuksekligi + 50;
        int parlama_genisligi = 60;
        int parlama_bosluk = 150;
        Color parlama_renkleri[] = {
        (Color){ 0, 255, 255, (unsigned char)(parlama_alpha * 255) },
        (Color){ 255, 0, 0, (unsigned char)(parlama_alpha * 255) },
        (Color){ 128, 0, 255, (unsigned char)(parlama_alpha * 255) },
        (Color){ 255, 255, 0, (unsigned char)(parlama_alpha * 255) }
        };
        const char *parlama_aciklamalari[] = {
        "Savunma Bonusu",
        "Saldiri Bonusu",
        "Multi Bonus",
        "Kritik Sans Bonusu"
        };
        if(bus_kontrol==0)
        {
             for (int i = 0; i < 4; i++)
            {
                DrawCircleV((Vector2){parlama_x + i * (parlama_genisligi+ parlama_bosluk), parlama_y-20}, 20, parlama_renkleri[i]);
                DrawText(parlama_aciklamalari[i], parlama_x + i * (parlama_genisligi+parlama_bosluk) - 80, parlama_y + 10, 22, WHITE);
            }
        }

        int mevcut_satir = 1;
        int kalan_piyade = toplam_piyade;

        while (kalan_piyade > 0)
        {
            int birlik_hucrede = (kalan_piyade > hucredeki_max_sayi) ? hucredeki_max_sayi : kalan_piyade;

            Vector2 piyade_yer = (Vector2)
            {
                (float)(x_ekseni + 5 * hucre_boyutu), (float)(y_ekseni + mevcut_satir * hucre_boyutu)
            };
            if(bus_kontrol==0)
            {
                if(piyade_efect==1)
                {
                    DrawCircleV((Vector2)
                    {
                        piyade_yer.x + hucre_boyutu / 2.0f, piyade_yer.y + hucre_boyutu / 2.0f
                    }, hucre_boyutu * 0.7f, (Color)
                    {
                        0, 255, 255, (unsigned char)(parlama_alpha * 255)
                    });
                }
                else if(piyade_efect==2)
                {
                    DrawCircleV((Vector2)
                    {
                        piyade_yer.x + hucre_boyutu / 2.0f, piyade_yer.y + hucre_boyutu / 2.0f
                    }, hucre_boyutu * 0.7f, (Color)
                    {
                        255, 0, 0, (unsigned char)(parlama_alpha * 255)
                    });
                }
                else if(piyade_efect == 3)
                {
                    DrawCircleV((Vector2)
                    {
                        piyade_yer.x + hucre_boyutu / 2.0f, piyade_yer.y + hucre_boyutu / 2.0f
                    }, hucre_boyutu * 0.7f, (Color)
                    {
                        128, 0, 255, (unsigned char)(parlama_alpha * 255)
                    });
                }
                else if(piyade_efect==4)
                {
                    DrawCircleV((Vector2)
                    {
                        piyade_yer.x + hucre_boyutu / 2.0f, piyade_yer.y + hucre_boyutu / 2.0f
                    }, hucre_boyutu * 0.7f, (Color)
                    {
                        255, 255, 0, (unsigned char)(parlama_alpha * 255)
                    });
                }
            }
            DrawTextureEx(piyade, piyade_yer, 0.0f, piyade_olcek, WHITE);
            if(bus_kontrol ==0)
            {
                DrawRectangle(piyade_yer.x, piyade_yer.y + hucre_boyutu, hucre_boyutu, (float)saglik_bar_yuksekligi,BLACK);
                DrawRectangle(piyade_yer.x, piyade_yer.y + hucre_boyutu, tam_saglik * hucre_boyutu, (float)saglik_bar_yuksekligi, GREEN);
                DrawText("%100",piyade_yer.x + hucre_boyutu + 5, piyade_yer.y + hucre_boyutu,12,BLACK);
            }
            if (bus_kontrol == 1)
            {
                float kalan_saglik_piyade = insan.i_unit.piyadeler.saglik / bas_saglik_piyade;


                float saglik_bar_genislik = kalan_saglik_piyade * hucre_boyutu;
                DrawRectangle(piyade_yer.x, piyade_yer.y + hucre_boyutu,hucre_boyutu, (float)saglik_bar_yuksekligi,BLACK);
                Color saglik_bar_rengi;
                if (kalan_saglik_piyade > 0.5f)
                    saglik_bar_rengi = GREEN;
                else if (kalan_saglik_piyade > 0.2f)
                    saglik_bar_rengi = YELLOW;
                else
                    saglik_bar_rengi = RED;

                DrawRectangle(piyade_yer.x, piyade_yer.y + hucre_boyutu, saglik_bar_genislik, (float)saglik_bar_yuksekligi, saglik_bar_rengi);
                int saglik_yuzdesi = (int)(kalan_saglik_piyade * 100);
                char saglik_yazi[10];
                sprintf(saglik_yazi, "%%%d", saglik_yuzdesi);
                DrawText(saglik_yazi, piyade_yer.x + hucre_boyutu + 5, piyade_yer.y + hucre_boyutu, 12,BLACK);
            }

            sprintf(birlik_sayisi, "%d", birlik_hucrede);
            DrawText(birlik_sayisi, piyade_yer.x + hucre_boyutu / 2 - MeasureText(birlik_sayisi,10)/2, piyade_yer.y - 15, 15, BLACK);

            kalan_piyade -= birlik_hucrede;
            mevcut_satir += 2;
        }

        mevcut_satir = 1;
        int kalan_okcu = toplam_okcu;

        while (kalan_okcu > 0)
        {
            int birlik_hucrede = (kalan_okcu > hucredeki_max_sayi) ? hucredeki_max_sayi : kalan_okcu;

            Vector2 okcu_yer = (Vector2)
            {
                (float)(x_ekseni + 3 * hucre_boyutu), (float)(y_ekseni + mevcut_satir * hucre_boyutu)
            };
            if(bus_kontrol==0)
            {
                if(okcu_efect==1)
                {
                    DrawCircleV((Vector2)
                    {
                        okcu_yer.x + hucre_boyutu / 2.0f, okcu_yer.y + hucre_boyutu / 2.0f
                    }, hucre_boyutu * 0.7f, (Color)
                    {
                        0, 255, 255, (unsigned char)(parlama_alpha * 255)
                    });
                }
                else if(okcu_efect==2)
                {
                    DrawCircleV((Vector2)
                    {
                        okcu_yer.x + hucre_boyutu / 2.0f, okcu_yer.y + hucre_boyutu / 2.0f
                    }, hucre_boyutu * 0.7f, (Color)
                    {
                        255, 0, 0, (unsigned char)(parlama_alpha * 255)
                    });
                }
                else if(okcu_efect == 3)
                {
                    DrawCircleV((Vector2)
                    {
                        okcu_yer.x + hucre_boyutu / 2.0f, okcu_yer.y + hucre_boyutu / 2.0f
                    }, hucre_boyutu * 0.7f, (Color)
                    {
                        128, 0, 255, (unsigned char)(parlama_alpha * 255)
                    });
                }
                else if(okcu_efect==4)
                {
                    DrawCircleV((Vector2)
                    {
                        okcu_yer.x + hucre_boyutu / 2.0f, okcu_yer.y + hucre_boyutu / 2.0f
                    }, hucre_boyutu * 0.7f, (Color)
                    {
                        255, 255, 0, (unsigned char)(parlama_alpha * 255)
                    });
                }
            }
            DrawTextureEx(okcu, okcu_yer, 0.0f, okcu_olcek, WHITE);

            if(bus_kontrol == 0)
            {
                DrawRectangle(okcu_yer.x, okcu_yer.y + hucre_boyutu, hucre_boyutu, (float)saglik_bar_yuksekligi,BLACK);
                DrawRectangle(okcu_yer.x, okcu_yer.y + hucre_boyutu, tam_saglik * hucre_boyutu, (float)saglik_bar_yuksekligi, GREEN);
                DrawText("%100",okcu_yer.x + hucre_boyutu + 5, okcu_yer.y + hucre_boyutu,12,BLACK);
            }
            if (bus_kontrol == 1)
            {
                float kalan_saglik_okcu = insan.i_unit.okcular.saglik / bas_saglik_okcu;
                float saglik_bar_genislik = kalan_saglik_okcu * hucre_boyutu;
                DrawRectangle(okcu_yer.x, okcu_yer.y + hucre_boyutu,hucre_boyutu, (float)saglik_bar_yuksekligi,BLACK);
                Color saglik_bar_rengi;
                if (kalan_saglik_okcu > 0.5f)
                    saglik_bar_rengi = GREEN;
                else if (kalan_saglik_okcu > 0.2f)
                    saglik_bar_rengi = YELLOW;
                else
                    saglik_bar_rengi = RED;
                DrawRectangle(okcu_yer.x, okcu_yer.y + hucre_boyutu, saglik_bar_genislik, (float)saglik_bar_yuksekligi, saglik_bar_rengi);
                int saglik_yuzdesi = (int)(kalan_saglik_okcu * 100);
                char saglik_yazi[10];
                sprintf(saglik_yazi, "%%%d", saglik_yuzdesi);
                DrawText(saglik_yazi, okcu_yer.x + hucre_boyutu + 5, okcu_yer.y + hucre_boyutu, 12,BLACK);
            }

            sprintf(birlik_sayisi, "%d", birlik_hucrede);
            DrawText(birlik_sayisi, okcu_yer.x + hucre_boyutu / 2 - MeasureText(birlik_sayisi,10)/2, okcu_yer.y - 15, 15, BLACK);

            kalan_okcu -= birlik_hucrede;
            mevcut_satir += 2;
        }
        mevcut_satir = 1;
        int kalan_suvari = toplam_suvari;

        while (kalan_suvari > 0)
        {
            int birlik_hucrede = (kalan_suvari > hucredeki_max_sayi) ? hucredeki_max_sayi : kalan_suvari;
            Vector2 suvari_yer = (Vector2)
            {
                (float)(x_ekseni + 7 * hucre_boyutu), (float)(y_ekseni + mevcut_satir * hucre_boyutu)
            };
            if(bus_kontrol==0)
            {
                if(suvari_efect==1)
                {
                    DrawCircleV((Vector2)
                    {
                        suvari_yer.x + hucre_boyutu / 2.0f, suvari_yer.y + hucre_boyutu / 2.0f
                    }, hucre_boyutu * 0.7f, (Color)
                    {
                        0, 255, 255, (unsigned char)(parlama_alpha * 255)
                    });
                }
                else if(suvari_efect==2)
                {
                    DrawCircleV((Vector2)
                    {
                        suvari_yer.x + hucre_boyutu / 2.0f, suvari_yer.y + hucre_boyutu / 2.0f
                    }, hucre_boyutu * 0.7f, (Color)
                    {
                        255, 0, 0, (unsigned char)(parlama_alpha * 255)
                    });
                }
                else if(suvari_efect == 3)
                {
                    DrawCircleV((Vector2)
                    {
                        suvari_yer.x + hucre_boyutu / 2.0f, suvari_yer.y + hucre_boyutu / 2.0f
                    }, hucre_boyutu * 0.7f, (Color)
                    {
                        128, 0, 255, (unsigned char)(parlama_alpha * 255)
                    });
                }
                else if(suvari_efect==4)
                {
                    DrawCircleV((Vector2)
                    {
                        suvari_yer.x + hucre_boyutu / 2.0f, suvari_yer.y + hucre_boyutu / 2.0f
                    }, hucre_boyutu * 0.7f, (Color)
                    {
                        255, 255, 0, (unsigned char)(parlama_alpha * 255)
                    });
                }
            }
            DrawTextureEx(suvari, suvari_yer, 0.0f, mizrakci_olcek, WHITE);
            if(bus_kontrol == 0)
            {
                DrawRectangle(suvari_yer.x, suvari_yer.y + hucre_boyutu, hucre_boyutu, (float)saglik_bar_yuksekligi,BLACK);
                DrawRectangle(suvari_yer.x, suvari_yer.y + hucre_boyutu, tam_saglik * hucre_boyutu, (float)saglik_bar_yuksekligi, GREEN);
                DrawText("%100",suvari_yer.x + hucre_boyutu + 5, suvari_yer.y + hucre_boyutu,12,BLACK);
            }
            if (bus_kontrol == 1)
            {

                float kalan_saglik_suvari = insan.i_unit.suvariler.saglik / bas_saglik_suvari;
                float saglik_bar_genislik = kalan_saglik_suvari * hucre_boyutu;
                DrawRectangle(suvari_yer.x, suvari_yer.y + hucre_boyutu,hucre_boyutu, (float)saglik_bar_yuksekligi,BLACK);
                Color saglik_bar_rengi;
                if (kalan_saglik_suvari > 0.5f)
                    saglik_bar_rengi = GREEN;
                else if (kalan_saglik_suvari > 0.2f)
                    saglik_bar_rengi = YELLOW;
                else
                    saglik_bar_rengi = RED;
                DrawRectangle(suvari_yer.x, suvari_yer.y + hucre_boyutu, saglik_bar_genislik, (float)saglik_bar_yuksekligi, saglik_bar_rengi);
                int saglik_yuzdesi = (int)(kalan_saglik_suvari * 100);
                char saglik_yazi[10];
                sprintf(saglik_yazi, "%%%d", saglik_yuzdesi);
                DrawText(saglik_yazi, suvari_yer.x + hucre_boyutu + 5, suvari_yer.y + hucre_boyutu, 12,BLACK);
            }
            sprintf(birlik_sayisi, "%d", birlik_hucrede);
            DrawText(birlik_sayisi, suvari_yer.x + hucre_boyutu / 2 - MeasureText(birlik_sayisi,10)/2, suvari_yer.y - 15, 15, BLACK);

            kalan_suvari -= birlik_hucrede;
            mevcut_satir += 2;
        }
        mevcut_satir = 1;
        int kalan_kusatma = toplam_kusatma;
        while (kalan_kusatma > 0)
        {
            int birlik_hucrede = (kalan_kusatma > hucredeki_max_sayi) ? hucredeki_max_sayi : kalan_kusatma;

            Vector2 kusatma_yer = (Vector2)
            {
                (float)(x_ekseni + 1 * hucre_boyutu), (float)(y_ekseni + mevcut_satir * hucre_boyutu)
            };
            if(bus_kontrol==0)
            {
                if(kusatma_makine_efect==1)
                {
                    DrawCircleV((Vector2)
                    {
                        kusatma_yer.x + hucre_boyutu / 2.0f, kusatma_yer.y + hucre_boyutu / 2.0f
                    }, hucre_boyutu * 0.7f, (Color)
                    {
                        0, 255, 255, (unsigned char)(parlama_alpha * 255)
                    });
                }
                else if(kusatma_makine_efect==2)
                {
                    DrawCircleV((Vector2)
                    {
                        kusatma_yer.x + hucre_boyutu / 2.0f, kusatma_yer.y + hucre_boyutu / 2.0f
                    }, hucre_boyutu * 0.7f, (Color)
                    {
                        255, 0, 0, (unsigned char)(parlama_alpha * 255)
                    });
                }
                else if(kusatma_makine_efect == 3)
                {
                    DrawCircleV((Vector2)
                    {
                        kusatma_yer.x + hucre_boyutu / 2.0f, kusatma_yer.y + hucre_boyutu / 2.0f
                    }, hucre_boyutu * 0.7f, (Color)
                    {
                        128, 0, 255, (unsigned char)(parlama_alpha * 255)
                    });
                }
                else if(kusatma_makine_efect==4)
                {
                    DrawCircleV((Vector2)
                    {
                        kusatma_yer.x + hucre_boyutu / 2.0f, kusatma_yer.y + hucre_boyutu / 2.0f
                    }, hucre_boyutu * 0.7f, (Color)
                    {
                        255, 255, 0, (unsigned char)(parlama_alpha * 255)
                    });
                }
            }
            DrawTextureEx(kusatma, kusatma_yer, 0.0f, kusatma_olcek, WHITE);
            if(bus_kontrol == 0)
            {
                DrawRectangle(kusatma_yer.x, kusatma_yer.y + hucre_boyutu, hucre_boyutu, (float)saglik_bar_yuksekligi,BLACK);
                DrawRectangle(kusatma_yer.x, kusatma_yer.y + hucre_boyutu, tam_saglik * hucre_boyutu, (float)saglik_bar_yuksekligi, GREEN);
                DrawText("%100",kusatma_yer.x + hucre_boyutu + 5, kusatma_yer.y + hucre_boyutu,12,BLACK);
            }
            if (bus_kontrol == 1)
            {

                float kalan_saglik_kusatma = insan.i_unit.kusatma_makineleri.saglik / bas_saglik_kusatma_makine;
                float saglik_bar_genislik = kalan_saglik_kusatma * hucre_boyutu;
                DrawRectangle(kusatma_yer.x, kusatma_yer.y + hucre_boyutu,hucre_boyutu, (float)saglik_bar_yuksekligi,BLACK);
                Color saglik_bar_rengi;
                if (kalan_saglik_kusatma > 0.5f)
                    saglik_bar_rengi = GREEN;
                else if (kalan_saglik_kusatma > 0.2f)
                    saglik_bar_rengi = YELLOW;
                else
                    saglik_bar_rengi = RED;
                DrawRectangle(kusatma_yer.x, kusatma_yer.y + hucre_boyutu, saglik_bar_genislik, (float)saglik_bar_yuksekligi, saglik_bar_rengi);
                int saglik_yuzdesi = (int)(kalan_saglik_kusatma * 100);
                char saglik_yazi[10];
                sprintf(saglik_yazi, "%%%d", saglik_yuzdesi);
                DrawText(saglik_yazi, kusatma_yer.x + hucre_boyutu + 5, kusatma_yer.y + hucre_boyutu, 12,BLACK);
            }

            sprintf(birlik_sayisi, "%d", birlik_hucrede);
            DrawText(birlik_sayisi, kusatma_yer.x + hucre_boyutu / 2 - MeasureText(birlik_sayisi,10)/2, kusatma_yer.y - 15, 15, BLACK);
            kalan_kusatma -= birlik_hucrede;
            mevcut_satir += 2;
        }
        mevcut_satir = 1;
        int kalan_orkDovuscu = toplam_orkDovuscu;

        while (kalan_orkDovuscu > 0)
        {
            int birlik_hucrede = (kalan_orkDovuscu > hucredeki_max_sayi) ? hucredeki_max_sayi : kalan_orkDovuscu;

            Vector2 orkDovuscu_yer = (Vector2)
            {
                (float)(x_ekseni + 16 * hucre_boyutu), (float)(y_ekseni + mevcut_satir * hucre_boyutu)
            };
            if(bus_kontrol==0)
            {
                if(ork_dovuscu_efect==1)
                {
                    DrawCircleV((Vector2)
                    {
                        orkDovuscu_yer.x + hucre_boyutu / 2.0f, orkDovuscu_yer.y + hucre_boyutu / 2.0f
                    }, hucre_boyutu * 0.7f, (Color)
                    {
                        0, 255, 255, (unsigned char)(parlama_alpha * 255)
                    });
                }
                else if(ork_dovuscu_efect==2)
                {
                    DrawCircleV((Vector2)
                    {
                        orkDovuscu_yer.x + hucre_boyutu / 2.0f, orkDovuscu_yer.y + hucre_boyutu / 2.0f
                    }, hucre_boyutu * 0.7f, (Color)
                    {
                        255, 0, 0, (unsigned char)(parlama_alpha * 255)
                    });
                }
                else if(ork_dovuscu_efect == 3)
                {
                    DrawCircleV((Vector2)
                    {
                        orkDovuscu_yer.x + hucre_boyutu / 2.0f, orkDovuscu_yer.y + hucre_boyutu / 2.0f
                    }, hucre_boyutu * 0.7f, (Color)
                    {
                        128, 0, 255, (unsigned char)(parlama_alpha * 255)
                    });
                }
                else if(ork_dovuscu_efect==4)
                {
                    DrawCircleV((Vector2)
                    {
                        orkDovuscu_yer.x + hucre_boyutu / 2.0f, orkDovuscu_yer.y + hucre_boyutu / 2.0f
                    }, hucre_boyutu * 0.7f, (Color)
                    {
                        255, 255, 0, (unsigned char)(parlama_alpha * 255)
                    });
                }
            }
            DrawTextureEx(orkDovuscu, orkDovuscu_yer, 0.0f, orkDovuscu_olcek, WHITE);

            if(bus_kontrol == 0)
            {
                DrawRectangle(orkDovuscu_yer.x, orkDovuscu_yer.y + hucre_boyutu, hucre_boyutu, (float)saglik_bar_yuksekligi,BLACK);
                DrawRectangle(orkDovuscu_yer.x, orkDovuscu_yer.y + hucre_boyutu, tam_saglik * hucre_boyutu, (float)saglik_bar_yuksekligi, GREEN);
                DrawText("%100",orkDovuscu_yer.x + hucre_boyutu + 5, orkDovuscu_yer.y + hucre_boyutu,12,BLACK);
            }
            if (bus_kontrol == 1)
            {
                float kalan_saglik_ork = ork.o_unit.ork_dovusculeri.saglik / bas_saglik_ork_dovuscu;
                float saglik_bar_genislik = kalan_saglik_ork * hucre_boyutu;
                DrawRectangle(orkDovuscu_yer.x, orkDovuscu_yer.y + hucre_boyutu,hucre_boyutu, (float)saglik_bar_yuksekligi,BLACK);
                Color saglik_bar_rengi;
                if (kalan_saglik_ork > 0.5f)
                    saglik_bar_rengi = GREEN;
                else if (kalan_saglik_ork > 0.2f)
                    saglik_bar_rengi = YELLOW;
                else
                    saglik_bar_rengi = RED;
                DrawRectangle(orkDovuscu_yer.x, orkDovuscu_yer.y + hucre_boyutu, saglik_bar_genislik, (float)saglik_bar_yuksekligi, saglik_bar_rengi);
                int saglik_yuzdesi = (int)(kalan_saglik_ork * 100);
                char saglik_yazi[10];
                sprintf(saglik_yazi, "%%%d", saglik_yuzdesi);
                DrawText(saglik_yazi, orkDovuscu_yer.x + hucre_boyutu + 5, orkDovuscu_yer.y + hucre_boyutu, 12,BLACK);
            }
            sprintf(birlik_sayisi, "%d", birlik_hucrede);
            DrawText(birlik_sayisi, orkDovuscu_yer.x + hucre_boyutu / 2 - MeasureText(birlik_sayisi,10)/2, orkDovuscu_yer.y - 15, 15, BLACK);
            kalan_orkDovuscu -= birlik_hucrede;
            mevcut_satir += 2;
        }
        mevcut_satir = 1;
        int kalan_mizrakci = toplam_mizrakci;

        while (kalan_mizrakci > 0)
        {
            int birlik_hucrede = (kalan_mizrakci > hucredeki_max_sayi) ? hucredeki_max_sayi : kalan_mizrakci;

            Vector2 mizrakci_yer = (Vector2)
            {
                (float)(x_ekseni + 18 * hucre_boyutu), (float)(y_ekseni + mevcut_satir * hucre_boyutu)
            };
            if(bus_kontrol==0)
            {
                if(mizrakci_efect==1)
                {
                    DrawCircleV((Vector2)
                    {
                        mizrakci_yer.x + hucre_boyutu / 2.0f, mizrakci_yer.y + hucre_boyutu / 2.0f
                    }, hucre_boyutu * 0.7f, (Color)
                    {
                        0, 255, 255, (unsigned char)(parlama_alpha * 255)
                    });
                }
                else if(mizrakci_efect==2)
                {
                    DrawCircleV((Vector2)
                    {
                        mizrakci_yer.x + hucre_boyutu / 2.0f, mizrakci_yer.y + hucre_boyutu / 2.0f
                    }, hucre_boyutu * 0.7f, (Color)
                    {
                        255, 0, 0, (unsigned char)(parlama_alpha * 255)
                    });
                }
                else if(mizrakci_efect == 3)
                {
                    DrawCircleV((Vector2)
                    {
                        mizrakci_yer.x + hucre_boyutu / 2.0f, mizrakci_yer.y + hucre_boyutu / 2.0f
                    }, hucre_boyutu * 0.7f, (Color)
                    {
                        128, 0, 255, (unsigned char)(parlama_alpha * 255)
                    });
                }
                else if(mizrakci_efect==4)
                {
                    DrawCircleV((Vector2)
                    {
                        mizrakci_yer.x + hucre_boyutu / 2.0f, mizrakci_yer.y + hucre_boyutu / 2.0f
                    }, hucre_boyutu * 0.7f, (Color)
                    {
                        255, 255, 0, (unsigned char)(parlama_alpha * 255)
                    });
                }
            }
            DrawTextureEx(mizrakci, mizrakci_yer, 0.0f, mizrakci_olcek, WHITE);

            if(bus_kontrol==0)
            {
                DrawRectangle(mizrakci_yer.x, mizrakci_yer.y + hucre_boyutu, hucre_boyutu, (float)saglik_bar_yuksekligi,BLACK);
                DrawRectangle(mizrakci_yer.x, mizrakci_yer.y + hucre_boyutu, tam_saglik * hucre_boyutu, (float)saglik_bar_yuksekligi, GREEN);
                DrawText("%100",mizrakci_yer.x + hucre_boyutu + 5, mizrakci_yer.y + hucre_boyutu,12,BLACK);
            }
            if (bus_kontrol == 1)
            {

                float kalan_saglik_mizrakci = ork.o_unit.mizrakcilar.saglik / bas_saglik_mizrakci;
                float saglik_bar_genislik = kalan_saglik_mizrakci * hucre_boyutu;
                DrawRectangle(mizrakci_yer.x, mizrakci_yer.y + hucre_boyutu,hucre_boyutu, (float)saglik_bar_yuksekligi,BLACK);
                Color saglik_bar_rengi;
                if (kalan_saglik_mizrakci > 0.5f)
                    saglik_bar_rengi = GREEN;
                else if (kalan_saglik_mizrakci > 0.2f)
                    saglik_bar_rengi = YELLOW;
                else
                    saglik_bar_rengi = RED;


                DrawRectangle(mizrakci_yer.x, mizrakci_yer.y + hucre_boyutu, saglik_bar_genislik, (float)saglik_bar_yuksekligi, saglik_bar_rengi);
                int saglik_yuzdesi = (int)(kalan_saglik_mizrakci * 100);
                char saglik_yazi[10];
                sprintf(saglik_yazi, "%%%d", saglik_yuzdesi);
                DrawText(saglik_yazi, mizrakci_yer.x + hucre_boyutu + 5, mizrakci_yer.y + hucre_boyutu, 12,BLACK);
            }

            sprintf(birlik_sayisi, "%d", birlik_hucrede);
            DrawText(birlik_sayisi, mizrakci_yer.x + hucre_boyutu / 2 - MeasureText(birlik_sayisi,10)/2, mizrakci_yer.y - 15, 15, BLACK);

            kalan_mizrakci -= birlik_hucrede;
            mevcut_satir += 2;
        }
        mevcut_satir = 1;
        int kalan_vargBinici = toplam_vargBinici;

        while (kalan_vargBinici > 0)
        {
            int birlik_hucrede = (kalan_vargBinici > hucredeki_max_sayi) ? hucredeki_max_sayi : kalan_vargBinici;

            Vector2 vargBinici_yer = (Vector2)
            {
                (float)(x_ekseni + 12 * hucre_boyutu), (float)(y_ekseni + mevcut_satir * hucre_boyutu)
            };
            if(bus_kontrol==0)
            {
                if(varg_binici_efect==1)
                {
                    DrawCircleV((Vector2)
                    {
                        vargBinici_yer.x + hucre_boyutu / 2.0f, vargBinici_yer.y + hucre_boyutu / 2.0f
                    }, hucre_boyutu * 0.7f, (Color)
                    {
                        0, 255, 255, (unsigned char)(parlama_alpha * 255)
                    });
                }
                else if(varg_binici_efect==2)
                {
                    DrawCircleV((Vector2)
                    {
                        vargBinici_yer.x + hucre_boyutu / 2.0f, vargBinici_yer.y + hucre_boyutu / 2.0f
                    }, hucre_boyutu * 0.7f, (Color)
                    {
                        255, 0, 0, (unsigned char)(parlama_alpha * 255)
                    });
                }
                else if(varg_binici_efect == 3)
                {
                    DrawCircleV((Vector2)
                    {
                        vargBinici_yer.x + hucre_boyutu / 2.0f, vargBinici_yer.y + hucre_boyutu / 2.0f
                    }, hucre_boyutu * 0.7f, (Color)
                    {
                        128, 0, 255, (unsigned char)(parlama_alpha * 255)
                    });
                }
                else if(varg_binici_efect==4)
                {
                    DrawCircleV((Vector2)
                    {
                        vargBinici_yer.x + hucre_boyutu / 2.0f, vargBinici_yer.y + hucre_boyutu / 2.0f
                    }, hucre_boyutu * 0.7f, (Color)
                    {
                        255, 255, 0, (unsigned char)(parlama_alpha * 255)
                    });
                }
            }
            DrawTextureEx(vargBinici, vargBinici_yer, 0.0f, vargBinici_olcek, WHITE);

            if(bus_kontrol == 0)
            {
                DrawRectangle(vargBinici_yer.x, vargBinici_yer.y + hucre_boyutu, hucre_boyutu, (float)saglik_bar_yuksekligi,BLACK);
                DrawRectangle(vargBinici_yer.x, vargBinici_yer.y + hucre_boyutu, tam_saglik * hucre_boyutu, (float)saglik_bar_yuksekligi, GREEN);
                DrawText("%100",vargBinici_yer.x + hucre_boyutu + 5, vargBinici_yer.y + hucre_boyutu,12,BLACK);
            }
            if (bus_kontrol == 1)
            {
                float kalan_saglik_binici = ork.o_unit.varg_binicileri.saglik / bas_saglik_varg_binici;
                float saglik_bar_genislik = kalan_saglik_binici * hucre_boyutu;
                DrawRectangle(vargBinici_yer.x, vargBinici_yer.y + hucre_boyutu,hucre_boyutu, (float)saglik_bar_yuksekligi,BLACK);
                Color saglik_bar_rengi;
                if (kalan_saglik_binici > 0.5f)
                    saglik_bar_rengi = GREEN;
                else if (kalan_saglik_binici > 0.2f)
                    saglik_bar_rengi = YELLOW;
                else
                    saglik_bar_rengi = RED;
                DrawRectangle(vargBinici_yer.x, vargBinici_yer.y + hucre_boyutu, saglik_bar_genislik, (float)saglik_bar_yuksekligi, saglik_bar_rengi);
                int saglik_yuzdesi = (int)(kalan_saglik_binici * 100);
                char saglik_yazi[10];
                sprintf(saglik_yazi, "%%%d", saglik_yuzdesi);
                DrawText(saglik_yazi, vargBinici_yer.x + hucre_boyutu + 5, vargBinici_yer.y + hucre_boyutu, 12,BLACK);
            }
            sprintf(birlik_sayisi, "%d", birlik_hucrede);
            DrawText(birlik_sayisi, vargBinici_yer.x + hucre_boyutu / 2 - MeasureText(birlik_sayisi,10)/2, vargBinici_yer.y - 15, 15, BLACK);
            kalan_vargBinici -= birlik_hucrede;
            mevcut_satir += 2;
        }
        mevcut_satir = 1;
        int kalan_trol = toplam_trol;

        while (kalan_trol > 0)
        {
            int birlik_hucrede = (kalan_trol > hucredeki_max_sayi) ? hucredeki_max_sayi : kalan_trol;
            Vector2 trol_yer = (Vector2)
            {
                (float)(x_ekseni + 14 * hucre_boyutu), (float)(y_ekseni + mevcut_satir * hucre_boyutu)
            };
            if(bus_kontrol==0)
            {
                if(trol_efect==1)
                {
                    DrawCircleV((Vector2)
                    {
                        trol_yer.x + hucre_boyutu / 2.0f, trol_yer.y + hucre_boyutu / 2.0f
                    }, hucre_boyutu * 0.7f, (Color)
                    {
                        0, 255, 255, (unsigned char)(parlama_alpha * 255)
                    });
                }
                else if(trol_efect==2)
                {
                    DrawCircleV((Vector2)
                    {
                        trol_yer.x + hucre_boyutu / 2.0f, trol_yer.y + hucre_boyutu / 2.0f
                    }, hucre_boyutu * 0.7f, (Color)
                    {
                        255, 0, 0, (unsigned char)(parlama_alpha * 255)
                    });
                }
                else if(trol_efect == 3)
                {
                    DrawCircleV((Vector2)
                    {
                        trol_yer.x + hucre_boyutu / 2.0f, trol_yer.y + hucre_boyutu / 2.0f
                    }, hucre_boyutu * 0.7f, (Color)
                    {
                        128, 0, 255, (unsigned char)(parlama_alpha * 255)
                    });
                }
                else if(trol_efect==4)
                {
                    DrawCircleV((Vector2)
                    {
                        trol_yer.x + hucre_boyutu / 2.0f, trol_yer.y + hucre_boyutu / 2.0f
                    }, hucre_boyutu * 0.7f, (Color)
                    {
                        255, 255, 0, (unsigned char)(parlama_alpha * 255)
                    });
                }
            }
            DrawTextureEx(trol, trol_yer, 0.0f, trol_olcek, WHITE);
            if(bus_kontrol == 0)
            {
                DrawRectangle(trol_yer.x, trol_yer.y + hucre_boyutu, hucre_boyutu, (float)saglik_bar_yuksekligi,BLACK);
                DrawRectangle(trol_yer.x, trol_yer.y + hucre_boyutu, tam_saglik * hucre_boyutu, (float)saglik_bar_yuksekligi, GREEN);
                DrawText("%100",trol_yer.x + hucre_boyutu + 5, trol_yer.y + hucre_boyutu,12,BLACK);
            }
            if (bus_kontrol == 1)
            {

                float kalan_saglik_trol = ork.o_unit.troller.saglik / bas_saglik_trol;
                float saglik_bar_genislik = kalan_saglik_trol * hucre_boyutu;
                DrawRectangle(trol_yer.x, trol_yer.y + hucre_boyutu,hucre_boyutu, (float)saglik_bar_yuksekligi,BLACK);
                Color saglik_bar_rengi;
                if (kalan_saglik_trol > 0.5f)
                    saglik_bar_rengi = GREEN;
                else if (kalan_saglik_trol > 0.2f)
                    saglik_bar_rengi = YELLOW;
                else
                    saglik_bar_rengi = RED;
                DrawRectangle(trol_yer.x, trol_yer.y + hucre_boyutu, saglik_bar_genislik, (float)saglik_bar_yuksekligi, saglik_bar_rengi);
                int saglik_yuzdesi = (int)(kalan_saglik_trol * 100);
                char saglik_yazi[10];
                sprintf(saglik_yazi, "%%%d", saglik_yuzdesi);
                DrawText(saglik_yazi, trol_yer.x + hucre_boyutu + 5, trol_yer.y + hucre_boyutu, 12,BLACK);
            }
            sprintf(birlik_sayisi, "%d", birlik_hucrede);
            DrawText(birlik_sayisi, trol_yer.x + hucre_boyutu / 2 - MeasureText(birlik_sayisi,10)/2, trol_yer.y - 15, 15, BLACK);
            kalan_trol -= birlik_hucrede;
            mevcut_satir += 2;
        }
        if(insan_sayi.heroes_i_sayi.fatih_sultan_mehmet_sayi == 1 && (insan.i_unit.piyadeler.saglik>0 || insan.i_unit.okcular.saglik>0 || insan.i_unit.suvariler.saglik>0 || insan.i_unit.kusatma_makineleri.saglik))
        {
            Vector2 fsm_pos = {sol_ekran_x + 70, sol_ekran_y + 1 * aralik};
            DrawTextureEx(insan_kahramanlar[0], fsm_pos, 0.0f, i_kahraman_olcek, WHITE);
            DrawText("FATIH SULTAN MEHMET", fsm_pos.x, fsm_pos.y + insan_kahramanlar[0].height * i_kahraman_olcek + 10, 20, DARKGRAY);
        }
        if (insan_sayi.heroes_i_sayi.yavuz_sultan_selim_sayi == 1 && (insan.i_unit.piyadeler.saglik>0 || insan.i_unit.okcular.saglik>0 || insan.i_unit.suvariler.saglik>0 || insan.i_unit.kusatma_makineleri.saglik>0))
        {
            Vector2 yss_pos = {sol_ekran_x + 70, sol_ekran_y + 1 * aralik};
            DrawTextureEx(insan_kahramanlar[1], yss_pos, 0.0f, i_kahraman_olcek, WHITE);
            DrawText("YAVUZ SULTAN SELIM", yss_pos.x, yss_pos.y + insan_kahramanlar[1].height * i_kahraman_olcek + 10, 20, GRAY);
        }
        if (insan_sayi.heroes_i_sayi.tugrul_bey_sayi == 1 && (insan.i_unit.piyadeler.saglik>0 || insan.i_unit.okcular.saglik>0 || insan.i_unit.suvariler.saglik>0 || insan.i_unit.kusatma_makineleri.saglik>0) )
        {
            Vector2 tugrul_pos = {sol_ekran_x + 70, sol_ekran_y + 1 * aralik};
            DrawTextureEx(insan_kahramanlar[2], tugrul_pos, 0.0f, i_kahraman_olcek, WHITE);
            DrawText("  TUGRUL BEY", tugrul_pos.x, tugrul_pos.y + insan_kahramanlar[2].height * i_kahraman_olcek + 10, 20, WHITE);
        }
        if (insan_sayi.heroes_i_sayi.alparslan_sayi == 1 && (insan.i_unit.piyadeler.saglik>0 || insan.i_unit.okcular.saglik>0 || insan.i_unit.suvariler.saglik>0 || insan.i_unit.kusatma_makineleri.saglik>0))
        {
            Vector2 alparslan_pos = {sol_ekran_x + 70, sol_ekran_y + 1 * aralik};
            DrawTextureEx(insan_kahramanlar[3], alparslan_pos, 0.0f, i_kahraman_olcek, WHITE);
            DrawText("  ALPARSLAN", alparslan_pos.x, alparslan_pos.y + insan_kahramanlar[3].height * i_kahraman_olcek + 10, 20, WHITE);
        }
        if (insan_sayi.heroes_i_sayi.mete_han_sayi == 1 && (insan.i_unit.piyadeler.saglik>0 || insan.i_unit.okcular.saglik>0 || insan.i_unit.suvariler.saglik>0 || insan.i_unit.kusatma_makineleri.saglik>0))
        {
            Vector2 mete_pos = {sol_ekran_x + 70, sol_ekran_y + 1 * aralik};
            DrawTextureEx(insan_kahramanlar[4], mete_pos, 0.0f, i_kahraman_olcek, WHITE);
            DrawText("    METEHAN", mete_pos.x, mete_pos.y + insan_kahramanlar[4].height * i_kahraman_olcek + 10, 20, WHITE);
        }
        if (insan_sayi.creatures_i_sayi.ejderha_sayi == 1 && (insan.i_unit.piyadeler.saglik>0 || insan.i_unit.okcular.saglik>0 || insan.i_unit.suvariler.saglik>0 || insan.i_unit.kusatma_makineleri.saglik>0))
        {
            Vector2 ejderha_pos = {sol_ekran_x + 70, sol_ekran_y + 4 * aralik};
            DrawTextureEx(insan_canavarlar[0], ejderha_pos, 0.0f, i_canavar_olcek, WHITE);
            DrawText("   EJDERHA", ejderha_pos.x, ejderha_pos.y + insan_canavarlar[0].height * i_canavar_olcek + 10, 20, WHITE);
        }
        if (insan_sayi.creatures_i_sayi.agri_dagi_devi_sayi == 1 && (insan.i_unit.piyadeler.saglik>0 || insan.i_unit.okcular.saglik>0 || insan.i_unit.suvariler.saglik>0 || insan.i_unit.kusatma_makineleri.saglik>0))
        {
            Vector2 agridevi_pos = {sol_ekran_x + 70, sol_ekran_y + 4 * aralik};
            DrawTextureEx(insan_canavarlar[1], agridevi_pos, 0.0f, i_canavar_olcek, WHITE);
            DrawText("AGRI DAGI DEVLERI", agridevi_pos.x, agridevi_pos.y + insan_canavarlar[1].height * i_canavar_olcek + 10, 20, WHITE);
        }
        if (insan_sayi.creatures_i_sayi.tepegoz_sayi == 1&& (insan.i_unit.piyadeler.saglik>0 || insan.i_unit.okcular.saglik>0 || insan.i_unit.suvariler.saglik>0 || insan.i_unit.kusatma_makineleri.saglik>0) )
        {

            Vector2 tepegoz_pos = {sol_ekran_x + 70, sol_ekran_y + 4 * aralik};
            DrawTextureEx(insan_canavarlar[2], tepegoz_pos, 0.0f, i_canavar_olcek, WHITE);
            DrawText("     TEPEGOZ", tepegoz_pos.x, tepegoz_pos.y + insan_canavarlar[2].height * i_canavar_olcek + 10, 20, WHITE);

        }
        if (insan_sayi.creatures_i_sayi.karakurt_sayi == 1 && (insan.i_unit.piyadeler.saglik>0 || insan.i_unit.okcular.saglik>0 || insan.i_unit.suvariler.saglik>0 || insan.i_unit.kusatma_makineleri.saglik>0))
        {
            Vector2 karakurt_pos = {sol_ekran_x + 70, sol_ekran_y + 4 * aralik};
            DrawTextureEx(insan_canavarlar[3], karakurt_pos, 0.0f, i_canavar_olcek, WHITE);
            DrawText("   KARAKURT", karakurt_pos.x, karakurt_pos.y + insan_canavarlar[3].height * i_canavar_olcek + 10, 20, WHITE);
        }
        if (insan_sayi.creatures_i_sayi.samur_sayi == 1 && (insan.i_unit.piyadeler.saglik>0 || insan.i_unit.okcular.saglik>0 || insan.i_unit.suvariler.saglik>0 || insan.i_unit.kusatma_makineleri.saglik>0))
        {
            Vector2 samur_pos = {sol_ekran_x + 70, sol_ekran_y + 4 * aralik};
            DrawTextureEx(insan_canavarlar[4], samur_pos, 0.0f, i_canavar_olcek, WHITE);
            DrawText("     SAMUR", samur_pos.x, samur_pos.y + insan_canavarlar[4].height * i_canavar_olcek + 10, 20, WHITE);
        }
        if (ork_sayi.heroes_o_sayi.goruk_vahsi_sayi == 1 && (ork.o_unit.ork_dovusculeri.saglik>0 || ork.o_unit.mizrakcilar.saglik>0 || ork.o_unit.varg_binicileri.saglik>0 || ork.o_unit.troller.saglik>0) )
        {
            Vector2 kahraman_pos = {sag_ekran_x + 70, sag_ekran_y + 1 * kahraman_aralik};
            DrawTextureEx(ork_kahramanlar[0], kahraman_pos, 0.0f, i_canavar_olcek, WHITE);
            DrawText("  GORUK VAHSI", kahraman_pos.x, kahraman_pos.y + ork_kahramanlar[0].height * kahraman_olcek + 10, 20, WHITE);
        }
        if (ork_sayi.heroes_o_sayi.thruk_kemikkiran_sayi == 1 && (ork.o_unit.ork_dovusculeri.saglik>0 || ork.o_unit.mizrakcilar.saglik>0 || ork.o_unit.varg_binicileri.saglik>0 || ork.o_unit.troller.saglik>0 ))
        {
            Vector2 kahraman_pos = {sag_ekran_x + 70, sag_ekran_y + 1 * kahraman_aralik};
            DrawTextureEx(ork_kahramanlar[1], kahraman_pos, 0.0f, kahraman_olcek, WHITE);
            DrawText("THRUK KEMIKKIRAN", kahraman_pos.x, kahraman_pos.y + ork_kahramanlar[1].height * kahraman_olcek + 10, 20, WHITE);
        }
        if (ork_sayi.heroes_o_sayi.vrog_kafakiran_sayi == 1 && (ork.o_unit.ork_dovusculeri.saglik>0 || ork.o_unit.mizrakcilar.saglik>0 || ork.o_unit.varg_binicileri.saglik>0 || ork.o_unit.troller.saglik>0 ))
        {
            Vector2 kahraman_pos = {sag_ekran_x + 70, sag_ekran_y + 1 * kahraman_aralik};
            DrawTextureEx(ork_kahramanlar[2], kahraman_pos, 0.0f, kahraman_olcek, WHITE);
            DrawText("  VROG KAFAKIRAN", kahraman_pos.x, kahraman_pos.y + ork_kahramanlar[2].height * kahraman_olcek + 10, 20, WHITE);
        }
        if (ork_sayi.heroes_o_sayi.ugar_zalim_sayi == 1 && (ork.o_unit.ork_dovusculeri.saglik>0 || ork.o_unit.mizrakcilar.saglik>0 || ork.o_unit.varg_binicileri.saglik>0 || ork.o_unit.troller.saglik>0 ))
        {
            Vector2 kahraman_pos = {sag_ekran_x + 70, sag_ekran_y + 1 * kahraman_aralik};
            DrawTextureEx(ork_kahramanlar[3], kahraman_pos, 0.0f, kahraman_olcek, WHITE);
            DrawText("   UGAR ZALIM", kahraman_pos.x, kahraman_pos.y + ork_kahramanlar[3].height * kahraman_olcek + 10, 20, WHITE);
        }
        if(ork_sayi.creatures_o_sayi.kara_trol_sayi == 1 && (ork.o_unit.ork_dovusculeri.saglik>0 || ork.o_unit.mizrakcilar.saglik>0 || ork.o_unit.varg_binicileri.saglik>0 || ork.o_unit.troller.saglik>0 ))
        {
            Vector2 canavar_pos = {sag_ekran_x + 70, sag_ekran_y + 4 * canavar_aralik};
            DrawTextureEx(ork_canavarlar[0], canavar_pos, 0.0f, canavar_olcek, WHITE);
            DrawText("    KARA TROL", canavar_pos.x, canavar_pos.y + ork_canavarlar[0].height * canavar_olcek + 10, 20, WHITE);

        }
        if (ork_sayi.creatures_o_sayi.golge_kurtlari_sayi == 1 && (ork.o_unit.ork_dovusculeri.saglik>0 || ork.o_unit.mizrakcilar.saglik>0 || ork.o_unit.varg_binicileri.saglik>0 || ork.o_unit.troller.saglik>0 ))
        {
            Vector2 canavar_pos = {sag_ekran_x + 70, sag_ekran_y + 4 * canavar_aralik};
            DrawTextureEx(ork_canavarlar[1], canavar_pos, 0.0f, canavar_olcek, WHITE);
            DrawText("  GOLGE KURTLARI", canavar_pos.x, canavar_pos.y + ork_canavarlar[1].height * canavar_olcek + 10, 20, WHITE);
        }
        if (ork_sayi.creatures_o_sayi.camur_devleri_sayi == 1 && (ork.o_unit.ork_dovusculeri.saglik>0 || ork.o_unit.mizrakcilar.saglik>0 || ork.o_unit.varg_binicileri.saglik>0 || ork.o_unit.troller.saglik>0 ))
        {
            Vector2 canavar_pos = {sag_ekran_x + 70, sag_ekran_y + 4 * canavar_aralik};
            DrawTextureEx(ork_canavarlar[2], canavar_pos, 0.0f, canavar_olcek, WHITE);
            DrawText(" CAMUR DEVLERI", canavar_pos.x, canavar_pos.y + ork_canavarlar[2].height * canavar_olcek + 10, 20, WHITE);
        }
        if (ork_sayi.creatures_o_sayi.ates_iblisi_sayi ==1  && (ork.o_unit.ork_dovusculeri.saglik>0 || ork.o_unit.mizrakcilar.saglik>0 || ork.o_unit.varg_binicileri.saglik>0 || ork.o_unit.troller.saglik>0 ) )
        {
            Vector2 canavar_pos = {sag_ekran_x + 70, sag_ekran_y + 4 * canavar_aralik};
            DrawTextureEx(ork_canavarlar[3], canavar_pos, 0.0f, canavar_olcek, WHITE);
            DrawText("    ATES IBLISI", canavar_pos.x, canavar_pos.y + ork_canavarlar[3].height * canavar_olcek + 10, 20, WHITE);
        }
        if (ork_sayi.creatures_o_sayi.makrog_savas_beyi_sayi == 1 && (ork.o_unit.ork_dovusculeri.saglik>0 || ork.o_unit.mizrakcilar.saglik>0 || ork.o_unit.varg_binicileri.saglik>0 || ork.o_unit.troller.saglik>0 ))
        {
            Vector2 canavar_pos = {sag_ekran_x + 70, sag_ekran_y + 4 * canavar_aralik};
            DrawTextureEx(ork_canavarlar[4], canavar_pos, 0.0f, canavar_olcek, WHITE);
            DrawText("MAKROG SAVAS BEYI", canavar_pos.x, canavar_pos.y + ork_canavarlar[4].height * canavar_olcek + 10, 20, WHITE);
        }
        if (ork_sayi.creatures_o_sayi.makrog_savas_beyi_sayi == 1 && (ork.o_unit.ork_dovusculeri.saglik>0 || ork.o_unit.mizrakcilar.saglik>0 || ork.o_unit.varg_binicileri.saglik>0 || ork.o_unit.troller.saglik>0 ))
        {
            Vector2 canavar_pos = {sag_ekran_x + 70, sag_ekran_y + 4 * canavar_aralik};
            DrawTextureEx(ork_canavarlar[5], canavar_pos, 0.0f, canavar_olcek, WHITE);
            DrawText("   BUZ DEVLERI", canavar_pos.x, canavar_pos.y + ork_canavarlar[5].height * canavar_olcek + 10, 20, WHITE);

        }

        if(bus_kontrol == 1)
        {
            if(insan.i_unit.piyadeler.saglik == 0 && insan.i_unit.okcular.saglik == 0 && insan.i_unit.suvariler.saglik == 0 && insan.i_unit.kusatma_makineleri.saglik==0)
            {
                DrawText("ORK LEJYONU KAZANDI", ekran_genisligi / 2 - MeasureText("ORK LEJYONU KAZANDI",45) / 2, y_ekseni + izgara_yuksekligi + 25,45,WHITE);
            }
            if(ork.o_unit.ork_dovusculeri.saglik == 0 && ork.o_unit.mizrakcilar.saglik == 0 && ork.o_unit.varg_binicileri.saglik == 0 && ork.o_unit.troller.saglik == 0)
            {
                DrawText("INSAN IMPARATORLUGU KAZANDI", ekran_genisligi / 2 - MeasureText("INSAN IMPARATORLUGU KAZANDI",45) / 2, y_ekseni + izgara_yuksekligi + 25, 42, WHITE);
            }
        }



        EndDrawing();
    }
    UnloadTexture(piyade);
    UnloadTexture(okcu);
    UnloadTexture(suvari);
    UnloadTexture(kusatma);
    UnloadTexture(orkDovuscu);
    UnloadTexture(mizrakci);
    UnloadTexture(vargBinici);
    UnloadTexture(trol);
    UnloadTexture(insan_kahramanlar[0]);
    UnloadTexture(insan_kahramanlar[1]);
    UnloadTexture(insan_kahramanlar[2]);
    UnloadTexture(insan_kahramanlar[3]);
    UnloadTexture(insan_kahramanlar[4]);
    UnloadTexture(insan_canavarlar[0]);
    UnloadTexture(insan_canavarlar[1]);
    UnloadTexture(insan_canavarlar[2]);
    UnloadTexture(insan_canavarlar[3]);
    UnloadTexture(insan_canavarlar[4]);
    UnloadTexture(ork_kahramanlar[0]);
    UnloadTexture(ork_kahramanlar[1]);
    UnloadTexture(ork_kahramanlar[2]);
    UnloadTexture(ork_kahramanlar[3]);
    UnloadTexture(ork_canavarlar[0]);
    UnloadTexture(ork_canavarlar[1]);
    UnloadTexture(ork_canavarlar[2]);
    UnloadTexture(ork_canavarlar[3]);
    UnloadTexture(ork_canavarlar[4]);
    UnloadTexture(ork_canavarlar[5]);
    UnloadTexture(background);

    CloseWindow();
    if(bus_kontrol == 1)
    {
        return 0;
    }
    bus_kontrol=1;

    struct insan_savas_ani i_savas_ani = {0};
    struct ork_savas_ani o_savas_ani = {0};
    int tur_sayisi=0;
    int yorgunluk_sayac=0;
    int i_toplam_saldiri,o_toplam_saldiri,i_toplam_savunma,o_toplam_savunma,net_hasar;
    double i_oranS_piyade,i_oranS_okcu, i_oranS_suvari, i_oranS_kusatma;
    double o_oranS_ork_dovuscu,o_oranS_mizrakci,o_oranS_varg_binici,o_oranS_trol;
    double ork_dovuscu_saglik_puani,mizrakci_saglik_puani,varg_binici_saglik_puani,trol_saglik_puani;
    double piyade_saglik_puani,okcu_saglik_puani,suvari_saglik_puani,kusatma_makine_saglik_puani;
    int yazma_kontrol_i=0,yazma_kontrol_o=0;

    while((insan_sayi.unit_i_sayi.piyade_sayi > 0 || insan_sayi.unit_i_sayi.okcu_sayi > 0 || insan_sayi.unit_i_sayi.suvari_sayi > 0 || insan_sayi.unit_i_sayi.kusatma_makine_sayi > 0) && (ork_sayi.unit_o_sayi.ork_dovuscu_sayi >0 || ork_sayi.unit_o_sayi.mizrakci_sayi > 0 || ork_sayi.unit_o_sayi.varg_binici_sayi > 0 || ork_sayi.unit_o_sayi.troller_sayi > 0))
    {
        i_savas_ani.piyade_savas.toplam_saldiri_gucu = insan_sayi.unit_i_sayi.piyade_sayi * insan.i_unit.piyadeler.saldiri;
        i_savas_ani.okcu_savas.toplam_saldiri_gucu = insan_sayi.unit_i_sayi.okcu_sayi * insan.i_unit.okcular.saldiri;
        i_savas_ani.suvari_savas.toplam_saldiri_gucu = insan_sayi.unit_i_sayi.suvari_sayi * insan.i_unit.suvariler.saldiri;
        i_savas_ani.kusatma_makineleri_savas.toplam_saldiri_gucu = insan_sayi.unit_i_sayi.kusatma_makine_sayi * insan.i_unit.kusatma_makineleri.saldiri;

        i_savas_ani.piyade_savas.toplam_savunma_gucu = insan_sayi.unit_i_sayi.piyade_sayi * insan.i_unit.piyadeler.savunma;
        i_savas_ani.okcu_savas.toplam_savunma_gucu = insan_sayi.unit_i_sayi.okcu_sayi * insan.i_unit.okcular.savunma;
        i_savas_ani.suvari_savas.toplam_savunma_gucu = insan_sayi.unit_i_sayi.suvari_sayi * insan.i_unit.suvariler.savunma;
        i_savas_ani.kusatma_makineleri_savas.toplam_savunma_gucu = insan_sayi.unit_i_sayi.kusatma_makine_sayi * insan.i_unit.kusatma_makineleri.savunma;

        o_savas_ani.ork_dovuscu_savas.toplam_saldiri_gucu = ork_sayi.unit_o_sayi.ork_dovuscu_sayi * ork.o_unit.ork_dovusculeri.saldiri;
        o_savas_ani.mizrakci_savas.toplam_saldiri_gucu = ork_sayi.unit_o_sayi.mizrakci_sayi * ork.o_unit.mizrakcilar.saldiri;
        o_savas_ani.varg_binici_savas.toplam_saldiri_gucu = ork_sayi.unit_o_sayi.varg_binici_sayi * ork.o_unit.varg_binicileri.saldiri;
        o_savas_ani.troller_savas.toplam_saldiri_gucu = ork_sayi.unit_o_sayi.troller_sayi * ork.o_unit.troller.saldiri;

        o_savas_ani.ork_dovuscu_savas.toplam_savunma_gucu = ork_sayi.unit_o_sayi.ork_dovuscu_sayi * ork.o_unit.ork_dovusculeri.savunma;
        o_savas_ani.mizrakci_savas.toplam_savunma_gucu = ork_sayi.unit_o_sayi.mizrakci_sayi * ork.o_unit.mizrakcilar.savunma;
        o_savas_ani.varg_binici_savas.toplam_savunma_gucu = ork_sayi.unit_o_sayi.varg_binici_sayi * ork.o_unit.varg_binicileri.savunma;
        o_savas_ani.troller_savas.toplam_savunma_gucu = ork_sayi.unit_o_sayi.troller_sayi * ork.o_unit.troller.savunma;

        if(insan_sayi.heroes_i_sayi.alparslan_sayi == 1)
        {
            insan_kahraman_etkisi(&insan, &i_savas_ani, insan.i_heroes.alparslan.etkiledigi_birim, insan.i_heroes.alparslan.bonus_turu, insan.i_heroes.alparslan.bonus_degeri);
        }
        if(insan_sayi.heroes_i_sayi.fatih_sultan_mehmet_sayi == 1)
        {
            insan_kahraman_etkisi(&insan, &i_savas_ani, insan.i_heroes.fatih_Sultan_Mehmet.etkiledigi_birim, insan.i_heroes.fatih_Sultan_Mehmet.bonus_turu, insan.i_heroes.fatih_Sultan_Mehmet.bonus_degeri);
        }
        if(insan_sayi.heroes_i_sayi.mete_han_sayi == 1)
        {
            insan_kahraman_etkisi(&insan, &i_savas_ani, insan.i_heroes.mete_Han.etkiledigi_birim, insan.i_heroes.mete_Han.bonus_turu, insan.i_heroes.mete_Han.bonus_degeri);
        }
        if(insan_sayi.heroes_i_sayi.yavuz_sultan_selim_sayi == 1)
        {
            insan_kahraman_etkisi(&insan, &i_savas_ani, insan.i_heroes.yavuz_Sultan_Selim.etkiledigi_birim, insan.i_heroes.yavuz_Sultan_Selim.bonus_turu, insan.i_heroes.yavuz_Sultan_Selim.bonus_degeri);
        }
        if(insan_sayi.heroes_i_sayi.tugrul_bey_sayi == 1)
        {
            insan_kahraman_etkisi(&insan, &i_savas_ani, insan.i_heroes.tugrul_Bey.etkiledigi_birim, insan.i_heroes.tugrul_Bey.bonus_turu, insan.i_heroes.tugrul_Bey.bonus_degeri);
        }
        if(ork_sayi.heroes_o_sayi.goruk_vahsi_sayi == 1)
        {
            ork_kahraman_etkisi(&ork, &o_savas_ani, ork.o_heroes.goruk_Vahsi.etkiledigi_birim, ork.o_heroes.goruk_Vahsi.bonus_turu, ork.o_heroes.goruk_Vahsi.bonus_degeri);
        }
        if(ork_sayi.heroes_o_sayi.thruk_kemikkiran_sayi == 1)
        {
            ork_kahraman_etkisi(&ork, &o_savas_ani, ork.o_heroes.thruk_Kemikkiran.etkiledigi_birim, ork.o_heroes.thruk_Kemikkiran.bonus_turu, ork.o_heroes.thruk_Kemikkiran.bonus_degeri);
        }
        if(ork_sayi.heroes_o_sayi.vrog_kafakiran_sayi == 1)
        {
            ork_kahraman_etkisi(&ork, &o_savas_ani, ork.o_heroes.vrog_Kafakiran.etkiledigi_birim, ork.o_heroes.vrog_Kafakiran.bonus_turu, ork.o_heroes.vrog_Kafakiran.bonus_degeri);
        }
        if(ork_sayi.heroes_o_sayi.ugar_zalim_sayi == 1)
        {
            ork_kahraman_etkisi(&ork, &o_savas_ani, ork.o_heroes.ugar_Zalim.etkiledigi_birim, ork.o_heroes.ugar_Zalim.bonus_turu, ork.o_heroes.ugar_Zalim.bonus_degeri);
        }
        if(insan_sayi.creatures_i_sayi.ejderha_sayi == 1)
        {
            insan_canavar_etkisi(&insan, &i_savas_ani, insan.i_creatures.ejderha.etkiledigi_birim, insan.i_creatures.ejderha.bonus_turu, insan.i_creatures.ejderha.bonus_degeri);
        }
        if(insan_sayi.creatures_i_sayi.agri_dagi_devi_sayi == 1)
        {
            insan_canavar_etkisi(&insan, &i_savas_ani, insan.i_creatures.agri_Dagi_Devleri.etkiledigi_birim, insan.i_creatures.agri_Dagi_Devleri.bonus_turu, insan.i_creatures.agri_Dagi_Devleri.bonus_degeri);
        }
        if(insan_sayi.creatures_i_sayi.tepegoz_sayi == 1)
        {
            insan_canavar_etkisi(&insan, &i_savas_ani, insan.i_creatures.tepegoz.etkiledigi_birim, insan.i_creatures.tepegoz.bonus_turu, insan.i_creatures.tepegoz.bonus_degeri);
        }
        if(insan_sayi.creatures_i_sayi.karakurt_sayi == 1)
        {
            insan_canavar_etkisi(&insan, &i_savas_ani, insan.i_creatures.karakurt.etkiledigi_birim, insan.i_creatures.karakurt.bonus_turu, insan.i_creatures.karakurt.bonus_degeri);
        }
        if(insan_sayi.creatures_i_sayi.samur_sayi == 1)
        {
            insan_canavar_etkisi(&insan, &i_savas_ani, insan.i_creatures.samur.etkiledigi_birim, insan.i_creatures.samur.bonus_turu, insan.i_creatures.samur.bonus_degeri);
        }
        if(ork_sayi.creatures_o_sayi.kara_trol_sayi == 1)
        {
            ork_canavar_etkisi(&ork, &o_savas_ani, ork.o_creatures.kara_Troll.etkiledigi_birim, ork.o_creatures.kara_Troll.bonus_turu, ork.o_creatures.kara_Troll.bonus_degeri);
        }
        if(ork_sayi.creatures_o_sayi.golge_kurtlari_sayi == 1)
        {
            ork_canavar_etkisi(&ork, &o_savas_ani, ork.o_creatures.golge_Kurtlari.etkiledigi_birim, ork.o_creatures.golge_Kurtlari.bonus_turu, ork.o_creatures.golge_Kurtlari.bonus_degeri);
        }
        if(ork_sayi.creatures_o_sayi.camur_devleri_sayi == 1)
        {
            ork_canavar_etkisi(&ork, &o_savas_ani, ork.o_creatures.camur_Devleri.etkiledigi_birim, ork.o_creatures.camur_Devleri.bonus_turu, ork.o_creatures.camur_Devleri.bonus_degeri);
        }
        if(ork_sayi.creatures_o_sayi.ates_iblisi_sayi == 1)
        {
            ork_canavar_etkisi(&ork, &o_savas_ani, ork.o_creatures.ates_Iblisi.etkiledigi_birim, ork.o_creatures.ates_Iblisi.bonus_turu, ork.o_creatures.ates_Iblisi.bonus_degeri);
        }
        if(ork_sayi.creatures_o_sayi.makrog_savas_beyi_sayi == 1)
        {
            ork_canavar_etkisi(&ork, &o_savas_ani, ork.o_creatures.makrog_Savas_Beyi.etkiledigi_birim, ork.o_creatures.makrog_Savas_Beyi.bonus_turu, ork.o_creatures.makrog_Savas_Beyi.bonus_degeri);
        }
        if(ork_sayi.creatures_o_sayi.buz_devleri_sayi == 1)
        {
            ork_canavar_etkisi(&ork, &o_savas_ani, ork.o_creatures.buz_Devleri.etkiledigi_birim, ork.o_creatures.buz_Devleri.bonus_turu, ork.o_creatures.buz_Devleri.bonus_degeri);
        }
        if(insan_sayi.research_i_sayi.saldiri_gelistirmesi_sayi != 0)
        {
            if(insan_sayi.research_i_sayi.saldiri_gelistirmesi_sayi == 1)
            {
                insan_arastirma_etkisi(&insan, &i_savas_ani, &research.saldiri_gelistirmesi.level1, 1);
            }
            if(insan_sayi.research_i_sayi.saldiri_gelistirmesi_sayi == 2)
            {
                insan_arastirma_etkisi(&insan, &i_savas_ani, &research.saldiri_gelistirmesi.level2, 2);
            }
            if(insan_sayi.research_i_sayi.saldiri_gelistirmesi_sayi == 3)
            {
                insan_arastirma_etkisi(&insan, &i_savas_ani, &research.saldiri_gelistirmesi.level3, 3);
            }
        }
        if(insan_sayi.research_i_sayi.savunma_ustaligi_sayi != 0)
        {
            if(insan_sayi.research_i_sayi.savunma_ustaligi_sayi == 1)
            {
                insan_arastirma_etkisi(&insan, &i_savas_ani, &research.savunma_ustaligi.level1, 1);
            }
            if(insan_sayi.research_i_sayi.savunma_ustaligi_sayi == 2)
            {
                insan_arastirma_etkisi(&insan, &i_savas_ani, &research.savunma_ustaligi.level2, 2);
            }
            if(insan_sayi.research_i_sayi.savunma_ustaligi_sayi == 3)
            {
                insan_arastirma_etkisi(&insan, &i_savas_ani, &research.savunma_ustaligi.level3, 3);
            }
        }
        if(insan_sayi.research_i_sayi.elit_egitim_sayi != 0)
        {
            if(insan_sayi.research_i_sayi.elit_egitim_sayi == 1)
            {
                insan_arastirma_etkisi(&insan, &i_savas_ani, &research.elit_egitim.level1, 1);
            }
            if(insan_sayi.research_i_sayi.elit_egitim_sayi == 2)
            {
                insan_arastirma_etkisi(&insan, &i_savas_ani, &research.elit_egitim.level2, 2);
            }
            if(insan_sayi.research_i_sayi.elit_egitim_sayi == 3)
            {
                insan_arastirma_etkisi(&insan, &i_savas_ani, &research.elit_egitim.level3, 3);
            }
        }
        if(insan_sayi.research_i_sayi.kusatma_ustaligi_sayi != 0)
        {
            if(insan_sayi.research_i_sayi.kusatma_ustaligi_sayi == 1)
            {
                insan_arastirma_etkisi(&insan, &i_savas_ani, &research.kusatma_ustaligi.level1, 1);
            }
            if(insan_sayi.research_i_sayi.kusatma_ustaligi_sayi == 2)
            {
                insan_arastirma_etkisi(&insan, &i_savas_ani, &research.kusatma_ustaligi.level2, 2);
            }
            if(insan_sayi.research_i_sayi.kusatma_ustaligi_sayi == 3)
            {
                insan_arastirma_etkisi(&insan, &i_savas_ani, &research.kusatma_ustaligi.level3, 3);
            }
        }
        if(ork_sayi.research_o_sayi.saldiri_gelistirmesi_sayi != 0)
        {
            if(ork_sayi.research_o_sayi.saldiri_gelistirmesi_sayi == 1)
            {
                ork_arastirma_etkisi(&ork, &o_savas_ani,&research.saldiri_gelistirmesi.level1, 1);
            }
            if(ork_sayi.research_o_sayi.saldiri_gelistirmesi_sayi == 2)
            {
                ork_arastirma_etkisi(&ork, &o_savas_ani,&research.saldiri_gelistirmesi.level2, 2);
            }
            if(ork_sayi.research_o_sayi.saldiri_gelistirmesi_sayi == 3)
            {
                ork_arastirma_etkisi(&ork, &o_savas_ani,&research.saldiri_gelistirmesi.level3, 3);
            }
        }
        if(ork_sayi.research_o_sayi.savunma_ustaligi_sayi != 0)
        {
            if(ork_sayi.research_o_sayi.savunma_ustaligi_sayi == 1)
            {
                ork_arastirma_etkisi(&ork, &o_savas_ani,&research.savunma_ustaligi.level1, 1);
            }
            if(ork_sayi.research_o_sayi.savunma_ustaligi_sayi == 2)
            {
                ork_arastirma_etkisi(&ork, &o_savas_ani,&research.savunma_ustaligi.level2, 2);
            }
            if(ork_sayi.research_o_sayi.savunma_ustaligi_sayi == 3)
            {
                ork_arastirma_etkisi(&ork, &o_savas_ani,&research.savunma_ustaligi.level3, 3);
            }
        }
        if(ork_sayi.research_o_sayi.elit_egitim_sayi != 0)
        {
            if(ork_sayi.research_o_sayi.elit_egitim_sayi == 1)
            {
                ork_arastirma_etkisi(&ork, &o_savas_ani,&research.elit_egitim.level1, 1);
            }
            if(ork_sayi.research_o_sayi.elit_egitim_sayi == 2)
            {
                ork_arastirma_etkisi(&ork, &o_savas_ani,&research.elit_egitim.level2, 2);
            }
            if(ork_sayi.research_o_sayi.elit_egitim_sayi == 3)
            {
                ork_arastirma_etkisi(&ork, &o_savas_ani,&research.elit_egitim.level3, 3);
            }
        }
        if(ork_sayi.research_o_sayi.kusatma_ustaligi_sayi != 0)
        {
            if(ork_sayi.research_o_sayi.kusatma_ustaligi_sayi == 1)
            {
                ork_arastirma_etkisi(&ork, &o_savas_ani,&research.kusatma_ustaligi.level1, 1);
            }
            if(ork_sayi.research_o_sayi.kusatma_ustaligi_sayi == 2)
            {
                ork_arastirma_etkisi(&ork, &o_savas_ani,&research.kusatma_ustaligi.level2, 2);
            }
            if(ork_sayi.research_o_sayi.kusatma_ustaligi_sayi == 3)
            {
                ork_arastirma_etkisi(&ork, &o_savas_ani,&research.kusatma_ustaligi.level3, 3);
            }
        }

        if(tur_sayisi/5 > 0)
        {
            yorgunluk_sayac = tur_sayisi/5;
            for(i =0 ; i< yorgunluk_sayac; i++)
            {
                i_savas_ani.piyade_savas.toplam_saldiri_gucu *= 0.9;
                i_savas_ani.okcu_savas.toplam_saldiri_gucu *= 0.9;
                i_savas_ani.suvari_savas.toplam_saldiri_gucu *= 0.9;
                i_savas_ani.kusatma_makineleri_savas.toplam_saldiri_gucu *= 0.9;
                i_savas_ani.piyade_savas.toplam_savunma_gucu *= 0.9;
                i_savas_ani.okcu_savas.toplam_savunma_gucu *= 0.9;
                i_savas_ani.suvari_savas.toplam_savunma_gucu *= 0.9;
                i_savas_ani.kusatma_makineleri_savas.toplam_savunma_gucu *= 0.9;

                o_savas_ani.ork_dovuscu_savas.toplam_saldiri_gucu *= 0.9;
                o_savas_ani.mizrakci_savas.toplam_saldiri_gucu *= 0.9;
                o_savas_ani.varg_binici_savas.toplam_saldiri_gucu *= 0.9;
                o_savas_ani.troller_savas.toplam_saldiri_gucu *= 0.9;
                o_savas_ani.ork_dovuscu_savas.toplam_savunma_gucu *= 0.9;
                o_savas_ani.mizrakci_savas.toplam_savunma_gucu *= 0.9;
                o_savas_ani.varg_binici_savas.toplam_savunma_gucu *= 0.9;
                o_savas_ani.troller_savas.toplam_savunma_gucu *= 0.9;
            }
        }

        if(tur_sayisi % 2 == 1 && yazma_kontrol_i == 0)
        {
            fptr = fopen("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\savas_sim.txt","a");
            if(fptr == NULL)
            {
                printf("Dosya '230202050_230202058/savas_sim.txt' bulunamadi. Lütfen dosyanin dogru isimde ve dogru dizinde oldugundan emin olun.");
            }
            else
            {
                fprintf(fptr,"\n\n%d. Adim Bilgileri Insan Imparatorlugu Saldirisi\n\n",tur_sayisi);
                fprintf(fptr,"Net Hasar: %d\n",net_hasar);
                fprintf(fptr,"*****INSAN IMPARATORLUGU*****\n\n");
                fprintf(fptr,"-----BIRIMLER-----\n\n");
                fprintf(fptr,"Piyadeler\n\n");
                fprintf(fptr,"Toplam sayi: %d\n",insan_sayi.unit_i_sayi.piyade_sayi);
                fprintf(fptr,"Toplam saldiri gucu: %.lf\n",i_savas_ani.piyade_savas.toplam_saldiri_gucu);
                fprintf(fptr,"Toplam savunma gucu: %.lf\n",i_savas_ani.piyade_savas.toplam_savunma_gucu);
                fprintf(fptr,"Toplam saglik: %.lf\n\n",insan.i_unit.piyadeler.saglik);

                fprintf(fptr,"Okcular\n\n");
                fprintf(fptr,"Toplam sayi: %d\n",insan_sayi.unit_i_sayi.okcu_sayi);
                fprintf(fptr,"Toplam saldiri gucu: %.lf\n",i_savas_ani.okcu_savas.toplam_saldiri_gucu);
                fprintf(fptr,"Toplam savunma gucu: %.lf\n",i_savas_ani.okcu_savas.toplam_savunma_gucu);
                fprintf(fptr,"Toplam saglik: %.lf\n\n",insan.i_unit.okcular.saglik);

                fprintf(fptr,"Suvariler\n\n");
                fprintf(fptr,"Toplam sayi: %d\n",insan_sayi.unit_i_sayi.suvari_sayi);
                fprintf(fptr,"Toplam saldiri gucu: %.lf\n",i_savas_ani.suvari_savas.toplam_saldiri_gucu);
                fprintf(fptr,"Toplam savunma gucu: %.lf\n",i_savas_ani.suvari_savas.toplam_savunma_gucu);
                fprintf(fptr,"Toplam saglik: %.lf\n\n",insan.i_unit.suvariler.saglik);

                fprintf(fptr,"Kusatma Makineleri\n\n");
                fprintf(fptr,"Toplam sayi: %d\n",insan_sayi.unit_i_sayi.kusatma_makine_sayi);
                fprintf(fptr,"Toplam saldiri gucu: %.lf\n",i_savas_ani.kusatma_makineleri_savas.toplam_saldiri_gucu);
                fprintf(fptr,"Toplam savunma gucu: %.lf\n",i_savas_ani.kusatma_makineleri_savas.toplam_savunma_gucu);
                fprintf(fptr,"Toplam saglik: %.lf\n\n",insan.i_unit.kusatma_makineleri.saglik);
                fprintf(fptr,"Insan Imparatorlugunun Toplam Saldiri Gucu: %.lf\n",(i_savas_ani.piyade_savas.toplam_saldiri_gucu+i_savas_ani.okcu_savas.toplam_saldiri_gucu+i_savas_ani.suvari_savas.toplam_saldiri_gucu+i_savas_ani.kusatma_makineleri_savas.toplam_saldiri_gucu));
                fprintf(fptr,"Insan Imparatorlugunun Toplam Savunma Gucu: %.lf\n\n",(i_savas_ani.piyade_savas.toplam_savunma_gucu+i_savas_ani.okcu_savas.toplam_savunma_gucu+i_savas_ani.suvari_savas.toplam_savunma_gucu+i_savas_ani.kusatma_makineleri_savas.toplam_savunma_gucu));

                fprintf(fptr,"*****ORK LEJYONU*****\n\n");
                fprintf(fptr,"-----BIRIMLER-----\n\n");
                fprintf(fptr,"Ork Dovusculeri\n\n");
                fprintf(fptr,"Toplam sayi: %d\n",ork_sayi.unit_o_sayi.ork_dovuscu_sayi);
                fprintf(fptr,"Toplam saldiri gucu: %.lf\n",o_savas_ani.ork_dovuscu_savas.toplam_saldiri_gucu);
                fprintf(fptr,"Toplam savunma gucu: %.lf\n",o_savas_ani.ork_dovuscu_savas.toplam_savunma_gucu);
                fprintf(fptr,"Toplam saglik: %.lf\n\n",ork.o_unit.ork_dovusculeri.saglik);

                fprintf(fptr,"Mizrakcilar\n\n");
                fprintf(fptr,"Toplam sayi: %d\n",ork_sayi.unit_o_sayi.mizrakci_sayi);
                fprintf(fptr,"Toplam saldiri gucu: %.lf\n",o_savas_ani.mizrakci_savas.toplam_saldiri_gucu);
                fprintf(fptr,"Toplam savunma gucu: %.lf\n",o_savas_ani.mizrakci_savas.toplam_savunma_gucu);
                fprintf(fptr,"Toplam saglik: %.lf\n\n",ork.o_unit.mizrakcilar.saglik);

                fprintf(fptr,"Varg binicileri\n\n");
                fprintf(fptr,"Toplam sayi: %d\n",ork_sayi.unit_o_sayi.varg_binici_sayi);
                fprintf(fptr,"Toplam saldiri gucu: %.lf\n",o_savas_ani.varg_binici_savas.toplam_saldiri_gucu);
                fprintf(fptr,"Toplam savunma gucu: %.lf\n",o_savas_ani.varg_binici_savas.toplam_savunma_gucu);
                fprintf(fptr,"Toplam saglik: %.lf\n\n",ork.o_unit.varg_binicileri.saglik);

                fprintf(fptr,"Troller\n\n");
                fprintf(fptr,"Toplam sayi: %d\n",ork_sayi.unit_o_sayi.troller_sayi);
                fprintf(fptr,"Toplam saldiri gucu: %.lf\n",o_savas_ani.troller_savas.toplam_saldiri_gucu);
                fprintf(fptr,"Toplam savunma gucu: %.lf\n",o_savas_ani.troller_savas.toplam_savunma_gucu);
                fprintf(fptr,"Toplam saglik: %.lf\n\n",ork.o_unit.troller.saglik);
                fprintf(fptr,"Ork Lejyonu Toplam Saldiri Gucu: %.lf\n",(o_savas_ani.ork_dovuscu_savas.toplam_saldiri_gucu+o_savas_ani.mizrakci_savas.toplam_saldiri_gucu+o_savas_ani.varg_binici_savas.toplam_saldiri_gucu+o_savas_ani.troller_savas.toplam_saldiri_gucu));
                fprintf(fptr,"Ork Lejyonu Toplam Savunma Gucu: %.lf\n\n",(o_savas_ani.ork_dovuscu_savas.toplam_savunma_gucu+o_savas_ani.mizrakci_savas.toplam_savunma_gucu+o_savas_ani.varg_binici_savas.toplam_savunma_gucu+o_savas_ani.troller_savas.toplam_savunma_gucu));
            }

            fclose(fptr);
        }
        if(tur_sayisi % 2 == 0 && tur_sayisi!=0 && yazma_kontrol_o == 0)
        {
            fptr = fopen("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\savas_sim.txt","a");
            if(fptr == NULL)
            {
                printf("Dosya '230202050_230202058/savas_sim.txt' bulunamadi. Lütfen dosyanin dogru isimde ve dogru dizinde oldugundan emin olun.");
            }
            else
            {
                fprintf(fptr,"\n\n%d. Adim Bilgileri Ork Lejyonu Saldirisi\n\n",tur_sayisi);
                fprintf(fptr,"Net Hasar: %d\n",net_hasar);
                fprintf(fptr,"*****INSAN IMPARATORLUGU*****\n\n");
                fprintf(fptr,"-----BIRIMLER-----\n\n");
                fprintf(fptr,"Piyadeler\n\n");
                fprintf(fptr,"Toplam sayi: %d\n",insan_sayi.unit_i_sayi.piyade_sayi);
                fprintf(fptr,"Toplam saldiri gucu: %.lf\n",i_savas_ani.piyade_savas.toplam_saldiri_gucu);
                fprintf(fptr,"Toplam savunma gucu: %.lf\n",i_savas_ani.piyade_savas.toplam_savunma_gucu);
                fprintf(fptr,"Toplam saglik: %.lf\n\n",insan.i_unit.piyadeler.saglik);

                fprintf(fptr,"Okcular\n\n");
                fprintf(fptr,"Toplam sayi: %d\n",insan_sayi.unit_i_sayi.okcu_sayi);
                fprintf(fptr,"Toplam saldiri gucu: %.lf\n",i_savas_ani.okcu_savas.toplam_saldiri_gucu);
                fprintf(fptr,"Toplam savunma gucu: %.lf\n",i_savas_ani.okcu_savas.toplam_savunma_gucu);
                fprintf(fptr,"Toplam saglik: %.lf\n\n",insan.i_unit.okcular.saglik);

                fprintf(fptr,"Suvariler\n\n");
                fprintf(fptr,"Toplam sayi: %d\n",insan_sayi.unit_i_sayi.suvari_sayi);
                fprintf(fptr,"Toplam saldiri gucu: %.lf\n",i_savas_ani.suvari_savas.toplam_saldiri_gucu);
                fprintf(fptr,"Toplam savunma gucu: %.lf\n",i_savas_ani.suvari_savas.toplam_savunma_gucu);
                fprintf(fptr,"Toplam saglik: %.lf\n\n",insan.i_unit.suvariler.saglik);

                fprintf(fptr,"Kusatma Makineleri\n\n");
                fprintf(fptr,"Toplam sayi: %d\n",insan_sayi.unit_i_sayi.kusatma_makine_sayi);
                fprintf(fptr,"Toplam saldiri gucu: %.lf\n",i_savas_ani.kusatma_makineleri_savas.toplam_saldiri_gucu);
                fprintf(fptr,"Toplam savunma gucu: %.lf\n",i_savas_ani.kusatma_makineleri_savas.toplam_savunma_gucu);
                fprintf(fptr,"Toplam saglik: %.lf\n\n",insan.i_unit.kusatma_makineleri.saglik);
                fprintf(fptr,"Insan Imparatorlugunun Toplam Saldiri Gucu: %.lf\n",(i_savas_ani.piyade_savas.toplam_saldiri_gucu+i_savas_ani.okcu_savas.toplam_saldiri_gucu+i_savas_ani.suvari_savas.toplam_saldiri_gucu+i_savas_ani.kusatma_makineleri_savas.toplam_saldiri_gucu));
                fprintf(fptr,"Insan Imparatorlugunun Toplam Savunma Gucu: %.lf\n\n",(i_savas_ani.piyade_savas.toplam_savunma_gucu+i_savas_ani.okcu_savas.toplam_savunma_gucu+i_savas_ani.suvari_savas.toplam_savunma_gucu+i_savas_ani.kusatma_makineleri_savas.toplam_savunma_gucu));

                fprintf(fptr,"*****ORK LEJYONU*****\n\n");
                fprintf(fptr,"-----BIRIMLER-----\n\n");
                fprintf(fptr,"Ork Dovusculeri\n\n");
                fprintf(fptr,"Toplam sayi: %d\n",ork_sayi.unit_o_sayi.ork_dovuscu_sayi);
                fprintf(fptr,"Toplam saldiri gucu: %.lf\n",o_savas_ani.ork_dovuscu_savas.toplam_saldiri_gucu);
                fprintf(fptr,"Toplam savunma gucu: %.lf\n",o_savas_ani.ork_dovuscu_savas.toplam_savunma_gucu);
                fprintf(fptr,"Toplam saglik: %.lf\n\n",ork.o_unit.ork_dovusculeri.saglik);

                fprintf(fptr,"Mizrakcilar\n\n");
                fprintf(fptr,"Toplam sayi: %d\n",ork_sayi.unit_o_sayi.mizrakci_sayi);
                fprintf(fptr,"Toplam saldiri gucu: %.lf\n",o_savas_ani.mizrakci_savas.toplam_saldiri_gucu);
                fprintf(fptr,"Toplam savunma gucu: %.lf\n",o_savas_ani.mizrakci_savas.toplam_savunma_gucu);
                fprintf(fptr,"Toplam saglik: %.lf\n\n",ork.o_unit.mizrakcilar.saglik);

                fprintf(fptr,"Varg binicileri\n\n");
                fprintf(fptr,"Toplam sayi: %d\n",ork_sayi.unit_o_sayi.varg_binici_sayi);
                fprintf(fptr,"Toplam saldiri gucu: %.lf\n",o_savas_ani.varg_binici_savas.toplam_saldiri_gucu);
                fprintf(fptr,"Toplam savunma gucu: %.lf\n",o_savas_ani.varg_binici_savas.toplam_savunma_gucu);
                fprintf(fptr,"Toplam saglik: %.lf\n\n",ork.o_unit.varg_binicileri.saglik);

                fprintf(fptr,"Troller\n\n");
                fprintf(fptr,"Toplam sayi: %d\n",ork_sayi.unit_o_sayi.troller_sayi);
                fprintf(fptr,"Toplam saldiri gucu: %.lf\n",o_savas_ani.troller_savas.toplam_saldiri_gucu);
                fprintf(fptr,"Toplam savunma gucu: %.lf\n",o_savas_ani.troller_savas.toplam_savunma_gucu);
                fprintf(fptr,"Toplam saglik: %.lf\n\n",ork.o_unit.troller.saglik);
                fprintf(fptr,"Ork Lejyonu Toplam Saldiri Gucu: %.lf\n",(o_savas_ani.ork_dovuscu_savas.toplam_saldiri_gucu+o_savas_ani.mizrakci_savas.toplam_saldiri_gucu+o_savas_ani.varg_binici_savas.toplam_saldiri_gucu+o_savas_ani.troller_savas.toplam_saldiri_gucu));
                fprintf(fptr,"Ork Lejyonu Toplam Savunma Gucu: %.lf\n\n",(o_savas_ani.ork_dovuscu_savas.toplam_savunma_gucu+o_savas_ani.mizrakci_savas.toplam_savunma_gucu+o_savas_ani.varg_binici_savas.toplam_savunma_gucu+o_savas_ani.troller_savas.toplam_savunma_gucu));
            }

            fclose(fptr);
        }

        if(tur_sayisi == 0)
        {
            if(insan.i_unit.piyadeler.kritik_sans != 0)
            {
                i_savas_ani.piyade_savas.kritik_vurus_tur_sayisi = (1/insan.i_unit.piyadeler.kritik_sans)*100;
            }
            if(insan.i_unit.okcular.kritik_sans != 0)
            {
                i_savas_ani.okcu_savas.kritik_vurus_tur_sayisi = (1/insan.i_unit.okcular.kritik_sans)*100;
            }
            if(insan.i_unit.suvariler.kritik_sans != 0)
            {
                i_savas_ani.suvari_savas.kritik_vurus_tur_sayisi = (1/insan.i_unit.suvariler.kritik_sans)*100;
            }
            if(insan.i_unit.kusatma_makineleri.kritik_sans != 0)
            {
                i_savas_ani.kusatma_makineleri_savas.kritik_vurus_tur_sayisi = (1/insan.i_unit.kusatma_makineleri.kritik_sans)*100;
            }
            if(ork.o_unit.ork_dovusculeri.kritik_sans != 0)
            {
                o_savas_ani.ork_dovuscu_savas.kritik_vurus_tur_sayisi = (1/ork.o_unit.ork_dovusculeri.kritik_sans)*100;
            }
            if(ork.o_unit.mizrakcilar.kritik_sans != 0)
            {
                o_savas_ani.mizrakci_savas.kritik_vurus_tur_sayisi = (1/ork.o_unit.mizrakcilar.kritik_sans)*100;
            }
            if(ork.o_unit.varg_binicileri.kritik_sans != 0)
            {
                o_savas_ani.varg_binici_savas.kritik_vurus_tur_sayisi = (1/ork.o_unit.varg_binicileri.kritik_sans)*100;
            }
            if(ork.o_unit.troller.kritik_sans != 0)
            {
                o_savas_ani.troller_savas.kritik_vurus_tur_sayisi = (1/ork.o_unit.troller.kritik_sans)*100;
            }

            fptr = fopen("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\savas_sim.txt","w");
            if(fptr == NULL)
            {
                printf("Dosya '230202050_230202058/savas_sim.txt' bulunamadi. Lütfen dosyanin dogru isimde ve dogru dizinde oldugundan emin olun.");
            }

            else
            {
                fprintf(fptr,"Senaryoya Ait Baslangic Bilgileri:\n\n\n");

                fprintf(fptr,"*****INSAN IMPARATORLUGU*****\n\n");
                fprintf(fptr,"-----BIRIMLER-----\n\n");
                fprintf(fptr,"Piyadeler(Saldiri Gucu: %d,Savunma Gucu: %d,Saglik: %.lf,Kritik Vurus Sansi: %.2lf)\n\n",insan.i_unit.piyadeler.saldiri,insan.i_unit.piyadeler.savunma,insan.i_unit.piyadeler.saglik,insan.i_unit.piyadeler.kritik_sans);
                fprintf(fptr,"Toplam sayi: %d\n",insan_sayi.unit_i_sayi.piyade_sayi);
                fprintf(fptr,"Toplam saldiri gucu: %.lf\n",i_savas_ani.piyade_savas.toplam_saldiri_gucu);
                fprintf(fptr,"Toplam savunma gucu: %.lf\n\n",i_savas_ani.piyade_savas.toplam_savunma_gucu);

                fprintf(fptr,"Okcular(Saldiri Gucu: %d,Savunma Gucu: %d,Saglik: %.lf,Kritik Vurus Sansi: %.2lf)\n\n",insan.i_unit.okcular.saldiri,insan.i_unit.okcular.savunma,insan.i_unit.okcular.saglik,insan.i_unit.okcular.kritik_sans);
                fprintf(fptr,"Toplam sayi: %d\n",insan_sayi.unit_i_sayi.okcu_sayi);
                fprintf(fptr,"Toplam saldiri gucu: %.lf\n",i_savas_ani.okcu_savas.toplam_saldiri_gucu);
                fprintf(fptr,"Toplam savunma gucu: %.lf\n\n",i_savas_ani.okcu_savas.toplam_savunma_gucu);

                fprintf(fptr,"Suvariler(Saldiri Gucu: %d,Savunma Gucu: %d,Saglik: %.lf,Kritik Vurus Sansi: %.2lf)\n\n",insan.i_unit.suvariler.saldiri,insan.i_unit.suvariler.savunma,insan.i_unit.suvariler.saglik,insan.i_unit.suvariler.kritik_sans);
                fprintf(fptr,"Toplam sayi: %d\n",insan_sayi.unit_i_sayi.suvari_sayi);
                fprintf(fptr,"Toplam saldiri gucu: %.lf\n",i_savas_ani.suvari_savas.toplam_saldiri_gucu);
                fprintf(fptr,"Toplam savunma gucu: %.lf\n\n",i_savas_ani.suvari_savas.toplam_savunma_gucu);

                fprintf(fptr,"Kusatma Makineleri(Saldiri Gucu: %d,Savunma Gucu: %d,Saglik: %.lf,Kritik Vurus Sansi: %.2lf)\n\n",insan.i_unit.kusatma_makineleri.saldiri,insan.i_unit.kusatma_makineleri.savunma,insan.i_unit.kusatma_makineleri.saglik,insan.i_unit.kusatma_makineleri.kritik_sans);
                fprintf(fptr,"Toplam sayi: %d\n",insan_sayi.unit_i_sayi.kusatma_makine_sayi);
                fprintf(fptr,"Toplam saldiri gucu: %.lf\n",i_savas_ani.kusatma_makineleri_savas.toplam_saldiri_gucu);
                fprintf(fptr,"Toplam savunma gucu: %.lf\n\n",i_savas_ani.kusatma_makineleri_savas.toplam_savunma_gucu);

                fprintf(fptr,"Insan Imparatorlugunun Toplam Saldiri Gucu: %.lf\n",(i_savas_ani.piyade_savas.toplam_saldiri_gucu+i_savas_ani.okcu_savas.toplam_saldiri_gucu+i_savas_ani.suvari_savas.toplam_saldiri_gucu+i_savas_ani.kusatma_makineleri_savas.toplam_saldiri_gucu));
                fprintf(fptr,"Insan Imparatorlugunun Toplam Savunma Gucu: %.lf\n\n",(i_savas_ani.piyade_savas.toplam_savunma_gucu+i_savas_ani.okcu_savas.toplam_savunma_gucu+i_savas_ani.suvari_savas.toplam_savunma_gucu+i_savas_ani.kusatma_makineleri_savas.toplam_savunma_gucu));
                fprintf(fptr,"-------KAHRAMAN-------\n\n");
                if(insan_sayi.heroes_i_sayi.alparslan_sayi == 1)
                {
                    fprintf(fptr,"Alparslan (%s %%%d %s gucu bonusu saglar)\n\n",insan.i_heroes.alparslan.etkiledigi_birim,insan.i_heroes.alparslan.bonus_degeri,insan.i_heroes.alparslan.bonus_turu);
                }
                if(insan_sayi.heroes_i_sayi.fatih_sultan_mehmet_sayi == 1)
                {
                    fprintf(fptr,"Fatih Sultan Mehmet (%s %%%d %s gucu bonusu saglar)\n\n",insan.i_heroes.fatih_Sultan_Mehmet.etkiledigi_birim,insan.i_heroes.fatih_Sultan_Mehmet.bonus_degeri,insan.i_heroes.fatih_Sultan_Mehmet.bonus_turu);
                }
                if(insan_sayi.heroes_i_sayi.mete_han_sayi == 1)
                {
                    fprintf(fptr,"Mete Han (%s %%%d %s gucu bonusu saglar)\n\n",insan.i_heroes.mete_Han.etkiledigi_birim,insan.i_heroes.mete_Han.bonus_degeri,insan.i_heroes.mete_Han.bonus_turu);
                }
                if(insan_sayi.heroes_i_sayi.tugrul_bey_sayi == 1)
                {
                    fprintf(fptr,"Tugrul Bey (%s %%%d %s gucu bonusu saglar)\n\n",insan.i_heroes.tugrul_Bey.etkiledigi_birim,insan.i_heroes.tugrul_Bey.bonus_degeri,insan.i_heroes.tugrul_Bey.bonus_turu);
                }
                if(insan_sayi.heroes_i_sayi.yavuz_sultan_selim_sayi == 1)
                {
                    fprintf(fptr,"Yavuz Sultan Selim (%s %%%d %s gucu bonusu saglar)\n\n",insan.i_heroes.yavuz_Sultan_Selim.etkiledigi_birim,insan.i_heroes.yavuz_Sultan_Selim.bonus_degeri,insan.i_heroes.yavuz_Sultan_Selim.bonus_turu);
                }
                fprintf(fptr,"-------CANAVAR-------\n\n");
                if(insan_sayi.creatures_i_sayi.agri_dagi_devi_sayi == 1)
                {
                    fprintf(fptr,"Agri Dagi Devleri (%s %%%d %s gucu bonusu saglar)\n\n",insan.i_creatures.agri_Dagi_Devleri.etkiledigi_birim,insan.i_creatures.agri_Dagi_Devleri.bonus_degeri,insan.i_creatures.agri_Dagi_Devleri.bonus_turu);
                }
                if(insan_sayi.creatures_i_sayi.ejderha_sayi == 1)
                {
                    fprintf(fptr,"Ejderha (%s %%%d %s gucu bonusu saglar)\n\n",insan.i_creatures.ejderha.etkiledigi_birim,insan.i_creatures.ejderha.bonus_degeri,insan.i_creatures.ejderha.bonus_turu);
                }
                if(insan_sayi.creatures_i_sayi.karakurt_sayi == 1)
                {
                    fprintf(fptr,"Karakurt (%s %%%d %s gucu bonusu saglar)\n\n",insan.i_creatures.karakurt.etkiledigi_birim,insan.i_creatures.karakurt.bonus_degeri,insan.i_creatures.karakurt.bonus_turu);
                }
                if(insan_sayi.creatures_i_sayi.samur_sayi == 1)
                {
                    fprintf(fptr,"Samur (%s %%%d %s gucu bonusu saglar)\n\n",insan.i_creatures.samur.etkiledigi_birim,insan.i_creatures.samur.bonus_degeri,insan.i_creatures.samur.bonus_turu);
                }
                if(insan_sayi.creatures_i_sayi.tepegoz_sayi == 1)
                {
                    fprintf(fptr,"Tepegoz (%s %%%d %s gucu bonusu saglar)\n\n",insan.i_creatures.tepegoz.etkiledigi_birim,insan.i_creatures.tepegoz.bonus_degeri,insan.i_creatures.tepegoz.bonus_turu);
                }
                fprintf(fptr,"-------ARASTIRMA-------\n\n");
                if(insan_sayi.research_i_sayi.savunma_ustaligi_sayi == 1)
                {
                    fprintf(fptr,"Savunma Ustaligi (Seviye %d): %s %s %% %d artirir.\n\n",insan_sayi.research_i_sayi.savunma_ustaligi_sayi,research.savunma_ustaligi.level1.etkiledigi_birim,research.savunma_ustaligi.level1.etki_turu,research.savunma_ustaligi.level1.deger);
                }
                if(insan_sayi.research_i_sayi.savunma_ustaligi_sayi == 2)
                {
                    fprintf(fptr,"Savunma Ustaligi (Seviye %d): %s %s %% %d artirir.\n\n",insan_sayi.research_i_sayi.savunma_ustaligi_sayi,research.savunma_ustaligi.level2.etkiledigi_birim,research.savunma_ustaligi.level2.etki_turu,research.savunma_ustaligi.level2.deger);
                }
                if(insan_sayi.research_i_sayi.savunma_ustaligi_sayi == 3)
                {
                    fprintf(fptr,"Savunma Ustaligi (Seviye %d): %s %s %% %d artirir.\n\n",insan_sayi.research_i_sayi.savunma_ustaligi_sayi,research.savunma_ustaligi.level3.etkiledigi_birim,research.savunma_ustaligi.level3.etki_turu,research.savunma_ustaligi.level3.deger);
                }
                if(insan_sayi.research_i_sayi.saldiri_gelistirmesi_sayi == 1)
                {
                    fprintf(fptr,"Saldiri Gelistirmesi (Seviye %d): %s %s %% %d artirir.\n\n",insan_sayi.research_i_sayi.saldiri_gelistirmesi_sayi,research.saldiri_gelistirmesi.level1.etkiledigi_birim,research.saldiri_gelistirmesi.level1.etki_turu,research.saldiri_gelistirmesi.level1.deger);
                }
                if(insan_sayi.research_i_sayi.saldiri_gelistirmesi_sayi == 2)
                {
                    fprintf(fptr,"Saldiri Gelistirmesi (Seviye %d): %s %s %% %d artirir.\n\n",insan_sayi.research_i_sayi.saldiri_gelistirmesi_sayi,research.saldiri_gelistirmesi.level2.etkiledigi_birim,research.saldiri_gelistirmesi.level2.etki_turu,research.saldiri_gelistirmesi.level2.deger);
                }
                if(insan_sayi.research_i_sayi.saldiri_gelistirmesi_sayi == 3)
                {
                    fprintf(fptr,"Saldiri Gelistirmesi (Seviye %d): %s %s %% %d artirir.\n\n",insan_sayi.research_i_sayi.saldiri_gelistirmesi_sayi,research.saldiri_gelistirmesi.level3.etkiledigi_birim,research.saldiri_gelistirmesi.level3.etki_turu,research.saldiri_gelistirmesi.level3.deger);
                }
                if(insan_sayi.research_i_sayi.elit_egitim_sayi == 1)
                {
                    fprintf(fptr,"Elit Egitim (Seviye %d): %s %s %% %d artirir.\n\n",insan_sayi.research_i_sayi.elit_egitim_sayi,research.elit_egitim.level1.etkiledigi_birim,research.elit_egitim.level1.etki_turu,research.elit_egitim.level1.deger);
                }
                if(insan_sayi.research_i_sayi.elit_egitim_sayi == 2)
                {
                    fprintf(fptr,"Elit Egitim (Seviye %d): %s %s %% %d artirir.\n\n",insan_sayi.research_i_sayi.elit_egitim_sayi,research.elit_egitim.level2.etkiledigi_birim,research.elit_egitim.level2.etki_turu,research.elit_egitim.level2.deger);
                }
                if(insan_sayi.research_i_sayi.elit_egitim_sayi == 3)
                {
                    fprintf(fptr,"Elit Egitim (Seviye %d): %s %s %% %d artirir.\n\n",insan_sayi.research_i_sayi.elit_egitim_sayi,research.elit_egitim.level3.etkiledigi_birim,research.elit_egitim.level3.etki_turu,research.elit_egitim.level3.deger);
                }
                if(insan_sayi.research_i_sayi.kusatma_ustaligi_sayi == 1)
                {
                    fprintf(fptr,"Kusatma Ustaligi (Seviye %d): %s %s %% %d artirir.\n\n",insan_sayi.research_i_sayi.kusatma_ustaligi_sayi,research.kusatma_ustaligi.level1.etkiledigi_birim,research.kusatma_ustaligi.level1.etki_turu,research.kusatma_ustaligi.level1.deger);
                }
                if(insan_sayi.research_i_sayi.kusatma_ustaligi_sayi == 2)
                {
                    fprintf(fptr,"Kusatma Ustaligi (Seviye %d): %s %s %% %d artirir.\n\n",insan_sayi.research_i_sayi.kusatma_ustaligi_sayi,research.kusatma_ustaligi.level2.etkiledigi_birim,research.kusatma_ustaligi.level2.etki_turu,research.kusatma_ustaligi.level2.deger);
                }
                if(insan_sayi.research_i_sayi.kusatma_ustaligi_sayi == 3)
                {
                    fprintf(fptr,"Kusatma Ustaligi (Seviye %d): %s %s %% %d artirir.\n\n",insan_sayi.research_i_sayi.kusatma_ustaligi_sayi,research.kusatma_ustaligi.level3.etkiledigi_birim,research.kusatma_ustaligi.level3.etki_turu,research.kusatma_ustaligi.level3.deger);
                }
                fprintf(fptr,"*****ORK LEJYONU*****\n\n");
                fprintf(fptr,"-----BIRIMLER-----\n\n");
                fprintf(fptr,"Ork Dovusculeri(Saldiri Gucu: %d,Savunma Gucu: %d,Saglik: %.lf,Kritik Vurus Sansi: %.2lf)\n\n",ork.o_unit.ork_dovusculeri.saldiri,ork.o_unit.ork_dovusculeri.savunma,ork.o_unit.ork_dovusculeri.saglik,ork.o_unit.ork_dovusculeri.kritik_sans);
                fprintf(fptr,"Toplam sayi: %d\n",ork_sayi.unit_o_sayi.ork_dovuscu_sayi);
                fprintf(fptr,"Toplam saldiri gucu: %.lf\n",o_savas_ani.ork_dovuscu_savas.toplam_saldiri_gucu);
                fprintf(fptr,"Toplam savunma gucu: %.lf\n\n",o_savas_ani.ork_dovuscu_savas.toplam_savunma_gucu);

                fprintf(fptr,"Mizrakcilar\(Saldiri Gucu: %d,Savunma Gucu: %d,Saglik: %.lf,Kritik Vurus Sansi: %.2lf)\n\n",ork.o_unit.mizrakcilar.saldiri,ork.o_unit.mizrakcilar.savunma,ork.o_unit.mizrakcilar.saglik,ork.o_unit.mizrakcilar.kritik_sans);
                fprintf(fptr,"Toplam sayi: %d\n",ork_sayi.unit_o_sayi.mizrakci_sayi);
                fprintf(fptr,"Toplam saldiri gucu: %.lf\n",o_savas_ani.mizrakci_savas.toplam_saldiri_gucu);
                fprintf(fptr,"Toplam savunma gucu: %.lf\n\n",o_savas_ani.mizrakci_savas.toplam_savunma_gucu);

                fprintf(fptr,"Varg binicileri(Saldiri Gucu: %d,Savunma Gucu: %d,Saglik: %.lf,Kritik Vurus Sansi: %.2lf)\n\n",ork.o_unit.varg_binicileri.saldiri,ork.o_unit.varg_binicileri.savunma,ork.o_unit.varg_binicileri.saglik,ork.o_unit.varg_binicileri.kritik_sans);
                fprintf(fptr,"Toplam sayi: %d\n",ork_sayi.unit_o_sayi.varg_binici_sayi);
                fprintf(fptr,"Toplam saldiri gucu: %.lf\n",o_savas_ani.varg_binici_savas.toplam_saldiri_gucu);
                fprintf(fptr,"Toplam savunma gucu: %.lf\n\n",o_savas_ani.varg_binici_savas.toplam_savunma_gucu);

                fprintf(fptr,"Troller(Saldiri Gucu: %d,Savunma Gucu: %d,Saglik: %.lf,Kritik Vurus Sansi: %.2lf)\n\n",ork.o_unit.troller.saldiri,ork.o_unit.troller.savunma,ork.o_unit.troller.saglik,ork.o_unit.troller.kritik_sans);
                fprintf(fptr,"Toplam sayi: %d\n",ork_sayi.unit_o_sayi.troller_sayi);
                fprintf(fptr,"Toplam saldiri gucu: %.lf\n",o_savas_ani.troller_savas.toplam_saldiri_gucu);
                fprintf(fptr,"Toplam savunma gucu: %.lf\n\n",o_savas_ani.troller_savas.toplam_savunma_gucu);

                fprintf(fptr,"Ork Lejyonu Toplam Saldiri Gucu: %.lf\n",(o_savas_ani.ork_dovuscu_savas.toplam_saldiri_gucu+o_savas_ani.mizrakci_savas.toplam_saldiri_gucu+o_savas_ani.varg_binici_savas.toplam_saldiri_gucu+o_savas_ani.troller_savas.toplam_saldiri_gucu));
                fprintf(fptr,"Ork Lejyonu Toplam Savunma Gucu: %.lf\n\n",(o_savas_ani.ork_dovuscu_savas.toplam_savunma_gucu+o_savas_ani.mizrakci_savas.toplam_savunma_gucu+o_savas_ani.varg_binici_savas.toplam_savunma_gucu+o_savas_ani.troller_savas.toplam_savunma_gucu));
                fprintf(fptr,"-------KAHRAMAN-------\n\n");
                if(ork_sayi.heroes_o_sayi.goruk_vahsi_sayi == 1)
                {
                    fprintf(fptr,"Goruk Vahsi (%s %%%d %s gucu bonusu saglar)\n\n",ork.o_heroes.goruk_Vahsi.etkiledigi_birim,ork.o_heroes.goruk_Vahsi.bonus_degeri,ork.o_heroes.goruk_Vahsi.bonus_turu);
                }
                if(ork_sayi.heroes_o_sayi.thruk_kemikkiran_sayi == 1)
                {
                    fprintf(fptr,"Thruk Kemikkiran (%s %%%d %s gucu bonusu saglar)\n\n",ork.o_heroes.thruk_Kemikkiran.etkiledigi_birim,ork.o_heroes.thruk_Kemikkiran.bonus_degeri,ork.o_heroes.thruk_Kemikkiran.bonus_turu);
                }
                if(ork_sayi.heroes_o_sayi.ugar_zalim_sayi == 1)
                {
                    fprintf(fptr,"Ugar Zalim (%s %%%d %s gucu bonusu saglar)\n\n",ork.o_heroes.ugar_Zalim.etkiledigi_birim,ork.o_heroes.ugar_Zalim.bonus_degeri,ork.o_heroes.ugar_Zalim.bonus_turu);
                }
                if(ork_sayi.heroes_o_sayi.vrog_kafakiran_sayi == 1)
                {
                    fprintf(fptr,"Vrog Kafakiran (%s %%%d %s gucu bonusu saglar)\n\n",ork.o_heroes.vrog_Kafakiran.etkiledigi_birim,ork.o_heroes.vrog_Kafakiran.bonus_degeri,ork.o_heroes.vrog_Kafakiran.bonus_turu);
                }
                fprintf(fptr,"-------CANAVAR-------\n\n");
                if(ork_sayi.creatures_o_sayi.ates_iblisi_sayi == 1)
                {
                    fprintf(fptr,"Ates Iblisi (%s %%%d %s gucu bonusu saglar)\n\n",ork.o_creatures.ates_Iblisi.etkiledigi_birim,ork.o_creatures.ates_Iblisi.bonus_degeri,ork.o_creatures.ates_Iblisi.bonus_turu);
                }
                if(ork_sayi.creatures_o_sayi.buz_devleri_sayi == 1)
                {
                    fprintf(fptr,"Buz Devleri (%s %%%d %s gucu bonusu saglar)\n\n",ork.o_creatures.buz_Devleri.etkiledigi_birim,ork.o_creatures.buz_Devleri.bonus_degeri,ork.o_creatures.buz_Devleri.bonus_turu);
                }
                if(ork_sayi.creatures_o_sayi.camur_devleri_sayi == 1)
                {
                    fprintf(fptr,"Camur Devleri (%s %%%d %s gucu bonusu saglar)\n\n",ork.o_creatures.camur_Devleri.etkiledigi_birim,ork.o_creatures.camur_Devleri.bonus_degeri,ork.o_creatures.camur_Devleri.bonus_turu);
                }
                if(ork_sayi.creatures_o_sayi.golge_kurtlari_sayi == 1)
                {
                    fprintf(fptr,"Golge Kurtlari (%s %%%d %s gucu bonusu saglar)\n\n",ork.o_creatures.golge_Kurtlari.etkiledigi_birim,ork.o_creatures.golge_Kurtlari.bonus_degeri,ork.o_creatures.golge_Kurtlari.bonus_turu);
                }
                if(ork_sayi.creatures_o_sayi.kara_trol_sayi == 1)
                {
                    fprintf(fptr,"Kara Trol (%s %%%d %s gucu bonusu saglar)\n\n",ork.o_creatures.kara_Troll.etkiledigi_birim,ork.o_creatures.kara_Troll.bonus_degeri,ork.o_creatures.kara_Troll.bonus_turu);
                }
                if(ork_sayi.creatures_o_sayi.makrog_savas_beyi_sayi == 1)
                {
                    fprintf(fptr,"Makrog Savas Beyi (%s %%%d %s gucu bonusu saglar)\n\n",ork.o_creatures.makrog_Savas_Beyi.etkiledigi_birim,ork.o_creatures.makrog_Savas_Beyi.bonus_degeri,ork.o_creatures.makrog_Savas_Beyi.bonus_turu);
                }
                fprintf(fptr,"-------ARASTIRMA-------\n\n");
                if(ork_sayi.research_o_sayi.savunma_ustaligi_sayi == 1)
                {
                    fprintf(fptr,"Savunma Ustaligi (Seviye %d): %s %s %% %d artirir.\n\n",ork_sayi.research_o_sayi.savunma_ustaligi_sayi,research.savunma_ustaligi.level1.etkiledigi_birim,research.savunma_ustaligi.level1.etki_turu,research.savunma_ustaligi.level1.deger);
                }
                if(ork_sayi.research_o_sayi.savunma_ustaligi_sayi == 2)
                {
                    fprintf(fptr,"Savunma Ustaligi (Seviye %d): %s %s %% %d artirir.\n\n",ork_sayi.research_o_sayi.savunma_ustaligi_sayi,research.savunma_ustaligi.level2.etkiledigi_birim,research.savunma_ustaligi.level2.etki_turu,research.savunma_ustaligi.level2.deger);
                }
                if(ork_sayi.research_o_sayi.savunma_ustaligi_sayi == 3)
                {
                    fprintf(fptr,"Savunma Ustaligi (Seviye %d): %s %s %% %d artirir.\n\n",ork_sayi.research_o_sayi.savunma_ustaligi_sayi,research.savunma_ustaligi.level3.etkiledigi_birim,research.savunma_ustaligi.level3.etki_turu,research.savunma_ustaligi.level3.deger);
                }
                if(ork_sayi.research_o_sayi.saldiri_gelistirmesi_sayi == 1)
                {
                    fprintf(fptr,"Saldiri Gelistirmesi (Seviye %d): %s %s %% %d artirir.\n\n",ork_sayi.research_o_sayi.saldiri_gelistirmesi_sayi,research.saldiri_gelistirmesi.level1.etkiledigi_birim,research.saldiri_gelistirmesi.level1.etki_turu,research.saldiri_gelistirmesi.level1.deger);
                }
                if(ork_sayi.research_o_sayi.saldiri_gelistirmesi_sayi == 2)
                {
                    fprintf(fptr,"Saldiri Gelistirmesi (Seviye %d): %s %s %% %d artirir.\n\n",ork_sayi.research_o_sayi.saldiri_gelistirmesi_sayi,research.saldiri_gelistirmesi.level2.etkiledigi_birim,research.saldiri_gelistirmesi.level2.etki_turu,research.saldiri_gelistirmesi.level2.deger);
                }
                if(ork_sayi.research_o_sayi.saldiri_gelistirmesi_sayi == 3)
                {
                    fprintf(fptr,"Saldiri Gelistirmesi (Seviye %d): %s %s %% %d artirir.\n\n",ork_sayi.research_o_sayi.saldiri_gelistirmesi_sayi,research.saldiri_gelistirmesi.level3.etkiledigi_birim,research.saldiri_gelistirmesi.level3.etki_turu,research.saldiri_gelistirmesi.level3.deger);
                }
                if(ork_sayi.research_o_sayi.elit_egitim_sayi == 1)
                {
                    fprintf(fptr,"Elit Egitim (Seviye %d): %s %s %% %d artirir.\n\n",ork_sayi.research_o_sayi.elit_egitim_sayi,research.elit_egitim.level1.etkiledigi_birim,research.elit_egitim.level1.etki_turu,research.elit_egitim.level1.deger);
                }
                if(ork_sayi.research_o_sayi.elit_egitim_sayi == 2)
                {
                    fprintf(fptr,"Elit Egitim (Seviye %d): %s %s %% %d artirir.\n\n",ork_sayi.research_o_sayi.elit_egitim_sayi,research.elit_egitim.level2.etkiledigi_birim,research.elit_egitim.level2.etki_turu,research.elit_egitim.level2.deger);
                }
                if(ork_sayi.research_o_sayi.elit_egitim_sayi == 3)
                {
                    fprintf(fptr,"Elit Egitim (Seviye %d): %s %s %% %d artirir.\n\n",ork_sayi.research_o_sayi.elit_egitim_sayi,research.elit_egitim.level3.etkiledigi_birim,research.elit_egitim.level3.etki_turu,research.elit_egitim.level3.deger);
                }
                if(ork_sayi.research_o_sayi.kusatma_ustaligi_sayi == 1)
                {
                    fprintf(fptr,"Kusatma Ustaligi (Seviye %d): %s %s %% %d artirir.\n\n",ork_sayi.research_o_sayi.kusatma_ustaligi_sayi,research.kusatma_ustaligi.level1.etkiledigi_birim,research.kusatma_ustaligi.level1.etki_turu,research.kusatma_ustaligi.level1.deger);
                }
                if(ork_sayi.research_o_sayi.kusatma_ustaligi_sayi == 2)
                {
                    fprintf(fptr,"Kusatma Ustaligi (Seviye %d): %s %s %% %d artirir.\n\n",ork_sayi.research_o_sayi.kusatma_ustaligi_sayi,research.kusatma_ustaligi.level2.etkiledigi_birim,research.kusatma_ustaligi.level2.etki_turu,research.kusatma_ustaligi.level2.deger);
                }
                if(ork_sayi.research_o_sayi.kusatma_ustaligi_sayi == 3)
                {
                    fprintf(fptr,"Kusatma Ustaligi (Seviye %d): %s %s %% %d artirir.\n\n",ork_sayi.research_o_sayi.kusatma_ustaligi_sayi,research.kusatma_ustaligi.level3.etkiledigi_birim,research.kusatma_ustaligi.level3.etki_turu,research.kusatma_ustaligi.level3.deger);
                }
            }
            fclose(fptr);
            ork_dovuscu_saglik_puani = ork.o_unit.ork_dovusculeri.saglik;
            mizrakci_saglik_puani = ork.o_unit.mizrakcilar.saglik;
            varg_binici_saglik_puani = ork.o_unit.varg_binicileri.saglik;
            trol_saglik_puani = ork.o_unit.troller.saglik;

            piyade_saglik_puani = insan.i_unit.piyadeler.saglik;
            okcu_saglik_puani = insan.i_unit.okcular.saglik;
            suvari_saglik_puani = insan.i_unit.suvariler.saglik;
            kusatma_makine_saglik_puani = insan.i_unit.kusatma_makineleri.saglik;

            if(insan_sayi.unit_i_sayi.piyade_sayi<=0 )
            {
                insan.i_unit.piyadeler.saglik=0;
            }
            if(insan_sayi.unit_i_sayi.okcu_sayi<=0 )
            {
                insan.i_unit.okcular.saglik=0;
            }
            if(insan_sayi.unit_i_sayi.suvari_sayi<=0 )
            {
                insan.i_unit.suvariler.saglik=0;
            }
            if(insan_sayi.unit_i_sayi.kusatma_makine_sayi<=0 )
            {
                insan.i_unit.kusatma_makineleri.saglik=0;
            }
            if(ork_sayi.unit_o_sayi.ork_dovuscu_sayi<=0)
            {
                ork.o_unit.ork_dovusculeri.saglik=0;
            }
            if(ork_sayi.unit_o_sayi.mizrakci_sayi<=0)
            {
                ork.o_unit.mizrakcilar.saglik=0;
            }
            if(ork_sayi.unit_o_sayi.varg_binici_sayi<=0)
            {
                ork.o_unit.varg_binicileri.saglik=0;
            }
            if(ork_sayi.unit_o_sayi.troller_sayi<=0)
            {
                ork.o_unit.troller.saglik=0;
            }
        }

        if(insan.i_unit.piyadeler.kritik_sans != 0 && tur_sayisi % i_savas_ani.piyade_savas.kritik_vurus_tur_sayisi == 0 && tur_sayisi != 0 )
        {
            i_savas_ani.piyade_savas.toplam_saldiri_gucu *=  1.5;
        }
        if(insan.i_unit.okcular.kritik_sans != 0 && tur_sayisi % i_savas_ani.okcu_savas.kritik_vurus_tur_sayisi == 0 && tur_sayisi != 0  )
        {
            i_savas_ani.okcu_savas.toplam_saldiri_gucu *=  1.5;
        }
        if(insan.i_unit.suvariler.kritik_sans != 0 && tur_sayisi % i_savas_ani.suvari_savas.kritik_vurus_tur_sayisi == 0 && tur_sayisi != 0 )
        {
            i_savas_ani.suvari_savas.toplam_saldiri_gucu *=  1.5;
        }
        if(insan.i_unit.kusatma_makineleri.kritik_sans != 0 && tur_sayisi % i_savas_ani.kusatma_makineleri_savas.kritik_vurus_tur_sayisi == 0 && tur_sayisi != 0 )
        {
            i_savas_ani.kusatma_makineleri_savas.toplam_saldiri_gucu *=  1.5;
        }
        if(ork.o_unit.ork_dovusculeri.kritik_sans != 0 && tur_sayisi % o_savas_ani.ork_dovuscu_savas.kritik_vurus_tur_sayisi == 0 && tur_sayisi != 0 )
        {
            o_savas_ani.ork_dovuscu_savas.toplam_saldiri_gucu *=  1.5;
        }
        if(ork.o_unit.mizrakcilar.kritik_sans != 0 && tur_sayisi % o_savas_ani.mizrakci_savas.kritik_vurus_tur_sayisi == 0 && tur_sayisi != 0 )
        {
            o_savas_ani.mizrakci_savas.toplam_saldiri_gucu *=  1.5;
        }
        if(ork.o_unit.varg_binicileri.kritik_sans != 0 && tur_sayisi % o_savas_ani.varg_binici_savas.kritik_vurus_tur_sayisi == 0 && tur_sayisi != 0 )
        {
            o_savas_ani.varg_binici_savas.toplam_saldiri_gucu *=  1.5;
        }
        if(ork.o_unit.troller.kritik_sans != 0 && tur_sayisi % o_savas_ani.troller_savas.kritik_vurus_tur_sayisi == 0 && tur_sayisi != 0 )
        {
            o_savas_ani.troller_savas.toplam_saldiri_gucu *=  1.5;
        }

        if(tur_sayisi % 2 == 0)
        {
            i_toplam_saldiri = i_savas_ani.piyade_savas.toplam_saldiri_gucu + i_savas_ani.okcu_savas.toplam_saldiri_gucu + i_savas_ani.suvari_savas.toplam_saldiri_gucu + i_savas_ani.kusatma_makineleri_savas.toplam_saldiri_gucu;
            o_toplam_savunma = o_savas_ani.ork_dovuscu_savas.toplam_savunma_gucu + o_savas_ani.mizrakci_savas.toplam_savunma_gucu + o_savas_ani.varg_binici_savas.toplam_savunma_gucu + o_savas_ani.troller_savas.toplam_savunma_gucu;

            net_hasar = i_toplam_saldiri - o_toplam_savunma;
            if(net_hasar<= 0)
            {
                yazma_kontrol_i=1;
                tur_sayisi++;
                fptr = fopen("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\savas_sim.txt","a");
                if(fptr == NULL)
                {
                    printf("Dosya '230202050_230202058/savas_sim.txt' bulunamadi. Lütfen dosyanin dogru isimde ve dogru dizinde oldugundan emin olun.");
                }
                else
                {
                    fprintf(fptr,"%d. Tur Bilgileri Insan Imparatorlugu Saldirisi\n\n",tur_sayisi);
                    fprintf(fptr,"Ork Savunmasi insan saldirisindan daha fazla oldugundan saldiri gerceklesmedi\n\n");
                }
                fclose(fptr);
                continue;
            }

            o_oranS_ork_dovuscu =  (o_savas_ani.ork_dovuscu_savas.toplam_savunma_gucu / o_toplam_savunma);
            o_oranS_mizrakci= (o_savas_ani.mizrakci_savas.toplam_savunma_gucu / o_toplam_savunma);
            o_oranS_varg_binici = (o_savas_ani.varg_binici_savas.toplam_savunma_gucu / o_toplam_savunma);
            o_oranS_trol = (o_savas_ani.troller_savas.toplam_savunma_gucu / o_toplam_savunma);
            if(ork.o_unit.ork_dovusculeri.saglik>0 && ork_sayi.unit_o_sayi.ork_dovuscu_sayi>0)
            {
                ork.o_unit.ork_dovusculeri.saglik -= round(((o_oranS_ork_dovuscu*net_hasar)/ork_sayi.unit_o_sayi.ork_dovuscu_sayi));
            }
            if(ork.o_unit.mizrakcilar.saglik>0 && ork_sayi.unit_o_sayi.mizrakci_sayi>0)
            {
                ork.o_unit.mizrakcilar.saglik -= round(((o_oranS_mizrakci*net_hasar)/ork_sayi.unit_o_sayi.mizrakci_sayi));
            }
            if(ork.o_unit.varg_binicileri.saglik>0 && ork_sayi.unit_o_sayi.varg_binici_sayi>0)
            {
                ork.o_unit.varg_binicileri.saglik -= round(((o_oranS_varg_binici*net_hasar)/ork_sayi.unit_o_sayi.varg_binici_sayi));
            }
            if(ork.o_unit.troller.saglik>0 && ork_sayi.unit_o_sayi.troller_sayi>0)
            {
                ork.o_unit.troller.saglik -= round(((o_oranS_trol*net_hasar)/ork_sayi.unit_o_sayi.troller_sayi));
            }

            ork_sayi.unit_o_sayi.ork_dovuscu_sayi -=  round(((o_oranS_ork_dovuscu*net_hasar)/ork_dovuscu_saglik_puani));
            ork_sayi.unit_o_sayi.mizrakci_sayi -=  round(((o_oranS_mizrakci*net_hasar)/mizrakci_saglik_puani));
            ork_sayi.unit_o_sayi.varg_binici_sayi -=  round(((o_oranS_varg_binici*net_hasar)/varg_binici_saglik_puani));
            ork_sayi.unit_o_sayi.troller_sayi -=  round(((o_oranS_trol*net_hasar)/trol_saglik_puani));

            o_savas_ani.ork_dovuscu_savas.toplam_saldiri_gucu = ork_sayi.unit_o_sayi.ork_dovuscu_sayi * ork.o_unit.ork_dovusculeri.saldiri;
            o_savas_ani.mizrakci_savas.toplam_saldiri_gucu = ork_sayi.unit_o_sayi.mizrakci_sayi * ork.o_unit.mizrakcilar.saldiri;
            o_savas_ani.varg_binici_savas.toplam_saldiri_gucu = ork_sayi.unit_o_sayi.varg_binici_sayi * ork.o_unit.varg_binicileri.saldiri;
            o_savas_ani.troller_savas.toplam_saldiri_gucu = ork_sayi.unit_o_sayi.troller_sayi * ork.o_unit.troller.saldiri;

            o_savas_ani.ork_dovuscu_savas.toplam_savunma_gucu = ork_sayi.unit_o_sayi.ork_dovuscu_sayi * ork.o_unit.ork_dovusculeri.savunma;
            o_savas_ani.mizrakci_savas.toplam_savunma_gucu = ork_sayi.unit_o_sayi.mizrakci_sayi * ork.o_unit.mizrakcilar.savunma;
            o_savas_ani.varg_binici_savas.toplam_savunma_gucu = ork_sayi.unit_o_sayi.varg_binici_sayi * ork.o_unit.varg_binicileri.savunma;
            o_savas_ani.troller_savas.toplam_savunma_gucu = ork_sayi.unit_o_sayi.troller_sayi * ork.o_unit.troller.savunma;

            tur_sayisi++;
        }
        else if(tur_sayisi % 2 == 1)
        {
            o_toplam_saldiri = o_savas_ani.ork_dovuscu_savas.toplam_saldiri_gucu + o_savas_ani.mizrakci_savas.toplam_saldiri_gucu + o_savas_ani.varg_binici_savas.toplam_saldiri_gucu + o_savas_ani.troller_savas.toplam_saldiri_gucu;
            i_toplam_savunma = i_savas_ani.piyade_savas.toplam_savunma_gucu + i_savas_ani.okcu_savas.toplam_savunma_gucu + i_savas_ani.suvari_savas.toplam_savunma_gucu + i_savas_ani.kusatma_makineleri_savas.toplam_savunma_gucu;

            net_hasar = o_toplam_saldiri - i_toplam_savunma;

            if(net_hasar<= 0)
            {
                yazma_kontrol_o=1;
                tur_sayisi++;
                fptr = fopen("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\savas_sim.txt","a");
                if(fptr == NULL)
                {
                    printf("Dosya '230202050_230202058/savas_sim.txt' bulunamadi. Lütfen dosyanin dogru isimde ve dogru dizinde oldugundan emin olun.");
                }
                else
                {
                    fprintf(fptr,"%d. Tur Bilgileri Ork Lejyonu Saldirisi\n\n",tur_sayisi);
                    fprintf(fptr,"Insan Savunmasi ork saldirisindan daha fazla oldugundan saldiri gerceklesmedi\n\n");
                }
                fclose(fptr);
                continue;
            }
            i_oranS_piyade =  (i_savas_ani.piyade_savas.toplam_savunma_gucu / i_toplam_savunma);
            i_oranS_okcu= (i_savas_ani.okcu_savas.toplam_savunma_gucu / i_toplam_savunma);
            i_oranS_suvari = (i_savas_ani.suvari_savas.toplam_savunma_gucu / i_toplam_savunma);
            i_oranS_kusatma = (i_savas_ani.kusatma_makineleri_savas.toplam_savunma_gucu / i_toplam_savunma);

            if(insan.i_unit.piyadeler.saglik>0 && insan_sayi.unit_i_sayi.piyade_sayi>0)
            {
                insan.i_unit.piyadeler.saglik -= round(((i_oranS_piyade*net_hasar)/insan_sayi.unit_i_sayi.piyade_sayi));
            }
            if(insan.i_unit.okcular.saglik>0 && insan_sayi.unit_i_sayi.okcu_sayi>0)
            {
                insan.i_unit.okcular.saglik -= round(((i_oranS_okcu*net_hasar)/insan_sayi.unit_i_sayi.okcu_sayi));
            }
            if(insan.i_unit.suvariler.saglik>0 && insan_sayi.unit_i_sayi.suvari_sayi>0)
            {
                insan.i_unit.suvariler.saglik -= round(((i_oranS_suvari*net_hasar)/insan_sayi.unit_i_sayi.suvari_sayi));
            }
            if(insan.i_unit.kusatma_makineleri.saglik>0 && insan_sayi.unit_i_sayi.kusatma_makine_sayi>0)
            {
                insan.i_unit.kusatma_makineleri.saglik -= round(((i_oranS_kusatma*net_hasar)/insan_sayi.unit_i_sayi.kusatma_makine_sayi));
            }

            insan_sayi.unit_i_sayi.piyade_sayi -=  round(((i_oranS_piyade*net_hasar)/piyade_saglik_puani));
            insan_sayi.unit_i_sayi.okcu_sayi -=  round(((i_oranS_okcu*net_hasar)/okcu_saglik_puani));
            insan_sayi.unit_i_sayi.suvari_sayi -=  round(((i_oranS_suvari*net_hasar)/suvari_saglik_puani));
            insan_sayi.unit_i_sayi.kusatma_makine_sayi -=  round(((i_oranS_kusatma*net_hasar)/kusatma_makine_saglik_puani));

            i_savas_ani.piyade_savas.toplam_saldiri_gucu = insan_sayi.unit_i_sayi.piyade_sayi * insan.i_unit.piyadeler.saldiri;
            i_savas_ani.okcu_savas.toplam_saldiri_gucu = insan_sayi.unit_i_sayi.okcu_sayi * insan.i_unit.okcular.saldiri;
            i_savas_ani.suvari_savas.toplam_saldiri_gucu = insan_sayi.unit_i_sayi.suvari_sayi * insan.i_unit.suvariler.saldiri;
            i_savas_ani.kusatma_makineleri_savas.toplam_saldiri_gucu = insan_sayi.unit_i_sayi.kusatma_makine_sayi * insan.i_unit.kusatma_makineleri.saldiri;

            i_savas_ani.piyade_savas.toplam_savunma_gucu = insan_sayi.unit_i_sayi.piyade_sayi * insan.i_unit.piyadeler.savunma;
            i_savas_ani.okcu_savas.toplam_savunma_gucu = insan_sayi.unit_i_sayi.okcu_sayi * insan.i_unit.okcular.savunma;
            i_savas_ani.suvari_savas.toplam_savunma_gucu = insan_sayi.unit_i_sayi.suvari_sayi * insan.i_unit.suvariler.savunma;
            i_savas_ani.kusatma_makineleri_savas.toplam_savunma_gucu = insan_sayi.unit_i_sayi.kusatma_makine_sayi * insan.i_unit.kusatma_makineleri.savunma;

            tur_sayisi++;
        }
        if(insan_sayi.unit_i_sayi.piyade_sayi<0)
        {
            insan_sayi.unit_i_sayi.piyade_sayi=0;
            i_savas_ani.piyade_savas.toplam_saldiri_gucu=0;
            i_savas_ani.piyade_savas.toplam_savunma_gucu=0;
        }
        if(insan.i_unit.piyadeler.saglik<0)
        {
            insan.i_unit.piyadeler.saglik=0;
            insan_sayi.unit_i_sayi.piyade_sayi=0;
            i_savas_ani.piyade_savas.toplam_saldiri_gucu=0;
            i_savas_ani.piyade_savas.toplam_savunma_gucu=0;
        }
        if(insan_sayi.unit_i_sayi.okcu_sayi<0)
        {
            insan_sayi.unit_i_sayi.okcu_sayi=0;
            i_savas_ani.okcu_savas.toplam_saldiri_gucu=0;
            i_savas_ani.okcu_savas.toplam_savunma_gucu=0;

        }
        if(insan.i_unit.okcular.saglik<0)
        {
            insan.i_unit.okcular.saglik=0;
            insan_sayi.unit_i_sayi.okcu_sayi=0;
            i_savas_ani.okcu_savas.toplam_saldiri_gucu=0;
            i_savas_ani.okcu_savas.toplam_savunma_gucu=0;
        }
        if(insan_sayi.unit_i_sayi.suvari_sayi<0)
        {
            insan_sayi.unit_i_sayi.suvari_sayi=0;
            i_savas_ani.suvari_savas.toplam_saldiri_gucu=0;
            i_savas_ani.suvari_savas.toplam_savunma_gucu=0;
        }
        if(insan.i_unit.suvariler.saglik<0)
        {
            insan_sayi.unit_i_sayi.suvari_sayi=0;
            insan.i_unit.suvariler.saglik=0;
            i_savas_ani.suvari_savas.toplam_saldiri_gucu=0;
            i_savas_ani.suvari_savas.toplam_savunma_gucu=0;
        }
        if(insan_sayi.unit_i_sayi.kusatma_makine_sayi<0)
        {
            insan_sayi.unit_i_sayi.kusatma_makine_sayi=0;
            i_savas_ani.kusatma_makineleri_savas.toplam_saldiri_gucu=0;
            i_savas_ani.kusatma_makineleri_savas.toplam_savunma_gucu=0;
        }
        if(insan.i_unit.kusatma_makineleri.saglik<0)
        {
            insan.i_unit.kusatma_makineleri.saglik=0;
            insan_sayi.unit_i_sayi.kusatma_makine_sayi=0;
            i_savas_ani.kusatma_makineleri_savas.toplam_saldiri_gucu=0;
            i_savas_ani.kusatma_makineleri_savas.toplam_savunma_gucu=0;
        }
        if(ork_sayi.unit_o_sayi.ork_dovuscu_sayi<0)
        {
            ork_sayi.unit_o_sayi.ork_dovuscu_sayi=0;
            o_savas_ani.ork_dovuscu_savas.toplam_saldiri_gucu=0;
            o_savas_ani.ork_dovuscu_savas.toplam_savunma_gucu=0;
        }
        if(ork.o_unit.ork_dovusculeri.saglik<0)
        {
            ork.o_unit.ork_dovusculeri.saglik=0;
            ork_sayi.unit_o_sayi.ork_dovuscu_sayi=0;
            o_savas_ani.ork_dovuscu_savas.toplam_saldiri_gucu=0;
            o_savas_ani.ork_dovuscu_savas.toplam_savunma_gucu=0;
        }
        if(ork_sayi.unit_o_sayi.mizrakci_sayi<0)
        {
            ork_sayi.unit_o_sayi.mizrakci_sayi=0;
            o_savas_ani.mizrakci_savas.toplam_saldiri_gucu=0;
            o_savas_ani.mizrakci_savas.toplam_savunma_gucu=0;

        }
        if(ork.o_unit.mizrakcilar.saglik<0)
        {
            ork.o_unit.mizrakcilar.saglik=0;
            ork_sayi.unit_o_sayi.mizrakci_sayi=0;
            o_savas_ani.mizrakci_savas.toplam_saldiri_gucu=0;
            o_savas_ani.mizrakci_savas.toplam_savunma_gucu=0;
        }
        if(ork_sayi.unit_o_sayi.troller_sayi<0)
        {
            ork_sayi.unit_o_sayi.troller_sayi=0;
            o_savas_ani.troller_savas.toplam_saldiri_gucu=0;
            o_savas_ani.troller_savas.toplam_savunma_gucu=0;
        }
        if(ork.o_unit.troller.saglik<0)
        {
            ork.o_unit.troller.saglik=0;
            ork_sayi.unit_o_sayi.troller_sayi=0;
            o_savas_ani.troller_savas.toplam_saldiri_gucu=0;
            o_savas_ani.troller_savas.toplam_savunma_gucu=0;
        }
        if(ork_sayi.unit_o_sayi.varg_binici_sayi<0)
        {
            ork_sayi.unit_o_sayi.varg_binici_sayi=0;
            o_savas_ani.varg_binici_savas.toplam_saldiri_gucu=0;
            o_savas_ani.varg_binici_savas.toplam_savunma_gucu=0;
        }
        if(ork.o_unit.varg_binicileri.saglik<0)
        {
            ork.o_unit.varg_binicileri.saglik=0;
            ork_sayi.unit_o_sayi.varg_binici_sayi=0;
            o_savas_ani.varg_binici_savas.toplam_saldiri_gucu=0;
            o_savas_ani.varg_binici_savas.toplam_savunma_gucu=0;
        }
        if(i_savas_ani.piyade_savas.toplam_saldiri_gucu<0)
        {
            i_savas_ani.piyade_savas.toplam_saldiri_gucu=0;
        }
        if(i_savas_ani.piyade_savas.toplam_savunma_gucu<0)
        {
            i_savas_ani.piyade_savas.toplam_savunma_gucu=0;
        }
        if(i_savas_ani.okcu_savas.toplam_saldiri_gucu<0)
        {
            i_savas_ani.okcu_savas.toplam_saldiri_gucu=0;
        }
        if(i_savas_ani.okcu_savas.toplam_savunma_gucu<0)
        {
            i_savas_ani.okcu_savas.toplam_savunma_gucu=0;
        }
        if(i_savas_ani.suvari_savas.toplam_saldiri_gucu<0)
        {
            i_savas_ani.suvari_savas.toplam_saldiri_gucu=0;
        }
        if(i_savas_ani.suvari_savas.toplam_savunma_gucu<0)
        {
            i_savas_ani.suvari_savas.toplam_savunma_gucu=0;
        }
        if(i_savas_ani.kusatma_makineleri_savas.toplam_saldiri_gucu<0)
        {
            i_savas_ani.kusatma_makineleri_savas.toplam_saldiri_gucu=0;
        }
        if(i_savas_ani.kusatma_makineleri_savas.toplam_savunma_gucu<0)
        {
            i_savas_ani.kusatma_makineleri_savas.toplam_savunma_gucu=0;
        }
        if(o_savas_ani.ork_dovuscu_savas.toplam_saldiri_gucu<0)
        {
            o_savas_ani.ork_dovuscu_savas.toplam_saldiri_gucu=0;
        }
        if(o_savas_ani.ork_dovuscu_savas.toplam_savunma_gucu<0)
        {
            o_savas_ani.ork_dovuscu_savas.toplam_savunma_gucu=0;
        }
        if(o_savas_ani.mizrakci_savas.toplam_saldiri_gucu<0)
        {
            o_savas_ani.mizrakci_savas.toplam_saldiri_gucu=0;
        }
        if(o_savas_ani.mizrakci_savas.toplam_savunma_gucu<0)
        {
            o_savas_ani.mizrakci_savas.toplam_savunma_gucu=0;
        }
        if(o_savas_ani.varg_binici_savas.toplam_saldiri_gucu<0)
        {
            o_savas_ani.varg_binici_savas.toplam_saldiri_gucu=0;
        }
        if(o_savas_ani.varg_binici_savas.toplam_savunma_gucu<0)
        {
            o_savas_ani.varg_binici_savas.toplam_savunma_gucu=0;
        }
        if(o_savas_ani.troller_savas.toplam_saldiri_gucu<0)
        {
            o_savas_ani.troller_savas.toplam_saldiri_gucu=0;
        }
        if(o_savas_ani.troller_savas.toplam_savunma_gucu<0)
        {
            o_savas_ani.troller_savas.toplam_savunma_gucu=0;
        }
        if((insan_sayi.unit_i_sayi.piyade_sayi <= 0 && insan_sayi.unit_i_sayi.okcu_sayi <= 0 && insan_sayi.unit_i_sayi.suvari_sayi <= 0 && insan_sayi.unit_i_sayi.kusatma_makine_sayi <= 0) || (ork_sayi.unit_o_sayi.ork_dovuscu_sayi <=0 && ork_sayi.unit_o_sayi.mizrakci_sayi <= 0 && ork_sayi.unit_o_sayi.varg_binici_sayi <= 0 && ork_sayi.unit_o_sayi.troller_sayi <= 0))
        {
            fptr = fopen("C:\\Users\\yusuf\\OneDrive\\Masaüstü\\230202050_230202058\\savas_sim.txt","a");
            if(fptr == NULL)
            {
                printf("Dosya '230202050_230202058/savas_sim.txt' bulunamadi. Lütfen dosyanin dogru isimde ve dogru dizinde oldugundan emin olun.");
            }
            else
            {
                if(insan_sayi.unit_i_sayi.piyade_sayi==0 && insan_sayi.unit_i_sayi.okcu_sayi == 0 && insan_sayi.unit_i_sayi.suvari_sayi == 0 && insan_sayi.unit_i_sayi.kusatma_makine_sayi == 0)
                {
                   fprintf(fptr,"\n\n%d. Adim Bilgileri Ork Lejyonu Saldirisi ---SAVAS SONU BILGILERI----\n\n",tur_sayisi);
                }
                if(ork_sayi.unit_o_sayi.ork_dovuscu_sayi == 0 && ork_sayi.unit_o_sayi.mizrakci_sayi == 0 && ork_sayi.unit_o_sayi.varg_binici_sayi == 0 && ork_sayi.unit_o_sayi.troller_sayi == 0)
                {
                   fprintf(fptr,"\n\n%d. Adim Bilgileri Insan Imparatorlugu Saldirisi ---SAVAS SONU BILGILERI----\n\n",tur_sayisi);
                }
                fprintf(fptr,"*****INSAN IMPARATORLUGU*****\n\n");
                fprintf(fptr,"-----BIRIMLER-----\n\n");
                fprintf(fptr,"Piyadeler\n\n");
                fprintf(fptr,"Toplam sayi: %d\n",insan_sayi.unit_i_sayi.piyade_sayi);
                fprintf(fptr,"Toplam saldiri gucu: %.lf\n",i_savas_ani.piyade_savas.toplam_saldiri_gucu);
                fprintf(fptr,"Toplam savunma gucu: %.lf\n",i_savas_ani.piyade_savas.toplam_savunma_gucu);
                fprintf(fptr,"Toplam saglik: %.lf\n\n",insan.i_unit.piyadeler.saglik);

                fprintf(fptr,"Okcular\n\n");
                fprintf(fptr,"Toplam sayi: %d\n",insan_sayi.unit_i_sayi.okcu_sayi);
                fprintf(fptr,"Toplam saldiri gucu: %.lf\n",i_savas_ani.okcu_savas.toplam_saldiri_gucu);
                fprintf(fptr,"Toplam savunma gucu: %.lf\n",i_savas_ani.okcu_savas.toplam_savunma_gucu);
                fprintf(fptr,"Toplam saglik: %.lf\n\n",insan.i_unit.okcular.saglik);

                fprintf(fptr,"Suvariler\n\n");
                fprintf(fptr,"Toplam sayi: %d\n",insan_sayi.unit_i_sayi.suvari_sayi);
                fprintf(fptr,"Toplam saldiri gucu: %.lf\n",i_savas_ani.suvari_savas.toplam_saldiri_gucu);
                fprintf(fptr,"Toplam savunma gucu: %.lf\n",i_savas_ani.suvari_savas.toplam_savunma_gucu);
                fprintf(fptr,"Toplam saglik: %.lf\n\n",insan.i_unit.suvariler.saglik);

                fprintf(fptr,"Kusatma Makineleri\n\n");
                fprintf(fptr,"Toplam sayi: %d\n",insan_sayi.unit_i_sayi.kusatma_makine_sayi);
                fprintf(fptr,"Toplam saldiri gucu: %.lf\n",i_savas_ani.kusatma_makineleri_savas.toplam_saldiri_gucu);
                fprintf(fptr,"Toplam savunma gucu: %.lf\n",i_savas_ani.kusatma_makineleri_savas.toplam_savunma_gucu);
                fprintf(fptr,"Toplam saglik: %.lf\n\n",insan.i_unit.kusatma_makineleri.saglik);
                fprintf(fptr,"Insan Imparatorlugunun Toplam Saldiri Gucu: %.lf\n",(i_savas_ani.piyade_savas.toplam_saldiri_gucu+i_savas_ani.okcu_savas.toplam_saldiri_gucu+i_savas_ani.suvari_savas.toplam_saldiri_gucu+i_savas_ani.kusatma_makineleri_savas.toplam_saldiri_gucu));
                fprintf(fptr,"Insan Imparatorlugunun Toplam Savunma Gucu: %.lf\n\n",(i_savas_ani.piyade_savas.toplam_savunma_gucu+i_savas_ani.okcu_savas.toplam_savunma_gucu+i_savas_ani.suvari_savas.toplam_savunma_gucu+i_savas_ani.kusatma_makineleri_savas.toplam_savunma_gucu));

                fprintf(fptr,"*****ORK LEJYONU*****\n\n");
                fprintf(fptr,"-----BIRIMLER-----\n\n");
                fprintf(fptr,"Ork Dovusculeri\n\n");
                fprintf(fptr,"Toplam sayi: %d\n",ork_sayi.unit_o_sayi.ork_dovuscu_sayi);
                fprintf(fptr,"Toplam saldiri gucu: %.lf\n",o_savas_ani.ork_dovuscu_savas.toplam_saldiri_gucu);
                fprintf(fptr,"Toplam savunma gucu: %.lf\n",o_savas_ani.ork_dovuscu_savas.toplam_savunma_gucu);
                fprintf(fptr,"Toplam saglik: %.lf\n\n",ork.o_unit.ork_dovusculeri.saglik);

                fprintf(fptr,"Mizrakcilar\n\n");
                fprintf(fptr,"Toplam sayi: %d\n",ork_sayi.unit_o_sayi.mizrakci_sayi);
                fprintf(fptr,"Toplam saldiri gucu: %.lf\n",o_savas_ani.mizrakci_savas.toplam_saldiri_gucu);
                fprintf(fptr,"Toplam savunma gucu: %.lf\n",o_savas_ani.mizrakci_savas.toplam_savunma_gucu);
                fprintf(fptr,"Toplam saglik: %.lf\n\n",ork.o_unit.mizrakcilar.saglik);

                fprintf(fptr,"Varg binicileri\n\n");
                fprintf(fptr,"Toplam sayi: %d\n",ork_sayi.unit_o_sayi.varg_binici_sayi);
                fprintf(fptr,"Toplam saldiri gucu: %.lf\n",o_savas_ani.varg_binici_savas.toplam_saldiri_gucu);
                fprintf(fptr,"Toplam savunma gucu: %.lf\n",o_savas_ani.varg_binici_savas.toplam_savunma_gucu);
                fprintf(fptr,"Toplam saglik: %.lf\n\n",ork.o_unit.varg_binicileri.saglik);

                fprintf(fptr,"Troller\n\n");
                fprintf(fptr,"Toplam sayi: %d\n",ork_sayi.unit_o_sayi.troller_sayi);
                fprintf(fptr,"Toplam saldiri gucu: %.lf\n",o_savas_ani.troller_savas.toplam_saldiri_gucu);
                fprintf(fptr,"Toplam savunma gucu: %.lf\n",o_savas_ani.troller_savas.toplam_savunma_gucu);
                fprintf(fptr,"Toplam saglik: %.lf\n\n",ork.o_unit.troller.saglik);
                fprintf(fptr,"Ork Lejyonu Toplam Saldiri Gucu: %.lf\n",(o_savas_ani.ork_dovuscu_savas.toplam_saldiri_gucu+o_savas_ani.mizrakci_savas.toplam_saldiri_gucu+o_savas_ani.varg_binici_savas.toplam_saldiri_gucu+o_savas_ani.troller_savas.toplam_saldiri_gucu));
                fprintf(fptr,"Ork Lejyonu Toplam Savunma Gucu: %.lf\n\n",(o_savas_ani.ork_dovuscu_savas.toplam_savunma_gucu+o_savas_ani.mizrakci_savas.toplam_savunma_gucu+o_savas_ani.varg_binici_savas.toplam_savunma_gucu+o_savas_ani.troller_savas.toplam_savunma_gucu));
                if(insan_sayi.unit_i_sayi.piyade_sayi==0 && insan_sayi.unit_i_sayi.okcu_sayi == 0 && insan_sayi.unit_i_sayi.suvari_sayi == 0 && insan_sayi.unit_i_sayi.kusatma_makine_sayi == 0)
                {
                    fprintf(fptr,"----------------------------------------ORK LEJYONU Savasi Kazandi----------------------------------------\n");
                }
                if(ork_sayi.unit_o_sayi.ork_dovuscu_sayi == 0 && ork_sayi.unit_o_sayi.mizrakci_sayi == 0 && ork_sayi.unit_o_sayi.varg_binici_sayi == 0 && ork_sayi.unit_o_sayi.troller_sayi == 0)
                {
                    fprintf(fptr,"----------------------------------------INSAN IMPARATORLUGU Savasi Kazandi----------------------------------------\n");
                }
            }

            fclose(fptr);
        }
    }
    goto bus;

    return 0;
}
