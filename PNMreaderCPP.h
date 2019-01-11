#ifndef PNMREADERCPP_330
#define PNMREADERCPP_330

#include <stdio.h>
#include <source.h>

class PNMreaderCPP : public Source{
  protected:
    char *filename;
  public:
    PNMreaderCPP(char *f);
    ~PNMreaderCPP();
    void Execute();
};
#endif
