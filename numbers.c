#include<stdio.h>
#include<math.h>

/* Description:
	Generate label numbers for spectrum chart consisting of:
		NNN Hz   Frequency
		NNN m    wavelength
		NNN eV   Energy
*/

	double ColPosition,RowPosition;



/* +++Date last modified: 05-Jul-1997 */
/* ENG.C - Format floating point in engineering notation          */
/* Released to public domain by author, David Harmon, Jan. 1994   */
/* Modifed by Dan Stubbs & Bob Stout, 14-Jul-1997                 */
/* Modifed by Anthony Tekatch for SIunits, 28-Mar-2003            */
char *eng(double value, int places)
{
      const char * const prefixes[] = {
            "\\yocto ", "\\zepto ", "\\atto ", "\\femto ", "\\pico ", "\\nano ", "\\micro ", "\\milli ",
	     "",
	     "\\kilo ", "\\mega " , "\\giga ", "\\tera ", "\\peta ", "\\exa ", "\\zeta ", "\\yotta "
            };
      int p = 8;
      static char result[30];
      char *res = result;

      *res++ = (value >= 0) ? ' ' : '-';
      value  = (value >= 0) ? value : -value;

      for ( ; p > 0 && value != 0 && value < 1.0; --p)
            value *= 1000.0;

      for ( ; p < 14 && value != 0 && value > 1000.0; ++p)
            value /= 1000.0;

      places = (value >= 100.0) ? places-2 :
               (value >=  10.0) ? places-1 : places;

      sprintf(res, "%.*f %s", places-1, value, prefixes[p]);

      return result;
}

void printlabel(double number, char * color, char * label)
{

	printf("\\uput{2pt}[270]( %2.1f,%2.1f){\\textcolor{%s}{%s%s}}\n"  ,ColPosition ,RowPosition,color,eng(number,3),label);

	ColPosition +=0.817;  /* Increment_value = pspicture_width / 12 divisions*/
}



int main()
{
	const double pi = 3.1415926535898; 

	/*planks constant (4.13566 x 10^-15 electron volts/second)*/
	const double h = 4.13566e-15;

	/*speed of light 2.997925 x 10^8 m/s*/
	const double c = 2.997925e8;

	double frequency, wavelength, energy;

	int Row;
	
	RowPosition=0.0;

	//Frequency range from:
	//	1 doubles up to __EHz
	//	1 halves down to ___nHz

	// Energy: e=h·f 
	//   where: h = Planks constant
	//          f = frequency in Hertz.


	// Wavelength:
	//	c/f

	/*
	   Sample printout:
	      \rput(0,0.9){\labelfont 512 THz}
	      \rput(1,0.9){\labelfont 100 km}
	      \rput(2,0.9){\labelfont 200 MeV}

	*/

	printf("%s This text is produced by numbers (source=numbers.c).\n\n","%");

	/* There is physically not enough room to put all three units at each grid point
	   so we put alternating units in four sets of three for each octave.
	   This arrangement harmlessly implies musical notes.*/

	/* Starting at some fraction of 1Hz*/
	frequency= 0.015625;

	/* wraparound on first line only*/
	//printf("\\uput{1pt}[270]( 9.8,-0.5){\\textcolor{blue}{%s\\hertz}}\n"  ,eng(frequency,3));

	/* Print each octave*/
	for ( Row= 1; Row<=69 ; Row += 1){
	
	  ColPosition=0.0;

	  if (Row!=1){

	  printlabel(frequency                         ,"FColor","\\hertz");
	  printlabel(c / (frequency * pow(2.0, 1/12.0)),"WColor","\\meter");
	  printlabel(h*(frequency   * pow(2.0, 2/12.0)),"EColor","\\electronvolt");

	  printlabel(frequency      * pow(2.0, 3/12.0), "FColor","\\hertz");

	  }
	  else
	  {
	  ColPosition +=0.817;
	  ColPosition +=0.817;
	  ColPosition +=0.817;
	  ColPosition +=0.817;
	  }

	  printlabel(c / (frequency * pow(2.0, 4/12.0)),"WColor","\\meter");
	  printlabel(h*(frequency   * pow(2.0, 5/12.0)),"EColor","\\electronvolt");

	  printlabel(frequency      * pow(2.0, 6/12.0), "FColor","\\hertz");
	  printlabel(c / (frequency * pow(2.0, 7/12.0)),"WColor","\\meter");
	  printlabel(h*(frequency   * pow(2.0, 8/12.0)),"EColor","\\electronvolt");

	  printlabel(frequency      * pow(2.0, 9/12.0), "FColor","\\hertz");

	  //printf("%s unused ","%");
	  printlabel(c / (frequency * pow(2.0,10/12.0)),"WColor","\\meter");

	  //printf("%s unused ","%");
	  printlabel(h*(frequency   * pow(2.0,11/12.0)),"EColor","\\electronvolt");

	  printlabel(frequency      * pow(2.0,12/12.0),"FColor","\\hertz");

	  RowPosition += 0.5;
	  frequency *= 2;

	}

}
