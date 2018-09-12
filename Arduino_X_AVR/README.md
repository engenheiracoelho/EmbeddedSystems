# Verify operation

* Eclipse implementation:

1. Create a lst file on Eclipse:

```
avr-objdump -h -S interrupt.elf>interrupt.lst
```

2. Verify this file to view all the characteristics of this implementation.

* Arduino implementation:

1. Verify the .elf file path:
```
> Arquivo > Preferências
>>> Check the option "Compilação" on  "Mostrar mensagens de saída durante".
>>> Verify the path on the last line and open this folder.
>>> /tmp/build0c470ffab208b8c2163db3b6d36e6823.tmp/comparation_ard.ino.elf
```

2. Create a lst file on Eclipse:
```
avr-objdump -h -S comparation_ard.ino.elf > comparation.lst
```

* Now you can verify the differences between this two files :) 
