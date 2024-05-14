#include <cmath>
#include <concepts>
#include <numbers>

namespace dsp {

template <typename number_t = DSP_NUMBER_TYPE>
requires std::floating_point<number_t>
struct onepole {
    constexpr static number_t const twopi{ 2.0 * std::numbers::pi_v<number_t> };

    constexpr static number_t calculate_theta(number_t ntwopiosr, number_t frequency) exspec {
        return std::exp(ntwopiosr * frequency);
    }

    constexpr static number_t calculate_a0(number_t theta, number_t gain) exspec {
        return (1.0 - theta) * gain;
    }

    constexpr static number_t calculate_b1(number_t theta) exspec {
        return -theta;
    }

    constexpr onepole(number_t samplerate = 44100.0,
                      number_t  frequency = 1000.0,
                      number_t       gain = 1.0
    ) exspec :
        ntwopiosr{ -(twopi / samplerate) },
            theta{ calculate_theta(ntwopiosr, frequency) },
             gain{ gain },
               a0{ calculate_a0(theta, gain) },
               b1{ calculate_b1(theta) }
    {}

    constexpr void set_frequency(number_t value) exspec {
        theta = calculate_theta(ntwopiosr, value);
        a0 = calculate_a0(theta, gain);
        b1 = calculate_b1(theta);
    }

    constexpr void set_gain(number_t value) exspec {
        a0 = calculate_a0(theta, value);
        b1 = calculate_b1(theta);    
    }

    constexpr number_t operator()(number_t sample) exspec {
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
