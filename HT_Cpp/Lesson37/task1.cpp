#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::vector<int> evenNumbers;

    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        if (*it % 2 == 0) {
            evenNumbers.push_back(*it);
        }
    }

    
    std::cout << "Even nums: ";
    for (std::vector<int>::iterator it = evenNumbers.begin(); it != evenNumbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

}
