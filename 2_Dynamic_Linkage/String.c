/***

    File - String.c

    gcc -g -o main -Wall -Wextra -pedantic -Wwrite-strings -fsanitize=address *.c -lm

    Date: Thu 20 Feb 2025 11:05:00 AM PST
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
#include "new.r"

struct String {
  const void* class; /* must be first*/
  char* text;
};

static void* String_ctor(void* _self, va_list* app) {

  struct String * self = _self;
  const char * text = va_arg(* app, const char *);

  self->text = malloc(strlen(text) + 1);
  assert(self->text);
  strcpy(self->text, text);
  debug("->[%s]", self->text);
  return self;
}

static void* String_dtor(void* _self) {

  struct String * self = _self;
  free(self->text), self->text = 0;
  return self;
}

static void* String_clone(const void* _self) {

  const struct String * self = _self;
  debug("->[%s]", self->text);
  return new(String, self->text);
}

static int String_differ(const void* _self, const void* _b) {

  const struct String * self = _self;
  const struct String * b = _b;

  if (self == b)
    return 0;
  if (! b || b->class != String)
    return 1;
  return strcmp(self->text, b->text);
}

static const struct Class _String = {
	sizeof(struct String),
	String_ctor,
	String_dtor,
	String_clone,
	String_differ
};

const void* String = &_String;
/**

 **/
