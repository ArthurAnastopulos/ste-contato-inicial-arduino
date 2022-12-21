# Feedback

Nota final = 7.5

## Programa 1 - Interruptor LED
- Esquema elétrico do circuito: OK
- Máquina de estados: as transições E1->ON e E2->OFF deveriam ser disparadas por tempo e não por estado do botão. Note que não há necessidade de ficar trocando a sensibilidade da interrupção, já que dependeria apenas do tempo.
- Código-fonte: Não deveria ser verificado o valor do botão nos estados E1 e E2. Também não há necessidade de trocar a sensibilidade das interrupções.
- Nota: 7

## Programa 2 - Voltímetro Digital
- Esquema elétrico do circuito: OK
- Máquina de estados: Fica de sugestão utilizar nomes mais significativos para os estados.
- Código-fonte: A lógica no seu estado E1 não está coerente com a máquina de estados. Na interrupção você atualiza a variável scale_, porém no início do loop você consulta a entrada btn_scale. Verificar scale_ diretamente no E1 pode apresentar condição de corrida. A parada dentro de E2 também atualiza entradas dentro da transição, o que pode ser problemático.
- Nota: 8
