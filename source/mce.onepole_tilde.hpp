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

    attribute<number, threadsafe::no, limit::clamp>
              frequency { this, "frequency", 1000.0, range { 20.0, 20000.0 }, order { 1 }, title { "Frequency (Hz)" }, 
                          description { "Set the frequency in Hertz." }, 
                          setter { MIN_FUNCTION{ set_frequency(args[0]); return { frequency.get() }; } } };

    argument<number> frequency_argument { this, frequency.name(), "Sets the @frequency attribute.",
                                          MIN_ARGUMENT_FUNCTION { frequency = arg; } };

    message<> frequency_message { this, "number", description { "Sets the @frequency attribute." },
                                  MIN_FUNCTION { frequency = args[0]; return {}; } };
    
    attribute<number, threadsafe::no, limit::clamp>
              gain { this, "gain", 1.0, range { 0.01, 2.0 }, order { 2 }, title { "Gain (factor)" }, 
                     description { "Set the gain factor." }, 
                     setter { MIN_FUNCTION{ set_gain(args[0]); return { gain.get() }; } } };

    argument<number> gain_argument { this, gain.name(), "Sets the @gain attribute.",
                                     MIN_ARGUMENT_FUNCTION { gain = arg; } };

    message<> reset { this, "reset", description { "Resets the filter." },
                      MIN_FUNCTION { dspsetup(); return {}; } };

    message<> dspsetup { this, "dspsetup", MIN_FUNCTION { setup(); return {}; } };

    sample operator()(sample);

private:
    void set_frequency(number);
    void set_gain(number);
    void setup();

    dsp::onepole onepole{};
};

} // namespace mce
