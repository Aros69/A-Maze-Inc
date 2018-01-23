#include <Objet.h>

string Objet::get_Categorie()const{
    return Categorie;
}
Statistiques Objet::get_Stats_Objet()const{
    return Stats_Objet;
}

string Objet::get_Stats_Objet_Nom()const{
    return Stats_Objet.get_Nom();
}
unsigned int Objet::get_Stats_Objet_Point_De_Vie()const{
    return Stats_Objet.get_Point_De_Vie();
}
unsigned int Objet::get_Stats_Objet_Point_De_Vie_Max()const{
    return Stats_Objet.get_Point_De_Vie_Max();
}
unsigned int Objet::get_Stats_Objet_Mana()const{
    return Stats_Objet.get_Mana();
}
unsigned int Objet::get_Stats_Objet_Mana_Max()const{
    return Stats_Objet.get_Mana_Max();
}
unsigned int Objet::get_Stats_Objet_Experience_Restant()const{
    return Stats_Objet.get_Experience_Restant();
}

unsigned int Objet::get_Stats_Objet_Experience_Donne()const{
    return Stats_Objet.get_Experience_Donne();
}
unsigned int Objet::get_Stats_Objet_Niveau()const{
    return Stats_Objet.get_Niveau();
}
unsigned int Objet::get_Stats_Objet_Force()const{
    return Stats_Objet.get_Force();
}


void Objet::set_Categorie(string categorie){
    Categorie=categorie;
}

void Objet::set_Stats_Objet(Statistiques stats_objet){
    Stats_Objet.set_Nom(stats_objet.get_Nom());
    Stats_Objet.set_Point_De_Vie_Max(stats_objet.get_Point_De_Vie_Max());
    Stats_Objet.set_Point_De_Vie(stats_objet.get_Point_De_Vie());
    Stats_Objet.set_Mana_Max(stats_objet.get_Mana_Max());
    Stats_Objet.set_Mana(stats_objet.get_Mana());
    Stats_Objet.set_Experience_Restant(stats_objet.get_Experience_Donne());
    Stats_Objet.set_Experience_Donne(stats_objet.get_Experience_Donne());
    Stats_Objet.set_Niveau(stats_objet.get_Niveau());
    Stats_Objet.set_Force(stats_objet.get_Force());
    Stats_Objet.set_Intelligence(stats_objet.get_Intelligence());
    Stats_Objet.set_Agilite(stats_objet.get_Agilite());
}

void Objet::set_Stats_Objet_Nom(string nom){
    Stats_Objet.set_Nom(nom);
}
void Objet::set_Stats_Objet_Point_De_Vie(unsigned int pv){
    Stats_Objet.set_Point_De_Vie(pv);
}
void Objet::set_Stats_Objet_Point_De_Vie_Max(unsigned int pv_max){
    Stats_Objet.set_Point_De_Vie(pv_max);
}
void Objet::set_Stats_Objet_Mana(unsigned int mana){
    Stats_Objet.set_Mana(mana);
}
void Objet::set_Stats_Objet_Mana_Max(unsigned int pv_max){
    Stats_Objet.set_Mana_Max(pv_max);
}
void Objet::set_Stats_Objet_Experience_Restant(unsigned int xp_restant){
    Stats_Objet.set_Experience_Restant(xp_restant);
}
void Objet::set_Stats_Objet_Experience_Donne(unsigned int xp_donne){
    Stats_Objet.set_Experience_Donne(xp_donne);
}
void Objet::set_Stats_Objet_Niveau(unsigned int niv){
    Stats_Objet.set_Niveau(niv);
}
void Objet::set_Stats_Objet_Force(unsigned int force){
    Stats_Objet.set_Force(force);
}

void Objet::set_Stats_Objet_Intelligence(unsigned int intelligence){
    Stats_Objet.set_Intelligence(intelligence);
}

void Objet::set_Stats_Objet_Agilite(unsigned int agilite){
    Stats_Objet.set_Agilite(agilite);
}



Objet::Objet()
{
    Categorie=" ";
    Stats_Objet.set_Nom(" ");
    Stats_Objet.set_Point_De_Vie_Max(0);
    Stats_Objet.set_Point_De_Vie(0);
    Stats_Objet.set_Mana_Max(0);
    Stats_Objet.set_Mana(0);
    Stats_Objet.set_Experience_Restant(0);
    Stats_Objet.set_Experience_Donne(0);
    Stats_Objet.set_Niveau(0);
    Stats_Objet.set_Force(0);
    Stats_Objet.set_Intelligence(0);
    Stats_Objet.set_Agilite(0);
}
Objet::Objet(string categorie,Statistiques stats_objet)
{
    Categorie=categorie;
    set_Stats_Objet(stats_objet);
}


Objet::~Objet()
{
    //dtor
}
