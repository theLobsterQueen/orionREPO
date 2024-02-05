#ifndef ACTION_H
#define ACTION_H 1

// INCLUDES AND INITIALIZATIONS //

// STANDARD LIBRARY INCLUDES //
#include <LGL.h>

class Action
{
	public :
		// CONSTRUCTOR/DESTRUCTOR ARGUMENTS //
		Action(unsigned inputType, LGLPointFloat2 inputPos)
		{
			type = inputType;
			targetPos = inputPos;
		}

		// PUBLIC ATTRIBUTES //
		unsigned type = 0;
		LGLPointFloat2 targetPos;
};

#endif
