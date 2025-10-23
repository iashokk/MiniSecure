#pragma once
#include <string>
namespace minisec {
struct Packet { std::string data; };
struct TransportSim {
  void send(const Packet& p) { last = p.data; }
  std::string recv() const { return last; }
 private:
  std::string last;
};
}
