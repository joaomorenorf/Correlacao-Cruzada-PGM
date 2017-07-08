# Trabalho Prático em Linguagem C para Implementar a Correlacao Cruzada em imagens PGM

O problema desenvolvido neste trabalho diz respeito a encontrar uma imagem  dentro de uma imagem maior, sendo que as imagens não são necessáriamente idênticas. Isso pode ser feito aplicando a operação de correlação cruzada em cada janela possível da imagem maior que seja do tamanho da imagem menor. Entende-se correlação cruzada, basicamente, como uma operação que multiplica o valor escalar dos pixels de duas imagens estabelecendo um parâmetro de comparação de semelhança entre imagens, pois valores mais elevados tendem a apontar imagens mais parecidas..


Implementação

	A função LePGM recebe como argumento o nome da imagem tipo PGM a ser lida, a lê e a aloca de forma dinâmica como TAD: uma matriz de pixels, as dimensões da imagem e o valor máximo que um pixel pode assumir.
	A função CorrelacaoCruzada recebe como argumento a posição de uma janela deslizante, as imagens e calcula o valor da correlação cruzada de acordo com ponto de referência passado para a função. O cálculo é feito multiplicando os pixels e somando o resultado a soma da multiplicação dos pixels anteriores.
	A função JanelaDeslizante escolhe os pixels que terão sua correlação cruzada calculada e compara os resultados escolhendo o maior valor. O maior valor ao final designará o match entre as duas imagens e será retornado como ponteiro para TAD Ponto.
	A função SalvaPonto recebe o nome do arquivo de saída e o ponteiro para o valor do ponto escolhido, e então salva no arquivo as coordenadas do ponto.
	A função Desaloca recebe os TADs das imagens e ponto e os desaloca não retornando nada.

Resultados:

	Utilizou-se um computador Intel Atom N570 (1.66Ghz, 1MB L2 Cache) com 2GB de memória RAM, as instruções foram executadas apartir de um arquivo makefile cujo tempo de resposta foi medido.
	Utilizando o par de imagens exemplo, o computador demorou nas execuções ,edidas 0.011s em média para processar a requisição e retornou o valor correto para a resposta.
	Utilizando o par de imagens teste, o computador demorou 0.013s em média para processar a requisição e retornou o valor correto para a resposta.
	Utilizando o par de imagens tsukuba, o computador demorou 16s em média para processar a requisição e retornou o valor correto para a resposta.

Conclusão

	O programa foi capaz de encontrar com exatidão a posição dos objetos nas imagens amplas e como podemos perceber o tempo de execução não varia consideravelmente com a luminosidade da imagem, mas de forma quadrática com relação ao tamanho da imagem. A expectativa de que valores maiores de resultados da operação correlação cruzada correspondesse as imagens mais semelhantes pelo critério sensível mostrou-se verdadeira para as imagens testadas.	O problema não apresentou dificuldades em sua implementação.
