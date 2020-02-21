#include "interceptr_fcntl_wrappers.h"

#include "TracerState.h"
#include "interceptr_utilities.h"

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
    tracer_state(interceptr).raise_event(EVENT_FILE_OPEN, path, "CWT", "creat");
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
