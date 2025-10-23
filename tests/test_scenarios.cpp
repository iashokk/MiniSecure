#include "minisec/handshake.h"
#include <cassert>
int main() {
  minisec::Handshake hs("psk-demo");
  auto ok = hs.run({"abc","1"}, {"xyz", true});
  assert(ok.ok);
  auto rej = hs.run({"abc","1"}, {"xyz", false});
  assert(!rej.ok);
  return 0;
}
