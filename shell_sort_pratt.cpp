#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <set>
#include <chrono>

using namespace std;
using namespace chrono;

#define vi vector<int>

void print(vi a){
    for (auto it = a.begin(); it != a.end(); ++it){
        cout << *it << ' ';
    };
    cout << endl;
    return;
}

set<int> smooth_nums_upto(int n){
    set<int> a;
    for (int i = 0; i < log2(n) + 1; i++){
        for (int j = 0; j < log2(n)/log2(3) + 1; j++){
            int x = pow(2,i) * pow(3,j);
            if (x > n) break;
            a.insert(x);
        }
    }
    return a;
}

vi shell_sort(vi a){
    int n = a.size();
    auto b = smooth_nums_upto(n/2);
    for (auto it = b.rbegin(); it != b.rend(); ++it){
        int h = *it;
        for (int i = h; i < n; i++){
            int temp = a[i];
            int j = i;
            for (; j >= h && a[j-h] > temp; j -= h){
                a[j] = a[j-h];
            }
            a[j] = temp;
        }
    }
    return a;
}

auto time_shell(vi a){
    auto start = steady_clock::now();
    shell_sort(a);
    auto end = steady_clock::now();
    return (end-start).count()*1e-9;
}

auto time_usual(vi a){
    auto start = steady_clock::now();
    sort(a.begin(), a.end());
    auto end = steady_clock::now();
    return (end-start).count()*1e-9;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for (int n = 1e3; n < 1e6; n *= 10){

        vi a(n);

        mt19937 rng(time(nullptr));
        for (int i = 0; i < n; i++)
            a[i] = rng()%1000;

        cout << "n = " << n << endl;
        cout << "Моя сортировка " << time_shell(a) << endl;
        cout << "Обычная сортировка " << time_usual(a) << endl;
        cout << endl;

    }

    return 0;
}