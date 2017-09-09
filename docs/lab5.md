# Переменные окружения и файловые операции

### Задание

* Написать программу, которая сохраняет аргументы, передаваемые программе, а так же параметры окружения в файл lab5.txt
* Написать **Makefile**
* Написать **Dockerfile** и сделать **Docker image** с задачей

### Выполнение

Выполнение схоже с предыдущей лабораторной. В исходных кодах можно так же найти бонус, который копирует с необходимыми аргументами программу (и она рабочая).

### Инструкции по сборке

#### Сборка

```
cd lab5
docker build -t balberinlabs:lab5 .
```
#### Запуск
`docker  run --rm balberinlabs:lab5`


### Готовый образ

```
docker pull aachurbanov/balberinlabs:lab5
docker run --rm aachurbanov/balberinlabs:lab5
```

### Исходные файлы

#### lab5.c

```
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(int argc, const char * argv[], const char *envp[])
{
    char data[8000];
    strcat(data, "CLI arguments\n" );
    for (int i=0; i<argc; i++) {
        strcat(data, argv[i]);
        strcat(data, "\n");
    }
    strcat(data, "Enviroment variables\n" );
    for (int i=0; envp[i]; i++) {
        strcat(data, envp[i]);
        strcat(data, "\n");
        
    }
    printf("%s",data);
    
}
```

#### Makefile

```
TARGET = lab5
PREFIX = /usr/local/bin
CC = clang

.PHONY: all clean install uninstall

all: $(TARGET)
clean:
	rm -rf $(TARGET) *.o
lab5.o: lab5.c
	$(CC) -c -o lab5.o lab5.c
$(TARGET): lab5.o
	$(CC) -o $(TARGET) lab5.o
install:
	install -D $(TARGET) $(PREFIX)/$(TARGET)
uninstall:
	rm -rf $(PREFIX)/$(TARGET)
```

#### Dockerfile

```
FROM debian:jessie-slim
#FROM alpine
WORKDIR /src
#RUN apk add --update clang binutils gcc clang-libs libc-dev coreutils
RUN apt-get update && apt-get install -y --no-install-recommends \
	libc6-dev clang coreutils binutils gcc make \
	&& rm -rf /var/lib/apt/lists/*
ADD ./src/* ./
RUN make all
RUN make install
ENTRYPOINT ["lab5", "first", "secOnd", "thirdarg"]
```

### Скриншот

![Screenshot](balberinlabs5.png)

