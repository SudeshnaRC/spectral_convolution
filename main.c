#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "randu.h"
#include "test.h"
#include "MT.h"

//For setting the max loops we do in the period test
#define LOOPS 1000000000UL

//Test our three generators with period, spectral tests.
int main(void) {

	FILE * file;

	long seed = time(NULL);

	//seed PRNGs here
	srandu(seed);
	srand(seed);
	init_genrand(seed);

	//period tests here
	printf("The Period of function randu(), with seed %ld is %ld\n", seed, test_period(randu, LOOPS));
	printf("The period of function rand(), with seed %ld is %ld\n", seed, test_period(rand, LOOPS));
	printf("The period of function genrand_int32(), with seed %ld is %ld\n", seed, test_period(genrand_int32, LOOPS));


	//spectral tests here
	
	//randu()
	file = fopen("randuspectral.dat", "w");
	test_spectral(randu, 1000000, 3, file);
	fclose(file);
	
	//rand()
	file = fopen("randspectral.dat", "w");
	test_spectral(rand, 1000000, 3, file);
	fclose(file);

	//MT()
	file = fopen("mtspectral.dat", "w");
	test_spectral(genrand_int32, 1000000, 3, file);
	fclose(file);
	
	//roulette test here
	
	//randu()
	file = fopen("randuroulette.dat", "a");
	test_roulette(randu, 10000000, 36, file);
	fclose(file);

	//rand()
	file = fopen("randroulette.dat", "w");
	test_roulette(rand, 10000000, 36, file);
	fclose(file);

	//MT()
	file = fopen("mtroulette.dat", "w");
	test_roulette(genrand_int32, 100000000, 36, file);
	fclose(file);


	return 0; 
}

