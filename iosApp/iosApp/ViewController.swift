import UIKit
import app

class ViewController: UIViewController, UITextViewDelegate, UICollectionViewDataSource,
CalculatorView {
    
    var isComputing: Bool = false {
        willSet {
            DispatchQueue.main.async {
                self.progressBar.isHidden = !newValue
            }
        }
    }
    
    lazy var actions: CalculatorAction = {
        ExpressionPresenter(context: UI(), view: self)
    }()
    
    private var logs = [String]()
    
    @IBOutlet var partialResult: UILabel!
    @IBOutlet var result: UILabel!
    @IBOutlet var input: UITextView!
    @IBOutlet var numpad: UICollectionView!
    @IBOutlet var progressBar: UIActivityIndicatorView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        numpad.dataSource = self
        setupLogs()
    }
    
    func showError(t: KotlinThrowable) {
        print(t)
    }
    
    func onUpdate(result: KotlinDouble?, inputData: String) {
        if let parsed = result as? Double {
            self.result.text = "\(inputData) = \(parsed)"
        } else {
            self.result.text = "Couldn't parse \(inputData)"
        }
        
        self.partialResult.text = inputData
    }

    private func inputDidChange() {
        let inputText = input.text!
        self.actions.onRequestData(inputData: inputText)
    }

    @IBAction func calculate(_ sender: UIButton) {
        inputDidChange()
    }

    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return logs.count
    }

    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        let cell  = collectionView.dequeueReusableCell(withReuseIdentifier: "labelCell", for: indexPath)

        (cell.viewWithTag(1) as! UILabel).text = logs[indexPath.item]

        return cell
    }
    
    private func setupLogs() {
        let allPaths = NSSearchPathForDirectoriesInDomains(.documentDirectory, .userDomainMask, true)
        let documentsDirectory = allPaths.first!
        let pathForLog = documentsDirectory.appendingFormat("/calculator_logs.txt")
        
        freopen(pathForLog.cString(using: String.Encoding.ascii)!, "a+", stdout)
        
        let fileMonitor = DAFileMonitor(withFilePath: pathForLog)
        fileMonitor?.onFileEvent = {
            let dict = NSKeyedUnarchiver.unarchiveObject(withFile: pathForLog) as? [String: Any] ?? [:]
            self.onNewLogs(dict: dict)
        }
    }
    
    private func onNewLogs(dict: [String: Any]) {
        logs.append(dict.description)
        numpad.reloadData()
    }
}
