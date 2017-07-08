#ifndef PGM_INCLUDED
#define PGM_INCLUDED

typedef struct {
    int c;                          // número de colunas na imagem
    int l;                          // número de linhas na imagem
    unsigned char maximo;           // valor máximo para cada pixel
    unsigned char **imagem;         // variável para armazenar os pixels da imagem (matriz)
} PGM;

typedef struct {
    int x;                          // coluna
    int y;                          // linha
} Ponto;

PGM *LePGM(char* entrada);

    /*----------------------------------------------------------------------
      Protótipo: LePGM(char* entrada)
      Função: Le o arquivo PGM e salva em um TAD.
      Entrada: Endereço do caminho para o arquivo PGM.
      Saída: Retorna o endereço para o TAD PGM.
    ------------------------------------------------------------------------*/

int CorrelacaoCruzada(PGM *cena, PGM *obj, Ponto *p);

    /*----------------------------------------------------------------------
      Protótipo: CorrelacaoCruzada(PGM *cena, PGM *obj, Ponto *p)
      Função: Calcula a correlação cruzada do ponto de referência.
      Entrada: As duas imagens a serem comparadas e o ponto a ser estudado.
      Saída: O valor da correlação cruzada no ponto.
    ------------------------------------------------------------------------*/

Ponto *JanelaDeslizante(PGM *cena, PGM *obj);

    /*----------------------------------------------------------------------
      Protótipo: JanelaDeslizante(PGM *cena, PGM *obj)
      Função: Navega internamente na imagem maior chamando a função
              CorrelacaoCruzada para os pontos possíveis.
      Entrada: As imagens a serem comparadas.
      Saída: O ponto em que o match foi encontrado.
    ------------------------------------------------------------------------*/

void SalvaPonto(Ponto *p, char *ArquivoSaida);

    /*----------------------------------------------------------------------
      Protótipo: SalvaPonto(Ponto *p, char *ArquivoSaida)
      Função: Salva os valores do ponto no arquivo de saída.
      Entrada: O endereço onde se encotra as informações do ponto escolhido
               e o nome do arquivo de saída.
      Saída: Não retorna nada.
    ------------------------------------------------------------------------*/

void Desaloca(PGM* PGM_Cena, PGM* PGM_Recorte, Ponto* p);

    /*----------------------------------------------------------------------
      Protótipo: Desaloca(PGM* PGM_Cena, PGM* PGM_Recorte, Ponto* p)
      Função: Desaloca os TADs dos arquivos PGM e do ponto.
      Entrada: Os endereços das TADs a serem desalocadas.
      Saída: Não retorna nada.
    ------------------------------------------------------------------------*/

#endif // PGM_INCLUDED
