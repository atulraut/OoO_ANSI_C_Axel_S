#ifndef	STRING_H
#define	STRING_H

#define debug(str,args...) printf("L=[%d] [%s] [%s] :| "str"\n", __LINE__,__FILE__, __func__, ##args)
extern const void* String;

#endif
