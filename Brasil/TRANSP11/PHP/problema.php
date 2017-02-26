<?php

(new TRANSP11())->executar();

class TRANSP11
{

    public function executar()
    {
        $container = explode(" ", IO_Toolbox::lerLinha());
        $navio = explode(" ", IO_Toolbox::lerLinha());

        $qtde = floor($navio[0]/$container[0]) *
                floor($navio[1]/$container[1]) *
                floor($navio[2]/$container[2]);

        print $qtde . "\n";
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
