CC=gcc -g

main: main.o neville.o polynome.o newton.o reglin.o useful.o
	$(CC) -o $@ $^ -lm

main.o: main.c
	$(CC) -c $^ -lm

polynome.o: polynome.c
	$(CC) -c $^ -lm

newton.o: newton.c
	$(CC) -c $^ -lm

neville.o: neville.c
	$(CC) -c $^ -lm

reglin.o: reglin.c
	$(CC) -c $^ -lm

useful.o: useful.c
	$(CC) -c $^

clean:
	rm *~ *.o *.aux *.toc *.log *.bbl *.blg *.gz

arborescence: *.c *.h make*
	tree -r -P $^ | cut -d " " -f 1 | head -n -2 > $@

rapport: rapport.pdf

rapport.pdf: rapport.tex
	pdflatex $^; pdflatex $^
