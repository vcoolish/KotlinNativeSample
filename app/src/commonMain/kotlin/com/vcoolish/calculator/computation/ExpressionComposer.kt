package com.vcoolish.calculator.computation

interface ExpressionComposer<E : Any> {
    fun number(value: Double): E
    fun plus(left: E, right: E): E
    fun minus(left: E, right: E): E
    fun mult(left: E, right: E): E
    fun div(left: E, right: E): E
}