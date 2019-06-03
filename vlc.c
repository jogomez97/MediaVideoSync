#include "vlc.h"

pid_t vlcLaunch() {
    pid_t pid = fork();

    switch (pid) {
        case -1:
            write(1, ERR_FORK, strlen(ERR_FORK));
            return -1;
        break;
        case 0:; //child
            char *args[] = {"vlc", "-f", "-q", "-L", "./files/Vídeos", NULL};
            execvp(args[0], args);
        break;
        default: //father
            return pid;
        break;
    }

    return 0; //only child
}

void stopVlc(pid_t child_id) {
    kill(child_id, SIGINT);
    wait(NULL);
    child_id = 0;
    printf("\n\e[1;31mVLC killed\e[0m\n");
}
