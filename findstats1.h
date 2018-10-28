#ifndef FINDSTATS1_H
#define FINDSTATS1_H
#include <utility>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

//ГРУППИРОВКА ПО СИМВОЛУ
/**
 * функция находит с помощью partition_point upper and lower bounds в векторе
 * возвращает два итератора как у std::equal_range
 *
 * Это шаблоны для гибкого поиска по коллекции с использованием кастомной функции Func custom_func
 * в качестве функции сравнения
 */
//template<class Iter, class T, class Func>
//std::pair<Iter, Iter> my_equal_range(Iter first, Iter last,
//                                     const T& value, Func custom_func) {

//    auto lower_bound_pred = [&](const auto& s) { return custom_func(s) < value; };
//    auto b = std::partition_point(first, last, lower_bound_pred);

//    auto upper_bound_pred = [&](const auto& s) { return !(value < custom_func(s)); };
//    auto e = std::partition_point(b, last, upper_bound_pred);

//    return {b, e};
//}

/*
 * более сложная версия реализации функции
template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
        RandomIt range_begin, RandomIt range_end,
        char prefix)
{
    return my_equal_range(range_begin, range_end, prefix,
                   [](const auto& s) { return s.front(); });
}
*/

/**
 * упрощенная версия поиска в векторе строк по префиксу
 */
template<class Iter>
pair<Iter, Iter> FindStartsWith(Iter first, Iter last,
                                     char value) {

    auto lower_bound_pred = [&](const auto& s) { return s.front() < value; };
    auto b = std::partition_point(first, last, lower_bound_pred);

    auto upper_bound_pred = [&](const auto& s) { return !(value < s.front()); };
    auto e = std::partition_point(b, last, upper_bound_pred);

    return {b, e};
}

#endif // FINDSTATS1_H
