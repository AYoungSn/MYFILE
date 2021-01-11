three: one.o two.o
	@gcc -o three one.o two.o
clean:
	@rm -f one.o two.o three
.c.o:
	@echo "compiling " $< "to build " $*.o "..."
	@gcc -c $*.c

