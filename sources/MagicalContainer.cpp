#include "MagicalContainer.hpp"

bool MagicalContainer::isPrime(int n)
{
    if(n <= 1)
        return false;
    if(n == 2)
        return true;
    if(n % 2 == 0)
        return false;
    for(int i = 3; i * i <= n; i++)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}

void MagicalContainer::addElement(int num) {
    auto it = std::lower_bound(container.begin(), container.end(), num);
    container.insert(it, num);
    if(isPrime(num))
    {
        int *pointer = new int(num);
        auto pointer_it = std::lower_bound(this->primes.begin(), this->primes.end(), pointer, [](const int* a, const int* b) { return *a < *b; });
        primes.insert(pointer_it, pointer);
    }
}

void MagicalContainer::removeElement(int num) {
    for (auto it = container.begin(); it != container.end() ;it++) {
        if(*it == num) {
            this->container.erase(it);
            return;
        }
    }
    throw std::runtime_error("does not exist");
}

size_t MagicalContainer::size() const {
    return this->container.size();
}