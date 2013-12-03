CC=gcc -g

OBJS=main.o leverrier.o polynome.o matrices.o useful.o

SUFFIXES ?= .c .o #pour reconnaître les extensions comme suffixe
.SUFFIXES: $(SUFFIXES) .

main: $(OBJS)
	$(CC) -o $@ $^ -lm

.c.o: #règle implicite -> dérive les .c vers des .o avec la règle définie dessous
	$(CC) -c $*.c

clean:
	rm *~ *.o *.aux *.toc *.log *.bbl *.blg *.gz

arborescence: *.c *.h make*
	tree -r -P $^ | cut -d " " -f 1 | head -n -2 > $@

rapport: rapport.pdf

rapport.pdf: rapport.tex
	pdflatex $^; pdflatex $^
