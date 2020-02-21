extern "C" {
#include "interceptr.h"
}

#include "interceptr_stdlib_wrappers.h"
#include "interceptr_unistd_wrappers.h"

extern "C" {

int fcntl_open(struct interceptr_t* interceptr,
               interceptr_open_t callback,
               const char* path,
               int flags,
               mode_t mode);

int fcntl___open_2(struct interceptr_t* interceptr,
                   interceptr___open_2_t callback,
                   const char* path,
                   int flags);

int fcntl_open64(struct interceptr_t* interceptr,
                 interceptr_open64_t callback,
                 const char* path,
                 int flags,
                 mode_t mode);

int fcntl___open64_2(struct interceptr_t* interceptr,
                     interceptr___open64_2_t callback,
                     const char* path,
                     int flags);

int fcntl_openat(struct interceptr_t* interceptr,
                 interceptr_openat_t callback,
                 int dirfd,
                 const char* path,
                 int flags,
                 mode_t mode);

int fcntl_openat_2(struct interceptr_t* interceptr,
                   interceptr_openat_2_t callback,
                   int dirfd,
                   const char* path,
                   int flags);

int fcntl___openat_2(struct interceptr_t* interceptr,
                     interceptr___openat_2_t callback,
                     int dirfd,
                     const char* path,
                     int flags);

int fcntl_openat64(struct interceptr_t* interceptr,
                   interceptr_openat64_t callback,
                   int dirfd,
                   const char* path,
                   int flags,
                   mode_t mode);

int fcntl_openat64_2(struct interceptr_t* interceptr,
                     interceptr_openat64_2_t callback,
                     int dirfd,
                     const char* path,
                     int flags);

int fcntl___openat64_2(struct interceptr_t* interceptr,
                       interceptr___openat64_2_t callback,
                       int dirfd,
                       const char* path,
                       int flags);

int fcntl_creat(struct interceptr_t* interceptr,
                interceptr_creat_t callback,
                const char* path,
                mode_t mode);

int fcntl_creat64(struct interceptr_t* interceptr,
                  interceptr_creat64_t callback,
                  const char* path,
                  mode_t mode);

FILE* fcntl_fopen64(struct interceptr_t* interceptr,
                    interceptr_fopen64_t callback,
                    const char* path,
                    const char* mode);

/******************************************************************************/

FILE* stdio_fopen(struct interceptr_t* interceptr,
                  interceptr_fopen_t callback,
                  const char* path,
                  const char* mode);

FILE* stdio_freopen(struct interceptr_t* interceptr,
                    interceptr_freopen_t callback,
                    const char* path,
                    const char* mode,
                    FILE* stream);

size_t stdio_fwrite(struct interceptr_t* interceptr,
                    interceptr_fwrite_t callback,
                    const void* ptr,
                    size_t size,
                    size_t count,
                    FILE* stream);
int stdio_vfprintf(struct interceptr_t* interceptr,
                   interceptr_vfprintf_t callback,
                   FILE* stream,
                   const char* format,
                   va_list arg);

/******************************************************************************/
}
