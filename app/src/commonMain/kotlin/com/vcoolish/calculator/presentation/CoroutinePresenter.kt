package com.vcoolish.calculator.presentation

import com.vcoolish.calculator.LogLevel
import com.vcoolish.calculator.log
import kotlinx.coroutines.*
import kotlin.coroutines.CoroutineContext

open class CoroutinePresenter(
    private val mainContext: CoroutineContext,
    private val baseView: BaseView
) : CoroutineScope {

    companion object {
        internal val TAG = CoroutinePresenter::class.toString()
    }

    private val job = Job()
    private val exceptionHandler = CoroutineExceptionHandler { _, throwable ->
        log(LogLevel.ERROR, TAG, "Error", throwable)
        baseView.showError(throwable)
    }

    override val coroutineContext: CoroutineContext
        get() = mainContext + job + exceptionHandler

    open fun onDestroy() {
        log(LogLevel.DEBUG, TAG, "onDestroy()")
        job.cancel()
    }
}
