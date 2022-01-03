bin=convert

CFLAGS += -g 
LDLIBS + = -lm
LDFLAGS +=

src=convert.c base64.c binary.c hexadecimal.c decimal.c helper.c
obj=$(src:.c=.o)

$(bin): $(obj)
	$(CC) $(CFLAGS) $(LDLIBS) $(LDFLAGS) $(obj) -o $@

convert.o: convert.c base64.h binary.h hexadecimal.h decimal.h helper.h
base64.o: base64.c base64.h decimal.h binary.h helper.h
binary.o: binary.c binary.h decimal.h helper.h
hexadecimal.o: hexadecimal.c hexadecimal.h decimal.h helper.h
decimal.o: decimal.c decimal.h base64.h helper.h
helper.o: helper.c helper.h


check: convert
	./convert 2 0b101010
	./convert 2 0o20
	./convert 2 100
	./convert 2 0xFF
	./convert 2 0+10

	./convert 10 0b101010
	./convert 10 0o20
	./convert 10 100
	./convert 10 0xFF
	./convert 10 0+10
	
	./convert 16 0b101010
	./convert 16 0o20
	./convert 16 100
	./convert 16 0xFF
	./convert 16 0+10

	./convert 64 0b101010
	./convert 64 0o20
	./convert 64 100
	./convert 64 0xFF
	./convert 64 0+10

clean:
	rm -f $(bin) $(obj)