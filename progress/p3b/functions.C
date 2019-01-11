#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <image.h>

void  ReadImage(char *filename, Image &output) {
	FILE *f_in = fopen(filename, "rb");
	char magicNum[128];
	int width, height, maxval;

	fscanf(f_in, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval);
	output.ResetSize(width, height);
	output.setMaxval(maxval);
	output.setBuffer();
	fread(output.getBuffer(),3*sizeof(unsigned char), width*height, f_in);
	fclose(f_in);
}

void WriteImage(char *filename, Image &img) {
	FILE *f_out = fopen(filename, "wb");
	fprintf(f_out, "%s\n%d %d\n%d\n", "P6", img.getWidth(), img.getHeight(), img.getMaxval());
	fwrite(img.getBuffer(), 3*sizeof(unsigned char), img.getWidth()*img.getHeight(), f_out);
	fclose(f_out);
}

/*HalfSize:	the	output	image	should	be	half	the	width	and	height.		Pixel	(i,	j)	in	the
output	should	be	the	same	as	pixel	(2*i,	2*j)	in	the	input.*/

void HalfSize(Image &input, Image &output) {
	int width = input.getWidth();
	int height = input.getHeight();
	int halfheight = input.getHeight()/2;
	int halfwidth = input.getWidth()/2;

	output.ResetSize(halfwidth, halfheight);
	output.setMaxval(input.getMaxval());
	output.setBuffer();
	for(int i=0; i < halfheight; i++) {
		for(int j=0; j < halfwidth; j++) {
			int inputOffset = 3*(2*i*width+2*j);
			int outputOffset = 3*(i*halfwidth+j);
			output.getBuffer()[outputOffset] = input.getBuffer()[inputOffset];
			output.getBuffer()[outputOffset+1] = input.getBuffer()[inputOffset+1];
			output.getBuffer()[outputOffset+2] = input.getBuffer()[inputOffset+2];
		}
	}
}

/*LeftRightCombine:	take	two	input	images	that	have	the	same	height	and	make	a
single	image	where	they	are	combined	left-to-right.		I.e.:	(A)	+	(B)	=	(AB)*/

void LeftRightCombine(Image &leftInput, Image &rightInput, Image &output) {
	int leftwidth = leftInput.getWidth();
	int rightwidth = rightInput.getWidth();
	int height = leftInput.getHeight();
	int doublewidth = leftwidth + rightwidth;

	output.ResetSize(doublewidth, height);
	output.setMaxval(leftInput.getMaxval());
	output.setBuffer();

	for(int i=0; i < leftwidth; i++) {
		for(int j=0; j < height; j++) {
			int inputOffset = 3*(j*leftwidth+i);
			int outputOffset = 3*(j*doublewidth+i);
			output.getBuffer()[outputOffset] = leftInput.getBuffer()[inputOffset];
			output.getBuffer()[outputOffset + 1] = leftInput.getBuffer()[inputOffset + 1];
			output.getBuffer()[outputOffset + 2] = leftInput.getBuffer()[inputOffset + 2];
		}
	}

	for(int i=0; i < rightwidth; i++) {
		for(int j=0; j < height; j++) {
			int inputOffset = 3*(j*rightwidth+i);
			int outputOffset = 3*(j*doublewidth+leftwidth+i);
			output.getBuffer()[outputOffset] = rightInput.getBuffer()[inputOffset];
			output.getBuffer()[outputOffset + 1] = rightInput.getBuffer()[inputOffset + 1];
			output.getBuffer()[outputOffset + 2] = rightInput.getBuffer()[inputOffset + 2];
		}
	}
}

/*TopBottomCombine:	take	two	input	images	that	have	the	same	width	and	make	a
single	image	where	they	are	combined	left-to-right.		I.e.:	(A)	+	(B)	=			(A)
(B)*/

void TopBottomCombine(Image &topInput, Image &bottomInput, Image &output) {
	int width = topInput.getWidth();
	int topheight = topInput.getHeight();
	int bottomheight = bottomInput.getHeight();
	int doubleheight = topheight + bottomheight;

	output.ResetSize(width, doubleheight);
	output.setMaxval(topInput.getMaxval());
	output.setBuffer();

	for(int i=0; i < width; i++) {
		for(int j=0; j < topheight; j++) {
			int inputOffset = 3*(j*width+i);
			int outputOffset = 3*(j*width+i);
			output.getBuffer()[outputOffset] = topInput.getBuffer()[inputOffset];
			output.getBuffer()[outputOffset + 1] = topInput.getBuffer()[inputOffset + 1];
			output.getBuffer()[outputOffset + 2] = topInput.getBuffer()[inputOffset + 2];
		}
	}

	for(int i=0; i < width; i++) {
		for(int j=0; j < bottomheight; j++) {
			int inputOffset = 3*(j*width+i);
			int outputOffset = 3*((j+topheight)*width+i);
			output.getBuffer()[outputOffset] = bottomInput.getBuffer()[inputOffset];
			output.getBuffer()[outputOffset + 1] = bottomInput.getBuffer()[inputOffset + 1];
			output.getBuffer()[outputOffset + 2] = bottomInput.getBuffer()[inputOffset + 2];
		}
	}
}

/*Blend:	take	two	input	images	that	have	the	same	width	and	height	and	blend	them
together.		If	the	“factor”	is	0.8,	then	the	output	image	should	be	80%	image	1	and
20%	image	2.		(This	would	mean	a	“0.8*V1	+	0.2*V2”	summation	for	each	channel.)*/

void Blend(Image &input1, Image &input2, double factor, Image &output) {
	output.ResetSize(input1.getWidth(), input1.getHeight());
	output.setMaxval(input1.getMaxval());
	output.setBuffer();

	for(int i=0; i < output.getWidth(); i++) {
		for(int j=0; j < output.getHeight(); j++) {
			int offset = 3*(j*output.getWidth()+i);
			output.getBuffer()[offset] = input1.getBuffer()[offset]*factor + input2.getBuffer()[offset]*(1-factor);
			output.getBuffer()[offset + 1] = input1.getBuffer()[offset + 1]*factor + input2.getBuffer()[offset+1]*(1-factor);
			output.getBuffer()[offset + 2] = input1.getBuffer()[offset + 2]*factor + input2.getBuffer()[offset+2]*(1-factor);					}
	}
}
