package com.vcoolish.calculator.computation

internal enum class BinaryOperator(val sign: Char, val precedence: Int) {
    PLUS('+', 2),
    MINUS('-', 2),
    MULT('*', 3),
    DIV('/', 3)
}
