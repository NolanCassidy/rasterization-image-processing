#ifndef PNMWRITER_330
#define PNMWRITER_330

#include <stdio.h>
#include <sink.h>

class PNMwriter : public Sink{
public:
  void Write(char *filename);
};
#endif
