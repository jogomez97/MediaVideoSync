#include "sync.h"

void videoSync() {
	printf("\e[1;34mVideo syncing...\e[0m\n");

	//Execute ruby script to sync with google drive.
	int code = system("ruby ./drivesync/drivesync.rb");

    if (code == 0) {
        printf("\e[1;34mVideo sync done\e[0m\n");
    } else {
    	sendMail(code);
    }
}

void sendMail(int code) {
    printf("\e[1;31mSync exited with code: %d\e[0m\n", code);
    printf("\e[1;31mVideo sync failed. Sending email...\e[0m\n");
    system("mutt -s \"[Radiolab] Plataforma vídeos\" lsradiolab@gmail.com < ./erroremail.txt");
    printf("\e[1;31mEmail sent!\e[0m\n");
}
