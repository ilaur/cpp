#include <iostream>

/// helper function
void print(long long n, long long* v) {
    std::cout<<"\n";
    for(long long i=0; i<n; ++i)
        std::cout<<' '<<v[i];
    std::cout<<"\n";
}

/// a)
void flip(long long* v, long long i, long long j) {
    --i;
    --j;
    while(i<j) {
        long long aux = v[j];
        v[j] = v[i];
        v[i] = aux;
        --j;
        ++i;
    }
}
///O(n);

/// b)
void vsort() {
    long long n=0;
    std::cin>>n;
    long long* v = new long long[n];
    for(long long i=0; i<n; ++i)
        std::cin>>v[i];
    for(long long i=0; i<n; ++i) {
        long long k=i;
        for(long long j=i+1; j<n; ++j) {
            if(v[k]>v[j]) {
                k=j;
            }
        }
        flip(v, i+1, k+1);
    }
    print(n, v);
    delete[] v;
}
///O(n^2);

/// c)
void flip(long long n, long long* v, long long i, long long j) {
    long long m = n/2;
    if(m<=1) {
        return;
    }
    while(m>2) {
        flip(v, i, j);
        m/=2;
    }
}

void vmergesort() {
    /*long long n=0;
    std::cin>>n;
    long long* v = new long long[n];
    for(long long i=0; i<n; ++i)
        std::cin>>v[i];*/
    long long v1[]={2, 1, 4, 3};
    long long n1 = 4;
    long long v2[]={14, 13, 15, 16, 11, 12, 9, 19, 2 ,1, 4, 3, 8, 7, 6, 5};
    long long n2=16;
    flip(n1, v1, 1, n1);
    flip(n2, v2, 1, n2);
    print(n1, v1);
    print(n2, v2);
    ///delete[] v;
}
///O(log(n));

int main() {
    vmergesort();
    return 0;
}
