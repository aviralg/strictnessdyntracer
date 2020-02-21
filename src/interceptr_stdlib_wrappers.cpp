#include "interceptr_stdlib_wrappers.h"

#include "TracerState.h"
#include "interceptr_utilities.h"

int stdlib_putenv(struct interceptr_t* interceptr,
                  interceptr_putenv_t callback,
                  char* string) {
    int result = callback(string);
    std::string delimiter = "=";
    std::string variable;
    std::string value;
    std::tie(variable, value) = split_string(value, delimiter);
    tracer_state(interceptr)
        .raise_event(EVENT_ENVVAR_ASSIGN, variable, value, result, "putenv");
    return result;
}

static void raise_getenv_event(struct interceptr_t* interceptr,
                               const char* name,
                               const char* val,
                               const char* function_name) {
    assert(name != NULL);
    std::string value = val == NULL ? "" : val;
    std::string variable = name;
    tracer_state(interceptr)
        .raise_event(
            EVENT_ENVVAR_LOOKUP, variable, value, std::string(function_name));
}

char* stdlib_getenv(struct interceptr_t* interceptr,
                    interceptr_getenv_t callback,
                    const char* name) {
    char* val = callback(name);
    raise_getenv_event(interceptr, name, val, "getenv");
    return val;
}

char* stdlib_secure_getenv(struct interceptr_t* interceptr,
                           interceptr_secure_getenv_t callback,
                           const char* name) {
    char* val = callback(name);
    raise_getenv_event(interceptr, name, val, "secure_getenv");
    return val;
}

int stdlib_clearenv(struct interceptr_t* interceptr,
                    interceptr_clearenv_t callback) {
    int result = callback();
    tracer_state(interceptr)
        .raise_event(EVENT_ENVVAR_CLEAR, result, "clearenv");
    return result;
}

int stdlib_setenv(struct interceptr_t* interceptr,
                  interceptr_setenv_t callback,
                  const char* name,
                  const char* value,
                  int overwrite) {
    std::string variable = name;
    std::string val = value;
    int result = callback(name, value, overwrite);
    tracer_state(interceptr)
        .raise_event(EVENT_ENVVAR_ASSIGN, variable, val, result, "setenv");
    return result;
}

int stdlib_unsetenv(struct interceptr_t* interceptr,
                    interceptr_unsetenv_t callback,
                    const char* name) {
    std::string variable = name;
    int result = callback(name);
    tracer_state(interceptr)
        .raise_event(EVENT_ENVVAR_REMOVE, variable, result, "unsetenv");
    return result;
}
