#include <Statistiques.h>

string Statistiques::get_Nom()const
{
    return Nom;
}
unsigned int const Statistiques::get_Point_De_Vie()const
{
    return Point_De_Vie;
}
unsigned int const Statistiques::get_Point_De_Vie_Max()const
{
    return Point_De_Vie_Max;
}
unsigned int const Statistiques::get_Mana()const
{
    return Mana;
}
unsigned int const Statistiques::get_Mana_Max()const
{
    return Mana_Max;
}
unsigned int const Statistiques::get_Experience_Restant()const
{
    return Experience_Restant;
}
unsigned int const Statistiques::get_Experience_Donne()const
{
    return Experience_Donne;
}
unsigned int const Statistiques::get_Niveau()const
{
    return Niveau;
}
unsigned int const Statistiques::get_Force()const
{
        return Force;
}
unsigned int const Statistiques::get_Intelligence()const
{
    return Intelligence;
}
unsigned int const Statistiques::get_Agilite()const
{
    return Agilite;
}


void Statistiques::set_Nom(string nom){
    Nom=nom;
}
void Statistiques::set_Point_De_Vie(unsigned int i){
    assert(i<=Point_De_Vie_Max);//fonctionne pas dans le constructeur car le point_de_vie_max est initialise a 0
    Point_De_Vie=i;
}
void Statistiques::set_Point_De_Vie_Max(unsigned int i){
    assert(i>=Point_De_Vie);
    Point_De_Vie_Max=i;
}

void Statistiques::set_Mana(unsigned int i){
    assert(i<=Mana_Max);
    Mana=i;
}
void Statistiques::set_Mana_Max(unsigned int i){
    assert(i>=Mana);
    Mana_Max=i;
}
void Statistiques::set_Experience_Restant(unsigned int i){
    Experience_Restant=i;
}
void Statistiques::set_Experience_Donne(unsigned int i){
    Experience_Donne=i;
}
void Statistiques::set_Niveau(unsigned int i){
    Niveau=i;
}
void Statistiques::set_Force(unsigned int i){
    Force=i;
}
void Statistiques::set_Intelligence(unsigned int i){
    Intelligence=i;
}
void Statistiques::set_Agilite(unsigned int i){
    Agilite=i;
}
void Statistiques::set_Statistiques(Statistiques stat)
{
    set_Nom(stat.get_Nom()) ;
    set_Point_De_Vie_Max(stat.get_Point_De_Vie_Max()) ;
    set_Point_De_Vie(stat.get_Point_De_Vie()) ;
    set_Mana_Max(stat.get_Mana_Max()) ;
    set_Mana(stat.get_Mana()) ;
    set_Experience_Donne(stat.get_Experience_Donne()) ;
    set_Experience_Restant(stat.get_Experience_Restant()) ;
    set_Niveau(stat.get_Niveau()) ;
    set_Force(stat.get_Force()) ;
    set_Agilite(stat.get_Agilite()) ;
    set_Intelligence(stat.get_Intelligence()) ;
}

Statistiques::Statistiques()
{
    Nom=" ";
    Point_De_Vie_Max=0;
    Point_De_Vie=0;
    Mana_Max=0;
    Mana=0;
    Experience_Donne =0;
    Experience_Restant=0;
    Niveau=0;
    Force=0;
    Intelligence=0;
    Agilite=0;



    //ctor
}
Statistiques::Statistiques(string nom,unsigned int pv,unsigned int pv_max,
                      unsigned int mana,unsigned int mana_max,unsigned int xp_restant,unsigned int xp_donne,
                      unsigned int niveau,unsigned int force,unsigned int intel,
                      unsigned int agilite)
{
    Nom=nom;
    Point_De_Vie_Max=pv_max;
    Point_De_Vie=pv;
    Mana_Max=mana_max;
    Mana=mana;
    Experience_Restant=xp_restant;
    Experience_Donne=xp_donne;
    Niveau=niveau;
    Force=force;
    Intelligence=intel;
    Agilite=agilite;
}

Statistiques::~Statistiques()
{
    //dtor
}
void Statistiques::Affiche_Statistiques()const
{
    cout<<"nom :"<<get_Nom()<<" PV: "<<get_Point_De_Vie()<<" PV_Max: "<<get_Point_De_Vie_Max()<<" Mana: "<<get_Mana()<<endl;
    cout<<" Xp_Restant: "<<get_Experience_Restant()<<" Xp_Donne: "<< get_Experience_Donne()<<" Niveau: "<<get_Niveau()<<endl;
    cout<< " force: "<< get_Force()<<" Intelligence: "<<get_Intelligence()<<" Agilite: "<<get_Agilite()<<endl;
}
void Statistiques::Test_Regression()
{
   Affiche_Statistiques();
   set_Nom("Tetsu");
   set_Point_De_Vie_Max(15000);
   set_Point_De_Vie(15000);
   set_Mana_Max(10000);
   set_Mana(10000);
   set_Experience_Restant(0);
   set_Experience_Donne(1);
   set_Niveau(99);
   set_Force(20000);
   set_Intelligence(30000);
   set_Agilite(50000);
   Affiche_Statistiques();
}
