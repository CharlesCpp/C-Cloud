#include "client.h"


char*    Second_server() {
    
    char *link = malloc(512);
    char test[123];

    int network_socket;
    network_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    memset(&server_address, '0', sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8081);
    server_address.sin_addr.s_addr = INADDR_ANY;

    sleep(1);
    while (connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        printf("[-] Error connecting to the remote client\n");
        sleep(5);
    }
    printf("[+] Connected to the remote client\n");

    recv(network_socket, test, sizeof(test), 0);
    printf("%s\n", test);
    return link;
}