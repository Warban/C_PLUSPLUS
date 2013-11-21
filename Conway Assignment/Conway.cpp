// s.cpp
#include "stdafx.h"
#include "Conway.h"


/* Class Board.
	* - Constructor
	* Params:
	* 
	* 
	* 
	* Returns:
	* none.
	*/	
LifeGame::LifeGame(){
		BOARD_SIZE = 500;
		BOARD_WIDTH = 25;

		gameBoard = new char[BOARD_SIZE];
		}


	/* Class Viewer.
	* - Builds the GUI
	* Params:
	* 
	* 
	* 
	* Returns:
	* none.
	*/	
void LifeGame::Viewer(){

	system("cls");

	for (int i = 0; i < BOARD_SIZE ;i++){
		

		cout << "[" ;
		cout <<  gameBoard[i];
		cout << "]" ;


		if ((i+1)%BOARD_WIDTH == 0){
		cout << "\n" ;
		}
	}


}

	/* Class Viewer.
	* - Builds the GUI
	* Params:
	* 
	* 
	* 
	* Returns:
	* none.
	*/	
void LifeGame::cleargrid(){	


	for (int i = 0; i < BOARD_SIZE ; i++){
		gameBoard[i] = ' ';
	}

}



	/* Class play.
	* - Builds the new game menu.
	* Params:
	* 
	* 
	* 
	* Returns:
	* none.
	*/	
void LifeGame::play(){
	
	cout << "play()\n";

	int command;
		
	cleargrid();

	cout << "random or seed?(1:seed, else random)";
	cin >> command;

	if (command == 1){
		genlife_templateA();
	} else {
		genlife();
	}

	cout << "How many rounds?(Number)";
	cin >> command;

		
		
	
		
	startworld(command);

}

	
	/* Class startworld.
	* - Starts the generator
	* Params:
	* 
	* 
	* 
	* Returns:
	* none.
	*/	
void LifeGame::startworld(int count){
		
	bool firstrun = true;
	for (int i = 0; i < count ;i++){
		if (firstrun==false){
			worldstep();
		}else {
			firstrun=false;
		}
		Viewer();
		system("pause");
		
	}
}

	/* Class genlife_templateA.
	* - Builds a life map based off a template.
	* Params:
	* 
	* 
	* 
	* Returns:
	* none.
	*/
void LifeGame::genlife(){
	int	R;
		
	for (int i = 0;i < 250;i++){
		R = rand() % BOARD_SIZE;

		gameBoard[R] = '*';	
	}
}

	
	/* Class worldstep.
	* - Calcualtes next life cycle
	* Params:
	* 
	* 
	* 
	* Returns:
	* none.
	*/
void LifeGame::genlife_templateA(){
		
		
	//gameBoard[175] = '*';

		

	gameBoard[185] = '*';
	gameBoard[186] = '*';
	gameBoard[187] = '*';
	gameBoard[189] = '*';

	gameBoard[210] = '*';

	gameBoard[238] = '*';
	gameBoard[239] = '*';

	gameBoard[261] = '*';
	gameBoard[262] = '*';
	gameBoard[264] = '*';
		
	gameBoard[285] = '*';
	gameBoard[287] = '*';
	gameBoard[289] = '*';





}

	/* Class worldstep.
	* - Calcualtes next life cycle
	* Params:
	* 
	* 
	* 
	* Returns:
	* none.
	*/
void LifeGame::worldstep(){
	
		
	//cout << "Test";
	int count;

	for(int i = 0;i < BOARD_SIZE ;i++){
		count = 0;
			
			
			
		if (i+1 < BOARD_SIZE){ // To the right.	WORKDS
			if (gameBoard[i+1] == '*' || gameBoard[i+1] == 'V'){ // The one after
				count ++;
				//cout << "RIGHT\n";
			}
		}
		if (i-1 >=0){ // To the left. WORKS
			if (gameBoard[i-1] == '*' || gameBoard[i-1] == 'V'){ // The one before
				count ++;
				//cout << "LEFT\n";
			}
		}


		if (i-(BOARD_WIDTH) >= 0){//Above WORKS
			if (gameBoard[i-BOARD_WIDTH] == '*'||gameBoard[i-BOARD_WIDTH] == 'V'){ 
				count ++;
				//cout << "ABOVE\n";
			}
		}

		if (i+(BOARD_WIDTH) < BOARD_SIZE){//below DOES NOT
			if (gameBoard[i+BOARD_WIDTH] == '*'||gameBoard[i+BOARD_WIDTH] == 'V'){
				count ++;
				//cout << "BELOW\n";
			}
		}

		if (i+(BOARD_WIDTH+1) < BOARD_SIZE){// 
			if (gameBoard[i+(BOARD_WIDTH+1)] == '*' || gameBoard[i+(BOARD_WIDTH+1)] == 'V'  ){
				count ++;
				//cout << "BELOW-RIGHT\n";
			}
		}

		if (i+(BOARD_WIDTH-1) < BOARD_SIZE){
			if (gameBoard[i+(BOARD_WIDTH-1)] == '*'||gameBoard[i+(BOARD_WIDTH-1)] == 'V'){
				count ++;
				//cout << "BELOW-LEFT\n";
			}
		}
				
		if (i-(BOARD_WIDTH-1) > 0){	
			if (gameBoard[i-(BOARD_WIDTH-1)] == '*'||gameBoard[i-(BOARD_WIDTH-1)] == 'V'){
				count ++;
				//cout << "ABOVE-RIGHT\n";
			}
		}
		if (i-(BOARD_WIDTH+1) > 0){
			if (gameBoard[i-(BOARD_WIDTH+1)] == '*'|| gameBoard[i-(BOARD_WIDTH+1)] == 'V'){
				count ++;
				//cout << "ABOVE-LEFT\n";
			}
		}
		//cout << count;
		//cout << "\n";
							
					
			
					
				

		if (gameBoard[i] =='*'){
			if (count == 3 || count == 2 ){
				gameBoard[i] ='*';
			}else{
				gameBoard[i] ='V';
			}
		}
		if (gameBoard[i] ==' '){
			if (count == 3){
				gameBoard[i] ='O';
			}else{
			gameBoard[i] =' ';
			}
		}
	}


	for(int i = 0;i < BOARD_SIZE ;i++){
		if (gameBoard[i] == 'V'){
			gameBoard[i] =' ';
		}	
		if (gameBoard[i] == 'O'){
			gameBoard[i] ='*';
		}	
	}

}