
echo $OSTYPE > make/Makefile
mv Makefile Makefile.linux-gnu

To Compile :
OSTYPE=linux-gnu make
