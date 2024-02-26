#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

// Максимальное произведение трех чисел.
// https://new.contest.yandex.ru/42734/problem?id=6789665/2023_04_06/zjsSos3gqx

// Определить максимальное произведение 3х чисел последовательности.
// Индексы должны отличаться, но сами элементы могут быть равны.

template <typename T>
istream& operator>>(istream& in, vector<T>& vec) {
    for (T& element : vec) {
        in >> element;
    }
    return in;
}

int64_t MaxProductNums(vector<int64_t>& seq, int count_numbers = 3) {
    if (static_cast<int>(seq.size()) < count_numbers || seq.empty() || count_numbers < 3) {
        return 0;
    }
    sort(seq.begin(), seq.end());
    int64_t product = seq.back();
    const int64_t left = seq[0] * seq[1];
    const int64_t right = seq[seq.size() - 2] * seq[seq.size() - 3];
    product *= left > right &&  product > 0 ? left : right;
    return product;
}

namespace tests {
    void TestMaxProductNums() {
        {
            vector<int64_t> seq{1,2,3};
            assert(MaxProductNums(seq) == 6);
        }{
            vector<int64_t> seq{-1,-2,-2};
            assert(MaxProductNums(seq) == -4);
        }{
            vector<int64_t> seq{-1,-3,-2,-4};
            assert(MaxProductNums(seq) == -6);
        }{
            vector<int64_t> seq{-1,0,-3,-2,0};
            assert(MaxProductNums(seq) == 0);
        }{
            vector<int64_t> seq(200'000, 200'000);
            assert(MaxProductNums(seq) == 8'000'000'000'000'000);
        }{
            vector<int64_t> seq(200'000, -200'000);
            assert(MaxProductNums(seq) == -8'000'000'000'000'000);
        }{
            vector<int64_t> seq{-5,-2,0,1};
            assert(MaxProductNums(seq) == 10);
        }{
            vector<int64_t> seq{9,2,-3,-7};
            assert(MaxProductNums(seq) == 189);
        }{
            vector<int64_t> seq{-9,-8,8};
            assert(MaxProductNums(seq) == 576);
        }{
            vector<int64_t> seq{-9,-8,-7,5};
            assert(MaxProductNums(seq) == 360);
        }
        // невалидные запросы
        {
            vector<int64_t> seq{3,6};
            assert(MaxProductNums(seq) == 0);
        }{
            vector<int64_t> seq;
            assert(MaxProductNums(seq) == 0);
        }{
            vector<int64_t> seq{1,3,5,7};
            assert(MaxProductNums(seq, 9) == 0);
        }
        cerr << "TestMaxProductNums passed"s << endl;
    }
} // namespace tests


int main() {
    tests::TestMaxProductNums();
    int size = 0;
    cin >> size;
    vector<int64_t> seq(size);
    cin >> seq;
    cout << MaxProductNums(seq) << endl;
    return 0;
}
