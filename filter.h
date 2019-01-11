#ifndef FILTER_330
#define FILTER_330

#include <stdio.h>
#include <source.h>
#include <sink.h>

class Filter : public Source, public Sink{
};

class Shrinker : public Filter{
  public:
    void Execute();
};

class LRCombine : public Filter
{
  public:
    void Execute();
};

class TBCombine : public Filter{
  public:
  	void Execute();
};

class Blender : public Filter{
  protected:
    double factor;
  public:
    void SetFactor(double f);
  	void Execute();
};
#endif
