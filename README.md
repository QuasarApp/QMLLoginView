# QMLLoginView
test work for Logic Way Solutions

## Introdaction

![logo](https://user-images.githubusercontent.com/12465465/79076393-77b55300-7d02-11ea-8128-498f954dec92.png)


This is a simple login window library for qml projects. The project is built with the help of the сmake build system and may be easily included into existing projects.


## Main features

1. support all qt qml [styles](https://doc.qt.io/qt-5/qtquickcontrols2-styles.html)
2. support logining of users
3. support registeration of new users
4. support custom country list
5. support cqtdeployer deploying system
6. support cmake build system

### Screenshots

#### Login View
![scrinshot Login](https://user-images.githubusercontent.com/12465465/79075704-2060b400-7cfd-11ea-9891-db1671d085e9.png)

#### Register View
![Screenshot register](https://user-images.githubusercontent.com/12465465/79075702-1dfe5a00-7cfd-11ea-9abe-8cfdb3820fe6.png)


## Incuding into exits project
 
 * cd yourRepo
 * git submodule add https://github.com/EndrII/QMLLoginView # add the repository of QMLLoginView into your repo like submodule
 * git submodule update --init --recursive
 * Include in your CMakeLists.txt file the main CMakeLists.txt file of QMLLoginView library
  ``` cmake
    include(QMLLoginView)
  ```
 * Rebuild yuor project


## Using 

``` cpp
#include <lvmainmodel.h>

    LoginView::LVMainModel loginModel("exampleLogin"); // create nodel for login dialog
    loginModel.init(&QMLEngine) // init login dialog. QMLEngine - this is object of QQmlApplicationEngine.
    loginModel.setCounrySource("path/to/countries.xml") // set country list/ Example of counrys xml see example/example.xml

```

``` qml
    LoginView {
        lognViewModel: exampleLogin // exampleLogin - this is inited model in main.cpp
        anchors.fill: parent
    }
```

``` xml country example 
<?xml version="1.0" encoding="UTF-8"?>
<countries>
    <country>
        <code>375</code>
        <name>Belarus</name>
    </country>
    <country>
        <code>33</code>
        <name>France</name>
    </country>
</countries>

```

### LoginView::LVMainModel Methods
``` cpp
    /**
     * @brief setCounrySource - sets path to xml source file and extract list of countrys
     * @param path
     * @return true if the function finished successful
     */
    Q_INVOKABLE bool setCounrySource(const QString &path);

    /**
     * @brief init - prepare all items for use on qml.
     * @param engine - current qml engine of application
     * @return true if the function finished successful
     */
    bool init(QQmlApplicationEngine *engine);


``` 

#### LoginView::LVMainModel Signals 
``` cpp

    /**
     * @brief sigLoginRequest
     * emited when user try login
     */
    void sigLoginRequest(UserData);

    /**
     * @brief sigRegisterRequest
     * emited when user try create new accaunt
     */
    void sigRegisterRequest(UserData);

    /**
     * @brief sigForgotPasswordRequest
     * emited when user forgot own password
     */
    void sigForgotPasswordRequest(UserData);

    /**
     * @brief sigShowTermOfUseRequest
     * emited when user click on "Show term of use" button
     */
    void sigShowTermOfUseRequest();
```

#### UserData properties 
``` cpp
    Q_PROPERTY(int country READ country WRITE setCountry)
    Q_PROPERTY(QString firstName READ firstName WRITE setFirstName)
    Q_PROPERTY(QString lastName READ lastName WRITE setLastName)
    Q_PROPERTY(QString rawPassword READ rawPassword WRITE setRawPassword)
    Q_PROPERTY(QString email READ email WRITE setEmail)
```


## Build Example 

### Prepare
1. install cqtdeployer
2. install cqtdeployer ([gitHubRelises](https://github.com/QuasarApp/CQtDeployer/releases or [snap-store](https://snapcraft.io/cqtdeployer)))
3. if you use snap store version of cqtdeployer add all permisions for cqdeployer.

### build on Linux

``` BASH
git clone https://github.com/EndrII/QMLLoginView

cd QMLLoginView

cmake -DCMAKE_PREFIX_PATH=/my/Qt/Dir

make -j12

export PATH=$PATH:/my/Qt/Dir/bin # add to path location of qmake

cqtdeployer

cd Distributionkit

chmod +x InstallerExampleLoginView.run

./InstallerExampleLoginView.run
```
