#include "interceptr_unistd_wrappers.h"

#include "TracerState.h"
#include "interceptr_utilities.h"

ssize_t unistd_read(struct interceptr_t* interceptr,
                    interceptr_read_t callback,
                    int fd,
                    void* buf,
                    size_t count) {
    ssize_t result = callback(fd, buf, count);
    tracer_state(interceptr)
        .raise_event(EVENT_FILE_READ, fd_to_path(fd), count, result, "read");
    return result;
}

ssize_t unistd_write(struct interceptr_t* interceptr,
                     interceptr_write_t callback,
                     int fd,
                     const void* buf,
                     size_t count) {
    ssize_t result = callback(fd, buf, count);
    tracer_state(interceptr)
        .raise_event(EVENT_FILE_WRITE, fd_to_path(fd), count, result, "write");
    return result;
}
