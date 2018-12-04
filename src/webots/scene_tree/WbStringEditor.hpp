// Copyright 1996-2018 Cyberbotics Ltd.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef WB_STRING_EDITOR_HPP
#define WB_STRING_EDITOR_HPP

//
// Description: editor for editing a WbSFString or a WbMFString item
//

#include "WbValueEditor.hpp"

class WbFieldLineEdit;

class WbStringEditor : public WbValueEditor {
  Q_OBJECT

public:
  explicit WbStringEditor(QWidget *parent = NULL);
  virtual ~WbStringEditor();

  void recursiveBlockSignals(bool block) override;

  const QString &stringValue() const { return mString; };
  QWidget *lastEditorWidget() override;

public slots:
  void applyIfNeeded() override;

protected:
  void edit(bool copyOriginalValue) override;
  void resetFocus() override;

protected slots:
  void apply() override;

protected:
  WbFieldLineEdit *lineEdit() const { return mLineEdit; }
  void takeKeyboardFocus() override;

private:
  QString mString;
  WbFieldLineEdit *mLineEdit;
};

#endif