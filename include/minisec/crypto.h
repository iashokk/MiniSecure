#pragma once
#include <string>

namespace minisec {
std::string toy_hash(const std::string& data);
std::string toy_hmac(const std::string& key, const std::string& data);
std::string derive_key(const std::string& psk,
                       const std::string& client_nonce,
                       const std::string& server_nonce);
}
