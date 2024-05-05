#include <cmath>
#include <concepts>
#include <numbers>

namespace dsp {

template <typename number_t = DSP_NUMBER_TYPE>
requires std::floating_point<number_t>
struct onepole {
    static constexpr number_t twopi{ 2.0 * std::numbers::pi_v<number_t> };

    static number_t calculate_theta(number_t const ntwopiosr, number_t const frequency) {
        return std::exp(ntwopiosr * frequency);
    }

    static number_t calculate_a0(number_t const theta, number_t const gain) {
        return (1.0 - theta) * gain;
    }

    static number_t calculate_b1(number_t const theta) {
        return -theta;
    }

    onepole(number_t const samplerate = 44100.0,
            number_t const  frequency = 1000.0,
            number_t const       gain = 1.0
        ) :
            ntwopiosr{ -(twopi / samplerate) },
                theta{ calculate_theta(ntwopiosr, frequency) },
                 gain{ gain },
                   a0{ calculate_a0(theta, gain) },
                   b1{ calculate_b1(theta) }
    {}

    void set_frequency(number_t const value) {
        theta = calculate_theta(ntwopiosr, value);
        a0 = calculate_a0(theta, gain);
        b1 = calculate_b1(theta);
    }

    void set_gain(number_t const value) {
        a0 = calculate_a0(theta, value);
        b1 = calculate_b1(theta);    
    }

    number_t operator()(number_t const sample) {
        z1 = a0 * sample - b1 * z1;
		return z1;
    }

private:
    number_t const ntwopiosr;
    number_t theta;
    number_t gain;
    number_t a0, b1;
    number_t z1{};
};

} // namespace dsp
