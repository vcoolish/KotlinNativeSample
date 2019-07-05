package com.vcoolish.calculator.computation

import com.vcoolish.calculator.LogLevel
import com.vcoolish.calculator.log

internal class PartialParser<E : Any, PE : Any>(
    private val parser: ParseExpression<E>,
    private val partialComposer: PartialExpressionComposer<E, PE>
) {

    fun parseWithPartial(expression: String): Result<E, PE> {
        log(LogLevel.DEBUG, PartialParser::class.toString(), "parseWithPartial")
        val tokenizer = Tokenizer(expression)
        val prefix = parser.parseAsPrefix(tokenizer)

        val remainder = tokenizer.getRemainder()
        val result =
            if (remainder != null) {
                null
            } else {
                tryReduce(prefix)
            }

        return Result(
            result,
            prefix.toPartialExpression(),
            remainder
        )
    }

    private fun tryReduce(prefix: ExpressionPrefix<E>): E? {
        if (prefix is EndedWithExpression) {

            val reduced = parser.reducedExpression(prefix)
            if (reduced.prefix is Empty) {
                return reduced.expression
            }
        }

        return null
    }

    private fun ExpressionPrefix<E>.toPartialExpression(): PE = when (this) {
        is EndedWithExpression -> this.prefix.toPartialExpressionWith(
            ending = partialComposer.ending(this.expression)
        )
        is ContinuableWithExpression -> this.toPartialExpressionWith(ending = partialComposer.missing())
    }

    private tailrec fun ContinuableWithExpression<E>.toPartialExpressionWith(
        ending: PE
    ): PE = when (this) {
        Empty -> ending

        is EndedWithLeftParenthesis -> this.prefix.toPartialExpressionWith(
            ending = partialComposer.leftParenthesized(ending)
        )

        is EndedWithOperator -> this.prefix.toPartialExpressionWith(
            ending = partialComposer.compose(this.operator, this.leftOperand, ending)
        )
    }

    private fun PartialExpressionComposer<E, PE>.compose(
        binaryOperator: BinaryOperator,
        left: E,
        right: PE
    ): PE = when (binaryOperator) {
        BinaryOperator.PLUS -> plus(left, right)
        BinaryOperator.MINUS -> minus(left, right)
        BinaryOperator.MULT -> mult(left, right)
        BinaryOperator.DIV -> div(left, right)
    }
}