#include "interceptr_wrappers.h"

#include "TracerState.h"

inline TracerState& tracer_state(interceptr_t* interceptr) {
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

static const char* process_file_mode_number(int mode, char* str_mode) {
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

static const char* process_file_mode_string(const char* flag, char* str_mode) {
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

int fcntl_open(struct interceptr_t* interceptr,
               interceptr_open_t callback,
               const char* path,
               int flags,
               mode_t mode) {
    char str_mode[10];
    tracer_state(interceptr)
        .raise_event(EVENT_FILE_OPEN,
                     path,
                     process_file_mode_number(flags, str_mode),
                     "open");
    return callback(path, flags, mode);
}

int fcntl___open_2(struct interceptr_t* interceptr,
                   interceptr___open_2_t callback,
                   const char* path,
                   int flags) {
    char str_mode[10];
    tracer_state(interceptr)
        .raise_event(EVENT_FILE_OPEN,
                     path,
                     process_file_mode_number(flags, str_mode),
                     "__open_2");
    return callback(path, flags);
}

int fcntl_open64(struct interceptr_t* interceptr,
                 interceptr_open64_t callback,
                 const char* path,
                 int flags,
                 mode_t mode) {
    char str_mode[10];
    tracer_state(interceptr)
        .raise_event(EVENT_FILE_OPEN,
                     path,
                     process_file_mode_number(flags, str_mode),
                     "open64");
    return callback(path, flags, mode);
}

int fcntl___open64_2(struct interceptr_t* interceptr,
                     interceptr___open64_2_t callback,
                     const char* path,
                     int flags) {
    char str_mode[10];
    tracer_state(interceptr)
        .raise_event(EVENT_FILE_OPEN,
                     path,
                     process_file_mode_number(flags, str_mode),
                     "open64_2");
    return callback(path, flags);
}

int fcntl_openat(struct interceptr_t* interceptr,
                 interceptr_openat_t callback,
                 int dirfd,
                 const char* path,
                 int flags,
                 mode_t mode) {
    char str_mode[10];
    // TODO - handle dirfd
    tracer_state(interceptr)
        .raise_event(EVENT_FILE_OPEN,
                     path,
                     process_file_mode_number(flags, str_mode),
                     "openat");
    return callback(dirfd, path, flags, mode);
}

int fcntl_openat_2(struct interceptr_t* interceptr,
                   interceptr_openat_2_t callback,
                   int dirfd,
                   const char* path,
                   int flags) {
    char str_mode[10];
    // TODO - handle dirfd
    tracer_state(interceptr)
        .raise_event(EVENT_FILE_OPEN,
                     path,
                     process_file_mode_number(flags, str_mode),
                     "openat_2");
    return callback(dirfd, path, flags);
}

int fcntl___openat_2(struct interceptr_t* interceptr,
                     interceptr___openat_2_t callback,
                     int dirfd,
                     const char* path,
                     int flags) {
    char str_mode[10];
    // TODO - handle dirfd
    tracer_state(interceptr)
        .raise_event(EVENT_FILE_OPEN,
                     path,
                     process_file_mode_number(flags, str_mode),
                     "__openat_2");
    return callback(dirfd, path, flags);
}

int fcntl_openat64(struct interceptr_t* interceptr,
                   interceptr_openat64_t callback,
                   int dirfd,
                   const char* path,
                   int flags,
                   mode_t mode) {
    char str_mode[10];
    // TODO - handle dirfd
    tracer_state(interceptr)
        .raise_event(EVENT_FILE_OPEN,
                     path,
                     process_file_mode_number(flags, str_mode),
                     "openat64");
    return callback(dirfd, path, flags, mode);
}

int fcntl_openat64_2(struct interceptr_t* interceptr,
                     interceptr_openat64_2_t callback,
                     int dirfd,
                     const char* path,
                     int flags) {
    char str_mode[10];
    // TODO - handle dirfd
    tracer_state(interceptr)
        .raise_event(EVENT_FILE_OPEN,
                     path,
                     process_file_mode_number(flags, str_mode),
                     "openat64_2");
    return callback(dirfd, path, flags);
}

int fcntl___openat64_2(struct interceptr_t* interceptr,
                       interceptr___openat64_2_t callback,
                       int dirfd,
                       const char* path,
                       int flags) {
    char str_mode[10];
    // TODO - handle dirfd
    tracer_state(interceptr)
        .raise_event(EVENT_FILE_OPEN,
                     path,
                     process_file_mode_number(flags, str_mode),
                     "__openat64_2");
    return callback(dirfd, path, flags);
}

int fcntl_creat(struct interceptr_t* interceptr,
                interceptr_creat_t callback,
                const char* path,
                mode_t mode) {
    /*
      http://man7.org/linux/man-pages/man2/open.2.html
      A call to creat() is equivalent to calling open() with flags equal to
      O_CREAT|O_WRONLY|O_TRUNC.
     */
    tracer_state(interceptr)
        .raise_event(EVENT_FILE_OPEN, path, "CWT", "creat");
    return callback(path, mode);
}

int fcntl_creat64(struct interceptr_t* interceptr,
                  interceptr_creat64_t callback,
                  const char* path,
                  mode_t mode) {
    /*
      http://man7.org/linux/man-pages/man2/open.2.html
      A call to creat() is equivalent to calling open() with flags equal to
      O_CREAT|O_WRONLY|O_TRUNC.
    */
    tracer_state(interceptr)
        .raise_event(EVENT_FILE_OPEN, path, "CWT", "creat64");
    return callback(path, mode);
}

FILE* fcntl_fopen64(struct interceptr_t* interceptr,
                    interceptr_fopen64_t callback,
                    const char* path,
                    const char* mode) {
    char str_mode[10];
    tracer_state(interceptr)
        .raise_event(EVENT_FILE_OPEN,
                     path,
                     process_file_mode_string(mode, str_mode),
                     "fopen64");
    return callback(path, mode);
}

/******************************************************************************/

FILE* stdio_fopen(struct interceptr_t* interceptr,
                  interceptr_fopen_t callback,
                  const char* path,
                  const char* mode) {
    char str_mode[10];
    tracer_state(interceptr)
        .raise_event(EVENT_FILE_OPEN,
                     path,
                     process_file_mode_string(mode, str_mode),
                     "fopen");
    return callback(path, mode);
}

FILE* stdio_freopen(struct interceptr_t* interceptr,
                    interceptr_freopen_t callback,
                    const char* path,
                    const char* mode,
                    FILE* stream) {
    char str_mode[10];
    tracer_state(interceptr)
        .raise_event(EVENT_FILE_OPEN,
                     path,
                     process_file_mode_string(mode, str_mode),
                     "freopen");
    return callback(path, mode, stream);
}

size_t stdio_fwrite(struct interceptr_t* interceptr,
                    interceptr_fwrite_t callback,
                    const void* ptr,
                    size_t size,
                    size_t count,
                    FILE* stream) {
    tracer_state(interceptr)
        .raise_event(
            EVENT_FILE_WRITE, fd_to_path(fileno(stream)), count, "fwrite");
    return callback(ptr, size, count, stream);
}

int stdio_vfprintf(struct interceptr_t* interceptr,
                   interceptr_vfprintf_t callback,
                   FILE* stream,
                   const char* format,
                   va_list arg) {
    tracer_state(interceptr)
        .raise_event(EVENT_FILE_WRITE, fd_to_path(fileno(stream)), "vfprintf");
    return callback(stream, format, arg);
}

/******************************************************************************/

int stdlib_putenv(struct interceptr_t* interceptr,
                  interceptr_putenv_t callback,
                  char* string) {
    // environment_put("putenv", string);
    return callback(string);
}

char* stdlib_getenv(struct interceptr_t* interceptr,
                    interceptr_getenv_t callback,
                    const char* name) {
    // environment_get("getenv", name);
    return callback(name);
}

char* stdlib_secure_getenv(struct interceptr_t* interceptr,
                           interceptr_getenv_t callback,
                           const char* name) {
    // environment_get("secure_getenv", name);
    return callback(name);
}

int stdlib_clearenv(struct interceptr_t* interceptr,
                    interceptr_clearenv_t callback) {
    // environment_clear("clearenv");
    return callback();
}

int stdlib_setenv(struct interceptr_t* interceptr,
                  interceptr_setenv_t callback,
                  const char* name,
                  const char* value,
                  int overwrite) {
    // environment_set("setenv", name, value, overwrite);
    return callback(name, value, overwrite);
}

int stdlib_unsetenv(struct interceptr_t* interceptr,
                    interceptr_unsetenv_t callback,
                    const char* name) {
    // environment_unset("unsetenv", name);
    return callback(name);
}

/******************************************************************************/

ssize_t unistd_read(struct interceptr_t* interceptr,
                    interceptr_read_t callback,
                    int fd,
                    void* buf,
                    size_t count) {
    tracer_state(interceptr)
        .raise_event(EVENT_FILE_READ, fd_to_path(fd), count, "read");
    return callback(fd, buf, count);
}

ssize_t unistd_write(struct interceptr_t* interceptr,
                     interceptr_write_t callback,
                     int fd,
                     const void* buf,
                     size_t count) {
    tracer_state(interceptr)
        .raise_event(EVENT_FILE_WRITE, fd_to_path(fd), count, "write");
    return callback(fd, buf, count);
}
