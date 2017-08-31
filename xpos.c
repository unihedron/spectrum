#include<stdio.h>
#include<math.h>

/* Description:
	Generate X position for spectrum chart:
		input frequency
		output position row & col corrected inches 
		
*/


int main()
{

	double startvert, endvert, xpos, start, end, startxpos, startypos, endxpos, endypos, position,width;
	int ypos;
	width=9.8; /*inches*/

	printf("Converts frequencie to X/Y positions.\n");
	printf("Enter two space separated frequencies Eg. 300e12 400e12\n");
	printf("  exa e18.\n");
	printf(" peta e15.\n");
	printf(" tera e12.\n");
	printf(" giga e9.\n");
	printf(" mega e6.\n");
	printf("  x step is 0.5 inches.\n");
	printf("  y divided into 12 steps.\n");
	printf("Ctl-c to exit.\n");

	while (scanf("%lf %lf", &start, &end) == 2){
		/*bottom left corner of box */
		position = log(start)/log(2);
		startvert = position/2+3.0;
		ypos = (int)position;
		startxpos = ((position-(double)ypos))*width;
		startypos = (double)(ypos)/2+3.05;
		printf("\t(%.3f,%.2f)",startxpos,startypos);

		/*top right corner of box*/
		position = log(end)/log(2);
		endvert = position/2+3.0;
		ypos = (int)position;
		endxpos = ((position-(double)ypos))*width;
		endypos = (double)(ypos)/2+3.25;
		printf("(%.3f,%.2f)   ",endxpos,endypos);

		/*text label centered in box*/
		printf("(%.2f,",(endxpos - startxpos)/2 + startxpos);
		printf("%.2f)\n",(endypos - startypos)/2 + startypos);
		printf("start_ypos= %.3f   end_ypos= %.3f\n",startvert,endvert);
		
	}
	return 0;

}
