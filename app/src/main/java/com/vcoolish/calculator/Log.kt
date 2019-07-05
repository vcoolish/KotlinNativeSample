package com.vcoolish.calculator

import com.hypertrack.hyperlog.HyperLog

actual fun log(level: LogLevel, tag: String, message: String, error: Throwable) {
    when (level) {
        is LogLevel.DEBUG -> HyperLog.d(tag, message, error)
        is LogLevel.INFO ->  HyperLog.i(tag, message, error)
        is LogLevel.WARN ->  HyperLog.w(tag, message, error)
        is LogLevel.ERROR -> HyperLog.e(tag, message, error)
    }
}

actual fun log(level: LogLevel, tag: String, message: String) {
    when (level) {
        is LogLevel.DEBUG -> HyperLog.d(tag, message)
        is LogLevel.INFO ->  HyperLog.i(tag, message)
        is LogLevel.WARN ->  HyperLog.w(tag, message)
        is LogLevel.ERROR -> HyperLog.e(tag, message)
    }
}