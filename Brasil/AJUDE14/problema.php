<?php

(new AJUDE14())->executar();

class AJUDE14
{

    public function executar()
    {
        IO_Toolbox::lerLinha(); //se não me engano a primeira linha fornecida é desnecessária

        $total = 0;

        $pessoas = explode(" ", IO_Toolbox::lerLinha());
        foreach ($pessoas as $pessoa) {
            $total += $pessoa;
        }

        if ($total == IO_Toolbox::lerLinha()) {
            print "Acertou\n";
        } else {
            print "Errou\n";
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
