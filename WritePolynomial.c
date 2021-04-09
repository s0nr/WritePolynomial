/* Writing polynomial in a pretty format
 * 28 March 2021
 * CSE102 HW4 Freshman
 * Soner Gunes */

#include <stdio.h>

void write_polynomial();

int main() {

	write_polynomial();	/* calling function to write polynomial */
	
	return 0;
}

void write_polynomial() { /* writes nth degree polynomial */

	int
	degree, /* stores the degree of polynomial */
	control, /* to determine first item of polynomial */
	i; /* loop item */
	
	double
	coefficient; /* stores coefficients of terms */

	printf("\nP(x) = a_nx^n + a_n-1x^n-1 + ... + a_1x + a_0\n"); /* info */

	printf("\nEnter your polynomial [n a_n a_n-1 a_n-2 ... a_0]: "); /* directive */
	
	scanf("%d", &degree); /* getting degree from user */
	
	printf("\n");
	
	control = 0; /* initalizing the value */

	for(i=0; i<=degree; i++) { /* loops degree plus one times and displays polynomial parts one by one */
	
		scanf("%lf", &coefficient); /* getting coefficent from user */
		
		if(coefficient != 0) { /* since the 0 coefficent will be neglected zero is omitted */
			
			if(coefficient > 0) { /* for positive values */
			
				if(coefficient == 1) { /* one is an exception while writing polynomials */
				
					if(control != 0) { /* checking if the value is first term or not */
						printf("+ ");
					}			
					
					if(degree - i == 0) { /* no degree no x term */
						printf("1 ");	
					}
						
					else if(degree - i == 1) { /* one degree for x */
						printf("x ");	
					}
					
					else { /* degrees greater than one */
						printf("x^%d ", degree - i);
					}
					              				
				}		
					
				else {		
				
					if((coefficient - (int)coefficient) == 0) { /* integers are displayed without decimal points */
					
						if(control != 0) { /* checking if the value is first term or not */
							printf("+ ");
						}
						
						if(degree - i== 0) { /* no degree no x term */
							printf("%d ", (int)coefficient);
						}
						
						else if(degree - i == 1) { /* one degree for x */
							printf("%dx ", (int)coefficient);
						
						}
						
						else { /* degrees greater than one */
							printf("%dx^%d ", (int)coefficient, degree - i);	
						}				
						
					}
					
					else { /* double numbers are displayed with decimal points */
					
						if(control != 0) { /* checking if the value is first term or not */
							printf("+ ");
						}
						
						if(degree - i == 0) { /* no degree no x term */
							printf("%.1lf ", coefficient);
						}
						
						else if(degree - i == 1) { /* one degree for x */
							printf("%.1lfx ", coefficient);
						
						}
						
						else { /* degrees greater than one */
							printf("%.1lfx^%d ", coefficient, degree - i);
						}
							
					}	
				}	
			}			
				
			else if(coefficient < 0) { /* for negative values */
			
				if(coefficient == -1) { /* minus one is an exception too */	
					
					if(control == 0) { /* there will be always a minus sign regardless of first term */					
						printf("-"); 
					}
					else { /* the difference is whether the minus sinus stuck to coefficient or not */
						printf("- ");
					}
					
					if(degree - i == 0) { /* no degree no x term */
						printf("1 ");
					}
						
					else if(degree - i == 1) { /* one degree for x */
						printf("x ");		
					}
						
					else { /* degrees greater than one */
						printf("x^%d ", degree - i);
					}
						
				}
			
				else {
				
					if((coefficient - (int)coefficient) == 0) { /* integers are displayed without decimal points */
					
						if(control == 0) { /* there will be always a minus sign regardless of first term */					
							printf("-"); 
					    }
						else { /* the difference is whether the minus sinus stuck to coefficient or not */
							printf("- ");
						}
						
						if(degree - i == 0) { /* integers no degree no x term */
							printf("%d ", -(int)coefficient);
						}
						
						else if(degree - i == 1) { /* integers one degree for x */
							printf("%dx ", -(int)coefficient);
						}
						
						else { /* integers degrees greater than one */
							printf("%dx^%d ", -(int)coefficient, degree - i);
						}
						
					}
					
					else { /* double numbers are displayed with decimal points */
					
						if(control == 0) { /* there will be always a minus sign regardless of first term */					
							printf("-"); 
						}
						else { /* the difference is whether the minus sinus stuck to coefficient or not */
							printf("- ");
						}
							
						if(degree - i == 0) { /* doubles no degree no x term */
							printf("%.1lf ", -coefficient);
						}
						
						else if(degree - i == 1) { /* doubles one degree for x */
							printf("%.1lfx ", -coefficient);						
						}
						
						else { /* doubles degrees greater than one */
							printf("%.1lfx^%d ", -coefficient, degree - i);
						}
						
					}
				}		
			}
			
			control = 1; /* the first non-0 value entered is displayed as the first term and other values will displayed sequentially */
		}
		
		else if(coefficient == 0 && degree == 0) { /* if all values are zero then result will be just zero */
			printf("0");	
		}				
	}
	
	printf("\n\n");
}
