exec:
	gcc main.c PGM.c -o exec
exemplo: exec
	./exec exemplo_cena.pgm exemplo_objeto.pgm exemplo_saida.txt

teste: exec
	./exec teste_cena.pgm teste_objeto.pgm teste_saida.txt

tsukuba: exec	
	./exec tsukuba_cena.pgm tsukuba_objeto.pgm tsukuba_saida.txt

clean:
	rm -rf exemplo_saida.txt teste_saida.txt tsukuba_saida.txt
