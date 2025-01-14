#include <cmath>
#include <concepts>
#include <numbers>

namespace dsp {

template <std::floating_point number_t = DSP_NUMBER_TYPE>
struct onepole {
    static constexpr number_t twopi { 2.0 * std::numbers::pi_v<number_t> };

    static constexpr number_t calculate_theta(number_t ntwopiosr, number_t frequency) noexcept {
        return std::exp(ntwopiosr * frequency);
    }

    static constexpr number_t calculate_a0(number_t theta, number_t gain) noexcept {
        return (1.0 - theta) * gain;
    }

    static constexpr number_t calculate_b1(number_t theta) noexcept {
        return -theta;
    }

    constexpr onepole(number_t samplerate = 44100.0,
                      number_t  frequency = 1000.0,
                      number_t       gain = 1.0
    ) noexcept :
        ntwopiosr { -(twopi / samplerate) },
        theta { calculate_theta(ntwopiosr, frequency) },
        gain { gain },
        state {
            .a0 { calculate_a0(theta, gain) },
            .b1 { calculate_b1(theta) }
        }
    {}

    constexpr void set_frequency(number_t value) noexcept {
        theta = calculate_theta(ntwopiosr, value);
        state.a0 = calculate_a0(theta, gain);
        state.b1 = calculate_b1(theta);
    }

    constexpr void set_gain(number_t value) noexcept {
        state.a0 = calculate_a0(theta, value);
        state.b1 = calculate_b1(theta);    
    }

    constexpr number_t operator ()(number_t sample) noexcept {
        return state(sample);
    }

private:
    number_t ntwopiosr;
    number_t theta;
    number_t gain;

    struct state_t {
        constexpr number_t operator ()(number_t sample) noexcept {
            z1 = a0 * sample - b1 * z1;
		    return z1;
        }

        number_t a0, b1;
        number_t z1 {};
    }
    state {};
};

} // namespace dsp
