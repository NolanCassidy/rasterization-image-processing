#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <PNMwriterCPP.h>

#include <iostream>
#include <fstream>

using namespace std;

void PNMwriterCPP::Write(char *filename){
	ofstream f_out;
	f_out.open(filename, ios::out);

  int width = input->getWidth();
  int height = input->getHeight();
	int maxval = input->getMaxval();

	f_out << "P6" << endl << width << " " << height << endl << maxval << endl;
	f_out.write((char *)input->getBuffer(), 3*width*height);
	f_out.close();

}
