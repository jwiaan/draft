#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

class Ticket {
public:
  Ticket(const set<int> &reds, int blue) : _reds(reds), _blue(blue) {
    assert(reds.size() == 6);
  }

  pair<int, bool> test(const Ticket &t) const {
    int i = 0;
    for (auto a : t._reds) {
      if (_reds.find(a) != _reds.end())
        ++i;
    }

    return {i, _blue == t._blue};
  }

private:
  set<int> _reds;
  int _blue = 0;
};

int test(const pair<int, bool> &p) {
  static const map<pair<int, bool>, int> res = {
      {{6, true}, 1}, {{6, false}, 2}, {{5, true}, 3}, {{5, false}, 4},
      {{4, true}, 4}, {{4, false}, 5}, {{3, true}, 5},
  };

  auto it = res.find(p);
  if (it != res.end())
    return it->second;

  return p.second ? 6 : -1;
}

int main() {
  Ticket t = {{1, 2, 3, 4, 5, 6}, 7};
  vector<Ticket> v = {
      {{6, 5, 4, 3, 2, 1}, 7},
      {{6, 5, 4, 3, 2, 1}, 5},
      {{6, 9, 4, 3, 2, 1}, 7},
  };

  for (const auto &a : v)
    cout << test(t.test(a)) << endl;
}