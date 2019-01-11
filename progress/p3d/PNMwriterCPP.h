#ifndef PNMWRITERCPP_330
#define PNMWRITERCPP_330

#include <stdio.h>
#include <sink.h>

class PNMwriterCPP : public Sink{
  public:
    void Write(char *filename);
};
#endif
