#include <syslog.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    openlog("writer", LOG_PID | LOG_CONS, LOG_USER);

    if (argc < 3) {
        syslog(LOG_ERR, "Insufficient arguments provided");
        closelog(); // Close the log
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "w");
    if (!file) {
        syslog(LOG_ERR, "Failed to open file: %s", argv[1]);
        closelog();
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%s", argv[2]);
    fclose(file);

    syslog(LOG_INFO, "Successfully wrote '%s' to %s", argv[2], argv[1]);
    closelog();

    return EXIT_SUCCESS;
}