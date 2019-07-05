package com.vcoolish.calculator.computation

interface PartialExpressionComposer<E : Any, PE : Any> {
    fun missing(): PE
    fun ending(expression: E): PE

    fun plus(left: E, partialRight: PE): PE
    fun minus(left: E, partialRight: PE): PE
    fun mult(left: E, partialRight: PE): PE
    fun div(left: E, partialRight: PE): PE

    fun leftParenthesized(partialExpression: PE): PE
}
