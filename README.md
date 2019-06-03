# MediaSyncVideo

Plataforma de sincronització i reproducció de vídeos del RadioLab, la Salle Universitat Ramon Llull.

El programa en C s'encarrega de mantenir sincronitzats els vídeos del Drive del compte de lsradiolab amb el servei drivesync i després executar vlc amb la llista de vídeos en bucle.

La sincronització de vídeos es realitza cada dia a les 10 del matí i s'envia un correu a lsradiolab@gmail.com en cas de que hagi fallat.

### Dependencies

És necessari instal·lar i configurar el Drive amb drivesync (https://github.com/MStadlmeier/drivesync). Aquest programa haurà d'estar instal·lat en una carpeta dins del programa amb el nom drivesync.
