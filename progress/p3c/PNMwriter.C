#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <PNMwriter.h>

void PNMwriter::Write(char *filename){
  FILE *f_out = fopen(filename, "wb");
	fprintf(f_out, "%s\n%d %d\n%d\n", "P6", input->getWidth(), input->getHeight(), input->getMaxval());
	fwrite(input->getBuffer(), 3*sizeof(unsigned char), input->getWidth()*input->getHeight(), f_out);
	fclose(f_out);
}
