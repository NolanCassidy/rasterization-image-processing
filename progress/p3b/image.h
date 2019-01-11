
#ifndef IMAGE_330
#define IMAGE_330
#include <stdlib.h>
#include <string.h>

class Image {
	private:
		int height, width, maxval;
		unsigned char *buffer;
	public:
		Image(void);
		Image(int height, int  weight, int maxval, unsigned char *buffer);
		Image(const Image &img);
		void ResetSize(int w, int h);
		void setMaxval(int maxval);
		void setBuffer();
		int getWidth();
		int getHeight();
		int getMaxval();
    unsigned char* getBuffer();
};
#endif
