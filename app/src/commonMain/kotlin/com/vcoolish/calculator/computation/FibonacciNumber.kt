package com.vcoolish.calculator.computation

import kotlin.Double.Companion.POSITIVE_INFINITY

private val memoizedMap: MutableMap<Double, Double> = mutableMapOf()

internal fun fibNumber(n: Double): Double =
    if (n == 0.0) {
        0.0
    } else if(n > 1500.0) {
        fibTail(n, 1.0, 0.0, 1.0)
    } else {
        fibTail(n, 1.0, 0.0, 1.0)
    }

private tailrec fun fibTail(max: Double, currIteration: Double, twoStep: Double, oneStep: Double): Double =
    if (currIteration >= max) {
        oneStep
    } else {
        fibTail(
            max,
            currIteration + 1,
            oneStep,
            memoizedMap.getOrPut(currIteration) { oneStep + twoStep }
        )
    }
