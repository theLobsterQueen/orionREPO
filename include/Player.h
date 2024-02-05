#ifndef PLAYER_H
#define PLAYER_H 1

// INCLUDES AND INITIALIZATIONS //

// ORION INCLUDES //
#include <Globals.h>

// STANDARD LIBRARY INCLUDES //
#include <LGL.h>

// FUNCTION DEFINITIONS //

/// <summary> ///
///		This function checks all currently active entities and sees if they
///			collide with input mouse position. If there is a collision, sets
///			the colliding entity as the currently active entity in global
///			context. Note that it returns the first one it detects, should
///			probably rework it.
/// </summary> ///

void SelectEntity(GlobalContainer& globs, LGLPointFloat2 inputMouse);

#endif
