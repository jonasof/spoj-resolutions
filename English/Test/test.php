<?php
 
fscanf(STDIN, "%d\n", $input); // reads number from STDIN

while ($input != 42) {
	print ($input . "\n");
	fscanf(STDIN, "%d\n", $input); // reads number from STDIN
}

return 0;
