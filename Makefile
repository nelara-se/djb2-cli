CC = gcc
CFLAGS  = -Wall -O3

TARGET = djb2
DESTDIR = $$HOME/.local/bin

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $@ $<

install: $(TARGET)
	mkdir -p ${DESTDIR}
	cp $< ${DESTDIR}

clean:
	$(RM) $(TARGET)
