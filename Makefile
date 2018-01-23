CC					= g++
LD 					= g++
LDFLAGS  			=
CPPFLAGS 			= -Wall -ggdb  -std=c++11
OBJ_DIR 			= obj
SRC_DIR				= src/cpp
BIN_DIR 			= bin
INCLUDE_DIR			= -Isrc/include


CORE = Carte.cpp Heros.cpp Statistiques.cpp Ennemis.cpp Equipement.cpp Mini_Carte.cpp Objet.cpp Jeu.cpp Mini_Jeux0.cpp # Rajouter les .cpp ici

# Rajouter les .cpp que vous voulez tester seulement dans votre compilation ici
SRCS_DANIEL = $(CORE) mainDaniel.cpp
FINAL_TARGET_DANIEL = Daniel.exe
#DEFINE_DANIEL = -DJEU_DANIEL

# Rajouter les .cpp que vous voulez tester seulement dans votre compilation ici
SRCS_ROBIN = $(CORE) mainRobin.cpp
FINAL_TARGET_ROBIN = Robin.exe
#DEFINE_ROBIN = -DJEU_ROBIN

# Rajouter les .cpp que vous voulez tester seulement dans votre compilation ici
SRCS_EMILIEN = $(CORE) mainEmilien.cpp
FINAL_TARGET_EMILIEN = Emilien.exe
#DEFINE_EMILIEN = -DJEU_EMILIEN


SRCS_JEUTXT = $(CORE) JeuTXT.cpp mainTxt.cpp winTxt.cpp
FINAL_TARGET_JEUTXT = JeuTxt.exe
#DEFINE_EMILIEN = -DJEU_TXT

SRCS_JEUSDL = $(CORE) JeuSDL.cpp mainSDL.cpp 
FINAL_TARGET_JEUSDL = JeuSDL.exe
#DEFINE_JEUSDL = -DJEU_SDL

ifeq ($(OS),Windows_NT)
	INCLUDE_DIR_SDL = 	-Iextern/SDL2_mingw/SDL2-2.0.3/include \
						-Iextern/SDL2_mingw/SDL2_ttf-2.0.12/i686-w64-mingw32/include/SDL2 \
						-Iextern/SDL2_mingw/SDL2_image-2.0.0/i686-w64-mingw32/include/SDL2
	LIBS_SDL = 	-Lextern \
			-Lextern/SDL2_mingw/SDL2-2.0.3/i686-w64-mingw32/lib \
			-Lextern/SDL2_mingw/SDL2_ttf-2.0.12/i686-w64-mingw32/lib \
			-Lextern/SDL2_mingw/SDL2_image-2.0.0/i686-w64-mingw32/lib \
			-lmingw32 -lSDL2main -lSDL2.dll -lSDL2_ttf.dll -lSDL2_image.dll
else
	INCLUDE_DIR_SDL = -I/usr/include/SDL2
	LIBS_SDL = -lSDL2 -lSDL2_ttf -lSDL2_image
endif

default: $(BIN_DIR)/$(FINAL_TARGET_DANIEL) $(BIN_DIR)/$(FINAL_TARGET_ROBIN) $(BIN_DIR)/$(FINAL_TARGET_EMILIEN) $(BIN_DIR)/$(FINAL_TARGET_JEUTXT) $(BIN_DIR)/$(FINAL_TARGET_JEUSDL)

MainDaniel: $(BIN_DIR)/$(FINAL_TARGET_DANIEL)

MainRobin: $(BIN_DIR)/$(FINAL_TARGET_ROBIN)

MainEmilien: $(BIN_DIR)/$(FINAL_TARGET_EMILIEN)

JeuTXT: $(BIN_DIR)/$(FINAL_TARGET_JEUTXT)

JeuSDL: $(BIN_DIR)/$(FINAL_TARGET_JEUSDL)


# Création de votre .exe
$(BIN_DIR)/$(FINAL_TARGET_DANIEL): $(SRCS_DANIEL:%.cpp=$(OBJ_DIR)/%.o)
	$(LD) $+ -o $@ $(LDFLAGS)

# Création de votre .exe
$(BIN_DIR)/$(FINAL_TARGET_ROBIN): $(SRCS_ROBIN:%.cpp=$(OBJ_DIR)/%.o)
	$(LD) $+ -o $@ $(LDFLAGS)

# Création de votre .exe
$(BIN_DIR)/$(FINAL_TARGET_EMILIEN): $(SRCS_EMILIEN:%.cpp=$(OBJ_DIR)/%.o)
	$(LD) $+ -o $@ $(LDFLAGS)

# Création de l'exe jeutxt
$(BIN_DIR)/$(FINAL_TARGET_JEUTXT): $(SRCS_JEUTXT:%.cpp=$(OBJ_DIR)/%.o)
	$(LD) $+ -o $@ $(LDFLAGS)

# Création de l'exe jeusdl
$(BIN_DIR)/$(FINAL_TARGET_JEUSDL): $(SRCS_JEUSDL:%.cpp=$(OBJ_DIR)/%.o)
	$(LD) $+ -o $@ $(LDFLAGS) $(LIBS_SDL)

# Création de TOUT les .o (normalement)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -c $(CPPFLAGS) $(INCLUDE_DIR_SDL) $(INCLUDE_DIR) $< -o $@


clean:
ifeq ($(OS),Windows_NT)
	del /f $(OBJ_DIR)\*.o $(BIN_DIR)\$(FINAL_TARGET_DANIEL) $(BIN_DIR)\$(FINAL_TARGET_ROBIN) $(BIN_DIR)\$(FINAL_TARGET_EMILIEN) $(BIN_DIR)\$(FINAL_TARGET_JEUTXT) $(BIN_DIR)\$(FINAL_TARGET_JEUSDL)
else
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/$(FINAL_TARGET_DANIEL) $(BIN_DIR)/$(FINAL_TARGET_ROBIN) $(BIN_DIR)/$(FINAL_TARGET_EMILIEN) $(BIN_DIR)/$(FINAL_TARGET_JEUTXT) $(BIN_DIR)/$(FINAL_TARGET_JEUSDL)
endif
