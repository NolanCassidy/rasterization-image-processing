#ifndef SINK_330
#define SINK_330

#include <image.h>

class Sink{
  protected:
      Image *input, *input2;
  public:
      void SetInput(Image *i){input = i;}
      void SetInput2(Image *i2){input2 = i2;}
};
#endif
