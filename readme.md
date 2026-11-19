l1.c

O static guarda o valor do id entre as chamadas, então a função devolve 1, 2, 3, 4, 5. Sem o static, id seria local e começaria em 0 toda vez, devolvendo 1 sempre.

l2.c

O malloc aloca espaço para n doubles e o free libera no final. Se vier NULL, o programa avisa e sai.

l3.c

Devolver v é certo porque o bloco do heap continua valendo depois que a função termina. Se eu devolvesse &x de uma local, o endereço morreria no retorno, e quem chama precisa dar o free.

l4.c

```sh
gcc -std=c11 -Wall -Wextra -g l4.c -o l4
valgrind --leak-check=full ./l4
```

Sem a ferramenta não dá para perceber, porque o programa termina normal. Vazou 4000 bytes (1000 * sizeof(int)) e o free em aloca resolve.

l5.c

No l5.c eu leio v[2] depois do free, então uso memória que já foi liberada e o AddressSanitizer acusa na hora. No L4 o bloco só fica perdido, sem ninguém acessar depois. A versão corrigida está em l5_corrigido.c.

```sh
gcc -std=c11 -Wall -Wextra -g -fsanitize=address l5.c -o l5
```

Para discutir

Com -Wall -Wextra o compilador pega erros que dá para ver no código, como variável não usada, tipo incompatível e printf com formato errado. Vazamento e uso depois do free só aparecem rodando, com Valgrind ou AddressSanitizer.
