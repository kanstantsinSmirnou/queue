#include <iostream>

#define lll long long

using namespace std;

class point {
   int x, y;
   public :
        point();
        point(int a, int b);
        int getX();
        int getY();
        void print();
};

void point::print() {
    std::cout << x << ' ' << y << '\n';
}

int point::getX() {
    return x;
}

int point::getY() {
    return y;
}

point::point() {
    x = 0;
    y = 0;
}

point::point(int a, int b) {
    x = a;
    y = b;
}

class queue {
    int n, uk, cnt;
    point* a;
    public :
        queue();
        queue(int sz);
        void enqueue(point& x);
        point dequeue();
        point front();
        bool empty();
        bool full();
        void clear();
        void resize(int sz);
        ~queue();
};

queue::queue() {
    cnt = 0;
    uk = 0;
    n = 15;
    a = new point[15];
}

queue::queue(int sz) {
    cnt = 0;
    uk = 0;
    n = sz;
    a = new point[sz];
}

void queue::enqueue(point& x) {
    if (!full()) {
        *(a + ((uk + cnt) % n)) = x;
        ++cnt;
    }
}

point queue::dequeue() {
    if (empty()) {
        return point();
    }
    uk = (uk + 1) % n;
    --cnt;
    return *(a + ((uk - 1 + n) % n));
}

point queue::front() {
    if (empty()) {
        return point();
    }
    return *(a + uk);
}

bool queue::empty() {
    return (!cnt);
}

bool queue::full() {
    return (cnt == n);
}

void queue::clear() {
    uk = 0;
    cnt = 0;
}

void queue::resize(int sz) {
    if (sz <= n) {
        return;
    }
    point* b = new point[sz];
    for (int i = 0; i < n; ++i) {
        b[(uk + i) % sz] = a[(uk + i) % n];
    }
    delete [] a;
    a = b;
    n = sz;
}

queue::~queue() {
    delete [] a;
}

