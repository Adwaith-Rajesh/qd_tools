/*
test.h - A quick and dirty testing "framework" for C
Copyright (c) 2023 Adwaith Rajesh <adwaithrajesh3180[at]gmail[dot]com>

LICENSE: MIT

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

/*
The test.h file is supposed to be included in the C source file.
It is an STB style (https://github.com/nothings/stb) header file
that includes both the declaration and the implementation of the functions.

test.h is not supposed be used with multiple files, in the sense that
each source file that includes the test.h file must be compiled and ran
independently (This might be worked on in the future)


DEFINITIONS:

    MACROS:
        TEST        - create a test blocs
        ASSERT      - assert the given stmt (a simple if block)



USAGE:

// main_test.c

#define QD_TEST_IMPLEMENTATION
#define SHOW_FAIL_REASON  // prints the reason for failure
#define SHOW_TEST_STATISTICS
#include "test.h"

int main(void) {
    TEST("The name of the test", {
        ASSERT(1 == 2);
    });

    // prints the test statistics and also sets the exit code
    // 0 if all pass else 1
    return test_end_call();
}

*/

#ifndef QD_TOOLS_TEST_H
#define QD_TOOLS_TEST_H

#ifndef SHOW_FAIL_REASON
// fail reason off
#define TEST(name, block)                                       \
    {                                                           \
        int assert_pass = 1;                                    \
        block;                                                  \
        if (assert_pass == 0) {                                 \
            printf("\x1b[31m[FAILED]\x1b[0m: \x1b[33m" __FILE__ \
                   ":"                                          \
                   "%d\x1b[0m %s\n",                            \
                   __LINE__, name);                             \
        } else {                                                \
            printf("\x1b[32m[ PASS ]\x1b[0m: %s\n", name);      \
        }                                                       \
    }

#define ASSERT(exp)          \
    {                        \
        if (!(exp)) {        \
            assert_pass = 0; \
        }                    \
    }

#else
// fail reason on

#include <stdio.h>
#include <string.h>

char fail_reason[4096] = {0};

#define TEST(name, block)                                       \
    {                                                           \
        int assert_pass = 1;                                    \
        block;                                                  \
        if (assert_pass == 0) {                                 \
            printf("\x1b[31m[FAILED]\x1b[0m: \x1b[33m" __FILE__ \
                   ":"                                          \
                   "%d\x1b[0m %s -- %s\n",                      \
                   __LINE__, name, fail_reason);                \
        } else {                                                \
            printf("\x1b[32m[ PASS ]\x1b[0m: %s\n", name);      \
        }                                                       \
        memset(fail_reason, 0, 4096);                           \
    }

#define ASSERT(exp)                           \
    {                                         \
        if (!(exp)) {                         \
            assert_pass = 0;                  \
            strncpy(fail_reason, #exp, 4096); \
        }                                     \
    }
#endif

#endif  // main ifdef
