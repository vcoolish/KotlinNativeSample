package com.vcoolish.calculator.computation

class PartialRenderer : PartialExpressionComposer<Double, String> {
    override fun missing() = "..."

    override fun ending(expression: Double) = "$expression ..."

    override fun plus(left: Double, partialRight: String) = "$left + $partialRight"
    override fun minus(left: Double, partialRight: String) = "$left - $partialRight"
    override fun mult(left: Double, partialRight: String) = "$left * $partialRight"
    override fun div(left: Double, partialRight: String) = "$left / $partialRight"
    override fun leftParenthesized(partialExpression: String) = "($partialExpression"
}