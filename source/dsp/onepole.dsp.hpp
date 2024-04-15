#include <numbers>

namespace dsp {

struct onepole {
#ifdef DSP_NUMBER_TYPE
    using number = DSP_NUMBER_TYPE;
#else
    using number = double;
#endif

    static constexpr number twopi{ 2.0 * std::numbers::pi_v<number> };

    number operator()(number sample) {
        // put implementation here
        return sample;
    }
};

} // namespace dsp
