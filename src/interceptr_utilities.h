#ifndef STRICTNESSDYNTRACER_INTERCEPTR_UTILITIES_H
#define STRICTNESSDYNTRACER_INTERCEPTR_UTILITIES_H

#include "TracerState.h"

TracerState& tracer_state(interceptr_t* interceptr);

std::string fd_to_path(int fd);
const char* process_file_mode_number(int mode, char* str_mode);
const char* process_file_mode_string(const char* flag, char* str_mode);

#define UNDECORATED_FUNCTION_NAME(library) std::string(__func__).substr(strlen(#library) + 1)

#endif /* STRICTNESSDYNTRACER_INTERCEPTR_UTILITIES_H */