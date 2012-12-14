# Workshop 18. Mai 2012

## Inhalt

Thema heute: Modularisierung, sowie als Grundlage dafür, die Phasen der Programm-Übersetzung.

### Folien zum Vortrag

Die Vortragsfolien stehen als [PDF](kit-cpp-workshop.github.com/raw/downloads/workshops/ss12-04/slides.pdf) zum Download bereit. Außerdem liegt der LaTeX-Quellcode zu den Folien im Ordner `slides`.

### Screencast

Eine Aufzeichnung des Vortrags steht zum [Download](http://ubuntuone.com/7aINm5vTShhKjOTjbrRkUo) bereit. Von Audioqualität kann man leider dieses Mal nicht sprechen, das Hintergrundrauschen/-pfeifen hat außerdem alle Fragen und Diskussionsbeiträge überdeckt.

 - ab 00:00 Intro
 - ab 00:37 Übersicht Übersetzungs-Phasen
 - ab 01:49 Präprozessor
 - ab 17:48 Linker
 - ab 25:16 Modularisierung
 - ab 36:32 Vorstellung der Aufgaben
 

## Aufgaben

Sendet, nachdem ihr alle Aufgaben abgearbeitet habt, einen Pull-Request an das Workshop-Repository. Stellt sicher, dass ihr vorher alle eure Änderungen in euren Fork übertragen habt. Nennt euren Workshop-Betreuer im Text des Pull-Requests, einer der Betreuer (bevorzugt der genannte) wird dann eure Lösungen durchsehen, kommentieren und nach Abschluss des Reviews den Pull-Request als abgelehnt markieren.

### Aufgabe 0: Vorbereitung

Am Freitag ist [Towel Day](http://de.wikipedia.org/wiki/Towel_Day). Bringt ein Handtuch mit zum Workshop. Und wie immer: 
_Don't Panic!_


### Aufgabe 1: Ein einfaches Schachspiel

Implementiert ein einfaches Schachspiel für die Kommandozeile. Das Programm soll selbstständig überprüfen, ob die 
eingegebenen Züge gültig sind und geschlagene Figuren automatisch vom Brett nehmen. Dabei genügt es, erst einmal die 
grundlegenden Bewegungs- und Schlagregeln zu unterstützen. Komplexere Regeln wie zum Beispiel die Rochade müsst ihr 
erstmal nicht einbauen. Ebenso ist es nicht unbedingt nötig, ein Schachmatt automatisch zu erkennen. Das Spiel endet, 
wenn einer der Könige tatsächlich geschlagen wurde (das geht ohne Schachmatt-Erkennung natürlich nur, wenn ihr nicht
erzwingt, dass der König aus dem Schach genommen wird.)

#### Benutzereingaben

Die beiden Spieler spielen abwechselnd am gleichen Rechner. Es soll jeweils angezeigt werden, wer gerade am Zug ist, 
woraufhin der aktive Spieler über die Tastatur seinen Zugin der Form Startfeld - Zielfeld eingeben kann. Die genaue 
Syntax bleibt euch dabei selbst überlassen. Wir empfehlen eine der folgenden Varianten:

    e2-e4
    e2 e4
    e 2 e 4
  
Weitere Notationsvarianten findet ihr in der [Wikipedia](http://de.wikipedia.org/wiki/Schach#Notation). Die sind in der 
Regel aber dazu gedacht, den Spielverlauf wiederzugeben und daher wesentlich ausführlicher, als es für die Eingabe 
nötig ist.

Wenn ein Spieler einen ungültigen Zug eingibt, soll er eine entsprechende Meldung erhalten, der Zug wird nicht durchgeführt
und der Spieler darf es solange versuchen bis der Zug gültig ist.
Ungültig ist ein Zug zum Beispiel:
* wenn ein Spieler eine Figur des Gegners bewegen will
* wenn auf dem Zielfeld eine eigene Figur steht
* wenn er eine Figur auf ein Feld bewegen will, das außerhalb des erlaubten Bewegungsrahmens für diese Figur liegt

Überlegt euch, welche dieser Einschränkungen für alle Figuren gleich sind und welche ihr für bestimmte Figuren anpassen
müsst (welche davon sind Spiel-Regeln, welche davon Figuren-Regeln).

#### Ausgabe

Dem Benutzer soll vor jedem Zug eine textbasierte Version des Spielbretts angezeigt bekommen. Alternativ könnt ihr das 
Spielbrett auch nur auf Wunsch des Spielers anzeigen lassen, zum Beispiel, falls er `board` statt einer Zugbeschreibung 
eingibt.

      abcdefgh
    
    8 rnbqkbnr
    7 pppppppp
    6         
    5         
    4         
    3         
    2 PPPPPPPP
    1 RNBQKBNR

An den Spielfeldrändern stehen die Namen der Zeilen (Zahlen von 1 bis 8) und Spalten (Buchstaben von a bis h). Beachtet, 
dass bei der Darstellung von Schachbrettern üblicherweise a8 oben links und h1 unten rechts liegt. Das eigentliche Brett 
ist von diesen Namen durch eine leere Zeile beziehungsweise ein Leerzeichen getrennt.

Jedes Zeichen entspricht einem Feld auf dem Spielbrett. Leere Felder werden durch ein Leerzeichen dargestellt, Felder 
mit einer Figur darauf durch einen Buchstaben. Ihr könnt wahlweise die deutsche oder die englische Notation verwenden. 
Für Bauern gibt es in den meisten Notationen kein Kürzel. Verwendet im Deutschen _B_ für Bauer und im Englischen _P_ für 
Pawn. Es sollte deutlich werden, welche Figur zu welchem Spieler gehört. Im Beispiel wurde Weiß durch Großbuchstaben 
dargestellt und Schwarz durch Kleinbuchstaben.

#### Struktur des Projekts

Der Code soll so strukturiert sein, dass Spiellogik und Benutzerinteraktion komplett voneinander getrennt sind. Es soll 
möglich sein, die Kommandozeilenoberfläche durch eine grafische Oberfläche zu ersetzen, ohne irgendwelchen vorhandenen 
Code außer der `main` Funktion ändern zu müssen (freilich muss noch code hinzugefügt werden). Legt am besten direkt
entsprechende Ordner und Namespaces an, um für euch selbst überprüfen zu können, ob diese Unterteilung eingehalten wird.

Arbeitet mit Vererbung und abstrakten Klassen, wo es sinnvoll ist. Im Folgenden zeigen wir euch ein (unvollständiges) 
Beispiel, wie man Teile des Projekts strukturieren könnte.

    namespace Chess
    {
        namespace UI
        {
            class UserInterface; // Abstract
        }
        namespace Game
        {
            class Piece; // Abstract
            namespace Pieces;
        }
    }

Wenn ihr wollt, könnt ihr die Struktur so flexibel gestalten, um später Features wie Netzwerkunterstützung, 
speichern und laden oder KI-Spieler zu unterstützen. Achtung: Eine Faustregel besagt, dass mehr Struktur mehr Arbeit
beim _ersten_ Implementieren bedeutet (kann ganz leicht ausarten!). Beim Warten, Anpassen und Erweitern reduziert eine
gute, flexible Struktur den Aufwand.

### Aufgabe 2: Mehr Features

Erweitert euer Schachspiel um mindestens eines der folgenden Features (grob sortiert von leicht nach schwer)

* Zeigt zusätzlich eine Liste der bereits vom Brett genommenen Figuren an
* Im Verlauf der Jahrhunderte haben sich die Figuren und Regeln des Schachspiels immer wieder verändert. Implementiert 
  eine Figur oder eine Regel, die heute nicht mehr gebräuchlich ist. Lasst den Benutzer zu Beginn des Spiels auswählen, 
  mit welchem Regelsatz er spielen will.
* Implementiert die Rochade-Regeln
* Implementiert das Umwandeln von Bauern in andere Figuren, wenn Sie die gegnerische Grundlinie erreichen.
* Lasst den aktuellen Spielstand speichern und wieder laden.
* Implementiert ein alternatives User Interface. Ein sehr einfaches Beispiel wäre eine Unterstützung für farbigen Text.
  Die bash unter Linux und Mac OS X unterstützt die Ausgabe von Farben über einfache Farbcodes:

      cout << "\e[0;31m" << "Red" << "\e[0m"  << endl;
  
  Unter Windows funktioniert das Ganze leider nicht ganz so einfach, aber es gibt auch da Mittel und Wege, farbigen 
  Text auszugeben.
  
  Wer sich mit GUI- oder Grafikprogrammierung auskennt, kann uns auch gerne mit einer aufwändigern Oberfläche 
  überraschen.
* Zeigt dem Spieler auf dem Spielfeld an, welche Züge für eine ausgewählte Figur gültig sind.
* Implementiert En-Passant Schlagen
* Erkennt Schach und Schachmatt automatisch. Züge, mit denen der eigene König in Schach gestellt wird, werden ungültig 
  und Schachmatt führt zum sofortigen Spielende.
* Lasst zwei Spieler per Netzwerk miteinander spielen
* Schreibt eine Schach-KI, die in der Lage ist, einen der Betreuer zu schlagen.
