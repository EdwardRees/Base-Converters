bin=convert

CC = clang++ 
CFLAGS += -g -fPIC -std=c++11 -stdlib=libc++
LDLIBS += -lm -lncurses
LDFLAGS +=

src=convert.cpp base64.cpp binary.cpp hexadecimal.cpp decimal.cpp helper.cpp
obj=$(src:.cpp=.o)

$(bin): $(obj)
	$(CC) $(CFLAGS) $(LDLIBS) $(LDFLAGS) $(obj) -o $@

convert.o: convert.cpp base64.hpp binary.hpp hexadecimal.hpp decimal.hpp helper.hpp
	clang++ -std=c++11 -stdlib=libc++ -c convert.cpp -o convert.o
base64.o: base64.cpp base64.hpp decimal.hpp binary.hpp helper.hpp
	clang++ -std=c++11 -stdlib=libc++ -o base64.o -c base64.cpp
binary.o: binary.cpp binary.hpp decimal.hpp helper.hpp
	clang++ -std=c++11 -stdlib=libc++ -c binary.cpp -o binary.o
hexadecimal.o: hexadecimal.cpp hexadecimal.hpp decimal.hpp helper.hpp
	clang++ -std=c++11 -stdlib=libc++ -c hexadecimal.cpp -o hexadecimal.o
decimal.o: decimal.cpp decimal.hpp base64.hpp helper.hpp
	clang++ -std=c++11 -stdlib=libc++ -c decimal.cpp -o decimal.o
helper.o: helper.cpp helper.hpp
	clang++ -std=c++11 -stdlib=libc++ -c helper.cpp  -o helper.o


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