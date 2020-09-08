
INCDIR += -I /usr/local/kaezip/include/
# Include Libs.
LIBDIR := -L/usr/local/kaezip/lib

# The flags
LIBFLAGS  := -lz
CFLAGS    := -g -Wall
LDFLAGS   := $(LIBDIR)

all: kaezip_perf
objects = kaezip_perf.c

kaezip_perf : $(objects)
	gcc $(CFLAGS) $(LDFLAGS) $(INCDIR) -o kaezip_perf $(objects) $(LIBFLAGS)

.PHONY : clean
clean :
	-rm -f kaezip_perf
