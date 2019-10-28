#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h> 


void makeDirectory(){

	char pid[10];
	char * dirname_base = "./readly.rooms.";
	char dirname[40];

	//zero the first character so strcat() is happy! 
	dirname[0]='\0';

	//add the base to the empty array
	strcat(dirname, dirname_base);

	//convert int to cstr~ and add to the filename
	sprintf(pid, "%d", getpid());
	strcat(dirname, pid);

	printf("-->%s\n", dirname);

	//make that directory
	mkdir(dirname, 0777);

	//go to that directory
	chdir(dirname);

	return;

}

int in (int val, int * array, int arraySize){

	//immitation python in() fx. Straightforward.

	for (int j = 0; j < arraySize; ++j){

		//if vals are the same, return true its in that array
		//printf("Comparing %d, %d", val, array[j]);

		if (array[j] == val){
			return 1;
		}

	}

	//not found - return false its not in that array.
	return 0;
}

void createRoomFiles(char ** chosenRooms){

	FILE * file = NULL;

	//we need 7 rooms....

	for (int i = 0; i < 7; ++i){

		//open that room name (create file + stream)

		file = fopen(chosenRooms[i], "w");

		if (file == NULL){
			//if error, quit.
			printf("ERROR ON FOPEN");
			exit(-1);
		}

		//add to the top of the file this init data:
		fprintf(file, "%s", "ROOM NAME: ");
		fprintf(file, "%s\n", chosenRooms[i]);

		//close that file.
		fclose(file);
	}

	return;
}


void createRooms(char ** roomNames, int roomNamesSize, char ** chosenRooms){

	//this will store the past choices so that we dont choose the same 
	//choice twice
	int chosen[7];

	for (int i = 0; i < 7; ++i){

		//rand%10 ---> 0..9
		int choice = rand()%10;

		//enforce random !in chosen
		while(in(choice, chosen, i)){
			choice = rand()%10;
		}

		//printf("Choice: %d, Name: %s\n", choice, roomNames[choice]);
		//assign name and number fields
		chosen[i] = choice;
		chosenRooms[i] = roomNames[choice];

	}

	//call create the room files
	createRoomFiles(chosenRooms);
	return;
}


int main(){

	int roomNamesSize = 10;
	char * roomNames[roomNamesSize];
	roomNames[0] = "bacon";
	roomNames[1] = "sweets";
	roomNames[2] = "toast";
	roomNames[3] = "bread";
	roomNames[4] = "onion";
	roomNames[5] = "pepper";
	roomNames[6] = "salt";
	roomNames[7] = "eggs";
	roomNames[8] = "ham";
	roomNames[9] = "sauce";

	char * chosenRooms[7];

	srand(time(0));

	//create directory && chdir to it

	makeDirectory();

	//pick random rooms and create those files with only the ROOM NAME header present

	createRooms(roomNames, roomNamesSize, chosenRooms);

	//link files already created to one another with the CONNECTION n list.

	linkRooms(chosenRooms);

	//assign ( START_ROOM | MID_ROOM | END_ROOM ) ROOM TYPE to each room.

	typeRooms(chosenRooms);

	//call the Game program?



}