CC=gcc -g

main: main.o gauss.o cholesky.o matrices.o jacobi.o gauss-seidel.o surrelaxation.o generateur.o
	$(CC) -o $@ $^ -lm

main.o: main.c
	$(CC) -c $^ -lm

cholesky.o: cholesky.c
	$(CC) -c $^ -lm

matrices.o: matrices.c
	$(CC) -c $^ -lm

gauss.o: gauss.c
	$(CC) -c $^ -lm

jacobi.o: jacobi.c
	$(CC) -c $^ -lm

gauss-seidel.o: gauss-seidel.c
	$(CC) -c $^ -lm

surrelaxation.o: surrelaxation.c
	$(CC) -c $^ -lm

generateur.o: generateur.c
	$(CC) -c $^ -lm

clean:
	rm *~ *.o *.aux *.toc *.log *.bbl *.blg *.gz

arborescence: *.c *.h make*
	tree -r -P $^ | cut -d " " -f 1 | head -n -2 > $@

rapport: rapport.pdf

rapport.pdf: rapport.tex
	pdflatex $^; pdflatex $^
