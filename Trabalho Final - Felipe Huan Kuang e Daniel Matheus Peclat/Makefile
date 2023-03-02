CC=g++
LD=g++

CFLAGS=`python3.8-config --cflags` -fPIE
LDFLAGS=`/usr/python3.8-config --embed --ldflags`


OBJS = main.o menu.o celular.o estoqueCelular.o local.o

TARGET = FabricaCelular


all: $(TARGET)

$(TARGET): $(OBJS)
		$(LD) -I/usr/include/python3.8 -o $@ $(OBJS) -L /usr/lib/x86_64-linux-gnu/ -lpython3.8

main.o:main.cpp
	$(CC) $(CFLAGS) -c main.cpp

menu.o:menu.cpp
	$(CC) $(CFLAGS) -c menu.cpp

celular.o:celular.cpp
	$(CC) $(CFLAGS) -c celular.cpp

estoqueCelular.o:estoqueCelular.cpp
	$(CC) $(CFLAGS) -c estoqueCelular.cpp

local.o:local.cpp
	$(CC) $(CFLAGS) -c local.cpp


clean:
	$(RM) -f *.o *:Zone.Identifier $(TARGET)
