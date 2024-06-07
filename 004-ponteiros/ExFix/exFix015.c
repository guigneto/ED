 #include <stdio.h>

 int main(){

    int x = 10, *px = &x, **ppx = &x;
    float y = 5.9, *py = &y, **ppy = &py;

    /*
    a) x = 10
    b) *py = 5.9
    c) px = FFA0
    d) &y = FFB4
    e) *px = 10
    f) y = 5.9
    g) *ppx = 10
    h) py = FFB4
    i) &x = FFA0
    j) py++ = FFB5
    k) *px-- = 9
    l) **ppy = 5.9
    m) &ppy = FFA6
    n) *&px = px = FFA0
    o) **ppx++ = 11
    p) px++ = FFA1
    q) &ppx = FFD4
    */


    return 0;
 }