// INCLUDES AND INITIALIZATIONS //

// STANDARD LIBRARY INCLUDES //
#include <LGL.h>

// ORION INCLUDES //
#include <Player.h>
#include <Globals.h>
#include <Entity.h>

// FUNCTION IMPLEMENTATIONS //
void SelectEntity(GlobalContainer& globs, LGLPointFloat2 inputMouse)
{
	// VARIABLE INITIALIZATION //
	Entity * newEntity = nullptr;

	// ADDS ALL ENTITIES THAT HAD JUST COLLIDED WITH THE MOUSE //
	for
	(
		auto entityRef = globs.entities.begin();
		entityRef != globs.entities.end();
		entityRef++
	)

	{
		if((*entityRef) -> PointInEntity(inputMouse))
			newEntity = *entityRef;
	}

	// IF NO UNIT WAS SELECTED, RETURNS //
	if(newEntity == nullptr)
		return;

	// CHECKS TO SEE IF THE ENTITY IS CURRENTLY SELECTED //
	bool addEntity = true;
	for
	(
		auto entityRef = globs.curEntities.begin();
		entityRef != globs.curEntities.end();
		entityRef++
	)

	{
		if(*entityRef == newEntity)
			addEntity = false;
	}

	// IF NOT ALREADY SELECTED, SELECTS THE ENTITY //
	if(addEntity)
	{
		globs.curEntities.push_back(newEntity);
		newEntity -> IsSelected(true);
	}

	// RETURNS //
	return;
}


