/*
*
* @author: Joan Gómez
*/

#include "libs.h"
#include "sync.h"
#include "vlc.h"

#define ALARM_TIME 3450 //Cada 58min aproximadament
#define SYNC_HOUR 10

void intHandler();
void alarmHandler();

pid_t child_id = 0;
char syncNow;
time_t now;

int main() {

	system("clear");
	printf("**** Radiolab Video Sync Service ****\n");
	signal(SIGINT, intHandler);
	signal(SIGALRM, alarmHandler);
	alarm(ALARM_TIME);
    syncNow = 0;

    child_id = vlcLaunch();

	while (1) {
		pause();
        if (syncNow) {
            syncNow = 0;
            //Do video sync
            videoSync();
            if (child_id > 0) {
                stopVlc(child_id);
            }
            child_id = vlcLaunch();
        }
        alarm(ALARM_TIME);
	}

	return 0;
}

void intHandler() {
    if (child_id > 0) {
        stopVlc(child_id);
    }
	printf("Exiting...\n");
	exit(0);
}

void alarmHandler() {
	time(&now);
	struct tm* tm_struct = localtime(&now);
	int hour = tm_struct->tm_hour;

	if (hour == SYNC_HOUR) {
		syncNow = 1;
	} else {
        printf("\e[1;34mNot sync hour! Waiting until %dh\e[0m\n", SYNC_HOUR);
    }
}
