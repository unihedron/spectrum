#include<stdio.h>
#include<math.h>

/* Description:
	Generate scale for spectrum chart:
		input and begining and step frequency
		output LaTeX for scale
		
		n         n         n
		|_._._._._|_._._._._|_._._._
		
*/


int main()
{

	double point,xpos, start, end,step, startxpos, startypos, endxpos, endypos, position,width;
	int ypos;
	width=9.8;/*inches*/
	printf("Generate scale for spectrum chart.\n");
	printf("Enter three space separated frequencies Eg. 300e12 400e12 10e11\n");
	printf("  exa e18.\n");
	printf(" peta e15.\n");
	printf(" tera e12.\n");
	printf(" giga e9.\n");
	printf(" mega e6.\n");
	printf("  x step is 0.5 inches.\n");
	printf("  y divided into 12 steps.\n");
	printf("Ctl-c to exit.\n");



	while (scanf("%lf %lf %lf", &start, &end, &step) == 3){
	
		for (point=start;point<=end;point=point+step){

		/*calculate the X and Y positions for a point */
		position = log(point)/log(2);
		ypos = (int)position;
		startxpos = ((position-(double)ypos))*width;
		startypos = (double)(ypos)/2+3.05;
		endypos = (double)(ypos)/2+3.075;
		printf("\\psline");
		printf("(%.3f,%.3f)",startxpos,startypos);
		printf("(%.3f,%.3f)",startxpos,endypos);
		printf("%s \tpoint=%.2f\n","%",point);

		}
	
		
	}


	return 0;


		/*bottom left corner of box */
		position = log(start)/log(2);
		ypos = (int)position;
		startxpos = ((position-(double)ypos))*width;
		startypos = (double)(ypos)/2+3.05;
		printf("\t(%.2f,%.2f)",startxpos,startypos);

		/*top right corner of box*/
		position = log(end)/log(2);
		ypos = (int)position;
		endxpos = ((position-(double)ypos))*width;
		endypos = (double)(ypos)/2+3.25;
		printf("(%.2f,%.2f)   ",endxpos,endypos);

		/*text label centered in box*/
		printf("(%.2f,",(endxpos - startxpos)/2 + startxpos);
		printf("%.2f)\n",(endypos - startypos)/2 + startypos);


}
