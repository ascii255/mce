#include <cmath>
#include <numbers>

namespace dsp {

struct onepole {
#ifdef DSP_NUMBER_TYPE
    using number = DSP_NUMBER_TYPE;
#else
    using number = double;
#endif

    static constexpr number twopi{ 2.0 * std::numbers::pi_v<number> };

    static number calculate_theta(number ntwopiosr, number frequency) {
        return std::exp(ntwopiosr * frequency);
    }

    static number calculate_a0(number theta, number gain) {
        return (1.0 - theta) * gain;
    }

    static number calculate_b1(number theta) {
        return -theta;
    }

    onepole(number samplerate = 44100.0,
            number  frequency = 1000.0,
            number       gain = 1.0
        ) :
            ntwopiosr{ -(twopi / samplerate) },
            theta{ calculate_theta(ntwopiosr, frequency) },
             gain{ gain },
               a0{ calculate_a0(theta, gain) },
               b1{ calculate_b1(theta) }
    {}

    void set_frequency(number value) {
        theta = calculate_theta(ntwopiosr, value);
        a0 = calculate_a0(theta, gain);
        b1 = calculate_b1(theta);
    }

    void set_gain(number value) {
        a0 = calculate_a0(theta, value);
        b1 = calculate_b1(theta);    
    }

    number operator()(number sample) {
        z1 = a0 * sample - b1 * z1;
		return z1;
    }

private:
    number const ntwopiosr;
    number theta;
    number gain;
    number a0, b1;
    number z1{};
};

} // namespace dsp
