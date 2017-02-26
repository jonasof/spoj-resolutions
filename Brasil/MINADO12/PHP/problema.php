<?php

(new MINADO())->executar();

class MINADO
{
    public $tabuleiro = [];
    public $qtde;

    public function executar()
    {
        $this->carregarTabuleiro();
        $this->processarCampos();
    }

    private function carregarTabuleiro()
    {
        $this->qtde = IO_Toolbox::lerLinha();
        for ($x = 0; $x < $this->qtde; $x++) {
            $this->tabuleiro[$x] = IO_Toolbox::lerLinha();
        }

        $this->tabuleiro[-1] = 0;
        $this->tabuleiro[(int) $this->qtde] = 0;
    }

    public function processarCampos()
    {
        for ($x = 0; $x < $this->qtde; $x++) {
            IO_Toolbox::exibir($this->tabuleiro[$x-1] + $this->tabuleiro[$x] + $this->tabuleiro[$x+1]);
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

    static function exibir($texto) {
        print $texto . "\n";
    }

}
