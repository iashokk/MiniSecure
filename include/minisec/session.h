#pragma once
#include <string>
#include <unordered_map>

namespace minisec {
struct Session {
  std::string id;
  std::string key;
  bool resumed=false;
};
class SessionStore {
 public:
  bool put(const Session& s);
  Session get(const std::string& id) const; // empty if not found
 private:
  std::unordered_map<std::string, Session> m_;
};
}
