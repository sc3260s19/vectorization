//********************************************
//
// This is a simple example to demonstrate
// autovectorization. To enable autovectorization
// build with:
//
// icc -O2 add.c (or higher)
// gcc -O3 add.c
//
//********************************************

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv )
{

   if (argc != 2) {
      printf("usage: ./vec_add vec_size\n");
      exit(-1);
   }

   int vec_size = atoi(argv[1]);

   // _mm_malloc() aligns the starting point of each of these arrays
   // on a 32-byte (in this case) boundary, which makes loading these vectors from
   // memory more efficient
   float *a = (float *) _mm_malloc( vec_size * sizeof(float), 32 );
   float *b = (float *) _mm_malloc( vec_size * sizeof(float), 32 );
   float *c = (float *) _mm_malloc( vec_size * sizeof(float), 32 );

   int i;
   for ( i=0; i < vec_size; i++)
   {
      a[i] = (float)i;
      b[i] = 2.0f * (float)i + 1.0f;
      c[i] = a[i] + b[i];
   }
 
   if ( vec_size > 10 )  
      printf("i: %d, c[i]: %f\n",10,c[10]);

   // byte-aligned memory freed with _mm_free()
   _mm_free(a);
   _mm_free(b);
   _mm_free(c);

   return 0;

}

