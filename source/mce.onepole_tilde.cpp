#include <memory>

#include "mce.onepole_tilde.hpp"

namespace mce {

void onepole_tilde::set_frequency(number value) {
    onepole.set_frequency(value);
}

void onepole_tilde::set_gain(number value) {
    onepole.set_gain(value);
}

void onepole_tilde::setup() {
    std::construct_at(&onepole,
                      samplerate(),
                      frequency.get(),
                      gain.get());
}

sample onepole_tilde::operator()(sample input) {
    return onepole(input);
}
    
} // namespace mce

MIN_EXTERNAL(mce::onepole_tilde);
