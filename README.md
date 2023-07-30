# QD Tools

## Quick and Dirty tools for developing in C

---

#### WARNING

THE TOOLS PROVIDED HAVE NO GUARANTEE OF WORKING AND ARE MEANT TO BE USED WITH CAUTION. THE TOOLS ITSELF MAY BREAK.

Eg. YOUR TEST MAY FAIL BECAUSE THE TESTING TOOL IS NOT WORKING PROPERLY.

<span style="color: red">USE IT WITH CAUTION</span>

## test.h

A simple testing "framework" for C

- Without fail reason

```c
// main_test.c
#include "test.h"

int main(void) {
    TEST("A simple test block", {
        ASSERT(1 == 1);
    });

    TEST("A failing block", {
        ASSERT(2 == 3);
    });

    return 0;
}
```

- Compile and run

```console
$ gcc main_test.c -o main_test && ./main_test

[ PASS ]: A simple test block
[FAILED]: main_test.c:8 A failing block
```

> It prints the filename and the line no. of the failed TEST.

- With fail reasons and test statistics

```c
// main_test.c
#define SHOW_FAIL_REASON
#define SHOW_TEST_STATISTICS
#include "test.h"


int main(void) {
    TEST("A simple test block", {
        ASSERT(1 == 1);
    });

    TEST("A failing block", {
        ASSERT(2 == 3);
    });

    TEST("Explicit Fail", {
        ASSERT_FAIL();
    });

    TEST("Explicit Fail with Reason", {  // requires SHOW_FAIL_REASON
        ASSERT_FAIL_W_REASON("Because it was wrong")
    });

    // test_end_call() requires SHOW_TEST_STATISTICS and
    // sets the exit code to EXIT_FAILURE if failed test exists
    return test_end_call();
}
```

- Compile and run

```console
$ gcc main_test.c -o main_test && ./main_test

[ PASS ]: A simple test block
[FAILED]: main_test.c:10 A failing block -- 2 == 3
[FAILED]: main_test.c:14 Explicit Fail --
[FAILED]: main_test.c:18 Explicit Fail with Reason -- Because it was wrong
Total: 4 -- Passed: 1 -- Failed: 3

$ echo $?
1
```

---

## debug.h

Docs on the way
