#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/IRBuilder.h"

#include <memory>
#include <vector>
//#include <iostream>

// https://www.ibm.com/developerworks/cn/opensource/os-createcompilerllvm1/

using IRBuilder = llvm::IRBuilder<llvm::ConstantFolder, llvm::IRBuilderDefaultInserter>;

int main(){
    std::unique_ptr<llvm::LLVMContext> ctx(new llvm::LLVMContext());
    std::unique_ptr<llvm::Module> module(new llvm::Module("Foo", *ctx));
    std::unique_ptr<IRBuilder> builder(new IRBuilder(*ctx));

    llvm::FunctionType *funcType = llvm::FunctionType::get(llvm::Type::getVoidTy(*ctx), {}, false);
    llvm::Function *mainFunc = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, "main", module.get());

    llvm::BasicBlock *entry = llvm::BasicBlock::Create(*ctx, "entrypoint", mainFunc);
    builder->SetInsertPoint(entry);

    llvm::Value *helloWorld = builder->CreateGlobalStringPtr("hello world!\n", "SomeVar");


    std::vector<llvm::Type *> putsArgs;
    putsArgs.push_back(builder->getInt8Ty()->getPointerTo());
    llvm::ArrayRef<llvm::Type*> argsRef(putsArgs);

    llvm::FunctionType *putsType = llvm::FunctionType::get(builder->getInt32Ty(), argsRef, false);
    llvm::Constant *putsFunc = module->getOrInsertFunction("puts", putsType);

    builder->CreateCall(putsFunc, helloWorld);
    builder->CreateRetVoid();

    module->print(llvm::outs(), nullptr);
}