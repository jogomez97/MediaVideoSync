#ifndef _VLC_H_
#define _VLC_H_

#include "libs.h"

#define ERR_FORK "Error en fer el fork.\n"

/*
    VLC ARGUMENTS:
        * --fullscreen = -f
        * --quiet = -q: menys log per pantalla
        * --loop = -L: repeat all
*/

pid_t vlcLaunch();
void stopVlc();

#endif
