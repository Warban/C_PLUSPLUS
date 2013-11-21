#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;


class game{
　

	public :
　

	char *map_array;
	int GRID_SIZE;
	int GRID_ROW;
	
　
	void startworld(){
		for (int i = 0; i < 25 ;i++){
　

		worldstep();
		drawmap();
		system("pause");
		
		}
	}

	void worldstep(){
	
		//cout << "Test";
		for(int i = 0;i < GRID_SIZE ;i++){
		
			if (map_array[i] == '?*'){
				map_array[i] =' ';
			}
		}
	}

　

	void genlife(){
		int	R;
		
		for (int i = 0;i < 10;i++){
			R = rand() % GRID_SIZE;

			map_array[R] = '*';	
		}
	}

	void drawmap(){
	
		//system("cls");

		cout <<	"drawmap();\n";

		for(int i = 0;i< GRID_SIZE ;i++){
	
			cout << "[";
			cout << map_array[i];
			cout << "]";

			if ((i+1) % GRID_ROW == 0){
				cout << "\n";
			}
		}
	}

	void fillworld(){
	
		cout <<	"fillworld()\n";
		for(int i = 0;i< GRID_SIZE;i++){
			map_array[i] =' ';
		}
	}
	
	game(){
		cout<< "Generating game object()\n";
		
		GRID_SIZE = 100;
		GRID_ROW = 10;
		
		map_array = new char[GRID_SIZE];

	}


	void play(){
	
		cout << "play()\n";
		fillworld();
		genlife();
		startworld();

	}


};

