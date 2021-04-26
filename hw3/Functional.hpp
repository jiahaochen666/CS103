#ifndef HW3_FUNCTIONAL_HPP
#define HW3_FUNCTIONAL_HPP

#include <utility>

template <typename InputIt, typename Output, class BinaryOperation>
Output fold_left(InputIt first, InputIt last, Output init, BinaryOperation binary_op)
{
    while(first != last){
        init = binary_op(init, *first);
        first++;
    }
    return init;
}

template <typename InputIt1, typename InputIt2, typename OutputIt>
void zip(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, OutputIt out)
{
    while (first1 != last1 && first2 != last2){
        out = {*first1, *first2};
        ++first1;
        ++first2;
    }
}

template <typename InputIt, typename OutputIt1, typename OutputIt2>
void unzip(InputIt first, InputIt last, OutputIt1 out1, OutputIt2 out2)
{
    while (first != last){
        out1 = first->first;
        out2 = first->second;
        ++first;
    }
}

#endif
