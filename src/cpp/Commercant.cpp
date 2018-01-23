#include <Commercant.h>
#include <Objet.h>
#include <Statistiques.h>

#include <iostream>
#include <string>

Commercant::Commercant()
{
    Script = " ";
    Position_X_Mini_Carte = 0;
}


Commercant::~Commercant()
{

}


void Commercant::set_Position_X_Mini_Carte(unsigned int Pos_X_Mini_Carte_nouv)
{
    Position_X_Mini_Carte = Pos_X_Mini_Carte_nouv;
}

void Commercant::set_Position_Y_Mini_Carte(unsigned int Pos_Y_Mini_Carte_nouv)
{
    Position_Y_Mini_Carte = Pos_Y_Mini_Carte_nouv;
}

void Commercant::set_Orientation(char orientation)
{
    assert(orientation == 'd' || orientation == 'g') ;
    Orientation = orientation ;
}



unsigned int Commercant::get_Position_X_Mini_Carte() const
{
    return Position_X_Mini_Carte;
}

unsigned int Commercant::get_Position_Y_Mini_Carte() const
{
    return Position_Y_Mini_Carte;
}

char Commercant::get_Orientation() const
{
    return Orientation;
}


void Commercant::Fuite(Mini_Carte & mc)
{
	if(Orientation == 'd')
	{
		if(!mc.Est_Ce_Que_Mur(Position_X_Mini_Carte+1,Position_Y_Mini_Carte))
		{
			Position_X_Mini_Carte += 1;
		}else{
			Orientation = 'g';
			Position_X_Mini_Carte -= 1;
		}
	}
	else if (Orientation == 'g')
	{
		if(!mc.Est_Ce_Que_Mur(Position_X_Mini_Carte-1, Position_Y_Mini_Carte))
		{
			Position_X_Mini_Carte -= 1;
		}else{
			Orientation = 'd';
			Position_X_Mini_Carte +=1;
		}
	}

}


