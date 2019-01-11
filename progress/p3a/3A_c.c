#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  //each pixel is 3 unsigned chars
  unsigned char r;
  unsigned char g;
  unsigned char b;
} Pixel;

typedef struct
{
/* data members go here */
  int width, height;
	unsigned char *buffer;
  int maxval;

} Image;

Image *
ReadImage(char *filename)
{
   // allocate space for image_in
   Image *image = malloc(sizeof(Image));
   FILE *f_in = fopen(filename, "rb");

   //These lines are useful:
   char magicNum[128];
   int  width, height, maxval;
   fscanf(f_in, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval);

   //initialize image and allocate space for pixel data
   image->width = width;
   image->height = height;
   image->buffer = malloc(width * height * sizeof(Pixel));
   image->maxval = maxval;

   //read pixels into buffer
   fread(image->buffer, sizeof(Pixel), width * height, f_in);
   fclose(f_in);

   //image object now containts the specified image format
   return image;
}

void WriteImage(Image *image, char *filename)
{
  FILE *f_out = fopen(filename, "wb");
  //creates file with P6 formatting so it can be written to pnm file
	fprintf(f_out, "%s\n%d %d\n%d\n","P6", image->width, image->height, image->maxval);
	fwrite(image->buffer, sizeof(Pixel), image->width * image->height, f_out);
	fclose(f_out);
}

Image *
YellowDiagonal(Image *input)
{
  //allocate space for image_out
  Image *image = malloc(sizeof(Image));

  //initialize image and allocate space for pixel data
  image->width = input->width;
	image->height = input->height;
  image->buffer = malloc(input->width * input->height * sizeof(Pixel));
	image->maxval = input->maxval;

  //copy n bits which is the amount of pixels from the in image to out image
  char *in = (char *)input->buffer;
  char *out = (char *)image->buffer;
  int n = input->width * input->height * sizeof(Pixel);
  for (int c=0; c<n; c++){
     out[c] = in[c];
  }

  //while loop moves across image left to right
  int i=0;
	while(i<image->width){
      //iterates down until reaching bottom of image
    	if(i==image->height){
    		return image;
    	}
      else{
        //when row=col then set yellow = 255,255,0
        int rc = i*3;
    		image->buffer[(rc*image->width + rc) + 0] = 255;    //Red
    		image->buffer[(rc*image->width + rc) + 1] = 255;    //Blue
    		image->buffer[(rc*image->width + rc) + 2] = 0;      //Green
      }
      i+=1;
	}
}

int main(int argc, char *argv[])
{
   /* Read an image, apply yellow diagonal to it, then write */
	Image *image_in = ReadImage(argv[1]);
  Image *image_out = YellowDiagonal(image_in);
	WriteImage(image_out, argv[2]);

  //allocated memory for 2 image and 2 buffers we need to free
	free(image_in);
  free(image_in->buffer);
	free(image_out);
  free(image_out->buffer);
}
