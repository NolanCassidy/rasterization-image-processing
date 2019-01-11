#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <PNMreader.h>

PNMreader::PNMreader(char *f){
    filename = new char[strlen(f)+1];
    strcpy(filename,f);
}

PNMreader::~PNMreader(){
}

void PNMreader::Execute(){
  FILE *f_in = fopen(filename, "rb");
	char magicNum[128];
	int width, height, maxval;

	fscanf(f_in, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval);
	img.ResetSize(width, height);
	img.setMaxval(maxval);
	img.setBuffer();
	fread(img.getBuffer(),3*sizeof(unsigned char), width*height, f_in);
	fclose(f_in);
}
