#include <ctype.h>
#include <stdlib.h>

const char *window_manager() {
    char *session = getenv("XDG_SESSION_DESKTOP");

    if (!session) {
        return "Unknown";
    }

    char *s = session;
    while (*s) {
        *s = toupper((unsigned char) *s);
        s++;
    }

    return session;
}