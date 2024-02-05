#ifndef ENTITY_H
#define ENTITY_H 1

// INCLUDES AND INITIALIZATIONS //

// STANDARD LIBRARY INCLUDES //
#include <LGL.h>
#include <iostream>

// ORION INCLUDES //
#include <Action.h>
#include <Globals.h>
#include <ImportantConstants.h>

/// <summary> ///
///	This class is the parent class to all selectable objects that exist 
///	within the space of the game world. Stations, unresearched 
///	anomalies, bots, and Star-Scions (among others) all fall under 
///	this category.
/// </summary> ///

class Entity
{
	public :
		// PUBLIC CONSTRUCTOR/DESTRUCTOR ARGUMENTS //
		Entity(LGLPointFloat2 inputPos, int inputSize)
		{
			// READS RECT FROM INPUT AND SETS SELECTION STATE //
				// TO FALSE //
			position = inputPos;
			size = inputSize;
			isSelected = false;

			// SETS THE COLOR VALUE FOR THE BASE ENTITY //
				// (NOTE: IS TYPICALLY OVERWRITTEN BY //
				// INHERITING OBJECTS) //
			onColor = LGLColor(255, 255, 0);
			offColor = LGLColor(0, 255, 255);
		}
		
		// PUBLIC FUNCTIONS //

		// DRAWS THE ENTITY TO THE FRAMEBUFFER //
		void Draw(GlobalContainer& globs)
		{
			LGLColor bodyColor = offColor;
			if(isSelected)
				bodyColor = onColor;
			
			// DRAWS A HITBOX, IF NECESARRY //
			if(DEBUG_MODE && SHOW_HITBOXES)
				LGLWireRectToFB(position.x, position.y, size, size, LGLColor(0, 255, 0));

			globs.sprites -> DrawChar
			(
				position.x, position.y,
				bodyColor, BOT_INTERCEPTOR,
				size
			);
		}
	
		// CHECKS TO SEE IF A POINT COLLIDES WITH THIS ENTITY //
		bool PointInEntity(LGLPointFloat2 inputPoint)
		{
			LGLRectFloat tempRect = LGLRectFloat(position.x, position.y, size, size);
			return tempRect.PointInRect(inputPoint); 
		}

		// SET/GET FIELD FUNCTIONS //	
		void IsSelected(bool inputSelect)
			{ isSelected = inputSelect; }
		
		LGLRectFloat GetRect()
		{
			return LGLRectFloat(position.x, position.y, size, size);
		}

		// VIRTUAL FUNCTIONS //

		/// <summary> ///
		///		Adds a new input order class to the list of
		///		order references. 
		/// </summary> ///

		virtual void AddOrder(Action inputOrder, bool setNow)
		{ 
			// EMPTY VIRTUAL FUNCTION // 
		}

		/// <summary> ///
		///	Updates the current state of the entity, typically
		///	using its orders to change its state.
		/// </summary> ///

		virtual void Update(GlobalContainer& globs, float deltaTime)
		{
			// EMPTY VIRTUAL FUNCTION //		
		}	
		
		/// <summary> ///
		///		Draws the entity's stats through the UI, and (if selected)
		///		displays its current move orders and view range on the
		///		screen.
		/// </summary> ///

		virtual void DrawUI()
		{
			// EMPTY VIRTUAL FUNCTION //
			// (TODO) DISPLAY STATS TO UI //
		}

		/// <summary> ///
		///		Draws a circle detailing the attack range of the entity.
		/// </summary> ///
		virtual void DrawAttackRange()
		{
			// EMPTY VIRTUAL FUNCTION //
		}

		// PUBLIC ATTRIBUTES //
		LGLPointFloat2 position;
		int size;

	protected :
		// PRIVATE ATTRIBUTES //
		LGLColor onColor;
		LGLColor offColor;
		bool isSelected;
};

#endif
