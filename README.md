# Sistemas Embarcados - Contato Inicial

Utilize o kit com Arduino entregue a você para implementar dois programas com as seguintes especificações. A documentação e o código fonte de cada solução devem estar em diretórios separados.


## Programa 1 - Interruptor LED

1. Monte um circuito com um Arduino, um LED e um botão, conforme desenvolvido nas aulas.

2. Desenhe a máquina de estados e implemente o software de uma aplicação que utilize o botão para acender e apagar o LED. O botão funciona como interruptor, ou seja, cada vez que o botão for pressionado, o estado do LED se alterna entre ligado e desligado. Considere uma solução sem repique (debounce).

3. O código-fonte e a documentação do seu trabalho deve estar no GitHub. A documentação deve estar no arquivo README.md do diretório da aplicação, e deve incluir o esquema elétrico utilizado e o(s) diagrama(s) de máquina(s) de estado.

Dica 1: esta solução foi feita em aula. Reaproveite as informações/código desenvolvidos com o professor e organize sua entrega.
### Documentação: Programa 1 - Interruptor LED

Para o Primeiro Programa foi desenvolvido um sistema de Interruptor LED, foi utilizada a solução feita em aula como base. Onde o circuito do sistema segue na imagem a seguir:

![Circuito01](/images/circuito1.png)

Para este circuito foram utilizados os seguintes componentes:
* Entrada: Interruptor (botão);
* Saída: LED;
* Um resistor de 220 Ohms para o LED;
* Um resistor de 10 kOhms para o Interruptor.

Já sua Máquina de Estado,também utilizando como base a solução feita em aula. Possui o seguinte modelo:

![State01](/images/StateMachine1.png)

Como visto na imagem esta possui 4 Estados:

* **OFF**: Que representa o estado do LED desligado;
* **E1**: Que representa o estado intermediário de OFF para ON, neste momento já acionado o LED;
* **ON**: Que representa o estado do LED ligado;
* **E2**: Que representa o estado intermediário de ON para OFF, neste momento já acionado o LED
## Programa 2 - Voltímetro Digital

Documente a solução e implemente um voltímetro digital, conforme debatido em sala de aula. O sistema embarcado desenvolvido deve ter as seguintes propriedades:

* Entradas: scale (botão), hold (botão), sinal de tensão (potenciômetro), timer/delay
* Saída: Serial (para saída do valor de tensão medido)
* A saída serial deve atualizar o valor de tensão medido no potenciômetro a cada 500ms.
* O botão scale deve alternar, cada vez que é pressionado, a resolução do valor de tensão entre V (volts) e mV (milivolts). O comportamento deste botão é similar ao "interruptor" do programa 1.
* O botão hold deve suspender a atualização da saída, ou seja, se o botão estiver pressionado, o voltímetro para de atualizar a saída serial. Se não estiver pressionado, a saída é atualizada normalmente.
