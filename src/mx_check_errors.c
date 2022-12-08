#include "../inc/pathfinder.h"

char* mx_check_errors(int argc, char const *argv[]) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(-1);
    }
    char* file = mx_file_to_str(argv[1]);
    if (file == NULL) {
        char *error = mx_strjoin("error: file ", argv[1]);
        char *msg = mx_strjoin(error, " does not exist\n");
        mx_strdel(&error);
        mx_printerr(msg);
        mx_strdel(&msg);
        exit(-2);
    }
    if (file != NULL && *file == '\0') {
        mx_strdel(&file);
        char *error = mx_strjoin("error: file ", argv[1]);
        char *msg = mx_strjoin(error, " is empty\n");
        mx_strdel(&error);
        mx_printerr(msg);
        mx_strdel(&msg);
        exit(-3);
    }
    return file;
}
