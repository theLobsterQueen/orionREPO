#ifndef LGL_H
#define LGL_H 1

// HOW MANY PARTICLES A SINGLE PARTICLE EMITTER CAN HOLD AT A TIME //
#define MAX_PARTICLES 		512

// DEFINES FOR THE DIFFERENT TYPES OF PARTICLES THAT CAN BE DRAWN //
#define PARTICLE_WIRE_RECT	2
#define PARTICLE_RECT		3
#define PARTICLE_CIRCLE		4


#include <iostream>

/// <summary> ///
///	This class contains two non-floating point values
///	referring to a position in space.
/// </summary> ///
class LGLPointInt2
{
	public :
		// CONSTRUCTOR/DESTRUCTOR ARGUMENTS //

		// DEFAULT CONSTRUCTOR //
		LGLPointInt2() { return; }

		// PARAMETERIZED CONSTRUCTOR //
		LGLPointInt2(int startX, int startY)
		{
			x = startX;
			y = startY;
		}
		
		// PUBLIC FUNCTIONS //
		void SetPoint(int inputX, int inputY)
		{
			x = inputX;
			y = inputY;
		}

		// OPERATOR OVERLOADS //
		LGLPointInt2 operator +(LGLPointInt2 other)
		{
			return LGLPointInt2(x + other.x, y + other.y);
		}

		LGLPointInt2 operator -(LGLPointInt2 other)
		{
			return LGLPointInt2(x - other.x, y - other.y);
		}

		LGLPointInt2 operator +=(LGLPointInt2 other)
		{ 
			*this = (*this) + other; 
			return *this;
		}

		LGLPointInt2 operator -=(LGLPointInt2 other)
		{ 
			*this = (*this) - other; 
			return *this;
		}
		
		LGLPointInt2 operator *(int scalar)
			{ return LGLPointInt2(x * scalar, y * scalar); }

		LGLPointInt2 operator *(float scalar)
			{ return LGLPointInt2(x * scalar, y * scalar); }
		
		LGLPointInt2 operator *(LGLPointInt2 other)
		{
			// CREATES NEW POINT TO MODIFY AND RETURN //
			LGLPointInt2 newPoint = *this;
			newPoint.x *= other.x;
			newPoint.y *= other.y;
			return newPoint;
		}

		LGLPointInt2 operator *=(LGLPointInt2 other)
		{
			return (*this) = (*this) * other;
		}
	
		LGLPointInt2 operator /(LGLPointInt2 other)
		{
			return LGLPointInt2(x / other.x, y / other.y);
		}

		LGLPointInt2 operator /(int scalar)
			{ return LGLPointInt2(x / scalar, y / scalar); }

		LGLPointInt2 operator /(float scalar)
			{ return LGLPointInt2(x / scalar, y / scalar); }

		LGLPointInt2 operator /=(LGLPointInt2 other)
			{ return (*this) / other; }

		friend std :: ostream& operator <<
		  (std :: ostream& out, const LGLPointInt2& self)
		{
			out << "(" << self.x << ", " << self.y << ")";
			return out;
		}

		// PUBLIC ATTRIBUTES //
		int x;
		int y;
};

/// <summary> ///
///	This class contains two floating point values
///	referring to a position in space.
/// </summary> ///
class LGLPointFloat2
{
	public :
		// CONSTRUCTOR/DESTRUCTOR ARGUMENTS //
		
		// DEFAULT CONSTRUCTOR //
		LGLPointFloat2() { return; }

		// PARAMATERIZED CONSTRUCTOR //
		LGLPointFloat2(float startX, float startY)
		{
			x = startX;
			y = startY;
		}
		
		// CAST FROM INT POINT CONSTRUCTOR //
		LGLPointFloat2(LGLPointInt2 inputPoint)
		{
			x = inputPoint.x;
			y = inputPoint.y;
		}

		// PUBLIC FUNCTIONS //
		void SetPoint(float inputX, float inputY)
		{
			x = inputX;
			y = inputY;
		}
		
		// OPERATOR OVERLOADS //
		bool operator ==(LGLPointFloat2 other)
		{
			LGLPointFloat2 self = *this;

			if(self.x != other.x || self.y != other.y)
				return false;

			else
				return true;
		}

		bool operator !=(LGLPointFloat2 other)
			{ return !(*this == other); }

		LGLPointFloat2 operator +(LGLPointFloat2 other)
		{
			return LGLPointFloat2(x + other.x, y + other.y);
		}

		LGLPointFloat2 operator -(LGLPointFloat2 other)
		{
			return LGLPointFloat2(x - other.x, y - other.y);
		}

		LGLPointFloat2 operator +=(LGLPointFloat2 other)
		{ 
			*this = (*this) + other; 
			return *this;
		}

		LGLPointFloat2 operator -=(LGLPointFloat2 other)
		{ 
			*this = (*this) - other; 
			return *this;
		}

		LGLPointFloat2 operator *(int scalar)
			{ return LGLPointFloat2(x * scalar, y * scalar); }

		LGLPointFloat2 operator *(float scalar)
			{ return LGLPointFloat2(x * scalar, y * scalar); }
		
		LGLPointFloat2 operator *(LGLPointFloat2 other)
		{
			// CREATES NEW POINT TO MODIFY AND RETURN //
			LGLPointFloat2 newPoint = *this;
			newPoint.x *= other.x;
			newPoint.y *= other.y;
			return newPoint;
		}

		LGLPointFloat2 operator *=(LGLPointFloat2 other)
		{
			return (*this) = (*this) * other;
		}

		LGLPointFloat2 operator /(int scalar)
			{ return LGLPointFloat2(x / scalar, y / scalar); }

		LGLPointFloat2 operator /(float scalar)
			{ return LGLPointFloat2(x / scalar, y / scalar); }

		LGLPointFloat2 operator /(LGLPointFloat2 other)
		{
			return LGLPointFloat2(x / other.x, y / other.y);
		}

		LGLPointFloat2 operator /=(LGLPointFloat2 other)
			{ return (*this) / other; }

		friend std :: ostream& operator <<
		  (std :: ostream& out, const LGLPointFloat2& self)
		{
			out << "(" << self.x << ", " << self.y << ")";
			return out;
		}

		// PUBLIC ATTRIBUTES //
		float x;
		float y;
};

/// <summary> ///
///	Returns a point value with its x and y values bounded between the
///	two input points.
/// </summary> ///
LGLPointInt2 RandomPointInt(LGLPointInt2 pointA, LGLPointInt2 pointB);
LGLPointFloat2 RandomPointFloat(LGLPointFloat2 pointA, LGLPointFloat2 pointB);


/// <summary> ///
///	Defines color class.
/// </summary> ///
class LGLColor
{
	public :
		// CONSTRUCTOR/DESTRUCTOR ARGUMENTS //
		
		// DEFAULT CONSTRUCTOR //
		LGLColor() { return; }

		// PARAMETERIZED CONSTRUCTOR //
		LGLColor(int inputR, int inputG, int inputB, int inputA=255)
		{
			r = inputR;
			g = inputG;
			b = inputB;
			a = inputA;
		}

		unsigned char r, g, b, a;
};


// INCLUDES AND INITIALIZATIONS //
#include <ctime>
#include <cstdlib>
#include <iostream>

/// <summary> ///
///	Initializes the utilities library, mostly by seeding random.
/// </summary> ///
void MathInit();

/// <sumary> ///
///	This function returns a random value from the range of
///	[inputLow, inputHigh).
/// </summary> ///
int RandInt(int inputLow, int inputHigh);
float RandFloat(float inputLow, float inputHigh);
LGLPointInt2 RandInt2
  (LGLPointInt2 inputLow, LGLPointInt2 inputHigh);
LGLPointFloat2 RandFloat2
  (LGLPointFloat2 inputLow, LGLPointFloat2 inputHigh);

/// <summary> ///
///	This function returns a value linearly interpolated between two
///	different values.
/// </summary> ///
float LerpUChar(unsigned char inputLow, unsigned char inputHigh, float t);
int LerpInt(int inputLow, int inputHigh, float t);
float LerpFloat(float inputLow, float inputHigh, float t);

/// <summary> ///
///		This function returns a boolean describing whether or not the two
///		objects are within the distance specified.
/// </summary> ///
float DistFloat(float v1, float v2);
float DistPointFloat2(LGLPointFloat2 v1, LGLPointFloat2 v2);


// PROTOTYPE STRUCTS //
struct LGLColor;

// FUNCTION PROTOTYPES //

/// <summary> ///
///	Pushes a single pixel to its coordinate in the framebuffer.
/// </summary> ///
/// <param name="posX">
///	The X-coordinate in pixels of the pixel being pushed to the
///	framebuffer.
/// </param>
/// <param name="posY">
///	The Y-coordinate in pixels of the pixel being pushed to the
///	framebuffer.
/// </param>
// <param name="pixColo">
///	The color of the pixel being pushed to the framebuffer.
/// </param>
void LGLPixelToFB
  (int posX, int posY, struct LGLColor pixColor);

/// <summary> ///
///	Draws a line from one position to another.
/// </summary> ///
void LGLLineToFB

// FUNCTION PARAMETERS //
(
	float startX, float startY, 
	float endX, float endY, 
	class LGLColor lineColor
);

/// <summary> ///
///	Draws a rect starting at the top left and drawing to the right,
///	which each iteration drawing downards through a column the size of
///	the rect's height.
/// </summary> ///
void LGLRectToFB
(
	int posX, int posY, float width, 
	float height, class LGLColor rectColor,
	float widthness = 1
);

/// <summary> ///
///		Draws a circle to the framebuffer.
/// </summary> ///
void LGLCircleToFB
(
	float posX, float posY, 
	float inputRadius,
	class LGLColor inputColor
);

/// <summary> ///
///	Draws wireframe rect.
/// </summary> ///
void LGLWireRectToFB

// PARAMETERS //
(
	int posX, int posY, float width, float height, 
	LGLColor rectColor
);

/// <summary> ///
///	Immediately clears the framebuffer to an input color.
/// </summary> ///
void LGLClearFB(struct LGLColor clearColor);

/// <summary> ///
/// 	Begins a render pass and clears the render target.
/// </summary> ///
void LGLBeginRenderPass(struct LGLColor pixColor);

/// <summary> ///
///	Ends render pass and pushes new framebuffer data to texture object.
/// </summary> ///
void LGLEndRenderPass();

/// <summary> ///
/// 	Presents the current state of the framebuffer to the screen.
/// </summary> ///
void LGLDrawFB();


/// <summary> ///
///	Returns an LGL point 2D int instance referencing the current
///	mouse position.
/// </summary> ///
class LGLPointInt2 GetMousePos();


#include <SDL2/SDL.h>


// PRE-PROCESSER DIRECTIVES //
#define LGL_LMB 0
#define LGL_RMB 1
#define LGL_MMB 2

// STRUCT DEFINITIONS //
class LGLInputEvent
{
	public :
		// BOOLEAN DESCRIBING WHETHER EVENT IS MOUSE-BASED OR NOT //
		unsigned char isMouseInput;

		// DISPLAYS KEY OF INTEREST AND WHETHER IT WAS PRESSED 
			// DOWN OR UNPRESSED // 
		unsigned char pressedKey;
		unsigned char pressedDown;
		
		// LIST STATE OF MODIFIERS //
		unsigned char shiftPressed; 
		unsigned char altPressed;
		unsigned char ctrlPressed;

		// DESCRIBES STATE OF EVENT STRUCT //
		unsigned char processed;
};

// FUNCTION DEFINITIONS //

/// <summary> ///
/// 	Checks SDL input and adds any new inputs to input list to
/// 	be processed.
/// </summary> ///
void LGLCheckInput();

/// <summary> ///
///	Attempts to set an SDL_EVENT as the next event to process in
///	the LGL engine. If the currently focused event has not been processed
///	yet, pushes the new input event back onto the SDL event stack.
/// </summary> ///
void LGLFocusEvent(SDL_Event * inputSDLEvent, LGLInputEvent inputLGLEvent);


// CLASS PROTOTYPES //
class LGLParticleEmitter;

#include <SDL2/SDL.h>
#include <vector>

/// <summary> ///
/// 	Class listing persistent SDL references and values.
/// </summary> ///
class LGLContext
{
	public :
		// HOLDS REFERENCES TO THE SDL INSTANCE'S WINDOW AND RENDERER //
		SDL_Window * winRef;
		SDL_Renderer * rendRef;
		
		// HOLDS WINDOW WIDTH AND HEIGHT //
		unsigned int winWidth;
		unsigned int winHeight;
		
		// HOLDS A DYNAMICALLY ALLOCATED VECTOR OF PARTICLE //
			// EMITTER INSTANCES //
		std :: vector<LGLParticleEmitter *> particleRef;

		// HOLDS REFERENCE TO THE SURFACE USED BY LGL'S FRAMEBUFFER //
			// FUNCTIONS //
		SDL_Texture * FBRef;
		SDL_PixelFormat * FBFormatRef;
		void * FBPixelRef;
		int FBPitch;
		
		// HOLDS REFERENCE TO DEFAULT PIXEL FORMAT //
		SDL_PixelFormat * FBPixelFormRef;

		// HOLDS REFERENCE TO CURRENT GAME STATE //
		unsigned char isRunning;
		
		// HOLDS DATA FOR TIME-RELATED VARIABLES //
		double oldTime;
		double deltaTime;

		// HOLDS REFERENCE TO ALL KEYS ALREADY PRESSED //
		char pressedKeys[256];
};


/// <summary> ///
///	This class contains four non-floating point values
///	referring to a box bounded in space by those four values.
/// </summary> ///
class LGLRectInt
{
	public :
		// CONSTRUCTOR/DESTRUCTOR ARGUMENTS //

		// DEFAULT CONSTRUCTOR //
		LGLRectInt() { }

		// PARAMETERIZED CONSTRUCTOR //
		LGLRectInt
		  (int startX, int startY, int startWidth, int startHeight)
		{
			x = startX;
			y = startY;
			w = startWidth;
			h = startHeight;
		}
		
		// PUBLIC FUNCTIONS //
		char PointInRect(const LGLPointInt2& inputPoint)
		{
			if((inputPoint.x > x && inputPoint.x < x + w) &&
			  	inputPoint.y > y && inputPoint.y < y + h)
			{
				return 1;
			}
			
			else
				return 0;
		}
		
		char RectInRect(const LGLRectInt& inputRect)
		{
			if(x + w >= inputRect.x && x <= inputRect.x + inputRect.w &&
			  y + h >= inputRect.y && y <= inputRect.y + inputRect.h) 
			{    
				return true;
			}

			else
				return false;		
		}
	
		// OPERATOR OVERLOADS //
		friend bool operator==
			(const LGLRectInt& self, const LGLRectInt& other)
		{
			return (self.x == other.x && self.y == other.y &&
				self.w == other.w && self.h == other.h);
		}

		friend bool operator!=
			(const LGLRectInt& self, const LGLRectInt& other)
		{
			return !(self == other);
		}
		
		friend std :: ostream& operator <<
			(std :: ostream& out, const LGLRectInt& self)
		{
			out << "(" << self.x << ", " << self.y << ", " << self.w << ", " 
				<< self.h << ")";
			return out;
		}

		// PUBLIC ATTRIBUTES //
		int x;
		int y;
		int w;
		int h;
};

/// <summary> ///
///	This class contains four floating point values
///	referring to a box bounded in space by those four values.
/// </summary> ///
class LGLRectFloat
{
	public :
		// CONSTRUCTOR/DESTRUCTOR ARGUMENTS //
		
		// DEFAULT CONSTRUCTOR //
		LGLRectFloat() { }

		// PARAMATERIZED CONSTRUCTOR //
		LGLRectFloat

		// PARAMETERS //
		(
			float startX, float startY, 
			float startWidth, float startHeight
		)
	

		// FUNCTION //
		{
			x = startX;
			y = startY;
			w = startWidth;
			h = startHeight;
		}
		
		// PUBLIC FUNCTIONS //
		char PointInRect(const LGLPointFloat2& inputPoint)
		{
			if((inputPoint.x >= x && inputPoint.x <= x + w) &&
			  	inputPoint.y >= y && inputPoint.y <= y + h)
			{
				return 1;
			}
			
			else
				return 0;
		}

		char RectInRect(const LGLRectFloat& inputRect)
		{
			if(x + w >= inputRect.x && x <= inputRect.x + inputRect.w &&
			  y + h >= inputRect.y && y <= inputRect.y + inputRect.h) 
			{    
				return true;
			}

			else
				return false;
		}
		
		// OPERATOR OVERLOADS //
		friend bool operator==
			(const LGLRectFloat& self, const LGLRectFloat& other)
		{
			return (self.x == other.x && self.y == other.y &&
				self.w == other.w && self.h == other.h);
		}

		friend bool operator!=
			(const LGLRectFloat& self, const LGLRectFloat& other)
		{
			return !(self == other);
		}

		friend std :: ostream& operator <<
			(std :: ostream& out, const LGLRectFloat& self)
		{
			out << "(" << self.x << ", " << self.y << ", " << self.w << ", " 
				<< self.h << ")";
			return out;
		}

		// PUBLIC ATTRIBUTES //
		float x;
		float y;
		float w;
		float h;
};


// INCLUDES AND INITIALIZATIONS //
#include <vector>

/// <summary> ///
///	Simple class that holds the position and life value of a particle.
/// </summary> ///
class LGLParticle
{
	public :
		// PUBLIC CONSTRUCTOR/DESTRUCTOR ARGUMENTS //
		
		// DEFAULT CONSTRUCTOR //
		LGLParticle() 
		{ 
			life = -1;
			return; 
		}

		// PARAMETERIZED CONSTRUCTOR //
		LGLParticle
		(
			LGLPointFloat2 inputPos, LGLPointFloat2 inputVelocity, 
			float inputLife
		)

		{
			position = inputPos;
			velocity = inputVelocity;
			life = inputLife;
		}
		
		// OPERATOR OVERLOADS //
		bool operator ==(LGLParticle other)
		{
			if(other.life != life || other.velocity != velocity
				|| other.position != position)
				return false;

			else
				return true;
		}

		// PUBLIC ATTRIBUTES //
		LGLPointFloat2 position;
		LGLPointFloat2 velocity;
		float life;
};

/// <summary> ///
///	This file holds classes which emit and update particles.
/// </summary> ///
class LGLParticleEmitter
{
	public :
		// CONSTRUCTOR/DESTRUCTOR ARGUMENTS //

		// PARAMATERIZED CONSTRUCTOR //
		LGLParticleEmitter
		
		// PARAMETERS //
		(
			LGLPointFloat2 inputPos, LGLPointFloat2 inputPosOffset,
			LGLPointFloat2 inputVelocLow,
			LGLPointFloat2 inputVelocHigh, 
			LGLPointFloat2 inputGravity, LGLColor inputColor, 
			float inputLifeTime, float inputSpawnTime,
			int inputParticleSize, int inputParticleType,
			float inputParticleWidthness = 1.0f,
			bool spawnOnceInput = false, int spawnCountInput = 0
		)

		// FUNCTION //
		{
			// SETS INITIAL VALUES BASED OFF OF PARAMETER INPUT //
			position = inputPos;
			positionOffset = inputPosOffset;
			velocityLow = 
			  LGLPointFloat2(inputVelocLow.x, -inputVelocLow.y);
			velocityHigh = 
			  LGLPointFloat2(inputVelocHigh.x, -inputVelocHigh.y);
			gravity = 
			  LGLPointFloat2(inputGravity.x, -inputGravity.y);
			color = inputColor;
			lifeTime = inputLifeTime;
			spawnTimeMax = inputSpawnTime;
			spawnOnce = spawnOnceInput;
			spawnCount = spawnCountInput;
			particleSize = inputParticleSize;
			particleType = inputParticleType;
			particleWidthness = inputParticleWidthness;

			// RESETS TICKERS AND COUNTERS //
			spawnTime = 0;
			particleCount = 0;
		}

		// PUBLIC FUNCTIONS //

		/// <summary> ///
		///	Updates the position and current life value of all
		///	active particles.
		/// </summary> ///
		/// <return> ///
		///	The return boolean states whether to destroy
		///	this particle or not. If it is set to true, the
		///	engine will queue this particle emitter for 
		///	destruction after the update loop.
		/// </return> ///
		bool Update(float deltaTime)
		{
			// VARIABLE INITIALIZATION //
			bool willDestroy = false;

			// DECREMENTS SPAWN TIME. IF SPAWN TIME DROPS BELOW //
				// ZERO, SPAWNS NEW PARTICLE //
			spawnTime -= deltaTime;
			if(spawnTime <= 0)
			{
				spawnTime = spawnTimeMax;
				bool willSpawn = true;

				if(spawnOnce && spawnCount == 0)
					willSpawn = false;
				if(particleCount == MAX_PARTICLES)
					willSpawn = false;

				while(willSpawn)
				{
					LGLPointFloat2 newPosition = RandFloat2
					(
						position - positionOffset,
						position + positionOffset
					);

					LGLPointFloat2 newVelocity = RandFloat2
					  (velocityLow, velocityHigh);

					AddParticle
					(
						LGLParticle
						(
							newPosition, 
							newVelocity,
							lifeTime
						)
					);

					if(spawnTime > 0 || 
				 	  particleCount == MAX_PARTICLES ||
					  spawnOnce && spawnCount == 0)
					{
						willSpawn = false;
					}
				}
			}

			int curCount = particleCount;
			for(int i = 0; i < MAX_PARTICLES && curCount > 0; i++)
			{
				// SKIPS OVER NULL PARTICLES //
				if(particles[i].life == -1)
					continue;

				// FINDS THE CUR PARTICLE //
				LGLParticle curParticle = particles[i];
				curCount--;
				
				// DECREMENTS LIFE. IF LIFE DROPS BELOW ZERO //
					// REMOVES PARTICLE //
				curParticle.life -= deltaTime;
				if(curParticle.life <= 0)
				{
					particleCount--;
					particles[i] = LGLParticle();

					if(spawnOnce && spawnCount == 0 &&
					  particleCount == 0)
					{
						willDestroy = true;
					}

					continue;
				}
				
				// SUBTRACTS THE VELOCITTY OF OLD PARTICLES //
					// BY GRAVITY //
				curParticle.velocity -= gravity * deltaTime;
				
				// ADDS CURRENT VELOCITY TO CURRENT //
					// POSITION //
				curParticle.position += 
					(curParticle.velocity * deltaTime);
				
				// APPLIES DATA TO PARTICLE //
				particles[i] = curParticle;
			}

			return willDestroy;
		}

		/// <summary> ///
		///	Draws all particles.
		/// </summary> ///
		void Draw()
		{
			int curCount = particleCount;
			for(int i = 0; i < MAX_PARTICLES && curCount > 0; i++)
			{
				// ENSURES THIS IS NOT A NULL PARTICLE //
				if(particles[i].life == -1)
					continue;

				// FINDS PARTICLE //
				LGLParticle curPart = particles[i];
				curCount--;

				// DRAWS A CIRCLE CENTERED AT ITS CURRENT //
					// LOCATION //
				LGLColor partColor = color;
				partColor.a = LerpUChar
				  (0, 255, curPart.life / lifeTime);

				// INITIALIZES VARIABLES THAT MAY BE //
					// USED IN SWITCH CASE //
				LGLPointInt2 N;
				LGLPointInt2 S;
				LGLPointInt2 W;
				LGLPointInt2 E;

				// DRAWS PARTICLE BASED OFF TPYE AND SIZE //
				switch(particleType)
				{
					case PARTICLE_RECT :
						LGLRectToFB
						(
							curPart.position.x -
							  particleSize / 2,
							curPart.position.y -
							  particleSize / 2,
							particleSize,
							particleSize,
							partColor,
							particleWidthness
						);
					break;

					case PARTICLE_WIRE_RECT :
						LGLWireRectToFB
						(
							curPart.position.x -
							  particleSize / 2,
							curPart.position.y -
							  particleSize/2,
							particleSize,
							particleSize,
							partColor
						);
					break;

					case PARTICLE_CIRCLE :
						LGLCircleToFB
						(
							curPart.position.x,
							curPart.position.y,
							particleSize,
							partColor
						);
					break;

					default :
						std :: cout << "ERROR! THERE "
							<< "WAS AN INVALID "
							<< "PARTICLE TPYE "
							<< "FIELD!"
							<< std :: endl;
					break;
				}

			}
		}
		
		// ADDS A PARTICLE TO THE ARRAY //
		void AddParticle(LGLParticle inputParticle)
		{
			for(int i = 0; i < MAX_PARTICLES; i++)
			{
				if(particles[i].life == -1)
				{
					particles[i] = inputParticle;
					particleCount++;
					if(spawnOnce)
						spawnCount--;
					break;
				}
			}
		}

		// PUBLIC ATTRIBUTES //
		LGLPointFloat2 position;
		LGLPointFloat2 positionOffset;
		LGLPointFloat2 gravity;
		LGLPointFloat2 velocityLow;
		LGLPointFloat2 velocityHigh;
		LGLColor color;
		float lifeTime;
		float spawnTime;
		float spawnTimeMax;
		float particleWidthness;
		int particleCount;
		int particleSize;
		int particleType;
		bool spawnOnce;
		int spawnCount;
		LGLParticle  particles[MAX_PARTICLES];
};

// FUNCTION DEFINITIONS //

/// <summary> ///
///	Adds a particle emitter to the internal particle emitter array.
/// </summary> ///

LGLParticleEmitter * LGLAddParticleEmitter

// FUNCTION PARAMETERS //
(
	LGLPointFloat2 inputPos, LGLPointFloat2 inputPosOffset,
	LGLPointFloat2 inputVelocLow,
	LGLPointFloat2 inputVelocHigh, 
	LGLPointFloat2 inputGravity, LGLColor inputColor, 
	float inputLifeTime, float inputSpawnTime,
	int inputParticleSize, int inputParticleType,
	float inputParticleWidthness,
	bool spawnOnceInput = false, int spawnCountInput = 0
);

/// <summary> ///
///	This function creates a particle emitter at input position which
///	will eventually despawn after spawning all its particles in a rapid
///	manner.
/// </summary> ///
void LGLAddParticleExplosion

// FUNCTION PARAMETERS //
(
	LGLPointFloat2 inputPosition, LGLPointFloat2 inputVelocityLow,
	LGLPointFloat2 inputVelocityHigh, int inputParticleCount
);


/// <summary> ///
/// 	This file contains initialization functions for Layna's Graphical
///	Library.
/// </summary> ///

/// <summary> ///
///	Initializes SDL system by creating a window and renderer reference,
///	initializing SDL video, and clearing screen to black.
/// </summary> ///

// INCLUDES AND INITIALIZATIONS //
#include <SDL2/SDL.h>

// STRUCT PROTOTYPES //
class LGLContext;
class LGLInputEvent;
class LGLColor;

// FUNCTION DEFINITIONS //

/// <summary> ///
/// 	Initializes Layna's Graphical Library, creating an SDL instance
///	and generating a Framebuffer reference.
/// </summary> ///
/// <param name="winName">
///	The name of the window instance.
/// </param>
/// <param name="winX"> ///
/// 	The width in pixels of the window to be created.
/// </param> ///
/// <param name="winY"> ///
///	The height in pixels of the window to be created.
/// </param> ///
/// <param name="bgColor"> ///
///	Reference to the starting background color of the window.
/// </param> ///
void LGLInit(const char * winName, unsigned int winX, unsigned int winY);

/// <summary> ///
///	Updates the value saved in LGL context as "deltaTime."
/// </summary> ///
void LGLUpdateDeltaTime();

/// <summary> ///
///	Returns the value of "deltaTime" to caller.
/// </summary> ///
double LGLGetDeltaTime();

/// <summary> ///
///	Updates delta time variables and input state. Should call before
///	processing input or drawing to screen.
/// </summary> ///
void LGLUpdate();

/// <summary> ///
///	Returns an unprocessed event, if any. If no event is unprocessed,
///	returns 0.
/// </summary> ///
unsigned char LGLPollEvent(struct LGLInputEvent * inputEvent);

/// <summary> ///
///	Returns a char stating whether LGL is still running or not.
/// </summary> ///
unsigned char LGLIsRunning();

/// <summary> ///
/// 	Stops LGL from running.
/// </summary> ///
void LGLQuit();

/// <summary> ///
///	Updates the current state of all active particle emitters in the
///	internal particle array.
/// </summary> ///
void LGLUpdateParticles(float deltaTime);

/// <summary> ///
///	Draws all active particles in the internal particle array.
/// </summary> ///
void LGLDrawParticles();

/// <summary> ///
///	Returns a list of all 256 ASCII values to determine which keys
///	are pressed. 1 == pressed while 0 == unpressed. To access the
///	on/off state of a valid ASCII character in this array, index into
///	it using the raw ASCII value of the target character.
/// </summary> ///
char * LGLGetPressed();


#include <iostream>
#include <fstream>
#include <sstream>

/// <summary> ///
///	This class represents a .lff font file. It holds an array of integers
///	where each bit represents the on/off state of that position. It is
///	capable of parsing a .lff file independently, and does so in the
///	constructor argument if passed a path to such a file.
/// </summary> ///
class LGLFont
{
	public :
		// CONSTRUCTOR/DESTRUCTOR ARGUMENTS //

		// DEFAULT CONSTRUCTOR //
		LGLFont() { return; }

		// PARAMETERIZED CONSTRUCTOR //
		LGLFont(const std :: string inputPath)
		{
			std :: fstream targetFile(inputPath);
			if(!targetFile.is_open())
				std :: cout << "ERROR LOADING .lff FILE!"
					<< std :: endl;

			// IF FIRST LINE IS NOT "LFF BEGIN," RETURNS ERROR //
			std :: string curLine = "";
			getline(targetFile, curLine);
			if(curLine != "LFF BEGIN")
			{
				std :: cout << "ERROR: FILE DOES NOT " 
					<< "BEGIN WITH 'LFF BEGIN!'"
					<< std :: endl;
				return;
			}

			// READS THE WIDTH AND DEPTH OF THE FONT //
			for(int i = 0; i < 2; i++)
			{
				getline(targetFile, curLine);
				std :: stringstream curSS(curLine);
				std :: string tempString = "";

				// FINDS WIDTH //
				while(curSS >> tempString)
				{
					if(tempString == "LFF")
						continue;

					else if(tempString == "WIDTH") 
						continue;

					else if(tempString == "HEIGHT")
						continue;

					else if(std :: isdigit(tempString[0]))
					{
						if(i == 0)
						  fontWidth = 
						    std :: stoi(tempString);

						else
						  fontHeight = 
						    std :: stoi(tempString);
					}
					
					else
					{
						std :: cout << "ERROR PARSING" 
						  << " WIDTH/HEIGHT STRING!"
							<< std :: endl;
						return;
					}
				}
			}
			
			// READS THE GRID DATA //
			int index = 0;
			char isReading = 1;
			int rowY = -1;
			
			while(isReading)
			{
				getline(targetFile, curLine);
				std :: stringstream curSS(curLine);
				std :: string tempString;
				char readData = 0;

				// IS READING DATA STRING-INCREMENTS 
					// Y POSITION AND PREPARES PROGRAM //
					// TO READ DATA //
				if(std :: isdigit(curLine[0]))
				{
					rowY++;
					readData = 1;
				}
				
				// IF NOT READING DATA, MUST BE PARSING TEXT //
				if(!readData)
				{
					while(curSS >> tempString)
					{
						if(tempString == "LFF")
							continue;
						
						else if(tempString == "INDEX")
							continue;
						
						// IF READING END, STOPS //
							// PARSING FILE //
						else if(tempString == "END")
						{
							isReading = 0;
							break;
						}
						
						// IF READING DIGIT, MUST BE 
							// INDEX FILE //
							// OF NEW CHARACTER //
							// RESETS Y-ROW AND 
							// SETS NEW INDEX //
						else if
						(std :: isdigit(tempString[0]))
						{
							index = 
							std :: stoi(tempString);
							rowY = -1;
						}
						
						// IF NONE ABOVE VALUES // 
							// WERE FOUND, //
							// SOMETHING IS WRONG //
						else
						{
							std :: cout << "ERROR"
							  << "PARSING DATA"
							  << "STRINGS!"
							  << std :: endl;

							return;
						}
					}
				}
				
				// PREPARES TO READ A DATA LINE //
				else if(readData)
				{
					// IS ONLY ITERATING THROUGH THE X //
						// POSITION: THE Y POSITION //
						// IS REPRESENTED BY LINES //
					for(int x = fontWidth; x > 0; x--)
					{
						// IF ASCII EQUIVALENT OF 0, //
							// CELL WAS EMPTY //
						if
						 (curLine[fontWidth - x] == '0')
						{
							fontArray[index][rowY] 
								&= (~(1 << x));
						}

						// IF ASCII EQUIVALENT OF 1, //
							// CELL WAS FILLED //
						else 	
						{
							fontArray[index][rowY] 
								|= (1 << x);
						}
					}
				}
			}
		}

		// PUBLIC FUNCTIONS //
		void DrawChar

		// PARAMETERS //
		(
			unsigned int posX, unsigned int posY, 
			LGLColor inputColor, const unsigned char inputChar,
			int size
		)

		// FUNCTION //
		{
			float sizeX = float(size) / fontWidth;
			float sizeY = float(size) / fontHeight;

			for(int y = 0; y < fontHeight; y++)
			  for(int x = fontWidth; x > 0; x--)
			{
				if((fontArray[inputChar][y] >> x) & 1)
				{
					LGLRectToFB
					(
						posX + ((fontWidth - x) * sizeX),
						posY + (y * sizeY), 
						sizeX, sizeY, 
						inputColor, 1.0f
					);
				}
			}
		}

		// PUBLIC ATTRIBUTES //
		int fontWidth; int fontHeight;
	private :
		// PRIVATE ATTRIBUTES //
		long long int fontArray[256][64];
};

// PARAMTER DEFINITIONS //

/// <summary> ///
///	Draws a string using an input .lff font, starting at an input position
///	and drawing using an input LGLColor.
/// </summary> ///

void DrawString
(
	const std :: string inputString, LGLFont& inputFont,
	int posX, int posY, int size, const LGLColor& inputColor
);



#endif
