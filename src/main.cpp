#include "minisec/handshake.h"
#include "minisec/transport_sim.h"
#include <iostream>
int main() {
  minisec::Handshake hs("psk-demo");
  auto res = hs.run({"c123","1","http/1.1",false}, {"s456", true});
  std::cout << (res.ok ? "OK " : "FAIL ") << res.session_key << "\n";
  minisec::TransportSim net;
  net.send({"hello"});
  (void)net.recv();
  return res.ok ? 0 : 1;
}
