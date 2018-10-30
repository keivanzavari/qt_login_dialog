# Login Dialog

Working implementation of the example given [here](https://wiki.qt.io/User_Login_Dialog)

- Requires cmake minimum *version 2.8* and *QT5*

## How to run

- If you do have QT creator installed, open the project file `login_app.pro`
- If you don't use QT creator do 
```bash
mkdir build
cd build
cmake ..
make
./qt_login_dialog
```
- the password is `123`!

### issues
If you get the compile error of *QDialog not such file or directory*, you can add 
`QT += widgets` to `login_app.pro` file. This issue & solution comes from [this][stackoverflow].



[stackoverflow]: https://stackoverflow.com/questions/14260475/qdialog-not-such-file-or-directory-qt-windows