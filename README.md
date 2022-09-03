# Checkpoint 4 _Internet Of Things_

Esse projeto foi desenvolvido por mim mesmo e pelo meu colega [Kaike Santana](https://www.linkedin.com/in/kaike-santana/).

## Features

- Motor integrado
- Sensor de umidade e temperatura
- Tag RFID
- Arduino se comunicando com Raspberry
- Node-red rodando na raspberry 
- Node-red da rasp se comunicando com Telegram, Whats, Twitter e banco
- Banco de dados MariaDB
- Dashboard
- Comunicação MQTT entre node-red da rasp com node-red na IBM Cloud
- Manipulação do sistema pelo celular

Utilizamos a arquitetura definida pelo professor Arnaldo construir toda esse projeto.
<p align="center">
  <img src="https://arnaldojr.github.io/IoT/checkpoint4/diagramablocos.png" />
</p>

## Vídeos

Aplicativo mobile que controla os componentes por MQTT: https://youtube.com/shorts/Q6K5SFC0TEA?feature=share<br>
Explicando como o projeto funciona/foi feito: https://youtu.be/emy82uhnI54


## Rodando o projeto

- Arduino UNO
- Raspberry
- Servo Motor
- Tag RFID
- sensor DTH11
- Node-red



#### 1 - Código Arduino
Comece criando o código para a tag RFID e Servo motor no [arduino IDE](https://www.arduino.cc/en/software), fazendo então o upload para a placa.
Pegue o código aqui

#### 2 - Raspberry headless
Conecte a raspberry no wifi e faça o boot. [Tutorial para esse passo](https://arnaldojr.github.io/IoT/aulas/lab7/)

#### 4 - Instalar o node-red

```
bash <(curl -sL https://raw.githubusercontent.com/node-red/linux-installers/master/deb/update-nodejs-and-nodered)
```

No node red, vá até o menu 'Manage Palette'

![Screenshot 2022-09-01 201637](https://user-images.githubusercontent.com/54187661/188030272-6d12df2e-7528-44f5-a8e0-addc3b08f86d.png)

Instale os seguintes módulos:
```
node-red-contrib-aedes
node-red-contrib-dht-sensor
node-red-node-serialport
node-red-node-mysql
node-red-dashboard
node-red-contrib-whatsapp-cmb
node-red-contrib-telegrambot
node-red-node-twitter
```
Todos os nós utilizados no node-red da rasp estão nesse link

#### 5 - Configurar node-red na Raspberry
Os nós utilizados no node-red na rasp estão disponíveis [aqui](https://github.com/GiulioBernardi/cp-iot/blob/master/json%20node-red%20raspberry/flows%20(10).json)

<p align="center">
  <img src="https://user-images.githubusercontent.com/54187661/188248749-6ddf79ca-54a2-495c-b451-0fc98289bae1.png" />
</p>

#### 6 - Crie o banco de dados na Raspberry

[Tutorial para instalar o MySQL/MariaDB](https://www.youtube.com/watch?v=crPoSYFcZDk&t=3s)

Ao instalar, criar um usuário e uma base de dados, rode o seguinte comando SQL

```
create table clima(
    id int auto_increment primary key,
    temperatura decimal(4,2),
    umidade decimal(4,2)
) engine=innodb;
```

#### 7 - Node-red local ou em núvem
Fora da RaspBerry, importe [esses nós](https://github.com/GiulioBernardi/cp-iot/blob/master/json%20node-red%20ibm/iot-cloud.json) para o node-red, seja esse local ou em alguma núvem, nós usamos o node-red da IBM.
<p align="center">
  <img src="https://user-images.githubusercontent.com/54187661/188224327-58715eb4-e89e-4ca1-b84e-ce6883da5a33.jpeg" />
</p>

Você deve estar apto a rodar o projeto se seguir todos esses passos acima.
Caso haja algum erro em algum passo, abra uma issue nesse repo para que eu melhore esse tutorial.
