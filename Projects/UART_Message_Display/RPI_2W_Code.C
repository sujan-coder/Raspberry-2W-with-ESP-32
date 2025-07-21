#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>

int main() {
    int serial_port = open("/dev/serial0", O_RDWR);

    struct termios tty;
    memset(&tty, 0, sizeof tty);
    tcgetattr(serial_port, &tty);
    tty.c_cflag = B115200 | CS8 | CREAD | CLOCAL;
    tty.c_iflag = IGNPAR;
    tty.c_oflag = 0;
    tty.c_lflag = 0;
    tcflush(serial_port, TCIFLUSH);
    tcsetattr(serial_port, TCSANOW, &tty);

    char msg[100];
    while (1) {
        printf("\n Enter message: ");
        fgets(msg, sizeof(msg), stdin);
        write(serial_port, msg, strlen(msg));
    }

    close(serial_port);
    return 0;
}




