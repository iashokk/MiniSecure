#include "minisec/handshake.h"
#include "minisec/crypto.h"
using namespace std;

namespace minisec {
HandshakeResult Handshake::run(const ClientHello& ch, const ServerHello& sh) {
  Transcript t;
  if (ch.version < "1") { // string compare for now
  return {false, "", "unsupported_version"};
}
  t.add("CH:" + ch.client_nonce + ":" + ch.version);
  if (!sh.accept) return {false, "", "rejected"};
  t.add("SH:" + sh.server_nonce + ":accept");
  auto session_key = derive_key(psk_, ch.client_nonce, sh.server_nonce);
  auto client_fin  = toy_hmac(session_key, t.str()+"client");
  t.add("CFIN:"+client_fin);
  auto server_fin  = toy_hmac(session_key, t.str()+"server");
  (void)server_fin; // placeholder for future verify logic
  return {true, session_key, ""};
}
}
