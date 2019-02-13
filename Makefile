CC=icc

# Vectorization enabled
CFLAGS=-Wall -O3 -qopt-report=5 -qopt-report-phase=vec -qopt-report-file=stdout

# Vectorization disabled
#CFLAGS=-Wall -O0 -qopt-report=5 -qopt-report-phase=vec -qopt-report-file=stdout

TARGET=vec_add

$(TARGET) : add.c
	$(CC) -o $@ $< $(CFLAGS)

.PHONY: clean

clean :
	rm -f $(TARGET)
