package com.vcoolish.calculator.computation

import com.vcoolish.calculator.LogLevel
import com.vcoolish.calculator.log

/**
 * @property expression the expression to calculate.
 * @return result of calculations.
 */
fun parseAndCompute(expression: String): Result<Double, String> {
    return PartialParser(
        Parser(Calculator()),
        PartialRenderer()
    ).parseWithPartial(expression)
}

/**
 * This class parses mathematical expression to operators and numbers.
 *
 * @param E : Any the type of a member in this group.
 * @property composer interface for calculations.
 */
internal open class Parser<E : Any>(private val composer: ExpressionComposer<E>): ParseExpression<E> {
    fun parse(expression: String): E? {
        val tokenizer = Tokenizer(expression)
        val prefix = parseAsPrefix(tokenizer)

        if (prefix is EndedWithExpression && !tokenizer.hasNext()) {
            val reduced = reducedExpression(prefix)
            if (reduced.prefix is Empty) {
                return reduced.expression
            }
        }
        return null
    }

    override fun parseAsPrefix(tokenizer: Tokenizer): ExpressionPrefix<E> =
        generateSequence<ExpressionPrefix<E>>(Empty) {
            it.tryExtend(tokenizer)
        }.last()

    private fun ExpressionPrefix<E>.tryExtend(tokenizer: Tokenizer): ExpressionPrefix<E>? {
        log(LogLevel.DEBUG, Parser::class.toString(), "tryExtend...")

        return when (this) {
            is ContinuableWithExpression -> {
                onContinuableWithExpression(tokenizer, this)
            }

            is EndedWithExpression -> {
                onEndedWithExpression(tokenizer, this)
            }
        }
    }

    override fun onContinuableWithExpression(
        tokenizer: Tokenizer, continuableWithExpression: ContinuableWithExpression<E>
    ): ExpressionPrefix<E>? {
        val number = tokenizer.tryReadNumber()
        return when {
            number != null -> continuableWithExpression.with(composer.number(number))
            tokenizer.tryReadLeftParenthesis() -> continuableWithExpression.withLeftParenthesis()
            else -> null
        }
    }

    internal fun onEndedWithExpression(
        tokenizer: Tokenizer, endedWithExpression: EndedWithExpression<E>
    ): ExpressionPrefix<E>? {
        val operator = tokenizer.tryReadBinaryOperator()
        return if (operator != null) {
            endedWithExpression.extendedWithOperator(operator)
        } else {
            val reduced = reducedExpression(endedWithExpression)
            if (reduced.prefix is EndedWithLeftParenthesis && tokenizer.tryReadRightParenthesis()) {
                reduced.prefix.prefix.with(reduced.expression)
            } else {
                null
            }
        }
    }

    private tailrec fun EndedWithExpression<E>.extendedWithOperator(operator: BinaryOperator): EndedWithOperator<E> =
        if (this.prefix is EndedWithOperator && this.prefix.operator.precedence >= operator.precedence) {
            // Apply the operator
            this.prefix
                .withOperatorApplied(this.expression)
                .extendedWithOperator(operator)
        } else {
            EndedWithOperator(this.prefix, this.expression, operator)
        }

    override tailrec fun reducedExpression(exp: EndedWithExpression<E>): EndedWithExpression<E> {
        return when (exp.prefix) {
            Empty, is EndedWithLeftParenthesis -> exp

            is EndedWithOperator ->
                reducedExpression(exp.prefix
                    .withOperatorApplied(exp.expression)
                )
        }
    }

    private fun EndedWithOperator<E>.withOperatorApplied(rightOperand: E) =
        this.prefix.with(composer.compose(this.operator, this.leftOperand, rightOperand))

    private fun ExpressionComposer<E>.compose(
        binaryOperator: BinaryOperator, left: E, right: E
    ): E = when (binaryOperator) {
        BinaryOperator.PLUS -> plus(left, right)
        BinaryOperator.MINUS -> minus(left, right)
        BinaryOperator.MULT -> mult(left, right)
        BinaryOperator.DIV -> div(left, right)
    }
}

