// Asig2_part2.cpp : Defines the entry point for the console application.


#include "stdafx.h"
#include "Conway.h"
#include <string>
#include <iostream>
using namespace std;






	/* 
	* 
	* Params: 
	* None.
	* 
	* 
	* Returns:
	* none.
	*/

int _tmain(int argc, _TCHAR* argv[]){

	
	bool gameplay = true;
	LifeGame game1;
	
	while (gameplay == true){
		game1.play();

		char command;

		cout << "Play again?(y/n)";
		cin >> command;

		if (command != 'y'){
			gameplay = false;
		}

	}
	

	
	return 0;
}

