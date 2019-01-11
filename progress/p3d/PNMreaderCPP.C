#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <PNMreaderCPP.h>

#include <iostream>
#include <fstream>

using namespace std;

PNMreaderCPP::PNMreaderCPP(char *f){
  filename = new char[strlen(f)+1];
  strcpy(filename,f);
}

PNMreaderCPP::~PNMreaderCPP(){
}

void PNMreaderCPP::Execute(){
  ifstream f_in;
	f_in.open(filename, ios::in);

  char magicNum[128];
	int width, height, maxval;

	f_in >> magicNum >> width >> height >> maxval;
  f_in.ignore();

	img.ResetSize(width, height);
  img.setMaxval(maxval);
  img.setBuffer();

	f_in.read((char *)img.getBuffer(), 3*width*height);
	f_in.close();
}
