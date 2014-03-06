#include <stdio.h>
int authenticate(char *username, char *password) {
    int authenticated;
    char buffer[1024];
    authenticated = verify(username, password);
    if (authenticated == 0) {
        sprintf(buffer, "Failed for user %s\n", username);
    }
    return authenticated;
}
