CC=gcc -g

main: main.o neuville.o newton.o polynome.o lagrange.o reglin.o
	$(CC) -o $@ $^ -lm

main.o: main.c
	$(CC) -c $^ -lm

polynome.o: polynome.c
	$(CC) -c $^ -lm

lagrange.o: lagrange.c
	$(CC) -c $^ -lm

newton.o: newton.c
	$(CC) -c $^ -lm

neuville.o: neuville.c
	$(CC) -c $^ -lm

reglin.o: reglin.c
	$(CC) -c $^ -lm

clean:
	rm *~ *.o *.aux *.toc *.log *.bbl *.blg *.gz

arborescence: *.c *.h make*
	tree -r -P $^ | cut -d " " -f 1 | head -n -2 > $@

rapport: rapport.pdf

rapport.pdf: rapport.tex
	pdflatex $^; pdflatex $^
