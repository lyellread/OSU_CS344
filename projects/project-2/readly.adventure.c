#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h> 
#include <errno.h>


//===================== S U P P O R T I N G   F U N C T I O N S =======================//

void findDirecrory(char * directoryName){

	//some help from https://stackoverflow.com/questions/42170824/use-stat-to-get-most-recently-modified-directory (and man page)
	struct stat currentStat

	DIR * cd;
	cd = opendir(".");

	while ((item = readdir(cd))){

		memset(&currentStat, 0, sizeof(currentStat));

		if (stat(item->d_name, &currentStat) == -1){
			//error
			printf("ERROR");
			continue;
		}




	}


}









//=============================== G A M E =================================//

void game(char * startRoom){

	printf("==>> GAME CALLED STARTING AT: %s\n", startRoom);

}









//================================ M A I N =================================//

int main() {

	char * direcroryName
	char * startRoom

	//find the most recent directory
	findDirecrory(directoryName);

	//go to that directory:
	chdir(directoryName);

	//Find the text file that is designated start_room
	findStartRoom(&startRoom);

	//run the game with that start room as the initial room
	game(startRoom)


}