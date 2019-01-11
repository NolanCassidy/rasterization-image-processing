#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <image.h>

//constructors	(default,	parameterized,	and	copy	constructor)
Image::Image(void) {
	width = 0;
	height = 0;
	maxval = 0;
	buffer = NULL;
}

Image::Image(int w, int h, int m, unsigned char *b) {
	width = w;
	height = h;
	maxval = m;
	buffer = b;
}

//copy	constructor	should	allocate new	memory	for	that	Image’s	pixel	buffer
Image::Image(const Image &img) {
	width = img.width;
	height = img.height;
	maxval = img.maxval;
	buffer = (unsigned char *) malloc(3*width*height);
}

void Image::ResetSize(int w, int h) {
	width = w;
	height = h;
}

void Image::setMaxval(int m) {
		maxval = m;
}

void Image::setBuffer() {
		buffer = (unsigned char *) malloc(3*width*height);
}

int Image::getWidth() {
	return width;
}

int Image::getHeight() {
	return height;
}

int Image::getMaxval() {
	return maxval;
}

unsigned char* Image::getBuffer() {
	return buffer;
}
