# Topics

## Index

- [Move Semantics in C++]()
- [hidden `this` pointer]()
- [inner_product and domain_error]()
- [classes]()
- [Typecasting]()
- [C Traps and Pitfalls]()

Reference : <https://en.cppreference.com/w/>
Online Compiler/IDE for C++ : <http://cpp.sh/>

## Typecasting in C++ and C Traps and Pitfalls

- [ ] [Typecasting in C++](http://www.cplusplus.com/doc/oldtutorial/typecasting/)
- [ ] [C Traps and Pitfalls for C Programmers](https://www.slideshare.net/LegalizeAdulthood/c-traps-and-pitfalls-for-c-programmers)

## Namespaces and Pragma Once

- [ ] [Namespaces](https://en.cppreference.com/w/cpp/language/namespace)
- [ ] [#include guards](https://en.wikipedia.org/wiki/Include_guard) or [#pragma once](https://en.wikipedia.org/wiki/Pragma_once) (To avoid double inclusion of files)

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

### **[hidden `this` pointer](https://www.learncpp.com/cpp-tutorial/8-8-the-hidden-this-pointer/)**

## Important Topics

### Classes

1. Constructors (Use of [`braces {}`](https://www.cplusplus.com/reference/initializer_list/initializer_list/) vs `parenthesis ()` for constructors for initializations)
2. _Benefits of using an `inline Constructor/Member Function` vs `Normal (non-inline) Constructor/ Member Function`_
3. Member Intialization

### **Move Semantics**

The best resource for understanding move semantics is a book: [Effective Modern C++](https://www.oreilly.com/library/view/effective-modern-c/9781491908419/) by Scott Meyers.
You might also like the two conference talks: At CppCon 2019 Klaus Iglberger gave a long talk titled "Back to Basics: Move Semantics" ([part 1](https://youtu.be/St0MNEU5b0o), [part 2](https://youtu.be/pIzaZbKUw2s)). At CppCon 2020 David Olsen gave a slightly shorter talk titled [Back to Basics: Move Semantics](https://youtu.be/ZG59Bqo7qX4).
Some programmers like the videos from TheCherno (but for me he's too informal and he makes some small mistakes). Here is he talking about [Move Semantics in C++](https://youtu.be/ehMg6zvXuMY).
