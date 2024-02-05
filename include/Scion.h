#ifndef SCION_H
#define SCION_H 1

// INCLUDES AND INITIALIZATIONS //

// ORION INCLUDES //
#include <Character.h>
#include <Entity.h>

// STANDARD LIBRARY INCLUDES //
#include <LGL.h>

/// <summary> ///
///	This class represents a controllable "bot" entity. It takes mouse
/// 	input, communicates with the UI to represent its data, and can
///	  accept orders from the player that change its behavior.
/// </summary> ///

class Scion : public Character
{
	public :
		// CONSTRUCTOR/DESTRUCTOR ARGUMENTS //
		Scion(LGLPointFloat2 inputPos, int inputSize, float inputSpeed = 100.0f) : 
		  Character(inputPos, inputSize, inputSpeed)
		{
			// OVERWRITES COLOR CODES //
			offColor = LGLColor(255, 0, 0);
			onColor = LGLColor(200, 50, 50);
		}
};

#endif
