#include <c74_min.h>

#include "dsp/onepole.dsp.hpp"

namespace mce {

using namespace c74::min;

struct onepole_tilde : object<onepole_tilde>, sample_operator<1, 1>
{
    MIN_DESCRIPTION { "Onepole filter. "
                      "Implementation of a simple onepole lowpass filter." };
    MIN_AUTHOR      { "Thomas Lieb" };
    MIN_TAGS        { "filter" };
    MIN_RELATED     { "onepole~" };

    inlet<>  input  { this, "(signal) input", "signal" };
    outlet<> output { this, "(signal) output", "signal" };

    message<> dspsetup { this, "dspsetup", MIN_FUNCTION { setup(); return {}; } };

    sample operator()(sample);

private:
    void setup();

    dsp::onepole onepole{};
};

} // namespace mce
