#include <stdio.h>
#include <WinSock2.h>

/* Need to link with Ws2_32.lib */
#pragma comment(lib, "ws2_32.lib")

int main(int argc, char *argv[])
{
    struct in_addr **addr_list;
    WSADATA wsa;
    PHOSTENT he;
    char msg[32];

    /* missing hostnsme argument */
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return -1;
    }

    /* initialising winsock */
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        fprintf(stderr, "Failed. Error Code : %d", WSAGetLastError());
        return -1;
    }

    /* get the hostname's IP address */
    if ((he = gethostbyname(argv[1])) == NULL) {
        fprintf(stderr, "Failed to get IP address.");
        return -1;
    }

    /* Cast the h_addr_list to in_addr,
        since h_addr_list also has the ip address in long format only */
    addr_list = (struct in_addr **) he->h_addr_list;
    if (addr_list[0] != NULL) {
        fprintf(stdout, "\n{ hostname: %s, ip: %s }\n",
            argv[1], inet_ntoa(*addr_list[0]));
    }

    return 0;
}
