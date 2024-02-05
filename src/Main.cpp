/// <summary> ///
///		This serves as an entry point to the game, initializes the graphics
///			library, and switches between different scenes in the game. 
/// </summary> ///

// INCLUDES AND INITIALIZATIONS //

// STANDARD LIBRARY INCLUDES //
#include <iostream>
#include <LGL.h>

// ORION INCLUDES //
#include <Entity.h>
#include <Bot.h>
#include <Scion.h>
#include <Globals.h>
#include <Player.h>
#include <Action.h>

int main()
{
	// INITIALIZES WINDOW AND LGL CONTEXT //
	LGLInit("ORION TEST BUILD", 1366, 768);
	
	// CREATES GLOBAL CONTEXT //
	GlobalContainer globs = GlobalContainer();
	globs.baseFont = new LGLFont("./assets/BASE.lff");
	globs.sprites = new LGLFont("./assets/ORION-SPRITES.lff");

	// CREATES TEST ENTITIES //
	for(int i = 0; i < 10; i++)
	{
		float randFloat = RandFloat(20, 80);
		globs.entities.push_back(new Entity
		(
			LGLPointFloat2(RandFloat(0, 1366), RandFloat(0, 768)),
			RandInt(30, 100) 		
		));

		// FOR EVERY THIRD INSTATIATION, CREATES BOT INSTANCE //
		if(!(i % 3))
		{
			Bot * newBot = new Bot
			(
				LGLPointFloat2(RandFloat(0, 1366), RandFloat(0, 768)),
				RandInt(30, 100), RandFloat(60, 250), RandFloat(75, 125),
				RandInt(75, 200)
			);
			globs.entities.push_back(newBot);
			globs.bots.push_back(newBot);
		}

		// FOR EVERY THIRD THIRD INSTATION, CREATES SCION INSTANCE //
		if(!(i % 9))
		{
			Scion * newScion = new Scion
			(
				LGLPointFloat2(RandFloat(0, 1366), RandFloat(0, 768)),
				RandInt(30, 100), RandFloat(60, 250)
			);
			globs.entities.push_back(newScion);
			globs.scions.push_back(newScion);
		}
	}

	// ATTRIBUTE DECLARATIONS //
	float deltaTime;
	bool lmbPressed = false;
	LGLPointFloat2 mousePos;

	// MAIN GAMEPLAY LOOP //
	while(LGLIsRunning())
	{
		// UPDATES DELTA TIME/MOUSE POSITION //
		deltaTime = LGLGetDeltaTime();
		mousePos = GetMousePos();

		// EVENT HANDLING //
		LGLInputEvent curEvent;
		while(LGLPollEvent(&curEvent))
		{
			// SELECTS AN ENTITY IF ONE IS NOT CURRENTLY SELECTED //
				// IF SHIFT IS HELD DOWN WHILE SELECTING ENTITIES, ADDS //
				// IT TO THE LIST OF CURRENTLY SELECTED ENTITIES //
			if(curEvent.pressedKey == LGL_LMB)
			{
				if(curEvent.pressedDown)
				{
					if(globs.curEntities.size() != 0 and 
						!curEvent.shiftPressed)
					{
						for
						(
							auto entityRef = globs.curEntities.begin();
							entityRef != globs.curEntities.end();
							entityRef++
						)

						{
							(*entityRef) -> IsSelected(false);
						}

						globs.curEntities.clear();
					}

					SelectEntity(globs, mousePos);
				}
			}

			// GIVES ALL CURRENTLY SELECTED ENTITIES ORDERS //
			if((curEvent.pressedKey == LGL_RMB || curEvent.pressedKey == ' ') &&
				globs.curEntities.size() != 0 && curEvent.pressedDown)
			{
				for
				(
					auto curEntity = globs.curEntities.begin();
					curEntity != globs.curEntities.end();
					curEntity++
				)

				{
					(*curEntity) -> AddOrder
					(
						Action
						(
							MOVE_TO, 
							mousePos
						),

						!curEvent.shiftPressed
					);
				}
			}

			if(curEvent.pressedKey == 27)
				LGLQuit();
		}

		// UPDATES ALL ENTITIES //
		for
		(
			auto entityRef = globs.entities.begin();
			entityRef != globs.entities.end();
			entityRef++
		)

		{
			(*entityRef) -> Update(globs, deltaTime);
		}

		// RENDERING PHASE //
		LGLBeginRenderPass(LGLColor(255, 0, 255));
		
		// IF ENTITY IS SLECTED, DRAWS ITS UI ELEMENTS //
		if(globs.curEntities.size() != 0)
		{
			for
			(
				auto entityRef = globs.curEntities.begin();
				entityRef != globs.curEntities.end();
				entityRef++
			)

			{
				(*entityRef) -> DrawUI();

				for
				(
					auto botRef = globs.bots.begin();
					botRef != globs.bots.end();
					botRef++
				)

				{
					(*botRef) -> DrawAttackRange();			
				}
			}
		}

		// (DEBUG) FOR EVERY SCION, DRAWS ITS "GetRect" RESULT //
		for
		(
			auto scionRef = globs.scions.begin();
			scionRef != globs.scions.end();
			scionRef++
		)

		{
			LGLRectFloat tempRect = (*scionRef) -> GetRect();
			LGLWireRectToFB
			  (tempRect.x, tempRect.y, tempRect.w, tempRect.h, LGLColor(0, 0, 0, 255));
		}

		// DRAWS ALL ENTITIES IN LIST //
		for
		(
			auto entityRef = globs.entities.begin(); 
			entityRef != globs.entities.end();
			entityRef++
		)

		{
			(*entityRef) -> Draw(globs);
		}
		
		// PUSHES TO SCREEN AND ENDS RENDER PASS //
		LGLDrawFB();
		LGLEndRenderPass();
	}

	return 0;
}
