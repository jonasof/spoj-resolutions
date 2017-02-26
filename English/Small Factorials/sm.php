<?php


function main(){
    fscanf(STDIN, "%d\n", $testes);
    $x = 0;
    while($x < $testes){
        fscanf(STDIN, "%d\n", $numero_fatorial);
        echo fatorial($numero_fatorial) . "\n";
        $x++;
    }
}


function fatorial($x){
    if ($x > 0)
        return $x * (fatorial($x-1));
    else
        return 1;
}

main();
