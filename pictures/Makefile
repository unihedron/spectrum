
all: emr.pdf

emr.pdf: emr.tex
	/usr/bin/latex emrmaster.tex
	/usr/bin/dvips  -Ppdf -G0 emrmaster.dvi -f > emrmaster.eps
	#ps2pdf emrmaster.eps
	/usr/bin/gs -dSAFER -q -dNOPAUSE -dBATCH -sDEVICE=pdfwrite -sOutputFile=emrmaster.pdf -dSAFER -c .setpdfwrite -f emrmaster.eps

waves: waves.c
	cc -lm -o waves waves.c

clean:
	rm -f *.aux
	rm -f *.dvi
	rm -f emrmaster.eps
	rm -f *.log

Makefile: Makefile.in ../config.status
	( cd .. && make config.status && ./config.status )
