/*
*
* @author: Joan Gómez
* @author2: Adria Arroyo (update on 11/03/2020)

*/

#include "libs.h"
#include "sync.h"
#include "vlc.h"

void intHandler();

pid_t child_id = 0;

int main() {
	
	system("clear");
	printf("**** Radiolab Video Sync Service ****\n");
	signal(SIGINT, intHandler);

	//Display the loading screen.
	child_id = vclLoadingScreen(); // 	system("cvlc -L ~/MediaVideoSync/drive/videos");

	//Download new videos from drive and save them into ~/MediaVideoSync/drive/videos
    videoSync();

	//Stop loading screen.
	stopVlc(child_id);
	
	//Start VLC playlist
    child_id = vlcLaunch();
	pause();

	return 0;
}

//In case user closes the software, close vlc child.
void intHandler() {
    if (child_id > 0) {
        stopVlc(child_id);
    }
	printf("Exiting...\n");
	exit(0);
}
