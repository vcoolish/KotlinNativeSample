package com.vcoolish.calculator.presentation

interface CalculatorView : BaseView {
    var isComputing: Boolean
    fun onUpdate(result: Double?, inputData: String)
}

interface CalculatorAction {
    fun onRequestData(inputData: String)
}