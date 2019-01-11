#include <stdlib.h>
#include <stdio.h>

int main()
{
   int *A = malloc(sizeof(int)*21);
   int	*B[3]	=	{	A,	A+7,	A+14	};
   A[0] = 0;

   A[1] = 1;

   for (int i = 2 ; i < 21 ; i++)
      A[i] = A[i-1] + A[i-2];

   printf("A is %p\n", A);
   printf("&A is %p\n", &A);
   printf("A[2] is %d\n", A[2]);
   printf("*A is %d\n", *A);
   printf("B[1][3] is %d\n", B[1][3]);
   printf("*(A+4) is %d\n", *(A+4));
   printf("(A+6) is %p\n", (A+6));
   printf("B[2][0]-B[1][6] is %d\n", B[2][0]-B[1][6]);
   printf("B[2][0]-B[1][7] is %d\n", B[2][0]-B[1][7]);
   printf("(A+3) is %p\n", (A+3));
   printf("*(A+6)-*(A+2) is %d \n", *(A+6)-*(A+2));
   printf("A[5]-*(A+4) is %d is %d \n", A[5],*(A+4));
   printf("(A+9)-B[0] is %p\n", (A+9)-B[0]);
   printf("B[0] is %p \n", B[0]);
   printf("B[2][2]-A[15] is %d \n", B[2][2]-A[15]);
   printf("&(B[2][3])-&(A[15]) is %ld \n", &(B[2][3])-&(A[15]));
   printf("*(&A[6]) is %d \n", *(&A[6]));
   printf("B[3]-B[1] is %ld \n", B[3]-B[1]);
   printf("&(B[2][3])-&(A[15]) is %p \n", &(B[2][3]));
   printf("&(B[2][3])-&(A[15]) is %p \n", B[2]);

   printf("&(B[2][3])-&(A[15]) is %p \n", &(A[15]));
   printf("&(B[2][3])-&(A[15]) is %p \n",&A[6]);
}
