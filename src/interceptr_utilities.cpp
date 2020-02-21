#include "interceptr_utilities.h"

TracerState& tracer_state(interceptr_t* interceptr) {
    return *(static_cast<TracerState*>(interceptr->state));
}

/* https://stackoverflow.com/questions/1188757/retrieve-filename-from-file-descriptor-in-c
 */
std::string fd_to_path(int fd) {
    std::string filepath = "/proc/self/fd/" + std::to_string(fd);
    const int bufsize = 1000;
    char filename[bufsize] = "<unknown-file-name>";
    if (!access(filepath.c_str(), R_OK)) {
        int bytes = readlink(filepath.c_str(), filename, bufsize);
        if (bytes != -1) {
            filename[bytes] = '\0';
        }
    }
    return filename;
}

const char* process_file_mode_number(int mode, char* str_mode) {
    int index = 0;
    if (mode & O_RDONLY)
        str_mode[index++] = 'R';
    if (mode & O_WRONLY)
        str_mode[index++] = 'W';
    if (mode & O_RDWR)
        str_mode[index++] = 'Z';
    if (mode & O_CREAT)
        str_mode[index++] = 'C';
    if (mode & O_TRUNC)
        str_mode[index++] = 'T';
    if (mode & O_APPEND)
        str_mode[index++] = 'A';
    str_mode[index] = '\0';

    return str_mode;
}

const char* process_file_mode_string(const char* flag, char* str_mode) {
    int mode = 0;
    int last_index = strlen(flag) - 1;

    for (int i = 0; i <= last_index; ++i) {
        if (flag[i] == 'r') {
            if (i != last_index && flag[i + 1] == '+') {
                mode = mode | O_RDWR;
                ++i;
            } else {
                mode = mode | O_RDONLY;
            }
        } else if (flag[i] == 'w') {
            if (i != last_index && flag[i + 1] == '+') {
                mode = mode | O_RDWR | O_CREAT | O_TRUNC;
                ++i;
            } else {
                mode = mode | O_WRONLY | O_CREAT | O_TRUNC;
            }
        } else if (flag[i] == 'a') {
            if (i != last_index && flag[i + 1] == '+') {
                mode = mode | O_RDWR | O_CREAT | O_APPEND;
                ++i;
            } else {
                mode = mode | O_WRONLY | O_CREAT | O_APPEND;
            }
        }
    }

    return process_file_mode_number(mode, str_mode);
}
