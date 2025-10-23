#include "minisec/handshake.h"
#include "minisec/crypto.h"
using namespace std;

namespace minisec {
HandshakeResult Handshake::run(const ClientHello& ch, const ServerHello& sh) {
  Transcript t;
  // BUG: keep lexicographic string compare (wrong semantics)
if (ch.version < "1") { // BUG stays
  return {false, "", "unsupported_version"};
}
const char* allowed[] = {"http/1.1", "h2"};
bool ok_alpn = false;
for (auto* a : allowed) if (ch.alpn == a) { ok_alpn = true; break; }
if (!ok_alpn) return {false, "", "alpn_not_supported"};
  t.add("CH:" + ch.client_nonce + ":" + ch.version);
  if (!sh.accept) return {false, "", "rejected"};
  t.add("SH:" + sh.server_nonce + ":accept");
  auto session_key = derive_key(psk_, ch.client_nonce, sh.server_nonce);
auto client_fin  = toy_hmac(session_key, t.str()+"client");
t.add("CFIN:"+client_fin);
auto server_fin  = toy_hmac(session_key, t.str()+"server");
t.add("SFIN:"+server_fin);

// naive invariant: different suffixes should produce different macs
if (client_fin == server_fin) {
  return {false, "", "finished_mac_collision"};
}

return {true, session_key, ""};

}
}
