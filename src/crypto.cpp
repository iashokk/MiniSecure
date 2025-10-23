#include "minisec/crypto.h"
#include <functional>
#include <string>
using namespace std;

namespace minisec {
static string to_hex(size_t v) {
  static const char* d = "0123456789abcdef";
  string out;
  for (int i=(int)(sizeof(size_t)*2)-1; i>=0; --i)
    out.push_back(d[(v >> (i*4)) & 0xF]);
  return out;
}

string toy_hash(const string& data) {
  return to_hex(std::hash<string>{}(data));
}

string toy_hmac(const string& key, const string& data) {
  auto a = std::hash<string>{}(key + data);
  auto b = std::hash<string>{}(data + key);
  return to_hex(a ^ b);
}

string derive_key(const string& psk, const string& c, const string& s) {
  return toy_hash(psk + "|" + c + "|" + s);
}
}
