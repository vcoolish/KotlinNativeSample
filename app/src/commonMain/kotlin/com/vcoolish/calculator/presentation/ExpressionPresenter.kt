package com.vcoolish.calculator.presentation

import com.vcoolish.calculator.LogLevel
import com.vcoolish.calculator.computation.parseAndComputeWithFibonacci
import com.vcoolish.calculator.log
import kotlinx.coroutines.async
import kotlin.coroutines.CoroutineContext

class ExpressionPresenter(
    context: CoroutineContext,
    private val view: CalculatorView
) : CoroutinePresenter(context, view), CalculatorAction {

    override fun onRequestData(inputData: String) = updateData(inputData)

    private fun updateData(inputData: String) {
        log(LogLevel.DEBUG, TAG, "updateData()")

        view.isComputing = true
        var result: Double? = null

        async(coroutineContext) {
            result = parseAndComputeWithFibonacci(inputData).expression
        }.invokeOnCompletion {
            view.onUpdate(result, inputData)
            view.isComputing = false
        }
    }
}
