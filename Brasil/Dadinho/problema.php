<?php

(new DADINHO())->executar();

class DADINHO
{

    public function executar()
    {
        $linha = $this->obterLinha();
        while (! $this->linhaEstaVazia($linha)) {
            $pessoas = $linha[0];
            $dadinhos = $linha[1];
            $custo = $linha[2];

            print($pessoas * $dadinhos * $custo) . "\n";
            $linha = $this->obterLinha();
        }
    }

    private function obterLinha() {
        $linha = IO_Toolbox::lerLinha();
        return explode(" ", $linha);
    }

    private function linhaEstaVazia($linha) {
        $esta_vazia = true;
        foreach ($linha as $elemento) {
            if ($elemento != 0) {
                $esta_vazia = false;
            }
        }
        return $esta_vazia;
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
