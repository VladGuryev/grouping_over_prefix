#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include "findstats1.h"
#include "findstats2.h"
using namespace std;

int main()
{
    /*
    const vector<string> sorted_strings = {"moscow", "murmansk", "vologda"};

    const auto m_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
    for (auto it = m_result.first; it != m_result.second; ++it) {
    cout << *it << " ";
    }
    cout << endl;

    const auto p_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
    cout << (p_result.first - begin(sorted_strings)) << " " <<
      (p_result.second - begin(sorted_strings)) << endl;

    const auto z_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
    cout << (z_result.first - begin(sorted_strings)) << " " <<
      (z_result.second - begin(sorted_strings)) << endl;
      */

    //----------------------------------------------------------------//
     vector<string> sorted_strings =  {"moscow", "motovilikha", "murmansk",
                                            "newyourk", "cherepovec", "chelyabinsk",
                                           "chernobyl"};

    sort(sorted_strings.begin(),sorted_strings.end());
    const auto mo_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), "ne");
    for (auto it = mo_result.first; it != mo_result.second; ++it) {
      cout << *it << " ";
    }
    cout << endl;

    const auto mt_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
    cout << (mt_result.first - begin(sorted_strings)) << " " <<
        (mt_result.second - begin(sorted_strings)) << endl;

    const auto na_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
    cout << (na_result.first - begin(sorted_strings)) << " " <<
        (na_result.second - begin(sorted_strings)) << endl;

    return 0;
}
