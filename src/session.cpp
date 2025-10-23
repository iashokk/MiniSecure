#include "minisec/session.h"
using namespace std;
namespace minisec {
bool SessionStore::put(const Session& s) { return m_.emplace(s.id, s).second; }
Session SessionStore::get(const string& id) const {
  auto it = m_.find(id);
  if (it==m_.end()) return {};
  return it->second;
}
}
