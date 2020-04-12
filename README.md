# QMLLoginView
test work for Logic Way Solutions

## Introdaction

This is a simple login window library for qml projects. The project is built with the help of the сmake build system and is very easily includet to existing projects.


## Main features

1. cmake support
2. support all qt qml [styles](https://doc.qt.io/qt-5/qtquickcontrols2-styles.html)
3. support login users
4. support register new users
5. support custom country list
6. support cqtdeployer deploy system

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
