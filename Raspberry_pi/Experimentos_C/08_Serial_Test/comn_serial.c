/*
Basado en https://github.com/todbot/arduino-serial/blob/master/arduino-serial-lib.c
*/
#include "comn_serial.h"
#include <sys/types.h> //pthread(aux)
#include <stdio.h> //printf, perror
#include <unistd.h> // UNIX standard function definitions
#include <fcntl.h> // File control definitions
#include <stdlib.h> //exit
#include <string.h> //strlen
#include <errno.h>
#include <termios.h>
#include "main.h"

#define BUFFSIZE 110

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RESET "\033[0m"

char buffRead[BUFFSIZE];

//Este es para el thread de lectrua
pthread_t tserial;

//Estos son para el canal serial
int serial_fd, nReadSerial; /* File descriptor for the port */
struct termios oldtio, newtio;

//METODO QUE METO EN EL THREAD
void* leerEntradaSerial()
{
	while(1)
	{
		memset(buffRead, 0, sizeof(buffRead));
		/* We sleep the program(10000) because we have to wait for a full buffer */
		usleep(100000);
		nReadSerial=read(serial_fd, &buffRead, BUFFSIZE);
		if(nReadSerial > 0)
		{
			imprimirEnConsola(buffRead);
			fflush(stdout);
		}
	}
}

void closeWithError(char *error)
{
	char errMsj[1024];
	sprintf(errMsj, KRED"%s"RESET, error);
	perror(errMsj);
	exit(1);
}

void initSerial(char *serialport, int baud)
{
	//Estos son para el Thread de lectura
	int err;
	char errMsj[1024];//posible mensaje de error

	//Aqui se establece la conexion serial
	serial_fd = open(serialport, O_RDWR | O_NONBLOCK );
	if(serial_fd == -1) closeWithError("serialport_init: Unable to open port ");

	if(tcgetattr(serial_fd, &oldtio) < 0) /* if work, save current port settings */
		closeWithError("serialport_init: Couldn't get term attributes");

	speed_t brate = baud; // let you override switch below if needed
  switch(baud)
  {
		case 4800:   brate=B4800;   break;
		case 9600:   brate=B9600;   break;
		#ifdef B14400
		case 14400:  brate=B14400;  break;
		#endif
		case 19200:  brate=B19200;  break;
		#ifdef B28800
		case 28800:  brate=B28800;  break;
		#endif
		case 38400:  brate=B38400;  break;
		case 57600:  brate=B57600;  break;
		case 115200: brate=B115200; break;
  }
  cfsetispeed(&newtio, brate);
  cfsetospeed(&newtio, brate);

  // 8N1
  newtio.c_cflag &= ~PARENB;
  newtio.c_cflag &= ~CSTOPB;
  newtio.c_cflag &= ~CSIZE;
  newtio.c_cflag |= CS8;
  // no flow control
  newtio.c_cflag &= ~CRTSCTS;

  newtio.c_cflag |= CREAD | CLOCAL;  // turn on READ & ignore ctrl lines
  newtio.c_iflag &= ~(IXON | IXOFF | IXANY); // turn off s/w flow ctrl

  newtio.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG); // make raw
  newtio.c_oflag &= ~OPOST; // make raw

  newtio.c_cc[VMIN]  = 0;
  newtio.c_cc[VTIME] = 0; //5;            // 0.5 seconds read timeout

  tcsetattr(serial_fd, TCSANOW, &newtio);
  if(tcsetattr(serial_fd, TCSAFLUSH, &newtio) < 0) closeWithError("init_serialport: Couldn't set term attributes");

  puts(KGRN"Successful Connection"RESET);

  //Aqui se crea el thread de lectura
  err = pthread_create(&(tserial), NULL, &leerEntradaSerial, NULL);
  if(err != 0)
  {
  	sprintf(errMsj,"Can't create thread:[%s]", strerror(err));
	closeWithError(errMsj);
  }
  else printf("Thread created successfully\n");
  printf(KCYN"___________________________\n"RESET);
}

void enviarCadenaSerial(char *texto)
{write(serial_fd, texto, strlen(texto));}

/*
int serialport_flush()
{
    sleep(2); //required to make flush work, for some reason
    return tcflush(serial_fd, TCIOFLUSH);
}
*/

void cerrarSerial()
{
	tcsetattr(serial_fd, TCSANOW, &oldtio);
	close(serial_fd);
}
