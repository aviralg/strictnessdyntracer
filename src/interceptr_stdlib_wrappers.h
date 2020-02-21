extern "C" {
#include "interceptr.h"
}

extern "C" int stdlib_putenv(struct interceptr_t* interceptr,
                             interceptr_putenv_t callback,
                             char* string);

extern "C" char* stdlib_getenv(struct interceptr_t* interceptr,
                               interceptr_getenv_t callback,
                               const char* name);

extern "C" char* stdlib_secure_getenv(struct interceptr_t* interceptr,
                                      interceptr_secure_getenv_t callback,
                                      const char* name);

extern "C" int stdlib_clearenv(struct interceptr_t* interceptr,
                               interceptr_clearenv_t callback);

extern "C" int stdlib_setenv(struct interceptr_t* interceptr,
                             interceptr_setenv_t callback,
                             const char* name,
                             const char* value,
                             int overwrite);

extern "C" int stdlib_unsetenv(struct interceptr_t* interceptr,
                               interceptr_unsetenv_t callback,
                               const char* name);
