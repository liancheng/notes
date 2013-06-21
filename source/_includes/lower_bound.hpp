template<typename Iterator, typename Value>
Iterator lower_bound (Iterator first, Iterator last, Value key) {
    while (first != last) {
        auto len = distance (first, last);
        auto mid = first + len / 2;

        if (*mid < key)
            first = mid + 1;
        else
            last = mid;
    }

    return first;
}
