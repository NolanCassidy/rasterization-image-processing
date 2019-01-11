#ifndef PNMREADER_330
#define PNMREADER_330

#include <stdio.h>
#include <source.h>

class PNMreader : public Source{
  protected:
    char *filename;
  public:
    PNMreader(char *f);
    ~PNMreader();
    virtual void Execute();
};
#endif
