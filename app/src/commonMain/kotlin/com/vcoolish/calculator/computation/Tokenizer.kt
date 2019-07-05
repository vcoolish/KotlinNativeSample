package com.vcoolish.calculator.computation

internal class Tokenizer(private val expression: String) {
    private var index = 0

    init {
        skipSpaces()
    }

    fun hasNext(): Boolean = (index < expression.length)

    fun getRemainder(): String? = if (this.hasNext()) {
        expression.substring(index)
    } else {
        null
    }

    fun tryReadNumber(): Double? {
        var endIndex = index
        while (expression.getOrNull(endIndex)?.isNumberChar() == true) {
            ++endIndex
        }

        return expression.substring(index, endIndex).toDoubleOrNull()?.also {
            index = endIndex
            skipSpaces()
        }
    }

    private fun checkFibonacciOperator(): Boolean {
        for (i in "fib(") {
            if(!tryRead(i)){
                return false
            }
        }
        return true
    }

    fun tryReadFibonacciExpr(): Double? {
        if (checkFibonacciOperator()) {
            tryReadNumber()?.let {
                if (tryReadRightParenthesis()) {
                    return it
                }
            }
        }
        return null
    }

    private fun Char.isNumberChar(): Boolean = this in '0'..'9' || this == '.'

    fun tryReadBinaryOperator(): BinaryOperator? = BinaryOperator.values().firstOrNull { tryRead(it.sign) }

    fun tryReadLeftParenthesis(): Boolean = tryRead('(')

    fun tryReadRightParenthesis(): Boolean = tryRead(')')

    private fun tryRead(char: Char): Boolean = if (hasNext() && expression[index] == char) {
        ++index
        skipSpaces()
        true
    } else {
        false
    }

    private fun skipSpaces() {
        while (expression.getOrNull(index)?.isWhitespace() == true) {
            ++index
        }
    }
}