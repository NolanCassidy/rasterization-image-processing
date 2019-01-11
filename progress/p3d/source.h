#ifndef SOURCE_330
#define SOURCE_330

#include <stdlib.h>
#include <string.h>
#include <image.h>

class Source{
	protected:
		Image  img;
	public:
    Image * GetOutput() {return &img;}
		virtual void Execute();
};
#endif
