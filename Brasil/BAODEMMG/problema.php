<?php

(new BAODEMMG())->executar();

class BAODEMMG
{

    public function executar()
    {
        $n_escolas = IO_Toolbox::lerLinha();

        for ($x = 1; $x <= (int) $n_escolas; $x++) {
            $this->verificarEscola();
        }
    }

    public function verificarEscola()
    {
        $linha = explode(" ", IO_Toolbox::lerLinha());
        $qtde_times = $linha[0];
        $qtde_alunos = $linha[0] * 3;

        $pessoas_necessarias = 0;
        for ($y = 1; $y <= $qtde_times; $y++) {
            $premios = ($linha[$y] > 0) ? 3 : 0; // três prêmios por pessoa apenas se ganhar
            $pessoas_necessarias += $premios * $linha[$y];
        }

        if ($pessoas_necessarias > $qtde_alunos) {
            print "precisa\n";
        } else {
            print "nao precisa\n";
        }
    }
}

class IO_Toolbox
{
    static function lerLinha($qtde_caracteres = null)
    {
        if ($qtde_caracteres === null)
            return fgets(STDIN);
        else
            return fread(STDIN, $qtde_caracteres);
    }

}
