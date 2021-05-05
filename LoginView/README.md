# SimpleQmlNotify
Simple Qml notification service for qml applications.

## Include

### For qmake projects 

 * cd yourRepo
 * git submodule add https://github.com/QuasarApp/SimpleQmlNotify.git # add the repository of QSimpleQmlNotify into your repo like submodule
 * git submodule update --init --recursive
 * Include in your pro file the pri file of Qt-Secret library
  ``` qmake
    include($$PWD/SimpleQmlNotify/QmlNotify.pri)
  ```
 * Rebuild yuor project

### For cmake projects
#### The cmake build do not required Qt libraries. 
 
 * cd yourRepo
 * git submodule add https://github.com/QuasarApp/SimpleQmlNotify.git # add the repository of QSimpleQmlNotify into your repo like submodule
 * git submodule update --init --recursive
 * Include in your CMakeLists.txt file the main CMakeLists.txt file of QSimpleQmlNotify library
  ``` cmake
    include(QmlNotyfyService)
  ```
 * Rebuild yuor project



### For other build system
 
 * cd yourRepo
 * git submodule add https://github.com/QuasarApp/SimpleQmlNotify.git # add the repository of QSimpleQmlNotify into your repo like submodule
 * git submodule update --init --recursive
 * Add the rule for build QmlNotyfyService
 * Add INCLUDEPATH and LIBS for your build system 
 * Rebuild yuor project


## Use

### CPP
``` cpp
 #include <qmlnotifyservice.h>

 int main() {
     QmlNotificationService::init();
     auto service = QmlNotificationService::NotificationService::getService();
     service->setNotify("title", "text", "UrlOfImage", NotificationData::Normal);
 }


```

### QML

``` qml

 NotificationServiceView {
     anchors.fill: parent;
 }

```


### Translations

The LoginView sopports next languages:
* xxxxx

#### Include 

For include use the QuasarAppUtils::Locales class. see oficial [documentation](https://quasarapp.ddns.net:3031/docs/QuasarApp/QuasarAppLib/latest/classQuasarAppUtils_1_1Locales.html#a8eba3973cc4e88697a41125de0c9653f)


```cpp
if(!QuasarAppUtils::Locales::init(locale, {":/lv_languages/"})){
    QuasarAppUtils::Params::log("Error load language : " , QuasarAppUtils::Error);
}
```

Or you can monualy load needed qm file.
All qm files located in lv_languages folder.
