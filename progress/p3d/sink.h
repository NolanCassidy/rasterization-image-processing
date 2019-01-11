#ifndef SINK_330
#define SINK_330

#include <image.h>

class Sink{
  protected:
      Image *input, *input2;
  public:
      void SetInput(Image *input);
      void SetInput2(Image *input2);
};
#endif
