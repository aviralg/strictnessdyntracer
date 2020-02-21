#ifndef STRICTNESSDYNTRACER_INTERCEPTR_STDIO_WRAPPERS_H
#define STRICTNESSDYNTRACER_INTERCEPTR_STDIO_WRAPPERS_H

extern "C" {
#include "interceptr.h"
}

extern "C" FILE* stdio_fopen(struct interceptr_t* interceptr,
                             interceptr_fopen_t callback,
                             const char* path,
                             const char* mode);

extern "C" FILE* stdio_freopen(struct interceptr_t* interceptr,
                               interceptr_freopen_t callback,
                               const char* path,
                               const char* mode,
                               FILE* stream);

extern "C" size_t stdio_fwrite(struct interceptr_t* interceptr,
                               interceptr_fwrite_t callback,
                               const void* ptr,
                               size_t size,
                               size_t count,
                               FILE* stream);
extern "C" int stdio_vfprintf(struct interceptr_t* interceptr,
                              interceptr_vfprintf_t callback,
                              FILE* stream,
                              const char* format,
                              va_list arg);

#endif /* STRICTNESSDYNTRACER_INTERCEPTR_STDIO_WRAPPERS_H */
