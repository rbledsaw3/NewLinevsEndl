# New Line vs std::endl

Attempting to settle the debate as to which is more performant.

## Usage Examples

```
./main 10000 newline
```

Prints "Hello World!" 10000 times with a `"\n"` in the stdout.

```
./main 10000 endl
```

Prints "Hello World!" 10000 times with `std::endl` for each line.

## Results

Using the `time` command, I saw `std::endl` finish about 5% sooner than `"\n"` even when compiled with no optimizations. Even for large `n` (e.g. 100000000), `std::endl` outperformed `"\n"`.
