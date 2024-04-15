namespace dsp {

struct onepole {
#ifdef DSP_NUMBER_TYPE
    using number = DSP_NUMBER_TYPE;
#else
    using number = double;
#endif

    number operator()(number sample) {
        // put implementation here
        return sample;
    }
};

} // namespace dsp
