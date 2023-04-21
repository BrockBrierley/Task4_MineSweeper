#pragma once
#include "raylib.h"
#include "ImageManager.h"

class mineButton
{
public:
	//constructor and deconstructor
	mineButton();
	~mineButton();

	//method called when a buttonis clicked
	bool Interact(class MineManager* manager);
	//method used to change the flag state
	int Flag();
	//method used to make this button contain a bomb 
	void ArmBomb();
	//method used to remove a bomb from this button
	void DisarmBomb();
	//inputs the number of nearby mines to be stored within this buttonm
	void SetNearbyMines(int numOfMines);
	//returns the number of nearby mines
	int GetNearby();
	//sets this buttons x and y positions in the window and the 2d matrix
	void SetX(int xPos, int x);
	void SetY(int yPos, int y);
	//draw this mine
	void Draw(bool alive, float imageSizeMultiplyer);
	//returns if this button contains a mine
	bool IsMine();
	//returns the current flag state of this button
	bool IsFlagged();
	//resets this button to its starting values
	void Reset();

	//boolean used to determine if this was the mine that the player exploded
	bool clickedSquare = false;

	//sets the image manager to be used when drawing this buttons images
	void SetImageManager(ImageManager* im);

protected:
private:
	//pointer to the image manager
	ImageManager* imageManager;
	//stored number of nearby mines
	int nearby = 0;
	//state whether this button contains a mine
	bool mine = false;
	//state whether this button has been revealed
	bool revealed = false;
	//state whether this button is interactable or not
	bool interactable = true;
	//state whether this button is flagged or not
	bool flagged = false;

	//position in the 2d array (its only a 1d array but its easy to think in 2d arrays and convert it later)
	int xArrayPos = 0;
	int yArrayPos = 0;

	//current position in the display window
	Vector2 pos;
};

