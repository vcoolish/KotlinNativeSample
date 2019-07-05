package com.vcoolish.calculator.computation

internal interface ParseExpression<E> {
    fun reducedExpression(exp: EndedWithExpression<E>): EndedWithExpression<E>
    fun parseAsPrefix(tokenizer: Tokenizer): ExpressionPrefix<E>
    fun onContinuableWithExpression(
        tokenizer: Tokenizer, continuableWithExpression: ContinuableWithExpression<E>
    ): ExpressionPrefix<E>?
}
