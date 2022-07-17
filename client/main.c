#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int ac, char** av) {

    // Create socket
    int network_socket;
    network_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Specify an address for the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = '0.0.0.0';

    int co_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    // Checking if the connection is successful
    if (co_status == -1) {
        printf("[-] There was an error making a connection to the remote socket \n\n");
    }

    char server_response[256];
    recv(network_socket, &server_response, sizeof(server_response), 0);

    // Printing data
    printf("The server sent the data: %s\n", server_response);

    close(network_socket);
    return 0;
}