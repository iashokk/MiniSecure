#pragma once
#include <string>
#include <vector>

namespace minisec {

struct ClientHello { std::string client_nonce; std::string version="1"; };
struct ServerHello { std::string server_nonce; bool accept=true; };
//struct Finished    { std::string mac; };

struct Transcript {
  std::vector<std::string> records;
  void add(const std::string& r) { records.push_back(r); }
  std::string str() const {
    std::string out; for (auto& r : records) out += r + "\n"; return out;
  }
};

struct HandshakeResult {
  bool ok=false;
  std::string session_key;
  std::string error;
};

class Handshake {
 public:
  explicit Handshake(std::string psk): psk_(std::move(psk)) {}
  HandshakeResult run(const ClientHello& ch, const ServerHello& sh);

 private:
  std::string psk_;
};
}
