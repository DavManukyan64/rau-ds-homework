#include <iostream>
#include <forward_list>

void mergeSortedLists(std::forward_list<int>& fl1,
    std::forward_list<int>& fl2) {
    auto prev = fl1.before_begin();
    auto it1 = fl1.begin();
    auto it2 = fl2.begin();
    while (it1 != fl1.end() && it2 != fl2.end()) {
        if (*it2 < *it1) {
            fl1.insert_after(prev, *it2);
            prev = std::next(prev);
            ++it2;
        }
        else {
            prev = it1;
            ++it1;
        }
    }

    while (it2 != fl2.end()) {
        fl1.insert_after(prev, *it2);
        prev = std::next(prev);
        ++it2;
    }

    fl2.clear();
}

int main() {
    std::forward_list<int> fl1 = { 1, 3, 5 };
    std::forward_list<int> fl2 = { 2, 4, 6 };

    mergeSortedLists(fl1, fl2);

    for (int x : fl1) {
        std::cout << x << " ";
    }

    std::cout << std::endl;

    for (int x : fl2) {
        std::cout << x << " ";
    }

    return 0;
}
