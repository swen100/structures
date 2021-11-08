--TEST--
Eos\DataStructures\Enum->getElements();
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
?>
--FILE--
<?php
use Eos\DataStructures\Enum;

class Fruit extends Enum {
    const Apple = 1;
    const Pear = 2;
}

$fruit = new Fruit(Fruit::Apple);
var_dump($fruit->getElements());

class Stupid extends Enum {
    const Apple = 'banana';
    const Pear = 'tootyfruity';
}

$rotten = new Stupid('Apple');
var_dump($rotten->getElements());

// too many args
try {
     $fruit->getElements(1);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
?>
--EXPECTF--
array(2) {
  ["Apple"]=>
  int(1)
  ["Pear"]=>
  int(2)
}

Warning: Constant Apple is being cast to an integer in Enum subclass Stupid in %s on line %d

Warning: Constant Pear is being cast to an integer in Enum subclass Stupid in %s on line %d
array(2) {
  ["Apple"]=>
  int(0)
  ["Pear"]=>
  int(0)
}
Eos\DataStructures\Enum::getElements() expects exactly 0 %s, 1 given