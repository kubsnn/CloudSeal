#include <utils/utils.hpp>
#include <random>
#include <mutex>

namespace cloudseal::utils {

std::string generate_uuid() {
    static constexpr char hex[] = "0123456789abcdef";
    static std::mutex mutex;
    static std::mt19937_64 rng{std::random_device{}()};
    static std::uniform_int_distribution<uint64_t> dist(0, 15);

    std::lock_guard<std::mutex> lock(mutex);

    std::string uuid;
    uuid.reserve(36);

    for (int i = 0; i < 36; ++i) {
        if (i == 8 || i == 13 || i == 18 || i == 23) {
            uuid += '-';
        } else {
            uint8_t val = static_cast<uint8_t>(dist(rng));

            if (i == 14)
                val = 4; // UUID version 4
            else if (i == 19)
                val = (val & 0x3) | 0x8; // UUID variant 1

            uuid += hex[val];
        }
    }

    return uuid;
}

} // namespace cloudseal::utils