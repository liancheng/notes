template<typename Iterator, typename BinaryPredicate>
Iterator partition (Iterator first, Iterator last, BinaryPredicate pred)
{
    auto pos = first;

    for (; first != last; ++first)
        if (pred (*first))
            swap (*first, *pos++);

    return pos;
}

template<typename Iterator, typename LessThan>
Iterator top_k (Iterator first, Iterator last, size_t k, LessThan less)
{
    if (k >= distance (first, last))
        return last;

    typedef decltype (*first) value_type;

    auto pos;

    while (true) {
        pos = partition (first, last, [&] (value_type elem) {
            return !less (elem, *first);
        });

        auto length = distance (first, pos);

        if (length == k)
            break;

        if (length < k) {
            first = pos;
            k -= length;
        }
        else {
            last = pos;
        }
    }

    return pos;
}
