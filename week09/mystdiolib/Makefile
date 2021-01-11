OBJS = myfopen.o myfclose.o myfputc.o myfgetc.o
MAIN = mymain.o

all: $(OBJS) $(MAIN)
	gcc -o test1 $(OBJS) $(MAIN)
	@echo "gcc is completed..."

uselib: $(MAIN)
	gcc -o test2 $(MAIN) -L. -lmystdio

lib: $(OBJS)
	ar -q libmystdio.a $(OBJS)
	@echo "libmystdio is created..."
clean:
	rm -f $(OBJS) $(MAIN) libmystdio.a

.c.o:
	gcc -c $<
