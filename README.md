# Demonstration of QTBUG-57841 bug

This project is intended to demonstrate the [QTBUG-57841](https://bugreports.qt.io/browse/QTBUG-57841) issue reported in Qt bug-tracker and provide a reproducible example for it.

## Environment

 * Windows 10 x64 in Virtual Box: [MSEdge on Win10 (x64) Stable](https://developer.microsoft.com/en-us/microsoft-edge/tools/vms) (with latest updates installed)
 * Microsoft [Visual Studio Community 2017](https://www.visualstudio.com/thank-you-downloading-visual-studio/?sku=Community&rel=15)
 * CDB Debugger from [Windows 10 SDK](https://developer.microsoft.com/en-us/windows/downloads/windows-10-sdk); [installed separately](https://docs.microsoft.com/en-us/windows-hardware/drivers/debugger) because Visual Studio Installer installs Windows 10 SDK without CDB
 * [Latest Qt version](https://www.qt.io/download-thank-you) Open Source:
    * Qt 5.10.1
    * MSVC 2017 64-bit
    * Sources
    * Qt Creator 4.5.1 + CDB Debugger Support

## Steps to reproduce the bug

 1. Clone this repository
 ```
 $ git clone https://github.com/darklynx/qt-bug-demo.git
 $ cd qt-bug-demo
 ```

 2. Open `qt-demo.pro` in Qt Creator
 3. Ensure that Tab Order on the MyDialog (`mydialog.ui`) is set as shown below:
 ![Tab Order to cause the bug](https://github.com/darklynx/qt-bug-demo/raw/master/screenshots/tab-stop-bug.png)

 4. Compile and run (`Ctrl + R`) the application
 5. Click the **Test a Bug** button and exit the dialog with OK or Cancel:
 ![Runtime Error in dialog destructor](https://github.com/darklynx/qt-bug-demo/raw/master/screenshots/run-bug-result.png)

## Work-around for Runtime Error

 1. Change the Tab Order on the MyDialog (`mydialog.ui`) to the natural (original) order as shown below:
 ![Tab Order that works](https://github.com/darklynx/qt-bug-demo/raw/master/screenshots/tab-stop-ok.png)

 2. Compile and run (`Ctrl + R`) the application
 3. Click the *Test a Bug* button and exit the dialog with OK or Cancel:
 ![No errors in dialog destructor](https://github.com/darklynx/qt-bug-demo/raw/master/screenshots/run-ok-result.png)
