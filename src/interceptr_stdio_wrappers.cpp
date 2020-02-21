#include "interceptr_stdio_wrappers.h"

#include "TracerState.h"
#include "interceptr_utilities.h"

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
