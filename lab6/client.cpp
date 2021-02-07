#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#define PORT 9090

int main(int argc, char const *argv[]){
    int sock = 0, valread;
    sockaddr_in serv_addr;
    char buffer[1024] = {0};
    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <=0){
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if(connect(sock, (sockaddr*)&serv_addr, sizeof(serv_addr))< 0){
        printf("\nConnection Failed \n");
        return -1;
    }
    std::string message;
    std::cin >> message;
    char char_array[message.length() + 1];
    strcpy(char_array, message.c_str());

    send(sock, char_array, strlen(char_array), 0);
    valread = read(sock, buffer, 1024);
    printf("%s\n", buffer);
    return 0;
}