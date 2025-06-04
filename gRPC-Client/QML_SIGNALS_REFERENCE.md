# QML Signals Reference - QFunctions

Ta dokumentacja opisuje wszystkie dostępne sygnały obsługiwane przez klasę `QFunctions`.

## Sposób użycia

```cpp
// Podstawowe użycie
qfunctions_.onClicked("button_id", [](const std::string& id, const QVariantList& args) {
    std::cout << "Button " << id << " clicked!" << std::endl;
});

// Uniwersalny callback dla dowolnego sygnału
qfunctions_.connectSignal("component_id", "customSignal(QString)", [](const std::string& id, const QVariantList& args) {
    std::cout << "Custom signal from " << id << std::endl;
});
```

## Kategorie sygnałów

### 🖱️ Podstawowe sygnały przycisków i kontrolek

| Metoda | Sygnał QML | Opis | Argumenty |
|--------|------------|------|-----------|
| `onClicked()` | `clicked()` | Kliknięcie komponentu | - |
| `onPressed()` | `pressed()` | Naciśnięcie komponentu | - |
| `onReleased()` | `released()` | Zwolnienie komponentu | - |
| `onDoubleClicked()` | `doubleClicked()` | Podwójne kliknięcie | - |
| `onToggled()` | `toggled(bool)` | Przełączenie stanu | bool checked |

**Przykład:**
```cpp
qfunctions_.onClicked("myButton", [](const std::string& id, const QVariantList& args) {
    log.info() << "Button " << id << " was clicked!";
});
```

### ✏️ Sygnały związane z tekstem

| Metoda | Sygnał QML | Opis | Argumenty |
|--------|------------|------|-----------|
| `onTextChanged()` | `textChanged()` | Zmiana tekstu | - |
| `onEditingFinished()` | `editingFinished()` | Zakończenie edycji | - |
| `onAccepted()` | `accepted()` | Zaakceptowanie (Enter) | - |
| `onCurrentTextChanged()` | `currentTextChanged(QString)` | Zmiana aktualnego tekstu | QString text |

**Przykład:**
```cpp
qfunctions_.onTextChanged("textInput", [](const std::string& id, const QVariantList& args) {
    log.info() << "Text changed in " << id;
});
```

### 🎯 Sygnały związane z focusem

| Metoda | Sygnał QML | Opis | Argumenty |
|--------|------------|------|-----------|
| `onFocusChanged()` | `focusChanged(bool)` | Zmiana focusu | bool hasFocus |
| `onActiveFocusChanged()` | `activeFocusChanged(bool)` | Zmiana aktywnego focusu | bool activeFocus |
| `onActiveFocusItemChanged()` | `activeFocusItemChanged()` | Zmiana aktywnego elementu | - |

### 🖱️ Sygnały związane z myszą

| Metoda | Sygnał QML | Opis | Argumenty |
|--------|------------|------|-----------|
| `onEntered()` | `entered()` | Najechanie myszą | - |
| `onExited()` | `exited()` | Zjechanie myszą | - |
| `onHoveredChanged()` | `hoveredChanged(bool)` | Zmiana stanu hover | bool hovered |
| `onPositionChanged()` | `positionChanged()` | Zmiana pozycji | - |

**Przykład:**
```cpp
qfunctions_.onEntered("hoverArea", [](const std::string& id, const QVariantList& args) {
    log.info() << "Mouse entered " << id;
});
```

### 📊 Sygnały związane z wartościami

| Metoda | Sygnał QML | Opis | Argumenty |
|--------|------------|------|-----------|
| `onValueChanged()` | `valueChanged()` | Zmiana wartości | - |
| `onCurrentIndexChanged()` | `currentIndexChanged(int)` | Zmiana aktualnego indeksu | int index |
| `onCurrentItemChanged()` | `currentItemChanged()` | Zmiana aktualnego elementu | - |
| `onCountChanged()` | `countChanged(int)` | Zmiana liczby elementów | int count |

### 📋 Sygnały związane z widokami i modelami

| Metoda | Sygnał QML | Opis | Argumenty |
|--------|------------|------|-----------|
| `onModelChanged()` | `modelChanged()` | Zmiana modelu | - |
| `onDelegateChanged()` | `delegateChanged()` | Zmiana delegata | - |

### 🎬 Sygnały związane z animacjami

| Metoda | Sygnał QML | Opis | Argumenty |
|--------|------------|------|-----------|
| `onStarted()` | `started()` | Start animacji | - |
| `onStopped()` | `stopped()` | Stop animacji | - |
| `onFinished()` | `finished()` | Zakończenie animacji | - |
| `onPaused()` | `paused()` | Wstrzymanie animacji | - |
| `onResumed()` | `resumed()` | Wznowienie animacji | - |

**Przykład:**
```cpp
qfunctions_.onFinished("fadeAnimation", [](const std::string& id, const QVariantList& args) {
    log.info() << "Animation " << id << " finished!";
});
```

### 📐 Sygnały związane z geometrią

| Metoda | Sygnał QML | Opis | Argumenty |
|--------|------------|------|-----------|
| `onWidthChanged()` | `widthChanged()` | Zmiana szerokości | - |
| `onHeightChanged()` | `heightChanged()` | Zmiana wysokości | - |
| `onXChanged()` | `xChanged()` | Zmiana pozycji X | - |
| `onYChanged()` | `yChanged()` | Zmiana pozycji Y | - |
| `onScaleChanged()` | `scaleChanged()` | Zmiana skali | - |
| `onRotationChanged()` | `rotationChanged()` | Zmiana rotacji | - |
| `onOpacityChanged()` | `opacityChanged()` | Zmiana przezroczystości | - |
| `onVisibleChanged()` | `visibleChanged()` | Zmiana widoczności | - |

### 🪟 Sygnały związane z oknem

| Metoda | Sygnał QML | Opis | Argumenty |
|--------|------------|------|-----------|
| `onClosing()` | `closing(QQuickCloseEvent*)` | Zamykanie okna | QQuickCloseEvent* |
| `onActiveChanged()` | `activeChanged()` | Zmiana aktywności okna | - |

### 🎨 Sygnały związane z kolorem i stylem

| Metoda | Sygnał QML | Opis | Argumenty |
|--------|------------|------|-----------|
| `onColorChanged()` | `colorChanged()` | Zmiana koloru | - |
| `onSourceChanged()` | `sourceChanged()` | Zmiana źródła | - |
| `onStatusChanged()` | `statusChanged()` | Zmiana statusu | - |

### 👆 Sygnały związane z gestami i dotknięciami

| Metoda | Sygnał QML | Opis | Argumenty |
|--------|------------|------|-----------|
| `onSwipeUp()` | `swipeUp()` | Przesunięcie w górę | - |
| `onSwipeDown()` | `swipeDown()` | Przesunięcie w dół | - |
| `onSwipeLeft()` | `swipeLeft()` | Przesunięcie w lewo | - |
| `onSwipeRight()` | `swipeRight()` | Przesunięcie w prawo | - |
| `onPinch()` | `pinch(QQuickPinchEvent*)` | Gest uszczypnięcia | QQuickPinchEvent* |
| `onTap()` | `tapped(QQuickGeoMapGestureEvent*)` | Stuknięcie | QQuickGeoMapGestureEvent* |

### 📥 Sygnały związane z ładowaniem

| Metoda | Sygnał QML | Opis | Argumenty |
|--------|------------|------|-----------|
| `onLoaded()` | `loaded()` | Zakończenie ładowania | - |
| `onProgressChanged()` | `progressChanged()` | Zmiana postępu | - |
| `onSourceComponentChanged()` | `sourceComponentChanged()` | Zmiana komponentu źródłowego | - |

### 📜 Sygnały związane z scrollowaniem

| Metoda | Sygnał QML | Opis | Argumenty |
|--------|------------|------|-----------|
| `onFlickStarted()` | `flickStarted()` | Start przewijania | - |
| `onFlickEnded()` | `flickEnded()` | Koniec przewijania | - |
| `onMovementStarted()` | `movementStarted()` | Start ruchu | - |
| `onMovementEnded()` | `movementEnded()` | Koniec ruchu | - |
| `onContentXChanged()` | `contentXChanged()` | Zmiana pozycji X zawartości | - |
| `onContentYChanged()` | `contentYChanged()` | Zmiana pozycji Y zawartości | - |

### 🎛️ Sygnały specyficzne dla kontrolek

| Metoda | Sygnał QML | Opis | Argumenty |
|--------|------------|------|-----------|
| `onCheckStateChanged()` | `checkStateChanged(Qt::CheckState)` | Zmiana stanu checkboxa | Qt::CheckState state |
| `onIndicatorChanged()` | `indicatorChanged()` | Zmiana wskaźnika | - |
| `onHighlightedChanged()` | `highlightedChanged(bool)` | Zmiana podświetlenia | bool highlighted |
| `onFlippedChanged()` | `flippedChanged(bool)` | Zmiana stanu odwrócenia | bool flipped |

### 📋 Sygnały właściwości

| Metoda | Sygnał QML | Opis | Argumenty |
|--------|------------|------|-----------|
| `onDataChanged()` | `dataChanged(QModelIndex,QModelIndex,QVector<int>)` | Zmiana danych modelu | Model indices |
| `onBackgroundChanged()` | `backgroundChanged()` | Zmiana tła | - |
| `onForegroundChanged()` | `foregroundChanged()` | Zmiana pierwszego planu | - |
| `onImplicitWidthChanged()` | `implicitWidthChanged()` | Zmiana domyślnej szerokości | - |
| `onImplicitHeightChanged()` | `implicitHeightChanged()` | Zmiana domyślnej wysokości | - |

### 🔄 Sygnały związane z animacjami i transformacjami

| Metoda | Sygnał QML | Opis | Argumenty |
|--------|------------|------|-----------|
| `onRunningChanged()` | `runningChanged(bool)` | Zmiana stanu działania | bool running |
| `onTransformOriginChanged()` | `transformOriginChanged()` | Zmiana punktu transformacji | - |
| `onAntialiasingChanged()` | `antialiasingChanged(bool)` | Zmiana antyaliasingu | bool antialiasing |

### ✅ Sygnały związane z walidacją

| Metoda | Sygnał QML | Opis | Argumenty |
|--------|------------|------|-----------|
| `onAcceptableInputChanged()` | `acceptableInputChanged(bool)` | Zmiana akceptowalności danych | bool acceptable |
| `onValidatorChanged()` | `validatorChanged()` | Zmiana walidatora | - |
| `onInputMethodHintsChanged()` | `inputMethodHintsChanged()` | Zmiana wskazówek metody wejścia | - |

### 🎵 Sygnały związane z dźwiękiem i mediami

| Metoda | Sygnał QML | Opis | Argumenty |
|--------|------------|------|-----------|
| `onDurationChanged()` | `durationChanged(qint64)` | Zmiana czasu trwania | qint64 duration |
| `onVolumeChanged()` | `volumeChanged(qreal)` | Zmiana głośności | qreal volume |
| `onPlaybackStateChanged()` | `playbackStateChanged()` | Zmiana stanu odtwarzania | - |

### 🌐 Sygnały związane z siecią

| Metoda | Sygnał QML | Opis | Argumenty |
|--------|------------|------|-----------|
| `onNetworkAccessibleChanged()` | `networkAccessibleChanged(bool)` | Zmiana dostępności sieci | bool accessible |
| `onLoadingChanged()` | `loadingChanged(bool)` | Zmiana stanu ładowania | bool loading |
| `onErrorChanged()` | `errorChanged()` | Zmiana błędu | - |

### ⏰ Sygnały związane z czasem i datą

| Metoda | Sygnał QML | Opis | Argumenty |
|--------|------------|------|-----------|
| `onTimeChanged()` | `timeChanged()` | Zmiana czasu | - |
| `onDateChanged()` | `dateChanged()` | Zmiana daty | - |
| `onIntervalChanged()` | `intervalChanged(int)` | Zmiana interwału | int interval |
| `onTriggered()` | `triggered()` | Wyzwolenie timera | - |

### 📐 Sygnały związane z układem

| Metoda | Sygnał QML | Opis | Argumenty |
|--------|------------|------|-----------|
| `onAnchorsChanged()` | `anchorsChanged()` | Zmiana kotwic | - |
| `onMarginsChanged()` | `marginsChanged()` | Zmiana marginesów | - |
| `onSpacingChanged()` | `spacingChanged(qreal)` | Zmiana odstępów | qreal spacing |
| `onLayoutDirectionChanged()` | `layoutDirectionChanged(Qt::LayoutDirection)` | Zmiana kierunku układu | Qt::LayoutDirection direction |

### 📋 Sygnały związane z listami i tabelami

| Metoda | Sygnał QML | Opis | Argumenty |
|--------|------------|------|-----------|
| `onItemsChanged()` | `itemsChanged()` | Zmiana elementów | - |
| `onRowsChanged()` | `rowsChanged(int)` | Zmiana liczby wierszy | int rows |
| `onColumnsChanged()` | `columnsChanged(int)` | Zmiana liczby kolumn | int columns |
| `onSelectionChanged()` | `selectionChanged()` | Zmiana selekcji | - |

### 🎨 Sygnały związane z grafiką i rysowaniem

| Metoda | Sygnał QML | Opis | Argumenty |
|--------|------------|------|-----------|
| `onPaintedSizeChanged()` | `paintedSizeChanged()` | Zmiana rozmiaru rysowania | - |
| `onSmoothChanged()` | `smoothChanged(bool)` | Zmiana wygładzania | bool smooth |
| `onFillModeChanged()` | `fillModeChanged()` | Zmiana trybu wypełniania | - |

### 🌍 Sygnały uniwersalne

| Metoda | Sygnał QML | Opis | Argumenty |
|--------|------------|------|-----------|
| `onChildrenChanged()` | `childrenChanged()` | Zmiana dzieci komponentu | - |
| `onParentChanged()` | `parentChanged()` | Zmiana rodzica | - |
| `onStateChanged()` | `stateChanged(QString)` | Zmiana stanu | QString state |
| `onEnabledChanged()` | `enabledChanged(bool)` | Zmiana dostępności | bool enabled |

**Przykład użycia nowych sygnałów:**
```cpp
// Obsługa walidacji
qfunctions_.onAcceptableInputChanged("emailInput", [this](const std::string& id, const QVariantList& args) {
    if (!args.isEmpty()) {
        bool acceptable = args[0].toBool();
        if (acceptable) {
            log.info() << "Email format is valid";
        } else {
            log.warning() << "Invalid email format";
        }
    }
});

// Obsługa timera
qfunctions_.onTriggered("autoSaveTimer", [this](const std::string& id, const QVariantList& args) {
    performAutoSave();
});

// Obsługa zmian układu
qfunctions_.onSpacingChanged("listLayout", [this](const std::string& id, const QVariantList& args) {
    if (!args.isEmpty()) {
        qreal spacing = args[0].toReal();
        log.info() << "Layout spacing changed to: " << spacing;
    }
});
```

## 🔧 Uniwersalny callback

Jeśli potrzebujesz obsłużyć sygnał, który nie jest na powyższej liście, użyj:

```cpp
qfunctions_.connectSignal("componentId", "customSignal(QString, int)", [](const std::string& id, const QVariantList& args) {
    std::cout << "Custom signal from " << id << std::endl;
    if (args.size() >= 2) {
        QString text = args[0].toString();
        int number = args[1].toInt();
        // Obsłuż argumenty...
    }
});
```

## 💡 Wskazówki

1. **ID komponentu**: Upewnij się, że komponent ma unikalne ID w QML
2. **Argumenty**: Argumenty sygnału są dostępne w `QVariantList& args`
3. **Konwersje**: Użyj metod `QVariant` do konwersji argumentów (`.toString()`, `.toInt()`, `.toBool()`, itp.)
4. **Lambda funkcje**: Możesz przechwytywać zmienne przez referencję `[&]` lub wartość `[=]`
5. **Zarządzanie połączeniami**: Połączenia są automatycznie zarządzane przez `QFunctions`

## 🚀 Przykład kompletnego użycia

```cpp
void setupCallbacks() {
    // Przycisk logowania
    qfunctions_.onClicked("loginButton", [this](const std::string& id, const QVariantList& args) {
        performLogin();
    });
    
    // Pole tekstowe username
    qfunctions_.onTextChanged("usernameInput", [this](const std::string& id, const QVariantList& args) {
        validateUsername();
    });
    
    // Slider volume
    qfunctions_.onValueChanged("volumeSlider", [this](const std::string& id, const QVariantList& args) {
        updateVolume();
    });
    
    // Uniwersalny callback
    qfunctions_.connectSignal("customComponent", "dataReceived(QString)", 
        [this](const std::string& id, const QVariantList& args) {
            if (!args.isEmpty()) {
                QString data = args[0].toString();
                processReceivedData(data);
            }
        });
}
```
