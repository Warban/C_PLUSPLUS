
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

/* Class Board.
* - Contains all game code.
* Params:
* 
* 
* 
* Returns:
* none.
*/
class LifeGame{

	public:

	char *gameBoard;

	int BOARD_SIZE;
	int BOARD_WIDTH;


	/* Class Board.
	* - Constructor
	* Params:
	* 
	* 
	* 
	* Returns:
	* none.
	*/	
	LifeGame();

	/* Class Viewer.
	* - Builds the GUI
	* Params:
	* 
	* 
	* 
	* Returns:
	* none.
	*/	
	void Viewer();

	/* Class Viewer.
	* - Builds the GUI
	* Params:
	* 
	* 
	* 
	* Returns:
	* none.
	*/	
	void cleargrid();


	/* Class play.
	* - Builds the new game menu.
	* Params:
	* 
	* 
	* 
	* Returns:
	* none.
	*/	
	void play();

	
	
	
	/* Class startworld.
	* - Starts the generator
	* Params:
	* 
	* 
	* 
	* Returns:
	* none.
	*/	
	void startworld(int count);



	/* Class genlife.
	* - Builds a random life map.
	* Params:
	* 
	* 
	* 
	* Returns:
	* none.
	*/
	void genlife();


	/* Class genlife_templateA.
	* - Builds a life map based off a template.
	* Params:
	* 
	* 
	* 
	* Returns:
	* none.
	*/
	void genlife_templateA();
	
	
	/* Class worldstep.
	* - Calcualtes next life cycle
	* Params:
	* 
	* 
	* 
	* Returns:
	* none.
	*/
	void worldstep();
};

