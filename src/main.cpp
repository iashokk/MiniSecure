#include "minisec/handshake.h"
#include <iostream>
int main() {
  minisec::Handshake hs("psk-demo");
  auto res = hs.run({"c123","1"}, {"s456", true});
  std::cout << (res.ok ? "OK " : "FAIL ") << res.session_key << "\n";
  return res.ok ? 0 : 1;
}
