#include <memory.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "osrelease.h"

int init_osrelease(OsInfo *info) {
    FILE *osrel = fopen("/etc/os-release", "r");

    if (!osrel) {
        return 1;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, osrel)) != -1) {
        char *s = strtok(line, "=");
        if (strcmp(s, "PRETTY_NAME") == 0) {
            s = strtok(NULL, "=");

            size_t len = strlen(s) - 3;
            info->name = malloc(len);
            memcpy(info->name, s + 1, len);
        }

        if (strcmp(s, "ANSI_COLOR") == 0) {
            s = strtok(NULL, "=");

            size_t len = strlen(s) - 3;
            info->color = malloc(len);
            memcpy(info->color, s + 1, len);
        }
    }

    fclose(osrel);

    return 0;
}