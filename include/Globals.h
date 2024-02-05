#ifndef GLOBAL_H 
#define GLOBAL_H 1

// INCLUDES AND INITIALIZATIONS //

// STANDARD LIBRARY INCLUDES //
#include <LGL.h>
#include <vector>
#include <list>

// CLASS PROTOYPES //
class Entity;
class Bot;
class Scion;

// CLASS DEFINITIONS //

/// <summary> ///
///	This class contains global references for the game, such as entity
///	arrays, current player stats, etc. 
/// </summary> ///

class GlobalContainer
{
	public :
		/// <summary> ///
		///	This field holds a reference to all entities
		///	currently active in the game. If an entity is not in
		///	this field, it will not be rendered or updated.
		/// </summary> ///
		std :: vector<Entity *> entities;
		
		/// <summary> ///
		///		This field points to all bots currently active in the game. If an entity
		///			is not in this field, it will not be considered for bot movement or
		///			detection.
		/// </summary> ///
		std :: vector<Bot *> bots;

		/// <summary> ///
		///		This field points to all scions currently active in the game. If an
		///			entity is not in this field, it will not be checked for bot-scion detection
		///			or updated during the AI step.
		/// </summary> ///
		std :: vector<Scion *> scions;

		/// <summary> ///
		///		This field holds a reference to all currently selected entities, if any. If an
		///			entity is not selected, it will not be given UI draw calls and will not
		///			display its movement path (if any) to the player.
		/// </summary> ///
		std :: vector<Entity *> curEntities;
		
		/// <summary> ///
		///		This lff file holds a reference to the standard text file that is used to
		///			display text.
		/// </summary> ///
		LGLFont * baseFont;

		/// <summary> ///
		///		This lff file holds a reference to all sprites rendered in the game.
		/// </summary> ///
		LGLFont * sprites;
};

#endif
