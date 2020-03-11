#ifndef _VLC_H_
#define _VLC_H_

#include "libs.h"

#define ERR_FORK "Error en fer el fork.\n"

#define PATH_TO_VIDEOS_FOLDER "./drive/videos"

#define PATH_TO_LOADING_VIDEO_FOLDER "./loadingScreen"

/*
    VLC ARGUMENTS:
        * --fullscreen = -f
        * --quiet = -q: menys log per pantalla
        * --loop = -L: repeat all
*/

pid_t vlcLaunch();
pid_t vclLoadingScreen();

void stopVlc();

#endif
