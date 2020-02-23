#ifndef STRICTNESSDYNTRACER_INTERCEPTR_SYS_STAT_WRAPPERS_H
#define STRICTNESSDYNTRACER_INTERCEPTR_SYS_STAT_WRAPPERS_H

extern "C" {
#include "interceptr.h"
}

extern "C" int sys_stat_stat(struct interceptr_t* interceptr,
                             interceptr_stat_t callback,
                             const char* path,
                             struct stat* buf);

extern "C" int sys_stat___xstat(struct interceptr_t* interceptr,
                                interceptr___xstat_t callback,
                                int version,
                                const char* path,
                                struct stat* buf);

extern "C" int sys_stat_stat64(struct interceptr_t* interceptr,
                               interceptr_stat64_t callback,
                               const char* path,
                               struct stat64* buf);

extern "C" int sys_stat___xstat64(struct interceptr_t* interceptr,
                                  interceptr___xstat64_t callback,
                                  int version,
                                  const char* path,
                                  struct stat64* buf);

extern "C" int sys_stat_fstat(struct interceptr_t* interceptr,
                              interceptr_fstat_t callback,
                              int fd,
                              struct stat* buf);

extern "C" int sys_stat___fxstat(struct interceptr_t* interceptr,
                                 interceptr___fxstat_t callback,
                                 int version,
                                 int fd,
                                 struct stat* buf);

extern "C" int sys_stat_fstat64(struct interceptr_t* interceptr,
                                interceptr_fstat64_t callback,
                                int fd,
                                struct stat64* buf);

extern "C" int sys_stat___fxstat64(struct interceptr_t* interceptr,
                                   interceptr___fxstat64_t callback,
                                   int version,
                                   int fd,
                                   struct stat64* buf);

extern "C" int sys_stat_fstatat(struct interceptr_t* interceptr,
                                interceptr_fstatat_t callback,
                                int dirfd,
                                const char* pathname,
                                struct stat* buf,
                                int flags);

extern "C" int sys_stat___fxstatat(struct interceptr_t* interceptr,
                                   interceptr___fxstatat_t callback,
                                   int version,
                                   int dirfd,
                                   const char* pathname,
                                   struct stat* buf,
                                   int flags);

extern "C" int sys_stat_fstatat64(struct interceptr_t* interceptr,
                                  interceptr_fstatat64_t callback,
                                  int dirfd,
                                  const char* pathname,
                                  struct stat64* buf,
                                  int flags);

extern "C" int sys_stat___fxstatat64(struct interceptr_t* interceptr,
                                     interceptr___fxstatat64_t callback,
                                     int version,
                                     int dirfd,
                                     const char* pathname,
                                     struct stat64* buf,
                                     int flags);

extern "C" int sys_stat_lstat(struct interceptr_t* interceptr,
                              interceptr_lstat_t callback,
                              const char* path,
                              struct stat* buf);

extern "C" int sys_stat___lxstat(struct interceptr_t* interceptr,
                                 interceptr___lxstat_t callback,
                                 int version,
                                 const char* path,
                                 struct stat* buf);

extern "C" int sys_stat_lstat64(struct interceptr_t* interceptr,
                                interceptr_lstat64_t callback,
                                const char* path,
                                struct stat64* buf);

extern "C" int sys_stat___lxstat64(struct interceptr_t* interceptr,
                                   interceptr___lxstat64_t callback,
                                   int version,
                                   const char* path,
                                   struct stat64* buf);

extern "C" int sys_stat_chmod(struct interceptr_t* interceptr,
                              interceptr_chmod_t callback,
                              const char* path,
                              mode_t mode);

extern "C" int sys_stat_fchmod(struct interceptr_t* interceptr,
                               interceptr_fchmod_t callback,
                               int fd,
                               mode_t mode);

extern "C" int sys_stat_fchmodat(struct interceptr_t* interceptr,
                                 interceptr_fchmodat_t callback,
                                 int dirfd,
                                 const char* pathname,
                                 mode_t mode,
                                 int flags);

extern "C" int sys_stat_mkdir(struct interceptr_t* interceptr,
                              interceptr_mkdir_t callback,
                              const char* pathname,
                              mode_t mode);

extern "C" int sys_stat_mkdirat(struct interceptr_t* interceptr,
                                interceptr_mkdirat_t callback,
                                int dirfd,
                                const char* pathname,
                                mode_t mode);

extern "C" int sys_stat_mknod(struct interceptr_t* interceptr,
                              interceptr_mknod_t callback,
                              const char* pathname,
                              mode_t mode,
                              dev_t dev);

extern "C" int sys_stat_mknodat(struct interceptr_t* interceptr,
                                interceptr_mknodat_t callback,
                                int dirfd,
                                const char* pathname,
                                mode_t mode,
                                dev_t dev);

extern "C" int sys_stat_mkfifo(struct interceptr_t* interceptr,
                               interceptr_mkfifo_t callback,
                               const char* pathname,
                               mode_t mode);

extern "C" int sys_stat_mkfifoat(struct interceptr_t* interceptr,
                                 interceptr_mkfifoat_t callback,
                                 int dirfd,
                                 const char* pathname,
                                 mode_t mode);

extern "C" int sys_stat_utimensat(struct interceptr_t* interceptr,
                                  interceptr_utimensat_t callback,
                                  int dirfd,
                                  const char* pathname,
                                  const struct timespec times[2],
                                  int flags);

extern "C" int sys_stat_futimens(struct interceptr_t* interceptr,
                                 interceptr_futimens_t callback,
                                 int fd,
                                 const struct timespec times[2]);

extern "C" mode_t sys_stat_umask(struct interceptr_t* interceptr,
                                 interceptr_umask_t callback,
                                 mode_t cmask);

#endif /* STRICTNESSDYNTRACER_INTERCEPTR_SYS_STAT_WRAPPERS_H */
