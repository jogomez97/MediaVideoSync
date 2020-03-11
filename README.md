
# MediaSyncVideo

Plataforma de sincronització i reproducció de vídeos del RadioLab, la Salle Universitat Ramon Llull.

El programa en C s'encarrega de mantenir sincronitzats els vídeos del Drive del compte de lsradiolab amb el servei drivesync i després executar vlc amb la llista de vídeos en bucle.

La sincronització de vídeos es realitza cada dia a les 8 del matí i s'envia un correu a lsradiolab@gmail.com en cas de que hagi fallat.

### Creedencials
Raspberry pi 4
User: pi
Password: RadioLab1

Email Drive RadioLab
Email: lsradiolab@gmail.com	
Password: Radiolab19

### Com instal.lar el software
Instalar mutt en el sistema linux:
	sudo apt-get install mutt -y

Instalar git en el sistema linux:
	sudo apt-get install git -y

Instalar vlc en el sistema linux:
	sudo apt-get install vlc -y

Instalar gedit en el sistema linux:
	sudo apt-get install gedit -y

Instalar ruby en el sistema linux:
	sudo apt-get install ruby -y

Instalar bundler en el sistema linux:
	sudo gem install bundler -y

Actualitzar el bundler:
	sudo bundle update --bundler

Un cop ruby esta instalat, executar la seguent comanda en la carpeta HOME (~). 
	git clone https://github.com/jogomez97/MediaVideoSync

Entrem en la carpeta que s'acaba de crear despres de la comanda anterior:
	cd MediaVideoSync

Executem la seguent comanda:
	git clone https://github.com/MStadlmeier/drivesync

Entrem a la carpeta amb:
	cd drivesync

Executem la següent comanda:
	bundle install

Ara ja tenim tot el software en el sistema linux. Fa falta però, acabar de configurar-lo:

Executar la seguent comanda, sobrirá un arxiu de configuració:
	gedit ~/.drivesync/config.yml

Editar les següents linies:	

	Segona linea: posar el path corresponent a la carpeta anomenada drive que es troba a l'interior de MediavideoSync.
	Linea 36: inclusion: whitelist
	Linea 44: whitelist: ["videos/*"]

En el cas de que es desitgi treballar amb fitxers més grans de 512Mbytes, s'han de modificar les següents linies:
	Linea 20 i Linea 31.

Exemple per treballar amb fitxers de fins a 1GB.

	Linea 20: timeout: 2400
	Linea 31: max_file_size: 1024

Un cop modificat el fitxer, el guardem i finalment fem que el programa s'executi al iniciar-se la raspberry.
Executa la següent comanda dins la carpeta MediaVideoSync:
	sudo cp ./tv_radiolab.service /etc/systemd/system/

Executa la següent comanda per a activar el servei
	sudo systemctl enable tv_radiolab.service

La proxima vegada que la raspberry pi sengegui, s'iniciará automaticament tot al cap de 10 segons despres del boot!
