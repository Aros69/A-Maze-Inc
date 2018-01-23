#ifndef JEUTXT_H
#define JEUTXT_H

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include <winTxt.h>

#include <Jeu.h>
#include <winTxt.h>
#include <chrono>

void txtAff(WinTXT & win, const Jeu & jeu) ;

void txtBoucle (Jeu & j) ;

#endif // JEUTXT_H
