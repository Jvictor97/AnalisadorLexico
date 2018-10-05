<h1>Projeto Analisador Léxico (Compiladores)</h1>
<hr/>
<p>Objetivo: Criar um analisador léxico para permitir o reconhecimento de variáveis, palavras reservadas e números, de acordo com a entrada fornecida</p>

 <h2>Exemplo de Entrada:</h2>
<code>
    Digite a entrada: LET A:=10 : IF A==10 THEN B=B+A : END % A=A+A : B=20
</code>

<h2>Saída Correspondente:</h2>

```
 P(7) V(0) := N(10) : P(0) V(0) ==N(10) P(4) V(1) =V(1) +V(0) : P(3)

Tabela de Variaveis:
    0....A
    1....B

Tabela de Palavras:
    0....IF
    1....ELSE
    2....GOTO
    3....END
    4....THEN
    5....READ
    6....PRINT
    7....LET
    8....OF
```

<br/>
<p>Colaboradores:<br>
    <ul>
        <li>João Souza (<a href=http://github.com/Jvictor97>@Jvictor97</a>)</li>
        <li>Marcus More (<a href=http://github.com/MarcusMore>@MarcusMore</a>)</li>
    </ul>
</p>
