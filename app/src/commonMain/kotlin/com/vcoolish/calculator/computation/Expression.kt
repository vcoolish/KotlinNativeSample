package com.vcoolish.calculator.computation

/**
 * Immutable prefix of expression partially parsed to combination of abstractly represented expressions.
 * The prefix representation can be thought as "almost AST", i.e. AST with unfinished rightmost leaf
 * (referenced by this object), and its nodes contain links to parent and (if needed) left child.
 *
 * @param E abstract representation of expression, e.g. its value, AST etc.
 */

internal sealed class ExpressionPrefix<out E>

internal sealed class ContinuableWithExpression<out E> : ExpressionPrefix<E>()

internal fun <E> ContinuableWithExpression<E>.with(expression: E) =
    EndedWithExpression(this, expression)

internal fun <E> ContinuableWithExpression<E>.withLeftParenthesis() =
    EndedWithLeftParenthesis(this)

internal data class EndedWithExpression<E>(
    val prefix: ContinuableWithExpression<E>,
    val expression: E
) : ExpressionPrefix<E>()

internal object Empty : ContinuableWithExpression<Nothing>()

internal data class EndedWithLeftParenthesis<out E>(
    val prefix: ContinuableWithExpression<E>
) : ContinuableWithExpression<E>()

internal data class EndedWithOperator<out E>(
    val prefix: ContinuableWithExpression<E>,
    val leftOperand: E,
    val operator: BinaryOperator
) : ContinuableWithExpression<E>()