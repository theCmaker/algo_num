CC=gcc -g
FichierC= main.c leverrier.c polynome.c matrices.c useful.c

main: $(FichierC)
	$(CC) -o $@ $^ -lm

clean:
	rm *~ *.o *.aux *.toc *.log *.bbl *.blg *.gz

arborescence: *.c *.h make*
	tree -r -P $^ | cut -d " " -f 1 | head -n -2 > $@

rapport: rapport.pdf

rapport.pdf: rapport.tex
	pdflatex $^; pdflatex $^
