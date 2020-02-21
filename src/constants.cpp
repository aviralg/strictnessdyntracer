#include "constants.h"

/* https://stackoverflow.com/questions/8206387/using-non-printable-characters-as-a-delimiter-in-php
 */
const eval_depth_t ESCAPED_PROMISE_EVAL_DEPTH = {-2, -2, -2, -1};
const eval_depth_t UNASSIGNED_PROMISE_EVAL_DEPTH = {-1, -1, -1, -1};

const size_t PROMISE_MAPPING_BUCKET_COUNT = 1000000;
const size_t FUNCTION_MAPPING_BUCKET_SIZE = 20000;

const std::vector<std::string> ENVIRONMENT_VARIABLES{"R_COMPILE_PKGS",
                                                     "R_DISABLE_BYTECODE",
                                                     "R_ENABLE_JIT",
                                                     "R_KEEP_PKG_SOURCE"};

const timestamp_t UNDEFINED_TIMESTAMP = -1;

const denoted_value_id_t UNASSIGNED_DENOTED_VALUE_ID = -1;

const function_id_t UNASSIGNED_FUNCTION_ID = "<unassigned-function-id>";

const std::string UNASSIGNED_CLASS_NAME = "<unassigned-class-name>";

const call_id_t UNASSIGNED_CALL_ID = -1;

const int UNASSIGNED_FORMAL_PARAMETER_POSITION = -1;

const int UNASSIGNED_ACTUAL_ARGUMENT_POSITION = -1;

const int UNASSIGNED_FORMAL_PARAMETER_COUNT = -1;

const unsigned int OBJECT_TYPE_TABLE_COUNT = 100;

const scope_t UNASSIGNED_SCOPE = "Unassigned";
const scope_t TOP_LEVEL_SCOPE = "Top Level";

extern const gc_cycle_t UNDEFINED_GC_CYCLE = -1;

const event_type_t EVENT_CLOSURE_ENTRY = "clb";
const event_type_t EVENT_CLOSURE_EXIT = "clf";
const event_type_t EVENT_BUILTIN_ENTRY = "bub";
const event_type_t EVENT_BUILTIN_EXIT = "buf";
const event_type_t EVENT_SPECIAL_ENTRY = "spb";
const event_type_t EVENT_SPECIAL_EXIT = "spf";
const event_type_t EVENT_ARGUMENT_PROMISE_ASSOCIATE = "apa";
const event_type_t EVENT_PROMISE_CREATE = "prc";
const event_type_t EVENT_PROMISE_ENTRY = "prb";
const event_type_t EVENT_PROMISE_EXIT = "prf";
const event_type_t EVENT_PROMISE_VALUE_LOOKUP = "pvl";
const event_type_t EVENT_PROMISE_EXPRESSION_LOOKUP = "pel";
const event_type_t EVENT_PROMISE_ENVIRONMENT_LOOKUP = "prl";
const event_type_t EVENT_PROMISE_VALUE_ASSIGN = "pva";
const event_type_t EVENT_PROMISE_EXPRESSION_ASSIGN = "pea";
const event_type_t EVENT_PROMISE_ENVIRONMENT_ASSIGN = "pra";
const event_type_t EVENT_ENVIRONMENT_CREATE = "enc";
const event_type_t EVENT_ENVIRONMENT_VARIABLE_ASSIGN = "ena";
const event_type_t EVENT_ENVIRONMENT_VARIABLE_REMOVE = "enr";
const event_type_t EVENT_ENVIRONMENT_VARIABLE_DEFINE = "end";
const event_type_t EVENT_ENVIRONMENT_VARIABLE_LOOKUP = "enl";
const event_type_t EVENT_FILE_OPEN = "flo";
const event_type_t EVENT_FILE_WRITE = "flw";
const event_type_t EVENT_FILE_READ = "flr";
const event_type_t EVENT_FILE_CLOSE = "flc";
const event_type_t EVENT_FILE_INFO_READ = "fli";
const event_type_t EVENT_ENVVAR_ASSIGN = "vaa";
const event_type_t EVENT_ENVVAR_REMOVE = "var";
const event_type_t EVENT_ENVVAR_LOOKUP = "val";
const event_type_t EVENT_ENVVAR_CLEAR = "vac";

const char RECORD_SEPARATOR = 0x1e;
const char UNIT_SEPARATOR = 0x1f;
