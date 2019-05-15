#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/* Description: Generate X position for spectrum chart derived from xpos.c
input: frequency range (default MHz)
output: position row & col corrected inches 
Arguments: multiplier offset thickness
		

Usage:
cat tex/3G-F.txt  | ./xpose6 1e6 0.250 0.020 > tex/3Gbands.tex
cat tex/LTE-F.txt | ./xpose6 1e6 0.270 0.020 > tex/4Gbands.tex
cat tex/5G-F1.txt | ./xpose6 1e6 0.290 0.020 > tex/5GF1bands.tex
cat tex/5G-F2.txt | ./xpose6 1e9 0.290 0.020 > tex/5GF2bands.tex

*/

int main(int argc, char* argv[] ) {
	double multiplier;// multliper from command line 
	double yoffset; //y offset from command line
	double thickness; //y thickness from command line
	double xpos, start, end, startxpos, endxpos, botypos, topypos, startposition,endposition,width;
	int startypos,endypos;
	width=9.8; /*inches*/

	//Multiplier (i.e. 1e6, 1e9, etc).
	if( argc > 1 ) {
		multiplier = atof(argv[1]);
	} else {
		multiplier = 1.0;
	}
	
	//Y offset in inches.
	if( argc > 2 ) {
		yoffset = atof(argv[2]);
	} else {
		yoffset = 0.0;
	}

	//Y thickness in inches.
	if( argc > 3 ) {
		thickness = atof(argv[3]);
	} else {
		thickness = 0.100;
	}

	while (scanf("%lf %lf", &start, &end) == 2){
		start = start * multiplier;
		end = end * multiplier;
		
		/*bottom left corner of box */
		startposition = log(start)/log(2);
		startypos = (int)startposition;
		startxpos = ((startposition-(double)startypos))*width;
		botypos = (double)(startypos)/2+3.00+yoffset; //3.00 is the base

		/*top right corner of box*/
		endposition = log(end)/log(2);
		endypos = (int)endposition;
		endxpos = ((endposition-(double)endypos))*width;
		topypos = (double)(endypos)/2+3.00+yoffset+thickness; //3.25 is the top

		if (startxpos<endxpos){
			printf("\\psframe(%.3f,%.3f)(%.3f,%.3f)\n", startxpos, topypos-thickness, endxpos, topypos);
		}else{
			printf("\\psframe(%.3f,%.3f)(9.800,%.3f)", startxpos, botypos, botypos+thickness);
			printf("\\psframe(0.000,%.3f)(%.3f,%.3f)\n", topypos-thickness, endxpos, topypos);
		}
		
		/* check for overlap */
	}
	return 0;

}
