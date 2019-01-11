#include <stdio.h>
#include <source.h>
#include <sink.h>
#include <filter.h>

void Shrinker::Execute(){
  int width = input->getWidth();
  int height = input->getHeight();
  int halfheight = input->getHeight()/2;
  int halfwidth = input->getWidth()/2;

  img.ResetSize(halfwidth, halfheight);
  img.setMaxval(input->getMaxval());
  img.setBuffer();
  for(int i=0; i < halfheight; i++) {
    for(int j=0; j < halfwidth; j++) {
      int inputOffset = 3*(2*i*width+2*j);
      int outputOffset = 3*(i*halfwidth+j);
      img.getBuffer()[outputOffset] = input->getBuffer()[inputOffset];
      img.getBuffer()[outputOffset+1] = input->getBuffer()[inputOffset+1];
      img.getBuffer()[outputOffset+2] = input->getBuffer()[inputOffset+2];
    }
  }
}

void LRCombine::Execute(){
  int leftwidth = input->getWidth();
  int rightwidth = input2->getWidth();
  int height = input->getHeight();
  int doublewidth = leftwidth + rightwidth;

  img.ResetSize(doublewidth, height);
  img.setMaxval(input->getMaxval());
  img.setBuffer();

  for(int i=0; i < leftwidth; i++) {
    for(int j=0; j < height; j++) {
      int inputOffset = 3*(j*leftwidth+i);
      int outputOffset = 3*(j*doublewidth+i);
      img.getBuffer()[outputOffset] = input->getBuffer()[inputOffset];
      img.getBuffer()[outputOffset + 1] = input->getBuffer()[inputOffset + 1];
      img.getBuffer()[outputOffset + 2] = input->getBuffer()[inputOffset + 2];
    }
  }

  for(int i=0; i < rightwidth; i++) {
    for(int j=0; j < height; j++) {
      int inputOffset = 3*(j*rightwidth+i);
      int outputOffset = 3*(j*doublewidth+leftwidth+i);
      img.getBuffer()[outputOffset] = input2->getBuffer()[inputOffset];
      img.getBuffer()[outputOffset + 1] = input2->getBuffer()[inputOffset + 1];
      img.getBuffer()[outputOffset + 2] = input2->getBuffer()[inputOffset + 2];
    }
  }
}

void TBCombine::Execute(){
  int width = input->getWidth();
	int topheight = input->getHeight();
	int bottomheight = input2->getHeight();
	int doubleheight = topheight + bottomheight;

	img.ResetSize(width, doubleheight);
	img.setMaxval(input->getMaxval());
	img.setBuffer();

	for(int i=0; i < width; i++) {
		for(int j=0; j < topheight; j++) {
			int inputOffset = 3*(j*width+i);
			int outputOffset = 3*(j*width+i);
			img.getBuffer()[outputOffset] = input->getBuffer()[inputOffset];
			img.getBuffer()[outputOffset + 1] = input->getBuffer()[inputOffset + 1];
			img.getBuffer()[outputOffset + 2] = input->getBuffer()[inputOffset + 2];
		}
	}

	for(int i=0; i < width; i++) {
		for(int j=0; j < bottomheight; j++) {
			int inputOffset = 3*(j*width+i);
			int outputOffset = 3*((j+topheight)*width+i);
			img.getBuffer()[outputOffset] = input2->getBuffer()[inputOffset];
			img.getBuffer()[outputOffset + 1] = input2->getBuffer()[inputOffset + 1];
			img.getBuffer()[outputOffset + 2] = input2->getBuffer()[inputOffset + 2];
		}
	}
}

void Blender::SetFactor(double f){
    factor = f;
}

void Blender::Execute(){
  img.ResetSize(input->getWidth(), input->getHeight());
	img.setMaxval(input->getMaxval());
	img.setBuffer();

	for(int i=0; i < img.getWidth(); i++) {
		for(int j=0; j < img.getHeight(); j++) {
			int offset = 3*(j*img.getWidth()+i);
			img.getBuffer()[offset] = input->getBuffer()[offset]*factor + input2->getBuffer()[offset]*(1-factor);
			img.getBuffer()[offset + 1] = input->getBuffer()[offset + 1]*factor + input2->getBuffer()[offset+1]*(1-factor);
			img.getBuffer()[offset + 2] = input->getBuffer()[offset + 2]*factor + input2->getBuffer()[offset+2]*(1-factor);					}
	}
}
