#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>


template <typename I, typename N>
N average(I iter, N num) {
    int counter = 0;
    for (auto &i: iter) {
        num += i;
        counter++;
    }
    return num / counter;
}

template<typename T>
class Greater_than{
private:
    T data;
public:
    explicit Greater_than(T data): data(data){};
    bool operator()(T num){
        return num > data;
    }
};

int main() {
    std::vector<int> lte_50;
    std::vector<int> gt_50;
    Greater_than<int> over_50{50};
    double avg_gt;
    int i, avg_lte;

    while (std::cin >> i) {
        if (over_50(i)) {
            gt_50.push_back(i);
        } else {
            lte_50.push_back(i);
        }
    }

    avg_lte = average(lte_50, 0);
    avg_gt = average(gt_50, 0.0);

    std::cout << avg_lte << std::endl << std::setprecision(2) << avg_gt;
}

