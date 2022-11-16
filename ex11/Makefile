all: fgetc  fputc  readwrite  stdio

fgetc: fgetc.cpp
	$(GXX) -ofgetc  fgetc.cpp

fputc: fputc.cpp
	$(GXX) -ofputc  fputc.cpp
	./fputc  # run program to create input file for fgetc above

readwrite: readwrite.cpp
	$(GXX) -oreadwrite  readwrite.cpp

stdio: stdio.cpp
	$(GXX) -ostdio  stdio.cpp

clean:
	rm -f fgetc  fputc  readwrite  stdio *.dat *~
