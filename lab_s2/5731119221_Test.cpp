#include <iostream>
#include <assert.h>
#include <queue>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <string>
#include <utility>
#include <vector>
#include <map>
using namespace std;

bool test1 () {
    size_t num = 3;
    queue <int> a;
    queue <int> b (a);
    queue <int> c = b;
    assert (a.size() == 0);
    assert (a == b && b == c);
    return true;
}

bool test2 () {
    queue <int> a;
    assert (a.size() == 0);
    assert (a.empty());
    a.push(1);
    a.push(2);
    a.push(3);

    assert (a.front() == 1);
    assert (a.back() == 3);
    assert (a.size() == 3);
    assert (a.size() == 3); //check const

    for (int i = 0 ; i < 100000 ; i++)
        a.push(i+4);

    assert(a.size() == 100003);
    assert (a.front() == 1);
    assert (a.back() == 100003);

    a.pop();
    assert (a.front() == 2);

    for (int i = 0 ; i < 50000 ; i++)
        a.pop();

    assert (a.size() == 50002);
    assert (a.front() == 50002);
    assert (a.back() == 100003);

    return true;
}

bool test3 () {
    queue <queue <vector <pair <int, int> > > > a;
    pair<int, int> p;
    vector <pair<int, int> > v;
    p = make_pair(20, 10);
    v.push_back(p);

    queue <vector <pair <int, int> > > q;
    q.push(v);
    a.push(q);

    assert (a.front() == q);
    assert (((a.front()).front())[0].first == 20);

    v.pop_back();
    a.pop();
    q.pop();

    map <int, int> m;
    for (int i = 0 ; i < 50 ; i++) {
        m[i%5]++;
    }
    for (auto &x : m) {
        v.push_back(x);
    }

    q.push(v);
    a.push(q);

    assert (a.front() == q);
    assert (((a.front()).front()).size() == 5);

    return true;
}



int main() {
  if (test1()) std::cout << "Test1 (Constructor) OK!" << std::endl;
  if (test2()) std::cout << "Test2 (Function) OK!" << std::endl;
  if (test3()) std::cout << "Test3 (Compound) OK!" << std::endl;

  return 0;
}
