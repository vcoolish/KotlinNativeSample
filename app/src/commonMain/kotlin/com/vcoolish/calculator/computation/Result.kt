package com.vcoolish.calculator.computation

data class Result<E : Any, PE : Any>(val expression: E?, val partialExpression: PE, val remainder: String?)