extern "C" {
#include "interceptr.h"
}

extern "C" ssize_t unistd_write(struct interceptr_t* interceptr,
                                interceptr_write_t callback,
                                int fd,
                                const void* buf,
                                size_t count);

extern "C" ssize_t unistd_read(struct interceptr_t* interceptr,
                               interceptr_read_t callback,
                               int fd,
                               void* buf,
                               size_t count);
