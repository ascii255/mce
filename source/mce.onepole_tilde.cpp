#include "mce.onepole_tilde.hpp"

namespace mce {

void onepole_tilde::setup() {
    // put implementation here
}

sample onepole_tilde::operator()(sample input) {
    return onepole(input);
}
    
} // namespace mce

MIN_EXTERNAL(mce::onepole_tilde);
