#ifndef STRICTNESSDYNTRACER_INTERCEPTR_UTILITIES_H
#define STRICTNESSDYNTRACER_INTERCEPTR_UTILITIES_H

#include "TracerState.h"

TracerState& tracer_state(interceptr_t* interceptr);

bool is_absolute_path(const std::string& path);
bool is_absolute_path(const char* path);
std::string fd_to_path(int dirfd, const char* path);
std::string fd_to_path(int fd);
std::string to_absolute_path(const char* path);
std::string to_absolute_path(const std::string& path);
const char* process_file_mode_number(int mode, char* str_mode);
const char* process_file_mode_string(const char* flag, char* str_mode);

#define UNDECORATED_FUNCTION_NAME(library) \
    std::string(__func__).substr(strlen(#library) + 1)

#endif /* STRICTNESSDYNTRACER_INTERCEPTR_UTILITIES_H */
