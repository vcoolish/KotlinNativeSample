package com.vcoolish.calculator.computation

interface FibonacciExpressionComposer<E : Any>: ExpressionComposer<E> {
    fun fib(value: Double): E
}