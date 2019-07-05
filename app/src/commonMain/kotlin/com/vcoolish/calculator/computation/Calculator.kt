package com.vcoolish.calculator.computation

class Calculator : ExpressionComposer<Double> {
    override fun number(value: Double) = value
    override fun plus(left: Double, right: Double) = left + right
    override fun minus(left: Double, right: Double) = left - right
    override fun mult(left: Double, right: Double) = left * right
    override fun div(left: Double, right: Double) = left / right
}