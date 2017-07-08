#include <stdio.h>
#include <stdlib.h>
#include "PGM.h"
#include <string.h>


PGM *LePGM (char* entrada) {
    // Abrir o arquivo
    FILE *imagem;
    imagem=fopen(entrada, "r");
    if (!imagem) {
        printf("Erro na abertura do arquivo.\n");
        exit (1);
    }
    char *c;
    c=(char *)malloc(3*sizeof(char));
    fscanf(imagem, "%s", c);
    c[2] = '\0';
    if (strcmp(c, "P2") != 0){
        printf("\nO Arquivo nao e PGM.\n");
    }
    free(c);

    // Iniciar PGM_Entrada
    PGM *PGM_Entrada=malloc(sizeof(PGM));
    fscanf (imagem, "%d", &PGM_Entrada->c);
    fscanf (imagem, "%d", &PGM_Entrada->l);
    fscanf (imagem, "%hhu", &PGM_Entrada->maximo);
    unsigned char **MatrizEntrada=(unsigned char **)malloc((PGM_Entrada->l)*sizeof(unsigned char *));
    int ii;
    for (ii=0; ii < PGM_Entrada->l; ii++) {
        MatrizEntrada[ii]=(unsigned char *)malloc((PGM_Entrada->c)*sizeof(unsigned char));
    }
    PGM_Entrada->imagem=MatrizEntrada;

    // Copiar imagem em PGM_Entrada.imagem
    int jj;
    for(ii=0; ii < PGM_Entrada->l; ii++) {
        for (jj=0; jj < PGM_Entrada->c; jj++) {
            if (fscanf(imagem,"%hhu", &PGM_Entrada->imagem[ii][jj]) != 1) {
                printf("\nErro ao copiar a imagem.\n");
                exit (2);
            }
	}
    }
    fclose (imagem);
    return PGM_Entrada;
}

Ponto *JanelaDeslizante(PGM *cena, PGM *obj) {
    int ii, jj, linhas_max, colunas_max, CorrelacaoMaxima=-32768, aux;
    Ponto *p=malloc(sizeof(Ponto));
    Ponto *pAUX=malloc(sizeof(Ponto));
    linhas_max=cena->l-obj->l+1;
    colunas_max=cena->c-obj->c+1;
    for (ii = 0;ii < linhas_max; ii++) {
        for (jj = 0;jj < colunas_max; jj++) {
	    pAUX->x=jj;
            pAUX->y=ii;
            aux=CorrelacaoCruzada(cena, obj, pAUX);
            if(aux > CorrelacaoMaxima){
                CorrelacaoMaxima=aux;
                p->x=jj;
                p->y=ii;
            }
        }
    }
    free(pAUX);
    return p;
}

int CorrelacaoCruzada(PGM *cena, PGM *obj, Ponto *p) {
    int ii, jj, kk, ll, valor=0;
    int linhas_max = p->y + obj->l;
    int colunas_max= p->x + obj->c;
    for     (ii=p->x, kk=0; ii < colunas_max; ii++, kk++) {
        for (jj=p->y, ll=0; jj < linhas_max ; jj++, ll++) {
            valor += cena->imagem[jj][ii]*obj->imagem[ll][kk];
        }
    }
    return valor;
}

void SalvaPonto(Ponto* p, char *ArquivoSaida) {
    FILE *saida;
    saida=fopen (ArquivoSaida,"w");
    fprintf(saida, "%d %d", p->x, p->y);
    fclose(saida);
}

void Desaloca(PGM* PGM_Cena, PGM* PGM_Recorte, Ponto* p) {
    int ii;
    //Desaloca MatrizCena
    for (ii=0; ii < PGM_Cena->l; ii++) {
        free(PGM_Cena->imagem[ii]);
    }
    free(PGM_Cena->imagem);
    free(PGM_Cena);

    //Desaloca MatrizRecorte
    for (ii=0; ii < PGM_Recorte->l; ii++) {
        free(PGM_Recorte->imagem[ii]);
    }
    free(PGM_Recorte->imagem);
    free(PGM_Recorte);

    //Desaloca Ponto
    free(p);
}
