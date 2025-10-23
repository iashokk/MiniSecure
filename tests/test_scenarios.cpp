#include "minisec/handshake.h"
#include <cassert>
int main() {
  minisec::Handshake hs("psk-demo");
  auto ok = hs.run({"abc","1"}, {"xyz", true});
  assert(ok.ok);
  auto rej = hs.run({"abc","1"}, {"xyz", false});
  assert(!rej.ok);
  auto res = hs.run({"c123","1","http/1.1",false}, {"s456", true});
  return 0;
}
