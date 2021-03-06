/*/////////////////////////////////////////////////////////////////////////////////
/// An
///    ___   ____ ___ _____ ___  ____
///   / _ \ / ___|_ _|_   _/ _ \|  _ \
///  | | | | |  _ | |  | || | | | |_) |
///  | |_| | |_| || |  | || |_| |  _ <
///   \___/ \____|___| |_| \___/|_| \_\
///                              File
///
/// Copyright (c) 2008-2015 Ismail TARIM <ismail@royalspor.com> and the Ogitor Team
///
/// The MIT License
///
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
///
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
/// THE SOFTWARE.
////////////////////////////////////////////////////////////////////////////////*/
#ifndef __shortcutsettings_hxx__
#define __shortcutsettings_hxx__

#include <QtWidgets/QWidget>
#include <QtGui/QStandardItemModel>
#include <QtCore/QEvent>

namespace Ui {
    class ShortCutSettings;
}

class ShortCutSettings : public QWidget {
    Q_OBJECT
    Q_DISABLE_COPY(ShortCutSettings)
public:
    explicit ShortCutSettings(QWidget *parent = 0);
    virtual ~ShortCutSettings();

    void initShortcuts();

    bool event( QEvent* ev );
    void keyPressEvent(QKeyEvent *k);
    void keyReleaseEvent(QKeyEvent *k);
    static QString getKeyText(int KeyC);

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::ShortCutSettings *m_ui;
    QStandardItemModel *shortcutModel;

    int keyCode;
    QString Part0;
    QString Part1;
    QString Part2;
    QString Part3;
    QString Part4;
    void shortcutSet(const QString &shortcut, const int &keycode);
    void reloadShortcuts();
    void setSelected(const QString &actionText);

private slots:
    void slotChangeShortcut();
    void slotClearShortcut();
    void slotActionSelected(const QModelIndex &mi);
    
Q_SIGNALS:
    void isDirty();
    
};

#endif // __shortcutsettings_hxx__