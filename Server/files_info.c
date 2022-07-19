#include "server.h"

void    link_back(char* link) {


    int net_socket;
    net_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in client_server;
    //memset(&client_server, '0', sizeof(client_server));
    
    client_server.sin_family = AF_INET;
    client_server.sin_port = htons(8081);
    client_server.sin_addr.s_addr = INADDR_ANY;
    printf("[+] Client socket created successfully\n");

    bind(net_socket, (struct sockaddr *) &client_server, sizeof(client_server));

    listen(net_socket, 10);
    printf("[+] Listening to connections port %d\n", htons(client_server.sin_port));

    int client_socket;
    client_socket = accept(net_socket, NULL, NULL);

    char test[123] = "Salut ça marche !";
    send(client_socket, test, sizeof(test), 0);

    return;
}