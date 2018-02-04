# Проектирование облачной файловой системы.

## Исследование Swarm-mode Docker.

​	Рассмотрим инициализацию Docker swarm mode на примере docker-machine.

​	Создадим три узла:

- [ ] `$ docker-machine create manager`;

- [ ] `$ docker-machine create node1`;

- [ ] `$ docker-machine create node2`.

      Посмотрим список созданных машин:

      `$ docker-machine ls`

![laba2_4](C:\Users\aachu\OneDrive\Документы\GitHub\labki\laba2_4.PNG)

​	Посмотрим IP адрес машины "manager" с помощью команды:

![laba2_5](C:\Users\aachu\OneDrive\Документы\GitHub\labki\laba2_5.PNG)

​	Подключимся к машине "manager":

`$ docker-machine ssh manager`

​	Выполним команду для инициализации роя. В параметр "--advertise-addr" передаем IP адрес и порт для коммуникации внутри роя:

`$ docker swarm init --advertise-addr 192.168.99.108:2377`

![laba2_6](C:\Users\aachu\OneDrive\Документы\GitHub\labki\laba2_6.PNG)

Выполним в node1 и node2 предложенную команду:

```
$ docker-machine ssh node1
docker@node1:~$ docker swarm join --token SWMTKN-1-2jqm3wwqneualaj0e45c3mkzftcyxoaw3uuw5tc6i28h2g3j3v-3jl4e2gzo9k1nr5ix6ay9k2ye 192.168.99.108:2377
```

![laba2_7](C:\Users\aachu\OneDrive\Документы\GitHub\labki\laba2_7.PNG)

​	Аналогично для node2:

```
$ docker-machine ssh node2
docker@node1:~$ docker swarm join --token SWMTKN-1-2jqm3wwqneualaj0e45c3mkzftcyxoaw3uuw5tc6i28h2g3j3v-3jl4e2gzo9k1nr5ix6ay9k2ye 192.168.99.108:2377
```

![laba2_8](C:\Users\aachu\OneDrive\Документы\GitHub\labki\laba2_8.PNG)

​	Теперь мы получили рой состоящий из трех узлов который обладает масштабируемостью, и высокой доступностью. Посмотрим информацию о нем при помощи команды:

`docker node ls`

# Вывод :

​	В рамках выполнения лабораторной были выявленны следующие особенности:

- [ ] Если терминал привязан к виртуальной машине то новую виртуальную машину в нем создавать нельзя (каждая виртуальную машину запускать в отдельном терминале);

- [ ] Минимально рой контейнеров может состоять из 1 элемента, но мы не получаем помехозащищенности и масштабируемость;

- [ ] Масштабируемость достигается при двух элементах.

      ​