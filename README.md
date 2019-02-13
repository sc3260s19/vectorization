# Autovectorization

This simple code demonstrates autovectorization for a vector addition routine.

## Building

Ensure that you have the intel compiler available in your environment:

	module load Intel

To build run:

	make

to delete the executable:

	make clean

## Running

The program accepts one command line argument, the length of the vector. For 
example:

	./vec_add 1000

A bash script is included that will time the execution time and pass in a vector
length of 1000000000 by default. Just type:

	bash run.sh

## Exercises

1. Build the binary with vectorization enabled (vectorization is turned on by default). 
Verify that the for loop is vectorized by reading the vectorization report generated 
by the compiler. Time the execution of the program for a vector length of 10000000000 by typing:

```bash
bash run.sh
``` 

2. Compare the walltime with versions of the binary that are built without vectorization enabled. Using 
optimization level zero will ensure that vectorization is disabled (uncomment CFLAGS line in Makefile).

3. Convert the for loop to a while loop. Does it still vectorize?

4. Notice the f characters in this expression:

```C
b[i] = 2.0f * (float)i + 1.0f;
```

What happens if you remove these characters from the line above and re-compile? What additional comments do you see
in the vectorization report?

5. Move the actual vector addition step (c = a + b) into a second for loop. With level three optimization
enabled, how does the autovectorization behavior compare (read reporting carefully)? How does the walltime compare?

6. Revert back to the original code. Now start the loop at i=1 (ignore the first element for the vector addition) 
and add this line to the end of the loop body:

```C
c[i] = c[i-1] + 82.3;
``` 

What changes? Why?
