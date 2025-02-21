
echo $OSTYPE > make/Makefile
mv Makefile Makefile.linux-gnu

To Compile :
OSTYPE=linux-gnu make

Ref - https://github.com/shichao-an/ooc
1] Fix compilation error at app 14
2] Add make/Makefile.linux-gnu per below

=> cat make/Makefile.linux-gnu
mklib:	$(mklib)
	$(AR) $(ARFLAGS) $l $o
	ranlib $l
.c.a:	;

# these implicit rules produce header files from class description files
# and C sources from class implementation files. in chapter 14 $(post) is
# set to change the base class name from Object to Objct.

.SUFFIXES:	.h .r .dc .d

.d.h:	; $(OOC) $(Rflag) $(OOCFLAGS) $* -h $(post) > $@
.d.r:	; $(OOC) $(Rflag) $(OOCFLAGS) $* -r $(post) > $@
.dc.c:	; $(OOC) $(Rflag) $(OOCFLAGS) $* $*.dc $(post) > $@

-include depend
