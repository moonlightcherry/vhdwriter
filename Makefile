bin:source/vhdwriter.c include/*.h
	@gcc source/vhdwriter.c -o bin/vhdwriter -I ./include/

.PHONY:source
source:
	@vim source/vhdwriter.c

install:bin/vhdwriter
	@install -o root -g root -m 777 bin/vhdwriter /usr/local/bin/vhdwriter
