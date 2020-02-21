#include "interceptr_sys_stat_wrappers.h"

#include "TracerState.h"
#include "interceptr_utilities.h"

#define serialize_event(event_name, ...) \
    tracer_state(interceptr)             \
        .raise_event(                    \
            event_name, ##__VA_ARGS__, UNDECORATED_FUNCTION_NAME(sys_stat));

#define serialize_file_info_read_event(path, result) \
    serialize_event(EVENT_FILE_INFO_READ, path, result)

extern "C" int sys_stat_stat(struct interceptr_t* interceptr,
                             interceptr_stat_t callback,
                             const char* path,
                             struct stat* buf) {
    int result = callback(path, buf);
    tracer_state(interceptr)
        .raise_event(EVENT_FILE_INFO_READ,
                     path,
                     result,
                     UNDECORATED_FUNCTION_NAME(sys_stat));
    return result;
}

extern "C" int sys_stat___xstat(struct interceptr_t* interceptr,
                                interceptr___xstat_t callback,
                                int version,
                                const char* path,
                                struct stat* buf) {
    int result = callback(version, path, buf);
    tracer_state(interceptr)
        .raise_event(EVENT_FILE_INFO_READ,
                     path,
                     result,
                     UNDECORATED_FUNCTION_NAME(sys_stat));
    return result;
}

extern "C" int sys_stat_stat64(struct interceptr_t* interceptr,
                               interceptr_stat64_t callback,
                               const char* path,
                               struct stat64* buf) {
    int result = callback(path, buf);
    tracer_state(interceptr)
        .raise_event(EVENT_FILE_INFO_READ,
                     path,
                     result,
                     UNDECORATED_FUNCTION_NAME(sys_stat));
    return result;
}

extern "C" int sys_stat___xstat64(struct interceptr_t* interceptr,
                                  interceptr___xstat64_t callback,
                                  int version,
                                  const char* path,
                                  struct stat64* buf) {
    int result = callback(version, path, buf);
    tracer_state(interceptr)
        .raise_event(EVENT_FILE_INFO_READ,
                     path,
                     result,
                     UNDECORATED_FUNCTION_NAME(sys_stat));
    return result;
}

extern "C" int sys_stat_fstat(struct interceptr_t* interceptr,
                              interceptr_fstat_t callback,
                              int fd,
                              struct stat* buf) {
    int result = callback(fd, buf);
    std::string path = fd_to_path(fd);
    tracer_state(interceptr)
        .raise_event(EVENT_FILE_INFO_READ,
                     path,
                     result,
                     UNDECORATED_FUNCTION_NAME(sys_stat));
    return result;
}

extern "C" int sys_stat___fxstat(struct interceptr_t* interceptr,
                                 interceptr___fxstat_t callback,
                                 int version,
                                 int fd,
                                 struct stat* buf) {
    int result = callback(version, fd, buf);
    std::string path = fd_to_path(fd);
    tracer_state(interceptr)
        .raise_event(EVENT_FILE_INFO_READ,
                     path,
                     result,
                     UNDECORATED_FUNCTION_NAME(sys_stat));
    return result;
}

extern "C" int sys_stat_fstat64(struct interceptr_t* interceptr,
                                interceptr_fstat64_t callback,
                                int fd,
                                struct stat64* buf) {
    int result = callback(fd, buf);
    std::string path = fd_to_path(fd);
    tracer_state(interceptr)
        .raise_event(EVENT_FILE_INFO_READ,
                     path,
                     result,
                     UNDECORATED_FUNCTION_NAME(sys_stat));
    return result;
}

extern "C" int sys_stat___fxstat64(struct interceptr_t* interceptr,
                                   interceptr___fxstat64_t callback,
                                   int version,
                                   int fd,
                                   struct stat64* buf) {
    int result = callback(version, fd, buf);
    std::string path = fd_to_path(fd);
    tracer_state(interceptr)
        .raise_event(EVENT_FILE_INFO_READ,
                     path,
                     result,
                     UNDECORATED_FUNCTION_NAME(sys_stat));
    return result;
}

extern "C" int sys_stat_fstatat(struct interceptr_t* interceptr,
                                interceptr_fstatat_t callback,
                                int dirfd,
                                const char* pathname,
                                struct stat* buf,
                                int flags) {
    int result = callback(dirfd, pathname, buf, flags);
    return result;
}

extern "C" int sys_stat_lstat(struct interceptr_t* interceptr,
                              interceptr_lstat_t callback,
                              const char* path,
                              struct stat* buf) {
    int result = callback(path, buf);
    serialize_file_info_read_event(path, result);
    return result;
}

extern "C" int sys_stat___lxstat(struct interceptr_t* interceptr,
                                 interceptr___lxstat_t callback,
                                 int version,
                                 const char* path,
                                 struct stat* buf) {
    int result = callback(version, path, buf);
    serialize_file_info_read_event(path, result);
    return result;
}

extern "C" int sys_stat_lstat64(struct interceptr_t* interceptr,
                                interceptr_lstat64_t callback,
                                const char* path,
                                struct stat64* buf) {
    int result = callback(path, buf);
    serialize_file_info_read_event(path, result);
    return result;
}

extern "C" int sys_stat___lxstat64(struct interceptr_t* interceptr,
                                   interceptr___lxstat64_t callback,
                                   int version,
                                   const char* path,
                                   struct stat64* buf) {
    int result = callback(version, path, buf);
    serialize_file_info_read_event(path, result);
    return result;
}

extern "C" int sys_stat_chmod(struct interceptr_t* interceptr,
                              interceptr_chmod_t callback,
                              const char* path,
                              mode_t mode) {
    int result = callback(path, mode);
    return result;
}

extern "C" int sys_stat_fchmod(struct interceptr_t* interceptr,
                               interceptr_fchmod_t callback,
                               int fd,
                               mode_t mode) {
    int result = callback(fd, mode);
    return result;
}

extern "C" int sys_stat_fchmodat(struct interceptr_t* interceptr,
                                 interceptr_fchmodat_t callback,
                                 int dirfd,
                                 const char* pathname,
                                 mode_t mode,
                                 int flags) {
    int result = callback(dirfd, pathname, mode, flags);
    return result;
}

extern "C" int sys_stat_mkdir(struct interceptr_t* interceptr,
                              interceptr_mkdir_t callback,
                              const char* pathname,
                              mode_t mode) {
    int result = callback(pathname, mode);
    return result;
}

extern "C" int sys_stat_mkdirat(struct interceptr_t* interceptr,
                                interceptr_mkdirat_t callback,
                                int dirfd,
                                const char* pathname,
                                mode_t mode) {
    int result = callback(dirfd, pathname, mode);
    return result;
}

extern "C" int sys_stat_mknod(struct interceptr_t* interceptr,
                              interceptr_mknod_t callback,
                              const char* pathname,
                              mode_t mode,
                              dev_t dev) {
    int result = callback(pathname, mode, dev);
    return result;
}

extern "C" int sys_stat_mknodat(struct interceptr_t* interceptr,
                                interceptr_mknodat_t callback,
                                int dirfd,
                                const char* pathname,
                                mode_t mode,
                                dev_t dev) {
    int result = callback(dirfd, pathname, mode, dev);
    return result;
}

extern "C" int sys_stat_mkfifo(struct interceptr_t* interceptr,
                               interceptr_mkfifo_t callback,
                               const char* pathname,
                               mode_t mode) {
    int result = callback(pathname, mode);
    return result;
}

extern "C" int sys_stat_mkfifoat(struct interceptr_t* interceptr,
                                 interceptr_mkfifoat_t callback,
                                 int dirfd,
                                 const char* pathname,
                                 mode_t mode) {
    int result = callback(dirfd, pathname, mode);
    return result;
}

extern "C" int sys_stat_utimensat(struct interceptr_t* interceptr,
                                  interceptr_utimensat_t callback,
                                  int dirfd,
                                  const char* pathname,
                                  const struct timespec times[2],
                                  int flags) {
    int result = callback(dirfd, pathname, times, flags);
    return result;
}

extern "C" int sys_stat_futimens(struct interceptr_t* interceptr,
                                 interceptr_futimens_t callback,
                                 int fd,
                                 const struct timespec times[2]) {
    int result = callback(fd, times);
    return result;
}

extern "C" mode_t sys_stat_umask(struct interceptr_t* interceptr,
                                 interceptr_umask_t callback,
                                 mode_t cmask) {
    mode_t result = callback(cmask);
    return result;
}
