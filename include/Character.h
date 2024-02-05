#ifndef CHARACTER_H
#define CHARACTER_H 1

// CONSTANTS //
#define DISTANCE_CUTOFF 10

// INCLUDES AND INITIALIZATIONS //

// STANDARD LIBRARY INCLUDES //
#include <list>
#include <LGL.h>

// ORION INCLUDES //
#include <Entity.h>
#include <Action.h>
#include <Globals.h>

/// <summary> ///
///	This class represents an entity on the map, which uses a list of 
///	behaviors that change its behavior.
/// </summary> ///
class Character : public Entity
{
	public :
		// CONSTRUCTOR/DESTRUCTOR ARGUMENTS //
		Character
		(
			LGLPointFloat2 inputPos, int inputSize, float inputHealth = 20.0f, 
			float inputSpeed = 100.0f
		)
	 	  : Entity(inputPos, inputSize)
		{
			// CLEARS ORDERS ATTRIBUTE //
			orders.clear();
			
			// SETS PUBLIC ATTRIBUTES //
			speed = inputSpeed;

			// SETS COLOR //
			onColor = LGLColor(0, 255, 0);
			offColor = LGLColor(0, 0, 255);		
		}

		// PUBLIC FUNCTIONS //

		
		/// <summary> ///
		///		Adds a new input order class to the list of
		///			order references. 
		/// </summary> ///

		void AddOrder(Action inputOrder, bool setNow)
		{
			if(setNow == true)
				orders.clear();

			orders.push_back(inputOrder); 
		}

		/// <summary> ///
		///	Updates the current state of the entity, typically
		///	using its orders to change its state.
		/// </summary> ///

		void Update(GlobalContainer& globs, float deltaTime)
		{
				Entity :: Update(globs, deltaTime);

				// IF SIZE OF ORDERS IS ZERO, IMMEDIATELY RETURNS //
					// OTHERWISE, BEGINS INTERPRETING FIRST ACTIVE ORDER //
				if(orders.size() == 0)
						return;

				// READS THE CURRENTLY ACTIVE ORDER //
				Action order = (orders.front());
				switch(order.type)
				{
					case MOVE_TO :
					{
						LGLPointFloat2 offsetPosition = 
							LGLPointFloat2(position.x + size / 2, position.y + size / 2);
						float distX = DistFloat(offsetPosition.x, order.targetPos.x); 
						float distY = DistFloat(offsetPosition.y, order.targetPos.y);
						char moveX = 0; char moveY = 0;
						bool isMovingX = true;
						
						if(distX > 1)
						{
							if(offsetPosition.x < order.targetPos.x)
								moveX = 1;
							else if(offsetPosition.x > order.targetPos.x)
								moveX = -1;
						}

						if(distY > 1)
						{
							if(offsetPosition.y < order.targetPos.y)
								moveY = 1;
							else if(offsetPosition.y > order.targetPos.y)
								moveY = -1;
						}
						
						// CHECKS TO SEE IF HAS REACHED TARGET DESTINATION //
						if(DistPointFloat2(LGLPointFloat2(offsetPosition.x, offsetPosition.y),
							order.targetPos) < 6.0f)
						{
							orders.pop_front();
							return;
						}
						
						// MOVES CHARACTER //
						float weightX = (distX / distY);
						if(weightX > 1)
							weightX = 1;
						float weightY = (distY / distX);
						if(weightY > 1)
							weightY = 1;
						position.x += (speed * moveX * weightX) * deltaTime; 
						position.y += (speed * moveY * weightY) * deltaTime;
					}
					break;

					default :
					{
						std :: cout << "ERROR, PROCESSING INVALID ORDER!"
							<< std :: endl << "\t" << "ORDER TYPE: "
							<< order.type << std :: endl;
					}
					break;
				}
		}

		void DrawUI()
		{
			// VARIABLE INITIALIZATIONS //
			LGLPointFloat2 oldPosition =
				LGLPointFloat2(position.x + (size / 2), position.y + (size / 2));

			// SINCE CHARACTER AND CAN MOVE, ALSO DISPLAYS CURRENT MOVE //
				// PATH, IF SUCH EXISTS. ALSO DISPLAYS ATTACK RANGE //

			// IF NO ACTIVE ORDER, SKIPS THIS AREA //
			if(orders.size() != 0)
			{
				for
				(
					auto orderRef = orders.begin();
					orderRef != orders.end();
					orderRef++
				)
				
				{
					if((*orderRef).type != MOVE_TO)
						continue;

					Action order = *orderRef;
					LGLLineToFB
					(
						oldPosition.x, 
						oldPosition.y,
						order.targetPos.x, 
						order.targetPos.y, 
						LGLColor(0, 255, 0)
					);

					LGLWireRectToFB
					(
						order.targetPos.x - 15, 
						order.targetPos.y - 15,
						30, 30, LGLColor(0, 255, 0)
					);

					// UPDATES THE OLD POSITION WITH THIS MOVE TARGET //
					oldPosition = LGLPointFloat2
					  (order.targetPos.x, order.targetPos.y);
				}
			}

		}

		// PUBLIC ATTRIBUTES //
		float speed;
		float health;

	private :
		// PRIVATE ATTRIBUTES //
		std :: list<Action> orders;	
};

#endif
