#include "client.h"

int main(int ac, char** av) {

    struct stat st;
    size_t file_size;
    char rbuff[1024];
    char sendbuffer[1024];
    int counter = 0;

    if(ac != 2) {
        printf("[-] Error Parameters\nUsage: %s filename (Exemple: ./client image.jpg)\n", av[0]);
        return 1;
    }
    
    // Opening the file
    printf("\n    Remote file hosting made by CharlesCPP 'Version: 0.1'   \n\n");
    sleep(1);
    FILE *file = fopen(av[1], "rb");
    if (file == NULL) {
        printf("[-] Could not open the file %s.\nClosing...", av[1]);
        return 1;
    }

    // Checking file length
    size_t file_len = get_length(file);
    printf("[?] File informations: %s size: %d bytes \n", av[1], get_length(file));
    sleep(1);

    // Checking the file type
    char* f_type = check_type(av[1]);
    sleep(1);
    

    // Create socket
    int network_socket;
    network_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Specify an address for the socket
    struct sockaddr_in server_address;
    memset(rbuff, '0', sizeof(rbuff));

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;
    printf("[+] Request created successfuly \n");
    printf("[+] IP address is: %s, Port: %d\n", inet_ntoa(server_address.sin_addr), htons(server_address.sin_port));

    sleep(1);
    // Checking if the connection is successful
    while (connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        printf("[-] There was an error making a connection to the remote server \nTrying again.... \n");
        sleep(5);
    }
    printf("[+] Connected successfuly to the remote server \n");

    // Sending file format to the remote server first
    int server_socket;
    server_socket = accept(network_socket, NULL, NULL);
    send(network_socket, f_type, sizeof(f_type), 0);
    printf("[+] Sent file properties (format %s)\n", f_type);
    sleep(1);

    // Sending the file
    printf("[+] Sending the file: %s to the remote server\n", av[1]);
    while( (file_size = fread(sendbuffer, 1, sizeof(sendbuffer), file))>0 ){
        send(network_socket, sendbuffer, file_size, 0);
        counter += file_size;
        fprintf(stdout, "\r[+] Sent %d out of %d bytes to the server", counter, file_len);
        fflush(stdout);
    }
    printf("\n");
    close(network_socket);

    // Function that wait for the server to send back file link and some informations
    char *link = Second_server();
    printf("[+] Your link is: %s", link);
    free(link);

    
    return 0;
}