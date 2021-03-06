#ifndef STRICTNESSDYNTRACER_CONSTANTS_H
#define STRICTNESSDYNTRACER_CONSTANTS_H

#include "definitions.h"

#include <string>
#include <vector>

extern const eval_depth_t ESCAPED_PROMISE_EVAL_DEPTH;
extern const eval_depth_t UNASSIGNED_PROMISE_EVAL_DEPTH;

extern const std::size_t PROMISE_MAPPING_BUCKET_COUNT;
extern const std::size_t FUNCTION_MAPPING_BUCKET_SIZE;

extern const std::vector<std::string> ENVIRONMENT_VARIABLES;

extern const timestamp_t UNDEFINED_TIMESTAMP;

extern const denoted_value_id_t UNASSIGNED_DENOTED_VALUE_ID;

extern const function_id_t UNASSIGNED_FUNCTION_ID;

extern const std::string UNASSIGNED_CLASS_NAME;

extern const call_id_t UNASSIGNED_CALL_ID;

extern const int UNASSIGNED_FORMAL_PARAMETER_POSITION;

extern const int UNASSIGNED_ACTUAL_ARGUMENT_POSITION;

extern const int UNASSIGNED_FORMAL_PARAMETER_COUNT;

extern const unsigned int OBJECT_TYPE_TABLE_COUNT;

extern const scope_t UNASSIGNED_SCOPE;
extern const scope_t TOP_LEVEL_SCOPE;

extern const gc_cycle_t UNDEFINED_GC_CYCLE;

extern const event_type_t EVENT_CLOSURE_ENTRY;
extern const event_type_t EVENT_CLOSURE_EXIT;
extern const event_type_t EVENT_BUILTIN_ENTRY;
extern const event_type_t EVENT_BUILTIN_EXIT;
extern const event_type_t EVENT_SPECIAL_ENTRY;
extern const event_type_t EVENT_SPECIAL_EXIT;
extern const event_type_t EVENT_ARGUMENT_PROMISE_ASSOCIATE;
extern const event_type_t EVENT_PROMISE_CREATE;
extern const event_type_t EVENT_PROMISE_ENTRY;
extern const event_type_t EVENT_PROMISE_EXIT;
extern const event_type_t EVENT_PROMISE_VALUE_LOOKUP;
extern const event_type_t EVENT_PROMISE_EXPRESSION_LOOKUP;
extern const event_type_t EVENT_PROMISE_ENVIRONMENT_LOOKUP;
extern const event_type_t EVENT_PROMISE_VALUE_ASSIGN;
extern const event_type_t EVENT_PROMISE_EXPRESSION_ASSIGN;
extern const event_type_t EVENT_PROMISE_ENVIRONMENT_ASSIGN;
extern const event_type_t EVENT_ENVIRONMENT_CREATE;
extern const event_type_t EVENT_ENVIRONMENT_VARIABLE_ASSIGN;
extern const event_type_t EVENT_ENVIRONMENT_VARIABLE_REMOVE;
extern const event_type_t EVENT_ENVIRONMENT_VARIABLE_DEFINE;
extern const event_type_t EVENT_ENVIRONMENT_VARIABLE_LOOKUP;
extern const event_type_t EVENT_FILE_OPEN;
extern const event_type_t EVENT_FILE_READ;
extern const event_type_t EVENT_FILE_WRITE;
extern const event_type_t EVENT_FILE_CLOSE;
extern const event_type_t EVENT_FILE_INFO_READ;
extern const event_type_t EVENT_FILE_INFO_WRITE;
extern const event_type_t EVENT_ENVVAR_ASSIGN;
extern const event_type_t EVENT_ENVVAR_REMOVE;
extern const event_type_t EVENT_ENVVAR_LOOKUP;
extern const event_type_t EVENT_ENVVAR_CLEAR;

extern const char RECORD_SEPARATOR;
extern const char UNIT_SEPARATOR;

#endif /* STRICTNESSDYNTRACER_CONSTANTS_H */
