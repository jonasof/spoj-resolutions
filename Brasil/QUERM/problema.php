<?php

(new QUERM())->executar();

class QUERM
{

    public function executar()
    {
        $qtde = IO_Toolbox::lerLinha();
        $numero_teste = 1;

        while ($qtde != 0) {
            $ganhador = 0;
            $participantes = explode(" ", IO_Toolbox::lerLinha());
            foreach ($participantes as $key=>$value) {
                if (($key+1) == $value) {
                    $ganhador = $value;
                    break;
                }
            }

            print "Teste $numero_teste\n";
            print "$ganhador\n\n";

            $qtde = IO_Toolbox::lerLinha();
            $numero_teste++;
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
