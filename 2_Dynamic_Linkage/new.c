/**
   va_list : It is a Data Type for accessing data
   from variable argument list.
   va_start: It is a micro that initialize the
   variable arg. list to the 1st argument.
   va_arg  : Fetching 'int' Data Type that's why
   here int, if ur data type change mention here
   va_end  : End variable arg list.
*/

#include <assert.h>
#include <stdlib.h>

#include "new.h"
#include "new.r"

void* new(const void* _class, ...) {

  const struct Class* class = _class;
  void* p = calloc(1, class->size);

  assert(p);
  *(const struct Class **)p = class;

  if (class->ctor) {
    va_list ap;
    va_start(ap, _class);
    p = class->ctor(p, &ap);
    va_end(ap);
  }
  return p;
}

void delete(void *self) {

  const struct Class** cp = self;
  if (self && *cp && (*cp)->dtor)
    self = (*cp)->dtor(self);
  free(self);
}

void* clone(const void* self) {

  const struct Class* const* cp = self;
  assert(self && *cp && (*cp)->clone);
  return (*cp)->clone(self);
}

int differ (const void* self, const void* b) {

  const struct Class* const* cp = self;
  assert(self && *cp && (*cp)->differ);
  return (*cp)->differ(self, b);
}

size_t sizeOf(const void* self) {

  const struct Class* const* cp = self;
  assert(self && *cp);
  return(*cp)->size;
}
