package com.vcoolish.calculator

import android.os.Bundle
import android.support.v7.app.AppCompatActivity
import android.util.Log
import android.view.View.GONE
import android.view.View.VISIBLE
import android.widget.Toast
import com.hypertrack.hyperlog.HyperLog
import com.vcoolish.calculator.presentation.CalculatorAction
import com.vcoolish.calculator.presentation.CalculatorView
import com.vcoolish.calculator.presentation.ExpressionPresenter
import kotlinx.android.synthetic.main.activity_main.*
import kotlinx.coroutines.Dispatchers
import sample.R
import java.io.File
import kotlin.concurrent.fixedRateTimer
import kotlin.properties.Delegates


class MainActivity : AppCompatActivity(), CalculatorView {

    override var isComputing: Boolean by Delegates.observable(false) { _, _, isComputing ->
        runOnUiThread {
            progressBar.visibility = if (isComputing) VISIBLE else GONE
        }
    }

    private val actions: CalculatorAction by lazy {
        ExpressionPresenter(Dispatchers.IO, this)
    }

    override fun onUpdate(result: Double?, inputData: String) {
        runOnUiThread {
            computed_result.text = if (result != null) "$inputData = $result" else "Unable to parse $inputData"
        }
    }

    override fun showError(t: Throwable) {
        Toast.makeText(this, t.toString(), android.widget.Toast.LENGTH_SHORT).show()
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        setupLog()

        input.setOnEditorActionListener { input, _, _ ->
            if(!isComputing) {
                actions.onRequestData(input.text.toString())
            }
            true
        }
    }

    private fun setupLog() {
        HyperLog.initialize(applicationContext)
        HyperLog.setLogLevel(Log.INFO)
        val file = HyperLog.getDeviceLogsInFile(applicationContext, false)
        observeLogsIn(file)
    }

    private fun observeLogsIn(file: File?) {
        fixedRateTimer("timer", false, 0, 1000) {
            runOnUiThread {
                if(file != null) {
                    logOutput.text = file.readText()
                }
            }
        }
    }
}