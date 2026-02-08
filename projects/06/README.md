# Hack Assembler

An assembler for the Hack assembly language (nand2tetris project 06). Translates `.asm` files into `.hack` binary files.

## Prerequisites

- GCC
- Make

## Build

```sh
make
```

This compiles the `assembler` binary in the project root.

## Usage

```sh
./assembler <file.asm>
```

## Tests

```sh
make test
```

## Clean

```sh
make clean
```

Removes the `assembler` and `test_runner` binaries and the `obj/` build directory.
