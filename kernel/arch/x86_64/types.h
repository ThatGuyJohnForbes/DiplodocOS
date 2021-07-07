//
// Created by john on 07/07/2021.
//

#ifndef DIPLODOCOS_TYPES_H
#define DIPLODOCOS_TYPES_H

typedef unsigned char u8;
typedef signed char i8;

typedef unsigned short u16;
typedef signed short i16;

typedef unsigned int u32;
typedef signed int i32;

#if defined __x86_64__ && !defined __ILP32__ //check that we're in 64 bit mode using the architecture
typedef unsigned long int u64;
typedef signed long int i64;
#else
typedef unsigned long long int u64;
typedef signed long long int i64;
#endif

#endif //DIPLODOCOS_TYPES_H
