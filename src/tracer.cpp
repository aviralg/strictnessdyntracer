#include "tracer.h"

#include "interceptr_wrappers.h"
#include "probes.h"

extern "C" {

interceptr_t* create_interceptr(void* state) {
    interceptr_t* interceptr = interceptr_create_interceptr();

    interceptr_set_interceptr_state(interceptr, state);

    /******************************************************************************/

    interceptr_set_wrapper_fcntl_open(interceptr, fcntl_open);
    interceptr_set_wrapper_fcntl___open_2(interceptr, fcntl___open_2);
    interceptr_set_wrapper_fcntl_open64(interceptr, fcntl_open64);
    interceptr_set_wrapper_fcntl___open64_2(interceptr, fcntl___open64_2);
    interceptr_set_wrapper_fcntl_openat(interceptr, fcntl_openat);
    interceptr_set_wrapper_fcntl_openat_2(interceptr, fcntl_openat_2);
    interceptr_set_wrapper_fcntl___openat_2(interceptr, fcntl___openat_2);
    interceptr_set_wrapper_fcntl_openat64(interceptr, fcntl_openat64);
    interceptr_set_wrapper_fcntl_openat64_2(interceptr, fcntl_openat64_2);
    interceptr_set_wrapper_fcntl___openat64_2(interceptr, fcntl___openat64_2);
    interceptr_set_wrapper_fcntl_creat(interceptr, fcntl_creat);
    interceptr_set_wrapper_fcntl_creat64(interceptr, fcntl_creat64);
    interceptr_set_wrapper_fcntl_fopen64(interceptr, fcntl_fopen64);

    /******************************************************************************/

    interceptr_set_wrapper_stdio_freopen(interceptr, stdio_freopen);
    interceptr_set_wrapper_stdio_fopen(interceptr, stdio_fopen);
    interceptr_set_wrapper_stdio_fwrite(interceptr, stdio_fwrite);
    interceptr_set_wrapper_stdio_vfprintf(interceptr, stdio_vfprintf);

    /******************************************************************************/

    interceptr_set_wrapper_stdlib_putenv(interceptr, stdlib_putenv);
    interceptr_set_wrapper_stdlib_getenv(interceptr, stdlib_getenv);
    interceptr_set_wrapper_stdlib_secure_getenv(interceptr,
                                                stdlib_secure_getenv);
    interceptr_set_wrapper_stdlib_clearenv(interceptr, stdlib_clearenv);
    interceptr_set_wrapper_stdlib_setenv(interceptr, stdlib_setenv);
    interceptr_set_wrapper_stdlib_unsetenv(interceptr, stdlib_unsetenv);

    /******************************************************************************/

    interceptr_set_wrapper_unistd_write(interceptr, unistd_write);
    interceptr_set_wrapper_unistd_read(interceptr, unistd_read);

    /******************************************************************************/

    interceptr_set_wrapper_sys_stat_stat(interceptr, sys_stat_stat);
    interceptr_set_wrapper_sys_stat___xstat(interceptr, sys_stat___xstat);
    interceptr_set_wrapper_sys_stat_stat64(interceptr, sys_stat_stat64);
    interceptr_set_wrapper_sys_stat___xstat64(interceptr, sys_stat___xstat64);
    interceptr_set_wrapper_sys_stat_fstat(interceptr, sys_stat_fstat);
    interceptr_set_wrapper_sys_stat_fstatat(interceptr, sys_stat_fstatat);
    interceptr_set_wrapper_sys_stat_lstat(interceptr, sys_stat_lstat);
    interceptr_set_wrapper_sys_stat_chmod(interceptr, sys_stat_chmod);
    interceptr_set_wrapper_sys_stat_fchmod(interceptr, sys_stat_fchmod);
    interceptr_set_wrapper_sys_stat_fchmodat(interceptr, sys_stat_fchmodat);
    interceptr_set_wrapper_sys_stat_mkdir(interceptr, sys_stat_mkdir);
    interceptr_set_wrapper_sys_stat_mkdirat(interceptr, sys_stat_mkdirat);
    interceptr_set_wrapper_sys_stat_mknod(interceptr, sys_stat_mknod);
    interceptr_set_wrapper_sys_stat_mknodat(interceptr, sys_stat_mknodat);
    interceptr_set_wrapper_sys_stat_mkfifo(interceptr, sys_stat_mkfifo);
    interceptr_set_wrapper_sys_stat_mkfifoat(interceptr, sys_stat_mkfifoat);
    interceptr_set_wrapper_sys_stat_utimensat(interceptr, sys_stat_utimensat);
    interceptr_set_wrapper_sys_stat_futimens(interceptr, sys_stat_futimens);
    interceptr_set_wrapper_sys_stat_umask(interceptr, sys_stat_umask);

    return interceptr;
}

SEXP create_dyntracer(SEXP output_dirpath,
                      SEXP verbose,
                      SEXP truncate,
                      SEXP binary,
                      SEXP compression_level) {
    void* state = new TracerState(sexp_to_string(output_dirpath),
                                  sexp_to_bool(verbose),
                                  sexp_to_bool(truncate),
                                  sexp_to_bool(binary),
                                  sexp_to_int(compression_level));

    /* calloc initializes the memory to zero. This ensures that probes not
       attached will be NULL. Replacing calloc with malloc will cause
       segfaults. */
    dyntracer_t* dyntracer = (dyntracer_t*) calloc(1, sizeof(dyntracer_t));
    dyntracer->probe_dyntrace_entry = dyntrace_entry;
    dyntracer->probe_dyntrace_exit = dyntrace_exit;
    dyntracer->probe_deserialize_object = deserialize_object;
    dyntracer->probe_eval_entry = eval_entry;
    dyntracer->probe_closure_argument_list_creation_entry =
        closure_argument_list_creation_entry;
    dyntracer->probe_closure_argument_list_creation_exit =
        closure_argument_list_creation_exit;
    dyntracer->probe_closure_entry = closure_entry;
    dyntracer->probe_closure_exit = closure_exit;
    dyntracer->probe_builtin_entry = builtin_entry;
    dyntracer->probe_builtin_exit = builtin_exit;
    dyntracer->probe_special_entry = special_entry;
    dyntracer->probe_special_exit = special_exit;
    dyntracer->probe_S3_dispatch_entry = S3_dispatch_entry;
    dyntracer->probe_S4_dispatch_argument = S4_dispatch_argument;
    dyntracer->probe_gc_entry = gc_entry;
    dyntracer->probe_gc_unmark = gc_unmark;
    dyntracer->probe_promise_force_entry = promise_force_entry;
    dyntracer->probe_promise_force_exit = promise_force_exit;
    dyntracer->probe_gc_allocate = gc_allocate;
    dyntracer->probe_promise_value_lookup = promise_value_lookup;
    dyntracer->probe_promise_expression_lookup = promise_expression_lookup;
    dyntracer->probe_promise_environment_lookup = promise_environment_lookup;
    dyntracer->probe_promise_value_assign = promise_value_assign;
    dyntracer->probe_promise_expression_assign = promise_expression_assign;
    dyntracer->probe_promise_environment_assign = promise_environment_assign;
    dyntracer->probe_promise_substitute = promise_substitute;
    dyntracer->probe_context_entry = context_entry;
    dyntracer->probe_context_jump = context_jump;
    dyntracer->probe_context_exit = context_exit;
    dyntracer->probe_environment_variable_define = environment_variable_define;
    dyntracer->probe_environment_variable_assign = environment_variable_assign;
    dyntracer->probe_environment_variable_remove = environment_variable_remove;
    dyntracer->probe_environment_variable_lookup = environment_variable_lookup;
    dyntracer->probe_environment_context_sensitive_promise_eval_entry =
        environment_context_sensitive_promise_eval_entry;
    dyntracer->probe_environment_context_sensitive_promise_eval_exit =
        environment_context_sensitive_promise_eval_exit;
    dyntracer->probe_substitute_call = substitute_call;
    dyntracer->state = state;

    interceptr_t* interceptr = create_interceptr(state);
    interceptr_set_interceptr(interceptr);

    return dyntracer_to_sexp(dyntracer, "dyntracer.promise");
}

static void destroy_promise_dyntracer(dyntracer_t* dyntracer) {
    /* free dyntracer iff it has not already been freed.
       this check ensures that multiple calls to destroy_dyntracer on the same
       object do not crash the process. */
    if (dyntracer) {
        delete (static_cast<TracerState*>(dyntracer->state));
        free(dyntracer);
    }
}

SEXP destroy_dyntracer(SEXP dyntracer_sexp) {
    return dyntracer_destroy_sexp(dyntracer_sexp, destroy_promise_dyntracer);
}

} // extern "C"
