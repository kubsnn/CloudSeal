#include <cloudseal/utils/utils.hpp>
#include <random>
#include <mutex>

namespace cloudseal::utils {


std::string generate_uuid() {
    static constexpr char alpha16[] = "abcdefghijklmnop"; // 16 liter
    static std::mutex mutex;
    static std::mt19937_64 rng{std::random_device{}()};
    static std::uniform_int_distribution<uint64_t> dist(0, 15);

    std::lock_guard<std::mutex> lock(mutex);

    std::string uuid;
    uuid.reserve(32); // 32 znaki, bez myślników

    for (int i = 0; i < 32; ++i) {
        uint8_t val = static_cast<uint8_t>(dist(rng));

        if (i == 12) {
            val = 4; // UUID version 4 (odpowiednik pozycji 14 z myślnikami)
        } else if (i == 16) {
            val = (val & 0x3) | 0x8; // UUID variant (pozycja 19)
        }

        uuid += alpha16[val];
    }

    return uuid;
}

} // namespace cloudseal::utils