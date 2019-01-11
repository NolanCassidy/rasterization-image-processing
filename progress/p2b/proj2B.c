#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
	FILE *f_in,*f_out;
	f_in = fopen(argv[1], "rb");
	f_out = fopen(argv[2], "w");
	int *array = malloc(5 * sizeof(int));
  int offset = 10 * sizeof(int);
  int i = 0;
	while(i < 5){
		fseek(f_in, i*offset, SEEK_SET);
		fread(array, sizeof(int), 5, f_in);
		for(int j = 0; j < 5; j++){
			fprintf(f_out, "%d\n", array[j]);
		}
    i++;
	}
	fclose(f_in);
	fclose(f_out);
  free(array);
}
