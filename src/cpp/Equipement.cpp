#include <Equipement.h>

Equipement::Equipement()
{
    Arme.set_Nom(" ");
    Arme.set_Point_De_Vie(0);
    Arme.set_Point_De_Vie_Max(0);
    Arme.set_Mana(0);
    Arme.set_Experience_Restant(0);
    Arme.set_Experience_Donne(0);
    Arme.set_Niveau(0);
    Arme.set_Force(0);
    Arme.set_Intelligence(0);
    Arme.set_Agilite(0);

    Bouclier.set_Nom(" ");
    Bouclier.set_Point_De_Vie(0);
    Bouclier.set_Point_De_Vie_Max(0);
    Bouclier.set_Mana(0);
    Bouclier.set_Experience_Restant(0);
    Bouclier.set_Experience_Donne(0);
    Bouclier.set_Niveau(0);
    Bouclier.set_Force(0);
    Bouclier.set_Intelligence(0);
    Bouclier.set_Agilite(0);

    Casque.set_Nom(" ");
    Casque.set_Point_De_Vie(0);
    Casque.set_Point_De_Vie_Max(0);
    Casque.set_Mana(0);
    Casque.set_Experience_Restant(0);
    Casque.set_Experience_Donne(0);
    Casque.set_Niveau(0);
    Casque.set_Force(0);
    Casque.set_Intelligence(0);
    Casque.set_Agilite(0);
}

Equipement::~Equipement()
{

}

Statistiques Equipement::get_Stats_Arme()const
{
    return Arme;
}

Statistiques Equipement::get_Stats_Bouclier()const
{
    return Bouclier;
}

Statistiques Equipement::get_Stats_Casque()const
{
    return Casque;
}

void Equipement::set_Stats_Arme(class Statistiques Arme_nouv)
{
    Arme.set_Nom(Arme_nouv.get_Nom());
    Arme.set_Point_De_Vie(Arme_nouv.get_Point_De_Vie());
    Arme.set_Point_De_Vie_Max(Arme_nouv.get_Point_De_Vie_Max());
    Arme.set_Mana(Arme_nouv.get_Mana());
    Arme.set_Mana_Max(Arme_nouv.get_Mana_Max());
    Arme.set_Experience_Donne(Arme_nouv.get_Experience_Donne());
    Arme.set_Experience_Restant(Arme_nouv.get_Experience_Restant());
    Arme.set_Niveau(Arme_nouv.get_Niveau());
    Arme.set_Force(Arme_nouv.get_Force());
    Arme.set_Intelligence(Arme_nouv.get_Intelligence());
    Arme.set_Agilite(Arme_nouv.get_Agilite());
}

void Equipement::set_Stats_Bouclier(class Statistiques Bouclier_nouv)
{
    Bouclier.set_Nom(Bouclier_nouv.get_Nom());
    Bouclier.set_Point_De_Vie(Bouclier_nouv.get_Point_De_Vie());
    Bouclier.set_Point_De_Vie_Max(Bouclier_nouv.get_Point_De_Vie_Max());
    Bouclier.set_Mana(Bouclier_nouv.get_Mana());
    Bouclier.set_Mana_Max(Bouclier_nouv.get_Mana_Max());
    Bouclier.set_Experience_Donne(Bouclier_nouv.get_Experience_Donne());
    Bouclier.set_Experience_Restant(Bouclier_nouv.get_Experience_Restant());
    Bouclier.set_Niveau(Bouclier_nouv.get_Niveau());
    Bouclier.set_Force(Bouclier_nouv.get_Force());
    Bouclier.set_Intelligence(Bouclier_nouv.get_Intelligence());
    Bouclier.set_Agilite(Bouclier_nouv.get_Agilite());
}

void Equipement::set_Stats_Casque(class Statistiques Casque_nouv)
{
    Casque.set_Nom(Casque_nouv.get_Nom());
    Casque.set_Point_De_Vie(Casque_nouv.get_Point_De_Vie());
    Casque.set_Point_De_Vie_Max(Casque_nouv.get_Point_De_Vie_Max());
    Casque.set_Mana(Casque_nouv.get_Mana());
    Casque.set_Mana_Max(Casque_nouv.get_Mana_Max());
    Casque.set_Experience_Donne(Casque_nouv.get_Experience_Donne());
    Casque.set_Experience_Restant(Casque_nouv.get_Experience_Restant());
    Casque.set_Niveau(Casque_nouv.get_Niveau());
    Casque.set_Force(Casque_nouv.get_Force());
    Casque.set_Intelligence(Casque_nouv.get_Intelligence());
    Casque.set_Agilite(Casque_nouv.get_Agilite());
}

void Equipement::Test_Regression()
{
    cout << "Début du test de régression de l'équipement" << endl;
    cout << "Appel du constructeur" << endl;
    Equipement eq;
    cout << "Utilisation des set" << endl;
    string nomE = "Senzu";
    Statistiques statsE(nomE, 1000, 1000, 2000, 1000, 0, 1, 99, 5000, 1500, 7);
    //set_Stats_Bouclier(statsE);

    cout << "Fin du test de régression de l'équipement" << endl;
}
