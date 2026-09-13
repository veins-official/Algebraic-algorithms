TARGET = main.out
CC = g++
CFLAGS = -fstack-protector-all -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wno-long-long -std=c++20 -Wmissing-declarations -Winit-self -Wswitch-default -Wshadow -Wlogical-op -Wignored-qualifiers -O3
LDLIBS = -lm

%.out: %.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)
%.o: %.cpp
	$(CC) -c $(CFLAGS) $<

all: $(TARGET)

$(TARGET): main.o Vector.o

main.o: main.cpp Vector.h
Vector.o: Vector.cpp Vector.h

clean:
	rm -f *.o *.out

.PHONY: clean

