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

const std::string EVENT_FUNCTION_ENTRY = "fnb";
const std::string EVENT_FUNCTION_EXIT = "fnf";
const std::string EVENT_ARGUMENT_PROMISE_ASSOCIATE = "apa";
const std::string EVENT_PROMISE_CREATE = "prc";
const std::string EVENT_PROMISE_ENTRY = "prb";
const std::string EVENT_PROMISE_EXIT = "prf";
const std::string EVENT_PROMISE_VALUE_LOOKUP = "pvl";
const std::string EVENT_PROMISE_EXPRESSION_LOOKUP = "pel";
const std::string EVENT_PROMISE_ENVIRONMENT_LOOKUP = "prl";
const std::string EVENT_PROMISE_VALUE_ASSIGN = "pva";
const std::string EVENT_PROMISE_EXPRESSION_ASSIGN = "pea";
const std::string EVENT_PROMISE_ENVIRONMENT_ASSIGN = "pra";
const std::string EVENT_ENVIRONMENT_CREATE = "enc";
const std::string EVENT_ENVIRONMENT_VARIABLE_ASSIGN = "ena";
const std::string EVENT_ENVIRONMENT_VARIABLE_REMOVE = "enr";
const std::string EVENT_ENVIRONMENT_VARIABLE_DEFINE = "end";
const std::string EVENT_ENVIRONMENT_VARIABLE_LOOKUP = "enl";

const char RECORD_SEPARATOR = 0x1e;
const char UNIT_SEPARATOR = 0x1f;
