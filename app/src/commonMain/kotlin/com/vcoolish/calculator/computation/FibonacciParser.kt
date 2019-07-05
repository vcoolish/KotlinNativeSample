package com.vcoolish.calculator.computation

/**
 * @property expression the expression to calculate with fibonacci support.
 * @return result of calculations.
 */

fun parseAndComputeWithFibonacci(expression: String): Result<Double, String> {
    return PartialParser(
        FibonacciParser(FibonacciCalculator()),
        PartialRenderer()
    ).parseWithPartial(expression)
}

/**
 * This class parses mathematical expression with fibonacci support.
 *
 * @param E : Any the type of a member in this group.
 * @property composer fibonacci extended interface for calculations.
 */
internal class FibonacciParser<E : Any>(private val composer: FibonacciExpressionComposer<E>) : Parser<E>(composer)  {

    override fun onContinuableWithExpression(
        tokenizer: Tokenizer,
        continuableWithExpression: ContinuableWithExpression<E>
    ): ExpressionPrefix<E>? {
        val number = tokenizer.tryReadNumber()
        val fibNumber = tokenizer.tryReadFibonacciExpr()
        return when {
            number != null -> continuableWithExpression.with(composer.number(number))
            tokenizer.tryReadLeftParenthesis() -> continuableWithExpression.withLeftParenthesis()
            fibNumber != null -> continuableWithExpression.with(composer.fib(fibNumber))
            else -> null
        }
    }
}



