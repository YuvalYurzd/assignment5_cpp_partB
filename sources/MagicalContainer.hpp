#pragma once
#include "iostream"
#include "vector"
#include "algorithm"
namespace ariel
{

}
class MagicalContainer {
public:
    std::vector<int> container;
    std::vector<int*> primes;

    MagicalContainer(){}
    ~MagicalContainer(){for (int* ptr : primes) {
    delete ptr;
}}
    void addElement(int num);
    void removeElement(int num);
    size_t size() const;
    bool isPrime(int n);
    class AscendingIterator{
    public:

        MagicalContainer*container;
        size_t index;
        int type = 1;

        AscendingIterator(MagicalContainer& container);
        AscendingIterator(MagicalContainer& container, size_t index);
        AscendingIterator(const AscendingIterator& other);
        ~AscendingIterator(){}

        AscendingIterator begin() const;
        AscendingIterator end() const;

        AscendingIterator& operator=(const AscendingIterator& other);
        bool operator==(const AscendingIterator& other) const;
        bool operator!=(const AscendingIterator& other) const;
        bool operator<(const AscendingIterator& other) const;
        bool operator>(const AscendingIterator& other) const;
        int operator*();
        AscendingIterator& operator++();

    };
    class PrimeIterator{
    public:

        MagicalContainer* container;
        size_t index;
        int type = 2;

        PrimeIterator(MagicalContainer& container);
        PrimeIterator(MagicalContainer &container, size_t index);
        PrimeIterator(const PrimeIterator& other);
        ~PrimeIterator(){}

        PrimeIterator begin() const;
        PrimeIterator end() const;

        PrimeIterator& operator=(const PrimeIterator& other);
        bool operator==(const PrimeIterator& other) const;
        bool operator!=(const PrimeIterator& other) const;
        bool operator<(const PrimeIterator& other) const;
        bool operator>(const PrimeIterator& other) const;
        int operator*();
        PrimeIterator& operator++();
    };
    class SideCrossIterator{
        public:

        MagicalContainer* container;
        size_t index;
        size_t side_index;

        SideCrossIterator(MagicalContainer& container);
        SideCrossIterator(MagicalContainer& container, size_t index);
        SideCrossIterator(const SideCrossIterator& other);
        ~SideCrossIterator(){}

        SideCrossIterator begin() const;
        SideCrossIterator end() const;

        SideCrossIterator& operator=(const SideCrossIterator& other);
        bool operator==(const SideCrossIterator& other) const;
        bool operator!=(const SideCrossIterator& other) const;
        bool operator<(const SideCrossIterator& other) const;
        bool operator>(const SideCrossIterator& other) const;
        int operator*();
        SideCrossIterator& operator++();
    };
};
