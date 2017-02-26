<?php

(new FATORIA2())->executar();

class FATORIA2
{

    public function executar()
    {
        $numero = IO_Toolbox::lerLinha();

        print $this->fatoria($numero) . "\n";
    }

    private function fatoria($numero) {
        if ($numero == 0) {
            return 1;
        } else {
            return $numero * $this->fatoria($numero -1);
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
