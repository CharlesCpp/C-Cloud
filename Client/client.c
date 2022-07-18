#include "client.h"

int main(int ac, char** av) {

    long int file_len;
    struct stat st;

    if(ac != 2) {
        printf("[-] Error Parameters\nUsage: %s filename (Exemple: ./client image.jpg)\n", av[0]);
        return 1;
    }
    
    // Opening the file
    printf("--- Cloud storage made in C by CharlesCPP ---\n");
    sleep(1);
    FILE *file = fopen(av[1], "rb");
    if (file == NULL) {
        printf("[-] Could not open the file %s.\nClosing...", av[1]);
        return 1;
    }

    // Checking file length
    long int Fsize = get_length(av[1]);
    printf("Your image is %d bytes long\n", Fsize);
    sleep(1);

    // Writing file from write_file function
    write_file(file, Fsize);
    fclose(file);

    // Create socket
    int network_socket;
    network_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Specify an address for the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;
    printf("[+] Request created successfuly \n");
    printf("IP address is: %s\n", inet_ntoa(server_address.sin_addr));

    sleep(1);
    int co_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    // Checking if the connection is successful
    if (co_status == -1) {
        printf("[-] There was an error making a connection to the remote server \n\n");
        return 1;
    }
    else {
        printf("[+] Connected successfuly to the remote server \n");
    }

    sleep(1);
    char server_response[256];
    //send(client_socket, message, sizeof(message), 0);

    // Printing data
    printf("The server sent the data: %s\n", server_response);

    return 0;
}