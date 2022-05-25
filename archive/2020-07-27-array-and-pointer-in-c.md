---
layout: post
title:  C 语言中指针和数组的异同点
date:   2020-07-27 14:27:12 +0800
tags:   C
---

这大概算是一个比较容易混淆的知识点。摘抄几段，来自[Arrays, String Constants and Pointers][Arrays, String Constants and Pointers]

    This is one of the most confusing parts of C, so here are three different ways of stating the difference between an array a and a pointer p which points to the first element of a :
    The technical explanation: arrays are accessed using direct addressing, pointers are accessed using indirect addressing
    The less technical explanation: a is an address, p is an address which holds the address of a
    The extremely wordy explanation: to retrieve value from a[n], the computer starts at address a, moves n past it and fetches value from there; to retrieve value from p[n], the computer starts at address p, fetches the address stored there and adds n to it, then fetches value from the resulting address

    Most of the time, however, pointer and array accesses can be treated as acting the same, the major exceptions being:
    the sizeof operator
        sizeof(array) returns the amount of memory used by all elements in array
        sizeof(pointer) only returns the amount of memory used by the pointer variable itself
    the & operator
        &array is an alias for &array[0] and returns the address of the first element in array
        &pointer returns the address of pointer
    a string literal initialization of a character array
        char array[] = "abc" sets the first four elements in array to 'a', 'b', 'c', and '\0'
        char *pointer = "abc" sets pointer to the address of the "abc" string (which may be stored in read-only memory and thus unchangeable)
    Additionally, an array cannot be resized or reassigned

指针的算数操作：

    ptr++ increments ptr by the appropriate amount to reach the next entry of ptr's datatype
    If, for example, ptr points to address 0xff00:
        if ptr is a char, ptr++ will set ptr to 0xff01
        if ptr is an int (and an int is 4 bytes long), ptr++ will set ptr to 0xff04
    If ptr1 is pointing at a[0] and ptr2 is pointing at a[3], then ptr2 - ptr1 returns the integer value 3, no matter what the datatype of a is
    Similarly, equality, inequality and other arithmetic relations all work appropriately, as long as the pointers being compared both point to the same group of elements
        That is, if a and b are different arrays, then given ptr1 = &a[0] and ptr2 = &b[0], it is impossible to predict whether ptr1 < ptr2 or ptr1 > ptr2 (though ptr1 != ptr2 will always be true)

另外一个文档是：[Essential C][Essential C]，文档来源：[Essential C][Essential C Source]

[Arrays, String Constants and Pointers]: https://icecube.wisc.edu/~dglo/c_class/array_ptr.html
[Essential C]: /assets/docs/EssentialC.pdf
[Essential C Source]: http://cslibrary.stanford.edu/101/EssentialC.pdf
