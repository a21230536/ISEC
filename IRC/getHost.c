#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

/* Need to link with Ws2_32.lib */
#pragma comment(lib, "ws2_32.lib")

int main(int argc, char **argv)
{
    WSADATA wsaData;
    DWORD dwError;
    struct hostent *remoteHost;
    struct in_addr addr;
    int iResult, i = 0;
    char **pAlias;

    /* Validate the parameters */
    if (argc != 2) {
        printf("usage: %s ipv4address\n", argv[0]);
        printf(" or\n");
        printf("       %s hostname\n", argv[0]);
        printf("  to return the host\n");
        printf("       %s 127.0.0.1\n", argv[0]);
        printf("  to return the IP addresses for a host\n");
        printf("       %s www.contoso.com\n", argv[0]);
        return 1;
    }

    /*-------------------------------------------------------------------------
     * Initialize Winsock
     *-----------------------------------------------------------------------*/
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed: %d\n", iResult);
        return 1;
    }

    /*-------------------------------------------------------------------------
     * Get Host Name or Address
     *-----------------------------------------------------------------------*/
    if (isalpha(argv[1][0])) {/* user input is an alpha name for the host */
        printf("Calling gethostbyname with %s\n", argv[1]);
        remoteHost = gethostbyname(argv[1]);
    }
    else {/* or assume IP v4 */
        printf("Calling gethostbyaddr with %s\n", argv[1]);
        addr.s_addr = inet_addr(argv[1]);
        if (addr.s_addr == INADDR_NONE) {
            printf("The IPv4 address entered must be a legal address\n");
            return 1;
        }
        else remoteHost = gethostbyaddr((char *)&addr, 4, AF_INET);
    }

    /* Failed to get Host Name or Address */
    if (remoteHost == NULL) {
        dwError = WSAGetLastError();
        if (dwError != 0) {
            if (dwError == WSAHOST_NOT_FOUND) printf("Host not found\n");
            else if (dwError == WSANO_DATA) printf("No data record found\n");
            else printf("Function failed with error: %ld\n", dwError);
        }
        return 1;
    }

    /*-------------------------------------------------------------------------
     * Display Host Address or Name Info
     *-----------------------------------------------------------------------*/
    printf("Official name: %s\n", remoteHost->h_name);
    for (pAlias = remoteHost->h_aliases; *pAlias != 0; pAlias++)
        printf("\tAlternate name #%d: %s\n", ++i, *pAlias);
    
    printf("Address type: ");
    switch (remoteHost->h_addrtype) {
        case AF_INET:printf("AF_INET\n");
        break;
        case AF_INET6: printf("AF_INET6\n");
        break;
        case AF_NETBIOS: printf("AF_NETBIOS\n");
        break;
        default: printf(" %d\n", remoteHost->h_addrtype);
    }
    
    printf("Address Length: %d\n", remoteHost->h_length);
    if (remoteHost->h_addrtype == AF_INET) {
        while (remoteHost->h_addr_list[i] != 0) {
            addr.s_addr = *(u_long *)remoteHost->h_addr_list[i++];
            printf("IPv4 Address #%d: %s\n", i, inet_ntoa(addr));
        }
    }
    else if (remoteHost->h_addrtype == AF_INET6) {
        printf("Remotehost is an IPv6 address\n");
    }

    return 0;
}
