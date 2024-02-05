#ifndef BOT_H
#define BOT_H 1

// INCLUDES AND INITIALIZATIONS //

// ORION INCLUDES //
#include <Character.h>
#include <Globals.h>
#include <Scion.h>

// STANDARD LIBRARY INCLUDES //
#include <LGL.h>

/// <summary> ///
///	This class represents a controllable "bot" entity. It takes mouse
/// 	input, communicates with the UI to represent its data, and can
///	  accept orders from the player that change its behavior.
/// </summary> ///

class Bot : public Character
{
	public :
		// CONSTRUCTOR/DESTRUCTOR ARGUMENTS //
		Bot
		(
			LGLPointFloat2 inputPos, int inputSize, float inputHealth = 20.0f, 
			float inputSpeed = 100.0f, float inputRange = 125.0f
		) 
			: Character(inputPos, inputSize, inputHealth, inputSpeed)
		{
			// ASSINGS INPUT ATTRIBUTES //
			attackRange = inputRange;

			// OVERWRITES COLOR CODES //
			onColor = LGLColor(0, 255, 0);
			offColor = LGLColor(0, 0, 255);
		}

		// FUNCTION IMPLEMENTATIONS //
		void DrawAttackRange()
		{
			// DRAWS ATTACK RANGE //
			LGLWireRectToFB
			(
				position.x - (attackRange / 2), position.y - (attackRange / 2), 
				attackRange + size, attackRange + size, 
				LGLColor(0, 0, 0)
			); 
		}

		void Update(GlobalContainer& globs, float deltaTime)
		{
			Character :: Update(globs, deltaTime);
			for
			(
				auto scionRef = globs.scions.begin();
				scionRef != globs.scions.end();
				scionRef++
			)

			{
				onColor = LGLColor(0, 255, 0);
				LGLRectFloat attackRangeRect = LGLRectFloat
				(
					position.x - (attackRange / 2), position.y - (attackRange / 2), 
					attackRange + size, attackRange + size
				);
				if((*scionRef) -> GetRect().RectInRect(attackRangeRect) == 1)
					onColor = LGLColor(0, 255, 0, 100);
			}
		}

		// PUBLIC ATTRIBUTES //
		float attackRange;
};

#endif
