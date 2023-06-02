#include "doctest.h"
#include "sources/MagicalContainer.hpp"


TEST_CASE("init container and compartor")
{
    CHECK_NOTHROW(MagicalContainer container);
    MagicalContainer cont;
    CHECK_NOTHROW(cont.addElement(1));
    CHECK_NOTHROW(cont.size());
    CHECK_NOTHROW(cont.removeElement(1));
    cont.addElement(1);
    cont.addElement(2);
    cont.addElement(3);
    CHECK_NOTHROW(MagicalContainer::SideCrossIterator it(cont));
    CHECK_NOTHROW(MagicalContainer::PrimeIterator it(cont));
    CHECK_NOTHROW(MagicalContainer::AscendingIterator it(cont));

}

TEST_CASE("Removing elements from the MagicalContainer")
{
    MagicalContainer container;
    CHECK(container.size() == 0);
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    CHECK(container.size() == 3);
    container.removeElement(1);
    CHECK(container.size() == 2);

    MagicalContainer::AscendingIterator it(container);
    CHECK(*it == 2);
    ++it;
    CHECK(*it == 3);
    ++it;
}

TEST_CASE("Iterating over the MagicalContainer with SideCrossIterator")
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);

    MagicalContainer::AscendingIterator it(container);

    CHECK(*it == 1);
    ++it;
    CHECK(*it == 2);
    ++it;
    CHECK(*it == 3);
    ++it;
    CHECK(*it == 4);
    ++it;
    CHECK(*it == 5);
    ++it;

    CHECK(it == MagicalContainer::AscendingIterator(container, container.size()));
}

TEST_CASE("Iterating over the MagicalContainer with SideCrossIterator")
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);

    MagicalContainer::SideCrossIterator it(container);

    CHECK(*it == 1);
    ++it;
    CHECK(*it == 5);
    ++it;
    CHECK(*it == 2);
    ++it;
    CHECK(*it == 4);
    ++it;
    CHECK(*it == 3);
    ++it;

    CHECK(it == MagicalContainer::SideCrossIterator(container, container.size()));
}

TEST_CASE("Iterating over the MagicalContainer with PrimeIterator")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(4);
    container.addElement(1);
    container.addElement(3);

    MagicalContainer::PrimeIterator it(container);

    CHECK(*it == 2);
    ++it;
    CHECK(*it == 3);
    ++it;
    CHECK(*it == 5);
    ++it;

    CHECK(it == MagicalContainer::PrimeIterator(container, container.size()));
}

TEST_CASE("Comparing iterators of the same type")
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);

    // Create some iterators of different types
    MagicalContainer::AscendingIterator it1(container);    // points to 1
    MagicalContainer::AscendingIterator it2(container, 2); // points to 3
    MagicalContainer::SideCrossIterator it3(container);    // points to 1
    MagicalContainer::SideCrossIterator it4(container, 4); // points to 3
    MagicalContainer::PrimeIterator it5(container);        // points to 2
    MagicalContainer::PrimeIterator it6(container, 3);     // points to 5

    CHECK(it1 == it1);
    CHECK(it1 != it2);
    CHECK(it3 == it3);
    CHECK(it3 != it4);
    CHECK(it5 == it5);
    CHECK(it5 != it6);

    CHECK(it1 < it2);
    CHECK(it2 > it1);
    CHECK(it3 < it4);
    CHECK(it4 > it3);
    CHECK(it5 < it6);
    CHECK(it6 > it5);
}