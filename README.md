# Boopa-Dee-Bappa-Dee
A Boopa-Dee Bappa-Dee Interpreter similar to [Urban Müller's brainfuck Interpreter](https://de.wikipedia.org/wiki/Brainfuck)

[![peter speaks italian video](https://img.youtube.com/vi/084VLYruPpw/0.jpg)](https://www.youtube.com/watch?v=084VLYruPpw)

## Commands
Command | Brainfuck | Meaning
--- | --- | ---
bappadee | \> | increment the data pointer
boo | \< | decrement the data pointer
boopa | \+ | increment the byte at the data pointer
bappa | \- | decrement the byte at the data pointer
dee | \. | output the byte at the data pointer
beepee | \, | accept one byte of input, storing its value in the byte at the data pointer
boopadee | \[ | if pointer is zero, jump to matching ]
baa | \] | if pointer is nonzero, jump to matching [
