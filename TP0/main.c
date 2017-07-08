#include <stdio.h>
#include <stdlib.h>
#include "PGM.h"

int main (int argc, char *argv[]) {

    PGM *PGM_Cena=LePGM(argv[1]);

    PGM *PGM_Recorte=LePGM(argv[2]);

    Ponto *p=JanelaDeslizante(PGM_Cena, PGM_Recorte);

    SalvaPonto(p, argv[3]);

    Desaloca(PGM_Cena, PGM_Recorte, p);

    return 0;
}
