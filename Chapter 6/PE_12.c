#include <stdio.h>
void main(void)
{
	int no_of_terms, t_ct;
	float denom1, denom2, sum_series1, sum_series2;
	printf("Enter the No. of terms till which the series should be evaluated\n");
	scanf("%d",&no_of_terms);

	while(no_of_terms > 0)
	{
		for(sum_series1 = sum_series2 = 0, t_ct = 1, denom1 = denom2 = 1.0; t_ct <= no_of_terms; 
			t_ct++, denom1 += 1.0, denom2 *= -1.0*denom1)
		{
			sum_series1 += 1.0/denom1;
			sum_series2 += 1.0/denom2;
		}
		printf("The sum of the two series is %f %f\n",sum_series1,sum_series2);
		printf("Enter the No. of terms till which the series should be evaluated\n");
		scanf("%d",&no_of_terms);
	}
}