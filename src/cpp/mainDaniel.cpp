#include <iostream>

#include <Heros.h>
#include <Equipement.h>

using namespace std;

int main()
{
    Heros heros;
    Equipement equip;

    /*heros.Test_Regression();
    cout << endl;
    equip.Test_Regression(); */

    heros.set_Heros("data/core/Heros/Bob.txt");

    cout << "Bonjour je suis le main de Daniel." << endl;
    return 0;
}

