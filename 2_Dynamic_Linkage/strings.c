/***

    Ch-02 : Dynamic Linkage

    gcc -g -o main -Wall -Wextra -pedantic -Wwrite-strings -fsanitize=address *.c -lm

    Date: Wed 19 Feb 2025 03:36:51 PM PST
    Folsom, CA.
 */

/*----------------------------------- Header --------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <string.h>  /* malloc */
#include <stdbool.h>
#include <math.h>
#include <assert.h>
#include <stdint.h> /* uint32_t */
#include <unistd.h> /* sleep */

#include "String.h"
#include "new.h"

void test() {
  void* a = new(String, "Atul");
  void *aa= clone(a);
  void* b = new(String, "Raut");

  debug("sizeof(a) == %lu", (unsigned long)sizeof(a));
  if(differ(a, b)) {
    debug("->");
    puts("Okay!");
  }

  if(differ(a, aa)) {
    debug("->");
    puts("Differ!");
  }

  if(a == aa) {
    debug("->");
    puts("Clone!");
  }

  delete(a);
  delete(aa);
  delete(b);
}

int main (int argc, char **argv) {
  test();
  return 0;
}

/**
   => ./atoms
   L=[63] [Atom.c] [String_ctor] :| count=1 ->[Atul]
   L=[98] [Atom.c] [String_clone] :| count->[2]
   L=[63] [Atom.c] [String_ctor] :| count=1 ->[Raut]
   L=[31] [strings.c] [test] :| sizeof(a) == 8
   L=[33] [strings.c] [test] :| ->
   Okay!
   L=[43] [strings.c] [test] :| ->
   Clone!
   atul@rajgad:~/dev/OoO_ANSI_C_Axel_S/2_Dynamic_Linkage
   => ./strings
   L=[40] [String.c] [String_ctor] :| ->[Atul]
   L=[54] [String.c] [String_clone] :| ->[Atul]
   L=[40] [String.c] [String_ctor] :| ->[Atul]
   L=[40] [String.c] [String_ctor] :| ->[Raut]
   L=[31] [strings.c] [test] :| sizeof(a) == 8
   L=[33] [strings.c] [test] :| ->
   Okay!
**/
