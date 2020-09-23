# Topics

Reference : <https://en.cppreference.com/w/>
Online Compiler/IDE for C++ : <http://cpp.sh/>

## Typecasting in C++ and C Traps and Pitfalls

[ ] [Typecasting in C++](http://www.cplusplus.com/doc/oldtutorial/typecasting/)
[ ] [C Traps and Pitfalls for C Programmers](https://www.slideshare.net/LegalizeAdulthood/c-traps-and-pitfalls-for-c-programmers)

## Namespaces and Pragma Once

[ ] [Namespaces](https://en.cppreference.com/w/cpp/language/namespace)
[ ] [#include guards](https://en.wikipedia.org/wiki/Include_guard) or [#pragma once](https://en.wikipedia.org/wiki/Pragma_once) (To avoid double inclusion of files)

## [inner_product](http://www.cplusplus.com/reference/numeric/inner_product/) and [domain_error](https://en.cppreference.com/w/cpp/error/domain_error)

### `inner_product`

Computes inner product \(i.e. sum of products\) or performs ordered map/reduce operation on the range \[first1, last1\) and the range beginning at first2.
The behavior of this function template is equivalent to:

```cpp
  template <class InputIterator1, class InputIterator2, class T>
    T inner_product (InputIterator1 first1, InputIterator1 last1,
                      InputIterator2 first2, T init, BinaryOperation1 binary_op1,
                    BinaryOperation2 binary_op2)
  {
    while (first1!=last1) {
      init = init + (*first1)*(*first2);
                // or: init = binary_op1 (init, binary_op2(*first1,*first2));
      ++first1; ++first2;
    }
    return init;
}
```

### `domain_error`

Defines a type of object to be thrown as exception. It may be used by the implementation to report domain errors, that is, situations where the inputs are outside of the domain on which an operation is defined
