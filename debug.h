/*
debug.h - A quick and dirty "framework" for printing debug information in C
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
debug.h allows the user to write stmts / blocks that are only executed of the source is
compiled with -DDEBUG flag.
debug.h is an STB style (https://github.com/nothings/stb) header file
that includes both the declaration and the implementation of the functions.


DEFINITIONS:

    MACROS:
        DEBUG_RUN           - to run a block of code that only run if -DDEBUG
                              is specified during compilation

USAGE:

#include <stdio.h>

#include "debug.h"

int main(void) {
    DEBUG_RUN({
        printf("This is a debug line\n");
    });
    return 0;
}

*/

#ifndef QD_TOOLS_DEBUG_H
#define QD_TOOLS_DEBUG_H

#ifdef DEBUG
#define IN_DEBUG 1
#else
#define IN_DEBUG 0
#endif

#define DEBUG_RUN(blk) \
    if (IN_DEBUG) (blk);

#endif  // QD_TOOLS_DEBUG_H