# LLVM_Note

## CLI
```
# generate human readable IR
clang -S -emit-llvm fmad.cpp -o fmad.ll

# generate llvm bitcode
clang -c -emit-llvm fmad.cpp -o fmad.bc

# generate llvm ast(abstract syntax tree)
clang -emit-ast fmad.cpp -o fmad.ast

# run IR
lli fmad.ll
``` 
