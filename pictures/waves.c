#include<stdio.h>
#include<math.h>

/* Description:
	Generate sound wave schematic for spectrum chart:
		
*/


int main()
{

	const double scale = 41.0916;  /*adjusted so that final point is drawn at 5.00 inches*/
	double xpos, xinc, iteration;
	xpos = 0.0;

	for (iteration=0;iteration<=20;iteration=iteration+0.1){

		xinc = sin(iteration);
		xpos = xpos + 1+xinc;
		//printf("xinc = %.2f\txpos = %.2f\n",xinc,xpos);

		printf("\\ThreeDput[normal=1 0 0](%.3f,0,0){\\pscircle[fillstyle=solid,fillcolor=green,linecolor=black](0,0){0.3}}\n",xpos/scale);

	}

	return 0;

}
