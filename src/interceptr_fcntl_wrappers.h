#ifndef STRICTNESSDYNTRACER_INTERCEPTR_FCNTL_WRAPPERS_H
#define STRICTNESSDYNTRACER_INTERCEPTR_FCNTL_WRAPPERS_H

extern "C" {
#include "interceptr.h"
}

extern "C" int fcntl_open(struct interceptr_t* interceptr,
                          interceptr_open_t callback,
                          const char* path,
                          int flags,
                          mode_t mode);

extern "C" int fcntl___open_2(struct interceptr_t* interceptr,
                              interceptr___open_2_t callback,
                              const char* path,
                              int flags);

extern "C" int fcntl_open64(struct interceptr_t* interceptr,
                            interceptr_open64_t callback,
                            const char* path,
                            int flags,
                            mode_t mode);

extern "C" int fcntl___open64_2(struct interceptr_t* interceptr,
                                interceptr___open64_2_t callback,
                                const char* path,
                                int flags);

extern "C" int fcntl_openat(struct interceptr_t* interceptr,
                            interceptr_openat_t callback,
                            int dirfd,
                            const char* path,
                            int flags,
                            mode_t mode);

extern "C" int fcntl_openat_2(struct interceptr_t* interceptr,
                              interceptr_openat_2_t callback,
                              int dirfd,
                              const char* path,
                              int flags);

extern "C" int fcntl___openat_2(struct interceptr_t* interceptr,
                                interceptr___openat_2_t callback,
                                int dirfd,
                                const char* path,
                                int flags);

extern "C" int fcntl_openat64(struct interceptr_t* interceptr,
                              interceptr_openat64_t callback,
                              int dirfd,
                              const char* path,
                              int flags,
                              mode_t mode);

extern "C" int fcntl_openat64_2(struct interceptr_t* interceptr,
                                interceptr_openat64_2_t callback,
                                int dirfd,
                                const char* path,
                                int flags);

extern "C" int fcntl___openat64_2(struct interceptr_t* interceptr,
                                  interceptr___openat64_2_t callback,
                                  int dirfd,
                                  const char* path,
                                  int flags);

extern "C" int fcntl_creat(struct interceptr_t* interceptr,
                           interceptr_creat_t callback,
                           const char* path,
                           mode_t mode);

extern "C" int fcntl_creat64(struct interceptr_t* interceptr,
                             interceptr_creat64_t callback,
                             const char* path,
                             mode_t mode);

extern "C" FILE* fcntl_fopen64(struct interceptr_t* interceptr,
                               interceptr_fopen64_t callback,
                               const char* path,
                               const char* mode);

#endif /* STRICTNESSDYNTRACER_INTERCEPTR_FCNTL_WRAPPERS_H */
