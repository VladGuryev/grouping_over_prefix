#ifndef FINDSTATS2_H
#define FINDSTATS2_H
#include <utility>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

//https://stackoverflow.com/questions/33428649/stdequal-range-with-lambda

//ГРУППИРОВКА ПО ПРЕФИКСУ
/**
 * функция находит с помощью partition_point upper and lower bounds в векторе
 * возвращает два итератора как у std::equal_range
 *
 * Это шаблоны для гибкого поиска по коллекции с использованием кастомной функции
 * Func custom_func в качестве функции сравнения
 */
template<class Iter, class T, class Func>
std::pair<Iter, Iter> my_equal_range2(Iter first, Iter last,
                                     const T& value, Func custom_func) {

    auto lower_bound_pred = [&](const auto& s) { return custom_func(s) < value; };
    auto b = std::partition_point(first, last, lower_bound_pred);

    auto upper_bound_pred = [&](const auto& s) { return !(value < custom_func(s)); };
    auto e = std::partition_point(b, last, upper_bound_pred);

    return {b, e};
}

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
        const string& prefix){

    size_t t = prefix.size();

    return my_equal_range2(range_begin, range_end, prefix,
                   [&t](const auto& s) { return s.substr(0, t); });
}
#endif // FINDSTATS2_H
