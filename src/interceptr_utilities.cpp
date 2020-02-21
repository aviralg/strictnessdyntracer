#include "interceptr_utilities.h"

TracerState& tracer_state(interceptr_t* interceptr) {
    return *(static_cast<TracerState*>(interceptr->state));
}
