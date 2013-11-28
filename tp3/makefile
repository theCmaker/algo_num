CC=gcc -g

main: main.o leverrier.o polynome.o useful.o matrices.o
	$(CC) -o $@ $^ -lm

main.o: main.c
	$(CC) -c $^ -lm

polynome.o: polynome.c
	$(CC) -c $^ -lm

leverrier.o: leverrier.c
	$(CC) -c $^ -lm

useful.o: useful.c
	$(CC) -c $^

matrices.o: matrices.c
	$(CC) -c $^ -lm

clean:
	rm *~ *.o *.aux *.toc *.log *.bbl *.blg *.gz

arborescence: *.c *.h make*
	tree -r -P $^ | cut -d " " -f 1 | head -n -2 > $@

rapport: rapport.pdf

rapport.pdf: rapport.tex
	pdflatex $^; pdflatex $^
