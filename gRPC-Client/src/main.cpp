#include <nlohmann/json.hpp>
#include <string>
#include <utils/utils.hpp>
#include <iostream>
using json = nlohmann::json;

int main(int argc, char** argv) {
	std::string uuid = cloudseal::utils::generate_uuid();
	std::cout << "UUID: " << uuid << std::endl;
	json j;
	j["uuid"] = uuid;
	std::cout << j.dump(4) << std::endl;
	return 0;
}